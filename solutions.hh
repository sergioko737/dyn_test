<?hh

/*function findMaxSliceSum(ConstVector<int> $xs): int
 {
 throw new \Exception('Not implemented.');
 }*/

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
  $vec_test = ImmVector {1.3, 3, 4, 5, 2, 3, 3};
  echo "Problem 2</br>";
  $zx = prodExcept($vec_test);
  var_dump($vec_test);
  echo "</br>";
  var_dump($zx);
  echo "</br>";
}
main();
