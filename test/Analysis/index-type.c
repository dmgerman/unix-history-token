begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 -analyzer-checker=core,alpha.security.ArrayBoundV2 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -triple i386-apple-darwin10 -analyzer-checker=core,alpha.security.ArrayBoundV2 -DM32 -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|(~0u)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M32
end_ifdef

begin_define
define|#
directive|define
name|X86_ARRAY_SIZE
value|(UINT_MAX/2 + 4)
end_define

begin_function
name|void
name|testIndexTooBig
parameter_list|()
block|{
name|char
name|arr
index|[
name|X86_ARRAY_SIZE
index|]
decl_stmt|;
name|char
modifier|*
name|ptr
init|=
name|arr
operator|+
name|UINT_MAX
operator|/
literal|2
decl_stmt|;
name|ptr
operator|+=
literal|2
expr_stmt|;
comment|// index shouldn't overflow
operator|*
name|ptr
operator|=
literal|42
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// 64-bit tests
end_comment

begin_define
define|#
directive|define
name|ARRAY_SIZE
value|0x100000000
end_define

begin_function
name|void
name|testIndexOverflow64
parameter_list|()
block|{
name|char
name|arr
index|[
name|ARRAY_SIZE
index|]
decl_stmt|;
name|char
modifier|*
name|ptr
init|=
name|arr
operator|+
name|UINT_MAX
operator|/
literal|2
decl_stmt|;
name|ptr
operator|+=
literal|2
expr_stmt|;
comment|// don't overflow 64-bit index
operator|*
name|ptr
operator|=
literal|42
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_define
define|#
directive|define
name|ULONG_MAX
value|(~0ul)
end_define

begin_define
define|#
directive|define
name|BIG_INDEX
value|(ULONG_MAX/16)
end_define

begin_function
name|void
name|testIndexTooBig64
parameter_list|()
block|{
name|char
name|arr
index|[
name|ULONG_MAX
operator|/
literal|8
operator|-
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|ptr
init|=
name|arr
operator|+
name|BIG_INDEX
decl_stmt|;
name|ptr
operator|+=
literal|2
expr_stmt|;
comment|// don't overflow 64-bit index
operator|*
name|ptr
operator|=
literal|42
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

