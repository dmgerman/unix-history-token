begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TGLexer.h - Lexer for TableGen Files ---------------------*- C++ -*-===//
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
comment|// This class represents the Lexer for tablegen files.
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
name|TGLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|TGLEXER_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|namespace
name|tgtok
block|{
enum|enum
name|TokKind
block|{
comment|// Markers
name|Eof
block|,
name|Error
block|,
comment|// Tokens with no info.
name|minus
block|,
name|plus
block|,
comment|// - +
name|l_square
block|,
name|r_square
block|,
comment|// [ ]
name|l_brace
block|,
name|r_brace
block|,
comment|// { }
name|l_paren
block|,
name|r_paren
block|,
comment|// ( )
name|less
block|,
name|greater
block|,
comment|//<>
name|colon
block|,
name|semi
block|,
comment|// ; :
name|comma
block|,
name|period
block|,
comment|// , .
name|equal
block|,
name|question
block|,
comment|// = ?
comment|// Keywords.
name|Bit
block|,
name|Bits
block|,
name|Class
block|,
name|Code
block|,
name|Dag
block|,
name|Def
block|,
name|Defm
block|,
name|Field
block|,
name|In
block|,
name|Int
block|,
name|Let
block|,
name|List
block|,
name|MultiClass
block|,
name|String
block|,
comment|// !keywords.
name|XConcat
block|,
name|XSRA
block|,
name|XSRL
block|,
name|XSHL
block|,
name|XStrConcat
block|,
name|XNameConcat
block|,
name|XCast
block|,
name|XSubst
block|,
name|XForEach
block|,
name|XCar
block|,
name|XCdr
block|,
name|XNull
block|,
name|XIf
block|,
name|XEq
block|,
comment|// Integer value.
name|IntVal
block|,
comment|// String valued tokens.
name|Id
block|,
name|StrVal
block|,
name|VarName
block|,
name|CodeFragment
block|}
enum|;
block|}
comment|/// TGLexer - TableGen Lexer class.
name|class
name|TGLexer
block|{
name|SourceMgr
modifier|&
name|SrcMgr
decl_stmt|;
specifier|const
name|char
modifier|*
name|CurPtr
decl_stmt|;
specifier|const
name|MemoryBuffer
modifier|*
name|CurBuf
decl_stmt|;
comment|// Information about the current token.
specifier|const
name|char
modifier|*
name|TokStart
decl_stmt|;
name|tgtok
operator|::
name|TokKind
name|CurCode
expr_stmt|;
name|std
operator|::
name|string
name|CurStrVal
expr_stmt|;
comment|// This is valid for ID, STRVAL, VARNAME, CODEFRAGMENT
name|int64_t
name|CurIntVal
decl_stmt|;
comment|// This is valid for INTVAL.
comment|/// CurBuffer - This is the current buffer index we're lexing from as managed
comment|/// by the SourceMgr object.
name|int
name|CurBuffer
decl_stmt|;
name|public
label|:
name|TGLexer
argument_list|(
name|SourceMgr
operator|&
name|SrcMgr
argument_list|)
expr_stmt|;
operator|~
name|TGLexer
argument_list|()
block|{}
name|tgtok
operator|::
name|TokKind
name|Lex
argument_list|()
block|{
return|return
name|CurCode
operator|=
name|LexToken
argument_list|()
return|;
block|}
name|tgtok
operator|::
name|TokKind
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|CurCode
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getCurStrVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|CurCode
operator|==
name|tgtok
operator|::
name|Id
operator|||
name|CurCode
operator|==
name|tgtok
operator|::
name|StrVal
operator|||
name|CurCode
operator|==
name|tgtok
operator|::
name|VarName
operator|||
name|CurCode
operator|==
name|tgtok
operator|::
name|CodeFragment
operator|)
operator|&&
literal|"This token doesn't have a string value"
argument_list|)
block|;
return|return
name|CurStrVal
return|;
block|}
name|int64_t
name|getCurIntVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CurCode
operator|==
name|tgtok
operator|::
name|IntVal
operator|&&
literal|"This token isn't an integer"
argument_list|)
block|;
return|return
name|CurIntVal
return|;
block|}
name|SMLoc
name|getLoc
argument_list|()
specifier|const
expr_stmt|;
name|void
name|PrintError
argument_list|(
specifier|const
name|char
operator|*
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|)
decl|const
decl_stmt|;
name|void
name|PrintError
argument_list|(
name|SMLoc
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// LexToken - Read the next token and return its code.
name|tgtok
operator|::
name|TokKind
name|LexToken
argument_list|()
expr_stmt|;
name|tgtok
operator|::
name|TokKind
name|ReturnError
argument_list|(
specifier|const
name|char
operator|*
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|)
expr_stmt|;
name|int
name|getNextChar
parameter_list|()
function_decl|;
name|void
name|SkipBCPLComment
parameter_list|()
function_decl|;
name|bool
name|SkipCComment
parameter_list|()
function_decl|;
name|tgtok
operator|::
name|TokKind
name|LexIdentifier
argument_list|()
expr_stmt|;
name|bool
name|LexInclude
parameter_list|()
function_decl|;
name|tgtok
operator|::
name|TokKind
name|LexString
argument_list|()
expr_stmt|;
name|tgtok
operator|::
name|TokKind
name|LexVarName
argument_list|()
expr_stmt|;
name|tgtok
operator|::
name|TokKind
name|LexNumber
argument_list|()
expr_stmt|;
name|tgtok
operator|::
name|TokKind
name|LexBracket
argument_list|()
expr_stmt|;
name|tgtok
operator|::
name|TokKind
name|LexExclaim
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
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

