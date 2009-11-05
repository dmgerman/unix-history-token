begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=arm-none-none %s | FileCheck -check-prefix ARM %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef long long int int64_t;
end_comment

begin_comment
comment|// ARM:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// ARM:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// ARM:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// ARM:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// ARM:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef int int32_t;
end_comment

begin_comment
comment|// ARM:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// ARM:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// ARM:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// ARM:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// ARM:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef short int16_t;
end_comment

begin_comment
comment|// ARM:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// ARM:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// ARM:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// ARM:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// ARM:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef signed char int8_t;
end_comment

begin_comment
comment|// ARM:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// ARM:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// ARM:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// ARM:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// ARM:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef long int intptr_t;
end_comment

begin_comment
comment|// ARM:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef long long int intmax_t;
end_comment

begin_comment
comment|// ARM:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT8_MAX_ 127
end_comment

begin_comment
comment|// ARM:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// ARM:UINT8_MAX_ 255
end_comment

begin_comment
comment|// ARM:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// ARM:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// ARM:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// ARM:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// ARM:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// ARM:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT16_MAX_ 32767
end_comment

begin_comment
comment|// ARM:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// ARM:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// ARM:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// ARM:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// ARM:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// ARM:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// ARM:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// ARM:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// ARM:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// ARM:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// ARM:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// ARM:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// ARM:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// ARM:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// ARM:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// ARM:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// ARM:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// ARM:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// ARM:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT8_C_(0) (0)
end_comment

begin_comment
comment|// ARM:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// ARM:INT16_C_(0) (0)
end_comment

begin_comment
comment|// ARM:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// ARM:INT32_C_(0) (0)
end_comment

begin_comment
comment|// ARM:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// ARM:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// ARM:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// ARM:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=bfin-none-none %s | FileCheck -check-prefix BFIN %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef long long int int64_t;
end_comment

begin_comment
comment|// BFIN:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// BFIN:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// BFIN:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// BFIN:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// BFIN:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef int int32_t;
end_comment

begin_comment
comment|// BFIN:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// BFIN:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// BFIN:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// BFIN:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// BFIN:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef short int16_t;
end_comment

begin_comment
comment|// BFIN:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// BFIN:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// BFIN:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// BFIN:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// BFIN:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef signed char int8_t;
end_comment

begin_comment
comment|// BFIN:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// BFIN:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// BFIN:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// BFIN:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// BFIN:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef long int intptr_t;
end_comment

begin_comment
comment|// BFIN:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:typedef long long int intmax_t;
end_comment

begin_comment
comment|// BFIN:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INT8_MAX_ 127
end_comment

begin_comment
comment|// BFIN:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// BFIN:UINT8_MAX_ 255
end_comment

begin_comment
comment|// BFIN:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// BFIN:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// BFIN:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// BFIN:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// BFIN:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// BFIN:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INT16_MAX_ 32767
end_comment

begin_comment
comment|// BFIN:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// BFIN:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// BFIN:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// BFIN:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// BFIN:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// BFIN:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// BFIN:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// BFIN:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// BFIN:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// BFIN:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// BFIN:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// BFIN:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// BFIN:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// BFIN:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// BFIN:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// BFIN:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// BFIN:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// BFIN:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// BFIN:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// BFIN:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INT8_C_(0) (0)
end_comment

begin_comment
comment|// BFIN:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// BFIN:INT16_C_(0) (0)
end_comment

begin_comment
comment|// BFIN:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// BFIN:INT32_C_(0) (0)
end_comment

begin_comment
comment|// BFIN:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// BFIN:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// BFIN:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BFIN:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// BFIN:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=i386-none-none %s | FileCheck -check-prefix I386 %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef long long int int64_t;
end_comment

begin_comment
comment|// I386:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// I386:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// I386:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// I386:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// I386:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef int int32_t;
end_comment

begin_comment
comment|// I386:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// I386:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// I386:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// I386:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// I386:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef short int16_t;
end_comment

begin_comment
comment|// I386:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// I386:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// I386:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// I386:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// I386:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef signed char int8_t;
end_comment

begin_comment
comment|// I386:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// I386:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// I386:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// I386:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// I386:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef int intptr_t;
end_comment

begin_comment
comment|// I386:typedef unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef long long int intmax_t;
end_comment

begin_comment
comment|// I386:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INT8_MAX_ 127
end_comment

begin_comment
comment|// I386:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// I386:UINT8_MAX_ 255
end_comment

begin_comment
comment|// I386:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// I386:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// I386:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// I386:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// I386:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// I386:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INT16_MAX_ 32767
end_comment

begin_comment
comment|// I386:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// I386:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// I386:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// I386:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// I386:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// I386:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// I386:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// I386:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// I386:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// I386:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// I386:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// I386:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// I386:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// I386:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// I386:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// I386:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// I386:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// I386:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// I386:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INT8_C_(0) (0)
end_comment

begin_comment
comment|// I386:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// I386:INT16_C_(0) (0)
end_comment

begin_comment
comment|// I386:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// I386:INT32_C_(0) (0)
end_comment

begin_comment
comment|// I386:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// I386:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// I386:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// I386:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=msp430-none-none %s | FileCheck -check-prefix MSP430 %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef long long int32_t;
end_comment

begin_comment
comment|// MSP430:typedef unsigned long long uint32_t;
end_comment

begin_comment
comment|// MSP430:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// MSP430:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// MSP430:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// MSP430:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef short int16_t;
end_comment

begin_comment
comment|// MSP430:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// MSP430:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// MSP430:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// MSP430:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// MSP430:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef signed char int8_t;
end_comment

begin_comment
comment|// MSP430:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// MSP430:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// MSP430:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// MSP430:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// MSP430:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef short intptr_t;
end_comment

begin_comment
comment|// MSP430:typedef unsigned short uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef long int intmax_t;
end_comment

begin_comment
comment|// MSP430:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT8_MAX_ 127
end_comment

begin_comment
comment|// MSP430:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// MSP430:UINT8_MAX_ 255
end_comment

begin_comment
comment|// MSP430:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// MSP430:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// MSP430:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// MSP430:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// MSP430:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// MSP430:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT16_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// MSP430:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// MSP430:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// MSP430:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// MSP430:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MSP430:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MSP430:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MSP430:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MSP430:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MSP430:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MSP430:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MSP430:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT64_MAX_ INT64_MAX
end_comment

begin_comment
comment|// MSP430:INT64_MIN_ INT64_MIN
end_comment

begin_comment
comment|// MSP430:UINT64_MAX_ UINT64_MAX
end_comment

begin_comment
comment|// MSP430:INT_LEAST64_MIN_ INT_LEAST64_MIN
end_comment

begin_comment
comment|// MSP430:INT_LEAST64_MAX_ INT_LEAST64_MAX
end_comment

begin_comment
comment|// MSP430:UINT_LEAST64_MAX_ UINT_LEAST64_MAX
end_comment

begin_comment
comment|// MSP430:INT_FAST64_MIN_ INT_FAST64_MIN
end_comment

begin_comment
comment|// MSP430:INT_FAST64_MAX_ INT_FAST64_MAX
end_comment

begin_comment
comment|// MSP430:UINT_FAST64_MAX_ UINT_FAST64_MAX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INTPTR_MIN_ (-32768)
end_comment

begin_comment
comment|// MSP430:INTPTR_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:UINTPTR_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:PTRDIFF_MIN_ (-32768)
end_comment

begin_comment
comment|// MSP430:PTRDIFF_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:SIZE_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INTMAX_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MSP430:INTMAX_MAX_ 2147483647L
end_comment

begin_comment
comment|// MSP430:UINTMAX_MAX_ (2147483647L*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MSP430:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// MSP430:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MSP430:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// MSP430:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT8_C_(0) (0)
end_comment

begin_comment
comment|// MSP430:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// MSP430:INT16_C_(0) (0)
end_comment

begin_comment
comment|// MSP430:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// MSP430:INT32_C_(0) (0)
end_comment

begin_comment
comment|// MSP430:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// MSP430:INT64_C_(0) INT64_C(0)
end_comment

begin_comment
comment|// MSP430:UINT64_C_(0) UINT64_C(0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// MSP430:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=pic16-none-none %s | FileCheck -check-prefix PIC16 %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:typedef long long int32_t;
end_comment

begin_comment
comment|// PIC16:typedef unsigned long long uint32_t;
end_comment

begin_comment
comment|// PIC16:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// PIC16:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// PIC16:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// PIC16:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:typedef short int16_t;
end_comment

begin_comment
comment|// PIC16:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// PIC16:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// PIC16:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// PIC16:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// PIC16:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:typedef signed char int8_t;
end_comment

begin_comment
comment|// PIC16:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// PIC16:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// PIC16:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// PIC16:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// PIC16:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:typedef short intptr_t;
end_comment

begin_comment
comment|// PIC16:typedef unsigned short uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:typedef long int intmax_t;
end_comment

begin_comment
comment|// PIC16:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INT8_MAX_ 127
end_comment

begin_comment
comment|// PIC16:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// PIC16:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PIC16:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PIC16:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PIC16:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PIC16:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PIC16:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// PIC16:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INT16_MAX_ 32767
end_comment

begin_comment
comment|// PIC16:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// PIC16:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PIC16:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PIC16:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PIC16:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PIC16:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PIC16:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// PIC16:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// PIC16:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PIC16:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PIC16:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PIC16:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PIC16:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PIC16:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PIC16:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PIC16:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INT64_MAX_ INT64_MAX
end_comment

begin_comment
comment|// PIC16:INT64_MIN_ INT64_MIN
end_comment

begin_comment
comment|// PIC16:UINT64_MAX_ UINT64_MAX
end_comment

begin_comment
comment|// PIC16:INT_LEAST64_MIN_ INT_LEAST64_MIN
end_comment

begin_comment
comment|// PIC16:INT_LEAST64_MAX_ INT_LEAST64_MAX
end_comment

begin_comment
comment|// PIC16:UINT_LEAST64_MAX_ UINT_LEAST64_MAX
end_comment

begin_comment
comment|// PIC16:INT_FAST64_MIN_ INT_FAST64_MIN
end_comment

begin_comment
comment|// PIC16:INT_FAST64_MAX_ INT_FAST64_MAX
end_comment

begin_comment
comment|// PIC16:UINT_FAST64_MAX_ UINT_FAST64_MAX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INTPTR_MIN_ (-32768)
end_comment

begin_comment
comment|// PIC16:INTPTR_MAX_ 32767
end_comment

begin_comment
comment|// PIC16:UINTPTR_MAX_ 65535
end_comment

begin_comment
comment|// PIC16:PTRDIFF_MIN_ (-32768)
end_comment

begin_comment
comment|// PIC16:PTRDIFF_MAX_ 32767
end_comment

begin_comment
comment|// PIC16:SIZE_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INTMAX_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// PIC16:INTMAX_MAX_ 2147483647L
end_comment

begin_comment
comment|// PIC16:UINTMAX_MAX_ (2147483647L*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PIC16:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// PIC16:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PIC16:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// PIC16:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INT8_C_(0) (0)
end_comment

begin_comment
comment|// PIC16:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// PIC16:INT16_C_(0) (0)
end_comment

begin_comment
comment|// PIC16:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// PIC16:INT32_C_(0) (0)
end_comment

begin_comment
comment|// PIC16:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// PIC16:INT64_C_(0) INT64_C(0)
end_comment

begin_comment
comment|// PIC16:UINT64_C_(0) UINT64_C(0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PIC16:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// PIC16:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=powerpc64-none-none %s | FileCheck -check-prefix PPC64 %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef long int int64_t;
end_comment

begin_comment
comment|// PPC64:typedef unsigned long int uint64_t;
end_comment

begin_comment
comment|// PPC64:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// PPC64:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// PPC64:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// PPC64:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef int int32_t;
end_comment

begin_comment
comment|// PPC64:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// PPC64:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// PPC64:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// PPC64:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// PPC64:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef short int16_t;
end_comment

begin_comment
comment|// PPC64:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// PPC64:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// PPC64:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// PPC64:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// PPC64:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef signed char int8_t;
end_comment

begin_comment
comment|// PPC64:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// PPC64:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// PPC64:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// PPC64:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// PPC64:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef long int intptr_t;
end_comment

begin_comment
comment|// PPC64:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef long int intmax_t;
end_comment

begin_comment
comment|// PPC64:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INT8_MAX_ 127
end_comment

begin_comment
comment|// PPC64:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC64:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PPC64:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC64:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC64:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PPC64:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC64:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC64:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INT16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC64:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC64:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC64:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC64:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC64:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC64:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC64:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INTPTR_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64:INTPTR_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:UINTPTR_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC64:PTRDIFF_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64:PTRDIFF_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64:SIZE_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INTMAX_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:INTMAX_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:UINTMAX_MAX_ (9223372036854775807L*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INT8_C_(0) (0)
end_comment

begin_comment
comment|// PPC64:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// PPC64:INT16_C_(0) (0)
end_comment

begin_comment
comment|// PPC64:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// PPC64:INT32_C_(0) (0)
end_comment

begin_comment
comment|// PPC64:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// PPC64:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// PPC64:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// PPC64:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=powerpc-none-none %s | FileCheck -check-prefix PPC %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef long long int int64_t;
end_comment

begin_comment
comment|// PPC:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// PPC:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// PPC:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// PPC:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// PPC:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef int int32_t;
end_comment

begin_comment
comment|// PPC:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// PPC:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// PPC:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// PPC:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// PPC:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef short int16_t;
end_comment

begin_comment
comment|// PPC:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// PPC:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// PPC:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// PPC:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// PPC:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef signed char int8_t;
end_comment

begin_comment
comment|// PPC:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// PPC:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// PPC:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// PPC:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// PPC:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef long int intptr_t;
end_comment

begin_comment
comment|// PPC:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:typedef long long int intmax_t;
end_comment

begin_comment
comment|// PPC:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INT8_MAX_ 127
end_comment

begin_comment
comment|// PPC:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PPC:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PPC:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// PPC:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INT16_MAX_ 32767
end_comment

begin_comment
comment|// PPC:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PPC:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PPC:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// PPC:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INT8_C_(0) (0)
end_comment

begin_comment
comment|// PPC:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// PPC:INT16_C_(0) (0)
end_comment

begin_comment
comment|// PPC:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// PPC:INT32_C_(0) (0)
end_comment

begin_comment
comment|// PPC:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// PPC:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// PPC:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// PPC:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=s390x-none-none %s | FileCheck -check-prefix S390X %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef long long int int64_t;
end_comment

begin_comment
comment|// S390X:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// S390X:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// S390X:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// S390X:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// S390X:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef int int32_t;
end_comment

begin_comment
comment|// S390X:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// S390X:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// S390X:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// S390X:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// S390X:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef short int16_t;
end_comment

begin_comment
comment|// S390X:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// S390X:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// S390X:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// S390X:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// S390X:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef signed char int8_t;
end_comment

begin_comment
comment|// S390X:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// S390X:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// S390X:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// S390X:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// S390X:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef long int intptr_t;
end_comment

begin_comment
comment|// S390X:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef long long int intmax_t;
end_comment

begin_comment
comment|// S390X:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT8_MAX_ 127
end_comment

begin_comment
comment|// S390X:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// S390X:UINT8_MAX_ 255
end_comment

begin_comment
comment|// S390X:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// S390X:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// S390X:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// S390X:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// S390X:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// S390X:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT16_MAX_ 32767
end_comment

begin_comment
comment|// S390X:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// S390X:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// S390X:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// S390X:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// S390X:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// S390X:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// S390X:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// S390X:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// S390X:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// S390X:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// S390X:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// S390X:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// S390X:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// S390X:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// S390X:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// S390X:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// S390X:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// S390X:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTPTR_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:INTPTR_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:UINTPTR_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// S390X:PTRDIFF_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:PTRDIFF_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:SIZE_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// S390X:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// S390X:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// S390X:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// S390X:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// S390X:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// S390X:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT8_C_(0) (0)
end_comment

begin_comment
comment|// S390X:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// S390X:INT16_C_(0) (0)
end_comment

begin_comment
comment|// S390X:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// S390X:INT32_C_(0) (0)
end_comment

begin_comment
comment|// S390X:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// S390X:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// S390X:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// S390X:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=sparc-none-none %s | FileCheck -check-prefix SPARC %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef long long int int64_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned long long int uint64_t;
end_comment

begin_comment
comment|// SPARC:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// SPARC:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// SPARC:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// SPARC:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef int int32_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// SPARC:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// SPARC:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// SPARC:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// SPARC:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef short int16_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// SPARC:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// SPARC:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// SPARC:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// SPARC:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef signed char int8_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// SPARC:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// SPARC:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// SPARC:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// SPARC:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef long int intptr_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef long long int intmax_t;
end_comment

begin_comment
comment|// SPARC:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INT8_MAX_ 127
end_comment

begin_comment
comment|// SPARC:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// SPARC:UINT8_MAX_ 255
end_comment

begin_comment
comment|// SPARC:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// SPARC:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// SPARC:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// SPARC:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// SPARC:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// SPARC:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INT16_MAX_ 32767
end_comment

begin_comment
comment|// SPARC:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// SPARC:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// SPARC:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// SPARC:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// SPARC:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// SPARC:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// SPARC:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// SPARC:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// SPARC:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// SPARC:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// SPARC:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// SPARC:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// SPARC:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// SPARC:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// SPARC:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// SPARC:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// SPARC:UINTMAX_MAX_ (9223372036854775807LL*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// SPARC:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// SPARC:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INT8_C_(0) (0)
end_comment

begin_comment
comment|// SPARC:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// SPARC:INT16_C_(0) (0)
end_comment

begin_comment
comment|// SPARC:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// SPARC:INT32_C_(0) (0)
end_comment

begin_comment
comment|// SPARC:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// SPARC:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// SPARC:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// SPARC:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=tce-none-none %s | FileCheck -check-prefix TCE %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:typedef int int32_t;
end_comment

begin_comment
comment|// TCE:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// TCE:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// TCE:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// TCE:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// TCE:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:typedef short int16_t;
end_comment

begin_comment
comment|// TCE:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// TCE:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// TCE:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// TCE:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// TCE:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:typedef signed char int8_t;
end_comment

begin_comment
comment|// TCE:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// TCE:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// TCE:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// TCE:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// TCE:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:typedef int intptr_t;
end_comment

begin_comment
comment|// TCE:typedef unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:typedef long int intmax_t;
end_comment

begin_comment
comment|// TCE:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INT8_MAX_ 127
end_comment

begin_comment
comment|// TCE:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// TCE:UINT8_MAX_ 255
end_comment

begin_comment
comment|// TCE:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// TCE:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// TCE:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// TCE:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// TCE:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// TCE:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INT16_MAX_ 32767
end_comment

begin_comment
comment|// TCE:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// TCE:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// TCE:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// TCE:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// TCE:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// TCE:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// TCE:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// TCE:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// TCE:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// TCE:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INT64_MAX_ INT64_MAX
end_comment

begin_comment
comment|// TCE:INT64_MIN_ INT64_MIN
end_comment

begin_comment
comment|// TCE:UINT64_MAX_ UINT64_MAX
end_comment

begin_comment
comment|// TCE:INT_LEAST64_MIN_ INT_LEAST64_MIN
end_comment

begin_comment
comment|// TCE:INT_LEAST64_MAX_ INT_LEAST64_MAX
end_comment

begin_comment
comment|// TCE:UINT_LEAST64_MAX_ UINT_LEAST64_MAX
end_comment

begin_comment
comment|// TCE:INT_FAST64_MIN_ INT_FAST64_MIN
end_comment

begin_comment
comment|// TCE:INT_FAST64_MAX_ INT_FAST64_MAX
end_comment

begin_comment
comment|// TCE:UINT_FAST64_MAX_ UINT_FAST64_MAX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// TCE:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INTMAX_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// TCE:INTMAX_MAX_ 2147483647L
end_comment

begin_comment
comment|// TCE:UINTMAX_MAX_ (2147483647L*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// TCE:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// TCE:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INT8_C_(0) (0)
end_comment

begin_comment
comment|// TCE:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// TCE:INT16_C_(0) (0)
end_comment

begin_comment
comment|// TCE:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// TCE:INT32_C_(0) (0)
end_comment

begin_comment
comment|// TCE:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// TCE:INT64_C_(0) INT64_C(0)
end_comment

begin_comment
comment|// TCE:UINT64_C_(0) UINT64_C(0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TCE:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// TCE:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: clang-cc -E -ffreestanding -triple=x86_64-none-none %s | FileCheck -check-prefix X86_64 %s&&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef long int int64_t;
end_comment

begin_comment
comment|// X86_64:typedef unsigned long int uint64_t;
end_comment

begin_comment
comment|// X86_64:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// X86_64:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// X86_64:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// X86_64:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef int int32_t;
end_comment

begin_comment
comment|// X86_64:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// X86_64:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// X86_64:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// X86_64:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// X86_64:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef short int16_t;
end_comment

begin_comment
comment|// X86_64:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// X86_64:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// X86_64:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// X86_64:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// X86_64:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef signed char int8_t;
end_comment

begin_comment
comment|// X86_64:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// X86_64:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// X86_64:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// X86_64:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// X86_64:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef long int intptr_t;
end_comment

begin_comment
comment|// X86_64:typedef unsigned long int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:typedef long int intmax_t;
end_comment

begin_comment
comment|// X86_64:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INT8_MAX_ 127
end_comment

begin_comment
comment|// X86_64:INT8_MIN_ (-128)
end_comment

begin_comment
comment|// X86_64:UINT8_MAX_ 255
end_comment

begin_comment
comment|// X86_64:INT_LEAST8_MIN_ (-128)
end_comment

begin_comment
comment|// X86_64:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// X86_64:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// X86_64:INT_FAST8_MIN_ (-128)
end_comment

begin_comment
comment|// X86_64:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// X86_64:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INT16_MAX_ 32767
end_comment

begin_comment
comment|// X86_64:INT16_MIN_ (-32768)
end_comment

begin_comment
comment|// X86_64:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// X86_64:INT_LEAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// X86_64:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// X86_64:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// X86_64:INT_FAST16_MIN_ (-32768)
end_comment

begin_comment
comment|// X86_64:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// X86_64:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// X86_64:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// X86_64:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// X86_64:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// X86_64:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// X86_64:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// X86_64:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// X86_64:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// X86_64:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// X86_64:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// X86_64:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// X86_64:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// X86_64:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// X86_64:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INTPTR_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// X86_64:INTPTR_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:UINTPTR_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// X86_64:PTRDIFF_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// X86_64:PTRDIFF_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// X86_64:SIZE_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INTMAX_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:INTMAX_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:UINTMAX_MAX_ (9223372036854775807L*2ULL +1ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// X86_64:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// X86_64:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// X86_64:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// X86_64:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INT8_C_(0) (0)
end_comment

begin_comment
comment|// X86_64:UINT8_C_(0) (0U)
end_comment

begin_comment
comment|// X86_64:INT16_C_(0) (0)
end_comment

begin_comment
comment|// X86_64:UINT16_C_(0) (0U)
end_comment

begin_comment
comment|// X86_64:INT32_C_(0) (0)
end_comment

begin_comment
comment|// X86_64:UINT32_C_(0) (0U)
end_comment

begin_comment
comment|// X86_64:INT64_C_(0) (0LL)
end_comment

begin_comment
comment|// X86_64:UINT64_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INTMAX_C_(0) (0LL)
end_comment

begin_comment
comment|// X86_64:UINTMAX_C_(0) (0ULL)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: true
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|INT8_MAX_
name|INT8_MAX
name|INT8_MIN_
name|INT8_MIN
name|UINT8_MAX_
name|UINT8_MAX
name|INT_LEAST8_MIN_
name|INT_LEAST8_MIN
name|INT_LEAST8_MAX_
name|INT_LEAST8_MAX
name|UINT_LEAST8_MAX_
name|UINT_LEAST8_MAX
name|INT_FAST8_MIN_
name|INT_FAST8_MIN
name|INT_FAST8_MAX_
name|INT_FAST8_MAX
name|UINT_FAST8_MAX_
name|UINT_FAST8_MAX
name|INT16_MAX_
name|INT16_MAX
name|INT16_MIN_
name|INT16_MIN
name|UINT16_MAX_
name|UINT16_MAX
name|INT_LEAST16_MIN_
name|INT_LEAST16_MIN
name|INT_LEAST16_MAX_
name|INT_LEAST16_MAX
name|UINT_LEAST16_MAX_
name|UINT_LEAST16_MAX
name|INT_FAST16_MIN_
name|INT_FAST16_MIN
name|INT_FAST16_MAX_
name|INT_FAST16_MAX
name|UINT_FAST16_MAX_
name|UINT_FAST16_MAX
name|INT32_MAX_
name|INT32_MAX
name|INT32_MIN_
name|INT32_MIN
name|UINT32_MAX_
name|UINT32_MAX
name|INT_LEAST32_MIN_
name|INT_LEAST32_MIN
name|INT_LEAST32_MAX_
name|INT_LEAST32_MAX
name|UINT_LEAST32_MAX_
name|UINT_LEAST32_MAX
name|INT_FAST32_MIN_
name|INT_FAST32_MIN
name|INT_FAST32_MAX_
name|INT_FAST32_MAX
name|UINT_FAST32_MAX_
name|UINT_FAST32_MAX
name|INT64_MAX_
name|INT64_MAX
name|INT64_MIN_
name|INT64_MIN
name|UINT64_MAX_
name|UINT64_MAX
name|INT_LEAST64_MIN_
name|INT_LEAST64_MIN
name|INT_LEAST64_MAX_
name|INT_LEAST64_MAX
name|UINT_LEAST64_MAX_
name|UINT_LEAST64_MAX
name|INT_FAST64_MIN_
name|INT_FAST64_MIN
name|INT_FAST64_MAX_
name|INT_FAST64_MAX
name|UINT_FAST64_MAX_
name|UINT_FAST64_MAX
name|INTPTR_MIN_
name|INTPTR_MIN
name|INTPTR_MAX_
name|INTPTR_MAX
name|UINTPTR_MAX_
name|UINTPTR_MAX
name|PTRDIFF_MIN_
name|PTRDIFF_MIN
name|PTRDIFF_MAX_
name|PTRDIFF_MAX
name|SIZE_MAX_
name|SIZE_MAX
name|INTMAX_MIN_
name|INTMAX_MIN
name|INTMAX_MAX_
name|INTMAX_MAX
name|UINTMAX_MAX_
name|UINTMAX_MAX
name|SIG_ATOMIC_MIN_
name|SIG_ATOMIC_MIN
name|SIG_ATOMIC_MAX_
name|SIG_ATOMIC_MAX
name|WINT_MIN_
name|WINT_MIN
name|WINT_MAX_
name|WINT_MAX
name|WCHAR_MAX_
name|WCHAR_MAX
name|WCHAR_MIN_
name|WCHAR_MIN
name|INT8_C_
argument_list|(
literal|0
argument_list|)
name|INT8_C
argument_list|(
literal|0
argument_list|)
name|UINT8_C_
argument_list|(
literal|0
argument_list|)
name|UINT8_C
argument_list|(
literal|0
argument_list|)
name|INT16_C_
argument_list|(
literal|0
argument_list|)
name|INT16_C
argument_list|(
literal|0
argument_list|)
name|UINT16_C_
argument_list|(
literal|0
argument_list|)
name|UINT16_C
argument_list|(
literal|0
argument_list|)
name|INT32_C_
argument_list|(
literal|0
argument_list|)
name|INT32_C
argument_list|(
literal|0
argument_list|)
name|UINT32_C_
argument_list|(
literal|0
argument_list|)
name|UINT32_C
argument_list|(
literal|0
argument_list|)
name|INT64_C_
argument_list|(
literal|0
argument_list|)
name|INT64_C
argument_list|(
literal|0
argument_list|)
name|UINT64_C_
argument_list|(
literal|0
argument_list|)
name|UINT64_C
argument_list|(
literal|0
argument_list|)
name|INTMAX_C_
argument_list|(
literal|0
argument_list|)
name|INTMAX_C
argument_list|(
literal|0
argument_list|)
name|UINTMAX_C_
argument_list|(
literal|0
argument_list|)
name|UINTMAX_C
argument_list|(
literal|0
argument_list|)
end_decl_stmt

end_unit

