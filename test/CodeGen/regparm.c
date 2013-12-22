begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|FASTCALL
value|__attribute__((regparm(2)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|aaa
decl_stmt|;
name|double
name|bbbb
decl_stmt|;
name|int
name|ccc
index|[
literal|200
index|]
decl_stmt|;
block|}
name|foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|FType
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(regparm
parameter_list|(
function_decl|3
typedef|)
operator|,
name|stdcall
typedef|));
end_typedef

begin_decl_stmt
name|FType
name|bar
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|FASTCALL
name|reduced
parameter_list|(
name|char
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|foo
modifier|*
name|d
parameter_list|,
name|double
name|e
parameter_list|,
name|int
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// PR7025
end_comment

begin_function_decl
name|void
name|FASTCALL
name|f1
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @f1(i32 inreg %i, i32 inreg %j, i32 %k)
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
name|k
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @reduced(i8 inreg signext 0, {{.*}} %struct.foo* inreg null
name|reduced
argument_list|(
literal|0
argument_list|,
literal|0.0
argument_list|,
literal|0
argument_list|,
literal|0.0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_stdcallcc void {{.*}}(i32 inreg 1, i32 inreg 2)
name|bar
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

