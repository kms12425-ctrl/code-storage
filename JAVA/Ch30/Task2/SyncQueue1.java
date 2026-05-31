package Task2;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 一个线程安全同步队列，模拟多线程环境下的生产者消费者机制
 * 一个生产者线程通过produce方法向队列里产生元素
 * 一个消费者线程通过consume方法从队列里消费元素
 * 
 * @param <T> 元素类型
 */
public class SyncQueue1<T> {
    /**
     * 保存队列元素
     */
    private ArrayList<T> list = new ArrayList<>();

    public synchronized void produce(List<T> elements) throws InterruptedException {
        while (!list.isEmpty()) {
            wait();
        }
        for (T element : elements) {
            list.add(element);
        }

        notifyAll();
    }

    public synchronized List<T> consume() throws InterruptedException {
        while (list.isEmpty()) {
            wait();
        }
        List<T> result = new ArrayList<>(list);
        list.clear();
        notifyAll(); // 唤醒等待的生产者线程
        return result;
    }
}
