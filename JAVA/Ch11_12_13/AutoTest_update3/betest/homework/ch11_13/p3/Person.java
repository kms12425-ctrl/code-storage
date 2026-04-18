package homework.ch11_13.p3;

import java.util.Objects;

public class Person extends Object implements Cloneable {
    private String name;
    private int age;

    public Person() {
        this.age = 0;
        this.name = "null";
    }

    public Person(String name, int age) {
        this.age = age;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return this.age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String toString() {
        return "name: " + name + ", age: " + age + " ";
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Person tmp = (Person) obj;
        return age == tmp.age && Objects.equals(tmp.name, this.name);
    }

    public Object clone() throws CloneNotSupportedException {
        Person newPerson = (Person) super.clone();
        newPerson.age = age;
        newPerson.name = (name == null) ? null : new String(name);
        return newPerson;
    }
}
