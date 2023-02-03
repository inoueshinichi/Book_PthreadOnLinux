# PthreadsOnLinux  
Linuxとpthreadsによるマルチスレッド  
https://www.shuwasystem.co.jp/book/9784798053721.html  

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


