begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------- IssueHash.h - Generate identification hashes ----*- C++ -*-===//
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
name|LLVM_CLANG_STATICANALYZER_CORE_ISSUE_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_ISSUE_HASH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|FullSourceLoc
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// \brief Get an MD5 hash to help identify bugs.
comment|///
comment|/// This function returns a hash that helps identify bugs within a source file.
comment|/// This identification can be utilized to diff diagnostic results on different
comment|/// snapshots of a projects, or maintain a database of suppressed diagnotics.
comment|///
comment|/// The hash contains the normalized text of the location associated with the
comment|/// diagnostic. Normalization means removing the whitespaces. The associated
comment|/// location is the either the last location of a diagnostic path or a uniqueing
comment|/// location. The bugtype and the name of the checker is also part of the hash.
comment|/// The last component is the string representation of the enclosing declaration
comment|/// of the associated location.
comment|///
comment|/// In case a new hash is introduced, the old one should still be maintained for
comment|/// a while. One should not introduce a new hash for every change, it is
comment|/// possible to introduce experimental hashes that may change in the future.
comment|/// Such hashes should be marked as experimental using a comment in the plist
comment|/// files.
name|llvm
operator|::
name|SmallString
operator|<
literal|32
operator|>
name|GetIssueHash
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|FullSourceLoc&IssueLoc
argument_list|,
argument|llvm::StringRef CheckerName
argument_list|,
argument|llvm::StringRef BugType
argument_list|,
argument|const Decl *D
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
expr_stmt|;
comment|/// \brief Get the string representation of issue hash. See GetIssueHash() for
comment|/// more information.
name|std
operator|::
name|string
name|GetIssueString
argument_list|(
argument|const SourceManager&SM
argument_list|,
argument|FullSourceLoc&IssueLoc
argument_list|,
argument|llvm::StringRef CheckerName
argument_list|,
argument|llvm::StringRef BugType
argument_list|,
argument|const Decl *D
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

