>***G++***
>
>>g++ -o demo demo_1.cpp -g -llsan -fsanitize=leak
>>
>>gcc -o demo1 demo_1.cpp -ldl -rdynamic -g -llsan -fsanitize=leak
>>
>>https://zhuanlan.zhihu.com/p/372722440
>>
>>https://www.jianshu.com/p/4f71df4c2e4b