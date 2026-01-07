package chap02;

public class chap0204_InAndOut {
    public static void main(String[] args) {

        // 출력
        //System.out.println();

        System.out.printf("이름: %s", "김수민");    // println 쓰면 안됨.
        System.out.printf("나이: %d\n\n", 23);         // 형식 줄거면 printf 써야함

        System.out.printf("이름: %1$s, 나이: %2$d", "김수민", 23);
        // 1$ 는 순번을 표시, 생략 가능




        // 입력
        //System.in.read();
    }

}
