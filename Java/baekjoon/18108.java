// 스캐너 써도 됨 근데 스캐너 쪽이 느림

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");


        int years = Integer.parseInt(st.nextToken());

        years = years - 543;

        System.out.println(years);


    }
}