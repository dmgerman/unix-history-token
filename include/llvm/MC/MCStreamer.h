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
name|raw_ostream
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
name|public
label|:
enum|enum
name|SymbolAttr
block|{
name|Global
block|,
comment|/// .globl
name|Hidden
block|,
comment|/// .hidden (ELF)
name|IndirectSymbol
block|,
comment|/// .indirect_symbol (Apple)
name|Internal
block|,
comment|/// .internal (ELF)
name|LazyReference
block|,
comment|/// .lazy_reference (Apple)
name|NoDeadStrip
block|,
comment|/// .no_dead_strip (Apple)
name|PrivateExtern
block|,
comment|/// .private_extern (Apple)
name|Protected
block|,
comment|/// .protected (ELF)
name|Reference
block|,
comment|/// .reference (Apple)
name|Weak
block|,
comment|/// .weak
name|WeakDefinition
block|,
comment|/// .weak_definition (Apple)
name|WeakReference
block|,
comment|/// .weak_reference (Apple)
name|SymbolAttrFirst
init|=
name|Global
block|,
name|SymbolAttrLast
init|=
name|WeakReference
block|}
enum|;
enum|enum
name|AssemblerFlag
block|{
name|SubsectionsViaSymbols
comment|/// .subsections_via_symbols (Apple)
block|}
enum|;
name|private
label|:
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
comment|/// @param Section.  This is required to update CurSection.
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
comment|/// EmitLabel - Emit a label for @param Symbol into the current section.
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
comment|/// EmitAssemblerFlag - Note in the output the specified @param Flag
name|virtual
name|void
name|EmitAssemblerFlag
parameter_list|(
name|AssemblerFlag
name|Flag
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitAssignment - Emit an assignment of @param Value to @param Symbol.
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
comment|/// EmitSymbolAttribute - Add the given @param Attribute to @param Symbol.
name|virtual
name|void
name|EmitSymbolAttribute
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|SymbolAttr
name|Attribute
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitSymbolDesc - Set the @param DescValue for the @param Symbol.
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
comment|/// EmitCommonSymbol - Emit a common or local common symbol.
comment|///
comment|/// @param Symbol - The common symbol to emit.
comment|/// @param Size - The size of the common symbol.
comment|/// @param ByteAlignment - The alignment of the symbol if
comment|/// non-zero. This must be a power of 2 on some targets.
name|virtual
name|void
name|EmitCommonSymbol
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|ByteAlignment
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
specifier|const
name|StringRef
modifier|&
name|Data
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitValue - Emit the expression @param Value into the output as a native
comment|/// integer of the given @param Size bytes.
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
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// EmitValueToAlignment - Emit some number of copies of @param Value until
comment|/// the byte alignment @param ByteAlignment is reached.
comment|///
comment|/// If the number of bytes need to emit for the alignment is not a multiple
comment|/// of @param ValueSize, then the contents of the emitted fill bytes is
comment|/// undefined.
comment|///
comment|/// This used to implement the .align assembler directive.
comment|///
comment|/// @param ByteAlignment - The alignment to reach. This must be a power of
comment|/// two on some targets.
comment|/// @param Value - The value to use when filling bytes.
comment|/// @param Size - The size of the integer (in bytes) to emit for @param
comment|/// Value. This must match a native machine width.
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
comment|/// EmitValueToOffset - Emit some number of copies of @param Value until the
comment|/// byte offset @param Offset is reached.
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
comment|/// EmitInstruction - Emit the given @param Instruction into the current
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
name|MCStreamer
modifier|*
name|createAsmStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
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
init|=
literal|0
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

