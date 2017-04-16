begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-unknown -fsyntax-only -Wstrict-prototypes -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-unknown -fsyntax-only -Wstrict-prototypes -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// function declaration with unspecified params
end_comment

begin_function_decl
name|void
name|foo1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{this function declaration is not a prototype}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:11-[[@LINE-1]]:11}:"void"
end_comment

begin_comment
comment|// function declaration with 0 params
end_comment

begin_function_decl
name|void
name|foo2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// function definition with 0 params(for both cases),
end_comment

begin_comment
comment|// valid according to 6.7.5.3/14
end_comment

begin_function
name|void
name|foo1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|foo2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// function type typedef unspecified params
end_comment

begin_typedef
typedef|typedef
name|void
name|foo3
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// expected-warning {{this function declaration is not a prototype}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:19-[[@LINE-1]]:19}:"void"
end_comment

begin_comment
comment|// global fp unspecified params
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|foo4
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{this function declaration is not a prototype}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:14-[[@LINE-1]]:14}:"void"
end_comment

begin_comment
comment|// struct member fp unspecified params
end_comment

begin_struct
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|foo5
function_decl|)
parameter_list|()
function_decl|;
block|}
name|s
struct|;
end_struct

begin_comment
comment|// expected-warning {{this function declaration is not a prototype}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:23-[[@LINE-1]]:23}:"void"
end_comment

begin_comment
comment|// param fp unspecified params
end_comment

begin_function
name|void
name|bar2
parameter_list|(
name|void
function_decl|(
modifier|*
name|foo6
function_decl|)
parameter_list|()
parameter_list|)
block|{
comment|// expected-warning {{this function declaration is not a prototype}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:24-[[@LINE-1]]:24}:"void"
comment|// local fp unspecified params
name|void
function_decl|(
modifier|*
name|foo7
function_decl|)
parameter_list|()
init|=
literal|0
function_decl|;
comment|// expected-warning {{this function declaration is not a prototype}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:16-[[@LINE-1]]:16}:"void"
comment|// array fp unspecified params
name|void
function_decl|(
modifier|*
name|foo8
index|[
literal|2
index|]
function_decl|)
parameter_list|()
init|=
block|{
literal|0
block|}
function_decl|;
comment|// expected-warning {{this function declaration is not a prototype}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:19-[[@LINE-1]]:19}:"void"
block|}
end_function

begin_comment
comment|// function type cast using using an anonymous function declaration
end_comment

begin_function
name|void
name|bar3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// casting function w/out prototype to unspecified params function type
operator|(
name|void
operator|)
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|foo1
expr_stmt|;
comment|// expected-warning {{this function declaration is not a prototype}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:18-[[@LINE-1]]:18}:"void"
comment|// .. specified params
operator|(
name|void
operator|)
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|foo1
expr_stmt|;
block|}
end_function

begin_comment
comment|// K&R function definition not preceded by full prototype
end_comment

begin_function
name|int
name|foo9
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
comment|// expected-warning {{old-style function definition is not preceded by a prototype}}
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|// Function declaration with no types
end_comment

begin_function_decl
name|void
name|foo10
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{this function declaration is not a prototype}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:12-[[@LINE-1]]:12}:"void"
end_comment

begin_comment
comment|// K&R function definition with incomplete param list declared
end_comment

begin_function
name|void
name|foo10
parameter_list|(
name|p
parameter_list|,
name|p2
parameter_list|)
name|void
modifier|*
name|p
decl_stmt|;
block|{}
end_function

begin_comment
comment|// expected-warning {{old-style function definition is not preceded by a prototype}}
end_comment

begin_comment
comment|// K&R function definition with previous prototype declared is not diagnosed.
end_comment

begin_function_decl
name|void
name|foo11
parameter_list|(
name|int
name|p
parameter_list|,
name|int
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo11
parameter_list|(
name|p
parameter_list|,
name|p2
parameter_list|)
name|int
name|p
decl_stmt|;
name|int
name|p2
decl_stmt|;
block|{}
end_function

begin_comment
comment|// PR31020
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
name|foo12
argument_list|(
name|d
argument_list|)
comment|// expected-warning {{this old-style function definition is not preceded by a prototype}}
name|short
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{}
end_block

end_unit

