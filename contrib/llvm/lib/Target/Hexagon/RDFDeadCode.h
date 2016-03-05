begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RDFDeadCode.h ----------------------------------------------------===//
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
comment|// RDF-based generic dead code elimination.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The main interface of this class are functions "collect" and "erase".
end_comment

begin_comment
comment|// This allows custom processing of the function being optimized by a
end_comment

begin_comment
comment|// particular consumer. The simplest way to use this class would be to
end_comment

begin_comment
comment|// instantiate an object, and then simply call "collect" and "erase",
end_comment

begin_comment
comment|// passing the result of "getDeadInstrs()" to it.
end_comment

begin_comment
comment|// A more complex scenario would be to call "collect" first, then visit
end_comment

begin_comment
comment|// all post-increment instructions to see if the address update is dead
end_comment

begin_comment
comment|// or not, and if it is, convert the instruction to a non-updating form.
end_comment

begin_comment
comment|// After that "erase" can be called with the set of nodes including both,
end_comment

begin_comment
comment|// dead defs from the updating instructions and the nodes corresponding
end_comment

begin_comment
comment|// to the dead instructions.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RDF_DEADCODE_H
end_ifndef

begin_define
define|#
directive|define
name|RDF_DEADCODE_H
end_define

begin_include
include|#
directive|include
file|"RDFGraph.h"
end_include

begin_include
include|#
directive|include
file|"RDFLiveness.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineRegisterInfo
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|rdf
block|{
struct|struct
name|DeadCodeElimination
block|{
name|DeadCodeElimination
argument_list|(
name|DataFlowGraph
operator|&
name|dfg
argument_list|,
name|MachineRegisterInfo
operator|&
name|mri
argument_list|)
operator|:
name|Trace
argument_list|(
name|false
argument_list|)
operator|,
name|DFG
argument_list|(
name|dfg
argument_list|)
operator|,
name|MRI
argument_list|(
name|mri
argument_list|)
operator|,
name|LV
argument_list|(
argument|mri
argument_list|,
argument|dfg
argument_list|)
block|{}
name|bool
name|collect
argument_list|()
expr_stmt|;
name|bool
name|erase
argument_list|(
specifier|const
name|SetVector
operator|<
name|NodeId
operator|>
operator|&
name|Nodes
argument_list|)
decl_stmt|;
name|void
name|trace
parameter_list|(
name|bool
name|On
parameter_list|)
block|{
name|Trace
operator|=
name|On
expr_stmt|;
block|}
name|bool
name|trace
argument_list|()
specifier|const
block|{
return|return
name|Trace
return|;
block|}
name|SetVector
operator|<
name|NodeId
operator|>
name|getDeadNodes
argument_list|()
block|{
return|return
name|DeadNodes
return|;
block|}
name|SetVector
operator|<
name|NodeId
operator|>
name|getDeadInstrs
argument_list|()
block|{
return|return
name|DeadInstrs
return|;
block|}
name|DataFlowGraph
modifier|&
name|getDFG
parameter_list|()
block|{
return|return
name|DFG
return|;
block|}
name|private
label|:
name|bool
name|Trace
decl_stmt|;
name|SetVector
operator|<
name|NodeId
operator|>
name|LiveNodes
expr_stmt|;
name|SetVector
operator|<
name|NodeId
operator|>
name|DeadNodes
expr_stmt|;
name|SetVector
operator|<
name|NodeId
operator|>
name|DeadInstrs
expr_stmt|;
name|DataFlowGraph
modifier|&
name|DFG
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
name|Liveness
name|LV
decl_stmt|;
name|bool
name|isLiveInstr
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
name|void
name|scanInstr
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|SetVector
operator|<
name|NodeId
operator|>
operator|&
name|WorkQ
argument_list|)
decl_stmt|;
name|void
name|processDef
argument_list|(
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|DA
argument_list|,
name|SetVector
operator|<
name|NodeId
operator|>
operator|&
name|WorkQ
argument_list|)
decl_stmt|;
name|void
name|processUse
argument_list|(
name|NodeAddr
operator|<
name|UseNode
operator|*
operator|>
name|UA
argument_list|,
name|SetVector
operator|<
name|NodeId
operator|>
operator|&
name|WorkQ
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

