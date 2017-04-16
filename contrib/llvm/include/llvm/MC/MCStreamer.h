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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
file|"llvm/MC/MCLinkerOptimizationHint.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCWinEH.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|AssemblerConstantPools
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
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
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbolRefExpr
decl_stmt|;
name|class
name|MCSymbolWasm
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Twine
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|MCSection
operator|*
operator|,
specifier|const
name|MCExpr
operator|*
operator|>
name|MCSectionSubPair
expr_stmt|;
comment|/// Target specific streamer interface. This is used so that targets can
comment|/// implement support for target specific assembly directives.
comment|///
comment|/// If target foo wants to use this, it should implement 3 classes:
comment|/// * FooTargetStreamer : public MCTargetStreamer
comment|/// * FooTargetAsmStreamer : public FooTargetStreamer
comment|/// * FooTargetELFStreamer : public FooTargetStreamer
comment|///
comment|/// FooTargetStreamer should have a pure virtual method for each directive. For
comment|/// example, for a ".bar symbol_name" directive, it should have
comment|/// virtual emitBar(const MCSymbol&Symbol) = 0;
comment|///
comment|/// The FooTargetAsmStreamer and FooTargetELFStreamer classes implement the
comment|/// method. The assembly streamer just prints ".bar symbol_name". The object
comment|/// streamer does whatever is needed to implement .bar in the object file.
comment|///
comment|/// In the assembly printer and parser the target streamer can be used by
comment|/// calling getTargetStreamer and casting it to FooTargetStreamer:
comment|///
comment|/// MCTargetStreamer&TS = OutStreamer.getTargetStreamer();
comment|/// FooTargetStreamer&ATS = static_cast<FooTargetStreamer&>(TS);
comment|///
comment|/// The base classes FooTargetAsmStreamer and FooTargetELFStreamer should
comment|/// *never* be treated differently. Callers should always talk to a
comment|/// FooTargetStreamer.
name|class
name|MCTargetStreamer
block|{
name|protected
label|:
name|MCStreamer
modifier|&
name|Streamer
decl_stmt|;
name|public
label|:
name|MCTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|MCTargetStreamer
argument_list|()
expr_stmt|;
name|MCStreamer
modifier|&
name|getStreamer
parameter_list|()
block|{
return|return
name|Streamer
return|;
block|}
comment|// Allow a target to add behavior to the EmitLabel of MCStreamer.
name|virtual
name|void
name|emitLabel
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
function_decl|;
comment|// Allow a target to add behavior to the emitAssignment of MCStreamer.
name|virtual
name|void
name|emitAssignment
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
function_decl|;
name|virtual
name|void
name|prettyPrintAsm
parameter_list|(
name|MCInstPrinter
modifier|&
name|InstPrinter
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|MCInst
modifier|&
name|Inst
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|virtual
name|void
name|finish
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|// FIXME: declared here because it is used from
comment|// lib/CodeGen/AsmPrinter/ARMException.cpp.
name|class
name|ARMTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|ARMTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
operator|~
name|ARMTargetStreamer
argument_list|()
name|override
block|;
name|virtual
name|void
name|emitFnStart
argument_list|()
block|;
name|virtual
name|void
name|emitFnEnd
argument_list|()
block|;
name|virtual
name|void
name|emitCantUnwind
argument_list|()
block|;
name|virtual
name|void
name|emitPersonality
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Personality
argument_list|)
block|;
name|virtual
name|void
name|emitPersonalityIndex
argument_list|(
argument|unsigned Index
argument_list|)
block|;
name|virtual
name|void
name|emitHandlerData
argument_list|()
block|;
name|virtual
name|void
name|emitSetFP
argument_list|(
argument|unsigned FpReg
argument_list|,
argument|unsigned SpReg
argument_list|,
argument|int64_t Offset =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|emitMovSP
argument_list|(
argument|unsigned Reg
argument_list|,
argument|int64_t Offset =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|emitPad
argument_list|(
argument|int64_t Offset
argument_list|)
block|;
name|virtual
name|void
name|emitRegSave
argument_list|(
argument|const SmallVectorImpl<unsigned>&RegList
argument_list|,
argument|bool isVector
argument_list|)
block|;
name|virtual
name|void
name|emitUnwindRaw
argument_list|(
argument|int64_t StackOffset
argument_list|,
argument|const SmallVectorImpl<uint8_t>&Opcodes
argument_list|)
block|;
name|virtual
name|void
name|switchVendor
argument_list|(
argument|StringRef Vendor
argument_list|)
block|;
name|virtual
name|void
name|emitAttribute
argument_list|(
argument|unsigned Attribute
argument_list|,
argument|unsigned Value
argument_list|)
block|;
name|virtual
name|void
name|emitTextAttribute
argument_list|(
argument|unsigned Attribute
argument_list|,
argument|StringRef String
argument_list|)
block|;
name|virtual
name|void
name|emitIntTextAttribute
argument_list|(
argument|unsigned Attribute
argument_list|,
argument|unsigned IntValue
argument_list|,
argument|StringRef StringValue =
literal|""
argument_list|)
block|;
name|virtual
name|void
name|emitFPU
argument_list|(
argument|unsigned FPU
argument_list|)
block|;
name|virtual
name|void
name|emitArch
argument_list|(
argument|unsigned Arch
argument_list|)
block|;
name|virtual
name|void
name|emitArchExtension
argument_list|(
argument|unsigned ArchExt
argument_list|)
block|;
name|virtual
name|void
name|emitObjectArch
argument_list|(
argument|unsigned Arch
argument_list|)
block|;
name|virtual
name|void
name|finishAttributeSection
argument_list|()
block|;
name|virtual
name|void
name|emitInst
argument_list|(
argument|uint32_t Inst
argument_list|,
argument|char Suffix =
literal|'\0'
argument_list|)
block|;
name|virtual
name|void
name|AnnotateTLSDescriptorSequence
argument_list|(
specifier|const
name|MCSymbolRefExpr
operator|*
name|SRE
argument_list|)
block|;
name|virtual
name|void
name|emitThumbSet
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
block|;
name|void
name|finish
argument_list|()
name|override
block|;
comment|/// Reset any state between object emissions, i.e. the equivalent of
comment|/// MCStreamer's reset method.
name|virtual
name|void
name|reset
argument_list|()
block|;
comment|/// Callback used to implement the ldr= pseudo.
comment|/// Add a new entry to the constant pool for the current section and return an
comment|/// MCExpr that can be used to refer to the constant pool location.
specifier|const
name|MCExpr
operator|*
name|addConstantPoolEntry
argument_list|(
argument|const MCExpr *
argument_list|,
argument|SMLoc Loc
argument_list|)
block|;
comment|/// Callback used to implemnt the .ltorg directive.
comment|/// Emit contents of constant pool for the current section.
name|void
name|emitCurrentConstantPool
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|AssemblerConstantPools
operator|>
name|ConstantPools
block|; }
decl_stmt|;
comment|/// \brief Streaming machine code generation interface.
comment|///
comment|/// This interface is intended to provide a programatic interface that is very
comment|/// similar to the level that an assembler .s file provides.  It has callbacks
comment|/// to emit bytes, handle directives, etc.  The implementation of this interface
comment|/// retains state to know what the current section is etc.
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
name|std
operator|::
name|unique_ptr
operator|<
name|MCTargetStreamer
operator|>
name|TargetStreamer
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MCDwarfFrameInfo
operator|>
name|DwarfFrameInfos
expr_stmt|;
name|MCDwarfFrameInfo
modifier|*
name|getCurrentDwarfFrameInfo
parameter_list|()
function_decl|;
name|void
name|EnsureValidDwarfFrame
parameter_list|()
function_decl|;
name|MCSymbol
modifier|*
name|EmitCFILabel
parameter_list|()
function_decl|;
name|MCSymbol
modifier|*
name|EmitCFICommon
parameter_list|()
function_decl|;
name|std
operator|::
name|vector
operator|<
name|WinEH
operator|::
name|FrameInfo
operator|*
operator|>
name|WinFrameInfos
expr_stmt|;
name|WinEH
operator|::
name|FrameInfo
operator|*
name|CurrentWinFrameInfo
expr_stmt|;
name|void
name|EnsureValidWinFrameInfo
parameter_list|()
function_decl|;
comment|/// \brief Tracks an index to represent the order a symbol was emitted in.
comment|/// Zero means we did not emit that symbol.
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|unsigned
operator|>
name|SymbolOrdering
expr_stmt|;
comment|/// \brief This is stack of current and previous section values saved by
comment|/// PushSection.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSectionSubPair
operator|,
name|MCSectionSubPair
operator|>
operator|,
literal|4
operator|>
name|SectionStack
expr_stmt|;
comment|/// The next unique ID to use when creating a WinCFI-related section (.pdata
comment|/// or .xdata). This ID ensures that we have a one-to-one mapping from
comment|/// code section to unwind info section, which MSVC's incremental linker
comment|/// requires.
name|unsigned
name|NextWinCFIID
init|=
literal|0
decl_stmt|;
name|protected
label|:
name|MCStreamer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
name|virtual
name|void
name|EmitCFIStartProcImpl
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
name|WinEH
operator|::
name|FrameInfo
operator|*
name|getCurrentWinFrameInfo
argument_list|()
block|{
return|return
name|CurrentWinFrameInfo
return|;
block|}
name|virtual
name|void
name|EmitWindowsUnwindTables
parameter_list|()
function_decl|;
name|virtual
name|void
name|EmitRawTextImpl
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
name|public
label|:
name|MCStreamer
argument_list|(
specifier|const
name|MCStreamer
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCStreamer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCStreamer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|MCStreamer
argument_list|()
expr_stmt|;
name|void
name|visitUsedExpr
parameter_list|(
specifier|const
name|MCExpr
modifier|&
name|Expr
parameter_list|)
function_decl|;
name|virtual
name|void
name|visitUsedSymbol
parameter_list|(
specifier|const
name|MCSymbol
modifier|&
name|Sym
parameter_list|)
function_decl|;
name|void
name|setTargetStreamer
parameter_list|(
name|MCTargetStreamer
modifier|*
name|TS
parameter_list|)
block|{
name|TargetStreamer
operator|.
name|reset
argument_list|(
name|TS
argument_list|)
expr_stmt|;
block|}
comment|/// State management
comment|///
name|virtual
name|void
name|reset
parameter_list|()
function_decl|;
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
name|MCTargetStreamer
modifier|*
name|getTargetStreamer
parameter_list|()
block|{
return|return
name|TargetStreamer
operator|.
name|get
argument_list|()
return|;
block|}
name|unsigned
name|getNumFrameInfos
parameter_list|()
block|{
return|return
name|DwarfFrameInfos
operator|.
name|size
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|MCDwarfFrameInfo
operator|>
name|getDwarfFrameInfos
argument_list|()
specifier|const
block|{
return|return
name|DwarfFrameInfos
return|;
block|}
name|bool
name|hasUnfinishedDwarfFrameInfo
parameter_list|()
function_decl|;
name|unsigned
name|getNumWinFrameInfos
parameter_list|()
block|{
return|return
name|WinFrameInfos
operator|.
name|size
argument_list|()
return|;
block|}
name|ArrayRef
operator|<
name|WinEH
operator|::
name|FrameInfo
operator|*
operator|>
name|getWinFrameInfos
argument_list|()
specifier|const
block|{
return|return
name|WinFrameInfos
return|;
block|}
name|void
name|generateCompactUnwindEncodings
parameter_list|(
name|MCAsmBackend
modifier|*
name|MAB
parameter_list|)
function_decl|;
comment|/// \name Assembly File Formatting.
comment|/// @{
comment|/// \brief Return true if this streamer supports verbose assembly and if it is
comment|/// enabled.
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
comment|/// \brief Return true if this asm streamer supports emitting unformatted text
comment|/// to the .s file with EmitRawText.
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
comment|/// \brief Is the integrated assembler required for this streamer to function
comment|/// correctly?
name|virtual
name|bool
name|isIntegratedAssemblerRequired
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Add a textual comment.
comment|///
comment|/// Typically for comments that can be emitted to the generated .s
comment|/// file if applicable as a QoI issue to make the output of the compiler
comment|/// more readable.  This only affects the MCAsmStreamer, and only when
comment|/// verbose assembly output is enabled.
comment|///
comment|/// If the comment includes embedded \n's, they will each get the comment
comment|/// prefix as appropriate.  The added comment should not end with a \n.
comment|/// By default, each comment is terminated with an end of line, i.e. the
comment|/// EOL param is set to true by default. If one prefers not to end the
comment|/// comment with a new line then the EOL param should be passed
comment|/// with a false value.
name|virtual
name|void
name|AddComment
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|,
name|bool
name|EOL
init|=
name|true
parameter_list|)
block|{}
comment|/// \brief Return a raw_ostream that comments can be written to. Unlike
comment|/// AddComment, you are required to terminate comments with \n if you use this
comment|/// method.
name|virtual
name|raw_ostream
modifier|&
name|GetCommentOS
parameter_list|()
function_decl|;
comment|/// \brief Print T and prefix it with the comment string (normally #) and
comment|/// optionally a tab. This prints the comment immediately, not at the end of
comment|/// the current line. It is basically a safe version of EmitRawText: since it
comment|/// only prints comments, the object streamer ignores it instead of asserting.
name|virtual
name|void
name|emitRawComment
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|,
name|bool
name|TabPrefix
init|=
name|true
parameter_list|)
function_decl|;
comment|/// \brief Add explicit comment T. T is required to be a valid
comment|/// comment in the output and does not need to be escaped.
name|virtual
name|void
name|addExplicitComment
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|)
function_decl|;
comment|/// \brief Emit added explicit comments.
name|virtual
name|void
name|emitExplicitComments
parameter_list|()
function_decl|;
comment|/// AddBlankLine - Emit a blank line to a .s file to pretty it up.
name|virtual
name|void
name|AddBlankLine
parameter_list|()
block|{}
comment|/// @}
comment|/// \name Symbol& Section Management
comment|/// @{
comment|/// \brief Return the current section that the streamer is emitting code to.
name|MCSectionSubPair
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
name|MCSectionSubPair
argument_list|()
return|;
block|}
name|MCSection
operator|*
name|getCurrentSectionOnly
argument_list|()
specifier|const
block|{
return|return
name|getCurrentSection
argument_list|()
operator|.
name|first
return|;
block|}
comment|/// \brief Return the previous section that the streamer is emitting code to.
name|MCSectionSubPair
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
name|MCSectionSubPair
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns an index to represent the order a symbol was emitted in.
end_comment

begin_comment
comment|/// (zero if we did not emit that symbol)
end_comment

begin_decl_stmt
name|unsigned
name|GetSymbolOrder
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|)
decl|const
block|{
return|return
name|SymbolOrdering
operator|.
name|lookup
argument_list|(
name|Sym
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Update streamer for a new active section.
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
name|MCSection
modifier|*
parameter_list|,
specifier|const
name|MCExpr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Save the current and previous section on the section stack.
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
comment|/// \brief Restore the current and previous section from the section stack.
end_comment

begin_comment
comment|/// Calls ChangeSection as needed.
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
name|auto
name|I
init|=
name|SectionStack
operator|.
name|end
argument_list|()
decl_stmt|;
operator|--
name|I
expr_stmt|;
name|MCSectionSubPair
name|OldSection
init|=
name|I
operator|->
name|first
decl_stmt|;
operator|--
name|I
expr_stmt|;
name|MCSectionSubPair
name|NewSection
init|=
name|I
operator|->
name|first
decl_stmt|;
if|if
condition|(
name|OldSection
operator|!=
name|NewSection
condition|)
name|ChangeSection
argument_list|(
name|NewSection
operator|.
name|first
argument_list|,
name|NewSection
operator|.
name|second
argument_list|)
expr_stmt|;
name|SectionStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_function
name|bool
name|SubSection
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Subsection
parameter_list|)
block|{
if|if
condition|(
name|SectionStack
operator|.
name|empty
argument_list|()
condition|)
return|return
name|false
return|;
name|SwitchSection
argument_list|(
name|SectionStack
operator|.
name|back
argument_list|()
operator|.
name|first
operator|.
name|first
argument_list|,
name|Subsection
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// Set the current section where code is being emitted to \p Section.  This
end_comment

begin_comment
comment|/// is required to update CurSection.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to assembler directives like .section, .text, etc.
end_comment

begin_function_decl
name|virtual
name|void
name|SwitchSection
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Subsection
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the current section where code is being emitted to \p Section.
end_comment

begin_comment
comment|/// This is required to update CurSection. This version does not call
end_comment

begin_comment
comment|/// ChangeSection.
end_comment

begin_function
name|void
name|SwitchSectionNoChange
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Subsection
init|=
name|nullptr
parameter_list|)
block|{
name|assert
argument_list|(
name|Section
operator|&&
literal|"Cannot switch to a null section!"
argument_list|)
expr_stmt|;
name|MCSectionSubPair
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
name|MCSectionSubPair
argument_list|(
name|Section
argument_list|,
name|Subsection
argument_list|)
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
name|MCSectionSubPair
argument_list|(
name|Section
argument_list|,
name|Subsection
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Create the default sections and set the initial one.
end_comment

begin_function_decl
name|virtual
name|void
name|InitSections
parameter_list|(
name|bool
name|NoExecStack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSymbol
modifier|*
name|endSection
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Sets the symbol's section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each emitted symbol will be tracked in the ordering table,
end_comment

begin_comment
comment|/// so we can sort on them later.
end_comment

begin_function_decl
name|void
name|AssignFragment
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|MCFragment
modifier|*
name|Fragment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a label for \p Symbol into the current section.
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
comment|/// \param Symbol - The symbol to emit. A given symbol should only be
end_comment

begin_comment
comment|/// emitted as a label once, and symbols emitted as a label should never be
end_comment

begin_comment
comment|/// used in an assignment.
end_comment

begin_comment
comment|// FIXME: These emission are non-const because we mutate the symbol to
end_comment

begin_comment
comment|// add the section we're emitting it to later.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitLabel
parameter_list|(
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
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
comment|/// \brief Note in the output the specified \p Flag.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitAssemblerFlag
parameter_list|(
name|MCAssemblerFlag
name|Flag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the given list \p Options of strings as linker
end_comment

begin_comment
comment|/// options into the output.
end_comment

begin_decl_stmt
name|virtual
name|void
name|EmitLinkerOptions
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|Kind
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|/// \brief Note in the output the specified region \p Kind.
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
comment|/// \brief Specify the MachO minimum deployment target version.
end_comment

begin_function
name|virtual
name|void
name|EmitVersionMin
parameter_list|(
name|MCVersionMinType
parameter_list|,
name|unsigned
name|Major
parameter_list|,
name|unsigned
name|Minor
parameter_list|,
name|unsigned
name|Update
parameter_list|)
block|{}
end_function

begin_comment
comment|/// \brief Note in the output that the specified \p Func is a Thumb mode
end_comment

begin_comment
comment|/// function (ARM target only).
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit an assignment of \p Value to \p Symbol.
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
comment|/// \param Symbol - The symbol being assigned to.
end_comment

begin_comment
comment|/// \param Value - The value for the symbol.
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit an weak reference from \p Alias to \p Symbol.
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
comment|/// \param Alias - The alias that is being created.
end_comment

begin_comment
comment|/// \param Symbol - The symbol being aliased.
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add the given \p Attribute to \p Symbol.
end_comment

begin_function_decl
name|virtual
name|bool
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
comment|/// \brief Set the \p DescValue for the \p Symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - The symbol to have its n_desc field set.
end_comment

begin_comment
comment|/// \param DescValue - The value to set into the n_desc field.
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Start emitting COFF symbol definition
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - The symbol to have its External& Type fields set.
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the storage class of the symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param StorageClass - The storage class the symbol should have.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSymbolStorageClass
parameter_list|(
name|int
name|StorageClass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the type of the symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Type - A COFF type identifier (see COFF::SymbolType in X86COFF.h)
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSymbolType
parameter_list|(
name|int
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Marks the end of the symbol definition.
end_comment

begin_function_decl
name|virtual
name|void
name|EndCOFFSymbolDef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCOFFSafeSEH
parameter_list|(
name|MCSymbol
specifier|const
modifier|*
name|Symbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emits a COFF section index.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - Symbol the section number relocation should point to.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCOFFSectionIndex
parameter_list|(
name|MCSymbol
specifier|const
modifier|*
name|Symbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emits a COFF section relative relocation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - Symbol the section relative relocation should point to.
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
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit an ELF .size directive.
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

begin_function_decl
name|virtual
name|void
name|emitELFSize
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit an ELF .symver directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to an assembler statement such as:
end_comment

begin_comment
comment|///  .symver _start, foo@@SOME_VERSION
end_comment

begin_comment
comment|/// \param Alias - The versioned alias (i.e. "foo@@SOME_VERSION")
end_comment

begin_comment
comment|/// \param Aliasee - The aliased symbol (i.e. "_start")
end_comment

begin_function_decl
name|virtual
name|void
name|emitELFSymverDirective
parameter_list|(
name|MCSymbol
modifier|*
name|Alias
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Aliasee
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a Linker Optimization Hint (LOH) directive.
end_comment

begin_comment
comment|/// \param Args - Arguments of the LOH.
end_comment

begin_function
name|virtual
name|void
name|EmitLOHDirective
parameter_list|(
name|MCLOHType
name|Kind
parameter_list|,
specifier|const
name|MCLOHArgs
modifier|&
name|Args
parameter_list|)
block|{}
end_function

begin_comment
comment|/// \brief Emit a common symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - The common symbol to emit.
end_comment

begin_comment
comment|/// \param Size - The size of the common symbol.
end_comment

begin_comment
comment|/// \param ByteAlignment - The alignment of the symbol if
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
comment|/// \brief Emit a local common (.lcomm) symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Symbol - The common symbol to emit.
end_comment

begin_comment
comment|/// \param Size - The size of the common symbol.
end_comment

begin_comment
comment|/// \param ByteAlignment - The alignment of the common symbol in bytes.
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the zerofill section and an optional symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Section - The zerofill section to create and or to put the symbol
end_comment

begin_comment
comment|/// \param Symbol - The zerofill symbol to emit, if non-NULL.
end_comment

begin_comment
comment|/// \param Size - The size of the zerofill symbol.
end_comment

begin_comment
comment|/// \param ByteAlignment - The alignment of the zerofill symbol if
end_comment

begin_comment
comment|/// non-zero. This must be a power of 2 on some targets.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitZerofill
parameter_list|(
name|MCSection
modifier|*
name|Section
parameter_list|,
name|MCSymbol
modifier|*
name|Symbol
init|=
name|nullptr
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
comment|/// \brief Emit a thread local bss (.tbss) symbol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Section - The thread local common section.
end_comment

begin_comment
comment|/// \param Symbol - The thread local common symbol to emit.
end_comment

begin_comment
comment|/// \param Size - The size of the symbol.
end_comment

begin_comment
comment|/// \param ByteAlignment - The alignment of the thread local common symbol
end_comment

begin_comment
comment|/// if non-zero.  This must be a power of 2 on some targets.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitTBSSSymbol
parameter_list|(
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
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Generating Data
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Emit the bytes in \p Data into the output.
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Functionally identical to EmitBytes. When emitting textual assembly, this
end_comment

begin_comment
comment|/// method uses .byte directives instead of .ascii or .asciz for readability.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitBinaryData
parameter_list|(
name|StringRef
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a native
end_comment

begin_comment
comment|/// integer of the given \p Size bytes.
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
comment|/// \param Value - The value to emit.
end_comment

begin_comment
comment|/// \param Size - The size of the integer (in bytes) to emit. This must
end_comment

begin_comment
comment|/// match a native machine width.
end_comment

begin_comment
comment|/// \param Loc - The location of the expression for error reporting.
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
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
parameter_list|)
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
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Special case of EmitValue that avoids the client having
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Special case of EmitULEB128Value that avoids the client having to
end_comment

begin_comment
comment|/// pass in a MCExpr for constant integers.
end_comment

begin_function_decl
name|void
name|EmitULEB128IntValue
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|unsigned
name|Padding
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Special case of EmitSLEB128Value that avoids the client having to
end_comment

begin_comment
comment|/// pass in a MCExpr for constant integers.
end_comment

begin_function_decl
name|void
name|EmitSLEB128IntValue
parameter_list|(
name|int64_t
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Special case of EmitValue that avoids the client having to pass in
end_comment

begin_comment
comment|/// a MCExpr for MCSymbols.
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
name|bool
name|IsSectionRelative
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a dtprel
end_comment

begin_comment
comment|/// (64-bit DTP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .dtpreldword on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitDTPRel64Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a dtprel
end_comment

begin_comment
comment|/// (32-bit DTP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .dtprelword on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitDTPRel32Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a tprel
end_comment

begin_comment
comment|/// (64-bit TP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .tpreldword on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitTPRel64Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a tprel
end_comment

begin_comment
comment|/// (32-bit TP relative) value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .tprelword on
end_comment

begin_comment
comment|/// targets that support them.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitTPRel32Value
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the expression \p Value into the output as a gprel64 (64-bit
end_comment

begin_comment
comment|/// GP relative) value.
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
comment|/// \brief Emit the expression \p Value into the output as a gprel32 (32-bit
end_comment

begin_comment
comment|/// GP relative) value.
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
comment|/// \brief Emit NumBytes bytes worth of the value specified by FillValue.
end_comment

begin_comment
comment|/// This implements directives such as '.space'.
end_comment

begin_function_decl
name|virtual
name|void
name|emitFill
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|,
name|uint8_t
name|FillValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit \p Size bytes worth of the value specified by \p FillValue.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .space or .skip.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumBytes - The number of bytes to emit.
end_comment

begin_comment
comment|/// \param FillValue - The value to use when filling bytes.
end_comment

begin_comment
comment|/// \param Loc - The location of the expression for error reporting.
end_comment

begin_function_decl
name|virtual
name|void
name|emitFill
parameter_list|(
specifier|const
name|MCExpr
modifier|&
name|NumBytes
parameter_list|,
name|uint64_t
name|FillValue
parameter_list|,
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit \p NumValues copies of \p Size bytes. Each \p Size bytes is
end_comment

begin_comment
comment|/// taken from the lowest order 4 bytes of \p Expr expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used to implement assembler directives such as .fill.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumValues - The number of copies of \p Size bytes to emit.
end_comment

begin_comment
comment|/// \param Size - The size (in bytes) of each repeated value.
end_comment

begin_comment
comment|/// \param Expr - The expression from which \p Size bytes are used.
end_comment

begin_function_decl
name|virtual
name|void
name|emitFill
parameter_list|(
name|uint64_t
name|NumValues
parameter_list|,
name|int64_t
name|Size
parameter_list|,
name|int64_t
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|emitFill
parameter_list|(
specifier|const
name|MCExpr
modifier|&
name|NumValues
parameter_list|,
name|int64_t
name|Size
parameter_list|,
name|int64_t
name|Expr
parameter_list|,
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit NumBytes worth of zeros.
end_comment

begin_comment
comment|/// This function properly handles data in virtual sections.
end_comment

begin_function_decl
name|void
name|EmitZeros
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit some number of copies of \p Value until the byte alignment \p
end_comment

begin_comment
comment|/// ByteAlignment is reached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the number of bytes need to emit for the alignment is not a multiple
end_comment

begin_comment
comment|/// of \p ValueSize, then the contents of the emitted fill bytes is
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
comment|/// \param ByteAlignment - The alignment to reach. This must be a power of
end_comment

begin_comment
comment|/// two on some targets.
end_comment

begin_comment
comment|/// \param Value - The value to use when filling bytes.
end_comment

begin_comment
comment|/// \param ValueSize - The size of the integer (in bytes) to emit for
end_comment

begin_comment
comment|/// \p Value. This must match a native machine width.
end_comment

begin_comment
comment|/// \param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit nops until the byte alignment \p ByteAlignment is reached.
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
comment|/// \param ByteAlignment - The alignment to reach. This must be a power of
end_comment

begin_comment
comment|/// two on some targets.
end_comment

begin_comment
comment|/// \param MaxBytesToEmit - The maximum numbers of bytes to emit, or 0. If
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
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit some number of copies of \p Value until the byte offset \p
end_comment

begin_comment
comment|/// Offset is reached.
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
comment|/// \param Offset - The offset to reach. This may be an expression, but the
end_comment

begin_comment
comment|/// expression must be associated with the current section.
end_comment

begin_comment
comment|/// \param Value - The value to use when filling bytes.
end_comment

begin_function_decl
name|virtual
name|void
name|emitValueToOffset
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Offset
parameter_list|,
name|unsigned
name|char
name|Value
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \brief Switch to a new logical file.  This is used to implement the '.file
end_comment

begin_comment
comment|/// "foo.c"' assembler directive.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitFileDirective
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the "identifiers" directive.  This implements the
end_comment

begin_comment
comment|/// '.ident "version foo"' assembler directive.
end_comment

begin_function
name|virtual
name|void
name|EmitIdent
parameter_list|(
name|StringRef
name|IdentString
parameter_list|)
block|{}
end_function

begin_comment
comment|/// \brief Associate a filename with a specified logical file number.  This
end_comment

begin_comment
comment|/// implements the DWARF2 '.file 4 "foo.c"' assembler directive.
end_comment

begin_function_decl
name|virtual
name|unsigned
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
parameter_list|,
name|unsigned
name|CUID
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This implements the DWARF2 '.loc fileno lineno ...' assembler
end_comment

begin_comment
comment|/// directive.
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

begin_comment
comment|/// \brief Associate a filename with a specified logical file number.  This
end_comment

begin_comment
comment|/// implements the '.cv_file 4 "foo.c"' assembler directive. Returns true on
end_comment

begin_comment
comment|/// success.
end_comment

begin_function_decl
name|virtual
name|bool
name|EmitCVFileDirective
parameter_list|(
name|unsigned
name|FileNo
parameter_list|,
name|StringRef
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Introduces a function id for use with .cv_loc.
end_comment

begin_function_decl
name|virtual
name|bool
name|EmitCVFuncIdDirective
parameter_list|(
name|unsigned
name|FunctionId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Introduces an inline call site id for use with .cv_loc. Includes
end_comment

begin_comment
comment|/// extra information for inline line table generation.
end_comment

begin_function_decl
name|virtual
name|bool
name|EmitCVInlineSiteIdDirective
parameter_list|(
name|unsigned
name|FunctionId
parameter_list|,
name|unsigned
name|IAFunc
parameter_list|,
name|unsigned
name|IAFile
parameter_list|,
name|unsigned
name|IALine
parameter_list|,
name|unsigned
name|IACol
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This implements the CodeView '.cv_loc' assembler directive.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCVLocDirective
parameter_list|(
name|unsigned
name|FunctionId
parameter_list|,
name|unsigned
name|FileNo
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Column
parameter_list|,
name|bool
name|PrologueEnd
parameter_list|,
name|bool
name|IsStmt
parameter_list|,
name|StringRef
name|FileName
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This implements the CodeView '.cv_linetable' assembler directive.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCVLinetableDirective
parameter_list|(
name|unsigned
name|FunctionId
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|FnStart
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|FnEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This implements the CodeView '.cv_inline_linetable' assembler
end_comment

begin_comment
comment|/// directive.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitCVInlineLinetableDirective
parameter_list|(
name|unsigned
name|PrimaryFunctionId
parameter_list|,
name|unsigned
name|SourceFileId
parameter_list|,
name|unsigned
name|SourceLineNum
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|FnStartSym
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|FnEndSym
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This implements the CodeView '.cv_def_range' assembler
end_comment

begin_comment
comment|/// directive.
end_comment

begin_decl_stmt
name|virtual
name|void
name|EmitCVDefRangeDirective
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbol
operator|*
argument_list|,
specifier|const
name|MCSymbol
operator|*
operator|>>
name|Ranges
argument_list|,
name|StringRef
name|FixedSizePortion
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief This implements the CodeView '.cv_stringtable' assembler directive.
end_comment

begin_function
name|virtual
name|void
name|EmitCVStringTableDirective
parameter_list|()
block|{}
end_function

begin_comment
comment|/// \brief This implements the CodeView '.cv_filechecksums' assembler directive.
end_comment

begin_function
name|virtual
name|void
name|EmitCVFileChecksumsDirective
parameter_list|()
block|{}
end_function

begin_comment
comment|/// Emit the absolute difference between two symbols.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre Offset of \c Hi is greater than the offset \c Lo.
end_comment

begin_function_decl
name|virtual
name|void
name|emitAbsoluteSymbolDiff
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Hi
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Lo
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|MCSymbol
modifier|*
name|getDwarfLineTableSymbol
parameter_list|(
name|unsigned
name|CUID
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
parameter_list|(
name|bool
name|IsSimple
parameter_list|)
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
name|EmitCFIGnuArgsSize
parameter_list|(
name|int64_t
name|Size
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
name|EmitCFIUndefined
parameter_list|(
name|int64_t
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIRegister
parameter_list|(
name|int64_t
name|Register1
parameter_list|,
name|int64_t
name|Register2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitCFIWindowSave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFIStartProc
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
name|EmitWinCFIEndProc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFIStartChained
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFIEndChained
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFIPushReg
parameter_list|(
name|unsigned
name|Register
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFISetFrame
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
name|EmitWinCFIAllocStack
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFISaveReg
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
name|EmitWinCFISaveXMM
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
name|EmitWinCFIPushFrame
parameter_list|(
name|bool
name|Code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinCFIEndProlog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitWinEHHandler
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
name|EmitWinEHHandlerData
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Get the .pdata section used for the given section. Typically the given
end_comment

begin_comment
comment|/// section is either the main .text section or some other COMDAT .text
end_comment

begin_comment
comment|/// section, but it may be any section containing code.
end_comment

begin_function_decl
name|MCSection
modifier|*
name|getAssociatedPDataSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|TextSec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the .xdata section used for the given section.
end_comment

begin_function_decl
name|MCSection
modifier|*
name|getAssociatedXDataSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|TextSec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|EmitSyntaxDirective
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a .reloc directive.
end_comment

begin_comment
comment|/// Returns true if the relocation could not be emitted because Name is not
end_comment

begin_comment
comment|/// known.
end_comment

begin_function
name|virtual
name|bool
name|EmitRelocDirective
parameter_list|(
specifier|const
name|MCExpr
modifier|&
name|Offset
parameter_list|,
name|StringRef
name|Name
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Expr
parameter_list|,
name|SMLoc
name|Loc
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// \brief Emit the given \p Instruction into the current section.
end_comment

begin_comment
comment|/// PrintSchedInfo == true then schedul comment should be added to output
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
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|bool
name|PrintSchedInfo
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the bundle alignment mode from now on in the section.
end_comment

begin_comment
comment|/// The argument is the power of 2 to which the alignment is set. The
end_comment

begin_comment
comment|/// value 0 means turn the bundle alignment off.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitBundleAlignMode
parameter_list|(
name|unsigned
name|AlignPow2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The following instructions are a bundle-locked group.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AlignToEnd - If true, the bundle-locked group will be aligned to
end_comment

begin_comment
comment|///                     the end of a bundle.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitBundleLock
parameter_list|(
name|bool
name|AlignToEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Ends a bundle-locked group.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitBundleUnlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If this file is backed by a assembly streamer, this dumps the
end_comment

begin_comment
comment|/// specified string in the output .s file.  This capability is indicated by
end_comment

begin_comment
comment|/// the hasRawTextSupport() predicate.  By default this aborts.
end_comment

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
comment|/// \brief Streamer specific finalization.
end_comment

begin_function_decl
name|virtual
name|void
name|FinishImpl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Finish emission of machine code.
end_comment

begin_function_decl
name|void
name|Finish
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|bool
name|mayHaveInstructions
argument_list|(
name|MCSection
operator|&
name|Sec
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// Create a dummy machine code streamer, which does nothing. This is useful for
end_comment

begin_comment
comment|/// timing the assembler front end.
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
comment|/// Create a machine code streamer which will print out assembly for the native
end_comment

begin_comment
comment|/// target, suitable for compiling with a native assembler.
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
comment|/// encoding inline with the assembly. This method takes ownership of \p CE.
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
comment|/// ownership of \p TAB.
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

begin_decl_stmt
name|MCStreamer
modifier|*
name|createAsmStreamer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|formatted_raw_ostream
operator|>
name|OS
argument_list|,
name|bool
name|isVerboseAsm
argument_list|,
name|bool
name|useDwarfDirectory
argument_list|,
name|MCInstPrinter
operator|*
name|InstPrint
argument_list|,
name|MCCodeEmitter
operator|*
name|CE
argument_list|,
name|MCAsmBackend
operator|*
name|TAB
argument_list|,
name|bool
name|ShowInst
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCSTREAMER_H
end_comment

end_unit

