begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wmissing-braces -verify %s
end_comment

begin_decl_stmt
name|int
name|a
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{suggest braces}} expected-warning{{suggest braces}}
end_comment

end_unit

