// Tips：注意检查输入参数row的值，当输入负数，0时如何处理也考虑进来，如何处理这种情况不做要求，可以简单地打印出提示信息，或者抛出异常。
// 但最简单的办法就是当出现这些边界条件，直接返回null引用就行了。
// 由这个方法的调用者去处理。另外也不考虑当row的值太大导致内存溢出的情况。

import java.util.Scanner;

public class Test3 {
    /**
     * 创建一个不规则二维数组
     * 第一行row列
     * 第二行row - 1列
     * ...
     * 最后一行1列
     * 数组元素值都为默认值
     * 
     * @param row 行数
     * @return 创建好的不规则数组
     */
    public static int[][] createArray(int row) {
        int[][] arr = new int[row][];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new int[arr.length - i];
        }
        return arr;
    }

    /**
     * 逐行打印出二维数组，数组元素之间以空格分开
     * 
     * @param a
     */
    public static void printArray(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length - i; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner ans = new Scanner(System.in);
        int num = ans.nextInt();
        ans.close();
        if (num <= 0) {
            System.err.println("非法参数");
        } else {
            int[][] arr = createArray(num);
            printArray(arr);
        }
    }
}
