begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCTargetAsmParser.h - Target Assembly Parser ----*- C++ -*-===//
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
name|LLVM_MC_TARGETPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_TARGETPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmParserExtension.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|AsmToken
decl_stmt|;
name|class
name|MCParsedAsmOperand
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
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
literal|1
block|,
comment|// AOK_Align
literal|1
block|,
comment|// AOK_DotOperator
literal|1
block|,
comment|// AOK_Emit
literal|3
block|,
comment|// AOK_Imm
literal|3
block|,
comment|// AOK_ImmPrefix
literal|2
block|,
comment|// AOK_Input
literal|2
block|,
comment|// AOK_Output
literal|4
block|,
comment|// AOK_SizeDirective
literal|1
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
expr_stmt|;
name|ParseInstructionInfo
argument_list|()
operator|:
name|AsmRewrites
argument_list|(
literal|0
argument_list|)
block|{}
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
operator|~
name|ParseInstructionInfo
argument_list|()
block|{}
block|}
struct|;
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
name|private
operator|:
name|MCTargetAsmParser
argument_list|(
argument|const MCTargetAsmParser&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCTargetAsmParser
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
comment|// Can only create subclasses.
name|MCTargetAsmParser
argument_list|()
block|;
comment|/// AvailableFeatures - The current set of available features.
name|unsigned
name|AvailableFeatures
block|;
comment|/// ParsingInlineAsm - Are we parsing ms-style inline assembly?
name|bool
name|ParsingInlineAsm
block|;
comment|/// SemaCallback - The Sema callback implementation.  Must be set when parsing
comment|/// ms-style inline assembly.
name|MCAsmParserSemaCallback
operator|*
name|SemaCallback
block|;
name|public
operator|:
name|virtual
operator|~
name|MCTargetAsmParser
argument_list|()
block|;
name|unsigned
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
argument|unsigned Value
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
argument|SmallVectorImpl<MCParsedAsmOperand*>&Operands
argument_list|)
operator|=
literal|0
block|;
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
comment|/// mnemonicIsValid - This returns true if this is a valid mnemonic and false
comment|/// otherwise.
name|virtual
name|bool
name|mnemonicIsValid
argument_list|(
argument|StringRef Mnemonic
argument_list|,
argument|unsigned VariantID
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
argument|SmallVectorImpl<MCParsedAsmOperand*>&Operands
argument_list|,
argument|MCStreamer&Out
argument_list|,
argument|unsigned&ErrorInfo
argument_list|,
argument|bool MatchingInlineAsm
argument_list|)
operator|=
literal|0
block|;
comment|/// Allow a target to add special case operand matching for things that
comment|/// tblgen doesn't/can't handle effectively. For example, literal
comment|/// immediates on ARM. TableGen expects a token operand, but the parser
comment|/// will recognize them as immediates.
name|virtual
name|unsigned
name|validateTargetOperandClass
argument_list|(
argument|MCParsedAsmOperand *Op
argument_list|,
argument|unsigned Kind
argument_list|)
block|{
return|return
name|Match_InvalidOperand
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
argument|const SmallVectorImpl<MCParsedAsmOperand*>&Operands
argument_list|)
operator|=
literal|0
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
literal|0
return|;
block|}
name|virtual
name|void
name|onLabelParsed
argument_list|(
argument|MCSymbol *Symbol
argument_list|)
block|{ }
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

