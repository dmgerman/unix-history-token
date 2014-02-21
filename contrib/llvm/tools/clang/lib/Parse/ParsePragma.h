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
name|Sema
decl_stmt|;
name|class
name|Parser
decl_stmt|;
name|class
name|PragmaAlignHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaAlignHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"align"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaGCCVisibilityHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaGCCVisibilityHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"visibility"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaOptionsHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaOptionsHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"options"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaPackHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaPackHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"pack"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaMSStructHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaMSStructHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"ms_struct"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaUnusedHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaUnusedHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"unused"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaWeakHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaWeakHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"weak"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaRedefineExtnameHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|explicit
name|PragmaRedefineExtnameHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"redefine_extname"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaOpenCLExtensionHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaOpenCLExtensionHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"EXTENSION"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaFPContractHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaFPContractHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"FP_CONTRACT"
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaNoOpenMPHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaNoOpenMPHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"omp"
argument_list|)
block|{ }
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
name|class
name|PragmaOpenMPHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaOpenMPHandler
argument_list|()
operator|:
name|PragmaHandler
argument_list|(
literal|"omp"
argument_list|)
block|{ }
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|; }
decl_stmt|;
comment|/// PragmaCommentHandler - "\#pragma comment ...".
name|class
name|PragmaCommentHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaCommentHandler
argument_list|(
name|Sema
operator|&
name|Actions
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
literal|"comment"
argument_list|)
block|,
name|Actions
argument_list|(
argument|Actions
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|;
name|private
operator|:
name|Sema
operator|&
name|Actions
block|; }
decl_stmt|;
name|class
name|PragmaDetectMismatchHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|PragmaDetectMismatchHandler
argument_list|(
name|Sema
operator|&
name|Actions
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
literal|"detect_mismatch"
argument_list|)
block|,
name|Actions
argument_list|(
argument|Actions
argument_list|)
block|{}
name|virtual
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
block|;
name|private
operator|:
name|Sema
operator|&
name|Actions
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

