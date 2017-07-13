begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Diagnostic.h - Framework for clang diagnostics tools --*- C++ -*-===//
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
comment|// \file
end_comment

begin_comment
comment|//  Structures supporting diagnostics and refactorings that span multiple
end_comment

begin_comment
comment|//  translation units. Indicate diagnostics reports and replacements
end_comment

begin_comment
comment|//  suggestions for the analyzed sources.
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
name|LLVM_CLANG_TOOLING_CORE_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_CORE_DIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"Replacement.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|namespace
name|tooling
block|{
comment|/// \brief Represents the diagnostic message with the error message associated
comment|/// and the information on the location of the problem.
struct|struct
name|DiagnosticMessage
block|{
name|DiagnosticMessage
argument_list|(
argument|llvm::StringRef Message =
literal|""
argument_list|)
empty_stmt|;
comment|/// \brief Constructs a diagnostic message with anoffset to the diagnostic
comment|/// within the file where the problem occured.
comment|///
comment|/// \param Loc Should be a file location, it is not meaningful for a macro
comment|/// location.
comment|///
name|DiagnosticMessage
argument_list|(
argument|llvm::StringRef Message
argument_list|,
argument|const SourceManager&Sources
argument_list|,
argument|SourceLocation Loc
argument_list|)
empty_stmt|;
name|std
operator|::
name|string
name|Message
expr_stmt|;
name|std
operator|::
name|string
name|FilePath
expr_stmt|;
name|unsigned
name|FileOffset
decl_stmt|;
block|}
struct|;
comment|/// \brief Represents the diagnostic with the level of severity and possible
comment|/// fixes to be applied.
struct|struct
name|Diagnostic
block|{
enum|enum
name|Level
block|{
name|Warning
init|=
name|DiagnosticsEngine
operator|::
name|Warning
block|,
name|Error
init|=
name|DiagnosticsEngine
operator|::
name|Error
block|}
enum|;
name|Diagnostic
argument_list|()
operator|=
expr|default
expr_stmt|;
name|Diagnostic
argument_list|(
argument|llvm::StringRef DiagnosticName
argument_list|,
argument|Level DiagLevel
argument_list|,
argument|StringRef BuildDirectory
argument_list|)
empty_stmt|;
name|Diagnostic
argument_list|(
argument|llvm::StringRef DiagnosticName
argument_list|,
argument|const DiagnosticMessage&Message
argument_list|,
argument|const llvm::StringMap<Replacements>&Fix
argument_list|,
argument|const SmallVector<DiagnosticMessage
argument_list|,
literal|1
argument|>&Notes
argument_list|,
argument|Level DiagLevel
argument_list|,
argument|llvm::StringRef BuildDirectory
argument_list|)
empty_stmt|;
comment|/// \brief Name identifying the Diagnostic.
name|std
operator|::
name|string
name|DiagnosticName
expr_stmt|;
comment|/// \brief Message associated to the diagnostic.
name|DiagnosticMessage
name|Message
decl_stmt|;
comment|/// \brief Fixes to apply, grouped by file path.
name|llvm
operator|::
name|StringMap
operator|<
name|Replacements
operator|>
name|Fix
expr_stmt|;
comment|/// \brief Potential notes about the diagnostic.
name|SmallVector
operator|<
name|DiagnosticMessage
operator|,
literal|1
operator|>
name|Notes
expr_stmt|;
comment|/// \brief Diagnostic level. Can indicate either an error or a warning.
name|Level
name|DiagLevel
decl_stmt|;
comment|/// \brief A build directory of the diagnostic source file.
comment|///
comment|/// It's an absolute path which is `directory` field of the source file in
comment|/// compilation database. If users don't specify the compilation database
comment|/// directory, it is the current directory where clang-tidy runs.
comment|///
comment|/// Note: it is empty in unittest.
name|std
operator|::
name|string
name|BuildDirectory
expr_stmt|;
block|}
struct|;
comment|/// \brief Collection of Diagnostics generated from a single translation unit.
struct|struct
name|TranslationUnitDiagnostics
block|{
comment|/// Name of the main source for the translation unit.
name|std
operator|::
name|string
name|MainSourceFile
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Diagnostic
operator|>
name|Diagnostics
expr_stmt|;
block|}
struct|;
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

begin_comment
comment|// LLVM_CLANG_TOOLING_CORE_DIAGNOSTIC_H
end_comment

end_unit

