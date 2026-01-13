package chap02;

import java.util.Scanner;

public class chap0204_InAndOut {
    public static void main(String[] args) throws Exception{

        // 출력
        //System.out.println();

        System.out.printf("이름: %s\n", "김수민");    // println 쓰면 안됨.
        System.out.printf("나이: %d\n\n", 23);         // 형식 줄거면 printf 써야함

        System.out.printf("이름: %1$s, 나이: %2$d\n", "김수민", 23);
        // 1$ 는 순번을 표시, 생략 가능

        System.out.printf("학교: %s, 학과: %s\n\n", "동국대", "컴공");
        System.out.printf("%1$s님이시군요! 반갑습니다 %1$s님!\n\n\n", "김수민");

        // 입력
        //System.in.read();
        
        int keycode = System.in.read();
        System.out.printf("Keycode: "+ keycode);

        while (true) {
            int keycode2 = System.in.read();
            System.out.println("Keycode: "+keycode2);
            if (keycode2 == 113) {
                break;
            }
        }

        // Scanner 쓰기
        // import java.util.scanner 필요함

        Scanner scanner= new Scanner(System.in);
        String inputData;

        while(true) {
            inputData = scanner.nextLine();
            System.out.println("입력된 문자열: " + inputData);
            if (inputData.equals("q") || inputData.equals("Q")) {
                break;
            }
        }

    }

}
