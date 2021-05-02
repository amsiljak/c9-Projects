#include <iostream>

template <typename Tip> 
class Cvor {
public:
    Tip x;
    Cvor<Tip>* pok;
    Cvor() {pok = nullptr;}
    Cvor (const Tip &x, Cvor<Tip> *pok) : x(x), pok(pok) {}
};
template <typename Tip>
class Red {
private:
    Cvor<Tip>* prvi;
    Cvor<Tip>* krajnji;
    int brElemenata;
public: 
    Red() : brElemenata(0) {
        prvi = nullptr;
        krajnji = nullptr;
    }
    Red(const Red &r) {
        brElemenata = r.brElemenata;
        if(r.brElemenata == 0) return;
        
        prvi = new Cvor<Tip> (*r.prvi);
        Cvor<Tip>* temp = prvi;
        
        while( temp -> pok != nullptr) {
            temp -> pok = new Cvor<Tip>(*temp -> pok);
            temp = temp -> pok;
        }
        krajnji = temp;
    }
    Red &operator = (const Red &r) {
        if(&r == this) return *this;
        
        if(r.brElemenata == 0) {
            prvi = nullptr;
            krajnji = nullptr;
            brElemenata = 0;
        }
        else {
            if(brElemenata != 0) {
                Cvor <Tip>* pok1 = prvi;
                while(1) {
                    if(prvi == nullptr) break;
                    pok1 = prvi -> pok;
                    delete prvi;
                    prvi = pok1;
                }
            }
            prvi = new Cvor<Tip> (*r.prvi);
            brElemenata = r.brElemenata;
            
            Cvor<Tip>* temp = prvi;
            while(temp -> pok != nullptr) {
                temp -> pok = new Cvor<Tip> (*temp->pok);
                temp = temp -> pok;
            }
        }
        return *this;
    }
    ~Red() {
        Cvor<Tip>* pok1 = prvi;
        while(1) {
            if(prvi == nullptr) break;
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
        brElemenata = 0;
    }
    void brisi() {
        if(brElemenata == 0) return;
        Cvor<Tip>* pok1 = prvi;
        
        while(1) {
            if(prvi == nullptr) break;
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
        brElemenata = 0;
    }
    int brojElemenata() {
        return brElemenata;
    }
    void stavi(const Tip &el) {
        Cvor<Tip>* temp = new Cvor<Tip>;
        temp -> x = el;
        if(brElemenata == 0) {
            prvi = temp;
            krajnji = temp;
        }
        else {
            krajnji -> pok = temp;
            krajnji = krajnji -> pok;
        }
        brElemenata++;
    }
    Tip skini() {
        if(brElemenata== 0) throw "Red je prazna";
        Tip el = prvi -> x;
        
        Cvor<Tip> * temp = prvi;
        prvi = prvi -> pok;
        delete temp;
        brElemenata --;
        return el;
    }
    Tip& celo() {
        if(brElemenata == 0) throw "Red je prazan";
        return prvi -> x;
    }
};
bool Test1() {
    Red<int> r;
    r.stavi(5);
    r.stavi(6);
    r.brisi();
    if(r.brojElemenata() == 0) return 1;
    return 0;
}

bool Test2() {
    Red<int> r;
    r.stavi(3);
    r.stavi(2);
    if(r.celo() != 3) return false;
    r.skini();
    if(r.celo() == 2) return true;
    return false;
}
bool Test3() {
    Red<int> r;
    try {
        int a = r.celo();
        return false;
    }
    catch(...) {
        return true;
    }
}
bool Test4() {
    Red<int> r;
    r.stavi(2);
    r.stavi(3);
    r.stavi(4);
    if(r.brojElemenata() == 3) return true;
    return false;
}
int main() {
    if(Test1()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test2()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test3()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test4()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    return 0;
}
