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
comment|// expected-error {{returning 'void' from a function with incompatible result type 'int'}}\
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

begin_comment
comment|// PR6034
end_comment

begin_function
name|void
name|test11
parameter_list|(
name|int
name|bit
parameter_list|)
block|{
switch|switch
condition|(
name|bit
condition|)
switch|switch
condition|(
name|env
operator|->
name|fpscr
condition|)
comment|// expected-error {{use of undeclared identifier 'env'}}
block|{   }
block|}
end_function

begin_comment
comment|// rdar://3271964
end_comment

begin_enum
enum|enum
name|Numbers
block|{
name|kOne
block|,
name|kTwo
block|,
name|kThree
block|,
name|kFour
block|}
enum|;
end_enum

begin_function
name|int
name|test12
parameter_list|(
name|enum
name|Numbers
name|num
parameter_list|)
block|{
switch|switch
condition|(
name|num
operator|==
name|kOne
condition|)
block|{
comment|// expected-warning {{switch condition has boolean value}}
default|default:
case|case
name|kThree
case|:
break|break;
block|}
block|}
end_function

begin_enum
enum|enum
name|x
block|{
name|a
block|,
name|b
block|,
name|c
block|,
name|d
block|,
name|e
block|,
name|f
block|,
name|g
block|}
enum|;
end_enum

begin_function
name|void
name|foo
parameter_list|(
name|enum
name|x
name|X
parameter_list|)
block|{
switch|switch
condition|(
name|X
condition|)
block|{
comment|// expected-warning {{enumeration value 'g' not handled in switch}}
case|case
name|a
case|:
case|case
name|b
case|:
case|case
name|c
case|:
case|case
name|d
case|:
case|case
name|e
case|:
case|case
name|f
case|:
break|break;
block|}
switch|switch
condition|(
name|X
condition|)
block|{
comment|// expected-warning {{enumeration values 'f' and 'g' not handled in switch}}
case|case
name|a
case|:
case|case
name|b
case|:
case|case
name|c
case|:
case|case
name|d
case|:
case|case
name|e
case|:
break|break;
block|}
switch|switch
condition|(
name|X
condition|)
block|{
comment|// expected-warning {{enumeration values 'e', 'f', and 'g' not handled in switch}}
case|case
name|a
case|:
case|case
name|b
case|:
case|case
name|c
case|:
case|case
name|d
case|:
break|break;
block|}
switch|switch
condition|(
name|X
condition|)
block|{
comment|// expected-warning {{5 enumeration values not handled in switch: 'c', 'd', 'e'...}}
case|case
name|a
case|:
case|case
name|b
case|:
break|break;
block|}
block|}
end_function

begin_function
name|int
name|test_pr8880
parameter_list|()
block|{
name|int
name|first
init|=
literal|1
decl_stmt|;
for|for
control|(
init|;
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
literal|0
expr|;
control|}
block|)
function|;
end_function

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
literal|1
return|;
end_return

unit|}
end_unit

