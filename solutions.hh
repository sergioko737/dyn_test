<?hh

function findMaxSliceSum(ConstVector<int> $xs): int {
  $max_slice = $max_slice_found = 0;
  foreach ($xs as $key => $value) {
    $max_slice_found = max(0, $max_slice_found + $value);
    $max_slice = max($max_slice, $max_slice_found);
  }
  return $max_slice;
}

function prodExcept(ConstVector<num> $xs): ConstVector<num> {
  //count product of given ConstVector
  $product = 1.0;
  foreach ($xs as $key => $value) {
    $product = $product * $value;
  }
  //place resulting values to temporary Vector
  $vec_temp = Vector {};
  foreach ($xs as $key => $value) {
    $vec_temp[] = $product / $value;
  }
  //return resulting immutable vector
  return $vec_result = $vec_temp->toImmVector();

}

function parse(string $str): ?Set<string> {
  throw new \Exception('Not implemented.');
}

function checkMatchingBraces(string $str): bool {
  static $braces = '{';
  static $closing_braces = '}';
  $stack = 0;

  for ($i = 0, $length = strlen($str); $i < $length; $i++){
    $char = $str[$i];

    if ($char == $braces){
      $stack = $stack+1;
      echo "-if- ". $stack;
    } else if ($char == $closing_braces){
      $stack = $stack-1;
      echo "-else if- ". $stack;
      if($stack < 0){
        echo "Mismatched braces";
        return false;
      }
    } else {
      echo "else ";
    }
  }
  return $stack == 0;
}
/*function fanout<Tx, Ty, Tz>(
 //(function (): Result<Tx>) $f,
 //(function (Tx): Result<Ty>) $g1,
 //(function (Tx): Result<Tz>) $g2
 );//: Result<(Ty, Tz)>
 {
 throw new \Exception('Not implemented.');
 }*/

function main() {
  $vec_test1 = ImmVector {-1, -2, 3, -4, 5};
  $vec_test = ImmVector {30, 3434, 4, 5, 2, 3, 3};
  $string_pr3 = "}{dd}{{dd}";
  echo "Problem 1<br>";
  echo "max slice is ";
  echo findMaxSliceSum($vec_test1);
  echo "<br><br>";
  echo "Problem 2</br>";
  $zx = prodExcept($vec_test);
  var_dump($vec_test);
  echo "<br>";
  var_dump($zx);
  echo "<br><br>";
  echo "Problem 3<br>";
  var_dump (checkMatchingBraces ($string_pr3));
}
main();
