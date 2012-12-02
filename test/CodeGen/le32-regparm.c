begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple le32-unknown-nacl %s -emit-llvm -o - | FileCheck %s
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

begin_comment
comment|// 2 inreg arguments are supported.
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
comment|// CHECK: define void @f1(i32 inreg %i, i32 inreg %j, i32 %k)
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

begin_comment
comment|// inreg structs are not supported.
end_comment

begin_comment
comment|// CHECK: define void @f2(%struct.foo* inreg %a)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|f2
argument_list|(
name|foo
operator|*
name|a
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// Only the first 2 arguments can be passed inreg, and the first
end_comment

begin_comment
comment|// non-integral type consumes remaining available registers.
end_comment

begin_comment
comment|// CHECK: define void @f3(%struct.foo* byval %a, i32 %b)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
name|f3
argument_list|(
name|foo
name|a
argument_list|,
name|int
name|b
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// Only 64 total bits are supported
end_comment

begin_comment
comment|// CHECK: define void @f4(i64 inreg %g, i32 %h)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
name|f4
argument_list|(
name|long
name|long
name|g
argument_list|,
name|int
name|h
argument_list|)
block|{}
end_decl_stmt

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
function_decl|2
typedef|)));
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

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
comment|// The presence of double c means that foo* d is not passed inreg. This
comment|// behavior is different from current x86-32 behavior
comment|// CHECK: call void @reduced(i8 signext inreg 0, {{.*}} %struct.foo* null
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
comment|// CHECK: call void {{.*}}(i32 inreg 1, i32 inreg 2)
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

