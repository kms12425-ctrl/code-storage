package homework.ch11_13.p3;

import java.util.Objects;

public class Student extends Person {
    private int studentId;// 学生Id
    private String department;// s所在院系
    private String classNo;// 所在班级

    public Student() {
        super();
        this.studentId = 0;
        this.department = "null";
        this.classNo = "null";
    }

    public Student(String name, int age, int studentId, String department, String classNo) {
        super(name, age);
        this.studentId = studentId;
        this.department = department;
        this.classNo = classNo;
    }

    public int getStudentId() {
        return studentId;
    }

    public void setStudentId(int studentId) {
        this.studentId = studentId;
    }

    public String getDepartment() {
        return this.department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getClassNo() {
        return classNo;
    }

    public void setClassNo(String classNo) {
        this.classNo = classNo;
    }

    public String toString() {
        return super.toString()
                + ", studentId: " + studentId
                + ", department: " + department
                + ", classNo: " + classNo;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        if (!super.equals(obj))
            return false;
        Student tmp = (Student) obj;
        return this.studentId == tmp.studentId
                && Objects.equals(tmp.department, department)
                && Objects.equals(tmp.classNo, classNo);
    }

    public Object clone() throws CloneNotSupportedException {
        Student newStudent = (Student) super.clone();
        newStudent.classNo = (classNo == null) ? null : new String(classNo);
        newStudent.department = (department == null) ? null : new String(department);
        newStudent.studentId = studentId;
        return newStudent;
    }
}
