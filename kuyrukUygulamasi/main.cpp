#include <iostream>

using namespace std;


struct node{ //Bagli liste
    int no;
    string ad;
    node* next;
};


struct queue{ //Kuyruk
    int indis=0;
    node *front=NULL;
    node *rear=NULL;
};

typedef struct queue kuyruk;

void enqueue(kuyruk *k, int no, string ad){
    node *eleman= new node();
    eleman->no=no;
    eleman->ad=ad;

    if(k->indis==0){
        eleman->next=NULL;
        k->front=k->rear=eleman;
        k->indis++;
        cout << eleman->ad << " kuyruga ilk kisi eklendi!" << endl;    }


    else{
        eleman->next=k->rear;
        k->rear=eleman;
        k->indis++;
        cout << eleman->ad << " kisisi kuyruga eklendi!" << endl;    }
}

void dequeue(kuyruk *k){
    if(k->indis==0) {cout << "Kuyruk bos!" << endl;}

    else if(k->indis==1){
        cout << k->front->ad << " ilk ve tek kisisi kuyruktan cikarildi!" << endl;
        delete k->front;
        k->front= k->rear=NULL;
        k->indis--;}

    else{
        node *iter=k->rear;
        while(iter->next!=k->front)
            iter= iter->next;
        cout << k->front->ad << " kisisi kuyruktan cikarildi!" << endl;
        delete k->front;
        k->front=iter;
        k->front->next=NULL;
        k->indis--;}
}

void print(kuyruk *k){
    if(k->indis==0) {cout << "Kuyruk bos!" << endl;}
    else{
        cout << "Onem Derecesi -- Ad" << endl;
        node *iter=k->rear;
        while(iter!=NULL){
            cout << "\t" << iter->no << "\t" << iter->ad << endl;
            iter= iter->next;}}
            }


void onemDerecesineGoreSirala(kuyruk *k){
    int n=k->indis, noDizi[n];
    string adDizi[n];
    node *iter=k->rear;

    for(int i=0;i<n;i++){
        noDizi[i]=iter->no;
        adDizi[i]=iter->ad;
        iter=iter->next;}

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(noDizi[i]<noDizi[j]){
                int tempNo = noDizi[i];
                noDizi[i] = noDizi[j];
                noDizi[j] = tempNo;

                string tempAd = adDizi[i];
                adDizi[i] = adDizi[j];
                adDizi[j] = tempAd;}
        }
    }

    for(int i=0;i<n;i++){dequeue(k);} //Kuyruk bosaltildi

    for(int i=0;i<n;i++){enqueue(k,noDizi[i], adDizi[i]);} //Kuyruga dizideki degerler eklendi

    print(k);
}

void oncesindeKacKisiVar(kuyruk *k, string ad){
    int n= k->indis, i=0; bool sonuc = false;
    if(n==0) {cout << "Kuyruk bos!" << endl; return;}

    node *iter=k->rear;
    while(iter!=NULL){
        if(iter->ad==ad){
            sonuc= true;
            break;}
        iter= iter->next;
        i++;}
    if(!sonuc){cout << ad << " isimli kisi kuyruk listesinde yok!" << endl;}
    else{cout << ad << " isimli kisiden once " << i << " kisi var!" << endl; }

}






int main()
{
    kuyruk qu;
    int secim, no;
    string ad;
    while(true){
        cout << endl;
        cout << "KUYRUK UYGULAMASI" << endl;
        cout << "1- Enqueue" << endl;
        cout << "2- Dequeue" << endl;
        cout << "3- Yazdir" << endl;
        cout << "4- Onem derecesine gore sirala " << endl;
        cout << "5- Oncesinde kac kisi var?" << endl;
        cout << "6- Cikis " << endl;
        cout << "Yapmak istediginiz islemi seciniz: "; cin >> secim;
        switch(secim){
        case 1:
            cout << "Ad: "; cin >> ad;
            cout << "Onem derecesi: "; cin >> no;
            enqueue(&qu, no, ad);
            break;
        case 2:
            dequeue(&qu);
            break;
        case 3:
            print(&qu);
            break;
        case 4:
            onemDerecesineGoreSirala(&qu);
            break;
        case 5:
            cout << "Ad: "; cin >> ad;
            oncesindeKacKisiVar(&qu,ad);
            break;
        case 6:
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        default:
            cout << "Lutfen gecerli bir islem giriniz!" << endl;
            break;
        }
    }
    return 0;
}
