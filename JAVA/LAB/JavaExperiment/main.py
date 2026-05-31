# encoding: latin-1

import uncompressor  # import uncompressor???import uncompressor__init__.py
import fileutil
import parse
import exception
import logger
import shell
import autotest
import os
import excelutil
import pandas as pd

# ?????¼ ???
# ?¼°????????
# submit_root_dir = r'E:\JavaExperimentTest\18'
# submit_root_dir = r'E:\JavaExperimentTest\19'
# submit_root_dir = r'E:\JavaExperimentTest\20'
submit_root_dir = os.path.dirname(os.path.abspath(__file__))

if submit_root_dir[-1] != '\\':
    submit_root_dir += '\\'

# ???¼
uncompress_test_target = submit_root_dir + r'temp'
if not os.path.exists(uncompress_test_target):
    os.mkdir(uncompress_test_target)

# ???¼, ???¼???·?
running_test_dir = submit_root_dir + r'run'
if not os.path.exists(running_test_dir):
    os.mkdir(running_test_dir)


# ??¼
logger_path = submit_root_dir + r'logs'
if not os.path.exists(logger_path):
    os.mkdir(logger_path)

# ??logger
run_logger = logger.Logger('run logger', logger_path).get_logger()

# ????Excel,?False, ??original_score_excel_filetest_score_excel_file?
# ????False
record_test_result_to_excel = True


def find_input_excel(dir_full_path, exclude_file_name):
    """
    Find the first .xlsx file in the given directory, excluding the output file name.
    """
    files = fileutil.find_files(dir_full_path)
    for f in files:
        if f.lower().endswith('.xlsx') and os.path.basename(f).lower() != exclude_file_name.lower():
            return f
    return ''


# ????
# test_score_excel_file = submit_root_dir + r'JAVA ?(18???)-??.xlsx'
test_score_excel_file = os.path.join(submit_root_dir, 'test-output.xlsx')

# ????
# original_score_excel_file = submit_root_dir + r'JAVA ?(18???).xlsx'
# original_score_excel_file = submit_root_dir + r'JAVA ??(19????).xlsx'
original_score_excel_file = find_input_excel(
    submit_root_dir, os.path.basename(test_score_excel_file))

excel = None
fallback_rows = []
fallback_headers = ['s_id', 's_class', 's_name',
                    'total', 'failures', 'skips', 'detail']

if record_test_result_to_excel:
    if original_score_excel_file != '':
        # Excel? original_score_excel_file
        excel = excelutil.Excel(
            original_score_excel_file, test_score_excel_file)
    else:
        run_logger.warning(
            'No input Excel found. Will write a standalone output Excel at: ' + test_score_excel_file)


def append_fallback_row(sinfo, final_result=None, detail=''):
    """
    Append a row to the fallback output when no input Excel is provided.
    """
    if not record_test_result_to_excel or excel is not None:
        return
    if sinfo is None:
        return
    row = {
        's_id': sinfo.s_id,
        's_class': sinfo.s_class,
        's_name': sinfo.s_name,
        'total': '',
        'failures': '',
        'skips': '',
        'detail': detail,
    }
    if final_result is not None:
        row['total'] = final_result[0]
        row['failures'] = final_result[1]
        row['skips'] = final_result[2]
    fallback_rows.append(row)


def find_all_submit_files(root_dir):
    """
    ??¼???
    :param root_dir: ??¼
    :return: ????
    """
    li = []
    submit_files = fileutil.find_files(submit_root_dir)
    for f in submit_files:
        f_suffix = fileutil.find_file_suffix(f)  # õf??
        if f_suffix == '.zip' or f_suffix == '.rar':
            li.append(f)

    return li


def handle_per_compressed_file(compressed_file):
    """
    ÿ????
    :param compressed_file: ?????·
    :return:
    """
    run_logger.info('---->' + compressed_file + 'µ?')

    # õ???
    file_name_without_suffix = fileutil.find_file_name_without_suffix(
        compressed_file)
    # ????
    try:
        sinfo = parse.parse_student_info(file_name_without_suffix)
    except exception.FileNameFormatError as e:
        run_logger.error('-------->' + e)
        return  # ??, ????

    if record_test_result_to_excel and excel is not None:
        student_index_excel = excel.find_student(
            0, sinfo)  # ???Excel
        if student_index_excel == -1:
            run_logger.warning('-------->??:?=' + sinfo.s_id + ',?=' +
                               sinfo.s_class + ',=' + sinfo.s_name + '??')
            return  # ?Excel???

    run_logger.info('-------->??:?=' + sinfo.s_id +
                    ',?=' + sinfo.s_class + ',=' + sinfo.s_name)

    # ???
    fileutil.remove_subdir(uncompress_test_target)  # ????¼
    try:
        uncompressor.decompression(compressed_file, uncompress_test_target)
        run_logger.info('-------->?' + compressed_file +
                        '??' + uncompress_test_target)
    except Exception as e:
        run_logger.error('-------->' + e.__str__())
        return  # ?, ????

    # ?????¼
    run_logger.info('---------------->??=' + sinfo.s_id +
                    ',?=' + sinfo.s_class + ',=' + sinfo.s_name + '?')
    test_dir = parse.find_test_dir(
        uncompress_test_target)  # ?????¼
    if test_dir == '':
        run_logger.error('---------------->?=' + sinfo.s_id + ',?=' +
                         sinfo.s_class + ',=' + sinfo.s_name + '??¼??')
        if record_test_result_to_excel and excel is not None:
            # Excel¼?
            excel.write_cell_in_dataframe(
                0, student_index_excel, excelutil.sheet0_auto_test_detail_excel_col_index, '??¼??')
        else:
            append_fallback_row(
                sinfo, detail='auto test dir missing or invalid')
        return  # ??¼????

    # ??¼test_dir????¼running_test_dir
    fileutil.remove_subdir(running_test_dir)  # ???¼running_test_dir
    fileutil.copy_dir(test_dir, running_test_dir)

    # ?running_test_dir?
    # test_executor = autotest.TestExecutor(test_dir)
    test_executor = autotest.TestExecutor(running_test_dir)
    result = test_executor.run_test()
    if result.code != 0:
        # ???????
        student_error_log_file = sinfo.s_id + '_' + \
            sinfo.s_class + '_' + sinfo.s_name + '_error.log'
        student_error_log_file_full_path = os.path.join(
            logger_path, student_error_log_file)
        fileutil.write_to_file(student_error_log_file_full_path, result.error)

        student_out_log_file = sinfo.s_id + '_' + \
            sinfo.s_class + '_' + sinfo.s_name + '_out.log'
        student_out_log_file_full_path = os.path.join(
            logger_path, student_out_log_file)
        fileutil.write_to_file(student_out_log_file_full_path, result.out)

        run_logger.error('---------------->?=' + sinfo.s_id + ',?=' + sinfo.s_class + ',=' + sinfo.s_name + '??,??' +
                         student_error_log_file_full_path + '' + student_out_log_file_full_path)

    final_result = test_executor.parse_final_result(result)
    if final_result is None:
        run_logger.error('---------------->?=' + sinfo.s_id + ',?=' +
                         sinfo.s_class + ',=' + sinfo.s_name + '?û?õ??')
        if record_test_result_to_excel and excel is not None:
            # Excel¼?
            excel.write_cell_in_dataframe(
                0, student_index_excel, excelutil.sheet0_auto_test_detail_excel_col_index, 'û?õ??')
        else:
            append_fallback_row(sinfo, detail='no final test result')
    else:
        run_logger.info('---------------->?=' + sinfo.s_id + ',?=' + sinfo.s_class + ',=' + sinfo.s_name +
                        '???=' + str(final_result[0]) + ',??=' + str(final_result[1]) + ',?=' + str(final_result[2]))
        if record_test_result_to_excel and excel is not None:
            # Excel¼?
            record_info = str(
                final_result[0]) + '-' + str(final_result[1]) + '-' + str(final_result[2])
            excel.write_cell_in_dataframe(
                0, student_index_excel, excelutil.sheet0_auto_test_detail_excel_col_index, record_info)
        else:
            append_fallback_row(sinfo, final_result=final_result, detail='ok')

    None


def run_auto_test():
    run_logger.info('??' + submit_root_dir + 'µ?')

    # ?????
    compressed_file_list = find_all_submit_files(submit_root_dir)
    # print(compressed_file_list)

    # ÿ???
    for file in compressed_file_list:
        handle_per_compressed_file(file)

    run_logger.info('')
    if record_test_result_to_excel:
        if excel is not None:
            excel.save_to_new_excel(0)
        else:
            if len(fallback_rows) > 0:
                df = pd.DataFrame(fallback_rows, columns=fallback_headers)
                df.to_excel(test_score_excel_file, index=False)
                run_logger.info(
                    'Standalone output Excel written to: ' + test_score_excel_file)
            else:
                run_logger.warning(
                    'No results to write to: ' + test_score_excel_file)

    None


if __name__ == "__main__":
    run_auto_test()
