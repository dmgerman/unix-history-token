begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify  */
end_comment

begin_struct
specifier|extern
struct|struct
block|{
name|int
name|a
decl_stmt|;
block|}
name|x
struct|;
end_struct

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_struct
specifier|extern
struct|struct
block|{
name|int
name|a
decl_stmt|;
block|}
name|x
struct|;
end_struct

begin_comment
comment|// expected-error {{redefinition of 'x'}}
end_comment

begin_struct_decl
struct_decl|struct
name|x
struct_decl|;
end_struct_decl

begin_function
name|int
name|a
parameter_list|(
name|struct
name|x
modifier|*
name|b
parameter_list|)
block|{
comment|// Per C99 6.7.2.3, since the outer and inner "struct x"es have different
comment|// scopes, they don't refer to the same type, and are therefore incompatible
struct|struct
name|x
block|{
name|int
name|a
decl_stmt|;
block|}
modifier|*
name|c
init|=
name|b
struct|;
comment|// expected-warning {{incompatible pointer types}}
block|}
end_function

begin_struct
struct|struct
name|x
block|{
name|int
name|a
decl_stmt|;
block|}
name|r
struct|;
end_struct

begin_function
name|int
name|b
parameter_list|()
block|{
struct|struct
name|x
block|{
name|char
name|x
decl_stmt|;
block|}
name|s
init|=
name|r
struct|;
comment|// expected-error {{incompatible type initializing}}
block|}
end_function

end_unit

