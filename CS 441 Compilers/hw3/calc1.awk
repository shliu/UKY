# calc1 - reverse-polish calculator, version 1
# input: artithmetic expression in reverse polish
# output: values of expressions
{ for (i = 1; i <=NF; i++)
if ($i ~ /^[+-]?([0-9]+[.]?[0-9]*|[.][0-9]+)$/) {
stack[++top] = $i
} else if ($i == "+" && top > 1) {
stack[top-1] += stack[top]; top--
} else if ($i == "-" && top > 1) {
stack[top-1] -= stack[top]; top--
} else if ($i == "*" && top > 1) {
stack[top-1] *= stack[top]; top--
} else if ($i == "/" && top > 1) {
stack[top-1] /= stack[top]; top--
} else if ($i == "^" && top > 1) {
stack[top-1] ^= stack[top]; top--
} else {
printf("error: cannot evaluate %s\n", $i)
top = 0
next
}
if (top == 1)
printf("\t%.8g\n", stack[top--])
else if (top > 1) {
printf("error: too many operand\n")
top = 0
}
}
