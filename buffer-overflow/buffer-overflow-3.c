void write(char *p) {
    *(p + 15) = 'z';
}

int main() {
    char arr[10];
    write(arr);
    return 0;
}
