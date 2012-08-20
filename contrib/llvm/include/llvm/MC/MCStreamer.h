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
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCWin64EH.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
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
name|bool
name|EmitEHFrame
decl_stmt|;
name|bool
name|EmitDebugFrame
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MCDwarfFrameInfo
operator|>
name|FrameInfos
expr_stmt|;
name|MCDwarfFrameInfo
modifier|*
name|getCurrentFrameInfo
parameter_list|()
function_decl|;
name|void
name|EnsureValidFrame
parameter_list|()
function_decl|;
name|std
operator|::
name|vector
operator|<
name|MCWin64EHUnwindInfo
operator|*
operator|>
name|W64UnwindInfos
expr_stmt|;
name|MCWin64EHUnwindInfo
modifier|*
name|CurrentW64UnwindInfo
decl_stmt|;
name|void
name|setCurrentW64UnwindInfo
parameter_list|(
name|MCWin64EHUnwindInfo
modifier|*
name|Frame
parameter_list|)
function_decl|;
name|void
name|EnsureValidW64UnwindInfo
parameter_list|()
function_decl|;
name|MCSymbol
modifier|*
name|LastSymbol
decl_stmt|;
comment|/// SectionStack - This is stack of current and previous section
comment|/// values saved by PushSection.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSection
operator|*
operator|,
specifier|const
name|MCSection
operator|*
operator|>
operator|,
literal|4
operator|>
name|SectionStack
expr_stmt|;
name|protected
label|:
name|MCStreamer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
specifier|const
name|MCExpr
modifier|*
name|BuildSymbolDiff
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|A
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|B
parameter_list|)
function_decl|;
specifier|const
name|MCExpr
modifier|*
name|ForceExpAbs
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Expr
parameter_list|)
function_decl|;
name|void
name|RecordProcStart
parameter_list|(
name|MCDwarfFrameInfo
modifier|&
name|Frame
parameter_list|)
function_decl|;
name|virtual
name|void
name|EmitCFIStartProcImpl
parameter_list|(
name|MCDwarfFrameInfo
modifier|&
name|Frame
parameter_list|)
function_decl|;
name|void
name|RecordProcEnd
parameter_list|(
name|MCDwarfFrameInfo
modifier|&
name|Frame
parameter_list|)
function_decl|;
name|virtual
name|void
name|EmitCFIEndProcImpl
parameter_list|(
name|MCDwarfFrameInfo
modifier|&
name|CurFrame
parameter_list|)
function_decl|;
name|void
name|EmitFrames
parameter_list|(
name|bool
name|usingCFI
parameter_list|)
function_decl|;
name|MCWin64EHUnwindInfo
modifier|*
name|getCurrentW64UnwindInfo
parameter_list|()
block|{
return|return
name|CurrentW64UnwindInfo
return|;
block|}
name|void
name|EmitW64Tables
parameter_list|()
function_decl|;
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
name|unsigned
name|getNumFrameInfos
parameter_list|()
block|{
return|return
name|FrameInfos
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|MCDwarfFrameInfo
modifier|&
name|getFrameInfo
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|FrameInfos
index|[
name|i
index|]
return|;
block|}
name|ArrayRef
operator|<
name|MCDwarfFrameInfo
operator|>
name|getFrameInfos
argument_list|()
block|{
return|return
name|FrameInfos
return|;
block|}
name|unsigned
name|getNumW64UnwindInfos
parameter_list|()
block|{
return|return
name|W64UnwindInfos
operator|.
name|size
argument_list|()
return|;
block|}
name|MCWin64EHUnwindInfo
modifier|&
name|getW64UnwindInfo
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
operator|*
name|W64UnwindInfos
index|[
name|i
index|]
return|;
block|}
comment|/// @name Assembly File Formatting.
comment|/// @{
comment|/// isVerboseAsm - Return true if this streamer supports verbose assembly
comment|/// and if it is enabled.
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
comment|/// hasRawTextSupport - Return true if this asm streamer supports emitting
comment|/// unformatted text to the .s file with EmitRawText.
name|virtual
name|bool
name|hasRawTextSupport
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
comment|/// getCurrentSection - Return the current section that the streamer is
comment|/// emitting code to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|SectionStack
operator|.
name|empty
argument_list|()
condition|)
return|return
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
return|;
return|return
name|NULL
return|;
block|}
comment|/// getPreviousSection - Return the previous section that the streamer is
comment|/// emitting code to.
specifier|const
name|MCSection
operator|*
name|getPreviousSection
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|SectionStack
operator|.
name|empty
argument_list|()
condition|)
return|return
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|second
return|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ChangeSection - Update streamer for a new active section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is called by PopSection and SwitchSection, if the current
end_comment

begin_comment
comment|/// section changes.
end_comment

begin_function_decl
name|virtual
name|void
name|ChangeSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// pushSection - Save the current and previous section on the
end_comment

begin_comment
comment|/// section stack.
end_comment

begin_function
name|void
name|PushSection
parameter_list|()
block|{
name|SectionStack
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|getCurrentSection
argument_list|()
argument_list|,
name|getPreviousSection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// popSection - Restore the current and previous section from
end_comment

begin_comment
comment|/// the section stack.  Calls ChangeSection as needed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns false if the stack was empty.
end_comment

begin_function
name|bool
name|PopSection
parameter_list|()
block|{
if|if
condition|(
name|SectionStack
operator|.
name|size
argument_list|()
operator|<=
literal|1
condition|)
return|return
name|false
return|;
specifier|const
name|MCSection
modifier|*
name|oldSection
init|=
name|SectionStack
operator|.
name|pop_back_val
argument_list|()
operator|.
name|first
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|curSection
init|=
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
decl_stmt|;
if|if
condition|(
name|oldSection
operator|!=
name|curSection
condition|)
name|ChangeSection
argument_list|(
name|curSection
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// SwitchSection - Set the current section where code is being emitted to
end_comment

begin_comment
comment|/// @p Section.  This is required to update CurSection.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to assembler directives like .section, .text, etc.
end_comment

begin_function
name|void
name|SwitchSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|)
block|{
name|assert
argument_list|(
name|Section
operator|&&
literal|"Cannot switch to a null section!"
argument_list|)
expr_stmt|;
specifier|const
name|MCSection
modifier|*
name|curSection
init|=
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
decl_stmt|;
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|second
operator|=
name|curSection
expr_stmt|;
if|if
condition|(
name|Section
operator|!=
name|curSection
condition|)
block|{
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
operator|=
name|Section
expr_stmt|;
name|ChangeSection
argument_list|(
name|Section
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// SwitchSectionNoChange - Set the current section where code is being
end_comment

begin_comment
comment|/// emitted to @p Section.  This is required to update CurSection. This
end_comment

begin_comment
comment|/// version does not call ChangeSection.
end_comment

begin_function
name|void
name|SwitchSectionNoChange
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|)
block|{
name|assert
argument_list|(
name|Section
operator|&&
literal|"Cannot switch to a null section!"
argument_list|)
expr_stmt|;
specifier|const
name|MCSection
modifier|*
name|curSection
init|=
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
decl_stmt|;
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|second
operator|=
name|curSection
expr_stmt|;
if|if
condition|(
name|Section
operator|!=
name|curSection
condition|)
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
operator|=
name|Section
expr_stmt|;
block|}
end_function

begin_comment
comment|/// InitSections - Create the default sections and set the initial one.
end_comment

begin_function_decl
name|virtual
name|void
name|InitSections
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLabel - Emit a label for @p Symbol into the current section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to an assembler statement such as:
end_comment

begin_comment
comment|///   foo:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The symbol to emit. A given symbol should only be
end_comment

begin_comment
comment|/// emitted as a label once, and symbols emitted as a label should never be
end_comment

begin_comment
comment|/// used in an assignment.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitLabel
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitEHSymAttributes
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|MCSymbol
modifier|*
name|EHSymbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAssemblerFlag - Note in the output the specified @p Flag.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitDataRegion - Note in the output the specified region @p Kind.
end_comment

begin_function
name|virtual
name|void
name|EmitDataRegion
parameter_list|(
name|MCDataRegionType
name|Kind
parameter_list|)
block|{}
end_function

begin_comment
comment|/// EmitThumbFunc - Note in the output that the specified @p Func is
end_comment

begin_comment
comment|/// a Thumb mode function (ARM target only).
end_comment

begin_function_decl
name|virtual
name|void
name|EmitThumbFunc
parameter_list|(
name|MCSymbol
modifier|*
name|Func
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAssignment - Emit an assignment of @p Value to @p Symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to an assembler statement such as:
end_comment

begin_comment
comment|///  symbol = value
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The assignment generates no code, but has the side effect of binding the
end_comment

begin_comment
comment|/// value in the current context. For the assembly streamer, this prints the
end_comment

begin_comment
comment|/// binding into the .s file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The symbol being assigned to.
end_comment

begin_comment
comment|/// @param Value - The value for the symbol.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitWeakReference - Emit an weak reference from @p Alias to @p Symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to an assembler statement such as:
end_comment

begin_comment
comment|///  .weakref alias, symbol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Alias - The alias that is being created.
end_comment

begin_comment
comment|/// @param Symbol - The symbol being aliased.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitWeakReference
parameter_list|(
name|MCSymbol
modifier|*
name|Alias
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSymbolAttribute - Add the given @p Attribute to @p Symbol.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitSymbolDesc - Set the @p DescValue for the @p Symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The symbol to have its n_desc field set.
end_comment

begin_comment
comment|/// @param DescValue - The value to set into the n_desc field.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// BeginCOFFSymbolDef - Start emitting COFF symbol definition
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The symbol to have its External& Type fields set.
end_comment

begin_function_decl
name|virtual
name|void
name|BeginCOFFSymbolDef
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCOFFSymbolStorageClass - Emit the storage class of the symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param StorageClass - The storage class the symbol should have.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSymbolStorageClass
parameter_list|(
name|int
name|StorageClass
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCOFFSymbolType - Emit the type of the symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Type - A COFF type identifier (see COFF::SymbolType in X86COFF.h)
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSymbolType
parameter_list|(
name|int
name|Type
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EndCOFFSymbolDef - Marks the end of the symbol definition.
end_comment

begin_function_decl
name|virtual
name|void
name|EndCOFFSymbolDef
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCOFFSecRel32 - Emits a COFF section relative relocation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - Symbol the section relative realocation should point to.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSecRel32
parameter_list|(
name|MCSymbol
specifier|const
modifier|*
name|Symbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitELFSize - Emit an ELF .size directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to an assembler statement such as:
end_comment

begin_comment
comment|///  .size symbol, expression
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitCommonSymbol - Emit a common symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The common symbol to emit.
end_comment

begin_comment
comment|/// @param Size - The size of the common symbol.
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment of the symbol if
end_comment

begin_comment
comment|/// non-zero. This must be a power of 2.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitLocalCommonSymbol - Emit a local common (.lcomm) symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Symbol - The common symbol to emit.
end_comment

begin_comment
comment|/// @param Size - The size of the common symbol.
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment of the common symbol in bytes.
end_comment

begin_function_decl
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
parameter_list|,
name|unsigned
name|ByteAlignment
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitZerofill - Emit the zerofill section and an optional symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Section - The zerofill section to create and or to put the symbol
end_comment

begin_comment
comment|/// @param Symbol - The zerofill symbol to emit, if non-NULL.
end_comment

begin_comment
comment|/// @param Size - The size of the zerofill symbol.
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment of the zerofill symbol if
end_comment

begin_comment
comment|/// non-zero. This must be a power of 2 on some targets.
end_comment

begin_function_decl
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
name|uint64_t
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
end_function_decl

begin_comment
comment|/// EmitTBSSSymbol - Emit a thread local bss (.tbss) symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Section - The thread local common section.
end_comment

begin_comment
comment|/// @param Symbol - The thread local common symbol to emit.
end_comment

begin_comment
comment|/// @param Size - The size of the symbol.
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment of the thread local common symbol
end_comment

begin_comment
comment|/// if non-zero.  This must be a power of 2 on some targets.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitTBSSSymbol
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|,
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|ByteAlignment
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Generating Data
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// EmitBytes - Emit the bytes in \arg Data into the output.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .byte, .ascii,
end_comment

begin_comment
comment|/// etc.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitValue - Emit the expression @p Value into the output as a native
end_comment

begin_comment
comment|/// integer of the given @p Size bytes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .word, .quad,
end_comment

begin_comment
comment|/// etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Value - The value to emit.
end_comment

begin_comment
comment|/// @param Size - The size of the integer (in bytes) to emit. This must
end_comment

begin_comment
comment|/// match a native machine width.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitValueImpl
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
end_function_decl

begin_function_decl
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
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitIntValue - Special case of EmitValue that avoids the client having
end_comment

begin_comment
comment|/// to pass in a MCExpr for constant integers.
end_comment

begin_function_decl
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
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAbsValue - Emit the Value, but try to avoid relocations. On MachO
end_comment

begin_comment
comment|/// this is done by producing
end_comment

begin_comment
comment|/// foo = value
end_comment

begin_comment
comment|/// .long foo
end_comment

begin_function_decl
name|void
name|EmitAbsValue
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
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitULEB128Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitSLEB128Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// EmitULEB128Value - Special case of EmitULEB128Value that avoids the
end_comment

begin_comment
comment|/// client having to pass in a MCExpr for constant integers.
end_comment

begin_function_decl
name|void
name|EmitULEB128IntValue
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|,
name|unsigned
name|Padding
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSLEB128Value - Special case of EmitSLEB128Value that avoids the
end_comment

begin_comment
comment|/// client having to pass in a MCExpr for constant integers.
end_comment

begin_function_decl
name|void
name|EmitSLEB128IntValue
parameter_list|(
name|int64_t
name|Value
parameter_list|,
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSymbolValue - Special case of EmitValue that avoids the client
end_comment

begin_comment
comment|/// having to pass in a MCExpr for MCSymbols.
end_comment

begin_function_decl
name|void
name|EmitSymbolValue
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitGPRel64Value - Emit the expression @p Value into the output as a
end_comment

begin_comment
comment|/// gprel64 (64-bit GP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .gpdword on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitGPRel64Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitGPRel32Value - Emit the expression @p Value into the output as a
end_comment

begin_comment
comment|/// gprel32 (32-bit GP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .gprel32 on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitGPRel32Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFill - Emit NumBytes bytes worth of the value specified by
end_comment

begin_comment
comment|/// FillValue.  This implements directives such as '.space'.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitZeros - Emit NumBytes worth of zeros.  This is a convenience
end_comment

begin_comment
comment|/// function that just wraps EmitFill.
end_comment

begin_function
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
end_function

begin_comment
comment|/// EmitValueToAlignment - Emit some number of copies of @p Value until
end_comment

begin_comment
comment|/// the byte alignment @p ByteAlignment is reached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the number of bytes need to emit for the alignment is not a multiple
end_comment

begin_comment
comment|/// of @p ValueSize, then the contents of the emitted fill bytes is
end_comment

begin_comment
comment|/// undefined.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This used to implement the .align assembler directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment to reach. This must be a power of
end_comment

begin_comment
comment|/// two on some targets.
end_comment

begin_comment
comment|/// @param Value - The value to use when filling bytes.
end_comment

begin_comment
comment|/// @param ValueSize - The size of the integer (in bytes) to emit for
end_comment

begin_comment
comment|/// @p Value. This must match a native machine width.
end_comment

begin_comment
comment|/// @param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
end_comment

begin_comment
comment|/// the alignment cannot be reached in this many bytes, no bytes are
end_comment

begin_comment
comment|/// emitted.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitCodeAlignment - Emit nops until the byte alignment @p ByteAlignment
end_comment

begin_comment
comment|/// is reached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This used to align code where the alignment bytes may be executed.  This
end_comment

begin_comment
comment|/// can emit different bytes for different sizes to optimize execution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param ByteAlignment - The alignment to reach. This must be a power of
end_comment

begin_comment
comment|/// two on some targets.
end_comment

begin_comment
comment|/// @param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
end_comment

begin_comment
comment|/// the alignment cannot be reached in this many bytes, no bytes are
end_comment

begin_comment
comment|/// emitted.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitValueToOffset - Emit some number of copies of @p Value until the
end_comment

begin_comment
comment|/// byte offset @p Offset is reached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .org.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Offset - The offset to reach. This may be an expression, but the
end_comment

begin_comment
comment|/// expression must be associated with the current section.
end_comment

begin_comment
comment|/// @param Value - The value to use when filling bytes.
end_comment

begin_comment
comment|/// @return false on success, true if the offset was invalid.
end_comment

begin_function_decl
name|virtual
name|bool
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
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// EmitFileDirective - Switch to a new logical file.  This is used to
end_comment

begin_comment
comment|/// implement the '.file "foo.c"' assembler directive.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitDwarfFileDirective - Associate a filename with a specified logical
end_comment

begin_comment
comment|/// file number.  This implements the DWARF2 '.file 4 "foo.c"' assembler
end_comment

begin_comment
comment|/// directive.
end_comment

begin_function_decl
name|virtual
name|bool
name|EmitDwarfFileDirective
parameter_list|(
name|unsigned
name|FileNo
parameter_list|,
name|StringRef
name|Directory
parameter_list|,
name|StringRef
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitDwarfLocDirective - This implements the DWARF2
end_comment

begin_comment
comment|// '.loc fileno lineno ...' assembler directive.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitDwarfLocDirective
parameter_list|(
name|unsigned
name|FileNo
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Column
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|Isa
parameter_list|,
name|unsigned
name|Discriminator
parameter_list|,
name|StringRef
name|FileName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitDwarfAdvanceLineAddr
parameter_list|(
name|int64_t
name|LineDelta
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|LastLabel
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|,
name|unsigned
name|PointerSize
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_function
name|virtual
name|void
name|EmitDwarfAdvanceFrameAddr
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|LastLabel
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|)
block|{     }
end_function

begin_function_decl
name|void
name|EmitDwarfSetLineAddr
parameter_list|(
name|int64_t
name|LineDelta
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|,
name|int
name|PointerSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCompactUnwindEncoding
parameter_list|(
name|uint32_t
name|CompactUnwindEncoding
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFISections
parameter_list|(
name|bool
name|EH
parameter_list|,
name|bool
name|Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCFIStartProc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCFIEndProc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIDefCfa
parameter_list|(
name|int64_t
name|Register
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIDefCfaOffset
parameter_list|(
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIDefCfaRegister
parameter_list|(
name|int64_t
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIOffset
parameter_list|(
name|int64_t
name|Register
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIPersonality
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|unsigned
name|Encoding
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFILsda
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|unsigned
name|Encoding
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIRememberState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIRestoreState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFISameValue
parameter_list|(
name|int64_t
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIRestore
parameter_list|(
name|int64_t
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIRelOffset
parameter_list|(
name|int64_t
name|Register
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIAdjustCfaOffset
parameter_list|(
name|int64_t
name|Adjustment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIEscape
parameter_list|(
name|StringRef
name|Values
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFISignalFrame
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHStartProc
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHEndProc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHStartChained
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHEndChained
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHHandler
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|bool
name|Unwind
parameter_list|,
name|bool
name|Except
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHHandlerData
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHPushReg
parameter_list|(
name|unsigned
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHSetFrame
parameter_list|(
name|unsigned
name|Register
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHAllocStack
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHSaveReg
parameter_list|(
name|unsigned
name|Register
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHSaveXMM
parameter_list|(
name|unsigned
name|Register
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHPushFrame
parameter_list|(
name|bool
name|Code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWin64EHEndProlog
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitInstruction - Emit the given @p Instruction into the current
end_comment

begin_comment
comment|/// section.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// EmitRawText - If this file is backed by a assembly streamer, this dumps
end_comment

begin_comment
comment|/// the specified string in the output .s file.  This capability is
end_comment

begin_comment
comment|/// indicated by the hasRawTextSupport() predicate.  By default this aborts.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitRawText
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitRawText
parameter_list|(
specifier|const
name|Twine
modifier|&
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ARM-related methods.
end_comment

begin_comment
comment|/// FIXME: Eventually we should have some "target MC streamer" and move
end_comment

begin_comment
comment|/// these methods there.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitFnStart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitFnEnd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCantUnwind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitPersonality
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Personality
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitHandlerData
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitSetFP
parameter_list|(
name|unsigned
name|FpReg
parameter_list|,
name|unsigned
name|SpReg
parameter_list|,
name|int64_t
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitPad
parameter_list|(
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|void
name|EmitRegSave
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|RegList
argument_list|,
name|bool
name|isVector
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// FinishImpl - Streamer specific finalization.
end_comment

begin_function_decl
name|virtual
name|void
name|FinishImpl
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// Finish - Finish emission of machine code.
end_comment

begin_function_decl
name|void
name|Finish
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// createNullStreamer - Create a dummy machine code streamer, which does
end_comment

begin_comment
comment|/// nothing. This is useful for timing the assembler front end.
end_comment

begin_function_decl
name|MCStreamer
modifier|*
name|createNullStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createAsmStreamer - Create a machine code streamer which will print out
end_comment

begin_comment
comment|/// assembly for the native target, suitable for compiling with a native
end_comment

begin_comment
comment|/// assembler.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param InstPrint - If given, the instruction printer to use. If not given
end_comment

begin_comment
comment|/// the MCInst representation will be printed.  This method takes ownership of
end_comment

begin_comment
comment|/// InstPrint.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CE - If given, a code emitter to use to show the instruction
end_comment

begin_comment
comment|/// encoding inline with the assembly. This method takes ownership of \arg CE.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TAB - If given, a target asm backend to use to show the fixup
end_comment

begin_comment
comment|/// information in conjunction with encoding information. This method takes
end_comment

begin_comment
comment|/// ownership of \arg TAB.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ShowInst - Whether to show the MCInst representation inline with
end_comment

begin_comment
comment|/// the assembly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DecodeLSDA - If true, emit comments that translates the LSDA into a
end_comment

begin_comment
comment|/// human readable format. Only usable with CFI.
end_comment

begin_function_decl
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
name|bool
name|isVerboseAsm
parameter_list|,
name|bool
name|useLoc
parameter_list|,
name|bool
name|useCFI
parameter_list|,
name|bool
name|useDwarfDirectory
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
name|MCAsmBackend
modifier|*
name|TAB
init|=
literal|0
parameter_list|,
name|bool
name|ShowInst
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createMachOStreamer - Create a machine code streamer which will generate
end_comment

begin_comment
comment|/// Mach-O format object files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Takes ownership of \arg TAB and \arg CE.
end_comment

begin_function_decl
name|MCStreamer
modifier|*
name|createMachOStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|,
name|bool
name|RelaxAll
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createWinCOFFStreamer - Create a machine code streamer which will
end_comment

begin_comment
comment|/// generate Microsoft COFF format object files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Takes ownership of \arg TAB and \arg CE.
end_comment

begin_function_decl
name|MCStreamer
modifier|*
name|createWinCOFFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|MCCodeEmitter
modifier|&
name|CE
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|RelaxAll
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createELFStreamer - Create a machine code streamer which will generate
end_comment

begin_comment
comment|/// ELF format object files.
end_comment

begin_function_decl
name|MCStreamer
modifier|*
name|createELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|,
name|bool
name|RelaxAll
parameter_list|,
name|bool
name|NoExecStack
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// createPureStreamer - Create a machine code streamer which will generate
end_comment

begin_comment
comment|/// "pure" MC object files, for use with MC-JIT and testing tools.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Takes ownership of \arg TAB and \arg CE.
end_comment

begin_function_decl
name|MCStreamer
modifier|*
name|createPureStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
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
end_function_decl

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

