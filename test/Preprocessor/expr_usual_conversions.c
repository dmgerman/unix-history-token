begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -verify
end_comment

begin_define
define|#
directive|define
name|INTMAX_MIN
value|(-9223372036854775807LL -1)
end_define

begin_if
if|#
directive|if
operator|(
operator|-
literal|42
operator|+
literal|0U
operator|)
comment|/* expected-warning {{left side of operator converted from negative value to unsigned: -42 to 18446744073709551574}} */
expr|\
operator|/
operator|-
literal|2
end_if

begin_comment
comment|/* expected-warning {{right side of operator converted from negative value to unsigned: -2 to 18446744073709551614}} */
end_comment

begin_macro
name|foo
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Shifts don't want the usual conversions: PR2279
end_comment

begin_if
if|#
directive|if
operator|(
literal|2
operator|<<
literal|1U
operator|)
operator|-
literal|30
operator|>=
literal|0
end_if

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

