begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ARCMTActions.h - ARC Migrate Tool Frontend Actions -----*- C++ -*-===//
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
name|LLVM_CLANG_ARCMIGRATE_ARCMT_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ARCMIGRATE_ARCMT_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/ARCMigrate/FileRemapper.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|arcmt
block|{
name|class
name|CheckAction
range|:
name|public
name|WrapperFrontendAction
block|{
name|protected
operator|:
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|public
operator|:
name|CheckAction
argument_list|(
name|FrontendAction
operator|*
name|WrappedAction
argument_list|)
block|; }
decl_stmt|;
name|class
name|ModifyAction
range|:
name|public
name|WrapperFrontendAction
block|{
name|protected
operator|:
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|public
operator|:
name|ModifyAction
argument_list|(
name|FrontendAction
operator|*
name|WrappedAction
argument_list|)
block|; }
decl_stmt|;
name|class
name|MigrateSourceAction
range|:
name|public
name|ASTFrontendAction
block|{
name|FileRemapper
name|Remapper
block|;
name|protected
operator|:
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
block|; }
decl_stmt|;
name|class
name|MigrateAction
range|:
name|public
name|WrapperFrontendAction
block|{
name|std
operator|::
name|string
name|MigrateDir
block|;
name|std
operator|::
name|string
name|PlistOut
block|;
name|bool
name|EmitPremigrationARCErros
block|;
name|protected
operator|:
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|public
operator|:
name|MigrateAction
argument_list|(
argument|FrontendAction *WrappedAction
argument_list|,
argument|StringRef migrateDir
argument_list|,
argument|StringRef plistOut
argument_list|,
argument|bool emitPremigrationARCErrors
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Migrates to modern ObjC syntax.
name|class
name|ObjCMigrateAction
range|:
name|public
name|WrapperFrontendAction
block|{
name|std
operator|::
name|string
name|MigrateDir
block|;
name|unsigned
name|ObjCMigAction
block|;
name|FileRemapper
name|Remapper
block|;
name|CompilerInstance
operator|*
name|CompInst
block|;
name|public
operator|:
name|ObjCMigrateAction
argument_list|(
argument|FrontendAction *WrappedAction
argument_list|,
argument|StringRef migrateDir
argument_list|,
argument|unsigned migrateAction
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|bool
name|BeginInvocation
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

