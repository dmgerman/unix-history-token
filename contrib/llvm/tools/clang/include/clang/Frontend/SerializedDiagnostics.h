begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SerializedDiagnostics.h - Common data for serialized diagnostics -===//
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
name|LLVM_CLANG_FRONTEND_SERIALIZE_DIAGNOSTICS_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_SERIALIZE_DIAGNOSTICS_H_
end_define

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
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
comment|/// \brief A stable version of DiagnosticIDs::Level.
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
comment|/// \brief The serialized diagnostics version number.
enum|enum
block|{
name|VersionNumber
init|=
literal|2
block|}
enum|;
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

