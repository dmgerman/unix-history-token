begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RegAllocPBQP.h -------------------------------------------*- C++ -*-===//
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
comment|// This file defines the PBQPBuilder interface, for classes which build PBQP
end_comment

begin_comment
comment|// instances to represent register allocation problems, and the RegAllocPBQP
end_comment

begin_comment
comment|// interface.
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
name|LLVM_CODEGEN_PBQPRACONSTRAINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PBQPRACONSTRAINT_H
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PBQP
block|{
name|namespace
name|RegAlloc
block|{
comment|// Forward declare PBQP graph class.
name|class
name|PBQPRAGraph
decl_stmt|;
block|}
comment|// end namespace RegAlloc
block|}
comment|// end namespace PBQP
name|using
name|PBQPRAGraph
init|=
name|PBQP
operator|::
name|RegAlloc
operator|::
name|PBQPRAGraph
decl_stmt|;
comment|/// @brief Abstract base for classes implementing PBQP register allocation
comment|///        constraints (e.g. Spill-costs, interference, coalescing).
name|class
name|PBQPRAConstraint
block|{
name|public
label|:
name|virtual
operator|~
name|PBQPRAConstraint
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|apply
parameter_list|(
name|PBQPRAGraph
modifier|&
name|G
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// @brief PBQP register allocation constraint composer.
comment|///
comment|///   Constraints added to this list will be applied, in the order that they are
comment|/// added, to the PBQP graph.
name|class
name|PBQPRAConstraintList
range|:
name|public
name|PBQPRAConstraint
block|{
name|public
operator|:
name|void
name|apply
argument_list|(
argument|PBQPRAGraph&G
argument_list|)
name|override
block|{
for|for
control|(
name|auto
operator|&
name|C
operator|:
name|Constraints
control|)
name|C
operator|->
name|apply
argument_list|(
name|G
argument_list|)
expr_stmt|;
block|}
name|void
name|addConstraint
argument_list|(
argument|std::unique_ptr<PBQPRAConstraint> C
argument_list|)
block|{
if|if
condition|(
name|C
condition|)
name|Constraints
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|C
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PBQPRAConstraint
operator|>>
name|Constraints
block|;
name|void
name|anchor
argument_list|()
name|override
block|; }
decl_stmt|;
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
comment|// LLVM_CODEGEN_PBQPRACONSTRAINT_H
end_comment

end_unit

