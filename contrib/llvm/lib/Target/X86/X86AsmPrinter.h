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
name|LLVM_LIB_TARGET_X86_X86ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"X86Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/StackMaps.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_comment
comment|// Implemented in X86MCInstLower.cpp
end_comment

begin_macro
name|namespace
end_macro

begin_block
block|{
name|class
name|X86MCInstLower
decl_stmt|;
block|}
end_block

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
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
name|void
name|GenerateExportDirective
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|bool IsData
argument_list|)
block|;
comment|// This utility class tracks the length of a stackmap instruction's 'shadow'.
comment|// It is used by the X86AsmPrinter to ensure that the stackmap shadow
comment|// invariants (i.e. no other stackmaps, patchpoints, or control flow within
comment|// the shadow) are met, while outputting a minimal number of NOPs for padding.
comment|//
comment|// To minimise the number of NOPs used, the shadow tracker counts the number
comment|// of instruction bytes output since the last stackmap. Only if there are too
comment|// few instruction bytes to cover the shadow are NOPs used for padding.
name|class
name|StackMapShadowTracker
block|{
name|public
operator|:
name|StackMapShadowTracker
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|StackMapShadowTracker
argument_list|()
block|;
name|void
name|startFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|count
argument_list|(
name|MCInst
operator|&
name|Inst
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
block|;
comment|// Called to signal the start of a shadow of RequiredSize bytes.
name|void
name|reset
argument_list|(
argument|unsigned RequiredSize
argument_list|)
block|{
name|RequiredShadowSize
operator|=
name|RequiredSize
block|;
name|CurrentShadowSize
operator|=
literal|0
block|;
name|InShadow
operator|=
name|true
block|;     }
comment|// Called before every stackmap/patchpoint, and at the end of basic blocks,
comment|// to emit any necessary padding-NOPs.
name|void
name|emitShadowPadding
argument_list|(
name|MCStreamer
operator|&
name|OutStreamer
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
block|;
name|private
operator|:
name|TargetMachine
operator|&
name|TM
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCCodeEmitter
operator|>
name|CodeEmitter
block|;
name|bool
name|InShadow
block|;
comment|// RequiredShadowSize holds the length of the shadow specified in the most
comment|// recently encountered STACKMAP instruction.
comment|// CurrentShadowSize counts the number of bytes encoded since the most
comment|// recently encountered STACKMAP, stopping when that number is greater than
comment|// or equal to RequiredShadowSize.
name|unsigned
name|RequiredShadowSize
block|,
name|CurrentShadowSize
block|;   }
block|;
name|StackMapShadowTracker
name|SMShadowTracker
block|;
comment|// All instructions emitted by the X86AsmPrinter should use this helper
comment|// method.
comment|//
comment|// This helper function invokes the SMShadowTracker on each instruction before
comment|// outputting it to the OutStream. This allows the shadow tracker to minimise
comment|// the number of NOPs used for stackmap padding.
name|void
name|EmitAndCountInstruction
argument_list|(
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
name|void
name|InsertStackMapShadows
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|LowerSTACKMAP
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|void
name|LowerPATCHPOINT
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|void
name|LowerTlsAddr
argument_list|(
name|X86MCInstLower
operator|&
name|MCInstLowering
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|MI
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
operator|*
name|this
argument_list|)
block|,
name|SMShadowTracker
argument_list|(
argument|TM
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
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
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
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|EmitBasicBlockEnd
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
name|override
block|{
name|SMShadowTracker
operator|.
name|emitShadowPadding
argument_list|(
name|OutStreamer
argument_list|,
name|getSubtargetInfo
argument_list|()
argument_list|)
block|;   }
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
name|override
block|;
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
name|override
block|;
comment|/// \brief Return the symbol for the specified constant pool entry.
name|MCSymbol
operator|*
name|GetCPISymbol
argument_list|(
argument|unsigned CPID
argument_list|)
specifier|const
name|override
block|;
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|{
name|SMShadowTracker
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
block|;
name|SM
operator|.
name|reset
argument_list|()
block|;
return|return
name|AsmPrinter
operator|::
name|doInitialization
argument_list|(
name|M
argument_list|)
return|;
block|}
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&F
argument_list|)
name|override
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

