begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAsmParserExtension.h - Asm Parser Hooks -------*- C++ -*-===//
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
name|LLVM_MC_MCASMPARSEREXTENSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMPARSEREXTENSION_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmParser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Generic interface for extending the MCAsmParser,
comment|/// which is implemented by target and object file assembly parser
comment|/// implementations.
name|class
name|MCAsmParserExtension
block|{
name|MCAsmParserExtension
argument_list|(
specifier|const
name|MCAsmParserExtension
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAsmParserExtension
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|MCAsmParser
modifier|*
name|Parser
decl_stmt|;
name|protected
label|:
name|MCAsmParserExtension
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCAsmParserExtension
argument_list|()
expr_stmt|;
comment|/// \brief Initialize the extension for parsing using the given \arg
comment|/// Parser. The extension should use the AsmParser interfaces to register its
comment|/// parsing routines.
name|virtual
name|void
name|Initialize
parameter_list|(
name|MCAsmParser
modifier|&
name|Parser
parameter_list|)
function_decl|;
comment|/// @name MCAsmParser Proxy Interfaces
comment|/// @{
name|MCContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|getContext
argument_list|()
return|;
block|}
name|MCAsmLexer
modifier|&
name|getLexer
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|getLexer
argument_list|()
return|;
block|}
name|MCAsmParser
modifier|&
name|getParser
parameter_list|()
block|{
return|return
operator|*
name|Parser
return|;
block|}
name|SourceMgr
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|getSourceManager
argument_list|()
return|;
block|}
name|MCStreamer
modifier|&
name|getStreamer
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|getStreamer
argument_list|()
return|;
block|}
name|void
name|Warning
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
block|{
return|return
name|getParser
argument_list|()
operator|.
name|Warning
argument_list|(
name|L
argument_list|,
name|Msg
argument_list|)
return|;
block|}
name|bool
name|Error
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
block|{
return|return
name|getParser
argument_list|()
operator|.
name|Error
argument_list|(
name|L
argument_list|,
name|Msg
argument_list|)
return|;
block|}
specifier|const
name|AsmToken
modifier|&
name|Lex
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|Lex
argument_list|()
return|;
block|}
specifier|const
name|AsmToken
modifier|&
name|getTok
parameter_list|()
block|{
return|return
name|getParser
argument_list|()
operator|.
name|getTok
argument_list|()
return|;
block|}
name|bool
name|TokError
parameter_list|(
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
block|{
return|return
name|getParser
argument_list|()
operator|.
name|TokError
argument_list|(
name|Msg
argument_list|)
return|;
block|}
comment|/// @}
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

