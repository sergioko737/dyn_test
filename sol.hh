<?php

class ParensParser
{
    // something to keep track of parens nesting
    protected $stack = null;
    // current level
    protected $current = null;

    // input string to parse
    protected $string = null;
    // current character offset in string
    protected $position = null;
    // start of text-buffer
    protected $buffer_start = null;

    public function parse($string)
    {
      echo "Begin -parse- function<br>";
        if (!$string) {
            // no string, no data
            return array();
        }

        if ($string[0] == '(') {
            // killer outer parens, as they're unnecessary
            $string = substr($string, 1, -1);
        }

        $this->current = array();
        echo $current[0]."++++<br>";
        $this->stack = array();
        echo "+".$stack."*<br>";
        var_dump($stack);

        $this->string = $string;
        echo $string."--------------<br>";
        $this->length = strlen($this->string);
        // look at each character
        for ($this->position=0; $this->position < $this->length; $this->position++) {
            switch ($this->string[$this->position]) {
                case '(':
                    $this->push();
                    // push current scope to the stack an begin a new scope
                    array_push($this->stack, $this->current);
                    $this->current = array();
                    var_dump($this->stack);
                    echo "<br>";
                    break;

                case ')':
                    $this->push();
                    // save current scope
                    $t = $this->current;
                    // get the last scope from stack
                    $this->current = array_pop($this->stack);
                    // add just saved scope to current scope
                    $this->current[] = $t;
                    var_dump($this->current);
                    break;
               /*
                case ' ':
                    // make each word its own token
                    $this->push();
                    break;
                */
                default:
                    // remember the offset to do a string capture later
                    // could've also done $buffer .= $string[$position]
                    // but that would just be wasting resources…
                    if ($this->buffer_start === null) {
                        $this->buffer_start = $this->position;
                    }
            }
        }
        foreach ($this->current as $key => $value) {
          echo "<br>".$key." ".$value."<br>";
        }

        return $this->current;
    }

    protected function push()
    {
        if ($this->buffer_start !== null) {
            // extract string from buffer start to current position
            $buffer = substr($this->string, $this->buffer_start, $this->position - $this->buffer_start);
            echo $buffer." buffer<br>";
            // clean buffer
            $this->buffer_start = null;
            // throw token into current scope
            $this->current[] = $buffer;
        }
    }
}

//$string = '(TOP (S (NP (PRP I)) (VP (VBP love) (NP (NP (DT a) (JJ big) (NN bed)) (PP (IN of) (NP (NNS roses))))) (. .)))';
$string = 'one (two)(three)SPLIT(four(nested(nested before six) five(nestedsix)))two_outer(aaaaaa)';
$p = new ParensParser();
$result = $p->parse($string);
echo "<br><br>";
var_dump($result);
//foreach ($result as $key => $value) {
  //echo " <br>".$key." ".$value;

//}
