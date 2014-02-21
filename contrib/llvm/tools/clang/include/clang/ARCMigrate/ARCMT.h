begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARCMT.h - ARC Migration Rewriter ------------------------*- C++ -*-===//
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
name|LLVM_CLANG_ARCMIGRATE_ARCMT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ARCMIGRATE_ARCMT_H
end_define

begin_include
include|#
directive|include
file|"clang/ARCMigrate/FileRemapper.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInvocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|DiagnosticConsumer
decl_stmt|;
name|namespace
name|arcmt
block|{
name|class
name|MigrationPass
decl_stmt|;
comment|/// \brief Creates an AST with the provided CompilerInvocation but with these
comment|/// changes:
comment|///   -if a PCH/PTH is set, the original header is used instead
comment|///   -Automatic Reference Counting mode is enabled
comment|///
comment|/// It then checks the AST and produces errors/warning for ARC migration issues
comment|/// that the user needs to handle manually.
comment|///
comment|/// \param emitPremigrationARCErrors if true all ARC errors will get emitted
comment|/// even if the migrator can fix them, but the function will still return false
comment|/// if all ARC errors can be fixed.
comment|///
comment|/// \param plistOut if non-empty, it is the file path to store the plist with
comment|/// the pre-migration ARC diagnostics.
comment|///
comment|/// \returns false if no error is produced, true otherwise.
name|bool
name|checkForManualIssues
parameter_list|(
name|CompilerInvocation
modifier|&
name|CI
parameter_list|,
specifier|const
name|FrontendInputFile
modifier|&
name|Input
parameter_list|,
name|DiagnosticConsumer
modifier|*
name|DiagClient
parameter_list|,
name|bool
name|emitPremigrationARCErrors
init|=
name|false
parameter_list|,
name|StringRef
name|plistOut
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Works similar to checkForManualIssues but instead of checking, it
comment|/// applies automatic modifications to source files to conform to ARC.
comment|///
comment|/// \returns false if no error is produced, true otherwise.
name|bool
name|applyTransformations
parameter_list|(
name|CompilerInvocation
modifier|&
name|origCI
parameter_list|,
specifier|const
name|FrontendInputFile
modifier|&
name|Input
parameter_list|,
name|DiagnosticConsumer
modifier|*
name|DiagClient
parameter_list|)
function_decl|;
comment|/// \brief Applies automatic modifications and produces temporary files
comment|/// and metadata into the \p outputDir path.
comment|///
comment|/// \param emitPremigrationARCErrors if true all ARC errors will get emitted
comment|/// even if the migrator can fix them, but the function will still return false
comment|/// if all ARC errors can be fixed.
comment|///
comment|/// \param plistOut if non-empty, it is the file path to store the plist with
comment|/// the pre-migration ARC diagnostics.
comment|///
comment|/// \returns false if no error is produced, true otherwise.
name|bool
name|migrateWithTemporaryFiles
parameter_list|(
name|CompilerInvocation
modifier|&
name|origCI
parameter_list|,
specifier|const
name|FrontendInputFile
modifier|&
name|Input
parameter_list|,
name|DiagnosticConsumer
modifier|*
name|DiagClient
parameter_list|,
name|StringRef
name|outputDir
parameter_list|,
name|bool
name|emitPremigrationARCErrors
parameter_list|,
name|StringRef
name|plistOut
parameter_list|)
function_decl|;
comment|/// \brief Get the set of file remappings from the \p outputDir path that
comment|/// migrateWithTemporaryFiles produced.
comment|///
comment|/// \returns false if no error is produced, true otherwise.
name|bool
name|getFileRemappings
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|std
operator|::
name|string
operator|>
expr|>
operator|&
name|remap
argument_list|,
name|StringRef
name|outputDir
argument_list|,
name|DiagnosticConsumer
operator|*
name|DiagClient
argument_list|)
decl_stmt|;
comment|/// \brief Get the set of file remappings from a list of files with remapping
comment|/// info.
comment|///
comment|/// \returns false if no error is produced, true otherwise.
name|bool
name|getFileRemappingsFromFileList
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|std
operator|::
name|string
operator|>
expr|>
operator|&
name|remap
argument_list|,
name|ArrayRef
operator|<
name|StringRef
operator|>
name|remapFiles
argument_list|,
name|DiagnosticConsumer
operator|*
name|DiagClient
argument_list|)
decl_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|TransformFn
function_decl|)
parameter_list|(
name|MigrationPass
modifier|&
name|pass
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|TransformFn
operator|>
name|getAllTransformations
argument_list|(
argument|LangOptions::GCMode OrigGCMode
argument_list|,
argument|bool NoFinalizeRemoval
argument_list|)
expr_stmt|;
name|class
name|MigrationProcess
block|{
name|CompilerInvocation
name|OrigCI
decl_stmt|;
name|DiagnosticConsumer
modifier|*
name|DiagClient
decl_stmt|;
name|FileRemapper
name|Remapper
decl_stmt|;
name|public
label|:
name|bool
name|HadARCErrors
decl_stmt|;
name|MigrationProcess
argument_list|(
argument|const CompilerInvocation&CI
argument_list|,
argument|DiagnosticConsumer *diagClient
argument_list|,
argument|StringRef outputDir = StringRef()
argument_list|)
empty_stmt|;
name|class
name|RewriteListener
block|{
name|public
label|:
name|virtual
operator|~
name|RewriteListener
argument_list|()
expr_stmt|;
name|virtual
name|void
name|start
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{ }
name|virtual
name|void
name|finish
parameter_list|()
block|{ }
name|virtual
name|void
name|insert
parameter_list|(
name|SourceLocation
name|loc
parameter_list|,
name|StringRef
name|text
parameter_list|)
block|{ }
name|virtual
name|void
name|remove
parameter_list|(
name|CharSourceRange
name|range
parameter_list|)
block|{ }
block|}
empty_stmt|;
name|bool
name|applyTransform
parameter_list|(
name|TransformFn
name|trans
parameter_list|,
name|RewriteListener
modifier|*
name|listener
init|=
literal|0
parameter_list|)
function_decl|;
name|FileRemapper
modifier|&
name|getRemapper
parameter_list|()
block|{
return|return
name|Remapper
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end namespace arcmt
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

