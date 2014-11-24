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
name|LLVM_CLANG_FRONTEND_SERIALIZE_DIAGNOSTIC_PRINTER_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_SERIALIZE_DIAGNOSTIC_PRINTER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
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
enum|enum
name|BlockIDs
block|{
comment|/// \brief A top-level block which represents any meta data associated
comment|/// with the diagostics, including versioning of the format.
name|BLOCK_META
init|=
name|llvm
operator|::
name|bitc
operator|::
name|FIRST_APPLICATION_BLOCKID
block|,
comment|/// \brief The this block acts as a container for all the information
comment|/// for a specific diagnostic.
name|BLOCK_DIAG
block|}
enum|;
enum|enum
name|RecordIDs
block|{
name|RECORD_VERSION
init|=
literal|1
block|,
name|RECORD_DIAG
block|,
name|RECORD_SOURCE_RANGE
block|,
name|RECORD_DIAG_FLAG
block|,
name|RECORD_CATEGORY
block|,
name|RECORD_FILENAME
block|,
name|RECORD_FIXIT
block|,
name|RECORD_FIRST
init|=
name|RECORD_VERSION
block|,
name|RECORD_LAST
init|=
name|RECORD_FIXIT
block|}
enum|;
comment|/// A stable version of DiagnosticIDs::Level.
comment|///
comment|/// Do not change the order of values in this enum, and please increment the
comment|/// serialized diagnostics version number when you add to it.
enum|enum
name|Level
block|{
name|Ignored
init|=
literal|0
block|,
name|Note
block|,
name|Warning
block|,
name|Error
block|,
name|Fatal
block|,
name|Remark
block|}
enum|;
comment|/// \brief Returns a DiagnosticConsumer that serializes diagnostics to
comment|///  a bitcode file.
comment|///
comment|/// The created DiagnosticConsumer is designed for quick and lightweight
comment|/// transfer of of diagnostics to the enclosing build system (e.g., an IDE).
comment|/// This allows wrapper tools for Clang to get diagnostics from Clang
comment|/// (via libclang) without needing to parse Clang's command line output.
comment|///
name|DiagnosticConsumer
modifier|*
name|create
parameter_list|(
name|raw_ostream
modifier|*
name|OS
parameter_list|,
name|DiagnosticOptions
modifier|*
name|diags
parameter_list|)
function_decl|;
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

