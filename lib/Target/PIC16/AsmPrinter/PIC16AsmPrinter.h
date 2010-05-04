begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16AsmPrinter.h - PIC16 LLVM assembly writer ----------*- C++ -*-===//
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
comment|// This file contains a printer that converts from our internal representation
end_comment

begin_comment
comment|// of machine-dependent LLVM code to PIC16 assembly language.
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
name|PIC16ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"PIC16.h"
end_include

begin_include
include|#
directive|include
file|"PIC16TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"PIC16DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"PIC16MCAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"PIC16TargetObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|VISIBILITY_HIDDEN
name|PIC16AsmPrinter
range|:
name|public
name|AsmPrinter
block|{
name|public
operator|:
name|explicit
name|PIC16AsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
block|;
name|private
operator|:
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"PIC16 Assembly Printer"
return|;
block|}
specifier|const
name|PIC16TargetObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
block|{
return|return
operator|(
specifier|const
name|PIC16TargetObjectFile
operator|&
operator|)
name|AsmPrinter
operator|::
name|getObjFileLowering
argument_list|()
return|;
block|}
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
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
name|printCCOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|raw_ostream
operator|&
name|O
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|getRegisterName
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|void
name|EmitInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|void
name|EmitFunctionDecls
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitUndefinedVars
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitDefinedVars
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitIData
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitUData
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitAllAutos
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitRomData
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitSharedUdata
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitUserSections
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitFunctionFrame
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|printLibcallDecls
argument_list|()
block|;
name|void
name|EmitUninitializedDataSection
argument_list|(
specifier|const
name|PIC16Section
operator|*
name|S
argument_list|)
block|;
name|void
name|EmitInitializedDataSection
argument_list|(
specifier|const
name|PIC16Section
operator|*
name|S
argument_list|)
block|;
name|void
name|EmitSingleSection
argument_list|(
specifier|const
name|PIC16Section
operator|*
name|S
argument_list|)
block|;
name|void
name|EmitSectionList
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|SList
argument_list|)
block|;
name|void
name|ColorAutoSection
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;
name|protected
operator|:
name|bool
name|doInitialization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// EmitGlobalVariable - Emit the specified global variable and its
comment|/// initializer to the output stream.
name|virtual
name|void
name|EmitGlobalVariable
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
block|{
comment|// PIC16 doesn't use normal hooks for this.
block|}
name|private
operator|:
specifier|const
name|PIC16TargetObjectFile
operator|*
name|PTOF
block|;
name|PIC16DbgInfo
name|DbgInfo
block|;
specifier|const
name|PIC16MCAsmInfo
operator|*
name|PMAI
block|;
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|LibcallDecls
block|;
comment|// Sorted& uniqued set of extern decls.
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|ExternalVarDecls
block|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|ExternalVarDefs
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end of namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

