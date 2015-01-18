begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -g -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - %s | FileCheck %s --check-prefix=NO_DEBUG
end_comment

begin_function
name|int
name|main
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
comment|// CHECK:  i32 2, !"Debug Info Version", i32 2}
end_comment

begin_comment
comment|// NO_DEBUG-NOT: !"Debug Info Version"
end_comment

end_unit

