package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.index.impl.Term;
import hust.cs.javacourse.search.index.impl.TermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleScanner;
import hust.cs.javacourse.search.util.Config;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * AbstractTermTupleScanner的具体实现类
 */
public class TermTupleScanner extends AbstractTermTupleScanner {
    private String[] terms = null;
    private int index = 0;
    private int curPos = 0;

    public TermTupleScanner() {
        super();
    }

    public TermTupleScanner(BufferedReader input) {
        super(input);
    }

    @Override
    public AbstractTermTuple next() {
        try {
            while (true) {
                if (terms != null && index < terms.length) {
                    String termContent = terms[index++];
                    if (termContent == null || termContent.length() == 0) {
                        continue;
                    }

                    // 按配置进行规范化处理（忽略大小写）
                    if (Config.IGNORE_CASE) {
                        termContent = termContent.toLowerCase();
                    }
                    // 构建当前词项及其位置
                    TermTuple tuple = new TermTuple();
                    Term term = new Term();
                    term.setContent(termContent);
                    tuple.term = term;
                    tuple.curPos = curPos++;
                    return tuple;
                }

                // 读取下一行并切分为词项，供后续迭代使用
                String line = input.readLine();
                if (line == null) {
                    return null;
                }

                terms = line.split(Config.STRING_SPLITTER_REGEX);
                index = 0;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}