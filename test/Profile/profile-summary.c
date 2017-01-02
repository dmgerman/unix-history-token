begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that profile summary is set correctly.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/max-function-count.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -o - -disable-llvm-passes -emit-llvm -fprofile-instrument-use-path=%t.profdata | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_function
name|int
name|begin
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|end
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|begin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|end
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|end
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: {{![0-9]+}} = !{i32 1, !"ProfileSummary", {{![0-9]+}}}
end_comment

begin_comment
comment|// CHECK: {{![0-9]+}} = !{!"DetailedSummary", {{![0-9]+}}}
end_comment

end_unit

