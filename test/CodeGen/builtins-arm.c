begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-eabi -target-cpu cortex-a8 -O3 -emit-llvm -o %t %s
end_comment

begin_function
name|void
modifier|*
name|f0
parameter_list|()
block|{
return|return
name|__builtin_thread_pointer
argument_list|()
return|;
block|}
end_function

end_unit

