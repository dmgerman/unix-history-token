begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dM -ffreestanding -triple=thumbv7k-apple-watchos2.0< /dev/null | FileCheck %s
end_comment

begin_comment
comment|// Check that the chosen types for things like size_t, ptrdiff_t etc are as
end_comment

begin_comment
comment|// expected
end_comment

begin_comment
comment|// CHECK-NOT: #define _LP64 1
end_comment

begin_comment
comment|// CHECK-NOT: #define __AARCH_BIG_ENDIAN 1
end_comment

begin_comment
comment|// CHECK-NOT: #define __ARM_BIG_ENDIAN 1
end_comment

begin_comment
comment|// CHECK: #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// CHECK: #define __CHAR16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK: #define __CHAR32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK: #define __CHAR_BIT__ 8
end_comment

begin_comment
comment|// CHECK: #define __DBL_DENORM_MIN__ 4.9406564584124654e-324
end_comment

begin_comment
comment|// CHECK: #define __DBL_DIG__ 15
end_comment

begin_comment
comment|// CHECK: #define __DBL_EPSILON__ 2.2204460492503131e-16
end_comment

begin_comment
comment|// CHECK: #define __DBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// CHECK: #define __DBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// CHECK: #define __DBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// CHECK: #define __DBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// CHECK: #define __DBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// CHECK: #define __DBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// CHECK: #define __DBL_MAX__ 1.7976931348623157e+308
end_comment

begin_comment
comment|// CHECK: #define __DBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// CHECK: #define __DBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// CHECK: #define __DBL_MIN__ 2.2250738585072014e-308
end_comment

begin_comment
comment|// CHECK: #define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
end_comment

begin_comment
comment|// CHECK: #define __FLT_DENORM_MIN__ 1.40129846e-45F
end_comment

begin_comment
comment|// CHECK: #define __FLT_DIG__ 6
end_comment

begin_comment
comment|// CHECK: #define __FLT_EPSILON__ 1.19209290e-7F
end_comment

begin_comment
comment|// CHECK: #define __FLT_EVAL_METHOD__ 0
end_comment

begin_comment
comment|// CHECK: #define __FLT_HAS_DENORM__ 1
end_comment

begin_comment
comment|// CHECK: #define __FLT_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// CHECK: #define __FLT_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// CHECK: #define __FLT_MANT_DIG__ 24
end_comment

begin_comment
comment|// CHECK: #define __FLT_MAX_10_EXP__ 38
end_comment

begin_comment
comment|// CHECK: #define __FLT_MAX_EXP__ 128
end_comment

begin_comment
comment|// CHECK: #define __FLT_MAX__ 3.40282347e+38F
end_comment

begin_comment
comment|// CHECK: #define __FLT_MIN_10_EXP__ (-37)
end_comment

begin_comment
comment|// CHECK: #define __FLT_MIN_EXP__ (-125)
end_comment

begin_comment
comment|// CHECK: #define __FLT_MIN__ 1.17549435e-38F
end_comment

begin_comment
comment|// CHECK: #define __FLT_RADIX__ 2
end_comment

begin_comment
comment|// CHECK: #define __INT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __INT16_FMTd__ "hd"
end_comment

begin_comment
comment|// CHECK: #define __INT16_FMTi__ "hi"
end_comment

begin_comment
comment|// CHECK: #define __INT16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK: #define __INT16_TYPE__ short
end_comment

begin_comment
comment|// CHECK: #define __INT32_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __INT32_FMTd__ "d"
end_comment

begin_comment
comment|// CHECK: #define __INT32_FMTi__ "i"
end_comment

begin_comment
comment|// CHECK: #define __INT32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __INT32_TYPE__ int
end_comment

begin_comment
comment|// CHECK: #define __INT64_C_SUFFIX__ LL
end_comment

begin_comment
comment|// CHECK: #define __INT64_FMTd__ "lld"
end_comment

begin_comment
comment|// CHECK: #define __INT64_FMTi__ "lli"
end_comment

begin_comment
comment|// CHECK: #define __INT64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK: #define __INT64_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK: #define __INT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __INT8_FMTd__ "hhd"
end_comment

begin_comment
comment|// CHECK: #define __INT8_FMTi__ "hhi"
end_comment

begin_comment
comment|// CHECK: #define __INT8_MAX__ 127
end_comment

begin_comment
comment|// CHECK: #define __INT8_TYPE__ signed char
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_C_SUFFIX__ LL
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_FMTd__ "lld"
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_FMTi__ "lli"
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK: #define __INTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// CHECK: #define __INTPTR_FMTd__ "ld"
end_comment

begin_comment
comment|// CHECK: #define __INTPTR_FMTi__ "li"
end_comment

begin_comment
comment|// CHECK: #define __INTPTR_MAX__ 2147483647L
end_comment

begin_comment
comment|// CHECK: #define __INTPTR_TYPE__ long int
end_comment

begin_comment
comment|// CHECK: #define __INTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST16_TYPE__ short
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST32_FMTd__ "d"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST32_FMTi__ "i"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST32_TYPE__ int
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST64_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST8_MAX__ 127
end_comment

begin_comment
comment|// CHECK: #define __INT_FAST8_TYPE__ signed char
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST16_FMTd__ "hd"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST16_FMTi__ "hi"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST16_MAX__ 32767
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST16_TYPE__ short
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST32_FMTd__ "d"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST32_FMTi__ "i"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST32_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST32_TYPE__ int
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST64_FMTd__ "lld"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST64_FMTi__ "lli"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST64_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST64_TYPE__ long long int
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST8_FMTd__ "hhd"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST8_FMTi__ "hhi"
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST8_MAX__ 127
end_comment

begin_comment
comment|// CHECK: #define __INT_LEAST8_TYPE__ signed char
end_comment

begin_comment
comment|// CHECK: #define __INT_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __LDBL_DENORM_MIN__  4.9406564584124654e-324L
end_comment

begin_comment
comment|// CHECK: #define __LDBL_DIG__ 15
end_comment

begin_comment
comment|// CHECK: #define __LDBL_EPSILON__ 2.2204460492503131e-16L
end_comment

begin_comment
comment|// CHECK: #define __LDBL_HAS_DENORM__ 1
end_comment

begin_comment
comment|// CHECK: #define __LDBL_HAS_INFINITY__ 1
end_comment

begin_comment
comment|// CHECK: #define __LDBL_HAS_QUIET_NAN__ 1
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MANT_DIG__ 53
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MAX_10_EXP__ 308
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MAX_EXP__ 1024
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MAX__ 1.7976931348623157e+308L
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MIN_10_EXP__ (-307)
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MIN_EXP__ (-1021)
end_comment

begin_comment
comment|// CHECK: #define __LDBL_MIN__ 2.2250738585072014e-308L
end_comment

begin_comment
comment|// CHECK: #define __LONG_LONG_MAX__ 9223372036854775807LL
end_comment

begin_comment
comment|// CHECK: #define __LONG_MAX__ 2147483647L
end_comment

begin_comment
comment|// CHECK: #define __POINTER_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __PTRDIFF_TYPE__ long int
end_comment

begin_comment
comment|// CHECK: #define __PTRDIFF_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __SCHAR_MAX__ 127
end_comment

begin_comment
comment|// CHECK: #define __SHRT_MAX__ 32767
end_comment

begin_comment
comment|// CHECK: #define __SIG_ATOMIC_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __SIG_ATOMIC_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_WCHAR_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZE_MAX__ 4294967295UL
end_comment

begin_comment
comment|// CHECK: #define __SIZE_TYPE__ long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __SIZE_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __UINT16_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __UINT16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK: #define __UINT16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK: #define __UINT32_C_SUFFIX__ U
end_comment

begin_comment
comment|// CHECK: #define __UINT32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK: #define __UINT32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT64_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// CHECK: #define __UINT64_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK: #define __UINT64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT8_C_SUFFIX__ {{$}}
end_comment

begin_comment
comment|// CHECK: #define __UINT8_MAX__ 255
end_comment

begin_comment
comment|// CHECK: #define __UINT8_TYPE__ unsigned char
end_comment

begin_comment
comment|// CHECK: #define __UINTMAX_C_SUFFIX__ ULL
end_comment

begin_comment
comment|// CHECK: #define __UINTMAX_MAX__ 18446744073709551615ULL
end_comment

begin_comment
comment|// CHECK: #define __UINTMAX_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINTMAX_WIDTH__ 64
end_comment

begin_comment
comment|// CHECK: #define __UINTPTR_MAX__ 4294967295UL
end_comment

begin_comment
comment|// CHECK: #define __UINTPTR_TYPE__ long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINTPTR_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST8_MAX__ 255
end_comment

begin_comment
comment|// CHECK: #define __UINT_FAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST16_MAX__ 65535
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST16_TYPE__ unsigned short
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST32_MAX__ 4294967295U
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST32_TYPE__ unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST64_MAX__ 18446744073709551615UL
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST64_TYPE__ long long unsigned int
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST8_MAX__ 255
end_comment

begin_comment
comment|// CHECK: #define __UINT_LEAST8_TYPE__ unsigned char
end_comment

begin_comment
comment|// CHECK: #define __USER_LABEL_PREFIX__ _
end_comment

begin_comment
comment|// CHECK: #define __WCHAR_MAX__ 2147483647
end_comment

begin_comment
comment|// CHECK: #define __WCHAR_TYPE__ int
end_comment

begin_comment
comment|// CHECK-NOT: #define __WCHAR_UNSIGNED__ 1
end_comment

begin_comment
comment|// CHECK: #define __WCHAR_WIDTH__ 32
end_comment

begin_comment
comment|// CHECK: #define __WINT_TYPE__ int
end_comment

begin_comment
comment|// CHECK: #define __WINT_WIDTH__ 32
end_comment

end_unit

