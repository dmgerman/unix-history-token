begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmParser.h - Parser for Assembly Files ------------------*- C++ -*-===//
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
comment|// This class declares the parser for assembly files.
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
name|ASMPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|ASMPARSER_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"AsmLexer.h"
end_include

begin_include
include|#
directive|include
file|"AsmCond.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmParser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSectionMachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmCond
decl_stmt|;
name|class
name|AsmToken
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
name|MCStreamer
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|TargetAsmParser
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|AsmParser
range|:
name|public
name|MCAsmParser
block|{
name|private
operator|:
name|AsmLexer
name|Lexer
block|;
name|MCContext
operator|&
name|Ctx
block|;
name|MCStreamer
operator|&
name|Out
block|;
name|SourceMgr
operator|&
name|SrcMgr
block|;
name|TargetAsmParser
operator|*
name|TargetParser
block|;
comment|/// This is the current buffer index we're lexing from as managed by the
comment|/// SourceMgr object.
name|int
name|CurBuffer
block|;
name|AsmCond
name|TheCondState
block|;
name|std
operator|::
name|vector
operator|<
name|AsmCond
operator|>
name|TheCondStack
block|;
comment|// FIXME: Figure out where this should leave, the code is a copy of that which
comment|// is also used by TargetLoweringObjectFile.
name|mutable
name|void
operator|*
name|SectionUniquingMap
block|;
comment|/// DirectiveMap - This is a table handlers for directives.  Each handler is
comment|/// invoked after the directive identifier is read and is responsible for
comment|/// parsing and validating the rest of the directive.  The handler is passed
comment|/// in the directive name and the location of the directive keyword.
name|StringMap
operator|<
name|bool
argument_list|(
name|AsmParser
operator|::
operator|*
argument_list|)
argument_list|(
name|StringRef
argument_list|,
name|SMLoc
argument_list|)
operator|>
name|DirectiveMap
block|;
name|public
operator|:
name|AsmParser
argument_list|(
name|SourceMgr
operator|&
name|_SM
argument_list|,
name|MCContext
operator|&
name|_Ctx
argument_list|,
name|MCStreamer
operator|&
name|_Out
argument_list|,
specifier|const
name|MCAsmInfo
operator|&
name|_MAI
argument_list|)
block|;
operator|~
name|AsmParser
argument_list|()
block|;
name|bool
name|Run
argument_list|()
block|;
name|void
name|AddDirectiveHandler
argument_list|(
argument|StringRef Directive
argument_list|,
argument|bool (AsmParser::*Handler)(StringRef, SMLoc)
argument_list|)
block|{
name|DirectiveMap
index|[
name|Directive
index|]
operator|=
name|Handler
block|;   }
name|public
operator|:
name|TargetAsmParser
operator|&
name|getTargetParser
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TargetParser
return|;
block|}
name|void
name|setTargetParser
argument_list|(
argument|TargetAsmParser&P
argument_list|)
block|{
name|TargetParser
operator|=
operator|&
name|P
block|; }
comment|/// @name MCAsmParser Interface
comment|/// {
name|virtual
name|MCAsmLexer
operator|&
name|getLexer
argument_list|()
block|{
return|return
name|Lexer
return|;
block|}
name|virtual
name|MCContext
operator|&
name|getContext
argument_list|()
block|{
return|return
name|Ctx
return|;
block|}
name|virtual
name|MCStreamer
operator|&
name|getStreamer
argument_list|()
block|{
return|return
name|Out
return|;
block|}
name|virtual
name|void
name|Warning
argument_list|(
argument|SMLoc L
argument_list|,
argument|const Twine&Meg
argument_list|)
block|;
name|virtual
name|bool
name|Error
argument_list|(
argument|SMLoc L
argument_list|,
argument|const Twine&Msg
argument_list|)
block|;
specifier|const
name|AsmToken
operator|&
name|Lex
argument_list|()
block|;
name|bool
name|ParseExpression
argument_list|(
specifier|const
name|MCExpr
operator|*
operator|&
name|Res
argument_list|)
block|;
name|virtual
name|bool
name|ParseExpression
argument_list|(
specifier|const
name|MCExpr
operator|*
operator|&
name|Res
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
block|;
name|virtual
name|bool
name|ParseParenExpression
argument_list|(
specifier|const
name|MCExpr
operator|*
operator|&
name|Res
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
block|;
name|virtual
name|bool
name|ParseAbsoluteExpression
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|)
block|;
comment|/// }
name|private
operator|:
name|MCSymbol
operator|*
name|CreateSymbol
argument_list|(
argument|StringRef Name
argument_list|)
block|;
comment|// FIXME: See comment on SectionUniquingMap.
specifier|const
name|MCSection
operator|*
name|getMachOSection
argument_list|(
argument|const StringRef&Segment
argument_list|,
argument|const StringRef&Section
argument_list|,
argument|unsigned TypeAndAttributes
argument_list|,
argument|unsigned Reserved2
argument_list|,
argument|SectionKind Kind
argument_list|)
specifier|const
block|;
name|bool
name|ParseStatement
argument_list|()
block|;
name|bool
name|TokError
argument_list|(
specifier|const
name|char
operator|*
name|Msg
argument_list|)
block|;
name|void
name|PrintMessage
argument_list|(
argument|SMLoc Loc
argument_list|,
argument|const std::string&Msg
argument_list|,
argument|const char *Type
argument_list|)
specifier|const
block|;
comment|/// EnterIncludeFile - Enter the specified file. This returns true on failure.
name|bool
name|EnterIncludeFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
block|;
name|bool
name|ParseConditionalAssemblyDirectives
argument_list|(
argument|StringRef Directive
argument_list|,
argument|SMLoc DirectiveLoc
argument_list|)
block|;
name|void
name|EatToEndOfStatement
argument_list|()
block|;
name|bool
name|ParseAssignment
argument_list|(
specifier|const
name|StringRef
operator|&
name|Name
argument_list|)
block|;
name|bool
name|ParsePrimaryExpr
argument_list|(
specifier|const
name|MCExpr
operator|*
operator|&
name|Res
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
block|;
name|bool
name|ParseBinOpRHS
argument_list|(
argument|unsigned Precedence
argument_list|,
argument|const MCExpr *&Res
argument_list|,
argument|SMLoc&EndLoc
argument_list|)
block|;
name|bool
name|ParseParenExpr
argument_list|(
specifier|const
name|MCExpr
operator|*
operator|&
name|Res
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
block|;
comment|/// ParseIdentifier - Parse an identifier or string (as a quoted identifier)
comment|/// and set \arg Res to the identifier contents.
name|bool
name|ParseIdentifier
argument_list|(
name|StringRef
operator|&
name|Res
argument_list|)
block|;
comment|// Directive Parsing.
name|bool
name|ParseDirectiveDarwinSection
argument_list|()
block|;
comment|// Darwin specific ".section".
name|bool
name|ParseDirectiveSectionSwitch
argument_list|(
argument|const char *Segment
argument_list|,
argument|const char *Section
argument_list|,
argument|unsigned TAA =
literal|0
argument_list|,
argument|unsigned ImplicitAlign =
literal|0
argument_list|,
argument|unsigned StubSize =
literal|0
argument_list|)
block|;
name|bool
name|ParseDirectiveAscii
argument_list|(
argument|bool ZeroTerminated
argument_list|)
block|;
comment|// ".ascii", ".asciiz"
name|bool
name|ParseDirectiveValue
argument_list|(
argument|unsigned Size
argument_list|)
block|;
comment|// ".byte", ".long", ...
name|bool
name|ParseDirectiveFill
argument_list|()
block|;
comment|// ".fill"
name|bool
name|ParseDirectiveSpace
argument_list|()
block|;
comment|// ".space"
name|bool
name|ParseDirectiveSet
argument_list|()
block|;
comment|// ".set"
name|bool
name|ParseDirectiveOrg
argument_list|()
block|;
comment|// ".org"
comment|// ".align{,32}", ".p2align{,w,l}"
name|bool
name|ParseDirectiveAlign
argument_list|(
argument|bool IsPow2
argument_list|,
argument|unsigned ValueSize
argument_list|)
block|;
comment|/// ParseDirectiveSymbolAttribute - Parse a directive like ".globl" which
comment|/// accepts a single symbol (which should be a label or an external).
name|bool
name|ParseDirectiveSymbolAttribute
argument_list|(
argument|MCStreamer::SymbolAttr Attr
argument_list|)
block|;
name|bool
name|ParseDirectiveDarwinSymbolDesc
argument_list|()
block|;
comment|// Darwin specific ".desc"
name|bool
name|ParseDirectiveDarwinLsym
argument_list|()
block|;
comment|// Darwin specific ".lsym"
name|bool
name|ParseDirectiveComm
argument_list|(
argument|bool IsLocal
argument_list|)
block|;
comment|// ".comm" and ".lcomm"
name|bool
name|ParseDirectiveDarwinZerofill
argument_list|()
block|;
comment|// Darwin specific ".zerofill"
comment|// Darwin specific ".subsections_via_symbols"
name|bool
name|ParseDirectiveDarwinSubsectionsViaSymbols
argument_list|()
block|;
comment|// Darwin specific .dump and .load
name|bool
name|ParseDirectiveDarwinDumpOrLoad
argument_list|(
argument|SMLoc IDLoc
argument_list|,
argument|bool IsDump
argument_list|)
block|;
name|bool
name|ParseDirectiveAbort
argument_list|()
block|;
comment|// ".abort"
name|bool
name|ParseDirectiveInclude
argument_list|()
block|;
comment|// ".include"
name|bool
name|ParseDirectiveIf
argument_list|(
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".if"
name|bool
name|ParseDirectiveElseIf
argument_list|(
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".elseif"
name|bool
name|ParseDirectiveElse
argument_list|(
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".else"
name|bool
name|ParseDirectiveEndIf
argument_list|(
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// .endif
name|bool
name|ParseDirectiveFile
argument_list|(
argument|StringRef
argument_list|,
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".file"
name|bool
name|ParseDirectiveLine
argument_list|(
argument|StringRef
argument_list|,
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".line"
name|bool
name|ParseDirectiveLoc
argument_list|(
argument|StringRef
argument_list|,
argument|SMLoc DirectiveLoc
argument_list|)
block|;
comment|// ".loc"
comment|/// ParseEscapedString - Parse the current token as a string which may include
comment|/// escaped characters and return the string contents.
name|bool
name|ParseEscapedString
argument_list|(
name|std
operator|::
name|string
operator|&
name|Data
argument_list|)
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

