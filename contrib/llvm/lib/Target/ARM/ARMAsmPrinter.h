begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMAsmPrinter.h - Print machine code to an ARM .s file ------------===//
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
comment|// ARM Assembly printer class.
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
name|ARMASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|ARMASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"ARMTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
enum|enum
name|DW_ISA
block|{
name|DW_ISA_ARM_thumb
init|=
literal|1
block|,
name|DW_ISA_ARM_arm
init|=
literal|2
block|}
enum|;
block|}
name|class
name|LLVM_LIBRARY_VISIBILITY
name|ARMAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
comment|/// Subtarget - Keep a pointer to the ARMSubtarget around so that we can
comment|/// make the right decision when printing asm code for different targets.
specifier|const
name|ARMSubtarget
operator|*
name|Subtarget
block|;
comment|/// AFI - Keep a pointer to ARMFunctionInfo for the current
comment|/// MachineFunction.
name|ARMFunctionInfo
operator|*
name|AFI
block|;
comment|/// MCP - Keep a pointer to constantpool entries of the current
comment|/// MachineFunction.
specifier|const
name|MachineConstantPool
operator|*
name|MCP
block|;
name|public
operator|:
name|explicit
name|ARMAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
operator|:
name|AsmPrinter
argument_list|(
name|TM
argument_list|,
name|Streamer
argument_list|)
block|,
name|AFI
argument_list|(
name|NULL
argument_list|)
block|,
name|MCP
argument_list|(
argument|NULL
argument_list|)
block|{
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|ARMSubtarget
operator|>
operator|(
operator|)
block|;     }
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"ARM Assembly Printer"
return|;
block|}
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int OpNum
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier =
literal|0
argument_list|)
block|;
name|virtual
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|virtual
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|EmitJumpTable
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|void
name|EmitJump2Table
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|virtual
name|void
name|EmitInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
block|;
name|virtual
name|void
name|EmitConstantPool
argument_list|()
block|{}
comment|// we emit constant pools customly!
name|virtual
name|void
name|EmitFunctionEntryLabel
argument_list|()
block|;
name|void
name|EmitStartOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitEndOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|// Helpers for EmitStartOfAsmFile() and EmitEndOfAsmFile()
name|void
name|emitAttributes
argument_list|()
block|;
comment|// Helper for ELF .o only
name|void
name|emitARMAttributeSection
argument_list|()
block|;
comment|// Generic helper used to emit e.g. ARMv5 mul pseudos
name|void
name|EmitPatchedInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned TargetOpc
argument_list|)
block|;
name|void
name|EmitUnwindingInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|public
operator|:
name|void
name|PrintDebugValueComment
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|MachineLocation
name|getDebugValueLocation
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// getDwarfRegOpSize - get size required to emit given machine location
comment|/// using dwarf encoding.
name|virtual
name|unsigned
name|getDwarfRegOpSize
argument_list|(
argument|const MachineLocation&MLoc
argument_list|)
specifier|const
block|;
comment|/// EmitDwarfRegOp - Emit dwarf register operation.
name|virtual
name|void
name|EmitDwarfRegOp
argument_list|(
argument|const MachineLocation&MLoc
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getISAEncoding
argument_list|()
block|{
comment|// ARM/Darwin adds ISA to the DWARF info for each function.
if|if
condition|(
operator|!
name|Subtarget
operator|->
name|isTargetDarwin
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|Subtarget
operator|->
name|isThumb
argument_list|()
condition|?
name|llvm
operator|::
name|ARM
operator|::
name|DW_ISA_ARM_thumb
else|:
name|llvm
operator|::
name|ARM
operator|::
name|DW_ISA_ARM_arm
return|;
block|}
name|MCSymbol
modifier|*
name|GetARMSetPICJumpTableLabel2
argument_list|(
name|unsigned
name|uid
argument_list|,
name|unsigned
name|uid2
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|GetARMJTIPICJumpTableLabel2
argument_list|(
name|unsigned
name|uid
argument_list|,
name|unsigned
name|uid2
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|GetARMSJLJEHLabel
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|GetARMGVSymbol
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// EmitMachineConstantPoolValue - Print a machine constantpool value to
comment|/// the .s file.
name|virtual
name|void
name|EmitMachineConstantPoolValue
parameter_list|(
name|MachineConstantPoolValue
modifier|*
name|MCPV
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

