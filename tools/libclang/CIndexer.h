begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CIndexer.h - Clang-C Source Indexing Library -------------*- C++ -*-===//
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
name|LLVM_CLANG_TOOLS_LIBCLANG_CINDEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CINDEXER_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CrashRecoveryContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTUnit
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|CIndexer
block|{
name|bool
name|OnlyLocalDecls
decl_stmt|;
name|bool
name|DisplayDiagnostics
decl_stmt|;
name|unsigned
name|Options
decl_stmt|;
comment|// CXGlobalOptFlags.
name|std
operator|::
name|string
name|ResourcesPath
expr_stmt|;
name|public
label|:
name|CIndexer
argument_list|()
operator|:
name|OnlyLocalDecls
argument_list|(
name|false
argument_list|)
operator|,
name|DisplayDiagnostics
argument_list|(
name|false
argument_list|)
operator|,
name|Options
argument_list|(
argument|CXGlobalOpt_None
argument_list|)
block|{ }
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
parameter_list|(
name|bool
name|Local
init|=
name|true
parameter_list|)
block|{
name|OnlyLocalDecls
operator|=
name|Local
expr_stmt|;
block|}
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
parameter_list|(
name|bool
name|Display
init|=
name|true
parameter_list|)
block|{
name|DisplayDiagnostics
operator|=
name|Display
expr_stmt|;
block|}
name|unsigned
name|getCXGlobalOptFlags
argument_list|()
specifier|const
block|{
return|return
name|Options
return|;
block|}
name|void
name|setCXGlobalOptFlags
parameter_list|(
name|unsigned
name|options
parameter_list|)
block|{
name|Options
operator|=
name|options
expr_stmt|;
block|}
name|bool
name|isOptEnabled
argument_list|(
name|CXGlobalOptFlags
name|opt
argument_list|)
decl|const
block|{
return|return
name|Options
operator|&
name|opt
return|;
block|}
comment|/// \brief Get the path of the clang resource files.
specifier|const
name|std
operator|::
name|string
operator|&
name|getClangResourcesPath
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Return the current size to request for "safety".
name|unsigned
name|GetSafetyThreadStackSize
parameter_list|()
function_decl|;
comment|/// \brief Set the current size to request for "safety" (or 0, if safety
comment|/// threads should not be used).
name|void
name|SetSafetyThreadStackSize
parameter_list|(
name|unsigned
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Execution the given code "safely", using crash recovery or safety
comment|/// threads when possible.
comment|///
comment|/// \return False if a crash was detected.
name|bool
name|RunSafely
argument_list|(
name|llvm
operator|::
name|CrashRecoveryContext
operator|&
name|CRC
argument_list|,
name|void
argument_list|(
operator|*
name|Fn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|UserData
argument_list|,
name|unsigned
name|Size
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// \brief Set the thread priority to background.
comment|/// FIXME: Move to llvm/Support.
name|void
name|setThreadBackgroundPriority
parameter_list|()
function_decl|;
comment|/// \brief Print libclang's resource usage to standard error.
name|void
name|PrintLibclangResourceUsage
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
name|namespace
name|cxindex
block|{
name|void
name|printDiagsToStderr
parameter_list|(
name|ASTUnit
modifier|*
name|Unit
parameter_list|)
function_decl|;
comment|/// \brief If \c MacroDefLoc points at a macro definition with \c II as
comment|/// its name, this retrieves its MacroInfo.
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|MacroDefLoc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Retrieves the corresponding MacroInfo of a MacroDefinition.
specifier|const
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|(
specifier|const
name|MacroDefinition
modifier|*
name|MacroDef
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief If \c Loc resides inside the definition of \c MI and it points at
comment|/// an identifier that has ever been a macro name, this returns the latest
comment|/// MacroDefinition for that name, otherwise it returns NULL.
name|MacroDefinition
modifier|*
name|checkForMacroInMacroDefinition
parameter_list|(
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief If \c Tok resides inside the definition of \c MI and it points at
comment|/// an identifier that has ever been a macro name, this returns the latest
comment|/// MacroDefinition for that name, otherwise it returns NULL.
name|MacroDefinition
modifier|*
name|checkForMacroInMacroDefinition
parameter_list|(
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|,
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

