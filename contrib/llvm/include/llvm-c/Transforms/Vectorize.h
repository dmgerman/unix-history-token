begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---------------------------Vectorize.h --------------------- -*- C -*-===*\ |*===----------- Vectorization Transformation Library C Interface ---------===*| |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMVectorize.a, which          *| |* implements various vectorization transformations of the LLVM IR.           *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TRANSFORMS_VECTORIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TRANSFORMS_VECTORIZE_H
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
comment|/**  * @defgroup LLVMCTransformsVectorize Vectorization transformations  * @ingroup LLVMCTransforms  *  * @{  */
comment|/** DEPRECATED - Use LLVMAddSLPVectorizePass */
name|void
name|LLVMAddBBVectorizePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopVectorizePass function. */
name|void
name|LLVMAddLoopVectorizePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createSLPVectorizerPass function. */
name|void
name|LLVMAddSLPVectorizePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
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

begin_comment
comment|/* defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

