begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=ULONG -triple powerpc-unknown-linux-gnu -std=c89 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=ULONG -triple powerpc-unknown-linux-gnu -std=iso9899:199409 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=ULONG -triple powerpc-unknown-linux-gnu -std=c++98 -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=LLONG -triple powerpc-unknown-linux-gnu -std=c99 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=LLONG -triple powerpc-unknown-linux-gnu -std=c11 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=LLONG -triple powerpc-unknown-linux-gnu -std=c++11 -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=LLONG -triple powerpc-unknown-linux-gnu -std=c++1y -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX32TYPE=LLONG -triple powerpc-unknown-linux-gnu -std=c++1z -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULONG -triple powerpc64-unknown-linux-gnu -std=c89 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULONG -triple powerpc64-unknown-linux-gnu -std=iso9899:199409 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULONG -triple powerpc64-unknown-linux-gnu -std=c++98 -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULLONG -triple powerpc64-unknown-linux-gnu -std=c99 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULLONG -triple powerpc64-unknown-linux-gnu -std=c11 -x c %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULLONG -triple powerpc64-unknown-linux-gnu -std=c++11 -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULLONG -triple powerpc64-unknown-linux-gnu -std=c++1y -x c++ %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DX64TYPE=ULLONG -triple powerpc64-unknown-linux-gnu -std=c++1z -x c++ %s -verify
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|X64TYPE
end_ifdef

begin_define
define|#
directive|define
name|X32TYPE
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_ULONG_ULONG
value|1
end_define

begin_define
define|#
directive|define
name|IS_ULONG2
parameter_list|(
name|X
parameter_list|)
value|IS_ULONG_##X
end_define

begin_define
define|#
directive|define
name|IS_ULONG
parameter_list|(
name|X
parameter_list|)
value|IS_ULONG2(X)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|X64TYPE
argument_list|)
operator|&&
operator|!
name|IS_ULONG
argument_list|(
name|X32TYPE
argument_list|)
end_if

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|LLONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|ULLONG
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  * Test 2^31 as a decimal literal with no suffix and with the "l" and "L" cases.  ******************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|X32TYPE
name|x32
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __typeof__(2147483648
end_extern

begin_expr_stmt
unit|)
name|x32
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof__(2147483648l
end_extern

begin_expr_stmt
unit|)
name|x32
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof__(2147483648L
end_extern

begin_expr_stmt
unit|)
name|x32
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|IS_ULONG
argument_list|(
name|X32TYPE
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|__cplusplus
end_if

begin_comment
comment|/******************************************************************************  * Under pre-C99 ISO C, unsigned long is attempted for decimal integer literals  * that do not have a suffix containing "u" or "U" if the literal does not fit  * within the range of int or long. See 6.1.3.2 paragraph 5.  ******************************************************************************/
end_comment

begin_comment
comment|// expected-warning@39 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will have type 'long long' in C99 onwards}}
end_comment

begin_comment
comment|// expected-warning@40 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will have type 'long long' in C99 onwards}}
end_comment

begin_comment
comment|// expected-warning@41 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will have type 'long long' in C99 onwards}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  * Under pre-C++11 ISO C++, the same holds if the literal contains an "l" or "L"  * in its suffix; otherwise, the behavior is undefined. See 2.13.1 [lex.icon]  * paragraph 2.  ******************************************************************************/
end_comment

begin_comment
comment|// expected-warning@39 {{integer literal is too large to be represented in type 'long' and is subject to undefined behavior under C++98, interpreting as 'unsigned long'; this literal will have type 'long long' in C++11 onwards}}
end_comment

begin_comment
comment|// expected-warning@40 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C++98; this literal will have type 'long long' in C++11 onwards}}
end_comment

begin_comment
comment|// expected-warning@41 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C++98; this literal will have type 'long long' in C++11 onwards}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|X64TYPE
end_ifdef

begin_comment
comment|/******************************************************************************  * Test 2^63 as a decimal literal with no suffix and with the "l" and "L" cases.  ******************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|X64TYPE
name|x64
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __typeof__(9223372036854775808
end_extern

begin_expr_stmt
unit|)
name|x64
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof__(9223372036854775808l
end_extern

begin_expr_stmt
unit|)
name|x64
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof__(9223372036854775808L
end_extern

begin_expr_stmt
unit|)
name|x64
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|IS_ULONG
argument_list|(
name|X64TYPE
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|__cplusplus
end_if

begin_comment
comment|/******************************************************************************  * Under pre-C99 ISO C, unsigned long is attempted for decimal integer literals  * that do not have a suffix containing "u" or "U" if the literal does not fit  * within the range of int or long. See 6.1.3.2 paragraph 5.  ******************************************************************************/
end_comment

begin_comment
comment|// expected-warning@74 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will be ill-formed in C99 onwards}}
end_comment

begin_comment
comment|// expected-warning@75 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will be ill-formed in C99 onwards}}
end_comment

begin_comment
comment|// expected-warning@76 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C89; this literal will be ill-formed in C99 onwards}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  * Under pre-C++11 ISO C++, the same holds if the literal contains an "l" or "L"  * in its suffix; otherwise, the behavior is undefined. See 2.13.1 [lex.icon]  * paragraph 2.  ******************************************************************************/
end_comment

begin_comment
comment|// expected-warning@74 {{integer literal is too large to be represented in type 'long' and is subject to undefined behavior under C++98, interpreting as 'unsigned long'; this literal will be ill-formed in C++11 onwards}}
end_comment

begin_comment
comment|// expected-warning@75 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C++98; this literal will be ill-formed in C++11 onwards}}
end_comment

begin_comment
comment|// expected-warning@76 {{integer literal is too large to be represented in type 'long', interpreting as 'unsigned long' per C++98; this literal will be ill-formed in C++11 onwards}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  * The status quo in C99/C++11-and-later modes for the literals in question is  * to interpret them as unsigned as an extension.  ******************************************************************************/
end_comment

begin_comment
comment|// expected-warning@74 {{integer literal is too large to be represented in a signed integer type, interpreting as unsigned}}
end_comment

begin_comment
comment|// expected-warning@75 {{integer literal is too large to be represented in a signed integer type, interpreting as unsigned}}
end_comment

begin_comment
comment|// expected-warning@76 {{integer literal is too large to be represented in a signed integer type, interpreting as unsigned}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************  * Test preprocessor arithmetic with 2^31 as a decimal literal with no suffix  * and with the "l" and "L" cases.  ******************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|IS_ULONG
argument_list|(
name|X32TYPE
argument_list|)
end_if

begin_comment
comment|/******************************************************************************  * If the literal is signed without need for the modified range of the signed  * integer types within the controlling constant expression for conditional  * inclusion, then it will also be signed with said modified range.  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|EXPR
parameter_list|(
name|X
parameter_list|)
value|((X - X) - 1< 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  * Strictly speaking, in pre-C99/C++11 ISO C/C++, the preprocessor arithmetic is  * evaluated with the range of long/unsigned long; however, both Clang and GCC  * evaluate using 64-bits even when long/unsigned long are 32-bits outside of  * preprocessing.  *  * If the range used becomes 32-bits, then this test will enforce the treatment  * as unsigned of the literals in question.  *  * Note:  * Under pre-C99/C++11 ISO C/C++, whether the interpretation of the literal is  * affected by the modified range of the signed and unsigned integer types  * within the controlling constant expression for conditional inclusion is  * unclear.  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PP_LONG_MAX
value|((0ul - 1ul)>> 1)
end_define

begin_define
define|#
directive|define
name|EXPR
parameter_list|(
name|X
parameter_list|)
define|\
value|(PP_LONG_MAX>= 0x80000000 || (X - X) - 1> 0)
end_define

begin_comment
comment|// either 2^31 fits into a
end_comment

begin_comment
comment|// preprocessor "long" or the
end_comment

begin_comment
comment|// literals in question are
end_comment

begin_comment
comment|// unsigned
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|EXPR
argument_list|(
literal|2147483648
argument_list|)
operator|&&
name|EXPR
argument_list|(
literal|2147483648l
argument_list|)
operator|&&
name|EXPR
argument_list|(
literal|2147483648L
argument_list|)
operator|)
end_if

begin_error
error|#
directive|error
error|Unexpected signedness or conversion behavior
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

