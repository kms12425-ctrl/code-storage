package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Collections;
import java.util.List;

/**
 * AbstractPostingList的具体实现类
 */
public class PostingList extends AbstractPostingList {
    @Override
    public void add(AbstractPosting posting) {
        if (!this.contains(posting))
            this.list.add(posting);
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        for (AbstractPosting tmp : this.list) {
            sb.append(tmp.toString());
        }
        return sb.toString();
    }

    @Override
    public void add(List<AbstractPosting> postings) {
        for (AbstractPosting tmp : postings) {
            if (!this.contains(tmp))
                this.add(tmp);
        }
    }

    @Override
    public AbstractPosting get(int index) {
        return this.list.get(index);
    }

    @Override
    public int indexOf(AbstractPosting posting) {
        return this.list.indexOf(posting);
    }

    @Override
    public int indexOf(int docId) {
        for (int i = 0; i < this.list.size(); i++) {
            if (this.list.get(i).getDocId() == docId)
                return i;
        }
        return -1;
    }

    @Override
    public boolean contains(AbstractPosting posting) {
        return this.list.contains(posting);
    }

    @Override
    public void remove(int index) {
        this.list.remove(index);
    }

    @Override
    public void remove(AbstractPosting posting) {
        this.list.remove(posting);
    }

    @Override
    public int size() {
        return this.list.size();
    }

    @Override
    public void clear() {
        this.list.clear();
    }

    @Override
    public boolean isEmpty() {
        return this.list.isEmpty();
    }

    @Override
    public void sort() {
        Collections.sort(this.list);
        for (AbstractPosting tmp : this.list) {
            tmp.sort();
        }
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