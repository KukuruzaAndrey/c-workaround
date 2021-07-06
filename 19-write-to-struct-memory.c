struct st {
  int a;
  int b;
};

int main() {
  struct st c;
  c = (st){1, 2};
  printf("%d %d", c.a, c.b);
}
