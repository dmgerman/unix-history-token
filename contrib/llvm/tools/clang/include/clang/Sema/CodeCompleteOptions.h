begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- CodeCompleteOptions.h - Code Completion Options -------*- C++ -*-===//
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
name|LLVM_CLANG_SEMA_CODECOMPLETEOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_CODECOMPLETEOPTIONS_H
end_define

begin_comment
comment|/// Options controlling the behavior of code completion.
end_comment

begin_decl_stmt
name|class
name|CodeCompleteOptions
block|{
name|public
label|:
comment|/// Show macros in code completion results.
name|unsigned
name|IncludeMacros
range|:
literal|1
decl_stmt|;
comment|/// Show code patterns in code completion results.
name|unsigned
name|IncludeCodePatterns
range|:
literal|1
decl_stmt|;
comment|/// Show top-level decls in code completion results.
name|unsigned
name|IncludeGlobals
range|:
literal|1
decl_stmt|;
comment|/// Show brief documentation comments in code completion results.
name|unsigned
name|IncludeBriefComments
range|:
literal|1
decl_stmt|;
name|CodeCompleteOptions
argument_list|()
operator|:
name|IncludeMacros
argument_list|(
literal|0
argument_list|)
operator|,
name|IncludeCodePatterns
argument_list|(
literal|0
argument_list|)
operator|,
name|IncludeGlobals
argument_list|(
literal|1
argument_list|)
operator|,
name|IncludeBriefComments
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

