begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsAsmPrinter.h - Mips LLVM Assembly Printer ----------*- C++ -*--===//
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
comment|// Mips Assembly printer class.
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
name|LLVM_LIB_TARGET_MIPS_MIPSASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"Mips16HardFloatInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsMCInstLower.h"
end_include

begin_include
include|#
directive|include
file|"MipsMachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
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

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MipsTargetStreamer
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MipsAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
name|MipsTargetStreamer
operator|&
name|getTargetStreamer
argument_list|()
specifier|const
block|;
name|void
name|EmitInstrWithMacroNoAT
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
comment|//===------------------------------------------------------------------===//
comment|// XRay implementation
comment|//===------------------------------------------------------------------===//
name|public
operator|:
comment|// XRay-specific lowering for Mips.
name|void
name|LowerPATCHABLE_FUNCTION_ENTER
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|void
name|LowerPATCHABLE_FUNCTION_EXIT
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|void
name|LowerPATCHABLE_TAIL_CALL
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
comment|// Helper function that emits the XRay sleds we've collected for a particular
comment|// function.
name|void
name|EmitXRayTable
argument_list|()
block|;
name|private
operator|:
name|void
name|EmitSled
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|SledKind Kind
argument_list|)
block|;
comment|// tblgen'erated function.
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
comment|// Emit PseudoReturn, PseudoReturn64, PseudoIndirectBranch,
comment|// and PseudoIndirectBranch64 as a JR, JR_MM, JALR, or JALR64 as appropriate
comment|// for the target.
name|void
name|emitPseudoIndirectBranch
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
name|std
operator|::
name|map
operator|<
specifier|const
name|char
operator|*
block|,
specifier|const
name|llvm
operator|::
name|Mips16HardFloatInfo
operator|::
name|FuncSignature
operator|*
operator|>
name|StubsNeeded
block|;
name|void
name|emitInlineAsmStart
argument_list|()
specifier|const
name|override
block|;
name|void
name|emitInlineAsmEnd
argument_list|(
argument|const MCSubtargetInfo&StartInfo
argument_list|,
argument|const MCSubtargetInfo *EndInfo
argument_list|)
specifier|const
name|override
block|;
name|void
name|EmitJal
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|void
name|EmitInstrReg
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg
argument_list|)
block|;
name|void
name|EmitInstrRegReg
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|unsigned Reg2
argument_list|)
block|;
name|void
name|EmitInstrRegRegReg
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|unsigned Reg2
argument_list|,
argument|unsigned Reg3
argument_list|)
block|;
name|void
name|EmitMovFPIntPair
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|unsigned MovOpc
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|unsigned Reg2
argument_list|,
argument|unsigned FPReg1
argument_list|,
argument|unsigned FPReg2
argument_list|,
argument|bool LE
argument_list|)
block|;
name|void
name|EmitSwapFPIntParams
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|Mips16HardFloatInfo::FPParamVariant
argument_list|,
argument|bool LE
argument_list|,
argument|bool ToFP
argument_list|)
block|;
name|void
name|EmitSwapFPIntRetval
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|,
argument|Mips16HardFloatInfo::FPReturnVariant
argument_list|,
argument|bool LE
argument_list|)
block|;
name|void
name|EmitFPCallStub
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|Mips16HardFloatInfo
operator|::
name|FuncSignature
operator|*
argument_list|)
block|;
name|void
name|NaClAlignIndirectJumpTargets
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|isLongBranchPseudo
argument_list|(
argument|int Opcode
argument_list|)
specifier|const
block|;
name|public
operator|:
specifier|const
name|MipsSubtarget
operator|*
name|Subtarget
block|;
specifier|const
name|MipsFunctionInfo
operator|*
name|MipsFI
block|;
name|MipsMCInstLower
name|MCInstLowering
block|;
name|explicit
name|MipsAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MCStreamer
operator|>
name|Streamer
argument_list|)
operator|:
name|AsmPrinter
argument_list|(
name|TM
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Streamer
argument_list|)
argument_list|)
block|,
name|MCP
argument_list|(
name|nullptr
argument_list|)
block|,
name|InConstantPool
argument_list|(
name|false
argument_list|)
block|,
name|MCInstLowering
argument_list|(
argument|*this
argument_list|)
block|{}
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Mips Assembly Printer"
return|;
block|}
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|void
name|EmitConstantPool
argument_list|()
name|override
block|{
name|bool
name|UsingConstantPools
operator|=
operator|(
name|Subtarget
operator|->
name|inMips16Mode
argument_list|()
operator|&&
name|Subtarget
operator|->
name|useConstantIslands
argument_list|()
operator|)
block|;
if|if
condition|(
operator|!
name|UsingConstantPools
condition|)
name|AsmPrinter
operator|::
name|EmitConstantPool
argument_list|()
expr_stmt|;
comment|// we emit constant pools customly!
block|}
name|void
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|printSavedRegsBitmask
argument_list|()
block|;
name|void
name|emitFrameDirective
argument_list|()
block|;
specifier|const
name|char
operator|*
name|getCurrentABIString
argument_list|()
specifier|const
block|;
name|void
name|EmitFunctionEntryLabel
argument_list|()
name|override
block|;
name|void
name|EmitFunctionBodyStart
argument_list|()
name|override
block|;
name|void
name|EmitFunctionBodyEnd
argument_list|()
name|override
block|;
name|void
name|EmitBasicBlockEnd
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
name|override
block|;
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock* MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
name|override
block|;
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
name|override
block|;
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printMemOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printMemOperandEA
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printFCCOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier = nullptr
argument_list|)
block|;
name|void
name|printRegisterList
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|EmitStartOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
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
name|void
name|EmitDebugThreadLocal
argument_list|(
argument|const MCExpr *Value
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

