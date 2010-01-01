begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/struct.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/struct.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|struct
name|Point
modifier|*
name|p1
decl_stmt|;
end_decl_stmt

begin_function
name|float
name|getX
parameter_list|(
name|struct
name|Point
modifier|*
name|p1
parameter_list|)
block|{
return|return
name|p1
operator|->
name|x
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|get_fun_ptr
parameter_list|()
block|{
return|return
name|fun
operator|->
name|is_ptr
condition|?
name|fun
operator|->
name|ptr
else|:
literal|0
return|;
block|}
end_function

begin_struct
struct|struct
name|Fun2
block|{
name|int
name|very_fun
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|get_very_fun
parameter_list|()
block|{
return|return
name|fun2
operator|->
name|very_fun
return|;
block|}
end_function

begin_decl_stmt
name|int
modifier|*
name|int_ptr_fail
init|=
operator|&
name|fun
operator|->
name|is_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{address of bit-field requested}}
end_comment

begin_decl_stmt
name|struct
name|Nested
name|nested
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

end_unit

