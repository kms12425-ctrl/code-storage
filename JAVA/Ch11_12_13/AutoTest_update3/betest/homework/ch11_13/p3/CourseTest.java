package homework.ch11_13.p3;

public class CourseTest extends Object {
    public static void main(String[] args) throws CloneNotSupportedException {
        Faculty teacher1 = new Faculty("James Gosling", 65, 20190001, "Professor",
                "http://nighthacks.com/jag/bio/index.html");
        Faculty teacher2 = new Faculty("Bjarne Stroustrup", 70, 20190002, "Professor", "http://example.com/bjarne");

        Course javaCourse = new Course("Java Language Programming", teacher1);
        Course cppCourse = new Course("C++ Language Programming", teacher2);

        Student s1 = new Student("aaa", 20, 20170101, "CS", "CS1704");
        Student s2 = new Student("bbb", 20, 20170102, "CS", "CS1705");
        Student s3 = new Student("ccc", 20, 20170103, "CS", "CS1706");
        Student s4 = new Student("ddd", 21, 20170104, "CS", "CS1707");
        Student s5 = new Student("eee", 21, 20170105, "CS", "CS1708");
        Student s6 = new Student("fff", 21, 20170106, "CS", "CS1709");

        javaCourse.register(s1);
        javaCourse.register(s2);
        javaCourse.register(s3);

        cppCourse.register(s4);
        cppCourse.register(s5);
        cppCourse.register(s6);

        Course[] courses = new Course[] { javaCourse, cppCourse };
        System.out.println("=== Course Details ===");
        for (int i = 0; i < courses.length; i++) {
            System.out.println("----- course[" + i + "] -----");
            System.out.println(courses[i]);
        }

        System.out.println("=== Deep Copy Tests ===");

        Person p = new Person("Tom", 30);
        Person pClone = (Person) p.clone();
        System.out.println("Person equals: " + p.equals(pClone));
        System.out.println("Person same object: " + (p == pClone));
        System.out.println("Person name reference same: " + (p.getName() == pClone.getName()));

        Student st = new Student("Stu", 22, 1001, "Math", "M101");
        Student stClone = (Student) st.clone();
        System.out.println("Student equals: " + st.equals(stClone));
        System.out.println("Student same object: " + (st == stClone));
        System.out.println("Student name reference same: " + (st.getName() == stClone.getName()));
        System.out.println("Student department reference same: " + (st.getDepartment() == stClone.getDepartment()));
        System.out.println("Student classNo reference same: " + (st.getClassNo() == stClone.getClassNo()));

        Faculty f = new Faculty("Prof", 50, 2001, "Lecturer", "prof@example.com");
        Faculty fClone = (Faculty) f.clone();
        System.out.println("Faculty equals: " + f.equals(fClone));
        System.out.println("Faculty same object: " + (f == fClone));
        System.out.println("Faculty name reference same: " + (f.getName() == fClone.getName()));
        System.out.println("Faculty title reference same: " + (f.getTitle() == fClone.getTitle()));
        System.out.println("Faculty email reference same: " + (f.getEmail() == fClone.getEmail()));

        Course javaCourseClone = (Course) javaCourse.clone();
        boolean studentsDeepCopied = true;
        for (int i = 0; i < javaCourse.getStudents().size(); i++) {
            if (javaCourse.getStudents().get(i) == javaCourseClone.getStudents().get(i)) {
                studentsDeepCopied = false;
                break;
            }
        }

        System.out.println("Course equals: " + javaCourse.equals(javaCourseClone));
        System.out.println("Course same object: " + (javaCourse == javaCourseClone));
        System.out.println(
                "CourseName reference same: " + (javaCourse.getCourseName() == javaCourseClone.getCourseName()));
        System.out.println("Teacher reference same: " + (javaCourse.getTeacher() == javaCourseClone.getTeacher()));
        System.out.println(
                "Students list reference same: " + (javaCourse.getStudents() == javaCourseClone.getStudents()));
        System.out.println("Every student element deep copied: " + studentsDeepCopied);

        System.out.println("Original course:\n" + javaCourse);
        System.out.println("Cloned course:\n" + javaCourseClone);
    }
}
