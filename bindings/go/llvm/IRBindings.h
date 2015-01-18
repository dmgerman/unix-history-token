begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRBindings.h - Additional bindings for IR ----------------*- C++ -*-===//
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
comment|// This file defines additional C bindings for the IR component.
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
name|LLVM_BINDINGS_GO_LLVM_IRBINDINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BINDINGS_GO_LLVM_IRBINDINGS_H
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

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
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
name|struct
name|LLVMOpaqueMetadata
modifier|*
name|LLVMMetadataRef
typedef|;
comment|// These functions duplicate the LLVM*FunctionAttr functions in the stable C
comment|// API. We cannot use the existing functions because they take 32-bit attribute
comment|// values, and the Go bindings expose all of the LLVM attributes, some of which
comment|// have values>= 1<<32.
name|void
name|LLVMAddFunctionAttr2
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|,
name|uint64_t
name|PA
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetFunctionAttr2
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|)
function_decl|;
name|void
name|LLVMRemoveFunctionAttr2
parameter_list|(
name|LLVMValueRef
name|Fn
parameter_list|,
name|uint64_t
name|PA
parameter_list|)
function_decl|;
name|LLVMMetadataRef
name|LLVMConstantAsMetadata
parameter_list|(
name|LLVMValueRef
name|Val
parameter_list|)
function_decl|;
name|LLVMMetadataRef
name|LLVMMDString2
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
specifier|const
name|char
modifier|*
name|Str
parameter_list|,
name|unsigned
name|SLen
parameter_list|)
function_decl|;
name|LLVMMetadataRef
name|LLVMMDNode2
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
name|LLVMMetadataRef
modifier|*
name|MDs
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
name|LLVMMetadataRef
name|LLVMTemporaryMDNode
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
name|LLVMMetadataRef
modifier|*
name|MDs
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
name|void
name|LLVMAddNamedMetadataOperand2
parameter_list|(
name|LLVMModuleRef
name|M
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|LLVMMetadataRef
name|Val
parameter_list|)
function_decl|;
name|void
name|LLVMSetMetadata2
parameter_list|(
name|LLVMValueRef
name|Inst
parameter_list|,
name|unsigned
name|KindID
parameter_list|,
name|LLVMMetadataRef
name|MD
parameter_list|)
function_decl|;
name|void
name|LLVMMetadataReplaceAllUsesWith
parameter_list|(
name|LLVMMetadataRef
name|MD
parameter_list|,
name|LLVMMetadataRef
name|New
parameter_list|)
function_decl|;
name|void
name|LLVMSetCurrentDebugLocation2
parameter_list|(
name|LLVMBuilderRef
name|Bref
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|,
name|LLVMMetadataRef
name|Scope
parameter_list|,
name|LLVMMetadataRef
name|InlinedAt
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
name|DEFINE_ISA_CONVERSION_FUNCTIONS
argument_list|(
argument|Metadata
argument_list|,
argument|LLVMMetadataRef
argument_list|)
specifier|inline
name|Metadata
modifier|*
modifier|*
name|unwrap
parameter_list|(
name|LLVMMetadataRef
modifier|*
name|Vals
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Metadata
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

