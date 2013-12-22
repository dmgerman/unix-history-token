begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMSelectionDAGInfo.h - ARM SelectionDAG Info -----------*- C++ -*-===//
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
comment|// This file defines the ARM subclass for TargetSelectionDAGInfo.
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
name|ARMSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMSELECTIONDAGINFO_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMAddressingModes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSelectionDAGInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM_AM
block|{
specifier|static
specifier|inline
name|ShiftOpc
name|getShiftOpcForNode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
default|default:
return|return
name|ARM_AM
operator|::
name|no_shift
return|;
case|case
name|ISD
operator|::
name|SHL
case|:
return|return
name|ARM_AM
operator|::
name|lsl
return|;
case|case
name|ISD
operator|::
name|SRL
case|:
return|return
name|ARM_AM
operator|::
name|lsr
return|;
case|case
name|ISD
operator|::
name|SRA
case|:
return|return
name|ARM_AM
operator|::
name|asr
return|;
case|case
name|ISD
operator|::
name|ROTR
case|:
return|return
name|ARM_AM
operator|::
name|ror
return|;
comment|//case ISD::ROTL:  // Only if imm -> turn into ROTR.
comment|// Can't handle RRX here, because it would require folding a flag into
comment|// the addressing mode.  :(  This causes us to miss certain things.
comment|//case ARMISD::RRX: return ARM_AM::rrx;
block|}
block|}
block|}
comment|// end namespace ARM_AM
name|class
name|ARMSelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
comment|/// Subtarget - Keep a pointer to the ARMSubtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|ARMSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|ARMSelectionDAGInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|ARMSelectionDAGInfo
argument_list|()
block|;
name|virtual
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dst
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool isVolatile
argument_list|,
argument|bool AlwaysInline
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
block|;
comment|// Adjust parameters for memset, see RTABI section 4.3.4
name|virtual
name|SDValue
name|EmitTargetCodeForMemset
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Op1
argument_list|,
argument|SDValue Op2
argument_list|,
argument|SDValue Op3
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool isVolatile
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

