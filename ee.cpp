void up(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0){
    seg[node] += (en - st + 1) * lazy[node];

    if (st != en){
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if ((en < l) || (st > r))
  {
    return;
  }
  if (st >= l && en <= r){
    seg[node] += (en - st + 1) * val;
    if (st != en) {
      lazy[2 * node] += val;
      lazy[2 * node + 1] += val;
    }
    return;
  }
  int mid = (st + en) / 2;
  update(2 * node, st, mid, l, r, val);
  update(2 * node + 1, mid + 1, en, l, r, val);
  seg[node] = (seg[2 * node] + seg[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r) {
  if (lazy[node] != 0) {

    seg[node] += (en - st + 1) * lazy[node];
    if (st != en){
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (en < l || st > r) {
    return 0;
  }
  if ((l <= st) && (en <= r)) {
    return seg[node];
  }
  int mid = (st + en) / 2;
  ll q1 = query(2 * node, st, mid, l, r);
  ll q2 = query(2 * node + 1, mid + 1, end, l, r);

  return (q1 + q2);
}

void up(int l , int r , int i , int j , int idx  , int v , int x){
    if(l == r){
        arr[x] += v;
        st[idx] += v;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid){
        up(l  ,mid ,i , j , 2*idx , v , x);
    }else{
        up(mid+1 , r , i  , j , 2*idx+1 , v , x);
    }
    st[idx] = st[2*idx] + st[2*idx  + 1];
}

void build(int d, int f, int p){
    if (d>f)
        return ;
    if (d==f){
        tree[p]=0;
        return;
    }
    int mid = (d+f)/2;
    build(d, mid, p*2+1);
    build(mid+1,f, p*2+2);
    tree[p] = tree[p*2+1] + tree[p*2+2];
}
