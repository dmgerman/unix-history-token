begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -mregparm 3 -emit-llvm %s -o - | FileCheck %s -check-prefix=HARD
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -mregparm 3 -mfloat-abi soft -emit-llvm %s -o - | FileCheck %s -check-prefix=SOFT
end_comment

begin_comment
comment|// HARD: define void @f1(float %a)
end_comment

begin_comment
comment|// SOFT: define void @f1(float inreg %a)
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|float
name|a
parameter_list|)
block|{}
end_function

end_unit

