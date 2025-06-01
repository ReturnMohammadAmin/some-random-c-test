int main() {
    int a = __VERIFIER_nondet_int(), b = __VERIFIER_nondet_int(), sum = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b ; j++)
            sum += (i + j + 1) % 2;
    if (sum == 0xffffffff)
        __VERIFIER_error();
}
