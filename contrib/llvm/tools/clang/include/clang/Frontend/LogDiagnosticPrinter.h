begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LogDiagnosticPrinter.h - Log Diagnostic Client ---------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_LOG_DIAGNOSTIC_PRINTER_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_LOG_DIAGNOSTIC_PRINTER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|LogDiagnosticPrinter
range|:
name|public
name|DiagnosticConsumer
block|{   struct
name|DiagEntry
block|{
comment|/// The primary message line of the diagnostic.
name|std
operator|::
name|string
name|Message
block|;
comment|/// The source file name, if available.
name|std
operator|::
name|string
name|Filename
block|;
comment|/// The source file line number, if available.
name|unsigned
name|Line
block|;
comment|/// The source file column number, if available.
name|unsigned
name|Column
block|;
comment|/// The ID of the diagnostic.
name|unsigned
name|DiagnosticID
block|;
comment|/// The level of the diagnostic.
name|DiagnosticsEngine
operator|::
name|Level
name|DiagnosticLevel
block|;   }
block|;
name|raw_ostream
operator|&
name|OS
block|;
specifier|const
name|LangOptions
operator|*
name|LangOpts
block|;
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
block|;
name|SourceLocation
name|LastWarningLoc
block|;
name|FullSourceLoc
name|LastLoc
block|;
name|unsigned
name|OwnsOutputStream
operator|:
literal|1
block|;
name|SmallVector
operator|<
name|DiagEntry
block|,
literal|8
operator|>
name|Entries
block|;
name|std
operator|::
name|string
name|MainFilename
block|;
name|std
operator|::
name|string
name|DwarfDebugFlags
block|;
name|public
operator|:
name|LogDiagnosticPrinter
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DiagnosticOptions *Diags
argument_list|,
argument|bool OwnsOutputStream = false
argument_list|)
block|;
name|virtual
operator|~
name|LogDiagnosticPrinter
argument_list|()
block|;
name|void
name|setDwarfDebugFlags
argument_list|(
argument|StringRef Value
argument_list|)
block|{
name|DwarfDebugFlags
operator|=
name|Value
block|;   }
name|void
name|BeginSourceFile
argument_list|(
argument|const LangOptions&LO
argument_list|,
argument|const Preprocessor *PP
argument_list|)
block|{
name|LangOpts
operator|=
operator|&
name|LO
block|;   }
name|void
name|EndSourceFile
argument_list|()
block|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|DiagnosticsEngine::Level DiagLevel
argument_list|,
argument|const Diagnostic&Info
argument_list|)
block|;
name|DiagnosticConsumer
operator|*
name|clone
argument_list|(
argument|DiagnosticsEngine&Diags
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

