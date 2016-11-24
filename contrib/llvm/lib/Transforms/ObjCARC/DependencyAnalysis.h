begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DependencyAnalysis.h - ObjC ARC Optimization ---*- C++ -*-----------===//
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
comment|/// This file declares special dependency analysis routines used in Objective C
end_comment

begin_comment
comment|/// ARC Optimizations.
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
name|LLVM_LIB_TRANSFORMS_OBJCARC_DEPENDENCYANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TRANSFORMS_OBJCARC_DEPENDENCYANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ObjCARCInstKind.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
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
name|class
name|ProvenanceAnalysis
decl_stmt|;
comment|/// \enum DependenceKind
comment|/// \brief Defines different dependence kinds among various ARC constructs.
comment|///
comment|/// There are several kinds of dependence-like concepts in use here.
comment|///
enum|enum
name|DependenceKind
block|{
name|NeedsPositiveRetainCount
block|,
name|AutoreleasePoolBoundary
block|,
name|CanChangeRetainCount
block|,
name|RetainAutoreleaseDep
block|,
comment|///< Blocks objc_retainAutorelease.
name|RetainAutoreleaseRVDep
block|,
comment|///< Blocks objc_retainAutoreleaseReturnValue.
name|RetainRVDep
comment|///< Blocks objc_retainAutoreleasedReturnValue.
block|}
enum|;
name|void
name|FindDependencies
argument_list|(
name|DependenceKind
name|Flavor
argument_list|,
specifier|const
name|Value
operator|*
name|Arg
argument_list|,
name|BasicBlock
operator|*
name|StartBB
argument_list|,
name|Instruction
operator|*
name|StartInst
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|DependingInstructions
argument_list|,
name|SmallPtrSetImpl
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|&
name|Visited
argument_list|,
name|ProvenanceAnalysis
operator|&
name|PA
argument_list|)
decl_stmt|;
name|bool
name|Depends
parameter_list|(
name|DependenceKind
name|Flavor
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|,
specifier|const
name|Value
modifier|*
name|Arg
parameter_list|,
name|ProvenanceAnalysis
modifier|&
name|PA
parameter_list|)
function_decl|;
comment|/// Test whether the given instruction can "use" the given pointer's object in a
comment|/// way that requires the reference count to be positive.
name|bool
name|CanUse
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|,
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ProvenanceAnalysis
modifier|&
name|PA
parameter_list|,
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// Test whether the given instruction can result in a reference count
comment|/// modification (positive or negative) for the pointer's object.
name|bool
name|CanAlterRefCount
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|,
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ProvenanceAnalysis
modifier|&
name|PA
parameter_list|,
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
comment|/// Returns true if we can not conservatively prove that Inst can not decrement
comment|/// the reference count of Ptr. Returns false if we can.
name|bool
name|CanDecrementRefCount
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|,
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ProvenanceAnalysis
modifier|&
name|PA
parameter_list|,
name|ARCInstKind
name|Class
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|CanDecrementRefCount
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|,
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|ProvenanceAnalysis
modifier|&
name|PA
parameter_list|)
block|{
return|return
name|CanDecrementRefCount
argument_list|(
name|Inst
argument_list|,
name|Ptr
argument_list|,
name|PA
argument_list|,
name|GetARCInstKind
argument_list|(
name|Inst
argument_list|)
argument_list|)
return|;
block|}
block|}
comment|// namespace objcarc
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

