begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCStreamer.h - High-level Streaming Machine Code Output --*- C++ -*-===//
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
comment|// This file declares the MCStreamer class.
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
name|LLVM_MC_MCSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
comment|/// MCStreamer - Streaming machine code generation interface.  This interface
comment|/// is intended to provide a programatic interface that is very similar to the
comment|/// level that an assembler .s file provides.  It has callbacks to emit bytes,
comment|/// handle directives, etc.  The implementation of this interface retains
comment|/// state to know what the current section is etc.
comment|///
comment|/// There are multiple implementations of this interface: one for writing out
comment|/// a .s file, and implementations that write out .o files of various formats.
comment|///
name|class
name|MCStreamer
block|{
name|MCContext
modifier|&
name|Context
decl_stmt|;
name|MCStreamer
argument_list|(
specifier|const
name|MCStreamer
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|MCStreamer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCStreamer
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
name|MCStreamer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
comment|/// CurSection - This is the current section code is being emitted to, it is
comment|/// kept up to date by SwitchSection.
specifier|const
name|MCSection
modifier|*
name|CurSection
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCStreamer
argument_list|()
expr_stmt|;
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
comment|/// @name Assembly File Formatting.
comment|/// @{
comment|/// isVerboseAsm - Return true if this streamer supports verbose assembly at
comment|/// all.
name|virtual
name|bool
name|isVerboseAsm
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// AddComment - Add a comment that can be emitted to the generated .s
comment|/// file if applicable as a QoI issue to make the output of the compiler
comment|/// more readable.  This only affects the MCAsmStreamer, and only when
comment|/// verbose assembly output is enabled.
comment|///
comment|/// If the comment includes embedded \n's, they will each get the comment
comment|/// prefix as appropriate.  The added comment should not end with a \n.
name|virtual
name|void
name|AddComment
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|)
block|{}
comment|/// GetCommentOS - Return a raw_ostream that comments can be written to.
comment|/// Unlike AddComment, you are required to terminate comments with \n if you
comment|/// use this method.
name|virtual
name|raw_ostream
modifier|&
name|GetCommentOS
parameter_list|()
function_decl|;
comment|/// AddBlankLine - Emit a blank line to a .s file to pretty it up.
name|virtual
name|void
name|AddBlankLine
parameter_list|()
block|{}
comment|/// @}
comment|/// @name Symbol& Section Management
comment|/// @{
comment|/// getCurrentSection - Return the current seciton that the streamer is
comment|/// emitting code to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
block|{
return|return
name|CurSection
return|;
block|}
comment|/// SwitchSection - Set the current section where code is being emitted to
comment|/// @p Section.  This is required to update CurSection.
comment|///
comment|/// This corresponds to assembler directives like .section, .text, etc.
name|virtual
name|void
name|SwitchSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitLabel - Emit a label for @p Symbol into the current section.
comment|///
comment|/// This corresponds to an assembler statement such as:
comment|///   foo:
comment|///
comment|/// @param Symbol - The symbol to emit. A given symbol should only be
comment|/// emitted as a label once, and symbols emitted as a label should never be
comment|/// used in an assignment.
name|virtual
name|void
name|EmitLabel
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitAssemblerFlag - Note in the output the specified @p Flag
name|virtual
name|void
name|EmitAssemblerFlag
parameter_list|(
name|MCAssemblerFlag
name|Flag
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitAssignment - Emit an assignment of @p Value to @p Symbol.
comment|///
comment|/// This corresponds to an assembler statement such as:
comment|///  symbol = value
comment|///
comment|/// The assignment generates no code, but has the side effect of binding the
comment|/// value in the current context. For the assembly streamer, this prints the
comment|/// binding into the .s file.
comment|///
comment|/// @param Symbol - The symbol being assigned to.
comment|/// @param Value - The value for the symbol.
name|virtual
name|void
name|EmitAssignment
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitSymbolAttribute - Add the given @p Attribute to @p Symbol.
name|virtual
name|void
name|EmitSymbolAttribute
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|MCSymbolAttr
name|Attribute
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitSymbolDesc - Set the @p DescValue for the @p Symbol.
comment|///
comment|/// @param Symbol - The symbol to have its n_desc field set.
comment|/// @param DescValue - The value to set into the n_desc field.
name|virtual
name|void
name|EmitSymbolDesc
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|unsigned
name|DescValue
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitELFSize - Emit an ELF .size directive.
comment|///
comment|/// This corresponds to an assembler statement such as:
comment|///  .size symbol, expression
comment|///
name|virtual
name|void
name|EmitELFSize
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitCommonSymbol - Emit a common symbol.
comment|///
comment|/// @param Symbol - The common symbol to emit.
comment|/// @param Size - The size of the common symbol.
comment|/// @param ByteAlignment - The alignment of the symbol if
comment|/// non-zero. This must be a power of 2.
name|virtual
name|void
name|EmitCommonSymbol
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|ByteAlignment
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitLocalCommonSymbol - Emit a local common (.lcomm) symbol.
comment|///
comment|/// @param Symbol - The common symbol to emit.
comment|/// @param Size - The size of the common symbol.
name|virtual
name|void
name|EmitLocalCommonSymbol
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitZerofill - Emit a the zerofill section and an option symbol.
comment|///
comment|/// @param Section - The zerofill section to create and or to put the symbol
comment|/// @param Symbol - The zerofill symbol to emit, if non-NULL.
comment|/// @param Size - The size of the zerofill symbol.
comment|/// @param ByteAlignment - The alignment of the zerofill symbol if
comment|/// non-zero. This must be a power of 2 on some targets.
name|virtual
name|void
name|EmitZerofill
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|,
name|MCSymbol
modifier|*
name|Symbol
init|=
literal|0
parameter_list|,
name|unsigned
name|Size
init|=
literal|0
parameter_list|,
name|unsigned
name|ByteAlignment
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @}
comment|/// @name Generating Data
comment|/// @{
comment|/// EmitBytes - Emit the bytes in \arg Data into the output.
comment|///
comment|/// This is used to implement assembler directives such as .byte, .ascii,
comment|/// etc.
name|virtual
name|void
name|EmitBytes
parameter_list|(
name|StringRef
name|Data
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitValue - Emit the expression @p Value into the output as a native
comment|/// integer of the given @p Size bytes.
comment|///
comment|/// This is used to implement assembler directives such as .word, .quad,
comment|/// etc.
comment|///
comment|/// @param Value - The value to emit.
comment|/// @param Size - The size of the integer (in bytes) to emit. This must
comment|/// match a native machine width.
name|virtual
name|void
name|EmitValue
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitIntValue - Special case of EmitValue that avoids the client having
comment|/// to pass in a MCExpr for constant integers.
name|virtual
name|void
name|EmitIntValue
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
comment|/// EmitGPRel32Value - Emit the expression @p Value into the output as a
comment|/// gprel32 (32-bit GP relative) value.
comment|///
comment|/// This is used to implement assembler directives such as .gprel32 on
comment|/// targets that support them.
name|virtual
name|void
name|EmitGPRel32Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitFill - Emit NumBytes bytes worth of the value specified by
comment|/// FillValue.  This implements directives such as '.space'.
name|virtual
name|void
name|EmitFill
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|,
name|uint8_t
name|FillValue
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
comment|/// EmitZeros - Emit NumBytes worth of zeros.  This is a convenience
comment|/// function that just wraps EmitFill.
name|void
name|EmitZeros
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
block|{
name|EmitFill
argument_list|(
name|NumBytes
argument_list|,
literal|0
argument_list|,
name|AddrSpace
argument_list|)
expr_stmt|;
block|}
comment|/// EmitValueToAlignment - Emit some number of copies of @p Value until
comment|/// the byte alignment @p ByteAlignment is reached.
comment|///
comment|/// If the number of bytes need to emit for the alignment is not a multiple
comment|/// of @p ValueSize, then the contents of the emitted fill bytes is
comment|/// undefined.
comment|///
comment|/// This used to implement the .align assembler directive.
comment|///
comment|/// @param ByteAlignment - The alignment to reach. This must be a power of
comment|/// two on some targets.
comment|/// @param Value - The value to use when filling bytes.
comment|/// @param ValueSize - The size of the integer (in bytes) to emit for
comment|/// @p Value. This must match a native machine width.
comment|/// @param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
comment|/// the alignment cannot be reached in this many bytes, no bytes are
comment|/// emitted.
name|virtual
name|void
name|EmitValueToAlignment
parameter_list|(
name|unsigned
name|ByteAlignment
parameter_list|,
name|int64_t
name|Value
init|=
literal|0
parameter_list|,
name|unsigned
name|ValueSize
init|=
literal|1
parameter_list|,
name|unsigned
name|MaxBytesToEmit
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitCodeAlignment - Emit nops until the byte alignment @p ByteAlignment
comment|/// is reached.
comment|///
comment|/// This used to align code where the alignment bytes may be executed.  This
comment|/// can emit different bytes for different sizes to optimize execution.
comment|///
comment|/// @param ByteAlignment - The alignment to reach. This must be a power of
comment|/// two on some targets.
comment|/// @param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
comment|/// the alignment cannot be reached in this many bytes, no bytes are
comment|/// emitted.
name|virtual
name|void
name|EmitCodeAlignment
parameter_list|(
name|unsigned
name|ByteAlignment
parameter_list|,
name|unsigned
name|MaxBytesToEmit
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitValueToOffset - Emit some number of copies of @p Value until the
comment|/// byte offset @p Offset is reached.
comment|///
comment|/// This is used to implement assembler directives such as .org.
comment|///
comment|/// @param Offset - The offset to reach. This may be an expression, but the
comment|/// expression must be associated with the current section.
comment|/// @param Value - The value to use when filling bytes.
name|virtual
name|void
name|EmitValueToOffset
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Offset
parameter_list|,
name|unsigned
name|char
name|Value
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @}
comment|/// EmitFileDirective - Switch to a new logical file.  This is used to
comment|/// implement the '.file "foo.c"' assembler directive.
name|virtual
name|void
name|EmitFileDirective
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitDwarfFileDirective - Associate a filename with a specified logical
comment|/// file number.  This implements the DWARF2 '.file 4 "foo.c"' assembler
comment|/// directive.
name|virtual
name|void
name|EmitDwarfFileDirective
parameter_list|(
name|unsigned
name|FileNo
parameter_list|,
name|StringRef
name|Filename
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitInstruction - Emit the given @p Instruction into the current
comment|/// section.
name|virtual
name|void
name|EmitInstruction
parameter_list|(
specifier|const
name|MCInst
modifier|&
name|Inst
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Finish - Finish emission of machine code and flush any output.
name|virtual
name|void
name|Finish
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// createNullStreamer - Create a dummy machine code streamer, which does
comment|/// nothing. This is useful for timing the assembler front end.
name|MCStreamer
modifier|*
name|createNullStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
comment|/// createAsmStreamer - Create a machine code streamer which will print out
comment|/// assembly for the native target, suitable for compiling with a native
comment|/// assembler.
comment|///
comment|/// \param InstPrint - If given, the instruction printer to use. If not given
comment|/// the MCInst representation will be printed.
comment|///
comment|/// \param CE - If given, a code emitter to use to show the instruction
comment|/// encoding inline with the assembly.
comment|///
comment|/// \param ShowInst - Whether to show the MCInst representation inline with
comment|/// the assembly.
name|MCStreamer
modifier|*
name|createAsmStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|formatted_raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
parameter_list|,
name|bool
name|isLittleEndian
parameter_list|,
name|bool
name|isVerboseAsm
parameter_list|,
name|MCInstPrinter
modifier|*
name|InstPrint
init|=
literal|0
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
init|=
literal|0
parameter_list|,
name|bool
name|ShowInst
init|=
name|false
parameter_list|)
function_decl|;
comment|// FIXME: These two may end up getting rolled into a single
comment|// createObjectStreamer interface, which implements the assembler backend, and
comment|// is parameterized on an output object file writer.
comment|/// createMachOStream - Create a machine code streamer which will generative
comment|/// Mach-O format object files.
name|MCStreamer
modifier|*
name|createMachOStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|)
function_decl|;
comment|/// createELFStreamer - Create a machine code streamer which will generative
comment|/// ELF format object files.
name|MCStreamer
modifier|*
name|createELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
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

