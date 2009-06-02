begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_decl_stmt
name|int
name|check_wchar_size
index|[
sizeof|sizeof
argument_list|(
operator|*
literal|L""
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|t1
index|[]
init|=
literal|L"x"
decl_stmt|;
name|wchar_t
name|tab
index|[]
init|=
literal|L"x"
decl_stmt|;
name|int
name|t2
index|[]
init|=
literal|"x"
decl_stmt|;
comment|// expected-error {{initialization}}
name|char
name|t3
index|[]
init|=
literal|L"x"
decl_stmt|;
comment|// expected-error {{initialization}}
block|}
end_function

end_unit

