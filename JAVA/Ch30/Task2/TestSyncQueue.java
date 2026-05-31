package Task2;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TestSyncQueue {
    public static void main(String[] args) {
        SyncQueue1<Integer> syncQueue = new SyncQueue1<>();
        Runnable produceTask = () -> {
            for (int count = 0; count < 10; count++) {
                try {
                    List<Integer> list = new ArrayList<>();
                    int elementsCount = (int) (Math.random() * 10) + 1;
                    for (int i = 0; i < elementsCount; i++) {
                        int r = (int) (Math.random() * 10) + 1;
                        list.add(r);
                    }
                    syncQueue.produce(list);

                    StringBuilder sb = new StringBuilder("SyncQueue1 Produce elements:");
                    for (int n : list)
                        sb.append(" ").append(n);
                    System.out.println(sb.toString());

                    Thread.sleep((int) (Math.random() * 5) + 1);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Runnable consumeTask = () -> {
            for (int count = 0; count < 10; count++) {
                try {
                    List<Integer> list = syncQueue.consume();
                    StringBuilder sb = new StringBuilder("SyncQueue1 Consume elements:");
                    for (int n : list)
                        sb.append(" ").append(n);
                    System.out.println(sb.toString());

                    Thread.sleep((int) (Math.random() * 10) + 1);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        ExecutorService es = Executors.newFixedThreadPool(2);
        es.execute(produceTask);
        es.execute(consumeTask);
        es.shutdown();
        while (!es.isTerminated()) {
        }
        SyncQueue2<Integer> syncQueue2 = new SyncQueue2<>();
        Runnable produceTask2 = () -> {
            for (int count = 0; count < 10; count++) {
                try {
                    List<Integer> list2 = new ArrayList<>();
                    int elementsCount = (int) (Math.random() * 5) + 1;
                    for (int i = 0; i < elementsCount; i++) {
                        int r = (int) (Math.random() * 10) + 1;
                        list2.add(r);
                    }
                    syncQueue2.produce(list2);

                    StringBuilder sb = new StringBuilder("SyncQueue2 Produce elements:");
                    for (int n : list2)
                        sb.append(" ").append(n);
                    System.out.println(sb.toString());

                    Thread.sleep((int) (Math.random() * 5) + 1);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Runnable consumeTask2 = () -> {
            for (int count = 0; count < 10; count++) {
                try {
                    List<Integer> list2 = syncQueue2.consume();
                    StringBuilder sb = new StringBuilder("SyncQueue2 Consume elements:");
                    for (int n : list2)
                        sb.append(" ").append(n);
                    System.out.println(sb.toString());

                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        ExecutorService es2 = Executors.newFixedThreadPool(2);
        es2.execute(produceTask2);
        es2.execute(consumeTask2);
        es2.shutdown();
        while (!es2.isTerminated()) {
        }
    }
}
