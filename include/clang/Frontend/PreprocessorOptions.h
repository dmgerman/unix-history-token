begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PreprocessorOptionms.h ---------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_PREPROCESSOROPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PREPROCESSOROPTIONS_H_
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// PreprocessorOptions - This class is used for passing the various options
comment|/// used in preprocessor initialization to InitializePreprocessor().
name|class
name|PreprocessorOptions
block|{
name|public
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|bool
comment|/*isUndef*/
operator|>
expr|>
name|Macros
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Includes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|MacroIncludes
expr_stmt|;
name|unsigned
name|UsePredefines
range|:
literal|1
decl_stmt|;
comment|/// Initialize the preprocessor with the compiler
comment|/// and target specific predefines.
comment|/// The implicit PCH included at the start of the translation unit, or empty.
name|std
operator|::
name|string
name|ImplicitPCHInclude
expr_stmt|;
comment|/// The implicit PTH input included at the start of the translation unit, or
comment|/// empty.
name|std
operator|::
name|string
name|ImplicitPTHInclude
expr_stmt|;
comment|/// If given, a PTH cache file to use for speeding up header parsing.
name|std
operator|::
name|string
name|TokenCache
expr_stmt|;
name|public
label|:
name|PreprocessorOptions
argument_list|()
operator|:
name|UsePredefines
argument_list|(
argument|true
argument_list|)
block|{}
name|void
name|addMacroDef
argument_list|(
argument|llvm::StringRef Name
argument_list|)
block|{
name|Macros
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|false
argument_list|)
argument_list|)
block|;   }
name|void
name|addMacroUndef
argument_list|(
argument|llvm::StringRef Name
argument_list|)
block|{
name|Macros
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|true
argument_list|)
argument_list|)
block|;   }
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

