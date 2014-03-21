begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86AsmPrinter.h - X86 implementation of AsmPrinter ------*- C++ -*-===//
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
name|X86ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|X86ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"X86.h"
end_include

begin_include
include|#
directive|include
file|"X86MachineFunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/StackMaps.h"
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
name|MCStreamer
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|X86AsmPrinter
range|:
name|public
name|AsmPrinter
block|{
specifier|const
name|X86Subtarget
operator|*
name|Subtarget
block|;
name|StackMaps
name|SM
block|;
comment|// Parses operands of PATCHPOINT and STACKMAP to produce stack map Location
comment|// structures. Returns a result location and an iterator to the operand
comment|// immediately following the operands consumed.
comment|//
comment|// This method is implemented in X86MCInstLower.cpp.
specifier|static
name|std
operator|::
name|pair
operator|<
name|StackMaps
operator|::
name|Location
block|,
name|MachineInstr
operator|::
name|const_mop_iterator
operator|>
name|stackmapOperandParser
argument_list|(
argument|MachineInstr::const_mop_iterator MOI
argument_list|,
argument|MachineInstr::const_mop_iterator MOE
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
name|public
operator|:
name|explicit
name|X86AsmPrinter
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
name|SM
argument_list|(
argument|*this
argument_list|,
argument|stackmapOperandParser
argument_list|)
block|{
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|X86Subtarget
operator|>
operator|(
operator|)
block|;   }
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
literal|"X86 Assembly / Object Emitter"
return|;
block|}
specifier|const
name|X86Subtarget
operator|&
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Subtarget
return|;
block|}
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
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|LLVM_OVERRIDE
block|;
name|void
name|printSymbolOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|raw_ostream
operator|&
name|O
argument_list|)
block|;
comment|// These methods are used by the tablegen'erated instruction printer.
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier =
literal|0
argument_list|,
argument|unsigned AsmVariant =
literal|0
argument_list|)
block|;
name|void
name|printPCRelImm
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|bool
name|printAsmMRegister
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|char Mode
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|virtual
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
argument|raw_ostream&OS
argument_list|)
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
name|LLVM_OVERRIDE
block|;
name|void
name|printMemReference
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier=NULL
argument_list|)
block|;
name|void
name|printLeaMemReference
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier=NULL
argument_list|)
block|;
name|void
name|printIntelMemReference
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier=NULL
argument_list|,
argument|unsigned AsmVariant =
literal|1
argument_list|)
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&F
argument_list|)
name|LLVM_OVERRIDE
block|; }
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

