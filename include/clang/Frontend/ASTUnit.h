begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTUnit.h - ASTUnit utility ----------------------------*- C++ -*-===//
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
comment|// ASTUnit utility class.
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
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
name|FileManager
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
comment|/// \brief Utility class for loading a ASTContext from a PCH file.
comment|///
name|class
name|ASTUnit
block|{
name|Diagnostic
modifier|&
name|Diags
decl_stmt|;
name|SourceManager
name|SourceMgr
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|HeaderSearch
operator|>
name|HeaderInfo
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|TargetInfo
operator|>
name|Target
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|Preprocessor
operator|>
name|PP
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTContext
operator|>
name|Ctx
expr_stmt|;
name|ASTUnit
argument_list|(
specifier|const
name|ASTUnit
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|ASTUnit
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ASTUnit
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|ASTUnit
argument_list|(
name|Diagnostic
operator|&
name|_Diag
argument_list|)
expr_stmt|;
name|public
label|:
operator|~
name|ASTUnit
argument_list|()
expr_stmt|;
specifier|const
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|SourceMgr
return|;
block|}
specifier|const
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PP
operator|.
name|get
argument_list|()
return|;
block|}
name|Preprocessor
modifier|&
name|getPreprocessor
parameter_list|()
block|{
return|return
operator|*
name|PP
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Ctx
operator|.
name|get
argument_list|()
return|;
block|}
name|ASTContext
modifier|&
name|getASTContext
parameter_list|()
block|{
return|return
operator|*
name|Ctx
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|Diagnostic
operator|&
name|getDiagnostic
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
name|Diagnostic
modifier|&
name|getDiagnostic
parameter_list|()
block|{
return|return
name|Diags
return|;
block|}
name|FileManager
modifier|&
name|getFileManager
parameter_list|()
function_decl|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getOriginalSourceFileName
argument_list|()
expr_stmt|;
comment|/// \brief Create a ASTUnit from a PCH file.
comment|///
comment|/// \param Filename - The PCH file to load.
comment|///
comment|/// \param Diags - The Diagnostic implementation to use.
comment|///
comment|/// \param FileMgr - The FileManager to use.
comment|///
comment|/// \param ErrMsg - Error message to report if the PCH file could not be
comment|/// loaded.
comment|///
comment|/// \returns - The initialized ASTUnit or null if the PCH failed to load.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromPCHFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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

