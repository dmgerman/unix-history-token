begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachineSSAUpdater.h - Unstructured SSA Update Tool ------*- C++ -*-===//
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
comment|// This file declares the MachineSSAUpdater class.
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
name|LLVM_CODEGEN_MACHINESSAUPDATER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINESSAUPDATER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// MachineSSAUpdater - This class updates SSA form for a set of virtual
comment|/// registers defined in multiple blocks.  This is used when code duplication
comment|/// or another unstructured transformation wants to rewrite a set of uses of one
comment|/// vreg with uses of a set of vregs.
name|class
name|MachineSSAUpdater
block|{
comment|/// AvailableVals - This keeps track of which value to use on a per-block
comment|/// basis.  When we insert PHI nodes, we keep track of them here.
comment|//typedef DenseMap<MachineBasicBlock*, unsigned> AvailableValsTy;
name|void
modifier|*
name|AV
decl_stmt|;
comment|/// IncomingPredInfo - We use this as scratch space when doing our recursive
comment|/// walk.  This should only be used in GetValueInBlockInternal, normally it
comment|/// should be empty.
comment|//std::vector<std::pair<MachineBasicBlock*, unsigned>> IncomingPredInfo;
name|void
modifier|*
name|IPI
decl_stmt|;
comment|/// VR - Current virtual register whose uses are being updated.
name|unsigned
name|VR
decl_stmt|;
comment|/// VRC - Register class of the current virtual register.
specifier|const
name|TargetRegisterClass
modifier|*
name|VRC
decl_stmt|;
comment|/// InsertedPHIs - If this is non-null, the MachineSSAUpdater adds all PHI
comment|/// nodes that it creates to the vector.
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|*
name|InsertedPHIs
expr_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
name|public
label|:
comment|/// MachineSSAUpdater constructor.  If InsertedPHIs is specified, it will be
comment|/// filled in with all PHI Nodes created by rewriting.
name|explicit
name|MachineSSAUpdater
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|*
name|InsertedPHIs
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|MachineSSAUpdater
argument_list|()
expr_stmt|;
comment|/// Initialize - Reset this object to get ready for a new set of SSA
comment|/// updates.
name|void
name|Initialize
parameter_list|(
name|unsigned
name|V
parameter_list|)
function_decl|;
comment|/// AddAvailableValue - Indicate that a rewritten value is available at the
comment|/// end of the specified block with the specified value.
name|void
name|AddAvailableValue
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|,
name|unsigned
name|V
parameter_list|)
function_decl|;
comment|/// HasValueForBlock - Return true if the MachineSSAUpdater already has a
comment|/// value for the specified block.
name|bool
name|HasValueForBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// GetValueAtEndOfBlock - Construct SSA form, materializing a value that is
comment|/// live at the end of the specified block.
name|unsigned
name|GetValueAtEndOfBlock
parameter_list|(
name|MachineBasicBlock
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
name|unsigned
name|GetValueInMiddleOfBlock
parameter_list|(
name|MachineBasicBlock
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
name|MachineOperand
modifier|&
name|U
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|ReplaceRegWith
parameter_list|(
name|unsigned
name|OldReg
parameter_list|,
name|unsigned
name|NewReg
parameter_list|)
function_decl|;
name|unsigned
name|GetValueAtEndOfBlockInternal
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MachineSSAUpdater
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|MachineSSAUpdater
argument_list|(
specifier|const
name|MachineSSAUpdater
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

