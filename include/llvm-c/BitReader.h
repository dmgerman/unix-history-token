begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/BitReader.h - BitReader Library C Interface ------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMBitReader.a, which          *| |* implements input of the LLVM bitcode format.                               *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_BITCODEREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_BITCODEREADER_H
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
comment|/* Builds a module from the bitcode in the specified memory buffer, returning a    reference to the module via the OutModule parameter. Returns 0 on success.    Optionally returns a human-readable error message via OutMessage. */
name|LLVMBool
name|LLVMParseBitcode
parameter_list|(
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|,
name|LLVMModuleRef
modifier|*
name|OutModule
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMParseBitcodeInContext
parameter_list|(
name|LLVMContextRef
name|ContextRef
parameter_list|,
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|,
name|LLVMModuleRef
modifier|*
name|OutModule
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
parameter_list|)
function_decl|;
comment|/* Reads a module from the specified path, returning via the OutMP parameter    a module provider which performs lazy deserialization. Returns 0 on success.    Optionally returns a human-readable error message via OutMessage. */
name|LLVMBool
name|LLVMGetBitcodeModuleProvider
parameter_list|(
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|,
name|LLVMModuleProviderRef
modifier|*
name|OutMP
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMGetBitcodeModuleProviderInContext
parameter_list|(
name|LLVMContextRef
name|ContextRef
parameter_list|,
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|,
name|LLVMModuleProviderRef
modifier|*
name|OutMP
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

