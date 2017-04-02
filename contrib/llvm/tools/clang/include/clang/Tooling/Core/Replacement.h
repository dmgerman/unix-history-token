begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Replacement.h - Framework for clang refactoring tools --*- C++ -*-===//
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
comment|//  Classes supporting refactorings that span multiple translation units.
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
name|LLVM_CLANG_TOOLING_CORE_REPLACEMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_CORE_REPLACEMENT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<map>
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

begin_include
include|#
directive|include
file|<system_error>
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
name|Rewriter
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
comment|/// \brief Whether this range equals to \p RHS or not.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Range
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Offset
operator|==
name|RHS
operator|.
name|getOffset
argument_list|()
operator|&&
name|Length
operator|==
name|RHS
operator|.
name|getLength
argument_list|()
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
argument|const SourceManager&Sources
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
argument|const SourceManager&Sources
argument_list|,
argument|const CharSourceRange&Range
argument_list|,
argument|StringRef ReplacementText
argument_list|,
argument|const LangOptions&LangOpts = LangOptions()
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
argument|const SourceManager&Sources
argument_list|,
argument|const Node&NodeToReplace
argument_list|,
argument|StringRef ReplacementText
argument_list|,
argument|const LangOptions&LangOpts = LangOptions()
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
specifier|const
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
specifier|const
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
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
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
name|enum
name|class
name|replacement_error
block|{
name|fail_to_apply
operator|=
literal|0
operator|,
name|wrong_file_path
operator|,
name|overlap_conflict
operator|,
name|insert_conflict
operator|,
block|}
empty_stmt|;
comment|/// \brief Carries extra error information in replacement-related llvm::Error,
comment|/// e.g. fail applying replacements and replacements conflict.
name|class
name|ReplacementError
range|:
name|public
name|llvm
operator|::
name|ErrorInfo
operator|<
name|ReplacementError
operator|>
block|{
name|public
operator|:
name|ReplacementError
argument_list|(
argument|replacement_error Err
argument_list|)
operator|:
name|Err
argument_list|(
argument|Err
argument_list|)
block|{}
comment|/// \brief Constructs an error related to an existing replacement.
name|ReplacementError
argument_list|(
argument|replacement_error Err
argument_list|,
argument|Replacement Existing
argument_list|)
operator|:
name|Err
argument_list|(
name|Err
argument_list|)
block|,
name|ExistingReplacement
argument_list|(
argument|std::move(Existing)
argument_list|)
block|{}
comment|/// \brief Constructs an error related to a new replacement and an existing
comment|/// replacement in a set of replacements.
name|ReplacementError
argument_list|(
argument|replacement_error Err
argument_list|,
argument|Replacement New
argument_list|,
argument|Replacement Existing
argument_list|)
operator|:
name|Err
argument_list|(
name|Err
argument_list|)
block|,
name|NewReplacement
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|New
argument_list|)
argument_list|)
block|,
name|ExistingReplacement
argument_list|(
argument|std::move(Existing)
argument_list|)
block|{}
name|std
operator|::
name|string
name|message
argument_list|()
specifier|const
name|override
block|;
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
name|OS
operator|<<
name|message
argument_list|()
block|; }
name|replacement_error
name|get
argument_list|()
specifier|const
block|{
return|return
name|Err
return|;
block|}
specifier|static
name|char
name|ID
block|;
specifier|const
name|llvm
operator|::
name|Optional
operator|<
name|Replacement
operator|>
operator|&
name|getNewReplacement
argument_list|()
specifier|const
block|{
return|return
name|NewReplacement
return|;
block|}
specifier|const
name|llvm
operator|::
name|Optional
operator|<
name|Replacement
operator|>
operator|&
name|getExistingReplacement
argument_list|()
specifier|const
block|{
return|return
name|ExistingReplacement
return|;
block|}
name|private
operator|:
comment|// Users are not expected to use error_code.
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|inconvertibleErrorCode
argument_list|()
return|;
block|}
name|replacement_error
name|Err
block|;
comment|// A new replacement, which is to expected be added into a set of
comment|// replacements, that is causing problem.
name|llvm
operator|::
name|Optional
operator|<
name|Replacement
operator|>
name|NewReplacement
block|;
comment|// An existing replacement in a replacements set that is causing problem.
name|llvm
operator|::
name|Optional
operator|<
name|Replacement
operator|>
name|ExistingReplacement
block|; }
decl_stmt|;
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
comment|/// \brief Maintains a set of replacements that are conflict-free.
comment|/// Two replacements are considered conflicts if they overlap or have the same
comment|/// offset (i.e. order-dependent).
name|class
name|Replacements
block|{
name|private
label|:
typedef|typedef
name|std
operator|::
name|set
operator|<
name|Replacement
operator|>
name|ReplacementsImpl
expr_stmt|;
name|public
label|:
typedef|typedef
name|ReplacementsImpl
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|ReplacementsImpl
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
name|Replacements
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|Replacements
parameter_list|(
specifier|const
name|Replacement
modifier|&
name|R
parameter_list|)
block|{
name|Replaces
operator|.
name|insert
argument_list|(
name|R
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Adds a new replacement \p R to the current set of replacements.
comment|/// \p R must have the same file path as all existing replacements.
comment|/// Returns `success` if the replacement is successfully inserted; otherwise,
comment|/// it returns an llvm::Error, i.e. there is a conflict between R and the
comment|/// existing replacements (i.e. they are order-dependent) or R's file path is
comment|/// different from the filepath of existing replacements. Callers must
comment|/// explicitly check the Error returned, and the returned error can be
comment|/// converted to a string message with `llvm::toString()`. This prevents users
comment|/// from adding order-dependent replacements. To control the order in which
comment|/// order-dependent replacements are applied, use merge({R}) with R referring
comment|/// to the changed code after applying all existing replacements.
comment|/// Two replacements A and B are considered order-independent if applying them
comment|/// in either order produces the same result. Note that the range of the
comment|/// replacement that is applied later still refers to the original code.
comment|/// These include (but not restricted to) replacements that:
comment|///   - don't overlap (being directly adjacent is fine) and
comment|///   - are overlapping deletions.
comment|///   - are insertions at the same offset and applying them in either order
comment|///     has the same effect, i.e. X + Y = Y + X when inserting X and Y
comment|///     respectively.
comment|///   - are identical replacements, i.e. applying the same replacement twice
comment|///     is equivalent to applying it once.
comment|/// Examples:
comment|/// 1. Replacement A(0, 0, "a") and B(0, 0, "aa") are order-independent since
comment|///    applying them in either order gives replacement (0, 0, "aaa").
comment|///    However, A(0, 0, "a") and B(0, 0, "b") are order-dependent since
comment|///    applying A first gives (0, 0, "ab") while applying B first gives (B, A,
comment|///    "ba").
comment|/// 2. Replacement A(0, 2, "123") and B(0, 2, "123") are order-independent
comment|///    since applying them in either order gives (0, 2, "123").
comment|/// 3. Replacement A(0, 3, "123") and B(2, 3, "321") are order-independent
comment|///    since either order gives (0, 5, "12321").
comment|/// 4. Replacement A(0, 3, "ab") and B(0, 3, "ab") are order-independent since
comment|///    applying the same replacement twice is equivalent to applying it once.
comment|/// Replacements with offset UINT_MAX are special - we do not detect conflicts
comment|/// for such replacements since users may add them intentionally as a special
comment|/// category of replacements.
name|llvm
operator|::
name|Error
name|add
argument_list|(
specifier|const
name|Replacement
operator|&
name|R
argument_list|)
expr_stmt|;
comment|/// \brief Merges \p Replaces into the current replacements. \p Replaces
comment|/// refers to code after applying the current replacements.
name|Replacements
name|merge
argument_list|(
specifier|const
name|Replacements
operator|&
name|Replaces
argument_list|)
decl|const
decl_stmt|;
comment|// Returns the affected ranges in the changed code.
name|std
operator|::
name|vector
operator|<
name|Range
operator|>
name|getAffectedRanges
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the new offset in the code after replacements being applied.
comment|// Note that if there is an insertion at Offset in the current replacements,
comment|// \p Offset will be shifted to Offset + Length in inserted text.
name|unsigned
name|getShiftedCodePosition
argument_list|(
name|unsigned
name|Position
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|Replaces
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|empty
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|end
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|Replaces
operator|.
name|rend
argument_list|()
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Replacements
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Replaces
operator|==
name|RHS
operator|.
name|Replaces
return|;
block|}
name|private
label|:
name|Replacements
argument_list|(
argument|const_iterator Begin
argument_list|,
argument|const_iterator End
argument_list|)
block|:
name|Replaces
argument_list|(
argument|Begin
argument_list|,
argument|End
argument_list|)
block|{}
comment|// Returns `R` with new range that refers to code after `Replaces` being
comment|// applied.
name|Replacement
name|getReplacementInChangedCode
argument_list|(
specifier|const
name|Replacement
operator|&
name|R
argument_list|)
decl|const
decl_stmt|;
comment|// Returns a set of replacements that is equivalent to the current
comment|// replacements by merging all adjacent replacements. Two sets of replacements
comment|// are considered equivalent if they have the same effect when they are
comment|// applied.
name|Replacements
name|getCanonicalReplacements
argument_list|()
specifier|const
expr_stmt|;
comment|// If `R` and all existing replacements are order-indepedent, then merge it
comment|// with `Replaces` and returns the merged replacements; otherwise, returns an
comment|// error.
name|llvm
operator|::
name|Expected
operator|<
name|Replacements
operator|>
name|mergeIfOrderIndependent
argument_list|(
argument|const Replacement&R
argument_list|)
specifier|const
expr_stmt|;
name|ReplacementsImpl
name|Replaces
decl_stmt|;
block|}
empty_stmt|;
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
comment|/// \brief Applies all replacements in \p Replaces to \p Code.
comment|///
comment|/// This completely ignores the path stored in each replacement. If all
comment|/// replacements are applied successfully, this returns the code with
comment|/// replacements applied; otherwise, an llvm::Error carrying llvm::StringError
comment|/// is returned (the Error message can be converted to string using
comment|/// `llvm::toString()` and 'std::error_code` in the `Error` should be ignored).
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|string
operator|>
name|applyAllReplacements
argument_list|(
argument|StringRef Code
argument_list|,
argument|const Replacements&Replaces
argument_list|)
expr_stmt|;
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
comment|/// \brief Calculates the new ranges after \p Replaces are applied. These
comment|/// include both the original \p Ranges and the affected ranges of \p Replaces
comment|/// in the new code.
comment|///
comment|/// \pre Replacements must be for the same file.
comment|///
comment|/// \return The new ranges after \p Replaces are applied. The new ranges will be
comment|/// sorted and non-overlapping.
name|std
operator|::
name|vector
operator|<
name|Range
operator|>
name|calculateRangesAfterReplacements
argument_list|(
specifier|const
name|Replacements
operator|&
name|Replaces
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Range
operator|>
operator|&
name|Ranges
argument_list|)
expr_stmt|;
comment|/// \brief If there are multiple<File, Replacements> pairs with the same file
comment|/// entry, we only keep one pair and discard the rest.
comment|/// If a file does not exist, its corresponding replacements will be ignored.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|Replacements
operator|>
name|groupReplacementsByFile
argument_list|(
name|FileManager
operator|&
name|FileMgr
argument_list|,
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|Replacements
operator|>
operator|&
name|FileToReplaces
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|Node
operator|>
name|Replacement
operator|::
name|Replacement
argument_list|(
argument|const SourceManager&Sources
argument_list|,
argument|const Node&NodeToReplace
argument_list|,
argument|StringRef ReplacementText
argument_list|,
argument|const LangOptions&LangOpts
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
argument_list|,
name|LangOpts
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
comment|// LLVM_CLANG_TOOLING_CORE_REPLACEMENT_H
end_comment

end_unit

