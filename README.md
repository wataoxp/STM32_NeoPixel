8ピンMCUのSTM32G03J6M6を利用したNeoPixelのコントロールプログラムです。
ROMには余裕があったので色変更の関数(neopixel.c内)はパターン毎に用意しています。

DMAの利用/HALライブラリ利用/動作周波数24Mhz
データ幅はメモリ、ペリフェラル共にハーフワード
->当初はNucleoF446REでテストしていたので72Mhzクロックでの設定も残っています。

参考コード

https://controllerstech.com/interface-ws2812-with-stm32/

一番最初に試したコードです。
関数名やマクロ宣言の名前は恐らくこの時から変わってないです。

https://www.thevfdcollective.com/blog/stm32-and-sk6812-rgbw-led

特にシフト演算を用いた0/1判定の方法を大いに参考にしました。

諸々非効率なコードもあるとは思いますので、参考程度に役立ててもらえたら幸いです。
