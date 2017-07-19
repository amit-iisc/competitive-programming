 import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.PriorityQueue;

    /**
     *
     * @author jin
     */
    class sec {

        static class Cell implements Comparable<Cell> {

            int row, col, height;

            Cell(int r, int c, int h) {
                row = r;
                col = c;
                height = h;
            }

            public int compareTo(Cell c) {
                return height - c.height;
            }
        }

        public static void main(String args[]) throws Exception {
            int t = input(), n, m;
            int max, arr[] = new int[2];
            for (int i = 0; i < t; i++) {
                input(arr, 2);
                n = arr[0];
                m = arr[1];
                max = 0;
                int brr[][] = new int[n][m];
                PriorityQueue<Cell> queue = new PriorityQueue<Cell>();
                boolean flag[][] = new boolean[n][m];
                for (int j = 0; j < n; j++) {
                    input(brr[j], m);
                    for (int k = 0; k < m; k++) {
                        if (max < brr[j][k]) {
                            max = brr[j][k];
                        }
                    }
                }

                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        if (brr[j][k] == max) {
                            brr[j][k] = 0;
                            queue.offer(new Cell(j,k , 0));
                            flag[j][k]=true;
                        } else {
                            brr[j][k] = Integer.MAX_VALUE;
                        }

                    }
                }


                int b[] = new int[3];
                b[0] = 0;
                b[1] = 1;
                b[2] = -1;
                int p, q;



                while (!queue.isEmpty()) {
                    Cell cell = queue.poll();
                    int j = cell.row, k = cell.col,h=cell.height+1;
                   // flag = false;
                  //  System.out.println(j+" "+k);

                    for (int l = 0; l < 3; l++) {
                        p = j + b[l];
                        for (int o = 0; o < 3; o++) {
                            q = k + b[o];
                            if (p >= 0 && p < n && q >= 0 && q < m) {
                                if (!flag[p][q]&&brr[p][q] > h) { 
                                     brr[p][q] =h;
                                     flag[p][q]=true;
                                     queue.offer(new Cell(p,q,h));

                                }

                            }

                        }
                    }

                }


                max=0;
                 for (int j = 0; j < n; j++) {
                 //   input(brr[j], m);
                    for (int k = 0; k < m; k++) {

                        if (max < brr[j][k]) {
                            max = brr[j][k];
                        }
                  //      System.out.println(brr[j][k]);


                    }
                }


                 System.out.println(max);

            }

        }

        static BufferedReader br = new BufferedReader(new InputStreamReader(
                System.in));
        private static String s[];

        public static void input(int a[], int p) throws IOException {
            s = br.readLine().split(" ");
            int i;
            for (i = 0; i < p; i++) {
                a[i] = Integer.parseInt(s[i]);
            }

        }

        public static void input(long a[], int p) throws IOException {
            s = br.readLine().split(" ");
            int i;
            for (i = 0; i < p; i++) {
                a[i] = Long.parseLong(s[i]);
            }
        }

        public static void input(double a[], int p) throws IOException {
            s = br.readLine().split(" ");
            int i;
            for (i = 0; i < p; i++) {
                a[i] = Double.parseDouble(s[i]);
            }
        }

        public static int input() throws IOException {
            int a;
            a = Integer.parseInt(br.readLine());
            return a;
        }
    }