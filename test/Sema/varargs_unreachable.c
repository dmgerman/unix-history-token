begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple x86_64-apple-darwin9
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// From<rdar://problem/12322000>.  Do not warn about undefined behavior of parameter
end_comment

begin_comment
comment|// argument types in unreachable code in a macro.
end_comment

begin_define
define|#
directive|define
name|VA_ARG_RDAR12322000
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|((sizeof (TYPE)< sizeof (UINTN_RDAR12322000)) ? (TYPE)(__builtin_va_arg (Marker, UINTN_RDAR12322000)) : (TYPE)(__builtin_va_arg (Marker, TYPE)))
end_define

begin_comment
comment|// 64-bit system
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|UINTN_RDAR12322000
typedef|;
end_typedef

begin_function
name|int
name|test_VA_ARG_RDAR12322000
parameter_list|(
name|__builtin_va_list
name|Marker
parameter_list|)
block|{
return|return
name|VA_ARG_RDAR12322000
argument_list|(
name|Marker
argument_list|,
name|short
argument_list|)
return|;
comment|// no-warning
block|}
end_function

end_unit

