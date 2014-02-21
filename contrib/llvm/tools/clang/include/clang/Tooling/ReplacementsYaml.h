begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ReplacementsYaml.h -- Serialiazation for Replacements ---*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file defines the structure of a YAML document for serializing
end_comment

begin_comment
comment|/// replacements.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_TOOLING_REPLACEMENTS_YAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REPLACEMENTS_YAML_H
end_define

begin_include
include|#
directive|include
file|"clang/Tooling/Refactoring.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
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

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|clang::tooling::Replacement
argument_list|)
end_macro

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
comment|/// \brief ScalarTraits to read/write std::string objects.
name|template
operator|<
operator|>
expr|struct
name|ScalarTraits
operator|<
name|std
operator|::
name|string
operator|>
block|{
specifier|static
name|void
name|output
argument_list|(
argument|const std::string&Val
argument_list|,
argument|void *
argument_list|,
argument|llvm::raw_ostream&Out
argument_list|)
block|{
name|Out
operator|<<
name|Val
block|;   }
specifier|static
name|StringRef
name|input
argument_list|(
argument|StringRef Scalar
argument_list|,
argument|void *
argument_list|,
argument|std::string&Val
argument_list|)
block|{
name|Val
operator|=
name|Scalar
block|;
return|return
name|StringRef
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \brief Specialized MappingTraits to describe how a Replacement is
comment|/// (de)serialized.
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|clang
operator|::
name|tooling
operator|::
name|Replacement
operator|>
block|{
comment|/// \brief Helper to (de)serialize a Replacement since we don't have direct
comment|/// access to its data members.
block|struct
name|NormalizedReplacement
block|{
name|NormalizedReplacement
argument_list|(
specifier|const
name|IO
operator|&
argument_list|)
operator|:
name|FilePath
argument_list|(
literal|""
argument_list|)
block|,
name|Offset
argument_list|(
literal|0
argument_list|)
block|,
name|Length
argument_list|(
literal|0
argument_list|)
block|,
name|ReplacementText
argument_list|(
literal|""
argument_list|)
block|{}
name|NormalizedReplacement
argument_list|(
specifier|const
name|IO
operator|&
argument_list|,
specifier|const
name|clang
operator|::
name|tooling
operator|::
name|Replacement
operator|&
name|R
argument_list|)
operator|:
name|FilePath
argument_list|(
name|R
operator|.
name|getFilePath
argument_list|()
argument_list|)
block|,
name|Offset
argument_list|(
name|R
operator|.
name|getOffset
argument_list|()
argument_list|)
block|,
name|Length
argument_list|(
name|R
operator|.
name|getLength
argument_list|()
argument_list|)
block|,
name|ReplacementText
argument_list|(
argument|R.getReplacementText()
argument_list|)
block|{}
name|clang
operator|::
name|tooling
operator|::
name|Replacement
name|denormalize
argument_list|(
argument|const IO&
argument_list|)
block|{
return|return
name|clang
operator|::
name|tooling
operator|::
name|Replacement
argument_list|(
name|FilePath
argument_list|,
name|Offset
argument_list|,
name|Length
argument_list|,
name|ReplacementText
argument_list|)
return|;
block|}
name|std
operator|::
name|string
name|FilePath
block|;
name|unsigned
name|int
name|Offset
block|;
name|unsigned
name|int
name|Length
block|;
name|std
operator|::
name|string
name|ReplacementText
block|;   }
block|;
specifier|static
name|void
name|mapping
argument_list|(
argument|IO&Io
argument_list|,
argument|clang::tooling::Replacement&R
argument_list|)
block|{
name|MappingNormalization
operator|<
name|NormalizedReplacement
block|,
name|clang
operator|::
name|tooling
operator|::
name|Replacement
operator|>
name|Keys
argument_list|(
name|Io
argument_list|,
name|R
argument_list|)
block|;
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"FilePath"
argument_list|,
name|Keys
operator|->
name|FilePath
argument_list|)
block|;
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"Offset"
argument_list|,
name|Keys
operator|->
name|Offset
argument_list|)
block|;
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"Length"
argument_list|,
name|Keys
operator|->
name|Length
argument_list|)
block|;
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"ReplacementText"
argument_list|,
name|Keys
operator|->
name|ReplacementText
argument_list|)
block|;   }
block|}
block|;
comment|/// \brief Specialized MappingTraits to describe how a
comment|/// TranslationUnitReplacements is (de)serialized.
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|clang
operator|::
name|tooling
operator|::
name|TranslationUnitReplacements
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
argument|IO&Io
argument_list|,
argument|clang::tooling::TranslationUnitReplacements&Doc
argument_list|)
block|{
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"MainSourceFile"
argument_list|,
name|Doc
operator|.
name|MainSourceFile
argument_list|)
block|;
name|Io
operator|.
name|mapOptional
argument_list|(
literal|"Context"
argument_list|,
name|Doc
operator|.
name|Context
argument_list|,
name|std
operator|::
name|string
argument_list|()
argument_list|)
block|;
name|Io
operator|.
name|mapRequired
argument_list|(
literal|"Replacements"
argument_list|,
name|Doc
operator|.
name|Replacements
argument_list|)
block|;   }
block|}
block|; }
comment|// end namespace yaml
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_REPLACEMENTS_YAML_H
end_comment

end_unit

