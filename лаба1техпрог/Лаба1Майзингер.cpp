#include <iostream>
#include <cstdlib>
using namespace std;

struct product{
    string name;
    float price;
    int amount;
    //указатель на следующий по порядку элемент
    product *next;
};


void addfirst(product*& bufet, string NewName, float  newprice, int newamount){
    product *newproduct = new product;
    newproduct -> name = NewName;
    product *tmp = bufet;
    while(tmp != NULL){
        if(tmp -> name == NewName){
            cout << "Element uje v spiske";
            return;
        }
        tmp = tmp -> next;}
    newproduct -> price = newprice;
    newproduct -> amount = newamount;
    newproduct -> next = bufet;
    bufet = newproduct;
    return;
}

void PrintList(product *bufet){
    if (bufet == NULL){
        cout<<"Spisok pustoy";
        return;
    }
    product *tmp = bufet;
    while(tmp != NULL){
        cout<<"Product: "<<tmp->name<<
          "\nPrice: "<<tmp->price<<
          "\nAmount: "<<tmp->amount<<"\n\n";
        tmp = tmp->next;
    }
    return;
}

int AddBefore( product *&bufet, string NewName, float newprice, int newamount, string NameBefore){
    if ( bufet == NULL )
        return 1;
    if (bufet->name == NameBefore ){
        addfirst( bufet, NewName, newprice, newamount );
        return 0;
    }
    if ( bufet->next == NULL )
        return 1;
    product *prev = bufet, *tmp = bufet->next;
    product *newproduct = new product;
    newproduct -> name = NewName;
    while(tmp->next!=NULL && tmp->name!=NameBefore){
        if(tmp -> name == NewName){
            cout << "Element uje v spiske";
            return 1;
        }
        prev = prev->next;
        tmp = tmp->next;
    }
    if ( tmp->next==NULL && tmp->name!=NameBefore){
        cout << "Element ne v spiske";
        return 1;
    }
    newproduct->price = newprice;
    newproduct->amount = newamount;
    newproduct->next = tmp;
    prev->next = newproduct;
    return 0;
}

void addlast(product *&bufet, string newname, float newprice, int newamount){
    product *tmp = bufet;
    if ( bufet == NULL ){
        addfirst( bufet, newname, newprice,newamount ); //добавление в список, если он пуст
        return;
    }
    product *newproduct = new product;
    newproduct -> name = newname;
    while(tmp != NULL){
        if(tmp -> name == newname){
            cout << "Element uje v spiske";
            return;
        }
        tmp = tmp -> next;
    }
    newproduct -> price = newprice;
    newproduct -> amount = newamount;
    newproduct -> next = NULL;
    tmp -> next = newproduct;
    return;
}

int AddAfter( product *bufet, string NewName, float newprice ,int newamount, string NameAfter){
    if ( bufet == NULL )return 1;
    product *tmp = bufet;
    product *newproduct = new product;
    newproduct -> name = NewName;
    while(tmp != NULL) {
        if (tmp->name == NewName) {
            cout << "Element uje v spiske";
            return 1;
        }
        tmp = tmp->next;
    }
    tmp = bufet->next;
    while(tmp != NULL && tmp->name != NameAfter){
        tmp = tmp -> next;
    }
    if ( tmp == NULL )
        return 1;
    newproduct -> price = newprice;
    newproduct -> amount = newamount;
    newproduct -> next = tmp->next;
    tmp->next = newproduct;
    return 0;
}

int Delproduct( product *&bufet, string DelName){
    if ( bufet == NULL )
        return 1;
    product *tmp = bufet;
    if ( bufet->name == DelName ){
        bufet= bufet->next;
        delete tmp;
        return 0;
    }
    if ( bufet->next == NULL )
        return 1;
    product *prev = bufet;
    tmp = bufet->next;
    while(tmp->next != NULL && tmp->name != DelName){
        prev = prev->next;
        tmp = tmp->next;
    }
    if ( tmp->next==NULL && tmp->name!= DelName)
        return 1;
    prev->next = tmp->next;
    delete tmp;
    return 0;
}
void Printname(product *bufet, string printname){
    int k;
    if (bufet == NULL){
        cout<<"Spisok pust"; return;
    }
    product *tmp = bufet;
    while(tmp != NULL){
        if (tmp->name == printname){
                    cout << "Product: " << tmp->name << "\nPrice: " << tmp->price << "\nAmount: " << tmp->amount
                         << "\n\n";
                    k = 1;
            } else
                k =0;
        tmp = tmp->next;
    }
    if (k == 0){
        cout << "Net takogo tovara";
    }
    return;
}

int main(){
    product *bufet = NULL;
    int res, k, amount;
    string name, nameafter, namebefore;
    float price;

    k = 100;

    while (k != 0){
        while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k!=5 && k!=6 && k!=7){
            cout << "Dobavlenie elementa v konec spiska, najmite 1;\n";
            cout << "Dobavlenie elementa v nachalo spiska, najmite 2;\n";
            cout << "Udalit element, najmite 3; \n";
            cout << "Dobavit posle elementom, najmite 4;\n";
            cout << "Dobavit pered elementom, najmite 5;\n";
            cout << "Nayti ele, najmite 6;\n";
            cout << "List, najmite 7;\n";
            cout << "Vyyti, najmite 0: \n";
            cin >> k;
            cout << "\n\n";
                switch(k){
                    case 0:{
                        //Выходим из цикла
                        break;
                    }
                    case 1:{
                        cin>>name>>price>>amount;
                        addlast(bufet,name,price,amount);
                        // Реализуем логику добавления элемента в конец списка
                        k=100;
                        break;
                    }
                    case 2:{
                        cin>>name>>price>>amount;
                        addfirst(bufet,name,price,amount);
                        k = 100;
                        break;
                    }

                    case 3:{
                        // Реализуем логику удаления элемента из списка
                        cin>>name;
                        res = Delproduct(bufet,name);
                        k = 100;
                        break;
                    }
                    case 4:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cin>>name>>price>>amount;
                        cin>>nameafter;
                        res = AddAfter(bufet,name,price,amount,nameafter);
                        // Реализуем логику добавления нового элемента в список сразу ПОСЛЕ выбранного элемента
                        k = 100;
                        break;
                    }
                    case 5:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cin>>name>>price>>amount;
                        cin>>namebefore;
                        res = AddBefore(bufet,name,price,amount,namebefore);
                        // Реализуем логику добавления нового элемента в список сразу ПЕРЕД выбранным элементом
                        k = 100;
                        break;
                    }
                    case 6:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cin>>name;
                        Printname(bufet, name);
                        // Выводим на экран информацию о выбранном элементе
                        k = 100;
                        break;
                    }
                    case 7:{
                        // Выводим на экран информацию о всех элементах списка
                        PrintList(bufet);
                        k = 100;
                        break;
                    }
                    default:{
                        cout<<"Error!\n";
                        break;
                    }
                }
            cout<<"\n\n";
        }
    }
    return 0;
}