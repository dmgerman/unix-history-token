begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PtrState.h - ARC State for a Ptr -------------------*- C++ -*-----===//
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
comment|//  This file contains declarations for the ARC state associated with a ptr. It
end_comment

begin_comment
comment|//  is only used by the ARC Sequence Dataflow computation. By separating this
end_comment

begin_comment
comment|//  from the actual dataflow, it is easier to consider the mechanics of the ARC
end_comment

begin_comment
comment|//  optimization separate from the actual predicates being used.
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
name|LLVM_LIB_TRANSFORMS_OBJCARC_PTRSTATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TRANSFORMS_OBJCARC_PTRSTATE_H
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

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
name|class
name|ARCMDKindCache
decl_stmt|;
name|class
name|ProvenanceAnalysis
decl_stmt|;
comment|/// \enum Sequence
comment|///
comment|/// \brief A sequence of states that a pointer may go through in which an
comment|/// objc_retain and objc_release are actually needed.
enum|enum
name|Sequence
block|{
name|S_None
block|,
name|S_Retain
block|,
comment|///< objc_retain(x).
name|S_CanRelease
block|,
comment|///< foo(x) -- x could possibly see a ref count decrement.
name|S_Use
block|,
comment|///< any use of x.
name|S_Stop
block|,
comment|///< like S_Release, but code motion is stopped.
name|S_Release
block|,
comment|///< objc_release(x).
name|S_MovableRelease
comment|///< objc_release(x), !clang.imprecise_release.
block|}
enum|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Sequence
name|S
operator|)
name|LLVM_ATTRIBUTE_UNUSED
expr_stmt|;
comment|/// \brief Unidirectional information about either a
comment|/// retain-decrement-use-release sequence or release-use-decrement-retain
comment|/// reverse sequence.
struct|struct
name|RRInfo
block|{
comment|/// After an objc_retain, the reference count of the referenced
comment|/// object is known to be positive. Similarly, before an objc_release, the
comment|/// reference count of the referenced object is known to be positive. If
comment|/// there are retain-release pairs in code regions where the retain count
comment|/// is known to be positive, they can be eliminated, regardless of any side
comment|/// effects between them.
comment|///
comment|/// Also, a retain+release pair nested within another retain+release
comment|/// pair all on the known same pointer value can be eliminated, regardless
comment|/// of any intervening side effects.
comment|///
comment|/// KnownSafe is true when either of these conditions is satisfied.
name|bool
name|KnownSafe
decl_stmt|;
comment|/// True of the objc_release calls are all marked with the "tail" keyword.
name|bool
name|IsTailCallRelease
decl_stmt|;
comment|/// If the Calls are objc_release calls and they all have a
comment|/// clang.imprecise_release tag, this is the metadata tag.
name|MDNode
modifier|*
name|ReleaseMetadata
decl_stmt|;
comment|/// For a top-down sequence, the set of objc_retains or
comment|/// objc_retainBlocks. For bottom-up, the set of objc_releases.
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|2
operator|>
name|Calls
expr_stmt|;
comment|/// The set of optimal insert positions for moving calls in the opposite
comment|/// sequence.
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|2
operator|>
name|ReverseInsertPts
expr_stmt|;
comment|/// If this is true, we cannot perform code motion but can still remove
comment|/// retain/release pairs.
name|bool
name|CFGHazardAfflicted
decl_stmt|;
name|RRInfo
argument_list|()
operator|:
name|KnownSafe
argument_list|(
name|false
argument_list|)
operator|,
name|IsTailCallRelease
argument_list|(
name|false
argument_list|)
operator|,
name|ReleaseMetadata
argument_list|(
name|nullptr
argument_list|)
operator|,
name|CFGHazardAfflicted
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|clear
argument_list|()
expr_stmt|;
comment|/// Conservatively merge the two RRInfo. Returns true if a partial merge has
comment|/// occurred, false otherwise.
name|bool
name|Merge
parameter_list|(
specifier|const
name|RRInfo
modifier|&
name|Other
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// \brief This class summarizes several per-pointer runtime properties which
comment|/// are propagated through the flow graph.
name|class
name|PtrState
block|{
name|protected
label|:
comment|/// True if the reference count is known to be incremented.
name|bool
name|KnownPositiveRefCount
decl_stmt|;
comment|/// True if we've seen an opportunity for partial RR elimination, such as
comment|/// pushing calls into a CFG triangle or into one side of a CFG diamond.
name|bool
name|Partial
decl_stmt|;
comment|/// The current position in the sequence.
name|unsigned
name|char
name|Seq
range|:
literal|8
decl_stmt|;
comment|/// Unidirectional information about the current sequence.
name|RRInfo
name|RRI
decl_stmt|;
name|PtrState
argument_list|()
operator|:
name|KnownPositiveRefCount
argument_list|(
name|false
argument_list|)
operator|,
name|Partial
argument_list|(
name|false
argument_list|)
operator|,
name|Seq
argument_list|(
argument|S_None
argument_list|)
block|{}
name|public
operator|:
name|bool
name|IsKnownSafe
argument_list|()
specifier|const
block|{
return|return
name|RRI
operator|.
name|KnownSafe
return|;
block|}
name|void
name|SetKnownSafe
parameter_list|(
specifier|const
name|bool
name|NewValue
parameter_list|)
block|{
name|RRI
operator|.
name|KnownSafe
operator|=
name|NewValue
expr_stmt|;
block|}
name|bool
name|IsTailCallRelease
argument_list|()
specifier|const
block|{
return|return
name|RRI
operator|.
name|IsTailCallRelease
return|;
block|}
name|void
name|SetTailCallRelease
parameter_list|(
specifier|const
name|bool
name|NewValue
parameter_list|)
block|{
name|RRI
operator|.
name|IsTailCallRelease
operator|=
name|NewValue
expr_stmt|;
block|}
name|bool
name|IsTrackingImpreciseReleases
argument_list|()
specifier|const
block|{
return|return
name|RRI
operator|.
name|ReleaseMetadata
operator|!=
name|nullptr
return|;
block|}
specifier|const
name|MDNode
operator|*
name|GetReleaseMetadata
argument_list|()
specifier|const
block|{
return|return
name|RRI
operator|.
name|ReleaseMetadata
return|;
block|}
name|void
name|SetReleaseMetadata
parameter_list|(
name|MDNode
modifier|*
name|NewValue
parameter_list|)
block|{
name|RRI
operator|.
name|ReleaseMetadata
operator|=
name|NewValue
expr_stmt|;
block|}
name|bool
name|IsCFGHazardAfflicted
argument_list|()
specifier|const
block|{
return|return
name|RRI
operator|.
name|CFGHazardAfflicted
return|;
block|}
name|void
name|SetCFGHazardAfflicted
parameter_list|(
specifier|const
name|bool
name|NewValue
parameter_list|)
block|{
name|RRI
operator|.
name|CFGHazardAfflicted
operator|=
name|NewValue
expr_stmt|;
block|}
name|void
name|SetKnownPositiveRefCount
parameter_list|()
function_decl|;
name|void
name|ClearKnownPositiveRefCount
parameter_list|()
function_decl|;
name|bool
name|HasKnownPositiveRefCount
argument_list|()
specifier|const
block|{
return|return
name|KnownPositiveRefCount
return|;
block|}
name|void
name|SetSeq
parameter_list|(
name|Sequence
name|NewSeq
parameter_list|)
function_decl|;
name|Sequence
name|GetSeq
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Sequence
operator|>
operator|(
name|Seq
operator|)
return|;
block|}
name|void
name|ClearSequenceProgress
parameter_list|()
block|{
name|ResetSequenceProgress
argument_list|(
name|S_None
argument_list|)
expr_stmt|;
block|}
name|void
name|ResetSequenceProgress
parameter_list|(
name|Sequence
name|NewSeq
parameter_list|)
function_decl|;
name|void
name|Merge
parameter_list|(
specifier|const
name|PtrState
modifier|&
name|Other
parameter_list|,
name|bool
name|TopDown
parameter_list|)
function_decl|;
name|void
name|InsertCall
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|RRI
operator|.
name|Calls
operator|.
name|insert
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
name|void
name|InsertReverseInsertPt
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|RRI
operator|.
name|ReverseInsertPts
operator|.
name|insert
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
name|void
name|ClearReverseInsertPts
parameter_list|()
block|{
name|RRI
operator|.
name|ReverseInsertPts
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|HasReverseInsertPts
argument_list|()
specifier|const
block|{
return|return
operator|!
name|RRI
operator|.
name|ReverseInsertPts
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|RRInfo
operator|&
name|GetRRInfo
argument_list|()
specifier|const
block|{
return|return
name|RRI
return|;
block|}
block|}
empty_stmt|;
name|struct
name|BottomUpPtrState
range|:
name|PtrState
block|{
name|BottomUpPtrState
argument_list|()
operator|:
name|PtrState
argument_list|()
block|{}
comment|/// (Re-)Initialize this bottom up pointer returning true if we detected a
comment|/// pointer with nested releases.
name|bool
name|InitBottomUp
argument_list|(
name|ARCMDKindCache
operator|&
name|Cache
argument_list|,
name|Instruction
operator|*
name|I
argument_list|)
block|;
comment|/// Return true if this set of releases can be paired with a release. Modifies
comment|/// state appropriately to reflect that the matching occurred if it is
comment|/// successful.
comment|///
comment|/// It is assumed that one has already checked that the RCIdentity of the
comment|/// retain and the RCIdentity of this ptr state are the same.
name|bool
name|MatchWithRetain
argument_list|()
block|;
name|void
name|HandlePotentialUse
argument_list|(
argument|BasicBlock *BB
argument_list|,
argument|Instruction *Inst
argument_list|,
argument|const Value *Ptr
argument_list|,
argument|ProvenanceAnalysis&PA
argument_list|,
argument|ARCInstKind Class
argument_list|)
block|;
name|bool
name|HandlePotentialAlterRefCount
argument_list|(
argument|Instruction *Inst
argument_list|,
argument|const Value *Ptr
argument_list|,
argument|ProvenanceAnalysis&PA
argument_list|,
argument|ARCInstKind Class
argument_list|)
block|; }
decl_stmt|;
name|struct
name|TopDownPtrState
range|:
name|PtrState
block|{
name|TopDownPtrState
argument_list|()
operator|:
name|PtrState
argument_list|()
block|{}
comment|/// (Re-)Initialize this bottom up pointer returning true if we detected a
comment|/// pointer with nested releases.
name|bool
name|InitTopDown
argument_list|(
argument|ARCInstKind Kind
argument_list|,
argument|Instruction *I
argument_list|)
block|;
comment|/// Return true if this set of retains can be paired with the given
comment|/// release. Modifies state appropriately to reflect that the matching
comment|/// occurred.
name|bool
name|MatchWithRelease
argument_list|(
name|ARCMDKindCache
operator|&
name|Cache
argument_list|,
name|Instruction
operator|*
name|Release
argument_list|)
block|;
name|void
name|HandlePotentialUse
argument_list|(
argument|Instruction *Inst
argument_list|,
argument|const Value *Ptr
argument_list|,
argument|ProvenanceAnalysis&PA
argument_list|,
argument|ARCInstKind Class
argument_list|)
block|;
name|bool
name|HandlePotentialAlterRefCount
argument_list|(
argument|Instruction *Inst
argument_list|,
argument|const Value *Ptr
argument_list|,
argument|ProvenanceAnalysis&PA
argument_list|,
argument|ARCInstKind Class
argument_list|)
block|; }
decl_stmt|;
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

end_unit

