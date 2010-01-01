begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -pedantic
end_comment

begin_decl_stmt
name|int
name|X
index|[]
init|=
block|{
index|[
literal|4
index|]
literal|4
block|,
comment|// expected-warning {{use of GNU 'missing =' extension in designator}}
index|[
literal|5
index|]
operator|=
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|foo
block|{
name|int
name|arr
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
name|Y
index|[
literal|10
index|]
init|=
block|{
index|[
literal|4
index|]
operator|.
name|arr
index|[
literal|2
index|]
operator|=
literal|4
block|,
comment|// This is not the GNU array init designator extension.
index|[
literal|4
index|]
operator|.
name|arr
index|[
literal|2
index|]
literal|4
comment|// expected-error {{expected '=' or another designator}}
block|}
decl_stmt|;
end_decl_stmt

end_unit

