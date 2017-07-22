begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FunctionImportUtils.h - Importing support utilities -----*- C++ -*-===//
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
comment|// This file defines the FunctionImportGlobalProcessing class which is used
end_comment

begin_comment
comment|// to perform the necessary global value handling for function importing.
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
name|LLVM_TRANSFORMS_UTILS_FUNCTIONIMPORTUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_FUNCTIONIMPORTUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
comment|/// Class to handle necessary GlobalValue changes required by ThinLTO
comment|/// function importing, including linkage changes and any necessary renaming.
name|class
name|FunctionImportGlobalProcessing
block|{
comment|/// The Module which we are exporting or importing functions from.
name|Module
modifier|&
name|M
decl_stmt|;
comment|/// Module summary index passed in for function importing/exporting handling.
specifier|const
name|ModuleSummaryIndex
modifier|&
name|ImportIndex
decl_stmt|;
comment|/// Globals to import from this module, all other functions will be
comment|/// imported as declarations instead of definitions.
name|SetVector
operator|<
name|GlobalValue
operator|*
operator|>
operator|*
name|GlobalsToImport
expr_stmt|;
comment|/// Set to true if the given ModuleSummaryIndex contains any functions
comment|/// from this source module, in which case we must conservatively assume
comment|/// that any of its functions may be imported into another module
comment|/// as part of a different backend compilation process.
name|bool
name|HasExportedFunctions
init|=
name|false
decl_stmt|;
comment|/// Set of llvm.*used values, in order to validate that we don't try
comment|/// to promote any non-renamable values.
name|SmallPtrSet
operator|<
name|GlobalValue
operator|*
operator|,
literal|8
operator|>
name|Used
expr_stmt|;
comment|/// Check if we should promote the given local value to global scope.
name|bool
name|shouldPromoteLocalToGlobal
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|SGV
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// Check if the given value is a local that can't be renamed (promoted).
comment|/// Only used in assertion checking, and disabled under NDEBUG since the Used
comment|/// set will not be populated.
name|bool
name|isNonRenamableLocal
argument_list|(
specifier|const
name|GlobalValue
operator|&
name|GV
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|/// Helper methods to check if we are importing from or potentially
comment|/// exporting from the current source module.
name|bool
name|isPerformingImport
argument_list|()
specifier|const
block|{
return|return
name|GlobalsToImport
operator|!=
name|nullptr
return|;
block|}
name|bool
name|isModuleExporting
argument_list|()
specifier|const
block|{
return|return
name|HasExportedFunctions
return|;
block|}
comment|/// If we are importing from the source module, checks if we should
comment|/// import SGV as a definition, otherwise import as a declaration.
name|bool
name|doImportAsDefinition
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|SGV
parameter_list|)
function_decl|;
comment|/// Get the name for SGV that should be used in the linked destination
comment|/// module. Specifically, this handles the case where we need to rename
comment|/// a local that is being promoted to global scope, which it will always
comment|/// do when \p DoPromote is true (or when importing a local).
name|std
operator|::
name|string
name|getName
argument_list|(
argument|const GlobalValue *SGV
argument_list|,
argument|bool DoPromote
argument_list|)
expr_stmt|;
comment|/// Process globals so that they can be used in ThinLTO. This includes
comment|/// promoting local variables so that they can be reference externally by
comment|/// thin lto imported globals and converting strong external globals to
comment|/// available_externally.
name|void
name|processGlobalsForThinLTO
parameter_list|()
function_decl|;
name|void
name|processGlobalForThinLTO
parameter_list|(
name|GlobalValue
modifier|&
name|GV
parameter_list|)
function_decl|;
comment|/// Get the new linkage for SGV that should be used in the linked destination
comment|/// module. Specifically, for ThinLTO importing or exporting it may need
comment|/// to be adjusted. When \p DoPromote is true then we must adjust the
comment|/// linkage for a required promotion of a local to global scope.
name|GlobalValue
operator|::
name|LinkageTypes
name|getLinkage
argument_list|(
argument|const GlobalValue *SGV
argument_list|,
argument|bool DoPromote
argument_list|)
expr_stmt|;
name|public
label|:
name|FunctionImportGlobalProcessing
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|SetVector
operator|<
name|GlobalValue
operator|*
operator|>
operator|*
name|GlobalsToImport
operator|=
name|nullptr
argument_list|)
operator|:
name|M
argument_list|(
name|M
argument_list|)
operator|,
name|ImportIndex
argument_list|(
name|Index
argument_list|)
operator|,
name|GlobalsToImport
argument_list|(
argument|GlobalsToImport
argument_list|)
block|{
comment|// If we have a ModuleSummaryIndex but no function to import,
comment|// then this is the primary module being compiled in a ThinLTO
comment|// backend compilation, and we need to see if it has functions that
comment|// may be exported to another backend compilation.
if|if
condition|(
operator|!
name|GlobalsToImport
condition|)
name|HasExportedFunctions
operator|=
name|ImportIndex
operator|.
name|hasExportedFunctions
argument_list|(
name|M
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// First collect those in the llvm.used set.
name|collectUsedGlobalVariables
argument_list|(
name|M
argument_list|,
name|Used
argument_list|,
comment|/*CompilerUsed*/
name|false
argument_list|)
expr_stmt|;
comment|// Next collect those in the llvm.compiler.used set.
name|collectUsedGlobalVariables
argument_list|(
name|M
argument_list|,
name|Used
argument_list|,
comment|/*CompilerUsed*/
name|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|bool
name|run
parameter_list|()
function_decl|;
specifier|static
name|bool
name|doImportAsDefinition
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|SGV
argument_list|,
name|SetVector
operator|<
name|GlobalValue
operator|*
operator|>
operator|*
name|GlobalsToImport
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Perform in-place global value handling on the given Module for
end_comment

begin_comment
comment|/// exported local functions renamed and promoted for ThinLTO.
end_comment

begin_decl_stmt
name|bool
name|renameModuleForThinLTO
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|SetVector
operator|<
name|GlobalValue
operator|*
operator|>
operator|*
name|GlobalsToImport
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

