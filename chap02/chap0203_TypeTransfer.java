package chap02;

public class chap0203_TypeTransfer {

    public static void main(String[] args) {
        byte var1 = 10;
        int var2 = var1;        //타입변환 byte -> int

        char var3 = 'A';
        int var4 = var3;
        System.out.println(var4);           //유니코드 값인 65가 나옴

        /* ------------------------------------------- */

        int var5 = 65;
        char var6 = (char) var5;            // 강제 타입변환. 원래는 컴파일 오류남. A가 저장됨

        double var7 = 3.14;
        int var8 = (int)var7;               //강제. 3만 저장됨. 무조건 데이터 크기순대로 변환

        int var9 = 70;
        double var10 = 3.11;
        double var11 = var9 + var10;        // 더블이 더 크니깐 double로 계산해야함
        int var12 = var9 + (int)var10;      // int 계산하려면 이렇게

        /* ------------------------------------------- */

        String var13 = "1" + 2 + 3;
        System.out.println(var13);          // String으로 강제변환해서 123 나옴  
        String var14 = "1" + (2+3);         // 괄호를 먼저 연산해서 15가 나옴
        
        String var15 = "10";
        int var16 = Integer.parseInt(var15);    // 문자열->int 강제변환

        String var17 = "300000000";
        long var18 = Long.parseLong(var17);

        String var19 = "10.256";
        double var20 = Double.parseDouble(var19);

        String var21 = String.valueOf(10);      // 숫자 10을 String으로 저장
        String var22 = String.valueOf(10.125);

        System.out.println(var21+","+var22);

    }
}
