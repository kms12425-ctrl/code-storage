package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractPosting;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;

/**
 * AbstractPosting的具体实现类
 */
public class Posting extends AbstractPosting {
    @Override
    public boolean equals(Object obj) {
        // TODO: implement this method
        return false;
    }

    @Override
    public String toString() {
        // TODO: implement this method
        return null;
    }

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
    public int getFreq() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public void setFreq(int freq) {
        // TODO: implement this method
    }

    @Override
    public List<Integer> getPositions() {
        // TODO: implement this method
        return null;
    }

    @Override
    public void setPositions(List<Integer> positions) {
        // TODO: implement this method
    }

    @Override
    public int compareTo(AbstractPosting o) {
        // TODO: implement this method
        return 0;
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