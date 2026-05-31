# encoding: latin-1

import zipfile
import fileutil
import os
import exception


def unzip(zipfile_name, dest_folder):
    """
        ��ѹzip�ļ�
        zipfile_name    ��   zip�ļ���
        dest_folder     ��   ��ѹ����Ŀ¼
    """
    # print('unzip ' + zipfile_name + ' to ' + dest_folder)
    zip_file = None
    try:
        zip_file = zipfile.ZipFile(zipfile_name)
        zip_list = zip_file.namelist()  # �õ�ѹ�����������ļ�
        for f in zip_list:
            zip_file.extract(f, dest_folder)  # ѭ����ѹ�ļ���ָ��Ŀ¼
    except Exception as e:
        # print(e)
        raise exception.UncompressError('��ѹ����:' + e.__str__())

    if zip_file is None:
        return
    else:
        zip_file.close()  # �ر��ļ��������У��ͷ��ڴ�


def unrar(rarfile_name, dest_folder):
    """
        ��ѹrar�ļ�
        rarfile_name    ��   rar�ļ���
        dest_folder     ��   ��ѹ����Ŀ¼
    """
    try:
        from unrar import rarfile
        rf = rarfile.RarFile(rarfile_name, mode='r')  # mode��ֵֻ��Ϊ'r'
        rf_list = rf.namelist()  # �õ�ѹ���������е��ļ�
        for f in rf_list:
            rf.extract(f, dest_folder)  # ѭ����ѹ�����ļ���ѹ��ָ��·��
    except (ImportError, LookupError) as e:
        raise exception.UncompressError(
            'unrar dependency missing or not configured: ' + e.__str__())
    except Exception as e:
        raise exception.UncompressError('��ѹ����:' + e.__str__())

    # print('unrar ' + rarfile_name + ' to ' + dest_folder)


def decompression(file_full_path, dest_folder):
    """
    �ݹ��ѹѹ���ļ���Ŀ��Ŀ¼
    :param file_full_path:  ѹ���ļ���ȫ·��
    :param dest_folder: Ŀ��Ŀ¼
    :return:
    """
    file_suffix = fileutil.find_file_suffix(file_full_path)
    # print(file_suffix)
    if file_suffix == '.zip':
        unzip(file_full_path, dest_folder)
    elif file_suffix == '.rar':
        unrar(file_full_path, dest_folder)
    else:
        compress_format_error = exception.CompressFormatError('ѹ����ʽ��ʶ��')
        raise compress_format_error  # �׳��쳣

    # �ݹ��ҵ�Ŀ��Ŀ¼������ѹ���ļ�
    file_list = fileutil.find_compressed_files(dest_folder)
    for f in file_list:
        file_tuple = tuple(f)
        parent_dir_full_path = file_tuple[0]
        f_name = file_tuple[1]
        f_suffix = file_tuple[2]
        f_full_path = os.path.join(
            parent_dir_full_path, f_name + f_suffix)  # ѹ���ļ�����ȫ·��
        target_full_path = os.path.join(
            parent_dir_full_path, f_name)  # ѹ���ļ�Ҫ��ѹ����Ŀ��Ŀ¼
        if not os.path.exists(target_full_path):
            os.mkdir(target_full_path)
        decompression(f_full_path, target_full_path)
    # print('extract ' + file_full_path + ' to ' + dest_folder)
