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
literal|0xFFFFFF
argument|))
argument_list|)
name|int
modifier|*
name|_boundsB
decl_stmt|;
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
comment|// expected-error {{illegal implicit cast between two pointers with different address spaces}} \
name|expected
operator|-
name|warning
block|{
block|{
name|returning
literal|'void __attribute__((address_space(256))) *'
name|discards
name|qualifiers
block|,
name|expected
literal|'void *'
block|}
block|}
block|}
end_function

end_unit

