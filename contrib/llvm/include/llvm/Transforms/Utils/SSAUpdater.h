begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SSAUpdater.h - Unstructured SSA Update Tool -------------*- C++ -*-===//
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
comment|// This file declares the SSAUpdater class.
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
name|LLVM_TRANSFORMS_UTILS_SSAUPDATER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SSAUPDATER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|LoadInst
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SSAUpdaterTraits
expr_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Use
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// \brief Helper class for SSA formation on a set of values defined in
comment|/// multiple blocks.
comment|///
comment|/// This is used when code duplication or another unstructured
comment|/// transformation wants to rewrite a set of uses of one value with uses of a
comment|/// set of values.
name|class
name|SSAUpdater
block|{
name|friend
name|class
name|SSAUpdaterTraits
operator|<
name|SSAUpdater
operator|>
expr_stmt|;
name|private
label|:
comment|/// This keeps track of which value to use on a per-block basis. When we
comment|/// insert PHI nodes, we keep track of them here.
comment|//typedef DenseMap<BasicBlock*, Value*> AvailableValsTy;
name|void
modifier|*
name|AV
init|=
name|nullptr
decl_stmt|;
comment|/// ProtoType holds the type of the values being rewritten.
name|Type
modifier|*
name|ProtoType
init|=
name|nullptr
decl_stmt|;
comment|/// PHI nodes are given a name based on ProtoName.
name|std
operator|::
name|string
name|ProtoName
expr_stmt|;
comment|/// If this is non-null, the SSAUpdater adds all PHI nodes that it creates to
comment|/// the vector.
name|SmallVectorImpl
operator|<
name|PHINode
operator|*
operator|>
operator|*
name|InsertedPHIs
expr_stmt|;
name|public
label|:
comment|/// If InsertedPHIs is specified, it will be filled
comment|/// in with all PHI Nodes created by rewriting.
name|explicit
name|SSAUpdater
argument_list|(
name|SmallVectorImpl
operator|<
name|PHINode
operator|*
operator|>
operator|*
name|InsertedPHIs
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|SSAUpdater
argument_list|(
specifier|const
name|SSAUpdater
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|SSAUpdater
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SSAUpdater
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|SSAUpdater
argument_list|()
expr_stmt|;
comment|/// \brief Reset this object to get ready for a new set of SSA updates with
comment|/// type 'Ty'.
comment|///
comment|/// PHI nodes get a name based on 'Name'.
name|void
name|Initialize
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Indicate that a rewritten value is available in the specified block
comment|/// with the specified value.
name|void
name|AddAvailableValue
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// \brief Return true if the SSAUpdater already has a value for the specified
comment|/// block.
name|bool
name|HasValueForBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Construct SSA form, materializing a value that is live at the end
comment|/// of the specified block.
name|Value
modifier|*
name|GetValueAtEndOfBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// \brief Construct SSA form, materializing a value that is live in the
comment|/// middle of the specified block.
comment|///
comment|/// \c GetValueInMiddleOfBlock is the same as \c GetValueAtEndOfBlock except
comment|/// in one important case: if there is a definition of the rewritten value
comment|/// after the 'use' in BB.  Consider code like this:
comment|///
comment|/// \code
comment|///      X1 = ...
comment|///   SomeBB:
comment|///      use(X)
comment|///      X2 = ...
comment|///      br Cond, SomeBB, OutBB
comment|/// \endcode
comment|///
comment|/// In this case, there are two values (X1 and X2) added to the AvailableVals
comment|/// set by the client of the rewriter, and those values are both live out of
comment|/// their respective blocks.  However, the use of X happens in the *middle* of
comment|/// a block.  Because of this, we need to insert a new PHI node in SomeBB to
comment|/// merge the appropriate values, and this value isn't live out of the block.
name|Value
modifier|*
name|GetValueInMiddleOfBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// \brief Rewrite a use of the symbolic value.
comment|///
comment|/// This handles PHI nodes, which use their value in the corresponding
comment|/// predecessor. Note that this will not work if the use is supposed to be
comment|/// rewritten to a value defined in the same block as the use, but above it.
comment|/// Any 'AddAvailableValue's added for the use's block will be considered to
comment|/// be below it.
name|void
name|RewriteUse
parameter_list|(
name|Use
modifier|&
name|U
parameter_list|)
function_decl|;
comment|/// \brief Rewrite a use like \c RewriteUse but handling in-block definitions.
comment|///
comment|/// This version of the method can rewrite uses in the same block as
comment|/// a definition, because it assumes that all uses of a value are below any
comment|/// inserted values.
name|void
name|RewriteUseAfterInsertions
parameter_list|(
name|Use
modifier|&
name|U
parameter_list|)
function_decl|;
name|private
label|:
name|Value
modifier|*
name|GetValueAtEndOfBlockInternal
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Helper class for promoting a collection of loads and stores into SSA
comment|/// Form using the SSAUpdater.
comment|///
comment|/// This handles complexities that SSAUpdater doesn't, such as multiple loads
comment|/// and stores in one block.
comment|///
comment|/// Clients of this class are expected to subclass this and implement the
comment|/// virtual methods.
name|class
name|LoadAndStorePromoter
block|{
name|protected
label|:
name|SSAUpdater
modifier|&
name|SSA
decl_stmt|;
name|public
label|:
name|LoadAndStorePromoter
argument_list|(
argument|ArrayRef<const Instruction*> Insts
argument_list|,
argument|SSAUpdater&S
argument_list|,
argument|StringRef Name = StringRef()
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|LoadAndStorePromoter
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief This does the promotion.
comment|///
comment|/// Insts is a list of loads and stores to promote, and Name is the basename
comment|/// for the PHIs to insert. After this is complete, the loads and stores are
comment|/// removed from the code.
name|void
name|run
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Insts
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the specified instruction is in the Inst list.
comment|///
comment|/// The Insts list is the one passed into the constructor. Clients should
comment|/// implement this with a more efficient version if possible.
name|virtual
name|bool
name|isInstInList
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Insts
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief This hook is invoked after all the stores are found and inserted as
comment|/// available values.
name|virtual
name|void
name|doExtraRewritesBeforeFinalDeletion
argument_list|()
specifier|const
block|{   }
comment|/// \brief Clients can choose to implement this to get notified right before
comment|/// a load is RAUW'd another value.
name|virtual
name|void
name|replaceLoadWithValue
argument_list|(
argument|LoadInst *LI
argument_list|,
argument|Value *V
argument_list|)
specifier|const
block|{   }
comment|/// \brief Called before each instruction is deleted.
name|virtual
name|void
name|instructionDeleted
argument_list|(
argument|Instruction *I
argument_list|)
specifier|const
block|{   }
comment|/// \brief Called to update debug info associated with the instruction.
name|virtual
name|void
name|updateDebugInfo
argument_list|(
argument|Instruction *I
argument_list|)
specifier|const
block|{   }
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

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_SSAUPDATER_H
end_comment

end_unit

