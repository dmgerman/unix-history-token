begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ParserPragmas.h - Language specific pragmas -----------*- C++ -*-===//
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
comment|// This file defines #pragma handlers for language specific pragmas.
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
name|LLVM_CLANG_PARSE_PARSEPRAGMA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_PARSEPRAGMA_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/Pragma.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Action
decl_stmt|;
name|class
name|Parser
decl_stmt|;
name|class
name|PragmaPackHandler
range|:
name|public
name|PragmaHandler
block|{
name|Action
operator|&
name|Actions
block|;
name|public
operator|:
name|PragmaPackHandler
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|N
argument_list|,
name|Action
operator|&
name|A
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
name|N
argument_list|)
block|,
name|Actions
argument_list|(
argument|A
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|Token
operator|&
name|FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaUnusedHandler
range|:
name|public
name|PragmaHandler
block|{
name|Action
operator|&
name|Actions
block|;
name|Parser
operator|&
name|parser
block|;
name|public
operator|:
name|PragmaUnusedHandler
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|N
argument_list|,
name|Action
operator|&
name|A
argument_list|,
name|Parser
operator|&
name|p
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
name|N
argument_list|)
block|,
name|Actions
argument_list|(
name|A
argument_list|)
block|,
name|parser
argument_list|(
argument|p
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|Token
operator|&
name|FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaWeakHandler
range|:
name|public
name|PragmaHandler
block|{
name|Action
operator|&
name|Actions
block|;
name|public
operator|:
name|PragmaWeakHandler
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|N
argument_list|,
name|Action
operator|&
name|A
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
name|N
argument_list|)
block|,
name|Actions
argument_list|(
argument|A
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|Token
operator|&
name|FirstToken
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

