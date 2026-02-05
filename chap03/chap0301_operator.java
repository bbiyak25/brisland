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

        char c1 = 'A'+1; // int 계산, 65+1 = 66, B가 저장됨
        int d2 = c1 +2;     // int 계산, 67 나옴

        String s1 = "happy"+7.0;        // happy7.0 저장됨
        
        // String 비교연산자
        String s2 = "안녕하세요";
        String s3 = "햄수탑니다";
        boolean w1 = s2.equals(s1);

        // 논리연산자
        boolean w2 = true;
        boolean w3 = false;

        boolean AND = w2 && w3;
        boolean OR = w2 || w3;
        boolean XOR = w2 ^ w3;      // 둘이 달라야홤
        boolean NOT = !w2;

        // 삼항연산자
        int score = 90;
        String ans;
        if (score > 80) {
            ans = "합격";
        }
        else {
            ans ="불합격";
        }

        String answ = (score > 80) ? "합격" : "불합격";       // 한 줄로 줄여쓰기


        

    }

}
