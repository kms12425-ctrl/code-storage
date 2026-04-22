package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleFilter;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;

/**
 * 停用词过滤器
 */
public class StopWordTermTupleFilter extends AbstractTermTupleFilter {
    public StopWordTermTupleFilter(AbstractTermTupleStream input) {
        super(input);
    }

    @Override
    public AbstractTermTuple next() {
        // TODO: implement this method
        return null;
    }
}