among [] aa;
mang bb;
int keepText = 0, goal = 0;
void setup(){
  size(1600,900);
  bb=new mang();
  aa=new among[5];
  for(int i=0; i<2; i++){
    aa[2*i+1]=new hat(i);
    aa[2*i]=new sun(i);
  }
  aa[4]=new sun(4);
}
void draw(){
  background(0,255,255);
  if(keepText !=0) showText();
  else if(goal !=0) showSuccess();
  else checkSuccess(bb.x, bb.y);
  bb.show();
  for (int i=0; i<5; i++){
    if(keepText==0) keepText = bb.collide(aa[i]);
    aa[i].act();
    aa[i].show();
  }
}
void keyPressed(){
  bb.keyMove();
}
