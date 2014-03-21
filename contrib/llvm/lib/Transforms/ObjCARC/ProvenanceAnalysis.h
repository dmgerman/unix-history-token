begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProvenanceAnalysis.h - ObjC ARC Optimization ---*- C++ -*-----------===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file declares a special form of Alias Analysis called ``Provenance
end_comment

begin_comment
comment|/// Analysis''. The word ``provenance'' refers to the history of the ownership
end_comment

begin_comment
comment|/// of an object. Thus ``Provenance Analysis'' is an analysis which attempts to
end_comment

begin_comment
comment|/// use various techniques to determine if locally
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about certain library functions. It recognizes them
end_comment

begin_comment
comment|/// by name, and hardwires knowledge of their semantics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about how certain Objective-C library functions are
end_comment

begin_comment
comment|/// used. Naive LLVM IR transformations which would otherwise be
end_comment

begin_comment
comment|/// behavior-preserving may break these assumptions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_OBJCARC_PROVENANCEANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_OBJCARC_PROVENANCEANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|SelectInst
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
comment|/// \brief This is similar to BasicAliasAnalysis, and it uses many of the same
comment|/// techniques, except it uses special ObjC-specific reasoning about pointer
comment|/// relationships.
comment|///
comment|/// In this context ``Provenance'' is defined as the history of an object's
comment|/// ownership. Thus ``Provenance Analysis'' is defined by using the notion of
comment|/// an ``independent provenance source'' of a pointer to determine whether or
comment|/// not two pointers have the same provenance source and thus could
comment|/// potentially be related.
name|class
name|ProvenanceAnalysis
block|{
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|Value
operator|*
operator|,
specifier|const
name|Value
operator|*
operator|>
name|ValuePairTy
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|ValuePairTy
operator|,
name|bool
operator|>
name|CachedResultsTy
expr_stmt|;
name|CachedResultsTy
name|CachedResults
decl_stmt|;
name|bool
name|relatedCheck
parameter_list|(
specifier|const
name|Value
modifier|*
name|A
parameter_list|,
specifier|const
name|Value
modifier|*
name|B
parameter_list|)
function_decl|;
name|bool
name|relatedSelect
parameter_list|(
specifier|const
name|SelectInst
modifier|*
name|A
parameter_list|,
specifier|const
name|Value
modifier|*
name|B
parameter_list|)
function_decl|;
name|bool
name|relatedPHI
parameter_list|(
specifier|const
name|PHINode
modifier|*
name|A
parameter_list|,
specifier|const
name|Value
modifier|*
name|B
parameter_list|)
function_decl|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ProvenanceAnalysis
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|ProvenanceAnalysis
argument_list|(
argument|const ProvenanceAnalysis&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|public
label|:
name|ProvenanceAnalysis
argument_list|()
block|{}
name|void
name|setAA
parameter_list|(
name|AliasAnalysis
modifier|*
name|aa
parameter_list|)
block|{
name|AA
operator|=
name|aa
expr_stmt|;
block|}
name|AliasAnalysis
operator|*
name|getAA
argument_list|()
specifier|const
block|{
return|return
name|AA
return|;
block|}
name|bool
name|related
parameter_list|(
specifier|const
name|Value
modifier|*
name|A
parameter_list|,
specifier|const
name|Value
modifier|*
name|B
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
block|{
name|CachedResults
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
comment|// end namespace objcarc
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_OBJCARC_PROVENANCEANALYSIS_H
end_comment

end_unit

