begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfWriter.h - Dwarf Framework ------------*- C++ -*-===//
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
comment|// This file contains support for writing Dwarf debug and exception info into
end_comment

begin_comment
comment|// asm files.  For Details on the Dwarf 3 specfication see DWARF Debugging
end_comment

begin_comment
comment|// Information Format V.3 reference manual http://dwarf.freestandards.org ,
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The role of the Dwarf Writer class is to extract information from the
end_comment

begin_comment
comment|// MachineModuleInfo object, organize it in Dwarf form and then emit it into asm
end_comment

begin_comment
comment|// the current asm file using data and high level Dwarf directives.
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
name|LLVM_CODEGEN_DWARFWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_DWARFWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
name|AsmPrinter
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|DwarfException
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DICompileUnit
decl_stmt|;
name|class
name|DISubprogram
decl_stmt|;
name|class
name|DIVariable
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// DwarfWriter - Emits Dwarf debug and exception handling directives.
comment|//
name|class
name|DwarfWriter
range|:
name|public
name|ImmutablePass
block|{
name|private
operator|:
comment|/// DD - Provides the DwarfWriter debug implementation.
comment|///
name|DwarfDebug
operator|*
name|DD
block|;
comment|/// DE - Provides the DwarfWriter exception implementation.
comment|///
name|DwarfException
operator|*
name|DE
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|DwarfWriter
argument_list|()
block|;
name|virtual
operator|~
name|DwarfWriter
argument_list|()
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
comment|/// BeginModule - Emit all Dwarf sections that should come prior to the
comment|/// content.
name|void
name|BeginModule
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|MachineModuleInfo
operator|*
name|MMI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
name|AsmPrinter
operator|*
name|A
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|T
argument_list|)
block|;
comment|/// EndModule - Emit all Dwarf sections that should come after the content.
comment|///
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function debug information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|BeginFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function debug information.
comment|///
name|void
name|EndFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// RecordSourceLine - Register a source line with debug info. Returns a
comment|/// unique label ID used to generate a label and provide correspondence to
comment|/// the source line list.
name|unsigned
name|RecordSourceLine
argument_list|(
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|,
argument|MDNode *Scope
argument_list|)
block|;
comment|/// getRecordSourceLineCount - Count source lines.
name|unsigned
name|getRecordSourceLineCount
argument_list|()
block|;
comment|/// ShouldEmitDwarfDebug - Returns true if Dwarf debugging declarations should
comment|/// be emitted.
name|bool
name|ShouldEmitDwarfDebug
argument_list|()
specifier|const
block|;
name|void
name|BeginScope
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Label
argument_list|)
block|;
name|void
name|EndScope
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

