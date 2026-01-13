package chap03;

public class chap0301_operator {
    public static void main(String[] args) throws Exception{

        int x=5; int y=7;

        int result = x + y;
        boolean result2 = (x+y)<5 ;

        //chap0302_typesOfOperator

        byte b =100;
        int a = -b; //+- 연산자는 결과가 int
        long c = (long)-b;

        int k=10;
        int f = k++ +1;     // 11 저장됨
        k=10;
        int g = ++k +1;     // 12 저장됨

        k = f+g;
        k = f*g;
        k = f/g;        // 정수 몫
        k = f%g;        // 정수 나머지

        

    }

}
