
#include <stdio.h>

int IP[] = {2,6,3,1,4,8,5,7};
int IP1[] = {4,1,3,5,7,2,8,6};
int EP[] = {4,1,2,3,2,3,4,1};
int P4[] = {2,4,3,1};
int S0[4][4] = {
{1,0,3,2},{3,2,1,0},
{0,2,1,3},{3,1,3,2}
};
int S1[4][4] = {
{0,1,2,3},{2,0,1,3},
{3,0,1,0},{2,1,0,3}
};
int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[] = {6,3,7,4,8,5,10,9};

void permute(int *in, int *out, int *p, int n)
{
    for(int i=0;i<n;i++)
        out[i]=in[p[i]-1];
}

void keys(int key[], int k1[], int k2[])
{
    int p[10], c[5], d[5], temp[10];
    permute(key,p,P10,10);

    for(int i=0;i<5;i++)
    {
        c[i]=p[i];
        d[i]=p[i+5];
    }

    for(int i=0;i<5;i++)
    {
        c[i]=p[(i+1)%5];
        d[i]=p[5+(i+1)%5];
    }

    for(int i=0;i<5;i++)
    {
        temp[i]=c[i];
        temp[i+5]=d[i];
    }

    permute(temp,k1,P8,8);

    for(int i=0;i<5;i++)
    {
        c[i]=temp[(i+2)%5];
        d[i]=temp[5+(i+2)%5];
    }

    for(int i=0;i<5;i++)
    {
        temp[i]=c[i];
        temp[i+5]=d[i];
    }

    permute(temp,k2,P8,8);
}

void xorbits(int a[],int b[],int n)
{
    for(int i=0;i<n;i++) a[i]^=b[i];
}

void fk(int b[],int key[])
{
    int ep[8],x[8],s[4],p[4],row,col;
    permute(b+4,ep,EP,8);
    xorbits(ep,key,8);

    row=ep[0]*2+ep[3];
    col=ep[1]*2+ep[2];

    int v=S0[row][col];
    s[0]=(v>>1)&1; s[1]=v&1;

    row=ep[4]*2+ep[7];
    col=ep[5]*2+ep[6];

    v=S1[row][col];
    s[2]=(v>>1)&1; s[3]=v&1;

    permute(s,p,P4,4);
    xorbits(b,p,4);
}

void process(int in[],int out[],int k1[],int k2[],int dec)
{
    int b[8],t[8];
    permute(in,b,IP,8);

    if(dec) fk(b,k2);
    else fk(b,k1);

    for(int i=0;i<4;i++)
    {
        int x=b[i];
        b[i]=b[i+4];
        b[i+4]=x;
    }

    if(dec) fk(b,k1);
    else fk(b,k2);

    permute(b,out,IP1,8);
}

int main()
{
    int key[]={0,1,1,1,1,1,1,1,0,1};
    int iv[]={1,0,1,0,1,0,1,0};
    int p[16]={0,0,0,0,0,0,0,1,
               0,0,0,0,0,0,1,0};
    int c[16],d[16],k1[8],k2[8],block[8],prev[8];

    keys(key,k1,k2);

    for(int i=0;i<8;i++) prev[i]=iv[i];

    for(int j=0;j<2;j++)
    {
        for(int i=0;i<8;i++)
            block[i]=p[j*8+i]^prev[i];

        process(block,c+j*8,k1,k2,0);

        for(int i=0;i<8;i++) prev[i]=c[j*8+i];
    }

    printf("Ciphertext: ");
    for(int i=0;i<16;i++) printf("%d",c[i]);

    for(int i=0;i<8;i++) prev[i]=iv[i];

    for(int j=0;j<2;j++)
    {
        process(c+j*8,block,k1,k2,1);

        for(int i=0;i<8;i++)
        {
            d[j*8+i]=block[i]^prev[i];
            prev[i]=c[j*8+i];
        }
    }

    printf("\nDecrypted: ");
    for(int i=0;i<16;i++) printf("%d",d[i]);

    return 0;
}
