begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Linker.h - Module Linker C Interface -------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file defines the C interface to the module/file/archive linker.       *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_LINKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_LINKER_H
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
comment|/* Note: LLVMLinkerPreserveSource has no effect. */
typedef|typedef
enum|enum
block|{
name|LLVMLinkerDestroySource
init|=
literal|0
block|,
comment|/* Allow source module to be destroyed. */
name|LLVMLinkerPreserveSource
init|=
literal|1
comment|/* Preserve the source module. */
block|}
name|LLVMLinkerMode
typedef|;
comment|/* Links the source module into the destination module, taking ownership  * of the source module away from the caller. Optionally returns a  * human-readable description of any errors that occurred in linking.  * OutMessage must be disposed with LLVMDisposeMessage. The return value  * is true if an error occurred, false otherwise. */
name|LLVMBool
name|LLVMLinkModules
parameter_list|(
name|LLVMModuleRef
name|Dest
parameter_list|,
name|LLVMModuleRef
name|Src
parameter_list|,
name|LLVMLinkerMode
name|Mode
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

