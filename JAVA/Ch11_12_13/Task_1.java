import java.util.ArrayList;

public class Task_1 {
    public static void main(String[] args) {
        TaskService list1 = new TaskServiceImpl();
        list1.addTask(new Task_a());
        list1.addTask(new Task_b());
        list1.addTask(new Task_c());

        TaskService list2 = new TaskServiceImpl();
        list2.addTask(new Task_b());
        list2.addTask(new Task_b());

        System.out.println("Execute list1:");
        list1.executeTasks();

        System.out.println("Execute list2:");
        list2.executeTasks();
    }

    /**
     * 任务接口
     * 
     * @author crackryan
     */
    public interface Task {
        /**
         * 执行具体任务的接口方法
         */
        public abstract void execute();
    }

    public static class Task_a implements Task {
        public void execute() {
            System.out.println("This is the First Task that is implemented from the class'Task'");
        }
    }

    public static class Task_b implements Task {
        public void execute() {
            System.out.println("This is the Second Task that is implemented from the class'Task'");
        }
    }

    public static class Task_c implements Task {
        public void execute() {
            System.out.println("This is the Third Task that is implemented from the class'Task'");
        }
    }

    /**
     * 任务服务接口
     * 
     * @author crackryan
     */
    public interface TaskService {
        /**
         * 执行任务接口列表中的每个任务
         */
        public void executeTasks();

        /**
         * 添加任务
         * 
         * @param t 新添加的任务
         */
        public void addTask(Task t);
    }

    public static class TaskServiceImpl implements TaskService {
        private ArrayList<Task> list;

        TaskServiceImpl() {
            list = new ArrayList<>();
        }

        public void executeTasks() {
            for (int i = 0; i < list.size(); i++) {
                Task tmp = list.get(i);
                tmp.execute();
            }
        }

        public void addTask(Task t) {
            list.add(t);
        }
    }

}