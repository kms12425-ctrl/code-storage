package homework.ch11_13.p4;

public class CompositeComponent extends Component {
    protected ComponentList children;

    public CompositeComponent() {
        super();
        // TODO: 待实现
    }

    public CompositeComponent(int id, String name, double price) {
        super(id, name, price);
        // TODO: 待实现
    }

    @Override
    public void add(Component component) throws UnsupportedOperationException {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public void remove(Component component) throws UnsupportedOperationException {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public double calcPrice() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public ComponentIterator createIterator() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public String toString() {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }
}
