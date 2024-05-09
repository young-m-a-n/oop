void checkSuccess(float x, float y){ 
  fill(153, 204, 255); // 골인지점의 색깔 하늘색
  rect(1400,0,200,900); // 골인 지점의 크기 및 표시
  if(x > 1400) 
      goal = 300;
}
void showSuccess(){
    goal--;    
    fill(255,0,0);
    textSize(100);
    text("Clear!", 650, 450);
}
void showText(){
    keepText --;
    fill(255,0,0);
    textSize(100);
    text("You Died...", 600, 450);
}
