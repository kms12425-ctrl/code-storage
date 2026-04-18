package homework.ch11_13.p4;

public abstract class Component {
    protected int id;
    protected String name;
    protected double price;

    public Component() {
        id = 0;
        name = "null";
        price = 0.0;
    }

    public Component(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public abstract void add(Component component) throws UnsupportedOperationException;

    public abstract void remove(Component component) throws UnsupportedOperationException;

    public abstract double calcPrice();

    public abstract ComponentIterator createIterator();

    @Override
    public boolean equals(Object obj) {
        // TODO: 待实现
        throw new UnsupportedOperationException("TODO: 未实现");
    }

    @Override
    public String toString() {

    }
}
