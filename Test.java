public class Test{
    public static void main(String[] args) {
        int[] arr1 = new int[]{1,2,3};
        int[] arr2 = new int[]{5,6,7};

        arr1 = arr2;
        arr2[0] = 100;

        // for(int i: arr1){
        //     System.out.println(i);
        // }

        System.out.println(arr1 +" "+arr2);
    }
}