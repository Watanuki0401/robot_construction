# robot_construction

※printデバックコードがそのままになっています。

本プログラムはArduinoのモータドライブを用いた自走プログラムである。

本コードはdelay関数の欠点である、”並列処理”に対応させるため非同期処理を用いている。

ループ処理をするたびにmillis()を実行することで、現在の時間を記録できる。
この値と前回動作した時間の引き算を行い、設定した時間を経過したらif文内の処理を行う。
本コード内に非同期処理は2種類実装しており、”前進”と”旋回”の動作で切り分けている。

＜前進＞
1ミリ秒毎に実行される、後輪を前進させるための関数。
0~180度までを3度刻みで加減算をするような分岐処理とそれをサーボモータに書き込む処理からなる。
Serial.printとconsole()は実装時にシリアルでモニタリングできるようにつけている。

<旋回>
75000ミリ秒(1m15s)後から実行されるようになっている関数。 
こちらは200ミリ秒感覚で163→133→163度と変化していくように作成されており、途中133度まで達した場合、
12500ミリ秒(12.5s)その状態を維持し、その後163度に戻るようになっている。

