begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// WebAssemblyAsmPrinter.h - WebAssembly implementation of AsmPrinter-*- C++ -*-
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"WebAssemblySubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
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
name|MCSymbol
decl_stmt|;
name|class
name|WebAssemblyFunctionInfo
decl_stmt|;
name|class
name|WebAssemblyTargetStreamer
decl_stmt|;
name|class
name|WebAssemblyMCInstLower
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|WebAssemblyAsmPrinter
name|final
range|:
name|public
name|AsmPrinter
block|{
specifier|const
name|WebAssemblySubtarget
operator|*
name|Subtarget
block|;
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
block|;
name|WebAssemblyFunctionInfo
operator|*
name|MFI
block|;
name|public
operator|:
name|explicit
name|WebAssemblyAsmPrinter
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
name|Subtarget
argument_list|(
name|nullptr
argument_list|)
block|,
name|MRI
argument_list|(
name|nullptr
argument_list|)
block|,
name|MFI
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"WebAssembly Assembly Printer"
return|;
block|}
specifier|const
name|WebAssemblySubtarget
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
comment|//===------------------------------------------------------------------===//
comment|// MachineFunctionPass Implementation.
comment|//===------------------------------------------------------------------===//
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|{
name|Subtarget
operator|=
operator|&
name|MF
operator|.
name|getSubtarget
operator|<
name|WebAssemblySubtarget
operator|>
operator|(
operator|)
block|;
name|MRI
operator|=
operator|&
name|MF
operator|.
name|getRegInfo
argument_list|()
block|;
name|MFI
operator|=
name|MF
operator|.
name|getInfo
operator|<
name|WebAssemblyFunctionInfo
operator|>
operator|(
operator|)
block|;
return|return
name|AsmPrinter
operator|::
name|runOnMachineFunction
argument_list|(
name|MF
argument_list|)
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// AsmPrinter Implementation.
comment|//===------------------------------------------------------------------===//
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|void
name|EmitJumpTableInfo
argument_list|()
name|override
block|;
name|void
name|EmitConstantPool
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
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
specifier|const
name|MCExpr
operator|*
name|lowerConstant
argument_list|(
argument|const Constant *CV
argument_list|)
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
name|MVT
name|getRegType
argument_list|(
argument|unsigned RegNo
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|regToString
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
block|;
name|WebAssemblyTargetStreamer
operator|*
name|getTargetStreamer
argument_list|()
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

