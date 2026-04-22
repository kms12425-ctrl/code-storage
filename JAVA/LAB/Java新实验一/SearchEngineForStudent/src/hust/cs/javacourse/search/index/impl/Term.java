package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractTerm;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 * AbstractTerm的具体实现类
 */
public class Term extends AbstractTerm {
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
    public String getContent() {
        // TODO: implement this method
        return null;
    }

    @Override
    public void setContent(String content) {
        // TODO: implement this method
    }

    @Override
    public int compareTo(AbstractTerm o) {
        // TODO: implement this method
        return 0;
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