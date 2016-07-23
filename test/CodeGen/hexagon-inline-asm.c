begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple hexagon-unknown-elf -target-feature +hvx -emit-llvm -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|v64
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)))
name|__attribute__
typedef|((
name|aligned
typedef|(64)));
end_typedef

begin_decl_stmt
name|int
name|g
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|v64
name|v0
parameter_list|,
name|v64
name|v1
parameter_list|,
name|v64
modifier|*
name|p
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|v64
name|q0
decl_stmt|;
asm|asm ("%0 = vgtw(%1.w,%2.w)" : "=q"(q0) : "v"(v0), "v"(v1));
comment|// CHECK: call<16 x i32> asm "$0 = vgtw($1.w,$2.w)", "=q,v,v"(<16 x i32>{{.*}},<16 x i32>{{.*}})
operator|*
name|p
operator|=
name|q0
expr_stmt|;
asm|asm ("%0 = memw(##%1)" : "=r"(r) : "s"(&g));
comment|// CHECK: call i32 asm "$0 = memw(##$1)", "=r,s"(i32* @g)
block|}
end_function

end_unit

