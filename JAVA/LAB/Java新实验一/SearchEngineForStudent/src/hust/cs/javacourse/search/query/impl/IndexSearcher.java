package hust.cs.javacourse.search.query.impl;

import hust.cs.javacourse.search.index.AbstractTerm;
import hust.cs.javacourse.search.query.AbstractHit;
import hust.cs.javacourse.search.query.AbstractIndexSearcher;
import hust.cs.javacourse.search.query.Sort;

/**
 * AbstractIndexSearcher的具体实现类
 */
public class IndexSearcher extends AbstractIndexSearcher {
    @Override
    public void open(String indexFile) {
        // TODO: implement this method
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm, Sort sorter) {
        // TODO: implement this method
        return null;
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm1, AbstractTerm queryTerm2, Sort sorter,
            LogicalCombination combine) {
        // TODO: implement this method
        return null;
    }
}