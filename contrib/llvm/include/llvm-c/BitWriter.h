begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/BitWriter.h - BitWriter Library C Interface ------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMBitWriter.a, which          *| |* implements output of the LLVM bitcode format.                              *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_BITWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_BITWRITER_H
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
comment|/**  * @defgroup LLVMCBitWriter Bit Writer  * @ingroup LLVMC  *  * @{  */
comment|/*===-- Operations on modules ---------------------------------------------===*/
comment|/** Writes a module to the specified path. Returns 0 on success. */
name|int
name|LLVMWriteBitcodeToFile
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|,
specifier|const
name|char
modifier|*
name|Path
parameter_list|)
function_decl|;
comment|/** Writes a module to an open file descriptor. Returns 0 on success. */
name|int
name|LLVMWriteBitcodeToFD
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|,
name|int
name|FD
parameter_list|,
name|int
name|ShouldClose
parameter_list|,
name|int
name|Unbuffered
parameter_list|)
function_decl|;
comment|/** Deprecated for LLVMWriteBitcodeToFD. Writes a module to an open file     descriptor. Returns 0 on success. Closes the Handle. */
name|int
name|LLVMWriteBitcodeToFileHandle
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|,
name|int
name|Handle
parameter_list|)
function_decl|;
comment|/** Writes a module to a new memory buffer and returns it. */
name|LLVMMemoryBufferRef
name|LLVMWriteBitcodeToMemoryBuffer
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|)
function_decl|;
comment|/**  * @}  */
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

