begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=arm-none-none %s | FileCheck -check-prefix ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:typedef long long int int64_t;
end_comment

begin_comment
comment|// ARM:typedef long long unsigned int uint64_t;
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
comment|// ARM:typedef long unsigned int uintptr_t;
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
comment|// ARM:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// ARM:UINT8_MAX_ 255
end_comment

begin_comment
comment|// ARM:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// ARM:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// ARM:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// ARM:INT_FAST8_MIN_ (-127 -1)
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
comment|// ARM:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// ARM:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// ARM:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// ARM:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// ARM:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// ARM:INT_FAST16_MIN_ (-32767 -1)
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
comment|// ARM:INTPTR_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// ARM:INTPTR_MAX_ 2147483647L
end_comment

begin_comment
comment|// ARM:UINTPTR_MAX_ 4294967295UL
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
comment|// ARM:UINTMAX_MAX_ 18446744073709551615ULL
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
comment|// ARM:WCHAR_MAX_ 4294967295U
end_comment

begin_comment
comment|// ARM:WCHAR_MIN_ 0U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INT8_C_(0) 0
end_comment

begin_comment
comment|// ARM:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// ARM:INT16_C_(0) 0
end_comment

begin_comment
comment|// ARM:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// ARM:INT32_C_(0) 0
end_comment

begin_comment
comment|// ARM:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// ARM:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// ARM:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ARM:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// ARM:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=i386-none-none %s | FileCheck -check-prefix I386 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:typedef long long int int64_t;
end_comment

begin_comment
comment|// I386:typedef long long unsigned int uint64_t;
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
comment|// I386:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// I386:UINT8_MAX_ 255
end_comment

begin_comment
comment|// I386:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// I386:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// I386:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// I386:INT_FAST8_MIN_ (-127 -1)
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
comment|// I386:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// I386:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// I386:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// I386:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// I386:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// I386:INT_FAST16_MIN_ (-32767 -1)
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
comment|// I386:UINTMAX_MAX_ 18446744073709551615ULL
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
comment|// I386:INT8_C_(0) 0
end_comment

begin_comment
comment|// I386:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// I386:INT16_C_(0) 0
end_comment

begin_comment
comment|// I386:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// I386:INT32_C_(0) 0
end_comment

begin_comment
comment|// I386:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// I386:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// I386:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// I386:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=mips-none-none %s | FileCheck -check-prefix MIPS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef long long int int64_t;
end_comment

begin_comment
comment|// MIPS:typedef long long unsigned int uint64_t;
end_comment

begin_comment
comment|// MIPS:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// MIPS:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// MIPS:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// MIPS:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef int int32_t;
end_comment

begin_comment
comment|// MIPS:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// MIPS:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// MIPS:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// MIPS:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// MIPS:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef short int16_t;
end_comment

begin_comment
comment|// MIPS:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// MIPS:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// MIPS:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// MIPS:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// MIPS:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef signed char int8_t;
end_comment

begin_comment
comment|// MIPS:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// MIPS:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// MIPS:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// MIPS:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// MIPS:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef long int intptr_t;
end_comment

begin_comment
comment|// MIPS:typedef long unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:typedef long long int intmax_t;
end_comment

begin_comment
comment|// MIPS:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INT8_MAX_ 127
end_comment

begin_comment
comment|// MIPS:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS:UINT8_MAX_ 255
end_comment

begin_comment
comment|// MIPS:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// MIPS:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// MIPS:INT_FAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// MIPS:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INT16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// MIPS:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// MIPS:INT_FAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MIPS:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MIPS:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MIPS:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MIPS:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// MIPS:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MIPS:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INTPTR_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MIPS:INTPTR_MAX_ 2147483647L
end_comment

begin_comment
comment|// MIPS:UINTPTR_MAX_ 4294967295UL
end_comment

begin_comment
comment|// MIPS:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MIPS:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MIPS:UINTMAX_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INT8_C_(0) 0
end_comment

begin_comment
comment|// MIPS:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// MIPS:INT16_C_(0) 0
end_comment

begin_comment
comment|// MIPS:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// MIPS:INT32_C_(0) 0
end_comment

begin_comment
comment|// MIPS:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// MIPS:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// MIPS:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// MIPS:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=mips64-none-none %s | FileCheck -check-prefix MIPS64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef long int int64_t;
end_comment

begin_comment
comment|// MIPS64:typedef long unsigned int uint64_t;
end_comment

begin_comment
comment|// MIPS64:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// MIPS64:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef int int32_t;
end_comment

begin_comment
comment|// MIPS64:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// MIPS64:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// MIPS64:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef short int16_t;
end_comment

begin_comment
comment|// MIPS64:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// MIPS64:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// MIPS64:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef signed char int8_t;
end_comment

begin_comment
comment|// MIPS64:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// MIPS64:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// MIPS64:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// MIPS64:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef long int intptr_t;
end_comment

begin_comment
comment|// MIPS64:typedef long unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:typedef long int intmax_t;
end_comment

begin_comment
comment|// MIPS64:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INT8_MAX_ 127
end_comment

begin_comment
comment|// MIPS64:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS64:UINT8_MAX_ 255
end_comment

begin_comment
comment|// MIPS64:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS64:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// MIPS64:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// MIPS64:INT_FAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MIPS64:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// MIPS64:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INT16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS64:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS64:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// MIPS64:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS64:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS64:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// MIPS64:INT_FAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MIPS64:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// MIPS64:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS64:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS64:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MIPS64:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS64:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS64:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// MIPS64:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS64:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS64:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INT64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:INT64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:UINT64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64:INT_LEAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:INT_LEAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:UINT_LEAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64:INT_FAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:INT_FAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:UINT_FAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INTPTR_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:INTPTR_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:UINTPTR_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// MIPS64:PTRDIFF_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:PTRDIFF_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:SIZE_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INTMAX_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// MIPS64:INTMAX_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// MIPS64:UINTMAX_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS64:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS64:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// MIPS64:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// MIPS64:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INT8_C_(0) 0
end_comment

begin_comment
comment|// MIPS64:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// MIPS64:INT16_C_(0) 0
end_comment

begin_comment
comment|// MIPS64:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// MIPS64:INT32_C_(0) 0
end_comment

begin_comment
comment|// MIPS64:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// MIPS64:INT64_C_(0) 0L
end_comment

begin_comment
comment|// MIPS64:UINT64_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MIPS64:INTMAX_C_(0) 0L
end_comment

begin_comment
comment|// MIPS64:UINTMAX_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=msp430-none-none %s | FileCheck -check-prefix MSP430 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef long int int32_t;
end_comment

begin_comment
comment|// MSP430:typedef long unsigned int uint32_t;
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
comment|// MSP430:typedef int intptr_t;
end_comment

begin_comment
comment|// MSP430:typedef unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:typedef long long int intmax_t;
end_comment

begin_comment
comment|// MSP430:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT8_MAX_ 127
end_comment

begin_comment
comment|// MSP430:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MSP430:UINT8_MAX_ 255
end_comment

begin_comment
comment|// MSP430:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// MSP430:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// MSP430:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// MSP430:INT_FAST8_MIN_ (-127 -1)
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
comment|// MSP430:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MSP430:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MSP430:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:INT_FAST16_MIN_ (-32767 -1)
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
comment|// MSP430:INT32_MAX_ 2147483647L
end_comment

begin_comment
comment|// MSP430:INT32_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MSP430:UINT32_MAX_ 4294967295UL
end_comment

begin_comment
comment|// MSP430:INT_LEAST32_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MSP430:INT_LEAST32_MAX_ 2147483647L
end_comment

begin_comment
comment|// MSP430:UINT_LEAST32_MAX_ 4294967295UL
end_comment

begin_comment
comment|// MSP430:INT_FAST32_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MSP430:INT_FAST32_MAX_ 2147483647L
end_comment

begin_comment
comment|// MSP430:UINT_FAST32_MAX_ 4294967295UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MSP430:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MSP430:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// MSP430:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MSP430:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INTPTR_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MSP430:INTPTR_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:UINTPTR_MAX_ 65535
end_comment

begin_comment
comment|// MSP430:PTRDIFF_MIN_ (-32767 -1)
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
comment|// MSP430:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// MSP430:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// MSP430:UINTMAX_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:SIG_ATOMIC_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// MSP430:SIG_ATOMIC_MAX_ 2147483647L
end_comment

begin_comment
comment|// MSP430:WINT_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// MSP430:WINT_MAX_ 32767
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:WCHAR_MAX_ 32767
end_comment

begin_comment
comment|// MSP430:WCHAR_MIN_ (-32767 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INT8_C_(0) 0
end_comment

begin_comment
comment|// MSP430:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// MSP430:INT16_C_(0) 0
end_comment

begin_comment
comment|// MSP430:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// MSP430:INT32_C_(0) 0L
end_comment

begin_comment
comment|// MSP430:UINT32_C_(0) 0UL
end_comment

begin_comment
comment|// MSP430:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// MSP430:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MSP430:INTMAX_C_(0) 0L
end_comment

begin_comment
comment|// MSP430:UINTMAX_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=powerpc64-none-none %s | FileCheck -check-prefix PPC64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:typedef long int int64_t;
end_comment

begin_comment
comment|// PPC64:typedef long unsigned int uint64_t;
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
comment|// PPC64:typedef long unsigned int uintptr_t;
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
comment|// PPC64:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC64:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PPC64:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC64:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC64:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PPC64:INT_FAST8_MIN_ (-127 -1)
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
comment|// PPC64:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC64:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC64:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64:INT_FAST16_MIN_ (-32767 -1)
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
comment|// PPC64:INT64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:INT64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:UINT64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:INT_LEAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:INT_LEAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:UINT_LEAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:INT_FAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:INT_FAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:UINT_FAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INTPTR_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:INTPTR_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:UINTPTR_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64:PTRDIFF_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64:PTRDIFF_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64:SIZE_MAX_ 18446744073709551615UL
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
comment|// PPC64:UINTMAX_MAX_ 18446744073709551615UL
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
comment|// PPC64:INT8_C_(0) 0
end_comment

begin_comment
comment|// PPC64:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// PPC64:INT16_C_(0) 0
end_comment

begin_comment
comment|// PPC64:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// PPC64:INT32_C_(0) 0
end_comment

begin_comment
comment|// PPC64:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// PPC64:INT64_C_(0) 0L
end_comment

begin_comment
comment|// PPC64:UINT64_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64:INTMAX_C_(0) 0L
end_comment

begin_comment
comment|// PPC64:UINTMAX_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=powerpc64-none-netbsd %s | FileCheck -check-prefix PPC64-NETBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long long int int64_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long long unsigned int uint64_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int int32_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef short int16_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef signed char int8_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long int intptr_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long long int intmax_t;
end_comment

begin_comment
comment|// PPC64-NETBSD:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INT8_MAX_ 127
end_comment

begin_comment
comment|// PPC64-NETBSD:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INT16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64-NETBSD:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64-NETBSD:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64-NETBSD:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INTPTR_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INTPTR_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-NETBSD:UINTPTR_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// PPC64-NETBSD:PTRDIFF_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:PTRDIFF_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// PPC64-NETBSD:SIZE_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// PPC64-NETBSD:UINTMAX_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64-NETBSD:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// PPC64-NETBSD:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// PPC64-NETBSD:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INT8_C_(0) 0
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// PPC64-NETBSD:INT16_C_(0) 0
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// PPC64-NETBSD:INT32_C_(0) 0
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// PPC64-NETBSD:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// PPC64-NETBSD:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC64-NETBSD:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// PPC64-NETBSD:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=powerpc-none-none %s | FileCheck -check-prefix PPC %s
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
comment|// PPC:typedef long long unsigned int uint64_t;
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
comment|// PPC:typedef long unsigned int uintptr_t;
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
comment|// PPC:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC:UINT8_MAX_ 255
end_comment

begin_comment
comment|// PPC:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// PPC:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// PPC:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// PPC:INT_FAST8_MIN_ (-127 -1)
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
comment|// PPC:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// PPC:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// PPC:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// PPC:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// PPC:INT_FAST16_MIN_ (-32767 -1)
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
comment|// PPC:INTPTR_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// PPC:INTPTR_MAX_ 2147483647L
end_comment

begin_comment
comment|// PPC:UINTPTR_MAX_ 4294967295UL
end_comment

begin_comment
comment|// PPC:PTRDIFF_MIN_ (-2147483647L -1)
end_comment

begin_comment
comment|// PPC:PTRDIFF_MAX_ 2147483647L
end_comment

begin_comment
comment|// PPC:SIZE_MAX_ 4294967295UL
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
comment|// PPC:UINTMAX_MAX_ 18446744073709551615ULL
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
comment|// PPC:INT8_C_(0) 0
end_comment

begin_comment
comment|// PPC:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// PPC:INT16_C_(0) 0
end_comment

begin_comment
comment|// PPC:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// PPC:INT32_C_(0) 0
end_comment

begin_comment
comment|// PPC:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// PPC:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// PPC:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PPC:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// PPC:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=s390x-none-none %s | FileCheck -check-prefix S390X %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef long int int64_t;
end_comment

begin_comment
comment|// S390X:typedef long unsigned int uint64_t;
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
comment|// S390X:typedef long unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:typedef long int intmax_t;
end_comment

begin_comment
comment|// S390X:typedef long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INT8_MAX_ 127
end_comment

begin_comment
comment|// S390X:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// S390X:UINT8_MAX_ 255
end_comment

begin_comment
comment|// S390X:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// S390X:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// S390X:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// S390X:INT_FAST8_MIN_ (-127 -1)
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
comment|// S390X:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// S390X:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// S390X:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// S390X:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// S390X:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// S390X:INT_FAST16_MIN_ (-32767 -1)
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
comment|// S390X:INT64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:INT64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:UINT64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:INT_LEAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:INT_LEAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:UINT_LEAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:INT_FAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:INT_FAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:UINT_FAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTPTR_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:INTPTR_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:UINTPTR_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// S390X:PTRDIFF_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:PTRDIFF_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:SIZE_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTMAX_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// S390X:INTMAX_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// S390X:UINTMAX_MAX_ 18446744073709551615UL
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
comment|// S390X:INT8_C_(0) 0
end_comment

begin_comment
comment|// S390X:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// S390X:INT16_C_(0) 0
end_comment

begin_comment
comment|// S390X:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// S390X:INT32_C_(0) 0
end_comment

begin_comment
comment|// S390X:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// S390X:INT64_C_(0) 0L
end_comment

begin_comment
comment|// S390X:UINT64_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S390X:INTMAX_C_(0) 0L
end_comment

begin_comment
comment|// S390X:UINTMAX_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=sparc-none-none %s | FileCheck -check-prefix SPARC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:typedef long long int int64_t;
end_comment

begin_comment
comment|// SPARC:typedef long long unsigned int uint64_t;
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
comment|// SPARC:typedef int intptr_t;
end_comment

begin_comment
comment|// SPARC:typedef unsigned int uintptr_t;
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
comment|// SPARC:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// SPARC:UINT8_MAX_ 255
end_comment

begin_comment
comment|// SPARC:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// SPARC:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// SPARC:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// SPARC:INT_FAST8_MIN_ (-127 -1)
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
comment|// SPARC:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// SPARC:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// SPARC:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// SPARC:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// SPARC:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// SPARC:INT_FAST16_MIN_ (-32767 -1)
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
comment|// SPARC:UINTMAX_MAX_ 18446744073709551615ULL
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
comment|// SPARC:INT8_C_(0) 0
end_comment

begin_comment
comment|// SPARC:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// SPARC:INT16_C_(0) 0
end_comment

begin_comment
comment|// SPARC:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// SPARC:INT32_C_(0) 0
end_comment

begin_comment
comment|// SPARC:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// SPARC:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// SPARC:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SPARC:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// SPARC:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=tce-none-none %s | FileCheck -check-prefix TCE %s
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
comment|// TCE:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// TCE:UINT8_MAX_ 255
end_comment

begin_comment
comment|// TCE:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// TCE:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// TCE:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// TCE:INT_FAST8_MIN_ (-127 -1)
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
comment|// TCE:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// TCE:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// TCE:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// TCE:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// TCE:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// TCE:INT_FAST16_MIN_ (-32767 -1)
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
comment|// TCE:UINTMAX_MAX_ 4294967295UL
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
comment|// TCE:INT8_C_(0) 0
end_comment

begin_comment
comment|// TCE:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// TCE:INT16_C_(0) 0
end_comment

begin_comment
comment|// TCE:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// TCE:INT32_C_(0) 0
end_comment

begin_comment
comment|// TCE:UINT32_C_(0) 0U
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
comment|// TCE:INTMAX_C_(0) 0
end_comment

begin_comment
comment|// TCE:UINTMAX_C_(0) 0U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=x86_64-none-none %s | FileCheck -check-prefix X86_64 %s
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
comment|// X86_64:typedef long unsigned int uint64_t;
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
comment|// X86_64:typedef long unsigned int uintptr_t;
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
comment|// X86_64:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// X86_64:UINT8_MAX_ 255
end_comment

begin_comment
comment|// X86_64:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// X86_64:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// X86_64:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// X86_64:INT_FAST8_MIN_ (-127 -1)
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
comment|// X86_64:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// X86_64:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// X86_64:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// X86_64:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// X86_64:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// X86_64:INT_FAST16_MIN_ (-32767 -1)
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
comment|// X86_64:INT64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:INT64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:UINT64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:INT_LEAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:INT_LEAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:UINT_LEAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:INT_FAST64_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:INT_FAST64_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:UINT_FAST64_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INTPTR_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:INTPTR_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:UINTPTR_MAX_ 18446744073709551615UL
end_comment

begin_comment
comment|// X86_64:PTRDIFF_MIN_ (-9223372036854775807L -1)
end_comment

begin_comment
comment|// X86_64:PTRDIFF_MAX_ 9223372036854775807L
end_comment

begin_comment
comment|// X86_64:SIZE_MAX_ 18446744073709551615UL
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
comment|// X86_64:UINTMAX_MAX_ 18446744073709551615UL
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
comment|// X86_64:INT8_C_(0) 0
end_comment

begin_comment
comment|// X86_64:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// X86_64:INT16_C_(0) 0
end_comment

begin_comment
comment|// X86_64:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// X86_64:INT32_C_(0) 0
end_comment

begin_comment
comment|// X86_64:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// X86_64:INT64_C_(0) 0L
end_comment

begin_comment
comment|// X86_64:UINT64_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64:INTMAX_C_(0) 0L
end_comment

begin_comment
comment|// X86_64:UINTMAX_C_(0) 0UL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=x86_64-pc-linux-gnu %s | FileCheck -check-prefix X86_64_LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86_64_LINUX:WINT_MIN_ 0U
end_comment

begin_comment
comment|// X86_64_LINUX:WINT_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=i386-mingw32 %s | FileCheck -check-prefix I386_MINGW32 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// I386_MINGW32:WCHAR_MAX_ 65535
end_comment

begin_comment
comment|// I386_MINGW32:WCHAR_MIN_ 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding -triple=xcore-none-none %s | FileCheck -check-prefix XCORE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef long long int int64_t;
end_comment

begin_comment
comment|// XCORE:typedef long long unsigned int uint64_t;
end_comment

begin_comment
comment|// XCORE:typedef int64_t int_least64_t;
end_comment

begin_comment
comment|// XCORE:typedef uint64_t uint_least64_t;
end_comment

begin_comment
comment|// XCORE:typedef int64_t int_fast64_t;
end_comment

begin_comment
comment|// XCORE:typedef uint64_t uint_fast64_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef int int32_t;
end_comment

begin_comment
comment|// XCORE:typedef unsigned int uint32_t;
end_comment

begin_comment
comment|// XCORE:typedef int32_t int_least32_t;
end_comment

begin_comment
comment|// XCORE:typedef uint32_t uint_least32_t;
end_comment

begin_comment
comment|// XCORE:typedef int32_t int_fast32_t;
end_comment

begin_comment
comment|// XCORE:typedef uint32_t uint_fast32_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef short int16_t;
end_comment

begin_comment
comment|// XCORE:typedef unsigned short uint16_t;
end_comment

begin_comment
comment|// XCORE:typedef int16_t int_least16_t;
end_comment

begin_comment
comment|// XCORE:typedef uint16_t uint_least16_t;
end_comment

begin_comment
comment|// XCORE:typedef int16_t int_fast16_t;
end_comment

begin_comment
comment|// XCORE:typedef uint16_t uint_fast16_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef signed char int8_t;
end_comment

begin_comment
comment|// XCORE:typedef unsigned char uint8_t;
end_comment

begin_comment
comment|// XCORE:typedef int8_t int_least8_t;
end_comment

begin_comment
comment|// XCORE:typedef uint8_t uint_least8_t;
end_comment

begin_comment
comment|// XCORE:typedef int8_t int_fast8_t;
end_comment

begin_comment
comment|// XCORE:typedef uint8_t uint_fast8_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef int intptr_t;
end_comment

begin_comment
comment|// XCORE:typedef unsigned int uintptr_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:typedef long long int intmax_t;
end_comment

begin_comment
comment|// XCORE:typedef long long unsigned int uintmax_t;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INT8_MAX_ 127
end_comment

begin_comment
comment|// XCORE:INT8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// XCORE:UINT8_MAX_ 255
end_comment

begin_comment
comment|// XCORE:INT_LEAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// XCORE:INT_LEAST8_MAX_ 127
end_comment

begin_comment
comment|// XCORE:UINT_LEAST8_MAX_ 255
end_comment

begin_comment
comment|// XCORE:INT_FAST8_MIN_ (-127 -1)
end_comment

begin_comment
comment|// XCORE:INT_FAST8_MAX_ 127
end_comment

begin_comment
comment|// XCORE:UINT_FAST8_MAX_ 255
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INT16_MAX_ 32767
end_comment

begin_comment
comment|// XCORE:INT16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// XCORE:UINT16_MAX_ 65535
end_comment

begin_comment
comment|// XCORE:INT_LEAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// XCORE:INT_LEAST16_MAX_ 32767
end_comment

begin_comment
comment|// XCORE:UINT_LEAST16_MAX_ 65535
end_comment

begin_comment
comment|// XCORE:INT_FAST16_MIN_ (-32767 -1)
end_comment

begin_comment
comment|// XCORE:INT_FAST16_MAX_ 32767
end_comment

begin_comment
comment|// XCORE:UINT_FAST16_MAX_ 65535
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INT32_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:INT32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:UINT32_MAX_ 4294967295U
end_comment

begin_comment
comment|// XCORE:INT_LEAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:INT_LEAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:UINT_LEAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|// XCORE:INT_FAST32_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:INT_FAST32_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:UINT_FAST32_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INT64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// XCORE:INT64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// XCORE:UINT64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// XCORE:INT_LEAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// XCORE:INT_LEAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// XCORE:UINT_LEAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// XCORE:INT_FAST64_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// XCORE:INT_FAST64_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// XCORE:UINT_FAST64_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// XCORE:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// XCORE:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// XCORE:UINTMAX_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// XCORE:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// XCORE:WINT_MIN_ 0U
end_comment

begin_comment
comment|// XCORE:WINT_MAX_ 4294967295U
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:WCHAR_MAX_ 255
end_comment

begin_comment
comment|// XCORE:WCHAR_MIN_ 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INT8_C_(0) 0
end_comment

begin_comment
comment|// XCORE:UINT8_C_(0) 0U
end_comment

begin_comment
comment|// XCORE:INT16_C_(0) 0
end_comment

begin_comment
comment|// XCORE:UINT16_C_(0) 0U
end_comment

begin_comment
comment|// XCORE:INT32_C_(0) 0
end_comment

begin_comment
comment|// XCORE:UINT32_C_(0) 0U
end_comment

begin_comment
comment|// XCORE:INT64_C_(0) 0LL
end_comment

begin_comment
comment|// XCORE:UINT64_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XCORE:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// XCORE:UINTMAX_C_(0) 0ULL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// stdint.h forms several macro definitions by pasting together identifiers
end_comment

begin_comment
comment|// to form names (eg. int32_t is formed from int ## 32 ## _t). The following
end_comment

begin_comment
comment|// case tests that these joining operations are performed correctly even if
end_comment

begin_comment
comment|// the identifiers used in the operations (int, uint, _t, INT, UINT, _MIN,
end_comment

begin_comment
comment|// _MAX, and _C(v)) are themselves macros.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -ffreestanding                                 \
end_comment

begin_comment
comment|// RUN:   -U__UINTPTR_TYPE__ -U__INTPTR_TYPE__                       \
end_comment

begin_comment
comment|// RUN:   -U__UINTMAX_TYPE__ -U__INTMAX_TYPE__                       \
end_comment

begin_comment
comment|// RUN:   -Dint=a -Duint=b -D_t=c -DINT=d -DUINT=e -D_MIN=f -D_MAX=g \
end_comment

begin_comment
comment|// RUN:   '-D_C(v)=h' -triple=i386-none-none %s                      \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix JOIN %s
end_comment

begin_comment
comment|// JOIN:typedef __INTPTR_TYPE__ intptr_t;
end_comment

begin_comment
comment|// JOIN:typedef __UINTPTR_TYPE__ uintptr_t;
end_comment

begin_comment
comment|// JOIN:typedef __INTMAX_TYPE__ intmax_t;
end_comment

begin_comment
comment|// JOIN:typedef __UINTMAX_TYPE__ uintmax_t;
end_comment

begin_comment
comment|// JOIN:INTPTR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// JOIN:INTPTR_MAX_ 2147483647
end_comment

begin_comment
comment|// JOIN:UINTPTR_MAX_ 4294967295U
end_comment

begin_comment
comment|// JOIN:PTRDIFF_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// JOIN:PTRDIFF_MAX_ 2147483647
end_comment

begin_comment
comment|// JOIN:SIZE_MAX_ 4294967295U
end_comment

begin_comment
comment|// JOIN:INTMAX_MIN_ (-9223372036854775807LL -1)
end_comment

begin_comment
comment|// JOIN:INTMAX_MAX_ 9223372036854775807LL
end_comment

begin_comment
comment|// JOIN:UINTMAX_MAX_ 18446744073709551615ULL
end_comment

begin_comment
comment|// JOIN:SIG_ATOMIC_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// JOIN:SIG_ATOMIC_MAX_ 2147483647
end_comment

begin_comment
comment|// JOIN:WINT_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// JOIN:WINT_MAX_ 2147483647
end_comment

begin_comment
comment|// JOIN:WCHAR_MAX_ 2147483647
end_comment

begin_comment
comment|// JOIN:WCHAR_MIN_ (-2147483647 -1)
end_comment

begin_comment
comment|// JOIN:INTMAX_C_(0) 0LL
end_comment

begin_comment
comment|// JOIN:UINTMAX_C_(0) 0ULL
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

