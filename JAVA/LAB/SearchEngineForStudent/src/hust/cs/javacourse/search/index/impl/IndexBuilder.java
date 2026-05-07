package hust.cs.javacourse.search.index.impl;

import java.io.File;

import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.AbstractDocumentBuilder;
import hust.cs.javacourse.search.index.AbstractIndex;
import hust.cs.javacourse.search.index.AbstractIndexBuilder;
import hust.cs.javacourse.search.util.Config;
import hust.cs.javacourse.search.util.FileUtil;

/**
 * AbstractIndexBuilder的具体实现类
 */
public class IndexBuilder extends AbstractIndexBuilder {
    public IndexBuilder(AbstractDocumentBuilder docBuilder) {
        super(docBuilder);
    }

    @Override
    public AbstractIndex buildIndex(String rootDirectory) {
        Index index = new Index();

        for (String filepath : FileUtil.list(rootDirectory, ".txt")) {
            File file = new File(filepath);
            AbstractDocument document = this.docBuilder.build(docId, file.getPath(), file);
            index.addDocument(document);
            this.docId++;
        }
        index.optimize();
        index.save(new File(Config.INDEX_DIR + "index.dat"));
        return index;
    }
}