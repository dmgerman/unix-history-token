begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CIndexer.h - Clang-C Source Indexing Library -----------------------===//
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
comment|// This file defines CIndexer, a subclass of Indexer that provides extra
end_comment

begin_comment
comment|// functionality needed by the CIndex library.
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
name|LLVM_CLANG_CINDEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CINDEXER_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/ASTLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/Indexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/Program.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/Utils.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInstance.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/ASTUnit.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|clang
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// IgnoreDiagnosticsClient - A DiagnosticsClient that just ignores emitted
end_comment

begin_comment
comment|/// warnings and errors.
end_comment

begin_decl_stmt
name|class
name|IgnoreDiagnosticsClient
range|:
name|public
name|DiagnosticClient
block|{
name|public
operator|:
name|virtual
operator|~
name|IgnoreDiagnosticsClient
argument_list|()
block|{}
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level
argument_list|,
argument|const DiagnosticInfo&
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CIndexer
range|:
name|public
name|Indexer
block|{
name|DiagnosticOptions
name|DiagOpts
block|;
name|IgnoreDiagnosticsClient
name|IgnoreDiagClient
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|Diagnostic
operator|>
name|TextDiags
block|;
name|Diagnostic
name|IgnoreDiags
block|;
name|bool
name|UseExternalASTGeneration
block|;
name|bool
name|OnlyLocalDecls
block|;
name|bool
name|DisplayDiagnostics
block|;
name|llvm
operator|::
name|sys
operator|::
name|Path
name|ClangPath
block|;
name|public
operator|:
name|explicit
name|CIndexer
argument_list|(
name|Program
operator|*
name|prog
argument_list|)
operator|:
name|Indexer
argument_list|(
operator|*
name|prog
argument_list|)
block|,
name|IgnoreDiags
argument_list|(
operator|&
name|IgnoreDiagClient
argument_list|)
block|,
name|UseExternalASTGeneration
argument_list|(
name|false
argument_list|)
block|,
name|OnlyLocalDecls
argument_list|(
name|false
argument_list|)
block|,
name|DisplayDiagnostics
argument_list|(
argument|false
argument_list|)
block|{
name|TextDiags
operator|.
name|reset
argument_list|(
name|CompilerInstance
operator|::
name|createDiagnostics
argument_list|(
name|DiagOpts
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
block|;   }
name|virtual
operator|~
name|CIndexer
argument_list|()
block|{
name|delete
operator|&
name|getProgram
argument_list|()
block|; }
comment|/// \brief Whether we only want to see "local" declarations (that did not
comment|/// come from a previous precompiled header). If false, we want to see all
comment|/// declarations.
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
name|void
name|setOnlyLocalDecls
argument_list|(
argument|bool Local = true
argument_list|)
block|{
name|OnlyLocalDecls
operator|=
name|Local
block|; }
name|bool
name|getDisplayDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|DisplayDiagnostics
return|;
block|}
name|void
name|setDisplayDiagnostics
argument_list|(
argument|bool Display = true
argument_list|)
block|{
name|DisplayDiagnostics
operator|=
name|Display
block|;   }
name|bool
name|getUseExternalASTGeneration
argument_list|()
specifier|const
block|{
return|return
name|UseExternalASTGeneration
return|;
block|}
name|void
name|setUseExternalASTGeneration
argument_list|(
argument|bool Value
argument_list|)
block|{
name|UseExternalASTGeneration
operator|=
name|Value
block|;   }
name|Diagnostic
operator|&
name|getDiags
argument_list|()
block|{
return|return
name|DisplayDiagnostics
operator|?
operator|*
name|TextDiags
operator|:
name|IgnoreDiags
return|;
block|}
comment|/// \brief Get the path of the clang binary.
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|&
name|getClangPath
argument_list|()
block|;
comment|/// \brief Get the path of the clang resource files.
name|std
operator|::
name|string
name|getClangResourcesPath
argument_list|()
block|;
specifier|static
name|CXString
name|createCXString
argument_list|(
argument|const char *String
argument_list|,
argument|bool DupString = false
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

