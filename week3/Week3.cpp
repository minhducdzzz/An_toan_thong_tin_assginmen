#include <stdio.h>

#define MOD 0x409   // x^10 + x^3 + 1 = 1033

// tìm bậc đa thức
int degree(int x){
    int d = -1;
    while(x){
        x >>= 1;
        d++;
    }
    return d;
}

// nhân đa thức GF(2)
int poly_mul(int a,int b){
    int res = 0;

    while(b){
        if(b & 1)
            res ^= a;

        a <<= 1;
        b >>= 1;
    }

    return res;
}

// mod theo m(x)
int poly_mod(int a){

    while(degree(a) >= 10){
        int shift = degree(a) - 10;
        a ^= (MOD << shift);
    }

    return a;
}

// chia đa thức
int poly_div(int a,int b,int *r){

    int q = 0;

    int da = degree(a);
    int db = degree(b);

    while(da >= db){

        int shift = da - db;

        q ^= (1 << shift);
        a ^= (b << shift);

        da = degree(a);
    }

    *r = a;
    return q;
}

// Euclid mở rộng đúng bảng
int inverse(int b){

    int a = MOD;

    int r_prev = a;
    int r_curr = b;

    int v_prev = 1;
    int v_curr = 0;

    int w_prev = 0;
    int w_curr = 1;

    printf("Step | r(x) | q(x) | v(x) | w(x)\n");

    int step = 0;

    printf("%d | %d | - | %d | %d\n",step,r_prev,v_prev,w_prev);
    step++;

    printf("%d | %d | - | %d | %d\n",step,r_curr,v_curr,w_curr);
    step++;

    while(r_curr != 1){

        int r_next;
        int q = poly_div(r_prev,r_curr,&r_next);

        int v_next = v_prev ^ poly_mul(q,v_curr);
        int w_next = w_prev ^ poly_mul(q,w_curr);

        printf("%d | %d | %d | %d | %d\n",
               step,r_next,q,v_next,w_next);

        r_prev = r_curr;
        r_curr = r_next;

        v_prev = v_curr;
        v_curr = v_next;

        w_prev = w_curr;
        w_curr = w_next;

        step++;
    }

    return poly_mod(w_curr);
}

int main(){

    int a = 523;
    int b = 1015;

    printf("==== a = 523 ====\n");
    int invA = inverse(a);
    printf("a^-1 = %d\n\n",invA);

    printf("==== b = 1015 ====\n");
    int invB = inverse(b);
    printf("b^-1 = %d\n",invB);

    return 0;
}