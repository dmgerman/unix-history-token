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
file|"llvm/ADT/StringRef.h"
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
comment|/// \brief A source range independent of the \c SourceManager.
name|class
name|Range
block|{
name|public
label|:
name|Range
argument_list|()
operator|:
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Length
argument_list|(
literal|0
argument_list|)
block|{}
name|Range
argument_list|(
argument|unsigned Offset
argument_list|,
argument|unsigned Length
argument_list|)
operator|:
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|Length
argument_list|(
argument|Length
argument_list|)
block|{}
comment|/// \brief Accessors.
comment|/// @{
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
comment|/// @}
comment|/// \name Range Predicates
comment|/// @{
comment|/// \brief Whether this range overlaps with \p RHS or not.
name|bool
name|overlapsWith
argument_list|(
name|Range
name|RHS
argument_list|)
decl|const
block|{
return|return
name|Offset
operator|+
name|Length
operator|>
name|RHS
operator|.
name|Offset
operator|&&
name|Offset
operator|<
name|RHS
operator|.
name|Offset
operator|+
name|RHS
operator|.
name|Length
return|;
block|}
comment|/// \brief Whether this range contains \p RHS or not.
name|bool
name|contains
argument_list|(
name|Range
name|RHS
argument_list|)
decl|const
block|{
return|return
name|RHS
operator|.
name|Offset
operator|>=
name|Offset
operator|&&
operator|(
name|RHS
operator|.
name|Offset
operator|+
name|RHS
operator|.
name|Length
operator|)
operator|<=
operator|(
name|Offset
operator|+
name|Length
operator|)
return|;
block|}
comment|/// @}
name|private
label|:
name|unsigned
name|Offset
decl_stmt|;
name|unsigned
name|Length
decl_stmt|;
block|}
empty_stmt|;
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
argument|StringRef FilePath
argument_list|,
argument|unsigned Offset
argument_list|,
argument|unsigned Length
argument_list|,
argument|StringRef ReplacementText
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
argument|StringRef ReplacementText
argument_list|)
empty_stmt|;
comment|/// \brief Creates a Replacement of the given range with ReplacementText.
name|Replacement
argument_list|(
argument|SourceManager&Sources
argument_list|,
argument|const CharSourceRange&Range
argument_list|,
argument|StringRef ReplacementText
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
argument|StringRef ReplacementText
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
name|ReplacementRange
operator|.
name|getOffset
argument_list|()
return|;
block|}
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|ReplacementRange
operator|.
name|getLength
argument_list|()
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
name|private
label|:
name|void
name|setFromSourceLocation
parameter_list|(
name|SourceManager
modifier|&
name|Sources
parameter_list|,
name|SourceLocation
name|Start
parameter_list|,
name|unsigned
name|Length
parameter_list|,
name|StringRef
name|ReplacementText
parameter_list|)
function_decl|;
name|void
name|setFromSourceRange
parameter_list|(
name|SourceManager
modifier|&
name|Sources
parameter_list|,
specifier|const
name|CharSourceRange
modifier|&
name|Range
parameter_list|,
name|StringRef
name|ReplacementText
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|FilePath
expr_stmt|;
name|Range
name|ReplacementRange
decl_stmt|;
name|std
operator|::
name|string
name|ReplacementText
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Less-than operator between two Replacements.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Replacement
operator|&
name|LHS
operator|,
specifier|const
name|Replacement
operator|&
name|RHS
operator|)
expr_stmt|;
comment|/// \brief Equal-to operator between two Replacements.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Replacement
operator|&
name|LHS
operator|,
specifier|const
name|Replacement
operator|&
name|RHS
operator|)
expr_stmt|;
comment|/// \brief A set of Replacements.
comment|/// FIXME: Change to a vector and deduplicate in the RefactoringTool.
typedef|typedef
name|std
operator|::
name|set
operator|<
name|Replacement
operator|>
name|Replacements
expr_stmt|;
comment|/// \brief Apply all replacements in \p Replaces to the Rewriter \p Rewrite.
comment|///
comment|/// Replacement applications happen independently of the success of
comment|/// other applications.
comment|///
comment|/// \returns true if all replacements apply. false otherwise.
name|bool
name|applyAllReplacements
parameter_list|(
specifier|const
name|Replacements
modifier|&
name|Replaces
parameter_list|,
name|Rewriter
modifier|&
name|Rewrite
parameter_list|)
function_decl|;
comment|/// \brief Apply all replacements in \p Replaces to the Rewriter \p Rewrite.
comment|///
comment|/// Replacement applications happen independently of the success of
comment|/// other applications.
comment|///
comment|/// \returns true if all replacements apply. false otherwise.
name|bool
name|applyAllReplacements
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Replacement
operator|>
operator|&
name|Replaces
argument_list|,
name|Rewriter
operator|&
name|Rewrite
argument_list|)
decl_stmt|;
comment|/// \brief Applies all replacements in \p Replaces to \p Code.
comment|///
comment|/// This completely ignores the path stored in each replacement. If one or more
comment|/// replacements cannot be applied, this returns an empty \c string.
name|std
operator|::
name|string
name|applyAllReplacements
argument_list|(
argument|StringRef Code
argument_list|,
argument|const Replacements&Replaces
argument_list|)
expr_stmt|;
comment|/// \brief Calculates how a code \p Position is shifted when \p Replaces are
comment|/// applied.
name|unsigned
name|shiftedCodePosition
parameter_list|(
specifier|const
name|Replacements
modifier|&
name|Replaces
parameter_list|,
name|unsigned
name|Position
parameter_list|)
function_decl|;
comment|/// \brief Calculates how a code \p Position is shifted when \p Replaces are
comment|/// applied.
comment|///
comment|/// \pre Replaces[i].getOffset()<= Replaces[i+1].getOffset().
name|unsigned
name|shiftedCodePosition
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Replacement
operator|>
operator|&
name|Replaces
argument_list|,
name|unsigned
name|Position
argument_list|)
decl_stmt|;
comment|/// \brief Removes duplicate Replacements and reports if Replacements conflict
comment|/// with one another.
comment|///
comment|/// \post Replaces[i].getOffset()<= Replaces[i+1].getOffset().
comment|///
comment|/// This function sorts \p Replaces so that conflicts can be reported simply by
comment|/// offset into \p Replaces and number of elements in the conflict.
name|void
name|deduplicate
argument_list|(
name|std
operator|::
name|vector
operator|<
name|Replacement
operator|>
operator|&
name|Replaces
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Range
operator|>
operator|&
name|Conflicts
argument_list|)
decl_stmt|;
comment|/// \brief Collection of Replacements generated from a single translation unit.
struct|struct
name|TranslationUnitReplacements
block|{
comment|/// Name of the main source for the translation unit.
name|std
operator|::
name|string
name|MainSourceFile
expr_stmt|;
comment|/// A freeform chunk of text to describe the context of the replacements.
comment|/// Will be printed, for example, when detecting conflicts during replacement
comment|/// deduplication.
name|std
operator|::
name|string
name|Context
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Replacement
operator|>
name|Replacements
expr_stmt|;
block|}
struct|;
comment|/// \brief A tool to run refactorings.
comment|///
comment|/// This is a refactoring specific version of \see ClangTool. FrontendActions
comment|/// passed to run() and runAndSave() should add replacements to
comment|/// getReplacements().
name|class
name|RefactoringTool
range|:
name|public
name|ClangTool
block|{
name|public
operator|:
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
block|;
comment|/// \brief Returns the set of replacements to which replacements should
comment|/// be added during the run of the tool.
name|Replacements
operator|&
name|getReplacements
argument_list|()
block|;
comment|/// \brief Call run(), apply all generated replacements, and immediately save
comment|/// the results to disk.
comment|///
comment|/// \returns 0 upon success. Non-zero upon failure.
name|int
name|runAndSave
argument_list|(
name|FrontendActionFactory
operator|*
name|ActionFactory
argument_list|)
block|;
comment|/// \brief Apply all stored replacements to the given Rewriter.
comment|///
comment|/// Replacement applications happen independently of the success of other
comment|/// applications.
comment|///
comment|/// \returns true if all replacements apply. false otherwise.
name|bool
name|applyAllReplacements
argument_list|(
name|Rewriter
operator|&
name|Rewrite
argument_list|)
block|;
name|private
operator|:
comment|/// \brief Write all refactored files to disk.
name|int
name|saveRewrittenFiles
argument_list|(
name|Rewriter
operator|&
name|Rewrite
argument_list|)
block|;
name|private
operator|:
name|Replacements
name|Replace
block|; }
decl_stmt|;
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
argument|StringRef ReplacementText
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

