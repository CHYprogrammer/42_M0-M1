#include "ft_printf.h"  // 実際のパスに合わせて調整
#include <stdio.h>

int main(void)
{
    int ret1, ret2;
    char buf1[1000] = "hello";
    char buf2[1000] = "hello";

    // %c テスト
    ret1 = ft_printf("%c%c%c", 'a', 65, '\n');
    ret2 = printf("%c%c%c", 'a', 65, '\n');
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

    // %s テスト
    ret1 = ft_printf("%s%s", buf1, buf2);
    ret2 = printf("%s%s", buf1, buf2);
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

    // %d %i テスト
    ret1 = ft_printf("%d %i %d", -42, 42, 0);
    ret2 = printf("%d %i %d", -42, 42, 0);
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

	    // %u %x %X テスト
	ret2 = printf("%u %x %X %u\n", 4294967295U, 255, 255, UINT_MAX);
    ret1 = ft_printf("%u %x %X %u\n", 4294967295U, 255, 255, UINT_MAX);
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

    // エッジケース
    ret1 = ft_printf("%d %u %x\n", INT_MIN, 0, 0);
    ret2 = printf("%d %u %x\n", INT_MIN, 0, 0);
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

	    // %p テスト
    void *ptr = (void*)0x12345678;
    ret1 = ft_printf("%p %p\n", ptr, NULL);
    ret2 = printf("%p %p\n", ptr, NULL);
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

    // %% テスト
    ret1 = ft_printf("%% %%%%%% %%");
    ret2 = printf("%% %%%%%% %%");
    printf("ft: %d | std: %d\n[%s]\n[%s]\n\n", ret1, ret2, buf1, buf2);

    return (0);
}
