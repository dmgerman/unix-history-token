begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/IRReader.h - IR Reader C Interface -----------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file defines the C interface to the IR Reader.                        *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_IRREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_IRREADER_H
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
comment|/**  * Read LLVM IR from a memory buffer and convert it into an in-memory Module  * object. Returns 0 on success.  * Optionally returns a human-readable description of any errors that  * occured during parsing IR. OutMessage must be disposed with  * LLVMDisposeMessage.  *  * @see llvm::ParseIR()  */
name|LLVMBool
name|LLVMParseIRInContext
parameter_list|(
name|LLVMContextRef
name|ContextRef
parameter_list|,
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|,
name|LLVMModuleRef
modifier|*
name|OutM
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
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

