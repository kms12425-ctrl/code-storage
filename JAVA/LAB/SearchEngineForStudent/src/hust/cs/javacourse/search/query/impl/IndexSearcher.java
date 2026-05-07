package hust.cs.javacourse.search.query.impl;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;
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
        this.index.load(new File(indexFile));
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm, Sort sorter) {
        AbstractPostingList postingList = this.index.search(queryTerm);
        if (postingList == null || postingList.isEmpty()) {
            return new AbstractHit[0];
        }

        List<AbstractHit> hits = new ArrayList<AbstractHit>();

        for (int i = 0; i < postingList.size(); i++) {
            AbstractPosting posting = postingList.get(i);

            Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
            map.put(queryTerm, posting);

            Hit hit = new Hit(posting.getDocId(), this.index.getDocName(posting.getDocId()), map);
            hit.setScore(sorter.score(hit));
            hits.add(hit);
        }

        sorter.sort(hits);
        return hits.toArray(new AbstractHit[0]);
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm1, AbstractTerm queryTerm2, Sort sorter,
            LogicalCombination combine) {

        AbstractPostingList list1 = this.index.search(queryTerm1);
        AbstractPostingList list2 = this.index.search(queryTerm2);

        // 获取列表大小，防止某些 Term 没有命中导致返回 null 的情况
        int size1 = (list1 == null) ? 0 : list1.size();
        int size2 = (list2 == null) ? 0 : list2.size();

        if (combine == LogicalCombination.AND) {
            if (size1 == 0 || size2 == 0) {
                return new AbstractHit[0];
            }

            List<AbstractHit> hits = new ArrayList<AbstractHit>();
            int i = 0;
            int j = 0;

            while (i < size1 && j < size2) {
                AbstractPosting p1 = list1.get(i);
                AbstractPosting p2 = list2.get(j);

                if (p1.getDocId() == p2.getDocId()) {
                    Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                    map.put(queryTerm1, p1);
                    map.put(queryTerm2, p2);

                    Hit hit = new Hit(p1.getDocId(), this.index.getDocName(p1.getDocId()), map);
                    hit.setScore(sorter.score(hit));
                    hits.add(hit);

                    i++;
                    j++;
                } else if (p1.getDocId() < p2.getDocId()) {
                    i++;
                } else {
                    j++;
                }
            }

            sorter.sort(hits);
            return hits.toArray(new AbstractHit[0]);

        } else { // LogicalCombination.OR
            List<AbstractHit> hits = new ArrayList<AbstractHit>();
            int i = 0;
            int j = 0;

            while (i < size1 && j < size2) {
                AbstractPosting p1 = list1.get(i);
                AbstractPosting p2 = list2.get(j);

                if (p1.getDocId() == p2.getDocId()) { // 两个词都出现了
                    Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                    map.put(queryTerm1, p1);
                    map.put(queryTerm2, p2);
                    Hit hit = new Hit(p1.getDocId(), this.index.getDocName(p1.getDocId()), map);
                    hit.setScore(sorter.score(hit));
                    hits.add(hit);
                    i++;
                    j++;
                } else if (p1.getDocId() < p2.getDocId()) { // 只出现了 term1
                    Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                    map.put(queryTerm1, p1);
                    Hit hit = new Hit(p1.getDocId(), this.index.getDocName(p1.getDocId()), map);
                    hit.setScore(sorter.score(hit));
                    hits.add(hit);
                    i++;
                } else { // 只出现了 term2
                    Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                    map.put(queryTerm2, p2);
                    Hit hit = new Hit(p2.getDocId(), this.index.getDocName(p2.getDocId()), map);
                    hit.setScore(sorter.score(hit));
                    hits.add(hit);
                    j++;
                }
            }

            // 把 list1 剩余 posting 全部转成 hit
            while (i < size1) {
                AbstractPosting p1 = list1.get(i);
                Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                map.put(queryTerm1, p1);
                Hit hit = new Hit(p1.getDocId(), this.index.getDocName(p1.getDocId()), map);
                hit.setScore(sorter.score(hit));
                hits.add(hit);
                i++;
            }

            // 把 list2 剩余 posting 全部转成 hit
            while (j < size2) {
                AbstractPosting p2 = list2.get(j);
                Map<AbstractTerm, AbstractPosting> map = new TreeMap<AbstractTerm, AbstractPosting>();
                map.put(queryTerm2, p2);
                Hit hit = new Hit(p2.getDocId(), this.index.getDocName(p2.getDocId()), map);
                hit.setScore(sorter.score(hit));
                hits.add(hit);
                j++;
            }

            // 对 hits 打分并排序，然后返回数组
            sorter.sort(hits);
            return hits.toArray(new AbstractHit[0]);
        }
    }
}