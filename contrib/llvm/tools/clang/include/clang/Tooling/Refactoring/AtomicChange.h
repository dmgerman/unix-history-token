begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AtomicChange.h - AtomicChange class --------------------*- C++ -*-===//
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
comment|//  This file defines AtomicChange which is used to create a set of source
end_comment

begin_comment
comment|//  changes, e.g. replacements and header insertions.
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
name|LLVM_CLANG_TOOLING_REFACTOR_ATOMICCHANGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTOR_ATOMICCHANGE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Core/Replacement.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// \brief An atomic change is used to create and group a set of source edits,
comment|/// e.g. replacements or header insertions. Edits in an AtomicChange should be
comment|/// related, e.g. replacements for the same type reference and the corresponding
comment|/// header insertion/deletion.
comment|///
comment|/// An AtomicChange is uniquely identified by a key and will either be fully
comment|/// applied or not applied at all.
comment|///
comment|/// Calling setError on an AtomicChange stores the error message and marks it as
comment|/// bad, i.e. none of its source edits will be applied.
name|class
name|AtomicChange
block|{
name|public
label|:
comment|/// \brief Creates an atomic change around \p KeyPosition with the key being a
comment|/// concatenation of the file name and the offset of \p KeyPosition.
comment|/// \p KeyPosition should be the location of the key syntactical element that
comment|/// is being changed, e.g. the call to a refactored method.
name|AtomicChange
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|SourceLocation KeyPosition
argument_list|)
empty_stmt|;
comment|/// \brief Creates an atomic change for \p FilePath with a customized key.
name|AtomicChange
argument_list|(
argument|llvm::StringRef FilePath
argument_list|,
argument|llvm::StringRef Key
argument_list|)
block|:
name|Key
argument_list|(
name|Key
argument_list|)
operator|,
name|FilePath
argument_list|(
argument|FilePath
argument_list|)
block|{}
comment|/// \brief Returns the atomic change as a YAML string.
name|std
operator|::
name|string
name|toYAMLString
argument_list|()
expr_stmt|;
comment|/// \brief Converts a YAML-encoded automic change to AtomicChange.
specifier|static
name|AtomicChange
name|convertFromYAML
argument_list|(
name|llvm
operator|::
name|StringRef
name|YAMLContent
argument_list|)
decl_stmt|;
comment|/// \brief Returns the key of this change, which is a concatenation of the
comment|/// file name and offset of the key position.
specifier|const
name|std
operator|::
name|string
operator|&
name|getKey
argument_list|()
specifier|const
block|{
return|return
name|Key
return|;
block|}
comment|/// \brief Returns the path of the file containing this atomic change.
specifier|const
name|std
operator|::
name|string
operator|&
name|getFilePath
argument_list|()
specifier|const
block|{
return|return
name|FilePath
return|;
block|}
comment|/// \brief If this change could not be created successfully, e.g. because of
comment|/// conflicts among replacements, use this to set an error description.
comment|/// Thereby, places that cannot be fixed automatically can be gathered when
comment|/// applying changes.
name|void
name|setError
argument_list|(
name|llvm
operator|::
name|StringRef
name|Error
argument_list|)
block|{
name|this
operator|->
name|Error
operator|=
name|Error
expr_stmt|;
block|}
comment|/// \brief Returns whether an error has been set on this list.
name|bool
name|hasError
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Error
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Returns the error message or an empty string if it does not exist.
specifier|const
name|std
operator|::
name|string
operator|&
name|getError
argument_list|()
specifier|const
block|{
return|return
name|Error
return|;
block|}
comment|/// \brief Adds a replacement that replaces the given Range with
comment|/// ReplacementText.
comment|/// \returns An llvm::Error carrying ReplacementError on error.
name|llvm
operator|::
name|Error
name|replace
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|const CharSourceRange&Range
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
expr_stmt|;
comment|/// \brief Adds a replacement that replaces range [Loc, Loc+Length) with
comment|/// \p Text.
comment|/// \returns An llvm::Error carrying ReplacementError on error.
name|llvm
operator|::
name|Error
name|replace
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|unsigned Length
argument_list|,
argument|llvm::StringRef Text
argument_list|)
expr_stmt|;
comment|/// \brief Adds a replacement that inserts \p Text at \p Loc. If this
comment|/// insertion conflicts with an existing insertion (at the same position),
comment|/// this will be inserted before/after the existing insertion depending on
comment|/// \p InsertAfter. Users should use `replace` with `Length=0` instead if they
comment|/// do not want conflict resolving by default. If the conflicting replacement
comment|/// is not an insertion, an error is returned.
comment|///
comment|/// \returns An llvm::Error carrying ReplacementError on error.
name|llvm
operator|::
name|Error
name|insert
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::StringRef Text
argument_list|,
argument|bool InsertAfter = true
argument_list|)
expr_stmt|;
comment|/// \brief Adds a header into the file that contains the key position.
comment|/// Header can be in angle brackets or double quotation marks. By default
comment|/// (header is not quoted), header will be surrounded with double quotes.
name|void
name|addHeader
argument_list|(
name|llvm
operator|::
name|StringRef
name|Header
argument_list|)
decl_stmt|;
comment|/// \brief Removes a header from the file that contains the key position.
name|void
name|removeHeader
argument_list|(
name|llvm
operator|::
name|StringRef
name|Header
argument_list|)
decl_stmt|;
comment|/// \brief Returns a const reference to existing replacements.
specifier|const
name|Replacements
operator|&
name|getReplacements
argument_list|()
specifier|const
block|{
return|return
name|Replaces
return|;
block|}
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|getInsertedHeaders
argument_list|()
specifier|const
block|{
return|return
name|InsertedHeaders
return|;
block|}
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|getRemovedHeaders
argument_list|()
specifier|const
block|{
return|return
name|RemovedHeaders
return|;
block|}
name|private
label|:
name|AtomicChange
argument_list|()
block|{}
name|AtomicChange
argument_list|(
argument|std::string Key
argument_list|,
argument|std::string FilePath
argument_list|,
argument|std::string Error
argument_list|,
argument|std::vector<std::string> InsertedHeaders
argument_list|,
argument|std::vector<std::string> RemovedHeaders
argument_list|,
argument|clang::tooling::Replacements Replaces
argument_list|)
empty_stmt|;
comment|// This uniquely identifies an AtomicChange.
name|std
operator|::
name|string
name|Key
expr_stmt|;
name|std
operator|::
name|string
name|FilePath
expr_stmt|;
name|std
operator|::
name|string
name|Error
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|InsertedHeaders
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|RemovedHeaders
expr_stmt|;
name|tooling
operator|::
name|Replacements
name|Replaces
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_REFACTOR_ATOMICCHANGE_H
end_comment

end_unit

