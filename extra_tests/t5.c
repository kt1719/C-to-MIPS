int g(int n)
{
    for(int i=0; i<10; i++){
      n+=4;
    }
    return n;
}

int f(){
  return g(0);
}
