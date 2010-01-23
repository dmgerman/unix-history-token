begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetAsmLexer.h - Target Assembly Lexer ----*- C++ -*-===//
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
name|LLVM_TARGET_TARGETASMLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETASMLEXER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmLexer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
comment|/// TargetAsmLexer - Generic interface to target specific assembly lexers.
name|class
name|TargetAsmLexer
block|{
comment|/// The current token
name|AsmToken
name|CurTok
decl_stmt|;
comment|/// The location and description of the current error
name|SMLoc
name|ErrLoc
decl_stmt|;
name|std
operator|::
name|string
name|Err
expr_stmt|;
name|TargetAsmLexer
argument_list|(
specifier|const
name|TargetAsmLexer
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetAsmLexer
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|TargetAsmLexer
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
name|virtual
name|AsmToken
name|LexToken
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|SetError
argument_list|(
specifier|const
name|SMLoc
operator|&
name|errLoc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|err
argument_list|)
block|{
name|ErrLoc
operator|=
name|errLoc
expr_stmt|;
name|Err
operator|=
name|err
expr_stmt|;
block|}
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|TargetAsmLexer
argument_list|()
expr_stmt|;
specifier|const
name|Target
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
comment|/// Lex - Consume the next token from the input stream and return it.
specifier|const
name|AsmToken
modifier|&
name|Lex
parameter_list|()
block|{
return|return
name|CurTok
operator|=
name|LexToken
argument_list|()
return|;
block|}
comment|/// getTok - Get the current (last) lexed token.
specifier|const
name|AsmToken
modifier|&
name|getTok
parameter_list|()
block|{
return|return
name|CurTok
return|;
block|}
comment|/// getErrLoc - Get the current error location
specifier|const
name|SMLoc
modifier|&
name|getErrLoc
parameter_list|()
block|{
return|return
name|ErrLoc
return|;
block|}
comment|/// getErr - Get the current error string
specifier|const
name|std
operator|::
name|string
operator|&
name|getErr
argument_list|()
block|{
return|return
name|Err
return|;
block|}
comment|/// getKind - Get the kind of current token.
name|AsmToken
operator|::
name|TokenKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|CurTok
operator|.
name|getKind
argument_list|()
return|;
block|}
comment|/// is - Check if the current token has kind \arg K.
name|bool
name|is
argument_list|(
name|AsmToken
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|CurTok
operator|.
name|is
argument_list|(
name|K
argument_list|)
return|;
block|}
comment|/// isNot - Check if the current token has kind \arg K.
name|bool
name|isNot
argument_list|(
name|AsmToken
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|CurTok
operator|.
name|isNot
argument_list|(
name|K
argument_list|)
return|;
block|}
block|}
empty_stmt|;
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

