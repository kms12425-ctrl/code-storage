package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.AbstractTermTuple;

import java.util.List;

/**
 * AbstractDocument的具体实现类
 */
public class Document extends AbstractDocument {
    @Override
    public int getDocId() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public void setDocId(int docId) {
        // TODO: implement this method
    }

    @Override
    public String getDocPath() {
        // TODO: implement this method
        return null;
    }

    @Override
    public void setDocPath(String docPath) {
        // TODO: implement this method
    }

    @Override
    public List<AbstractTermTuple> getTuples() {
        // TODO: implement this method
        return null;
    }

    @Override
    public void addTuple(AbstractTermTuple tuple) {
        // TODO: implement this method
    }

    @Override
    public boolean contains(AbstractTermTuple tuple) {
        // TODO: implement this method
        return false;
    }

    @Override
    public AbstractTermTuple getTuple(int index) {
        // TODO: implement this method
        return null;
    }

    @Override
    public int getTupleSize() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public String toString() {
        // TODO: implement this method
        return null;
    }
}