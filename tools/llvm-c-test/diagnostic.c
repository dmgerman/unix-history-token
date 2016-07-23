begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- diagnostic.cpp - tool for testing libLLVM and llvm-c API ----------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements the --test-diagnostic-handler command in llvm-c-test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This command uses the C API to read a module with a custom diagnostic
end_comment

begin_comment
comment|// handler set to test the diagnostic handler functionality.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm-c-test.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/BitReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
specifier|static
name|void
name|diagnosticHandler
parameter_list|(
name|LLVMDiagnosticInfoRef
name|DI
parameter_list|,
name|void
modifier|*
name|C
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Executing diagnostic handler\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Diagnostic severity is of type "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|LLVMGetDiagInfoSeverity
argument_list|(
name|DI
argument_list|)
condition|)
block|{
case|case
name|LLVMDSError
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LLVMDSWarning
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"warning"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LLVMDSRemark
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"remark"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LLVMDSNote
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"note"
argument_list|)
expr_stmt|;
break|break;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
operator|(
operator|*
operator|(
name|int
operator|*
operator|)
name|C
operator|)
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|handlerCalled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|llvm_test_diagnostic_handler
parameter_list|(
name|void
parameter_list|)
block|{
name|LLVMContextRef
name|C
init|=
name|LLVMGetGlobalContext
argument_list|()
decl_stmt|;
name|LLVMContextSetDiagnosticHandler
argument_list|(
name|C
argument_list|,
name|diagnosticHandler
argument_list|,
operator|&
name|handlerCalled
argument_list|)
expr_stmt|;
if|if
condition|(
name|LLVMContextGetDiagnosticHandler
argument_list|(
name|C
argument_list|)
operator|!=
name|diagnosticHandler
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"LLVMContext{Set,Get}DiagnosticHandler failed\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|int
modifier|*
name|DC
init|=
operator|(
name|int
operator|*
operator|)
name|LLVMContextGetDiagnosticContext
argument_list|(
name|C
argument_list|)
decl_stmt|;
if|if
condition|(
name|DC
operator|!=
operator|&
name|handlerCalled
operator|||
operator|*
name|DC
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"LLVMContextGetDiagnosticContext failed\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|LLVMMemoryBufferRef
name|MB
decl_stmt|;
name|char
modifier|*
name|msg
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|LLVMCreateMemoryBufferWithSTDIN
argument_list|(
operator|&
name|MB
argument_list|,
operator|&
name|msg
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error reading file: %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|LLVMDisposeMessage
argument_list|(
name|msg
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|LLVMModuleRef
name|M
decl_stmt|;
name|int
name|Ret
init|=
name|LLVMGetBitcodeModule2
argument_list|(
name|MB
argument_list|,
operator|&
name|M
argument_list|)
decl_stmt|;
if|if
condition|(
name|Ret
condition|)
block|{
comment|// We do not return if the bitcode was invalid, as we want to test whether
comment|// the diagnostic handler was executed.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error parsing bitcode: %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
name|LLVMDisposeMemoryBuffer
argument_list|(
name|MB
argument_list|)
expr_stmt|;
if|if
condition|(
name|handlerCalled
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Diagnostic handler was called while loading module\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Diagnostic handler was not called while loading module\n"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

