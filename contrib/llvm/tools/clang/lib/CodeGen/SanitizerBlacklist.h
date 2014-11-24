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
name|CLANG_CODEGEN_SANITIZERBLACKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_SANITIZERBLACKLIST_H
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
file|"llvm/Support/SpecialCaseList.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
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
name|public
label|:
name|SanitizerBlacklist
argument_list|(
name|llvm
operator|::
name|SpecialCaseList
operator|*
name|SCL
argument_list|)
operator|:
name|SCL
argument_list|(
argument|SCL
argument_list|)
block|{}
name|bool
name|isIn
argument_list|(
argument|const llvm::Module&M
argument_list|,
argument|const StringRef Category = StringRef()
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|isIn
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isIn
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalVariable
operator|&
name|G
argument_list|,
specifier|const
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
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
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

