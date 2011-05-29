begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Analysis.h - Analysis Library C Interface --------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMAnalysis.a, which           *| |* implements various analyses of the LLVM IR.                                *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
enum|enum
block|{
name|LLVMAbortProcessAction
block|,
comment|/* verifier will print to stderr and abort() */
name|LLVMPrintMessageAction
block|,
comment|/* verifier will print to stderr and return 1 */
name|LLVMReturnStatusAction
comment|/* verifier will just return 1 */
block|}
name|LLVMVerifierFailureAction
typedef|;
comment|/* Verifies that a module is valid, taking the specified action if not.    Optionally returns a human-readable description of any invalid constructs.    OutMessage must be disposed with LLVMDisposeMessage. */
name|LLVMBool
name|LLVMVerifyModule
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|,
name|LLVMVerifierFailureAction
name|Action
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
parameter_list|)
function_decl|;
comment|/* Verifies that a single function is valid, taking the specified action. Useful    for debugging. */
name|LLVMBool
name|LLVMVerifyFunction
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|,
name|LLVMVerifierFailureAction
name|Action
parameter_list|)
function_decl|;
comment|/* Open up a ghostview window that displays the CFG of the current function.    Useful for debugging. */
name|void
name|LLVMViewFunctionCFG
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
function_decl|;
name|void
name|LLVMViewFunctionCFGOnly
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

