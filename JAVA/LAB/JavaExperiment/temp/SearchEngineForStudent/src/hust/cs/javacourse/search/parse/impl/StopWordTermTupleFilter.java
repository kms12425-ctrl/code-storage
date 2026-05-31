package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleFilter;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;
import hust.cs.javacourse.search.util.StopWords;

/**
 * 停用词过滤器
 */
public class StopWordTermTupleFilter extends AbstractTermTupleFilter {
    public StopWordTermTupleFilter(AbstractTermTupleStream input) {
        super(input);
    }

    @Override
    public AbstractTermTuple next() {
        while (true) {
            AbstractTermTuple tuple = input.next();
            if (tuple == null) {
                return null;
            }

            boolean isStopWord = false;
            // 若命中停用词则丢弃该词项
            for (String stopWord : StopWords.STOP_WORDS) {
                if (stopWord.equals(tuple.term.getContent())) {
                    isStopWord = true;
                    break;
                }
            }

            if (!isStopWord) {
                return tuple;
            }
        }
    }
}