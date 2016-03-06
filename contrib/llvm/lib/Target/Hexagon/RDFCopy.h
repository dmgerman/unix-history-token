begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RDFCopy.h --------------------------------------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|RDF_COPY_H
end_ifndef

begin_define
define|#
directive|define
name|RDF_COPY_H
end_define

begin_include
include|#
directive|include
file|"RDFGraph.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|rdf
block|{
struct|struct
name|CopyPropagation
block|{
name|CopyPropagation
argument_list|(
name|DataFlowGraph
operator|&
name|dfg
argument_list|)
operator|:
name|MDT
argument_list|(
name|dfg
operator|.
name|getDT
argument_list|()
argument_list|)
operator|,
name|DFG
argument_list|(
name|dfg
argument_list|)
operator|,
name|Trace
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|run
argument_list|()
expr_stmt|;
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
name|private
label|:
specifier|const
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
name|DataFlowGraph
modifier|&
name|DFG
decl_stmt|;
name|DataFlowGraph
operator|::
name|DefStackMap
name|DefM
expr_stmt|;
name|bool
name|Trace
decl_stmt|;
comment|// map: register -> (map: stmt -> reaching def)
name|std
operator|::
name|map
operator|<
name|RegisterRef
operator|,
name|std
operator|::
name|map
operator|<
name|NodeId
operator|,
name|NodeId
operator|>>
name|RDefMap
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|NodeId
operator|>
name|Copies
expr_stmt|;
name|void
name|recordCopy
argument_list|(
name|NodeAddr
operator|<
name|StmtNode
operator|*
operator|>
name|SA
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|)
decl_stmt|;
name|void
name|updateMap
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|)
decl_stmt|;
name|bool
name|scanBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|B
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

