ft_printf プロジェクト

プログラム名
libftprintf.a​

提出ファイル
Makefile, *.h, ft_printf.h, *.c, ft_printf.c, Makefile​

Makefileルール
NAME, all, clean, fclean, re​

外部関数
malloc, free, write, va_start, va_arg, va_copy, va_end​

libft使用許可
yes


説明
libcのprintf関数を再実装するライブラリを作成します。ft_printfはオリジナルのprintfを模倣する関数です。プロトタイプは int ft_printf(const char *, ...)です。


以下の要件があります：
・オリジナルのprintfのバッファ管理を実装しない
・以下の変換を扱う：cspdiuxX%
・実装はオリジナルのprintfの動作に対して評価される
・arコマンドを使用してライブラリを作成（libtoolは禁止）
・libftprintf.aはリポジトリのルートに作成


実装する変換
・c ▶ 単一文字を出力
・s ▶ 一般的なC規則で定義された文字列を出力
・p ▶ voidポインタ引数を16進形式で出力
・d ▶ 10進基数（decimal base 10）の数を出力
・i ▶ 10進基数の整数を出力
・u ▶ 符号なし10進基数の数を出力
・x ▶ 16進基数（小文字形式）の数を出力
・X ▶ 16進基数（大文字形式）の数を出力
・% ▶ パーセント記号を出力
