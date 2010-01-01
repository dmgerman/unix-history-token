begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_struct_decl
struct_decl|struct
name|s
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 2 {{forward declaration of 'struct s'}}
end_comment

begin_function
name|struct
name|s
modifier|*
name|t
parameter_list|(
name|struct
name|s
name|z
index|[]
parameter_list|)
block|{
comment|// expected-error {{array has incomplete element type}}
return|return
name|z
return|;
block|}
end_function

begin_function
name|void
name|ff
parameter_list|()
block|{
name|struct
name|s
name|v
decl_stmt|,
modifier|*
name|p
decl_stmt|;
comment|// expected-error {{variable has incomplete type 'struct s'}}
name|p
operator|=
operator|&
name|v
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|k
parameter_list|(
name|void
name|l
index|[
literal|2
index|]
parameter_list|)
block|{
comment|// expected-error {{array has incomplete element type}}
return|return
name|l
return|;
block|}
end_function

begin_struct
struct|struct
name|vari
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|vari
modifier|*
name|func
parameter_list|(
name|struct
name|vari
name|a
index|[]
parameter_list|)
block|{
comment|// expected-warning {{'struct vari' may not be used as an array element due to flexible array member}}
return|return
name|a
return|;
block|}
end_function

begin_function_decl
name|int
name|foo
function_decl|[]
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'foo' declared as array of functions}}
end_comment

begin_function_decl
name|int
name|foo2
function_decl|[1]
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'foo2' declared as array of functions}}
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|pfunc
name|xx
argument_list|(
name|int
name|f
index|[]
operator|(
name|void
operator|)
argument_list|)
block|{
comment|// expected-error {{'f' declared as array of functions}}
return|return
name|f
return|;
block|}
end_decl_stmt

begin_function
name|void
name|check_size
parameter_list|()
block|{
name|float
name|f
decl_stmt|;
name|int
name|size_not_int
index|[
name|f
index|]
decl_stmt|;
comment|// expected-error {{size of array has non-integer type 'float'}}
name|int
name|negative_size
index|[
literal|1
operator|-
literal|2
index|]
decl_stmt|;
comment|// expected-error{{array size is negative}}
name|int
name|zero_size
index|[
literal|0
index|]
decl_stmt|;
comment|// expected-warning{{zero size arrays are an extension}}
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|I
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|TA
index|[
name|I
index|]
typedef|;
end_typedef

begin_comment
comment|// expected-error {{variable length array declaration not allowed at file scope}}
end_comment

begin_function_decl
name|void
name|strFunc
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|char
name|staticAry
index|[]
init|=
literal|"test"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|checkStaticAry
parameter_list|()
block|{
name|strFunc
argument_list|(
name|staticAry
argument_list|)
expr_stmt|;
comment|// expected-warning{{passing 'char const [5]' discards qualifiers, expected 'char *'}}
block|}
end_function

end_unit

