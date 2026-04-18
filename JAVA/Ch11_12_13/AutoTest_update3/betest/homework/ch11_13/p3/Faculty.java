package homework.ch11_13.p3;

import java.util.Objects;

public class Faculty extends Person {
    private String email;// 邮箱
    private int facultyId;// 教工Id
    private String title;// 职称

    public Faculty() {
        super();
        this.email = "null";
        this.facultyId = 0;
        this.title = "null";
    }

    public Faculty(String name, int age, int facultyId, String title, String email) {
        super(name, age);
        this.email = email;
        this.facultyId = facultyId;
        this.title = title;
    }

    public Object clone() throws CloneNotSupportedException {
        Faculty newFaculty = (Faculty) super.clone();
        newFaculty.email = (email == null) ? null : new String(email);
        newFaculty.facultyId = facultyId;
        newFaculty.title = (title == null) ? null : new String(title);
        return newFaculty;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj != null && getClass() == obj.getClass()) {
            Faculty tmp = (Faculty) obj;
            if (!super.equals(obj))
                return false;
            if (this.facultyId != tmp.facultyId)
                return false;
            if (!Objects.equals(email, tmp.email))
                return false;
            if (!Objects.equals(title, tmp.title))
                return false;
        } else
            return false;
        return true;
    }

    public String getEmail() {
        return this.email;
    }

    public int getFacultyId() {
        return this.facultyId;
    }

    public String getTitle() {
        return this.title;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setFacultyId(int facultyId) {
        this.facultyId = facultyId;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String toString() {
        return super.toString() + "facultyId: " + facultyId + "title: " + title + "email: " + email + "\n";
    }
}
