package chap02;

public class chap0201_Variables {
    public static void main(String[] args) {
        int x;      //변수 생성되지 않음
        x = 10;     // 값을 넣어야 변수 생성됨

        int hour = 2;
        int minute = 36;
        int totalMinute = hour*60 + minute;
        System.out.println(totalMinute);

        int y = 20;

        x = x^y;
        y = x^y;
        x = x^y;

        if (x>1) {
            int z = 30;     //if블록 안에서 선언한 변수는 밖에서 못씀
            z+=10;            
        }
        // z+=10 은 컴파일 에러. if블록 밖에서는 x가 뭔지 모름
    }

}
