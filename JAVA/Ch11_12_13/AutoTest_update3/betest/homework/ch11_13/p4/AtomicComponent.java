package homework.ch11_13.p4;

public class AtomicComponent extends Component {
    public AtomicComponent() {
        super();
        // TODO: 待实现
    }

    public AtomicComponent(int id, String name, double price) {
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
}
