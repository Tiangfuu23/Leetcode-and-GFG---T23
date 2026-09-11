struct Node {
    Node *l, *r;
    bool isBooked; // fully booked
    Node() : l(nullptr), r(nullptr), isBooked(false) {};
};

bool isOverlap(Node *v, int vl, int vr, int l, int r){
    if(v == nullptr)
        return false;

    if(vr < l || vl > r)
        return false;
    
    if(v->isBooked)
        return true;

    // if(vl >= l && vr <= r){
    //     return v->isBooked;
    // }

    int m = (vl + vr) / 2;
    return isOverlap(v->l, vl, m, l, r) || isOverlap(v->r, m + 1, vr, l ,r);
}

void insert(Node *v, int vl, int vr, int l, int r){
    if(vr < l || vl > r){
        return;
    }

    if (l <= vl && vr <= r){
        v->isBooked = true;
        return;
    }

    if(v->l == nullptr) v->l = new Node();
    if(v->r == nullptr) v->r = new Node();

    int m = (vl + vr) / 2;

    if(r <= m){
        insert(v->l, vl, m, l, r);
    }else if(l > m){
        insert(v->r, m + 1, vr, l , r);
    }else{
        insert(v->l, vl, m, l, r);
        insert(v->r, m + 1, vr, l , r);
    }
    v->isBooked = v->l->isBooked && v->r->isBooked;
}

class MyCalendar {
    Node* root;
    int n = 1e9;

public:
    MyCalendar() { root = new Node(); }

    bool book(int startTime, int endTime) {
        if(isOverlap(root, 0, n, startTime, endTime-1)){
            return false;
        }

        insert(root, 0, n, startTime, endTime-1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */