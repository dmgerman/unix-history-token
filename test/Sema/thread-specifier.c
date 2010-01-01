begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -fsyntax-only -verify %s
end_comment

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

begin_comment
comment|// expected-error {{type name does not allow storage class to be specified}}
end_comment

begin_function_decl
name|__thread
name|int
name|t6
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'__thread' is only allowed on variable declarations}}
end_comment

begin_function
name|int
name|f
parameter_list|(
name|__thread
name|int
name|t7
parameter_list|)
block|{
comment|// expected-error {{'__thread' is only allowed on variable declarations}}
name|__thread
name|int
name|t8
decl_stmt|;
comment|// expected-error {{'__thread' variables must have global storage}}
name|__thread
specifier|extern
name|int
name|t9
decl_stmt|;
name|__thread
specifier|static
name|int
name|t10
decl_stmt|;
name|__thread
name|__private_extern__
name|int
name|t11
decl_stmt|;
name|__thread
specifier|auto
name|int
name|t12
decl_stmt|;
comment|// expected-error {{'__thread' variables must have global storage}}
name|__thread
specifier|register
name|int
name|t13
decl_stmt|;
comment|// expected-error {{'__thread' variables must have global storage}}
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
comment|// expected-error {{'__thread' is only allowed on variable declarations}}
end_comment

begin_decl_stmt
name|__thread
name|int
name|t15
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{[previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|t15
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{non-thread-local declaration of 't15' follows thread-local declaration}}
end_comment

begin_decl_stmt
name|int
name|t16
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{[previous definition is here}}
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

end_unit

