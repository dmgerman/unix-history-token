begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SerializedDiagnosticPrinter.h - Serializer for diagnostics -------===//
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
name|LLVM_CLANG_FRONTEND_SERIALIZEDDIAGNOSTICPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_SERIALIZEDDIAGNOSTICPRINTER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/SerializedDiagnostics.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamWriter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticConsumer
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|namespace
name|serialized_diags
block|{
comment|/// \brief Returns a DiagnosticConsumer that serializes diagnostics to
comment|///  a bitcode file.
comment|///
comment|/// The created DiagnosticConsumer is designed for quick and lightweight
comment|/// transfer of of diagnostics to the enclosing build system (e.g., an IDE).
comment|/// This allows wrapper tools for Clang to get diagnostics from Clang
comment|/// (via libclang) without needing to parse Clang's command line output.
comment|///
name|std
operator|::
name|unique_ptr
operator|<
name|DiagnosticConsumer
operator|>
name|create
argument_list|(
argument|StringRef OutputFile
argument_list|,
argument|DiagnosticOptions *Diags
argument_list|,
argument|bool MergeChildRecords = false
argument_list|)
expr_stmt|;
block|}
comment|// end serialized_diags namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

