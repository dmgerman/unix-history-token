begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|x
init|=
name|a
struct|;
end_struct

begin_comment
comment|// expected-error {{incompatible type initializing 'int', expected 'struct<anonymous>'}}
end_comment

end_unit

