begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- lib/CodeGen/DwarfPrinter.h - Dwarf Printer -------------*- C++ -*-===//
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
comment|// Emit general DWARF directives.
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
name|CODEGEN_ASMPRINTER_DWARFPRINTER_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFPRINTER_H__
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormattedStream.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|DwarfPrinter
block|{
name|protected
label|:
operator|~
name|DwarfPrinter
argument_list|()
block|{}
comment|//===-------------------------------------------------------------==---===//
comment|// Core attributes used by the DWARF printer.
comment|//
comment|/// O - Stream to .s file.
name|raw_ostream
operator|&
name|O
expr_stmt|;
comment|/// Asm - Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|/// MAI - Target asm information.
specifier|const
name|MCAsmInfo
modifier|*
name|MAI
decl_stmt|;
comment|/// TD - Target data.
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
comment|/// RI - Register Information.
specifier|const
name|TargetRegisterInfo
modifier|*
name|RI
decl_stmt|;
comment|/// M - Current module.
name|Module
modifier|*
name|M
decl_stmt|;
comment|/// MF - Current machine function.
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// MMI - Collected machine module information.
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
comment|/// SubprogramCount - The running count of functions being compiled.
name|unsigned
name|SubprogramCount
decl_stmt|;
name|DwarfPrinter
argument_list|(
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
expr_stmt|;
name|public
label|:
comment|//===------------------------------------------------------------------===//
comment|// Accessors.
comment|//
specifier|const
name|AsmPrinter
operator|*
name|getAsm
argument_list|()
specifier|const
block|{
return|return
name|Asm
return|;
block|}
name|MachineModuleInfo
operator|*
name|getMMI
argument_list|()
specifier|const
block|{
return|return
name|MMI
return|;
block|}
specifier|const
name|MCAsmInfo
operator|*
name|getMCAsmInfo
argument_list|()
specifier|const
block|{
return|return
name|MAI
return|;
block|}
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
comment|/// getDWLabel - Return the MCSymbol corresponding to the assembler temporary
comment|/// label with the specified stem and unique ID.
name|MCSymbol
modifier|*
name|getDWLabel
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
name|unsigned
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|/// getTempLabel - Return an assembler temporary label with the specified
comment|/// name.
name|MCSymbol
modifier|*
name|getTempLabel
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// SizeOfEncodedValue - Return the size of the encoding in bytes.
name|unsigned
name|SizeOfEncodedValue
argument_list|(
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitEncodingByte - Emit a .byte 42 directive that corresponds to an
comment|/// encoding.  If verbose assembly output is enabled, we output comments
comment|/// describing the encoding.  Desc is a string saying what the encoding is
comment|/// specifying (e.g. "LSDA").
name|void
name|EmitEncodingByte
parameter_list|(
name|unsigned
name|Val
parameter_list|,
specifier|const
name|char
modifier|*
name|Desc
parameter_list|)
function_decl|;
comment|/// EmitCFAByte - Emit a .byte 42 directive for a DW_CFA_xxx value.
name|void
name|EmitCFAByte
parameter_list|(
name|unsigned
name|Val
parameter_list|)
function_decl|;
comment|/// EmitSLEB128 - emit the specified signed leb128 value.
name|void
name|EmitSLEB128
argument_list|(
name|int
name|Value
argument_list|,
specifier|const
name|char
operator|*
name|Desc
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitULEB128 - emit the specified unsigned leb128 value.
name|void
name|EmitULEB128
argument_list|(
name|unsigned
name|Value
argument_list|,
specifier|const
name|char
operator|*
name|Desc
operator|=
literal|0
argument_list|,
name|unsigned
name|PadTo
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitReference - Emit a reference to a label.
comment|///
name|void
name|EmitReference
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
name|void
name|EmitReference
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitDifference - Emit the difference between two labels.
name|void
name|EmitDifference
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|LabelHi
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|LabelLo
parameter_list|,
name|bool
name|IsSmall
init|=
name|false
parameter_list|)
function_decl|;
comment|/// EmitSectionOffset - Emit Label-Section or use a special purpose directive
comment|/// to emit a section offset if the target has one.
name|void
name|EmitSectionOffset
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Section
parameter_list|,
name|bool
name|IsSmall
init|=
name|false
parameter_list|,
name|bool
name|isEH
init|=
name|false
parameter_list|)
function_decl|;
comment|/// EmitFrameMoves - Emit frame instructions to describe the layout of the
comment|/// frame.
name|void
name|EmitFrameMoves
argument_list|(
specifier|const
name|char
operator|*
name|BaseLabel
argument_list|,
name|unsigned
name|BaseLabelID
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
operator|&
name|Moves
argument_list|,
name|bool
name|isEH
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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

