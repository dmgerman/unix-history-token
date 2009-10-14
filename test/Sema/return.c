begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify -fblocks
end_comment

begin_comment
comment|// clang emits the following warning by default.
end_comment

begin_comment
comment|// With GCC, -pedantic, -Wreturn-type or -Wall are required to produce the
end_comment

begin_comment
comment|// following warning.
end_comment

begin_function
name|int
name|t14
parameter_list|()
block|{
return|return;
comment|// expected-warning {{non-void function 't14' should return a value}}
block|}
end_function

begin_function
name|void
name|t15
parameter_list|()
block|{
return|return
literal|1
return|;
comment|// expected-warning {{void function 't15' should not return a value}}
block|}
end_function

begin_function_decl
name|int
name|unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test0
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|test1
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
name|a
label|:
goto|goto
name|a
goto|;
block|}
end_function

begin_function
name|int
name|test3
parameter_list|()
block|{
goto|goto
name|a
goto|;
name|a
label|:
empty_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|void
name|halt
parameter_list|()
block|{
name|a
label|:
goto|goto
name|a
goto|;
block|}
end_function

begin_function_decl
name|void
name|halt2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|test4
parameter_list|()
block|{
name|halt2
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|()
block|{
name|halt2
argument_list|()
operator|,
operator|(
name|void
operator|)
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test6
parameter_list|()
block|{
literal|1
operator|,
name|halt2
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|unknown_nohalt
parameter_list|()
block|{
return|return
name|j
return|;
block|}
end_function

begin_function
name|int
name|test7
parameter_list|()
block|{
name|unknown
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test8
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
literal|1
operator|+
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function_decl
name|int
name|halt3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|test9
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|halt3
argument_list|()
operator|+
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test10
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|unknown
argument_list|()
operator|||
name|halt3
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test11
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|unknown
argument_list|()
operator|&&
name|halt3
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test12
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|halt3
argument_list|()
operator|||
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test13
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|halt3
argument_list|()
operator|&&
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test14
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
literal|1
operator|||
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test15
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
literal|0
operator|||
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test16
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
literal|0
operator|&&
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test17
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
literal|1
operator|&&
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test18
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|unknown_nohalt
argument_list|()
operator|&&
name|halt3
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test19
parameter_list|()
block|{
call|(
name|void
call|)
argument_list|(
name|unknown_nohalt
argument_list|()
operator|&&
name|unknown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test20
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
literal|0
condition|)
return|return
literal|2
return|;
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test21
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
literal|1
condition|)
return|return
literal|2
return|;
block|}
end_function

begin_function
name|int
name|test22
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
default|default:
empty_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_function
name|int
name|test23
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|0
return|;
case|case
literal|2
case|:
return|return
literal|2
return|;
block|}
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test24
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|0
return|;
case|case
literal|2
case|:
return|return
literal|2
return|;
default|default:
return|return
operator|-
literal|1
return|;
block|}
block|}
end_function

begin_function
name|int
name|test25
parameter_list|()
block|{
literal|1
condition|?
name|halt3
argument_list|()
else|:
name|unknown
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test26
parameter_list|()
block|{
literal|0
condition|?
name|halt3
argument_list|()
else|:
name|unknown
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|test27
parameter_list|()
block|{
switch|switch
condition|(
name|j
condition|)
block|{
case|case
literal|1
case|:
do|do
block|{ }
do|while
condition|(
literal|1
condition|)
do|;
break|break;
case|case
literal|2
case|:
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
break|break;
case|case
literal|3
case|:
for|for
control|(
init|;
literal|1
condition|;
control|)
empty_stmt|;
for|for
control|(
init|;
literal|0
condition|;
control|)
block|{
goto|goto
name|done
goto|;
block|}
return|return
literal|1
return|;
case|case
literal|4
case|:
while|while
condition|(
literal|0
condition|)
block|{
goto|goto
name|done
goto|;
block|}
return|return
literal|1
return|;
case|case
literal|5
case|:
while|while
condition|(
literal|1
condition|)
block|{
return|return
literal|1
return|;
block|}
break|break;
case|case
literal|6
case|:
name|fptr
argument_list|()
expr_stmt|;
break|break;
default|default:
return|return
literal|1
return|;
block|}
name|done
label|:
empty_stmt|;
block|}
end_function

begin_comment
comment|// PR4624
end_comment

begin_function_decl
name|void
name|test28
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test28
parameter_list|(
name|x
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

begin_function_decl
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test29
parameter_list|()
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|test30_j
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test30
parameter_list|()
block|{
if|if
condition|(
name|j
condition|)
name|longjmp
argument_list|(
name|test30_j
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|_longjmp
argument_list|(
name|test30_j
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
name|test31_t
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|void
name|test31
argument_list|(
name|test31_t
operator|*
name|callback
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test32
parameter_list|()
block|{
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
argument_list|()
expr_stmt|;
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|j
condition|)
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
argument_list|()
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

begin_function
name|void
name|test33
parameter_list|()
block|{
if|if
condition|(
name|j
condition|)
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

end_unit

