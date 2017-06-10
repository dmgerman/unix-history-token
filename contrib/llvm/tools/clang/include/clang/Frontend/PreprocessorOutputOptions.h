begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PreprocessorOutputOptions.h ----------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_PREPROCESSOROUTPUTOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PREPROCESSOROUTPUTOPTIONS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// PreprocessorOutputOptions - Options for controlling the C preprocessor
comment|/// output (e.g., -E).
name|class
name|PreprocessorOutputOptions
block|{
name|public
label|:
name|unsigned
name|ShowCPP
range|:
literal|1
decl_stmt|;
comment|///< Print normal preprocessed output.
name|unsigned
name|ShowComments
range|:
literal|1
decl_stmt|;
comment|///< Show comments.
name|unsigned
name|ShowLineMarkers
range|:
literal|1
decl_stmt|;
comment|///< Show \#line markers.
name|unsigned
name|UseLineDirectives
range|:
literal|1
decl_stmt|;
comment|///< Use \#line instead of GCC-style \# N.
name|unsigned
name|ShowMacroComments
range|:
literal|1
decl_stmt|;
comment|///< Show comments, even in macros.
name|unsigned
name|ShowMacros
range|:
literal|1
decl_stmt|;
comment|///< Print macro definitions.
name|unsigned
name|ShowIncludeDirectives
range|:
literal|1
decl_stmt|;
comment|///< Print includes, imports etc. within preprocessed output.
name|unsigned
name|RewriteIncludes
range|:
literal|1
decl_stmt|;
comment|///< Preprocess include directives only.
name|unsigned
name|RewriteImports
range|:
literal|1
decl_stmt|;
comment|///< Include contents of transitively-imported modules.
name|public
label|:
name|PreprocessorOutputOptions
argument_list|()
block|{
name|ShowCPP
operator|=
literal|0
expr_stmt|;
name|ShowComments
operator|=
literal|0
expr_stmt|;
name|ShowLineMarkers
operator|=
literal|1
expr_stmt|;
name|UseLineDirectives
operator|=
literal|0
expr_stmt|;
name|ShowMacroComments
operator|=
literal|0
expr_stmt|;
name|ShowMacros
operator|=
literal|0
expr_stmt|;
name|ShowIncludeDirectives
operator|=
literal|0
expr_stmt|;
name|RewriteIncludes
operator|=
literal|0
expr_stmt|;
name|RewriteImports
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
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

