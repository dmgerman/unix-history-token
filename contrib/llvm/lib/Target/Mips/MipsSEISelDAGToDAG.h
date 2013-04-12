begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSEISelDAGToDAG.h - A Dag to Dag Inst Selector for MipsSE -----===//
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
comment|// Subclass of MipsDAGToDAGISel specialized for mips32/64.
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
name|MIPSSEISELDAGTODAG_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSSEISELDAGTODAG_H
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
name|MipsSEDAGToDAGISel
range|:
name|public
name|MipsDAGToDAGISel
block|{
name|public
operator|:
name|explicit
name|MipsSEDAGToDAGISel
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|MipsDAGToDAGISel
argument_list|(
argument|TM
argument_list|)
block|{}
name|private
operator|:
name|bool
name|replaceUsesWithZeroReg
argument_list|(
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|,
specifier|const
name|MachineInstr
operator|&
argument_list|)
block|;
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
argument|DebugLoc dl
argument_list|,
argument|EVT Ty
argument_list|,
argument|bool HasLo
argument_list|,
argument|bool HasHi
argument_list|)
block|;
name|SDNode
operator|*
name|selectAddESubE
argument_list|(
argument|unsigned MOp
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|SDValue CmpLHS
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|selectAddrRegImm
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|selectAddrDefault
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|selectIntAddr
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|bool
block|,
name|SDNode
operator|*
operator|>
name|selectNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|)
block|;
name|virtual
name|void
name|processFunctionAfterISel
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
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
block|; }
decl_stmt|;
name|FunctionPass
modifier|*
name|createMipsSEISelDag
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

