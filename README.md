# PthreadsOnLinux  
Linuxとpthreadsによるマルチスレッド  
https://www.shuwasystem.co.jp/book/9784798053721.html

Chapter 1 マルチスレッドプログラミングとは
1-1 マルチプロセスとマルチスレッドの違い
1-2 マルチスレッドが役立つケース
1-3 マルチスレッドプログラミングの基本要素
1-4 マルチスレッドプログラミングの怖さ

Chapter 2 スレッドの管理
2-1 スレッドを作る
2-2 スレッドの終了
2-3 スレッドIDとスレッド終了待ち
2-4 スレッドの消去
2-5 スレッドの同定
2-6 スレッドの属性
2-7 他のスレッドの強制停止
2-8 Linuxでスレッドはどのように確認できるか

Chapter 3 スレッド間のデータ共有
3-1 スレッド間で共有するもの
3-2 C言語における変数とメモリの関係
3-3 動的に割り当てられたメモリ
3-4 他のスレッドのスタックへのアクセス
3-5 マルチプロセスとマルチスレッドの動作の違い
3-6 マルチスレッドセーフな関数
3-7 オブジェクト指向プログラミングとマルチスレッド
3-8 スレッドローカル変数
3-9 volatile変数
3-10 スレッドとシグナル

Chapter 4 実行の排他制御
4-1 同じ変数に同時にアクセスすると…
4-2 実行を排他する方法
4-3 pthreadsのミューテックス
4-4 ミューテックスの使い方の実習
4-5 実習の解答例
4-6 複数のミューテックスを用いる
4-7 デッドロック
4-8 デッドロックを回避するテクニック
4-9 read/writeロック
4-10 ミューテックスの属性

Chapter 5 条件待ち
5-1 実行を同期したいケース
5-2 条件待ちをする方法
5-3 タイムアウト付き条件待ち
5-4 条件変数の使い方の実習
5-5 実習の解答例
5-6 条件待ちでミューテックスを使う意義
5-7 1つの条件を複数のスレッドが待つ場合
5-8 スタベーション
5-9 条件変数の属性

Chapter 6 キューの作成実習
6-1 この実習で作成するキュー
6-2 マルチスレッドセーフではないキューの例
6-3 キューを使ったプログラム例
6-4 実習：キューをマルチスレッドセーフにする
6-5 実習の解答例

Chapter 7 デザインパターン
7-1 エージェント
7-2 ワーカースレッド
7-3 スレッドプール
7-4 待ち合わせ

Chapter 8 ソケットプログラム実習
8-1 実習の題材の説明
8-2 ソケットプログラムの簡単な例
8-3 マルチワーカー型ソケットプログラムの作成実習
8-4 正解例1：キューを使わない場合
8-5 正解例2：キューを使う場合

Appendix
Appendix A ソケットプログラム実習で使うソースコード
Appendix B ncコマンド代用品


pthread関数の一覧(抜粋)
| 分類 | 関数名 | 内容 | 備考 |
| :--- | :--- | :--- | :--- |
| 1.スレッドの管理 | **pthread_create** | **スレッド生成** | 実行開始もする |
| | **pthread_exit** | **現在のスレッドを終了** | - |
| | pthread_cancel | 指定したスレッドの実行のキャンセル要求 | - |
| | **pthread_join** | **他のスレッドが終了するのを待つ** | - |
| | pthread_kill | スレッドへのシグナル送信 | - |
| | pthread_sigmask | スレッドごとのシグナル設定 | - |
| | pthread_attr_init | スレッド属性を初期化 | - |
| | pthread_attr_destroy | スレッド属性の破棄 | - |
| | pthread_attr_getdetach | detachstate属性の取得 | - |
| | pthread_attr_setdetach | detachstate属性の取得 | - |
| | **pthread_self** | **自身のスレッドIDを得る** | - |
| | pthread_detach | スレッドにリソースを開放させる | - |
| | **pthread_equal** | **2つのスレッドIDが等しいかどうか調べる** | - |
| 2.動作の排他 | **pthread_mutex_init** | **ミューテックスの初期化** | - |
| | **pthread_mutex_destroy** | **ミューテックスの破棄** | - |
| | **pthread_mutex_lock** | **排他制御開始** | - |
| | **pthread_mutex_trylock** | **排他制御開始** | ブロックなし |
| | **pthread_mutex_unlock** | **排他制御終了** | - |
| | pthread_mutex_getprioceling | 優先順位の上限の獲得 | - |
| | pthread_mutex_setprioceling | 優先順位の上限の設定 | - |
| | **pthread_cond_wait** | **条件変数が有効になるのを待つ** | - |
| | **pthread_cond_timewait** | **条件変数が有効になるのを待つ** | 時間制限あり |
| | pthread_rwlock_init | read/writeロックの初期化 | - |
| | pthread_rwlock_destroy | read/writeロックの破棄 | - |
| | pthread_rwlock_rdlock | readロック | - |
| | pthread_rwlock_wrlock | writeロック | - |
| | pthread_rwlock_tryrdlock | readロック | ブロックなし |
| | pthread_rwlock_trywrlock | writeロック | ブロックなし |
| | pthread_rwlock_unlock | read/writeロックの解除 | - |
| | pthread_rwlockattr_init | read/writeロック属性の初期化 | - |
| | pthread_rwlockattr_destroy | read/writeロック属性の破棄 | - |
| | pthread_rwlockattr_getpshared | read/writeロックスコープの獲得 | - |
| | pthread_rwlockattr_setpshared | read/writeロックスコープの設定 | - |
| 3.イベント通知 | **pthread_cond_init** | **条件変数の初期化** | - |
| | **pthread_cond_destroy** | **条件変数の破棄** | - |
| | **pthread_cond_signal** | **条件変数を有効にする** | - |
| | pthraed_cond_broadcast | 条件変数を有効にする | 一斉通知 |
| | pthraed_condattr_init | 条件変数属性の初期化 | - |
| | pthread_condattr_destroy | 条件変数属性の破棄 | - |
| | pthread_condattr_getpshared | 条件変数スコープの獲得 | - |
| | pthread_condattr_setpshared | 条件変数スコープの設定 | - |
| 4.動作の一時停止 | - | - | pthreadライブラリ内にはない |
| 分類外 | pthread_key_create | スレッドローカル変数の作成 | - |
| | pthread_key_delete | スレッドローカル変数の破棄 | - |
| | pthread_getspecific | スレッドローカル変数の獲得 | - |
| | pthread_setspecific | スレッドローカル変数の設定 | - |

スレッド間で共有できるリソース</br>
1. ファイルディスクリプタ</br>
2. 通信ソケット</br>
3. プロセスID</br>
4. ユーザID</br>
5. カレントディレクトリ</br>
6. リソース制限(ulimit)</br>

プロセスが所有するメモリMAP(例)</br>
|メモリアドレス |領域名称 |用途 |
|:--- |:--- |:--- |
|0x00000000 - 0x3fffffff |システム |OSがプロセスを管理するための情報などを格納する |
|0x40000000 - 0x7fffffff |コード |プログラムコードを格納する |
|0x80000000 - 0xbfffffff |ヒープ |変数の値などのデータを格納する |
|0xc0000000 - 0xfbffffff |スタック |サブルーチンコール時のレジスタの対比や関数の実引数・関数内自動変数などを格納する |
|0xfc000000 - 0xffffffff |IO |ペリフェラルIOレジスタなどが割り当てられる |


