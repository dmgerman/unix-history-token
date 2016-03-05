begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/ErrorHandling.h - Error Handling C Interface -------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file defines the C interface to LLVM's error handling mechanism.      *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_ERROR_HANDLING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_ERROR_HANDLING_H
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
typedef|typedef
name|void
function_decl|(
modifier|*
name|LLVMFatalErrorHandler
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|Reason
parameter_list|)
function_decl|;
comment|/**  * Install a fatal error handler. By default, if LLVM detects a fatal error, it  * will call exit(1). This may not be appropriate in many contexts. For example,  * doing exit(1) will bypass many crash reporting/tracing system tools. This  * function allows you to install a callback that will be invoked prior to the  * call to exit(1).  */
name|void
name|LLVMInstallFatalErrorHandler
parameter_list|(
name|LLVMFatalErrorHandler
name|Handler
parameter_list|)
function_decl|;
comment|/**  * Reset the fatal error handler. This resets LLVM's fatal error handling  * behavior to the default.  */
name|void
name|LLVMResetFatalErrorHandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Enable LLVM's built-in stack trace code. This intercepts the OS's crash  * signals and prints which component of LLVM you were in at the time if the  * crash.  */
name|void
name|LLVMEnablePrettyStackTrace
parameter_list|(
name|void
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

