begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/LinkTimeOptimizer.h - LTO Public C Interface -------*- C++ -*-===//
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
comment|// This header provides a C API to use the LLVM link time optimization
end_comment

begin_comment
comment|// library. This is intended to be used by linkers which are C-only in
end_comment

begin_comment
comment|// their implementation for performing LTO.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_LINKTIMEOPTIMIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_LINKTIMEOPTIMIZER_H
end_define

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
comment|/**  * @defgroup LLVMCLinkTimeOptimizer Link Time Optimization  * @ingroup LLVMC  *  * @{  */
comment|/// This provides a dummy type for pointers to the LTO object.
typedef|typedef
name|void
modifier|*
name|llvm_lto_t
typedef|;
comment|/// This provides a C-visible enumerator to manage status codes.
comment|/// This should map exactly onto the C++ enumerator LTOStatus.
typedef|typedef
enum|enum
name|llvm_lto_status
block|{
name|LLVM_LTO_UNKNOWN
block|,
name|LLVM_LTO_OPT_SUCCESS
block|,
name|LLVM_LTO_READ_SUCCESS
block|,
name|LLVM_LTO_READ_FAILURE
block|,
name|LLVM_LTO_WRITE_FAILURE
block|,
name|LLVM_LTO_NO_TARGET
block|,
name|LLVM_LTO_NO_WORK
block|,
name|LLVM_LTO_MODULE_MERGE_FAILURE
block|,
name|LLVM_LTO_ASM_FAILURE
block|,
comment|//  Added C-specific error codes
name|LLVM_LTO_NULL_OBJECT
block|}
name|llvm_lto_status_t
typedef|;
comment|/// This provides C interface to initialize link time optimizer. This allows
comment|/// linker to use dlopen() interface to dynamically load LinkTimeOptimizer.
comment|/// extern "C" helps, because dlopen() interface uses name to find the symbol.
specifier|extern
name|llvm_lto_t
name|llvm_create_optimizer
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|llvm_destroy_optimizer
parameter_list|(
name|llvm_lto_t
name|lto
parameter_list|)
function_decl|;
specifier|extern
name|llvm_lto_status_t
name|llvm_read_object_file
parameter_list|(
name|llvm_lto_t
name|lto
parameter_list|,
specifier|const
name|char
modifier|*
name|input_filename
parameter_list|)
function_decl|;
specifier|extern
name|llvm_lto_status_t
name|llvm_optimize_modules
parameter_list|(
name|llvm_lto_t
name|lto
parameter_list|,
specifier|const
name|char
modifier|*
name|output_filename
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

