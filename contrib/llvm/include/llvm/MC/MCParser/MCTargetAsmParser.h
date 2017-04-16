begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCTargetAsmParser.h - Target Assembly Parser -----*- C++ -*-===//
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
name|LLVM_MC_MCPARSER_MCTARGETASMPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCPARSER_MCTARGETASMPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmLexer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmParserExtension.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCTargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MCParsedAsmOperand
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MCParsedAsmOperand
operator|>>
name|OperandVector
expr_stmt|;
enum|enum
name|AsmRewriteKind
block|{
name|AOK_Delete
init|=
literal|0
block|,
comment|// Rewrite should be ignored.
name|AOK_Align
block|,
comment|// Rewrite align as .align.
name|AOK_EVEN
block|,
comment|// Rewrite even as .even.
name|AOK_DotOperator
block|,
comment|// Rewrite a dot operator expression as an immediate.
comment|// E.g., [eax].foo.bar -> [eax].8
name|AOK_Emit
block|,
comment|// Rewrite _emit as .byte.
name|AOK_Imm
block|,
comment|// Rewrite as $$N.
name|AOK_ImmPrefix
block|,
comment|// Add $$ before a parsed Imm.
name|AOK_Input
block|,
comment|// Rewrite in terms of $N.
name|AOK_Output
block|,
comment|// Rewrite in terms of $N.
name|AOK_SizeDirective
block|,
comment|// Add a sizing directive (e.g., dword ptr).
name|AOK_Label
block|,
comment|// Rewrite local labels.
name|AOK_EndOfStatement
block|,
comment|// Add EndOfStatement (e.g., "\n\t").
name|AOK_Skip
comment|// Skip emission (e.g., offset/type operators).
block|}
enum|;
specifier|const
name|char
name|AsmRewritePrecedence
index|[]
init|=
block|{
literal|0
block|,
comment|// AOK_Delete
literal|2
block|,
comment|// AOK_Align
literal|2
block|,
comment|// AOK_EVEN
literal|2
block|,
comment|// AOK_DotOperator
literal|2
block|,
comment|// AOK_Emit
literal|4
block|,
comment|// AOK_Imm
literal|4
block|,
comment|// AOK_ImmPrefix
literal|3
block|,
comment|// AOK_Input
literal|3
block|,
comment|// AOK_Output
literal|5
block|,
comment|// AOK_SizeDirective
literal|1
block|,
comment|// AOK_Label
literal|5
block|,
comment|// AOK_EndOfStatement
literal|2
comment|// AOK_Skip
block|}
decl_stmt|;
struct|struct
name|AsmRewrite
block|{
name|AsmRewriteKind
name|Kind
decl_stmt|;
name|SMLoc
name|Loc
decl_stmt|;
name|unsigned
name|Len
decl_stmt|;
name|unsigned
name|Val
decl_stmt|;
name|StringRef
name|Label
decl_stmt|;
name|public
label|:
name|AsmRewrite
argument_list|(
argument|AsmRewriteKind kind
argument_list|,
argument|SMLoc loc
argument_list|,
argument|unsigned len =
literal|0
argument_list|,
argument|unsigned val =
literal|0
argument_list|)
block|:
name|Kind
argument_list|(
name|kind
argument_list|)
operator|,
name|Loc
argument_list|(
name|loc
argument_list|)
operator|,
name|Len
argument_list|(
name|len
argument_list|)
operator|,
name|Val
argument_list|(
argument|val
argument_list|)
block|{}
name|AsmRewrite
argument_list|(
argument|AsmRewriteKind kind
argument_list|,
argument|SMLoc loc
argument_list|,
argument|unsigned len
argument_list|,
argument|StringRef label
argument_list|)
operator|:
name|Kind
argument_list|(
name|kind
argument_list|)
operator|,
name|Loc
argument_list|(
name|loc
argument_list|)
operator|,
name|Len
argument_list|(
name|len
argument_list|)
operator|,
name|Val
argument_list|(
literal|0
argument_list|)
operator|,
name|Label
argument_list|(
argument|label
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|ParseInstructionInfo
block|{
name|SmallVectorImpl
operator|<
name|AsmRewrite
operator|>
operator|*
name|AsmRewrites
operator|=
name|nullptr
expr_stmt|;
name|ParseInstructionInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ParseInstructionInfo
argument_list|(
name|SmallVectorImpl
operator|<
name|AsmRewrite
operator|>
operator|*
name|rewrites
argument_list|)
operator|:
name|AsmRewrites
argument_list|(
argument|rewrites
argument_list|)
block|{}
block|}
struct|;
enum|enum
name|OperandMatchResultTy
block|{
name|MatchOperand_Success
block|,
comment|// operand matched successfully
name|MatchOperand_NoMatch
block|,
comment|// operand did not match
name|MatchOperand_ParseFail
comment|// operand matched but had errors
block|}
enum|;
comment|/// MCTargetAsmParser - Generic interface to target specific assembly parsers.
name|class
name|MCTargetAsmParser
range|:
name|public
name|MCAsmParserExtension
block|{
name|public
operator|:
expr|enum
name|MatchResultTy
block|{
name|Match_InvalidOperand
block|,
name|Match_MissingFeature
block|,
name|Match_MnemonicFail
block|,
name|Match_Success
block|,
name|FIRST_TARGET_MATCH_RESULT_TY
block|}
block|;
name|protected
operator|:
comment|// Can only create subclasses.
name|MCTargetAsmParser
argument_list|(
name|MCTargetOptions
specifier|const
operator|&
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
block|;
comment|/// Create a copy of STI and return a non-const reference to it.
name|MCSubtargetInfo
operator|&
name|copySTI
argument_list|()
block|;
comment|/// AvailableFeatures - The current set of available features.
name|uint64_t
name|AvailableFeatures
operator|=
literal|0
block|;
comment|/// ParsingInlineAsm - Are we parsing ms-style inline assembly?
name|bool
name|ParsingInlineAsm
operator|=
name|false
block|;
comment|/// SemaCallback - The Sema callback implementation.  Must be set when parsing
comment|/// ms-style inline assembly.
name|MCAsmParserSemaCallback
operator|*
name|SemaCallback
block|;
comment|/// Set of options which affects instrumentation of inline assembly.
name|MCTargetOptions
name|MCOptions
block|;
comment|/// Current STI.
specifier|const
name|MCSubtargetInfo
operator|*
name|STI
block|;
name|public
operator|:
name|MCTargetAsmParser
argument_list|(
specifier|const
name|MCTargetAsmParser
operator|&
argument_list|)
operator|=
name|delete
block|;
name|MCTargetAsmParser
operator|&
name|operator
operator|=
operator|(
specifier|const
name|MCTargetAsmParser
operator|&
operator|)
operator|=
name|delete
block|;
operator|~
name|MCTargetAsmParser
argument_list|()
name|override
block|;
specifier|const
name|MCSubtargetInfo
operator|&
name|getSTI
argument_list|()
specifier|const
block|;
name|uint64_t
name|getAvailableFeatures
argument_list|()
specifier|const
block|{
return|return
name|AvailableFeatures
return|;
block|}
name|void
name|setAvailableFeatures
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|AvailableFeatures
operator|=
name|Value
block|; }
name|bool
name|isParsingInlineAsm
argument_list|()
block|{
return|return
name|ParsingInlineAsm
return|;
block|}
name|void
name|setParsingInlineAsm
argument_list|(
argument|bool Value
argument_list|)
block|{
name|ParsingInlineAsm
operator|=
name|Value
block|; }
name|MCTargetOptions
name|getTargetOptions
argument_list|()
specifier|const
block|{
return|return
name|MCOptions
return|;
block|}
name|void
name|setSemaCallback
argument_list|(
argument|MCAsmParserSemaCallback *Callback
argument_list|)
block|{
name|SemaCallback
operator|=
name|Callback
block|;   }
name|virtual
name|bool
name|ParseRegister
argument_list|(
name|unsigned
operator|&
name|RegNo
argument_list|,
name|SMLoc
operator|&
name|StartLoc
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
operator|=
literal|0
block|;
comment|/// Sets frame register corresponding to the current MachineFunction.
name|virtual
name|void
name|SetFrameRegister
argument_list|(
argument|unsigned RegNo
argument_list|)
block|{}
comment|/// ParseInstruction - Parse one assembly instruction.
comment|///
comment|/// The parser is positioned following the instruction name. The target
comment|/// specific instruction parser should parse the entire instruction and
comment|/// construct the appropriate MCInst, or emit an error. On success, the entire
comment|/// line should be parsed up to and including the end-of-statement token. On
comment|/// failure, the parser is not required to read to the end of the line.
comment|//
comment|/// \param Name - The instruction name.
comment|/// \param NameLoc - The source location of the name.
comment|/// \param Operands [out] - The list of parsed operands, this returns
comment|///        ownership of them to the caller.
comment|/// \return True on failure.
name|virtual
name|bool
name|ParseInstruction
argument_list|(
argument|ParseInstructionInfo&Info
argument_list|,
argument|StringRef Name
argument_list|,
argument|SMLoc NameLoc
argument_list|,
argument|OperandVector&Operands
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ParseInstruction
argument_list|(
argument|ParseInstructionInfo&Info
argument_list|,
argument|StringRef Name
argument_list|,
argument|AsmToken Token
argument_list|,
argument|OperandVector&Operands
argument_list|)
block|{
return|return
name|ParseInstruction
argument_list|(
name|Info
argument_list|,
name|Name
argument_list|,
name|Token
operator|.
name|getLoc
argument_list|()
argument_list|,
name|Operands
argument_list|)
return|;
block|}
comment|/// ParseDirective - Parse a target specific assembler directive
comment|///
comment|/// The parser is positioned following the directive name.  The target
comment|/// specific directive parser should parse the entire directive doing or
comment|/// recording any target specific work, or return true and do nothing if the
comment|/// directive is not target specific. If the directive is specific for
comment|/// the target, the entire line is parsed up to and including the
comment|/// end-of-statement token and false is returned.
comment|///
comment|/// \param DirectiveID - the identifier token of the directive.
name|virtual
name|bool
name|ParseDirective
argument_list|(
argument|AsmToken DirectiveID
argument_list|)
operator|=
literal|0
block|;
comment|/// MatchAndEmitInstruction - Recognize a series of operands of a parsed
comment|/// instruction as an actual MCInst and emit it to the specified MCStreamer.
comment|/// This returns false on success and returns true on failure to match.
comment|///
comment|/// On failure, the target parser is responsible for emitting a diagnostic
comment|/// explaining the match failure.
name|virtual
name|bool
name|MatchAndEmitInstruction
argument_list|(
argument|SMLoc IDLoc
argument_list|,
argument|unsigned&Opcode
argument_list|,
argument|OperandVector&Operands
argument_list|,
argument|MCStreamer&Out
argument_list|,
argument|uint64_t&ErrorInfo
argument_list|,
argument|bool MatchingInlineAsm
argument_list|)
operator|=
literal|0
block|;
comment|/// Allows targets to let registers opt out of clobber lists.
name|virtual
name|bool
name|OmitRegisterFromClobberLists
argument_list|(
argument|unsigned RegNo
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Allow a target to add special case operand matching for things that
comment|/// tblgen doesn't/can't handle effectively. For example, literal
comment|/// immediates on ARM. TableGen expects a token operand, but the parser
comment|/// will recognize them as immediates.
name|virtual
name|unsigned
name|validateTargetOperandClass
argument_list|(
argument|MCParsedAsmOperand&Op
argument_list|,
argument|unsigned Kind
argument_list|)
block|{
return|return
name|Match_InvalidOperand
return|;
block|}
comment|/// Validate the instruction match against any complex target predicates
comment|/// before rendering any operands to it.
name|virtual
name|unsigned
name|checkEarlyTargetMatchPredicate
argument_list|(
argument|MCInst&Inst
argument_list|,
argument|const OperandVector&Operands
argument_list|)
block|{
return|return
name|Match_Success
return|;
block|}
comment|/// checkTargetMatchPredicate - Validate the instruction match against
comment|/// any complex target predicates not expressible via match classes.
name|virtual
name|unsigned
name|checkTargetMatchPredicate
argument_list|(
argument|MCInst&Inst
argument_list|)
block|{
return|return
name|Match_Success
return|;
block|}
name|virtual
name|void
name|convertToMapAndConstraints
argument_list|(
argument|unsigned Kind
argument_list|,
argument|const OperandVector&Operands
argument_list|)
operator|=
literal|0
block|;
comment|// Return whether this parser uses assignment statements with equals tokens
name|virtual
name|bool
name|equalIsAsmAssignment
argument_list|()
block|{
return|return
name|true
return|;
block|}
block|;
comment|// Return whether this start of statement identifier is a label
name|virtual
name|bool
name|isLabel
argument_list|(
argument|AsmToken&Token
argument_list|)
block|{
return|return
name|true
return|;
block|}
block|;
name|virtual
specifier|const
name|MCExpr
operator|*
name|applyModifierToExpr
argument_list|(
argument|const MCExpr *E
argument_list|,
argument|MCSymbolRefExpr::VariantKind
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|onLabelParsed
argument_list|(
argument|MCSymbol *Symbol
argument_list|)
block|{}
comment|/// Ensure that all previously parsed instructions have been emitted to the
comment|/// output streamer, if the target does not emit them immediately.
name|virtual
name|void
name|flushPendingInstructions
argument_list|(
argument|MCStreamer&Out
argument_list|)
block|{}
name|virtual
specifier|const
name|MCExpr
operator|*
name|createTargetUnaryExpr
argument_list|(
argument|const MCExpr *E
argument_list|,
argument|AsmToken::TokenKind OperatorToken
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCPARSER_MCTARGETASMPARSER_H
end_comment

end_unit

