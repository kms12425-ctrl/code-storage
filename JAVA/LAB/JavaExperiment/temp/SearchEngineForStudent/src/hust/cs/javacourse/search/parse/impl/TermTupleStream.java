package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;

/**
 * AbstractTermTupleStream的具体实现类
 */
public class TermTupleStream extends AbstractTermTupleStream {
    private final AbstractTermTupleStream input;

    public TermTupleStream(AbstractTermTupleStream input) {
        this.input = input;
    }

    @Override
    public AbstractTermTuple next() {
        return input.next();
    }

    @Override
    public void close() {
        input.close();
    }
}