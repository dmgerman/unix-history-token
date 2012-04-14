begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -ccc-clang-archs mips64el -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|long
name|double
name|LD
typedef|;
end_typedef

begin_comment
comment|// CHECK: ret fp128
end_comment

begin_function
name|LD
name|foo0
parameter_list|()
block|{
return|return
literal|2.625L
return|;
block|}
end_function

end_unit

