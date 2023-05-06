#include <fstream>
using namespace std;
ifstream f("mergeheap.in");
ofstream g("mergeheap.out");

class Node
{
public:
    int val;
    Node *child;
    Node *bro;

    Node(int valoare):val(valoare),child(nullptr),bro(nullptr){}
    Node(Node* nod)
    {
        val=nod->val;
        child=nod->child;
        bro=nod->bro;
    }
    int getData() const
    {
        return val;
    }
    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (node->child != nullptr) {
            clear(node->child);
        }

        if (node->bro != nullptr) {
            clear(node->bro);
        }

        delete node;
    }
};
class PairingHeap
{
private:
    Node* radacina;
public:
    PairingHeap() : radacina(nullptr) {}
    bool isEmpty() const {
        return radacina == nullptr;
    }
    PairingHeap(const int& valoare) : radacina(new Node(valoare)) {}
    //pentru cerinta 1
    void insert(const int& value)
    {
        if(radacina==nullptr)
        {
            radacina = new Node(value);
            return;
        }
        Node* auxiliar = new Node(value);
        if(radacina->getData() < value)
            swap(radacina, auxiliar);
        auxiliar->bro=radacina->child;
        radacina->child=auxiliar;
    }
    //cerinta 2
    int getMaxim()
    {
        int maxim = radacina->getData();
        Node* oldroot = radacina;
        if(radacina->child== nullptr)
            radacina = nullptr;
        else radacina = mergePairs(radacina->child);
        delete oldroot;
        return maxim;
    }
    //cerinta 3
    void merge(PairingHeap& other)
    {
        if(other.radacina == nullptr)return;
        if(radacina == nullptr){
            swap(radacina,other.radacina);
            return;
        }
        if(other.radacina->getData()>radacina->getData()){
            swap(radacina,other.radacina);
        }
        other.radacina->bro=radacina->child;
        radacina->child=other.radacina;
        other.radacina = nullptr;
    }
    //cerinta 2
    Node* mergePairs(Node* first) {
        if (first == nullptr || first->bro == nullptr)
            return first;
        Node *next;
        PairingHeap h1;
        h1.radacina = first;
        PairingHeap h2;
        h2.radacina = first->bro;
        next = first->bro->bro;
        h1.merge(h2);
        PairingHeap h3;
        h3.radacina = mergePairs(next);
        h1.merge(h3);
        return h1.radacina;
    }

};

int main()
{
    int N, Q;
    f >> N >> Q;
    PairingHeap heap[N];
    for (int i = 0; i < Q; i++)
    {
        int op, m, x, y;
        f >> op;
        switch (op)
        {
            case 1:
                f >> m >> x;
                heap[m-1].insert(x);
                break;

            case 2:
                f >> m;
                g << heap[m-1].getMaxim()<<"\n";
                break;

            case 3:
                f >> x >> y;
                heap[x-1].merge(heap[y-1]);
                break;
        }
    }
    return 0;
}
