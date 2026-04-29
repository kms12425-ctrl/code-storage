package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleScanner;

import java.io.BufferedReader;

/**
 * AbstractTermTupleScanner的具体实现类
 */
public class TermTupleScanner extends AbstractTermTupleScanner {
    public TermTupleScanner() {
        super();
    }

    public TermTupleScanner(BufferedReader input) {
        super(input);
    }

    @Override
    public AbstractTermTuple next() {
        // TODO: implement this method
        return null;
    }
}