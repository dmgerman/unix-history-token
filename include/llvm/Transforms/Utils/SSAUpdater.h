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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Use
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// SSAUpdater - This class updates SSA form for a set of values defined in
comment|/// multiple blocks.  This is used when code duplication or another unstructured
comment|/// transformation wants to rewrite a set of uses of one value with uses of a
comment|/// set of values.
name|class
name|SSAUpdater
block|{
comment|/// AvailableVals - This keeps track of which value to use on a per-block
comment|/// basis.  When we insert PHI nodes, we keep track of them here.  We use
comment|/// TrackingVH's for the value of the map because we RAUW PHI nodes when we
comment|/// eliminate them, and want the TrackingVH's to track this.
comment|//typedef DenseMap<BasicBlock*, TrackingVH<Value>> AvailableValsTy;
name|void
modifier|*
name|AV
decl_stmt|;
comment|/// PrototypeValue is an arbitrary representative value, which we derive names
comment|/// and a type for PHI nodes.
name|Value
modifier|*
name|PrototypeValue
decl_stmt|;
comment|/// IncomingPredInfo - We use this as scratch space when doing our recursive
comment|/// walk.  This should only be used in GetValueInBlockInternal, normally it
comment|/// should be empty.
comment|//std::vector<std::pair<BasicBlock*, TrackingVH<Value>>> IncomingPredInfo;
name|void
modifier|*
name|IPI
decl_stmt|;
comment|/// InsertedPHIs - If this is non-null, the SSAUpdater adds all PHI nodes that
comment|/// it creates to the vector.
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
comment|/// SSAUpdater constructor.  If InsertedPHIs is specified, it will be filled
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
literal|0
argument_list|)
decl_stmt|;
operator|~
name|SSAUpdater
argument_list|()
expr_stmt|;
comment|/// Initialize - Reset this object to get ready for a new set of SSA
comment|/// updates.  ProtoValue is the value used to name PHI nodes.
name|void
name|Initialize
parameter_list|(
name|Value
modifier|*
name|ProtoValue
parameter_list|)
function_decl|;
comment|/// AddAvailableValue - Indicate that a rewritten value is available at the
comment|/// end of the specified block with the specified value.
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
comment|/// HasValueForBlock - Return true if the SSAUpdater already has a value for
comment|/// the specified block.
name|bool
name|HasValueForBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// GetValueAtEndOfBlock - Construct SSA form, materializing a value that is
comment|/// live at the end of the specified block.
name|Value
modifier|*
name|GetValueAtEndOfBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// GetValueInMiddleOfBlock - Construct SSA form, materializing a value that
comment|/// is live in the middle of the specified block.
comment|///
comment|/// GetValueInMiddleOfBlock is the same as GetValueAtEndOfBlock except in one
comment|/// important case: if there is a definition of the rewritten value after the
comment|/// 'use' in BB.  Consider code like this:
comment|///
comment|///      X1 = ...
comment|///   SomeBB:
comment|///      use(X)
comment|///      X2 = ...
comment|///      br Cond, SomeBB, OutBB
comment|///
comment|/// In this case, there are two values (X1 and X2) added to the AvailableVals
comment|/// set by the client of the rewriter, and those values are both live out of
comment|/// their respective blocks.  However, the use of X happens in the *middle* of
comment|/// a block.  Because of this, we need to insert a new PHI node in SomeBB to
comment|/// merge the appropriate values, and this value isn't live out of the block.
comment|///
name|Value
modifier|*
name|GetValueInMiddleOfBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// RewriteUse - Rewrite a use of the symbolic value.  This handles PHI nodes,
comment|/// which use their value in the corresponding predecessor.  Note that this
comment|/// will not work if the use is supposed to be rewritten to a value defined in
comment|/// the same block as the use, but above it.  Any 'AddAvailableValue's added
comment|/// for the use's block will be considered to be below it.
name|void
name|RewriteUse
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
name|void
name|operator
init|=
operator|(
specifier|const
name|SSAUpdater
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|SSAUpdater
argument_list|(
specifier|const
name|SSAUpdater
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

