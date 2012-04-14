begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -o - -emit-llvm -g %s | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_comment
comment|// PR9796
end_comment

begin_comment
comment|// Check to make sure that we emit the block for the break so that we can count the line.
end_comment

begin_comment
comment|// CHECK: sw.bb:                                            ; preds = %entry
end_comment

begin_comment
comment|// CHECK: br label %sw.epilog, !dbg !21
end_comment

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|x
init|=
name|atoi
argument_list|(
name|arg
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

