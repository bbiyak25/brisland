package chap04;

public class chap0401_conditional {
    public static void main(String[] args) {
        int randie = (int) (Math.random()*10);
        System.out.println(randie);

        if (randie > 5) {
            System.out.println("5 미만입니다.");
        }
        else {
            System.out.println("5 이상입니다");
        }

        randie = (int) (Math.random()*67);
        switch (randie) {
            case 1:
                System.out.println("1입니다.");
                break;
            case 2:
                System.out.println("2입니다.");
                break;
            default:
                System.out.println("1도 2도 아닙니다.");
            }

        // 문자도 가능
        char c1 = 'A';
        switch (c1) {
            case 'A':
                System.out.println("햄부기");
                break;
            case 'B':
                System.out.println("햄수타");
                break;

        }


    }
}
