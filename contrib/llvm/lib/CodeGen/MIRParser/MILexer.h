begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MILexer.h - Lexer for machine instructions -------------------------===//
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
comment|// This file declares the function that lexes the machine instruction source
end_comment

begin_comment
comment|// string.
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
name|LLVM_LIB_CODEGEN_MIRPARSER_MILEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_MIRPARSER_MILEXER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Twine
decl_stmt|;
comment|/// A token produced by the machine instruction lexer.
struct|struct
name|MIToken
block|{
enum|enum
name|TokenKind
block|{
comment|// Markers
name|Eof
block|,
name|Error
block|,
comment|// Tokens with no info.
name|comma
block|,
name|equal
block|,
name|underscore
block|,
name|colon
block|,
comment|// Keywords
name|kw_implicit
block|,
name|kw_implicit_define
block|,
name|kw_dead
block|,
name|kw_killed
block|,
name|kw_undef
block|,
comment|// Identifier tokens
name|Identifier
block|,
name|NamedRegister
block|,
name|MachineBasicBlock
block|,
name|NamedGlobalValue
block|,
name|GlobalValue
block|,
comment|// Other tokens
name|IntegerLiteral
block|,
name|VirtualRegister
block|}
enum|;
name|private
label|:
name|TokenKind
name|Kind
decl_stmt|;
name|unsigned
name|StringOffset
decl_stmt|;
name|StringRef
name|Range
decl_stmt|;
name|APSInt
name|IntVal
decl_stmt|;
name|public
label|:
name|MIToken
argument_list|(
argument|TokenKind Kind
argument_list|,
argument|StringRef Range
argument_list|,
argument|unsigned StringOffset =
literal|0
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|StringOffset
argument_list|(
name|StringOffset
argument_list|)
operator|,
name|Range
argument_list|(
argument|Range
argument_list|)
block|{}
name|MIToken
argument_list|(
argument|TokenKind Kind
argument_list|,
argument|StringRef Range
argument_list|,
argument|const APSInt&IntVal
argument_list|,
argument|unsigned StringOffset =
literal|0
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|StringOffset
argument_list|(
name|StringOffset
argument_list|)
operator|,
name|Range
argument_list|(
name|Range
argument_list|)
operator|,
name|IntVal
argument_list|(
argument|IntVal
argument_list|)
block|{}
name|TokenKind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|isError
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Error
return|;
block|}
name|bool
name|isRegister
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|NamedRegister
operator|||
name|Kind
operator|==
name|underscore
operator|||
name|Kind
operator|==
name|VirtualRegister
return|;
block|}
name|bool
name|isRegisterFlag
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|kw_implicit
operator|||
name|Kind
operator|==
name|kw_implicit_define
operator|||
name|Kind
operator|==
name|kw_dead
operator|||
name|Kind
operator|==
name|kw_killed
operator|||
name|Kind
operator|==
name|kw_undef
return|;
block|}
name|bool
name|is
argument_list|(
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|==
name|K
return|;
block|}
name|bool
name|isNot
argument_list|(
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|!=
name|K
return|;
block|}
name|StringRef
operator|::
name|iterator
name|location
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|begin
argument_list|()
return|;
block|}
name|StringRef
name|stringValue
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|drop_front
argument_list|(
name|StringOffset
argument_list|)
return|;
block|}
specifier|const
name|APSInt
operator|&
name|integerValue
argument_list|()
specifier|const
block|{
return|return
name|IntVal
return|;
block|}
name|bool
name|hasIntegerValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|IntegerLiteral
operator|||
name|Kind
operator|==
name|MachineBasicBlock
operator|||
name|Kind
operator|==
name|GlobalValue
operator|||
name|Kind
operator|==
name|VirtualRegister
return|;
block|}
block|}
struct|;
comment|/// Consume a single machine instruction token in the given source and return
comment|/// the remaining source string.
name|StringRef
name|lexMIToken
argument_list|(
name|StringRef
name|Source
argument_list|,
name|MIToken
operator|&
name|Token
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|StringRef
operator|::
name|iterator
argument_list|,
specifier|const
name|Twine
operator|&
argument_list|)
operator|>
name|ErrorCallback
argument_list|)
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

