begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FileMatchTrie.h - --------------------------------------*- C++ -*-===//
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
comment|//  This file implements a match trie to find the matching file in a compilation
end_comment

begin_comment
comment|//  database based on a given path in the presence of symlinks.
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
name|LLVM_CLANG_TOOLING_FILEMATCHTRIE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_FILEMATCHTRIE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|namespace
name|tooling
block|{
struct|struct
name|PathComparator
block|{
name|virtual
operator|~
name|PathComparator
argument_list|()
block|{}
name|virtual
name|bool
name|equivalent
argument_list|(
argument|StringRef FileA
argument_list|,
argument|StringRef FileB
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
struct|;
name|class
name|FileMatchTrieNode
decl_stmt|;
comment|/// \brief A trie to efficiently match against the entries of the compilation
comment|/// database in order of matching suffix length.
comment|///
comment|/// When a clang tool is supposed to operate on a specific file, we have to
comment|/// find the corresponding file in the compilation database. Although entries
comment|/// in the compilation database are keyed by filename, a simple string match
comment|/// is insufficient because of symlinks. Commonly, a project hierarchy looks
comment|/// like this:
comment|///   /<project-root>/src/<path>/<somefile>.cc      (used as input for the tool)
comment|///   /<project-root>/build/<symlink-to-src>/<path>/<somefile>.cc (stored in DB)
comment|///
comment|/// Furthermore, there might be symlinks inside the source folder or inside the
comment|/// database, so that the same source file is translated with different build
comment|/// options.
comment|///
comment|/// For a given input file, the \c FileMatchTrie finds its entries in order
comment|/// of matching suffix length. For each suffix length, there might be one or
comment|/// more entries in the database. For each of those entries, it calls
comment|/// \c llvm::sys::fs::equivalent() (injected as \c PathComparator). There might
comment|/// be zero or more entries with the same matching suffix length that are
comment|/// equivalent to the input file. Three cases are distinguished:
comment|/// 0  equivalent files: Continue with the next suffix length.
comment|/// 1  equivalent file:  Best match found, return it.
comment|///>1 equivalent files: Match is ambiguous, return error.
name|class
name|FileMatchTrie
block|{
name|public
label|:
name|FileMatchTrie
argument_list|()
expr_stmt|;
comment|/// \brief Construct a new \c FileMatchTrie with the given \c PathComparator.
comment|///
comment|/// The \c FileMatchTrie takes ownership of 'Comparator'. Used for testing.
name|FileMatchTrie
argument_list|(
name|PathComparator
operator|*
name|Comparator
argument_list|)
expr_stmt|;
operator|~
name|FileMatchTrie
argument_list|()
expr_stmt|;
comment|/// \brief Insert a new absolute path. Relative paths are ignored.
name|void
name|insert
parameter_list|(
name|StringRef
name|NewPath
parameter_list|)
function_decl|;
comment|/// \brief Finds the corresponding file in this trie.
comment|///
comment|/// Returns file name stored in this trie that is equivalent to 'FileName'
comment|/// according to 'Comparator', if it can be uniquely identified. If there
comment|/// are no matches an empty \c StringRef is returned. If there are ambigious
comment|/// matches, an empty \c StringRef is returned and a corresponding message
comment|/// written to 'Error'.
name|StringRef
name|findEquivalent
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|raw_ostream
operator|&
name|Error
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|FileMatchTrieNode
modifier|*
name|Root
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|PathComparator
operator|>
name|Comparator
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

end_unit

