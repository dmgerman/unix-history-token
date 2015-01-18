begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -g -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|func
parameter_list|(
name|char
name|c
parameter_list|,
name|char
modifier|*
name|d
parameter_list|)
block|{
operator|*
name|d
operator|=
name|c
operator|+
literal|1
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|// CHECK: ret void, !dbg [[LINE:.*]]
end_comment

begin_comment
comment|// CHECK: [[LINE]] = !MDLocation(line: 6,
end_comment

end_unit

