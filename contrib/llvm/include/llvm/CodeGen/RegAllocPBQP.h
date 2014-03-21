begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegAllocPBQP.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_CODEGEN_REGALLOCPBQP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGALLOCPBQP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PBQP/Graph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PBQP/Solution.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OwningPtr
expr_stmt|;
comment|/// This class wraps up a PBQP instance representing a register allocation
comment|/// problem, plus the structures necessary to map back from the PBQP solution
comment|/// to a register allocation solution. (i.e. The PBQP-node<--> vreg map,
comment|/// and the PBQP option<--> storage location map).
name|class
name|PBQPRAProblem
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|AllowedSet
expr_stmt|;
name|PBQP
operator|::
name|Graph
operator|&
name|getGraph
argument_list|()
block|{
return|return
name|graph
return|;
block|}
specifier|const
name|PBQP
operator|::
name|Graph
operator|&
name|getGraph
argument_list|()
specifier|const
block|{
return|return
name|graph
return|;
block|}
comment|/// Record the mapping between the given virtual register and PBQP node,
comment|/// and the set of allowed pregs for the vreg.
comment|///
comment|/// If you are extending
comment|/// PBQPBuilder you are unlikely to need this: Nodes and options for all
comment|/// vregs will already have been set up for you by the base class.
name|template
operator|<
name|typename
name|AllowedRegsItr
operator|>
name|void
name|recordVReg
argument_list|(
argument|unsigned vreg
argument_list|,
argument|PBQP::Graph::NodeId nodeId
argument_list|,
argument|AllowedRegsItr arBegin
argument_list|,
argument|AllowedRegsItr arEnd
argument_list|)
block|{
name|assert
argument_list|(
name|node2VReg
operator|.
name|find
argument_list|(
name|nodeId
argument_list|)
operator|==
name|node2VReg
operator|.
name|end
argument_list|()
operator|&&
literal|"Re-mapping node."
argument_list|)
block|;
name|assert
argument_list|(
name|vreg2Node
operator|.
name|find
argument_list|(
name|vreg
argument_list|)
operator|==
name|vreg2Node
operator|.
name|end
argument_list|()
operator|&&
literal|"Re-mapping vreg."
argument_list|)
block|;
name|assert
argument_list|(
name|allowedSets
index|[
name|vreg
index|]
operator|.
name|empty
argument_list|()
operator|&&
literal|"vreg already has pregs."
argument_list|)
block|;
name|node2VReg
index|[
name|nodeId
index|]
operator|=
name|vreg
block|;
name|vreg2Node
index|[
name|vreg
index|]
operator|=
name|nodeId
block|;
name|std
operator|::
name|copy
argument_list|(
name|arBegin
argument_list|,
name|arEnd
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|allowedSets
index|[
name|vreg
index|]
argument_list|)
argument_list|)
block|;     }
comment|/// Get the virtual register corresponding to the given PBQP node.
name|unsigned
name|getVRegForNode
argument_list|(
argument|PBQP::Graph::NodeId nodeId
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get the PBQP node corresponding to the given virtual register.
name|PBQP
operator|::
name|Graph
operator|::
name|NodeId
name|getNodeForVReg
argument_list|(
argument|unsigned vreg
argument_list|)
specifier|const
expr_stmt|;
comment|/// Returns true if the given PBQP option represents a physical register,
comment|/// false otherwise.
name|bool
name|isPRegOption
argument_list|(
name|unsigned
name|vreg
argument_list|,
name|unsigned
name|option
argument_list|)
decl|const
block|{
comment|// At present we only have spills or pregs, so anything that's not a
comment|// spill is a preg. (This might be extended one day to support remat).
return|return
operator|!
name|isSpillOption
argument_list|(
name|vreg
argument_list|,
name|option
argument_list|)
return|;
block|}
comment|/// Returns true if the given PBQP option represents spilling, false
comment|/// otherwise.
name|bool
name|isSpillOption
argument_list|(
name|unsigned
name|vreg
argument_list|,
name|unsigned
name|option
argument_list|)
decl|const
block|{
comment|// We hardcode option zero as the spill option.
return|return
name|option
operator|==
literal|0
return|;
block|}
comment|/// Returns the allowed set for the given virtual register.
specifier|const
name|AllowedSet
modifier|&
name|getAllowedSet
argument_list|(
name|unsigned
name|vreg
argument_list|)
decl|const
decl_stmt|;
comment|/// Get PReg for option.
name|unsigned
name|getPRegForOption
argument_list|(
name|unsigned
name|vreg
argument_list|,
name|unsigned
name|option
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|PBQP
operator|::
name|Graph
operator|::
name|NodeId
operator|,
name|unsigned
operator|>
name|Node2VReg
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|PBQP
operator|::
name|Graph
operator|::
name|NodeId
operator|>
name|VReg2Node
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|AllowedSet
operator|>
name|AllowedSetMap
expr_stmt|;
name|PBQP
operator|::
name|Graph
name|graph
expr_stmt|;
name|Node2VReg
name|node2VReg
decl_stmt|;
name|VReg2Node
name|vreg2Node
decl_stmt|;
name|AllowedSetMap
name|allowedSets
decl_stmt|;
block|}
empty_stmt|;
comment|/// Builds PBQP instances to represent register allocation problems. Includes
comment|/// spill, interference and coalescing costs by default. You can extend this
comment|/// class to support additional constraints for your architecture.
name|class
name|PBQPBuilder
block|{
name|private
label|:
name|PBQPBuilder
argument_list|(
argument|const PBQPBuilder&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|PBQPBuilder
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|set
operator|<
name|unsigned
operator|>
name|RegSet
expr_stmt|;
comment|/// Default constructor.
name|PBQPBuilder
argument_list|()
block|{}
comment|/// Clean up a PBQPBuilder.
name|virtual
operator|~
name|PBQPBuilder
argument_list|()
block|{}
comment|/// Build a PBQP instance to represent the register allocation problem for
comment|/// the given MachineFunction.
name|virtual
name|PBQPRAProblem
operator|*
name|build
argument_list|(
name|MachineFunction
operator|*
name|mf
argument_list|,
specifier|const
name|LiveIntervals
operator|*
name|lis
argument_list|,
specifier|const
name|MachineBlockFrequencyInfo
operator|*
name|mbfi
argument_list|,
specifier|const
name|RegSet
operator|&
name|vregs
argument_list|)
expr_stmt|;
name|private
label|:
name|void
name|addSpillCosts
argument_list|(
name|PBQP
operator|::
name|Vector
operator|&
name|costVec
argument_list|,
name|PBQP
operator|::
name|PBQPNum
name|spillCost
argument_list|)
decl_stmt|;
name|void
name|addInterferenceCosts
argument_list|(
name|PBQP
operator|::
name|Matrix
operator|&
name|costMat
argument_list|,
specifier|const
name|PBQPRAProblem
operator|::
name|AllowedSet
operator|&
name|vr1Allowed
argument_list|,
specifier|const
name|PBQPRAProblem
operator|::
name|AllowedSet
operator|&
name|vr2Allowed
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|tri
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Extended builder which adds coalescing constraints to a problem.
name|class
name|PBQPBuilderWithCoalescing
range|:
name|public
name|PBQPBuilder
block|{
name|public
operator|:
comment|/// Build a PBQP instance to represent the register allocation problem for
comment|/// the given MachineFunction.
name|virtual
name|PBQPRAProblem
operator|*
name|build
argument_list|(
name|MachineFunction
operator|*
name|mf
argument_list|,
specifier|const
name|LiveIntervals
operator|*
name|lis
argument_list|,
specifier|const
name|MachineBlockFrequencyInfo
operator|*
name|mbfi
argument_list|,
specifier|const
name|RegSet
operator|&
name|vregs
argument_list|)
block|;
name|private
operator|:
name|void
name|addPhysRegCoalesce
argument_list|(
argument|PBQP::Vector&costVec
argument_list|,
argument|unsigned pregOption
argument_list|,
argument|PBQP::PBQPNum benefit
argument_list|)
block|;
name|void
name|addVirtRegCoalesce
argument_list|(
argument|PBQP::Matrix&costMat
argument_list|,
argument|const PBQPRAProblem::AllowedSet&vr1Allowed
argument_list|,
argument|const PBQPRAProblem::AllowedSet&vr2Allowed
argument_list|,
argument|PBQP::PBQPNum benefit
argument_list|)
block|;   }
decl_stmt|;
name|FunctionPass
modifier|*
name|createPBQPRegisterAllocator
argument_list|(
name|OwningPtr
operator|<
name|PBQPBuilder
operator|>
operator|&
name|builder
argument_list|,
name|char
operator|*
name|customPassID
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CODEGEN_REGALLOCPBQP_H */
end_comment

end_unit

