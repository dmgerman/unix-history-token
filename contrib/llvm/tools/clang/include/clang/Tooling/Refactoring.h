begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Refactoring.h - Framework for clang refactoring tools --*- C++ -*-===//
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
comment|//  Interfaces supporting refactorings that span multiple translation units.
end_comment

begin_comment
comment|//  While single translation unit refactorings are supported via the Rewriter,
end_comment

begin_comment
comment|//  when refactoring multiple translation units changes must be stored in a
end_comment

begin_comment
comment|//  SourceManager independent form, duplicate changes need to be removed, and
end_comment

begin_comment
comment|//  all changes must be applied at once at the end of the refactoring so that
end_comment

begin_comment
comment|//  the code is always parseable.
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
name|LLVM_CLANG_TOOLING_REFACTORING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTORING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Tooling.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Rewriter
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|namespace
name|tooling
block|{
comment|/// \brief A text replacement.
comment|///
comment|/// Represents a SourceManager independent replacement of a range of text in a
comment|/// specific file.
name|class
name|Replacement
block|{
name|public
label|:
comment|/// \brief Creates an invalid (not applicable) replacement.
name|Replacement
argument_list|()
expr_stmt|;
comment|/// \brief Creates a replacement of the range [Offset, Offset+Length) in
comment|/// FilePath with ReplacementText.
comment|///
comment|/// \param FilePath A source file accessible via a SourceManager.
comment|/// \param Offset The byte offset of the start of the range in the file.
comment|/// \param Length The length of the range in bytes.
name|Replacement
argument_list|(
argument|llvm::StringRef FilePath
argument_list|,
argument|unsigned Offset
argument_list|,
argument|unsigned Length
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
empty_stmt|;
comment|/// \brief Creates a Replacement of the range [Start, Start+Length) with
comment|/// ReplacementText.
name|Replacement
argument_list|(
argument|SourceManager&Sources
argument_list|,
argument|SourceLocation Start
argument_list|,
argument|unsigned Length
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
empty_stmt|;
comment|/// \brief Creates a Replacement of the given range with ReplacementText.
name|Replacement
argument_list|(
argument|SourceManager&Sources
argument_list|,
argument|const CharSourceRange&Range
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
empty_stmt|;
comment|/// \brief Creates a Replacement of the node with ReplacementText.
name|template
operator|<
name|typename
name|Node
operator|>
name|Replacement
argument_list|(
argument|SourceManager&Sources
argument_list|,
argument|const Node&NodeToReplace
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
expr_stmt|;
comment|/// \brief Returns whether this replacement can be applied to a file.
comment|///
comment|/// Only replacements that are in a valid file can be applied.
name|bool
name|isApplicable
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Accessors.
comment|/// @{
name|StringRef
name|getFilePath
argument_list|()
specifier|const
block|{
return|return
name|FilePath
return|;
block|}
name|unsigned
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|Length
return|;
block|}
name|StringRef
name|getReplacementText
argument_list|()
specifier|const
block|{
return|return
name|ReplacementText
return|;
block|}
comment|/// @}
comment|/// \brief Applies the replacement on the Rewriter.
name|bool
name|apply
argument_list|(
name|Rewriter
operator|&
name|Rewrite
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns a human readable string representation.
name|std
operator|::
name|string
name|toString
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Comparator to be able to use Replacement in std::set for uniquing.
name|class
name|Less
block|{
name|public
label|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Replacement
operator|&
name|R1
operator|,
specifier|const
name|Replacement
operator|&
name|R2
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|private
label|:
name|void
name|setFromSourceLocation
argument_list|(
name|SourceManager
operator|&
name|Sources
argument_list|,
name|SourceLocation
name|Start
argument_list|,
name|unsigned
name|Length
argument_list|,
name|llvm
operator|::
name|StringRef
name|ReplacementText
argument_list|)
decl_stmt|;
name|void
name|setFromSourceRange
argument_list|(
name|SourceManager
operator|&
name|Sources
argument_list|,
specifier|const
name|CharSourceRange
operator|&
name|Range
argument_list|,
name|llvm
operator|::
name|StringRef
name|ReplacementText
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|FilePath
expr_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|unsigned
name|Length
decl_stmt|;
name|std
operator|::
name|string
name|ReplacementText
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief A set of Replacements.
comment|/// FIXME: Change to a vector and deduplicate in the RefactoringTool.
typedef|typedef
name|std
operator|::
name|set
operator|<
name|Replacement
operator|,
name|Replacement
operator|::
name|Less
operator|>
name|Replacements
expr_stmt|;
comment|/// \brief Apply all replacements on the Rewriter.
comment|///
comment|/// If at least one Apply returns false, ApplyAll returns false. Every
comment|/// Apply will be executed independently of the result of other
comment|/// Apply operations.
name|bool
name|applyAllReplacements
parameter_list|(
name|Replacements
modifier|&
name|Replaces
parameter_list|,
name|Rewriter
modifier|&
name|Rewrite
parameter_list|)
function_decl|;
comment|/// \brief A tool to run refactorings.
comment|///
comment|/// This is a refactoring specific version of \see ClangTool.
comment|/// All text replacements added to getReplacements() during the run of the
comment|/// tool will be applied and saved after all translation units have been
comment|/// processed.
name|class
name|RefactoringTool
block|{
name|public
label|:
comment|/// \see ClangTool::ClangTool.
name|RefactoringTool
argument_list|(
specifier|const
name|CompilationDatabase
operator|&
name|Compilations
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|SourcePaths
argument_list|)
expr_stmt|;
comment|/// \brief Returns a set of replacements. All replacements added during the
comment|/// run of the tool will be applied after all translation units have been
comment|/// processed.
name|Replacements
modifier|&
name|getReplacements
parameter_list|()
function_decl|;
comment|/// \see ClangTool::run.
name|int
name|run
parameter_list|(
name|FrontendActionFactory
modifier|*
name|ActionFactory
parameter_list|)
function_decl|;
name|private
label|:
name|ClangTool
name|Tool
decl_stmt|;
name|Replacements
name|Replace
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|Node
operator|>
name|Replacement
operator|::
name|Replacement
argument_list|(
argument|SourceManager&Sources
argument_list|,
argument|const Node&NodeToReplace
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
block|{
specifier|const
name|CharSourceRange
name|Range
operator|=
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|NodeToReplace
operator|->
name|getSourceRange
argument_list|()
argument_list|)
block|;
name|setFromSourceRange
argument_list|(
name|Sources
argument_list|,
name|Range
argument_list|,
name|ReplacementText
argument_list|)
block|; }
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
comment|// end namespace LLVM_CLANG_TOOLING_REFACTORING_H
end_comment

end_unit

