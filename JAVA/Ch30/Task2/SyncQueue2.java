package Task2;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 一个线程安全同步队列，模拟多线程环境下的生产者消费者机制
 * 一个生产者线程通过produce方法向队列里产生元素
 * 一个消费者线程通过consume方法从队列里消费元素
 * 
 * @param <T> 元素类型
 */
public class SyncQueue2<T> {
    /**
     * 保存队列元素
     */
    private ArrayList<T> list = new ArrayList<>();

    private final Lock lock = new ReentrantLock();
    private final Condition notEmpty = lock.newCondition();

    /**
     * 生产数据
     * 
     * @param elements 生产出的元素列表，需要将该列表元素放入队列
     * @throws InterruptedException
     */
    public void produce(List<T> elements) {
        lock.lock();
        try {
            for (T element : elements) {
                list.add(element);
            }
            notEmpty.signalAll();
        } finally {
            lock.unlock();
        }
    }

    /**
     * 消费数据
     * 
     * @return 从队列中取出的数据
     * @throws InterruptedException
     */
    public List<T> consume() throws InterruptedException {
        lock.lock();
        try {
            while (list.isEmpty()) {
                notEmpty.await();
            }
            List<T> res = new ArrayList<>(list);
            list.clear();
            return res;
        } finally {
            lock.unlock();
        }
    }
}
