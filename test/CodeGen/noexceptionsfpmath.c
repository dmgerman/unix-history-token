begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -fno-trapping-math %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: main
end_comment

begin_comment
comment|// CHECK: attributes #0 = {{.*}}"no-trapping-math"="true"{{.*}}
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

