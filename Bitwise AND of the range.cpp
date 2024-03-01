  /* Bitwise AND of the range [left, right] */

    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left<right){
            cnt++;
            left/=2;
            right/=2;
        }
        return (left<<cnt);
    }

