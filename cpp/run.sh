g++-9 $1 -std=c++17 -O1 -fsanitize=address
./a.out
rm -rf a.out
