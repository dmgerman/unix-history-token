begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|c
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|a
parameter_list|(
name|struct
name|c
name|x
parameter_list|,
name|long
name|long
name|y
parameter_list|)
block|{
goto|goto *
name|x
goto|;
comment|// expected-error{{incompatible type}}
goto|goto *
name|y
goto|;
comment|// expected-warning{{incompatible integer to pointer conversion}}
block|}
end_function

end_unit

