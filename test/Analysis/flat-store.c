begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-store=flat -Wno-null-dereference -verify %s
end_comment

begin_define
define|#
directive|define
name|FAIL
value|((void)*(char*)0)
end_define

begin_struct
struct|struct
name|simple
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|PR7297
parameter_list|()
block|{
name|struct
name|simple
name|a
decl_stmt|;
name|struct
name|simple
modifier|*
name|p
init|=
operator|&
name|a
decl_stmt|;
name|p
operator|->
name|x
operator|=
literal|5
expr_stmt|;
if|if
condition|(
operator|!
name|p
index|[
literal|0
index|]
operator|.
name|x
condition|)
name|FAIL
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|.
name|x
condition|)
name|FAIL
expr_stmt|;
comment|// expected-warning {{null}}
block|}
end_function

end_unit

