<?hh



function main(){

  $arr = array(1,3,3,4,2);
  echo "Hello worlddd!";
  //echo $arr[0];
  $product = array_product($arr);
  foreach ($arr as $value){
    echo " ";
    echo $product/$value;
  }
}

main();
