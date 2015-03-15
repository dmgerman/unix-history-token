begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/CXErrorCode.h - C Index Error Codes  --------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides the CXErrorCode enumerators.                          *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_C_CXERRORCODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_C_CXERRORCODE_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Platform.h"
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
comment|/**  * \brief Error codes returned by libclang routines.  *  * Zero (\c CXError_Success) is the only error code indicating success.  Other  * error codes, including not yet assigned non-zero values, indicate errors.  */
enum|enum
name|CXErrorCode
block|{
comment|/**    * \brief No error.    */
name|CXError_Success
init|=
literal|0
block|,
comment|/**    * \brief A generic error code, no further details are available.    *    * Errors of this kind can get their own specific error codes in future    * libclang versions.    */
name|CXError_Failure
init|=
literal|1
block|,
comment|/**    * \brief libclang crashed while performing the requested operation.    */
name|CXError_Crashed
init|=
literal|2
block|,
comment|/**    * \brief The function detected that the arguments violate the function    * contract.    */
name|CXError_InvalidArguments
init|=
literal|3
block|,
comment|/**    * \brief An AST deserialization error has occurred.    */
name|CXError_ASTReadError
init|=
literal|4
block|}
enum|;
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

