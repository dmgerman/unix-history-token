begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -mrecip=!sqrtf,vec-divf:3 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|baz
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|4
return|;
block|}
end_function

begin_comment
comment|// CHECK: baz{{.*}} #0
end_comment

begin_comment
comment|// CHECK: #0 = {{.*}}"reciprocal-estimates"="!sqrtf,vec-divf:3"
end_comment

end_unit

