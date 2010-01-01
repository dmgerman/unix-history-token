begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|X
block|{
comment|// expected-note{{previous definition is here}}
struct|struct
name|X
block|{ }
name|x
struct|;
comment|// expected-error{{nested redefinition of 'X'}} \
comment|// expected-error{{field has incomplete type}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{ }
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
name|Y
block|{ }
struct|;
comment|// okay: this is a different Y
block|}
end_function

begin_struct_decl
struct_decl|struct
name|T
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|Z
block|{
struct|struct
name|T
block|{
name|int
name|x
decl_stmt|;
block|}
name|t
struct|;
struct|struct
name|U
block|{
name|int
name|x
decl_stmt|;
block|}
name|u
struct|;
block|}
struct|;
end_struct

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|T
name|t
decl_stmt|;
name|struct
name|U
name|u
decl_stmt|;
block|}
end_function

end_unit

