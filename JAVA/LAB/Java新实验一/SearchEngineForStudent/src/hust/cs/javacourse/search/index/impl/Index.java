package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.index.AbstractIndex;
import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;
import hust.cs.javacourse.search.index.AbstractTerm;
import java.io.File;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Set;

/**
 * AbstractIndex的具体实现类
 */
public class Index extends AbstractIndex {
    /**
     * 返回索引的字符串表示
     *
     * @return 索引的字符串表示
     */
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append("docIdToDocPathMapping: \n");
        for (Integer id : this.docIdToDocPathMapping.keySet()) {
            sb.append(id).append("->").append(this.docIdToDocPathMapping.get(id)).append("\n");
        }
        sb.append("termToPostingListMapping: \n");
        for (AbstractTerm term : this.termToPostingListMapping.keySet()) {
            sb.append(term.toString()).append("->").append(this.termToPostingListMapping.get(term).toString())
                    .append("\n");
        }
        return sb.toString();
    }

    /**
     * 添加文档到索引，更新索引内部的HashMap
     *
     * @param document ：文档的AbstractDocument子类型表示
     */
    @Override
    public void addDocument(AbstractDocument document) {
        this.docIdToDocPathMapping.put(document.getDocId(), document.getDocPath());

        for (AbstractTermTuple tmp : document.getTuples()) {
            PostingList postingList = (PostingList) this.termToPostingListMapping.get(tmp.term);

            if (postingList == null) {
                postingList = new PostingList();
                this.termToPostingListMapping.put(tmp.term, postingList);
            }

            int i = postingList.indexOf(document.getDocId());

            if (i == -1) {
                Posting posting = new Posting(document.getDocId(), 1, new ArrayList<Integer>());
                posting.getPositions().add(tmp.curPos);
                postingList.add(posting);
            } else {
                AbstractPosting posting = postingList.get(i);
                posting.setFreq(posting.getFreq() + 1);
                posting.getPositions().add(tmp.curPos);
            }
        }
    }

    /**
     * <pre>
     * 从索引文件里加载已经构建好的索引.内部调用FileSerializable接口方法readObject即可
     * @param file ：索引文件
     * </pre>
     */
    @Override
    public void load(File file) {
        // TODO: implement this method
    }

    /**
     * <pre>
     * 将在内存里构建好的索引写入到文件. 内部调用FileSerializable接口方法writeObject即可
     * @param file ：写入的目标索引文件
     * </pre>
     */
    @Override
    public void save(File file) {
        // TODO: implement this method
    }

    /**
     * 返回指定单词的PostingList
     *
     * @param term : 指定的单词
     * @return ：指定单词的PostingList;如果索引字典没有该单词，则返回null
     */
    @Override
    public AbstractPostingList search(AbstractTerm term) {
        return this.termToPostingListMapping.get(term);
    }

    /**
     * 返回索引的字典.字典为索引里所有单词的并集
     *
     * @return ：索引中Term列表
     */
    @Override
    public Set<AbstractTerm> getDictionary() {
        return this.termToPostingListMapping.keySet();
    }

    /**
     * <pre>
     * 对索引进行优化，包括：
     *      对索引里每个单词的PostingList按docId从小到大排序
     *      同时对每个Posting里的positions从小到大排序
     * 在内存中把索引构建完后执行该方法
     * </pre>
     */
    @Override
    public void optimize() {
        // TODO: implement this method
    }

    /**
     * 根据docId获得对应文档的完全路径名
     *
     * @param docId ：文档id
     * @return : 对应文档的完全路径名
     */
    @Override
    public String getDocName(int docId) {
        return this.docIdToDocPathMapping.get(docId);
    }

    /**
     * 写到二进制文件
     *
     * @param out :输出流对象
     */
    @Override
    public void writeObject(ObjectOutputStream out) {
        // TODO: implement this method
    }

    /**
     * 从二进制文件读
     *
     * @param in ：输入流对象
     */
    @Override
    public void readObject(ObjectInputStream in) {
        // TODO: implement this method
    }
}
