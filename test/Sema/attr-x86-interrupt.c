begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu  -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-linux-gnu  -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32  -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32  -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnux32  -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|a
name|test
name|__attribute__
argument_list|(
operator|(
name|interrupt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'interrupt' attribute only applies to non-K&R-style functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|int
name|foo1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error-re {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'void' return type}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error-re {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have only a pointer parameter optionally followed by an integer parameter}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo3
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|unsigned
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error-re {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have only a pointer parameter optionally followed by an integer parameter}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo4
parameter_list|(
name|int
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error-re {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a pointer as the first parameter}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_comment
comment|// expected-error-re@+6 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long' type as the second parameter}}
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_comment
comment|// expected-error-re@+4 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long long' type as the second parameter}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-error-re@+2 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned int' type as the second parameter}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo5
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_comment
comment|// expected-error-re@+6 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long' type as the second parameter}}
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_comment
comment|// expected-error-re@+4 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long long' type as the second parameter}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-error-re@+2 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned int' type as the second parameter}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo6
parameter_list|(
name|float
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_comment
comment|// expected-error-re@+4 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long' type as the second parameter}}
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_comment
comment|// expected-error-re@+2 {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'unsigned long long' type as the second parameter}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo7
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|unsigned
name|b
parameter_list|)
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo8
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|g
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|foo7
decl_stmt|;
name|g
argument_list|(
name|foo8
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ptr
expr_stmt|;
ifndef|#
directive|ifndef
name|__x86_64__
comment|// expected-error@+2 {{interrupt service routine cannot be called directly}}
endif|#
directive|endif
name|foo7
argument_list|(
operator|(
name|int
operator|*
operator|)
name|argv
argument_list|,
name|argc
argument_list|)
expr_stmt|;
name|foo8
argument_list|(
operator|(
name|int
operator|*
operator|)
name|argv
argument_list|)
expr_stmt|;
comment|// expected-error {{interrupt service routine cannot be called directly}}
return|return
literal|0
return|;
block|}
end_function

end_unit

