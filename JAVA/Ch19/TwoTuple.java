public class TwoTuple<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<TwoTuple<T1, T2>> {
    private T1 first;
    private T2 second;

    TwoTuple(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }

    TwoTuple() {
        this.first = null;
        this.second = null;
    }

    public T1 getFirst() {
        return this.first;
    }

    public void setFirst(T1 first) {
        this.first = first;
    }

    public T2 getSecond() {
        return this.second;
    }

    public void setSecond(T2 second) {
        this.second = second;
    }

    boolean equals(TwoTuple<T1, T2> tmp) {
        return (this.first == tmp.getFirst() && this.second == tmp.getSecond());
    }

    public String toString() {
        return "(" + this.getFirst() + ", " + this.getSecond() + ")";
    }

    public int compareTo(TwoTuple<T1, T2> tmp) {
        if (tmp == null)
            return 1;
        int firstCompre = this.first.compareTo(tmp.getFirst());
        if (firstCompre != 0)
            return firstCompre;
        return this.second.compareTo(tmp.getSecond());
    }
}
