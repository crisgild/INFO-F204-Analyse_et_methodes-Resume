/*************************************/

class Tour {
    stack<unsigned int> s;

public:
    Tour(unsigned int);
    void push(unsigned int);
    unsigned int pop();
};

Tour::Tour(unsigned int n=0) {
    for (unsigned int i=n; i>0; --i)
        s.push(i);
}

void Tour::push(unsigned int i) {
    s.push(i);
}

unsigned int Tour::pop() {
    unsigned int res = s.top();
    s.pop();
    return res;
}

/*************************************/

class Hanoi {
    void hanoi(unsigned int, Tour&, Tour&, Tour&);

public:
    Hanoi(unsigned int);
};

void Hanoi::hanoi(unsigned int i, Tour& src, Tour& dst, Tour& aux) {
    if (i == 1) {
        unsigned int x = src.pop();
        dst.push(x);
    }
    else {
        hanoi(i-1, src, aux, dst);
        unsigned int x = src.pop();
        dst.push(x);
        hanoi(i-1, aux, dst, src);
    }
}

Hanoi::Hanoi(unsigned int n) {
    Tour a(n), b, c;
    hanoi(n, a, c, b);
}

/*************************************/

int main() {
    Hanoi(2);
    return 0;
}
