begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic %s -DGNU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic -x c++ %s -DGNU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic %s -DC11 -D__thread=_Thread_local
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic -x c++ %s -DC11 -D__thread=_Thread_local
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic -x c++ %s -DCXX11 -D__thread=thread_local -std=c++11 -Wno-deprecated
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -Wno-private-extern -verify -pedantic -x c++ %s -DC11 -D__thread=_Thread_local -std=c++11 -Wno-deprecated
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// In C++, we define __private_extern__ to extern.
end_comment

begin_undef
undef|#
directive|undef
name|__private_extern__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__thread
name|int
name|t1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
specifier|extern
name|int
name|t2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
specifier|static
name|int
name|t3
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GNU
end_ifdef

begin_comment
comment|// expected-warning@-3 {{'__thread' before 'extern'}}
end_comment

begin_comment
comment|// expected-warning@-3 {{'__thread' before 'static'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__thread
name|__private_extern__
name|int
name|t4
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|t5
block|{
name|__thread
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// expected-error-re@-2 {{'{{__thread|_Thread_local|thread_local}}' is only allowed on variable declarations}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// FIXME: The 'is only allowed on variable declarations' diagnostic is better here.
end_comment

begin_comment
comment|// expected-error@-5 {{type name does not allow storage class to be specified}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__thread
name|int
name|t6
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GNU
argument_list|)
end_if

begin_comment
comment|// expected-error@-2 {{'__thread' is only allowed on variable declarations}}
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|C11
argument_list|)
end_elif

begin_comment
comment|// expected-error@-4 {{'_Thread_local' is only allowed on variable declarations}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-error@-6 {{'thread_local' is only allowed on variable declarations}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|f
parameter_list|(
name|__thread
name|int
name|t7
parameter_list|)
block|{
comment|// expected-error {{' is only allowed on variable declarations}}
name|__thread
name|int
name|t8
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|GNU
argument_list|)
comment|// expected-error@-2 {{'__thread' variables must have global storage}}
elif|#
directive|elif
name|defined
argument_list|(
name|C11
argument_list|)
comment|// expected-error@-4 {{'_Thread_local' variables must have global storage}}
endif|#
directive|endif
specifier|extern
name|__thread
name|int
name|t9
decl_stmt|;
specifier|static
name|__thread
name|int
name|t10
decl_stmt|;
name|__thread
name|__private_extern__
name|int
name|t11
decl_stmt|;
if|#
directive|if
name|__cplusplus
operator|<
literal|201103L
name|__thread
specifier|auto
name|int
name|t12a
decl_stmt|;
comment|// expected-error-re {{cannot combine with previous '{{__thread|_Thread_local}}' declaration specifier}}
specifier|auto
name|__thread
name|int
name|t12b
decl_stmt|;
comment|// expected-error {{cannot combine with previous 'auto' declaration specifier}}
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|CXX11
argument_list|)
name|__thread
specifier|auto
name|t12a
init|=
literal|0
decl_stmt|;
comment|// expected-error {{'_Thread_local' variables must have global storage}}
specifier|auto
name|__thread
name|t12b
init|=
literal|0
decl_stmt|;
comment|// expected-error {{'_Thread_local' variables must have global storage}}
endif|#
directive|endif
name|__thread
specifier|register
name|int
name|t13a
decl_stmt|;
comment|// expected-error-re {{cannot combine with previous '{{__thread|_Thread_local|thread_local}}' declaration specifier}}
specifier|register
name|__thread
name|int
name|t13b
decl_stmt|;
comment|// expected-error {{cannot combine with previous 'register' declaration specifier}}
block|}
end_function

begin_macro
name|__thread
end_macro

begin_typedef
typedef|typedef
name|int
name|t14
typedef|;
end_typedef

begin_comment
comment|// expected-error-re {{cannot combine with previous '{{__thread|_Thread_local|thread_local}}' declaration specifier}}
end_comment

begin_decl_stmt
name|__thread
name|int
name|t15
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|t15
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{non-thread-local declaration of 't15' follows thread-local declaration}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|t16
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
name|__thread
name|int
name|t16
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{thread-local declaration of 't16' follows non-thread-local declaration}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CXX11
end_ifdef

begin_decl_stmt
specifier|extern
name|thread_local
name|int
name|t17
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
specifier|_Thread_local
name|int
name|t17
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{thread-local declaration of 't17' with static initialization follows declaration with dynamic initialization}}
end_comment

begin_decl_stmt
specifier|extern
specifier|_Thread_local
name|int
name|t18
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
name|thread_local
name|int
name|t18
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{thread-local declaration of 't18' with dynamic initialization follows declaration with static initialization}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR13720
end_comment

begin_decl_stmt
name|__thread
name|int
name|thread_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|thread_int_ptr
init|=
operator|&
name|thread_int
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|// expected-error@-2 {{initializer element is not a compile-time constant}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|g
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
operator|&
name|thread_int
decl_stmt|;
comment|// This is perfectly fine, though.
block|}
end_function

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_decl_stmt
name|constexpr
name|int
modifier|*
name|thread_int_ptr_2
init|=
operator|&
name|thread_int
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{must be initialized by a constant expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|non_const
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|__thread
name|int
name|non_const_init
init|=
name|non_const
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|// expected-error@-2 {{initializer element is not a compile-time constant}}
end_comment

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|CXX11
argument_list|)
end_elif

begin_comment
comment|// expected-error@-4 {{initializer for thread-local variable must be a constant expression}}
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// expected-note@-6 {{use 'thread_local' to allow this}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|S
block|{
operator|~
name|S
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|__thread
name|S
name|s
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CXX11
argument_list|)
end_if

begin_comment
comment|// expected-error@-2 {{type of thread-local variable has non-trivial destruction}}
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// expected-note@-4 {{use 'thread_local' to allow this}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_struct
struct|struct
name|HasCtor
block|{
name|HasCtor
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|__thread
name|HasCtor
name|var_with_ctor
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CXX11
argument_list|)
end_if

begin_comment
comment|// expected-error@-2 {{initializer for thread-local variable must be a constant expression}}
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// expected-note@-4 {{use 'thread_local' to allow this}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__thread
name|int
name|aggregate
index|[
literal|10
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

