begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -gsplit-dwarf -S -emit-llvm -o - %s | FileCheck %s
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
comment|// Testing to ensure that the dwo name gets output into the compile unit.
end_comment

begin_comment
comment|// CHECK: split-debug-filename.dwo
end_comment

end_unit

