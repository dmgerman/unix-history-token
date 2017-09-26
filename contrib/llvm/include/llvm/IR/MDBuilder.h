begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/MDBuilder.h - Builder for LLVM metadata ----------*- C++ -*-===//
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
comment|// This file defines the MDBuilder class, which is used as a convenient way to
end_comment

begin_comment
comment|// create LLVM metadata with a consistent and simplified interface.
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
name|LLVM_IR_MDBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_MDBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantAsMetadata
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|MDString
decl_stmt|;
name|class
name|MDBuilder
block|{
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|public
label|:
name|MDBuilder
argument_list|(
name|LLVMContext
operator|&
name|context
argument_list|)
operator|:
name|Context
argument_list|(
argument|context
argument_list|)
block|{}
comment|/// \brief Return the given string as metadata.
name|MDString
operator|*
name|createString
argument_list|(
argument|StringRef Str
argument_list|)
expr_stmt|;
comment|/// \brief Return the given constant as metadata.
name|ConstantAsMetadata
modifier|*
name|createConstant
parameter_list|(
name|Constant
modifier|*
name|C
parameter_list|)
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// FPMath metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata with the given settings.  The special value 0.0
comment|/// for the Accuracy parameter indicates the default (maximal precision)
comment|/// setting.
name|MDNode
modifier|*
name|createFPMath
parameter_list|(
name|float
name|Accuracy
parameter_list|)
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// Prof metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata containing two branch weights.
name|MDNode
modifier|*
name|createBranchWeights
parameter_list|(
name|uint32_t
name|TrueWeight
parameter_list|,
name|uint32_t
name|FalseWeight
parameter_list|)
function_decl|;
comment|/// \brief Return metadata containing a number of branch weights.
name|MDNode
modifier|*
name|createBranchWeights
argument_list|(
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|Weights
argument_list|)
decl_stmt|;
comment|/// Return metadata specifying that a branch or switch is unpredictable.
name|MDNode
modifier|*
name|createUnpredictable
parameter_list|()
function_decl|;
comment|/// Return metadata containing the entry \p Count for a function, and the
comment|/// GUIDs stored in \p Imports that need to be imported for sample PGO, to
comment|/// enable the same inlines as the profiled optimized binary
name|MDNode
modifier|*
name|createFunctionEntryCount
argument_list|(
name|uint64_t
name|Count
argument_list|,
specifier|const
name|DenseSet
operator|<
name|GlobalValue
operator|::
name|GUID
operator|>
operator|*
name|Imports
argument_list|)
decl_stmt|;
comment|/// Return metadata containing the section prefix for a function.
name|MDNode
modifier|*
name|createFunctionSectionPrefix
parameter_list|(
name|StringRef
name|Prefix
parameter_list|)
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// Range metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata describing the range [Lo, Hi).
name|MDNode
modifier|*
name|createRange
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Lo
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Hi
parameter_list|)
function_decl|;
comment|/// \brief Return metadata describing the range [Lo, Hi).
name|MDNode
modifier|*
name|createRange
parameter_list|(
name|Constant
modifier|*
name|Lo
parameter_list|,
name|Constant
modifier|*
name|Hi
parameter_list|)
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// AA metadata.
comment|//===------------------------------------------------------------------===//
name|protected
label|:
comment|/// \brief Return metadata appropriate for a AA root node (scope or TBAA).
comment|/// Each returned node is distinct from all other metadata and will never
comment|/// be identified (uniqued) with anything else.
name|MDNode
modifier|*
name|createAnonymousAARoot
parameter_list|(
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|,
name|MDNode
modifier|*
name|Extra
init|=
name|nullptr
parameter_list|)
function_decl|;
name|public
label|:
comment|/// \brief Return metadata appropriate for a TBAA root node. Each returned
comment|/// node is distinct from all other metadata and will never be identified
comment|/// (uniqued) with anything else.
name|MDNode
modifier|*
name|createAnonymousTBAARoot
parameter_list|()
block|{
return|return
name|createAnonymousAARoot
argument_list|()
return|;
block|}
comment|/// \brief Return metadata appropriate for an alias scope domain node.
comment|/// Each returned node is distinct from all other metadata and will never
comment|/// be identified (uniqued) with anything else.
name|MDNode
modifier|*
name|createAnonymousAliasScopeDomain
parameter_list|(
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
return|return
name|createAnonymousAARoot
argument_list|(
name|Name
argument_list|)
return|;
block|}
comment|/// \brief Return metadata appropriate for an alias scope root node.
comment|/// Each returned node is distinct from all other metadata and will never
comment|/// be identified (uniqued) with anything else.
name|MDNode
modifier|*
name|createAnonymousAliasScope
parameter_list|(
name|MDNode
modifier|*
name|Domain
parameter_list|,
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
return|return
name|createAnonymousAARoot
argument_list|(
name|Name
argument_list|,
name|Domain
argument_list|)
return|;
block|}
comment|/// \brief Return metadata appropriate for a TBAA root node with the given
comment|/// name.  This may be identified (uniqued) with other roots with the same
comment|/// name.
name|MDNode
modifier|*
name|createTBAARoot
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Return metadata appropriate for an alias scope domain node with
comment|/// the given name. This may be identified (uniqued) with other roots with
comment|/// the same name.
name|MDNode
modifier|*
name|createAliasScopeDomain
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Return metadata appropriate for an alias scope node with
comment|/// the given name. This may be identified (uniqued) with other scopes with
comment|/// the same name and domain.
name|MDNode
modifier|*
name|createAliasScope
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|MDNode
modifier|*
name|Domain
parameter_list|)
function_decl|;
comment|/// \brief Return metadata for a non-root TBAA node with the given name,
comment|/// parent in the TBAA tree, and value for 'pointsToConstantMemory'.
name|MDNode
modifier|*
name|createTBAANode
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|MDNode
modifier|*
name|Parent
parameter_list|,
name|bool
name|isConstant
init|=
name|false
parameter_list|)
function_decl|;
struct|struct
name|TBAAStructField
block|{
name|uint64_t
name|Offset
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|MDNode
modifier|*
name|TBAA
decl_stmt|;
name|TBAAStructField
argument_list|(
argument|uint64_t Offset
argument_list|,
argument|uint64_t Size
argument_list|,
argument|MDNode *TBAA
argument_list|)
block|:
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|TBAA
argument_list|(
argument|TBAA
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Return metadata for a tbaa.struct node with the given
comment|/// struct field descriptions.
name|MDNode
modifier|*
name|createTBAAStructNode
argument_list|(
name|ArrayRef
operator|<
name|TBAAStructField
operator|>
name|Fields
argument_list|)
decl_stmt|;
comment|/// \brief Return metadata for a TBAA struct node in the type DAG
comment|/// with the given name, a list of pairs (offset, field type in the type DAG).
name|MDNode
modifier|*
name|createTBAAStructTypeNode
argument_list|(
name|StringRef
name|Name
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|MDNode
operator|*
argument_list|,
name|uint64_t
operator|>>
name|Fields
argument_list|)
decl_stmt|;
comment|/// \brief Return metadata for a TBAA scalar type node with the
comment|/// given name, an offset and a parent in the TBAA type DAG.
name|MDNode
modifier|*
name|createTBAAScalarTypeNode
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|MDNode
modifier|*
name|Parent
parameter_list|,
name|uint64_t
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Return metadata for a TBAA tag node with the given
comment|/// base type, access type and offset relative to the base type.
name|MDNode
modifier|*
name|createTBAAStructTagNode
parameter_list|(
name|MDNode
modifier|*
name|BaseType
parameter_list|,
name|MDNode
modifier|*
name|AccessType
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|bool
name|IsConstant
init|=
name|false
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

