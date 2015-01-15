begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -O3 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s -check-prefix=N64
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|f
index|[
literal|3
index|]
decl_stmt|;
block|}
name|S0
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|foo2
parameter_list|(
name|S0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// O32-LABEL: define void @foo1(i32 inreg %a0.coerce0, i32 inreg %a0.coerce1, i32 inreg %a0.coerce2)
end_comment

begin_comment
comment|// N64-LABEL: define void @foo1(i64 inreg %a0.coerce0, i32 inreg %a0.coerce1)
end_comment

begin_function
name|void
name|foo1
parameter_list|(
name|S0
name|a0
parameter_list|)
block|{
name|foo2
argument_list|(
name|a0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

