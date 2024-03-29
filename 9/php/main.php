<?php

// Complete the factorial function below.
function factorial($n) {
    if ($n <= 1)
        return $n;
        
    return $n * factorial($n-1);
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

$result = factorial($n);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
