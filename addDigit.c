int addDigits(int num) 
{
    int i = 0;
    while (num != 0) {
        i += num % 10;
        num = num / 10;
    }
    if (i >= 10) {
        return addDigits(i);
    } else {
        return i;
    }
}