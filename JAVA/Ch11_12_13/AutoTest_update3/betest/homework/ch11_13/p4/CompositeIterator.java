package homework.ch11_13.p4;

import java.util.List;

public class CompositeIterator implements ComponentIterator {
    protected List<ComponentIterator> iterators;

    public CompositeIterator(ComponentIterator iterator) {
        // TODO: 待实现
    }

    @Override
    public boolean hasNext() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public Component next() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }
}
