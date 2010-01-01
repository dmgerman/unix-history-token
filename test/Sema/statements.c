begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__byte_swap_int_var
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__ ({ register __uint32_t __X = (x); \    __asm ("bswap %0" : "+r" (__X)); \    __X; })
end_define

begin_function
name|int
name|test
parameter_list|(
name|int
name|_x
parameter_list|)
block|{
return|return
operator|(
name|__byte_swap_int_var
argument_list|(
name|_x
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|// PR2374
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
return|return
operator|(
block|{
name|L
operator|:
literal|5
block|;}
operator|)
return|;
block|}
end_function

begin_function
name|int
name|test3
parameter_list|()
block|{
return|return
operator|(
block|{
block|{
literal|5
block|;}
block|}
operator|)
return|;
block|}
end_function

begin_comment
comment|// expected-error {{incompatible type returning 'void', expected 'int'}}\
end_comment

begin_comment
comment|// expected-warning {{expression result unused}}
end_comment

begin_function
name|int
name|test4
parameter_list|()
block|{
return|return
operator|(
block|{
operator|(
block|{
literal|5
block|;}
operator|)
block|; }
operator|)
return|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|()
block|{
return|return
operator|(
block|{
name|L1
operator|:
name|L2
operator|:
name|L3
operator|:
literal|5
block|;}
operator|)
return|;
block|}
end_function

begin_function
name|int
name|test6
parameter_list|()
block|{
return|return
operator|(
block|{
literal|5
block|;}
operator|)
return|;
block|}
end_function

begin_function
name|void
name|test7
parameter_list|()
block|{
operator|(
block|{
literal|5
block|;}
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{expression result unused}}
end_comment

begin_comment
comment|// PR3062
end_comment

begin_expr_stmt
name|int
name|test8
index|[
operator|(
block|{
literal|10
expr|;
end_expr_stmt

begin_empty_stmt
unit|})]
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{statement expression not allowed at file scope}}
end_comment

begin_comment
comment|// PR3912
end_comment

begin_function
name|void
name|test9
parameter_list|(
specifier|const
name|void
modifier|*
name|P
parameter_list|)
block|{
name|__builtin_prefetch
argument_list|(
name|P
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|test10
parameter_list|()
block|{
name|bar
label|:
return|return
operator|&&
name|bar
return|;
comment|// expected-warning {{returning address of label, which is local}}
block|}
end_function

end_unit

