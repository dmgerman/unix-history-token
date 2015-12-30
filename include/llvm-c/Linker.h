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
file|"llvm-c/Types.h"
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
comment|/* This enum is provided for backwards-compatibility only. It has no effect. */
typedef|typedef
enum|enum
block|{
name|LLVMLinkerDestroySource
init|=
literal|0
block|,
comment|/* This is the default behavior. */
name|LLVMLinkerPreserveSource_Removed
init|=
literal|1
comment|/* This option has been deprecated and                                           should not be used. */
block|}
name|LLVMLinkerMode
typedef|;
comment|/* Links the source module into the destination module. The source module is  * damaged. The only thing that can be done is destroy it. Optionally returns a  * human-readable description of any errors that occurred in linking. OutMessage  * must be disposed with LLVMDisposeMessage. The return value is true if an  * error occurred, false otherwise.  *  * Note that the linker mode parameter \p Unused is no longer used, and has  * no effect.  *  * This function is deprecated. Use LLVMLinkModules2 instead.  */
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
name|Unused
parameter_list|,
name|char
modifier|*
modifier|*
name|OutMessage
parameter_list|)
function_decl|;
comment|/* Links the source module into the destination module. The source module is  * destroyed.  * The return value is true if an error occurred, false otherwise.  * Use the diagnostic handler to get any diagnostic message. */
name|LLVMBool
name|LLVMLinkModules2
parameter_list|(
name|LLVMModuleRef
name|Dest
parameter_list|,
name|LLVMModuleRef
name|Src
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

