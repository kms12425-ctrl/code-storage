package Task3;

public class ReusableThread extends Thread {
    private Runnable runTask = null; // 保存接受的线程任务

    // 只定义不带参数的构造函数
    public ReusableThread() {
        super();
    }

    /**
     * 覆盖Thread类的run方法
     */
    @Override
    public void run() {
        while (true) {
            synchronized (this) {
                try {
                    while (runTask == null) {
                        wait();
                    }
                    runTask.run();
                    runTask = null;
                    notifyAll();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    break;
                }

            }
        }
    }

    /**
     * 提交新的任务
     * 
     * @param task 要提交的任务
     */
    public synchronized void submit(Runnable task) {
        try {
            // 如果上一个任务还没执行完，等待它执行完
            while (runTask != null) {
                wait();
            }
            // 提交新任务并唤醒正在等待的 run() 线程
            runTask = task;
            notifyAll();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
