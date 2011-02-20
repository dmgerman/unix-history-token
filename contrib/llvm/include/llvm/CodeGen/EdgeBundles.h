begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- EdgeBundles.h - Bundles of CFG edges --------------*- c++ -*-===//
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
comment|// The EdgeBundles analysis forms equivalence classes of CFG edges such that all
end_comment

begin_comment
comment|// edges leaving a machine basic block are in the same bundle, and all edges
end_comment

begin_comment
comment|// leaving a basic block are in the same bundle.
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
name|LLVM_CODEGEN_EDGEBUNDLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_EDGEBUNDLES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntEqClasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|EdgeBundles
range|:
name|public
name|MachineFunctionPass
block|{
specifier|const
name|MachineFunction
operator|*
name|MF
block|;
comment|/// EC - Each edge bundle is an equivalence class. The keys are:
comment|///   2*BB->getNumber()   -> Ingoing bundle.
comment|///   2*BB->getNumber()+1 -> Outgoing bundle.
name|IntEqClasses
name|EC
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|EdgeBundles
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{}
comment|/// getBundle - Return the ingoing (Out = false) or outgoing (Out = true)
comment|/// bundle number for basic block #N
name|unsigned
name|getBundle
argument_list|(
argument|unsigned N
argument_list|,
argument|bool Out
argument_list|)
specifier|const
block|{
return|return
name|EC
index|[
literal|2
operator|*
name|N
operator|+
name|Out
index|]
return|;
block|}
comment|/// getNumBundles - Return the total number of bundles in the CFG.
name|unsigned
name|getNumBundles
argument_list|()
specifier|const
block|{
return|return
name|EC
operator|.
name|getNumClasses
argument_list|()
return|;
block|}
comment|/// getMachineFunction - Return the last machine function computed.
specifier|const
name|MachineFunction
operator|*
name|getMachineFunction
argument_list|()
specifier|const
block|{
return|return
name|MF
return|;
block|}
comment|/// view - Visualize the annotated bipartite CFG with Graphviz.
name|void
name|view
argument_list|()
specifier|const
block|;
name|private
operator|:
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// Specialize WriteGraph, the standard implementation won't work.
name|raw_ostream
modifier|&
name|WriteGraph
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|EdgeBundles
operator|&
name|G
argument_list|,
name|bool
name|ShortNames
operator|=
name|false
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Title
operator|=
literal|""
argument_list|)
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

end_unit

