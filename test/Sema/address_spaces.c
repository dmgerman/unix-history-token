begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_define
define|#
directive|define
name|_AS1
value|__attribute__((address_space(1)))
end_define

begin_define
define|#
directive|define
name|_AS2
value|__attribute__((address_space(2)))
end_define

begin_define
define|#
directive|define
name|_AS3
value|__attribute__((address_space(3)))
end_define

begin_function_decl
name|void
name|bar
parameter_list|(
name|_AS2
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{parameter may not be qualified with an address space}}
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|_AS3
name|float
modifier|*
name|a
parameter_list|,
name|_AS1
name|float
name|b
parameter_list|)
comment|// expected-error {{parameter may not be qualified with an address space}}
block|{
name|_AS2
modifier|*
name|x
decl_stmt|;
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
name|_AS1
name|float
modifier|*
name|_AS2
modifier|*
name|B
decl_stmt|;
name|int
name|_AS1
name|_AS2
modifier|*
name|Y
decl_stmt|;
comment|// expected-error {{multiple address spaces specified for type}}
name|int
modifier|*
name|_AS1
name|_AS2
modifier|*
name|Z
decl_stmt|;
comment|// expected-error {{multiple address spaces specified for type}}
name|_AS1
name|int
name|local
decl_stmt|;
comment|// expected-error {{automatic variable qualified with an address space}}
name|_AS1
name|int
name|array
index|[
literal|5
index|]
decl_stmt|;
comment|// expected-error {{automatic variable qualified with an address space}}
name|_AS1
name|int
name|arrarr
index|[
literal|5
index|]
index|[
literal|5
index|]
decl_stmt|;
comment|// expected-error {{automatic variable qualified with an address space}}
name|__attribute__
argument_list|(
argument|(address_space(-
literal|1
argument|))
argument_list|)
name|int
modifier|*
name|_boundsA
decl_stmt|;
comment|// expected-error {{address space is negative}}
name|__attribute__
argument_list|(
argument|(address_space(
literal|0x7FFFFF
argument|))
argument_list|)
name|int
modifier|*
name|_boundsB
decl_stmt|;
comment|// expected-error {{address space is larger than the maximum supported}}
name|__attribute__
argument_list|(
argument|(address_space(
literal|0x1000000
argument|))
argument_list|)
name|int
modifier|*
name|_boundsC
decl_stmt|;
comment|// expected-error {{address space is larger than the maximum supported}}
comment|// chosen specifically to overflow 32 bits and come out reasonable
name|__attribute__
argument_list|(
argument|(address_space(
literal|4294967500
argument|))
argument_list|)
name|int
modifier|*
name|_boundsD
decl_stmt|;
comment|// expected-error {{address space is larger than the maximum supported}}
operator|*
name|a
operator|=
literal|5.0f
operator|+
name|b
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|_st
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|s
name|__attribute
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|1
block|,
literal|1
block|}
struct|;
end_struct

begin_comment
comment|// rdar://6774906
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|256
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
modifier|*
specifier|const
name|base
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|get_0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|base
index|[
literal|0
index|]
return|;
comment|// expected-error {{returning '__attribute__((address_space(256))) void *' from a function with result type 'void *' changes address space of pointer}}
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|test3_array
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|void
name|test3_helper
argument_list|(
name|char
operator|*
name|p
argument_list|)
decl_stmt|;
comment|// expected-note {{passing argument to parameter 'p' here}}
name|test3_helper
argument_list|(
name|test3_array
argument_list|)
expr_stmt|;
comment|// expected-error {{changes address space of pointer}}
block|}
end_function

begin_typedef
typedef|typedef
name|void
name|ft
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|_AS1
name|ft
name|qf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{function type may not be qualified with an address space}}
end_comment

begin_typedef
typedef|typedef
name|_AS1
name|ft
name|qft
typedef|;
end_typedef

begin_comment
comment|// expected-error {{function type may not be qualified with an address space}}
end_comment

begin_typedef
typedef|typedef
name|_AS2
name|int
name|AS2Int
typedef|;
end_typedef

begin_struct
struct|struct
name|HasASFields
block|{
name|_AS2
name|int
name|as_field
decl_stmt|;
comment|// expected-error {{field may not be qualified with an address space}}
name|AS2Int
name|typedef_as_field
decl_stmt|;
comment|// expected-error {{field may not be qualified with an address space}}
block|}
struct|;
end_struct

begin_comment
comment|// Assertion failure was when the field was accessed
end_comment

begin_function
name|void
name|access_as_field
parameter_list|()
block|{
name|struct
name|HasASFields
name|x
decl_stmt|;
operator|(
name|void
operator|)
name|bar
operator|.
name|as_field
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|PR4997
name|__attribute__
typedef|((
name|address_space
typedef|(
name|Foobar
typedef|)));
end_typedef

begin_comment
comment|// expected-error {{use of undeclared identifier 'Foobar'}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(address_space(
literal|"12"
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'address_space' attribute requires an integer constant}}
end_comment

begin_comment
comment|// Clang extension doesn't forbid operations on pointers to different address spaces.
end_comment

begin_function
name|char
modifier|*
name|cmp
parameter_list|(
name|_AS1
name|char
modifier|*
name|x
parameter_list|,
name|_AS2
name|char
modifier|*
name|y
parameter_list|)
block|{
return|return
name|x
operator|<
name|y
condition|?
name|x
else|:
name|y
return|;
comment|// expected-warning {{pointer type mismatch ('__attribute__((address_space(1))) char *' and '__attribute__((address_space(2))) char *')}}
block|}
end_function

end_unit

