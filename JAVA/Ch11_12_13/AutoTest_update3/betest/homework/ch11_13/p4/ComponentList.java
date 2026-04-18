package homework.ch11_13.p4;

import java.util.ArrayList;

public class ComponentList extends ArrayList<Component> implements ComponentIterator {
    private int position;

    public ComponentList() {
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

    public ComponentIterator createIterator() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }
}
