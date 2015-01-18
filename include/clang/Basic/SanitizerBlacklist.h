begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SanitizerBlacklist.h - Blacklist for sanitizers --------*- C++ -*-===//
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
comment|// User-provided blacklist used to disable/alter instrumentation done in
end_comment

begin_comment
comment|// sanitizers.
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
name|LLVM_CLANG_BASIC_SANITIZERBLACKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SANITIZERBLACKLIST_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SpecialCaseList.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SanitizerBlacklist
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|SpecialCaseList
operator|>
name|SCL
expr_stmt|;
name|SourceManager
modifier|&
name|SM
decl_stmt|;
name|public
label|:
name|SanitizerBlacklist
argument_list|(
argument|StringRef BlacklistPath
argument_list|,
argument|SourceManager&SM
argument_list|)
empty_stmt|;
name|bool
name|isBlacklistedGlobal
argument_list|(
name|StringRef
name|GlobalName
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBlacklistedType
argument_list|(
name|StringRef
name|MangledTypeName
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBlacklistedFunction
argument_list|(
name|StringRef
name|FunctionName
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBlacklistedFile
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBlacklistedLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
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

