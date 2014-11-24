begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 %s -fsyntax-only -Wignored-qualifiers -Wno-error=return-type -verify -fblocks -Wno-unreachable-code -Wno-unused-value
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

begin_comment
comment|// Include these declarations here explicitly so we don't depend on system headers.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__jmp_buf_tag
block|{}
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|longjmp
parameter_list|(
name|struct
name|__jmp_buf_tag
name|__env
index|[
literal|1
index|]
parameter_list|,
name|int
name|__val
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|_longjmp
parameter_list|(
name|struct
name|__jmp_buf_tag
name|__env
index|[
literal|1
index|]
parameter_list|,
name|int
name|__val
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

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
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|longjmp
argument_list|(
name|test30_j
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
name|_longjmp
argument_list|(
name|test30_j
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
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

begin_comment
comment|// Test that 'static inline' functions are only analyzed for CFG-based warnings
end_comment

begin_comment
comment|// when they are used.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|si_has_missing_return
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{control reaches end of non-void function}}
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|si_has_missing_return_2
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{control reaches end of non-void function}}
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|si_forward
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|si_has_missing_return_3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
condition|)
return|return
name|si_has_missing_return_3
argument_list|(
name|x
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// expected-warning{{control may reach end of non-void function}}
end_comment

begin_function
name|int
name|test_static_inline
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|si_forward
argument_list|()
expr_stmt|;
return|return
name|x
condition|?
name|si_has_missing_return_2
argument_list|()
else|:
name|si_has_missing_return_3
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|si_forward
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{control reaches end of non-void function}}
end_comment

begin_comment
comment|// Test warnings on ignored qualifiers on return types.
end_comment

begin_function_decl
specifier|const
name|int
name|ignored_c_quals
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'const' type qualifier on return type has no effect}}
end_comment

begin_function_decl
specifier|const
specifier|volatile
name|int
name|ignored_cv_quals
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'const volatile' type qualifiers on return type have no effect}}
end_comment

begin_function_decl
name|char
modifier|*
specifier|const
specifier|volatile
specifier|restrict
name|ignored_cvr_quals
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'const volatile restrict' type qualifiers on return type have no effect}}
end_comment

begin_typedef
typedef|typedef
specifier|const
name|int
name|CI
typedef|;
end_typedef

begin_function_decl
name|CI
name|ignored_quals_typedef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|CI
name|ignored_quals_typedef_2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{'const' type qualifier}}
end_comment

begin_comment
comment|// Test that for switch(enum) that if the switch statement covers all the cases
end_comment

begin_comment
comment|// that we don't consider that for -Wreturn-type.
end_comment

begin_enum
enum|enum
name|Cases
block|{
name|C1
block|,
name|C2
block|,
name|C3
block|,
name|C4
block|}
enum|;
end_enum

begin_function
name|int
name|test_enum_cases
parameter_list|(
name|enum
name|Cases
name|C
parameter_list|)
block|{
switch|switch
condition|(
name|C
condition|)
block|{
case|case
name|C1
case|:
return|return
literal|1
return|;
case|case
name|C2
case|:
return|return
literal|2
return|;
case|case
name|C4
case|:
return|return
literal|3
return|;
case|case
name|C3
case|:
return|return
literal|4
return|;
block|}
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_comment
comment|// PR12318 - Don't give a may reach end of non-void function warning.
end_comment

begin_function
name|int
name|test34
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|==
literal|1
condition|)
block|{
return|return
literal|3
return|;
block|}
elseif|else
if|if
condition|(
name|x
operator|==
literal|2
operator|||
literal|1
condition|)
block|{
return|return
literal|5
return|;
block|}
block|}
end_function

begin_comment
comment|// PR18999
end_comment

begin_function
name|int
name|test35
parameter_list|()
block|{
name|lbl
label|:
if|if
condition|(
literal|1
condition|)
goto|goto
name|lbl
goto|;
block|}
end_function

begin_comment
comment|// PR19074.
end_comment

begin_function_decl
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|av_assert0
parameter_list|(
name|cond
parameter_list|)
value|do {\     if (!(cond)) {\       abort();\     }\   } while (0)
end_define

begin_function
name|int
name|PR19074
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|0
return|;
default|default:
name|av_assert0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|// no-warning
block|}
end_function

begin_function
name|int
name|PR19074_positive
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|0
return|;
default|default:
break|break;
block|}
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

begin_comment
comment|// sizeof(long) test.
end_comment

begin_function
name|int
name|sizeof_long
parameter_list|()
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
literal|4
condition|)
return|return
literal|1
return|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
literal|8
condition|)
return|return
literal|2
return|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

end_unit

