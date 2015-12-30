begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -debug-info-kind=line-tables-only -fexceptions -fcxx-exceptions -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK: icmp {{.*}}, !dbg [[DBG_F1:!.*]]
line|#
directive|line
number|100
return|return
name|a
comment|//
operator|&&
comment|//
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK: [[DBG_F1]] = !DILocation(line: 100,
end_comment

end_unit

