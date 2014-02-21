begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMAsmPrinter.h - ARM implementation of AsmPrinter ------*- C++ -*-===//
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
name|class
name|MCOperand
decl_stmt|;
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
comment|/// InConstantPool - Maintain state when emitting a sequence of constant
comment|/// pool entries so we can properly mark them as data regions.
name|bool
name|InConstantPool
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
name|NULL
argument_list|)
block|,
name|InConstantPool
argument_list|(
argument|false
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
name|LLVM_OVERRIDE
block|{
return|return
literal|"ARM Assembly / Object Emitter"
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
name|LLVM_OVERRIDE
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
name|LLVM_OVERRIDE
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
argument|const MachineInstr *MI
argument_list|)
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&F
argument_list|)
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|EmitConstantPool
argument_list|()
name|LLVM_OVERRIDE
block|{
comment|// we emit constant pools customly!
block|}
name|virtual
name|void
name|EmitFunctionBodyEnd
argument_list|()
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|EmitFunctionEntryLabel
argument_list|()
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|EmitStartOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|LLVM_OVERRIDE
block|;
name|virtual
name|void
name|EmitXXStructor
argument_list|(
argument|const Constant *CV
argument_list|)
name|LLVM_OVERRIDE
block|;
comment|// lowerOperand - Convert a MachineOperand into the equivalent MCOperand.
name|bool
name|lowerOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|MCOperand
operator|&
name|MCOp
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
comment|// emitPseudoExpansionLowering - tblgen'erated.
name|bool
name|emitPseudoExpansionLowering
argument_list|(
name|MCStreamer
operator|&
name|OutStreamer
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|public
operator|:
comment|/// EmitDwarfRegOp - Emit dwarf register operation.
name|virtual
name|void
name|EmitDwarfRegOp
argument_list|(
argument|const MachineLocation&MLoc
argument_list|,
argument|bool Indirect
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|unsigned
name|getISAEncoding
argument_list|()
name|LLVM_OVERRIDE
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
name|ARM
operator|::
name|DW_ISA_ARM_thumb
else|:
name|ARM
operator|::
name|DW_ISA_ARM_arm
return|;
block|}
name|private
label|:
name|MCOperand
name|GetSymbolRef
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
function_decl|;
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
operator|*
name|GetARMSJLJEHLabel
argument_list|()
specifier|const
expr_stmt|;
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
name|public
label|:
comment|/// EmitMachineConstantPoolValue - Print a machine constantpool value to
comment|/// the .s file.
name|virtual
name|void
name|EmitMachineConstantPoolValue
argument_list|(
name|MachineConstantPoolValue
operator|*
name|MCPV
argument_list|)
name|LLVM_OVERRIDE
decl_stmt|;
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

