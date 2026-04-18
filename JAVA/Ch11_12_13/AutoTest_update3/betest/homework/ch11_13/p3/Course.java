package homework.ch11_13.p3;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Course extends Object implements Cloneable {
    private String courseName;
    private List<Person> students;
    private Person teacher;

    public Course(String courseName, Person teacher) {
        this.courseName = courseName;
        this.teacher = teacher;
        this.students = new ArrayList<>();
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Course tmp = (Course) obj;
        if (tmp.getNumberOfStudent() != getNumberOfStudent())
            return false;

        return Objects.equals(tmp.courseName, courseName) && tmp.teacher.equals(teacher)
                && tmp.students.containsAll(students);
    }

    public Object clone() throws CloneNotSupportedException {
        Course newCourse = (Course) super.clone();
        newCourse.courseName = (courseName == null) ? null : new String(courseName);
        newCourse.teacher = (Person) teacher.clone();

        List<Person> newList = new ArrayList<>();
        for (Person p : students) {
            newList.add((Person) p.clone());
        }
        newCourse.students = newList;

        return newCourse;
    }

    public void register(Person s) {
        // 查重
        for (Person stu : students) {
            if (stu.equals(s)) {
                System.out.println("This student is already in the class");
                return;
            }
        }
        // 插入
        students.add(s);
    }

    public String getCourseName() {
        return this.courseName;
    }

    public List<Person> getStudents() {
        return students;
    }

    public Person getTeacher() {
        return this.teacher;
    }

    public void unregister(Person s) {
        students.remove(s);
    }

    public int getNumberOfStudent() {
        return this.students.size();
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("courseName: ").append(courseName).append("\n")
                .append(", Teacher Info: ").append(teacher.toString()).append("\n")
                .append(", Student List: \n");
        if (students != null) {
            for (int i = 0; i < students.size(); i++) {
                sb.append("    ").append(students.get(i).toString()).append("\n");
            }
        }
        sb.append("Totally: " + getNumberOfStudent() + "students.\n");
        return sb.toString();
    }
}
