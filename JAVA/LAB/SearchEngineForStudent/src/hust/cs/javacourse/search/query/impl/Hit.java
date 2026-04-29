package hust.cs.javacourse.search.query.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractTerm;
import hust.cs.javacourse.search.query.AbstractHit;

import java.util.Map;

/**
 * AbstractHit的具体实现类
 */
public class Hit extends AbstractHit {
    @Override
    public int getDocId() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public String getDocPath() {
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
    public double getScore() {
        // TODO: implement this method
        return 0;
    }

    @Override
    public void setScore(double score) {
        // TODO: implement this method
    }

    @Override
    public Map<AbstractTerm, AbstractPosting> getTermPostingMapping() {
        // TODO: implement this method
        return null;
    }

    @Override
    public String toString() {
        // TODO: implement this method
        return null;
    }

    @Override
    public int compareTo(AbstractHit o) {
        // TODO: implement this method
        return 0;
    }
}