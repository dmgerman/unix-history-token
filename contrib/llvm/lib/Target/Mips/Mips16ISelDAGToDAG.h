begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- Mips16ISelDAGToDAG.h - A Dag to Dag Inst Selector for Mips ------===//
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
comment|// Subclass of MipsDAGToDAGISel specialized for mips16.
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
name|LLVM_LIB_TARGET_MIPS_MIPS16ISELDAGTODAG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPS16ISELDAGTODAG_H
end_define

begin_include
include|#
directive|include
file|"MipsISelDAGToDAG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Mips16DAGToDAGISel
range|:
name|public
name|MipsDAGToDAGISel
block|{
name|public
operator|:
name|explicit
name|Mips16DAGToDAGISel
argument_list|(
argument|MipsTargetMachine&TM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
operator|:
name|MipsDAGToDAGISel
argument_list|(
argument|TM
argument_list|,
argument|OL
argument_list|)
block|{}
name|private
operator|:
name|std
operator|::
name|pair
operator|<
name|SDNode
operator|*
block|,
name|SDNode
operator|*
operator|>
name|selectMULT
argument_list|(
argument|SDNode *N
argument_list|,
argument|unsigned Opc
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|EVT Ty
argument_list|,
argument|bool HasLo
argument_list|,
argument|bool HasHi
argument_list|)
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|bool
name|selectAddr
argument_list|(
argument|bool SPAllowed
argument_list|,
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
block|;
name|bool
name|selectAddr16
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
name|override
block|;
name|bool
name|selectAddr16SP
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
name|override
block|;
name|bool
name|trySelect
argument_list|(
argument|SDNode *Node
argument_list|)
name|override
block|;
name|void
name|processFunctionAfterISel
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
comment|// Insert instructions to initialize the global base register in the
comment|// first MBB of the function.
name|void
name|initGlobalBaseReg
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|initMips16SPAliasReg
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|; }
decl_stmt|;
name|FunctionPass
modifier|*
name|createMips16ISelDag
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

