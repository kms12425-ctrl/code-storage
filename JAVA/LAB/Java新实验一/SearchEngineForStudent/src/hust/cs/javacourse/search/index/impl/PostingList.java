package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;

/**
 * AbstractPostingList的具体实现类
 */
public class PostingList extends AbstractPostingList {
    @Override
    public void add(AbstractPosting posting) {
        // TODO: implement this method
    }

    @Override
    public String toString() {
        // TODO: implement this method
        return null;
    }

    @Override
    public void add(List<AbstractPosting> postings) {
        // TODO: implement this method
    }

    @Override
    public AbstractPosting get(int index) {
        // TODO: implement this method
        return null;
    }

    @Override
    public int indexOf(AbstractPosting posting) {
        // TODO: implement this method
        return 0;
    }

    @Override
    public int indexOf(int docId) {
        // TODO: implement this method
        return 0;
    }

    @Override
    public boolean contains(AbstractPosting posting) {
        // TODO: implement this method
        return false;
    }

    @Override
    public void remove(int index) {
        // TODO: implement this method
    }

    @Override
    public void remove(AbstractPosting posting) {
        // TODO: implement this method
    }

    @Override
    public int size() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public void clear() {
        // TODO: implement this method
    }

    @Override
    public boolean isEmpty() {
        // TODO: implement this method
        return false;
    }

    @Override
    public void sort() {
        // TODO: implement this method
    }

    @Override
    public void writeObject(ObjectOutputStream out) {
        // TODO: implement this method
    }

    @Override
    public void readObject(ObjectInputStream in) {
        // TODO: implement this method
    }
}