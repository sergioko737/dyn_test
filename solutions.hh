<?hh

function findMaxSliceSum(ConstVector<int> $xs): int {
  $max_slice = 0;
  $max_slice_found = 0;
  foreach ($xs as $key => $value){
    $max_slice_found += $value;
    echo $max_slice_found;
    echo "</br>";
  }
  //throw new \Exception('Not implemented.');
  return $max_slice_found;
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

/*function parse(string $str): ?Set<string>
 {
 throw new \Exception('Not implemented.');
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
  $vec_test = ImmVector {30, 3434, 4, 5, 2, 3, 3};
  echo "Problem 1</br>";
  echo findMaxSliceSum($vec_test);

  echo "</br>";
  echo "Problem 2</br>";
  $zx = prodExcept($vec_test);
  var_dump($vec_test);
  echo "</br>";
  var_dump($zx);
  echo "</br>";
}
main();
