begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
label|:
literal|24
expr_stmt|;
name|char
name|b
decl_stmt|;
block|}
name|S
typedef|;
end_typedef

begin_decl_stmt
name|S
name|a
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

end_unit

