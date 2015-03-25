begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SerializedDiagnosticReader.h - Reads diagnostics -------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_SERIALIZED_DIAGNOSTIC_READER_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_SERIALIZED_DIAGNOSTIC_READER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|serialized_diags
block|{
name|enum
name|class
name|SDError
block|{
name|CouldNotLoad
operator|=
literal|1
operator|,
name|InvalidSignature
operator|,
name|InvalidDiagnostics
operator|,
name|MalformedTopLevelBlock
operator|,
name|MalformedSubBlock
operator|,
name|MalformedBlockInfoBlock
operator|,
name|MalformedMetadataBlock
operator|,
name|MalformedDiagnosticBlock
operator|,
name|MalformedDiagnosticRecord
operator|,
name|MissingVersion
operator|,
name|VersionMismatch
operator|,
name|UnsupportedConstruct
operator|,
comment|/// A generic error for subclass handlers that don't want or need to define
comment|/// their own error_category.
name|HandlerFailed
block|}
empty_stmt|;
specifier|const
name|std
operator|::
name|error_category
operator|&
name|SDErrorCategory
argument_list|()
expr_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|SDError E
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|E
operator|)
argument_list|,
name|SDErrorCategory
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief A location that is represented in the serialized diagnostics.
struct|struct
name|Location
block|{
name|unsigned
name|FileID
decl_stmt|;
name|unsigned
name|Line
decl_stmt|;
name|unsigned
name|Col
decl_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|Location
argument_list|(
argument|unsigned FileID
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|,
argument|unsigned Offset
argument_list|)
block|:
name|FileID
argument_list|(
name|FileID
argument_list|)
operator|,
name|Line
argument_list|(
name|Line
argument_list|)
operator|,
name|Col
argument_list|(
name|Col
argument_list|)
operator|,
name|Offset
argument_list|(
argument|Offset
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief A base class that handles reading serialized diagnostics from a file.
comment|///
comment|/// Subclasses should override the visit* methods with their logic for handling
comment|/// the various constructs that are found in serialized diagnostics.
name|class
name|SerializedDiagnosticReader
block|{
name|public
label|:
name|SerializedDiagnosticReader
argument_list|()
block|{}
name|virtual
operator|~
name|SerializedDiagnosticReader
argument_list|()
block|{}
comment|/// \brief Read the diagnostics in \c File
name|std
operator|::
name|error_code
name|readDiagnostics
argument_list|(
argument|StringRef File
argument_list|)
expr_stmt|;
name|private
label|:
name|enum
name|class
name|Cursor
decl_stmt|;
comment|/// \brief Read to the next record or block to process.
name|llvm
operator|::
name|ErrorOr
operator|<
name|Cursor
operator|>
name|skipUntilRecordOrBlock
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Stream
argument_list|,
name|unsigned
operator|&
name|BlockOrRecordId
argument_list|)
expr_stmt|;
comment|/// \brief Read a metadata block from \c Stream.
name|std
operator|::
name|error_code
name|readMetaBlock
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Stream
argument_list|)
expr_stmt|;
comment|/// \brief Read a diagnostic block from \c Stream.
name|std
operator|::
name|error_code
name|readDiagnosticBlock
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Stream
argument_list|)
expr_stmt|;
name|protected
label|:
comment|/// \brief Visit the start of a diagnostic block.
name|virtual
name|std
operator|::
name|error_code
name|visitStartOfDiagnostic
argument_list|()
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit the end of a diagnostic block.
name|virtual
name|std
operator|::
name|error_code
name|visitEndOfDiagnostic
argument_list|()
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a category. This associates the category \c ID to a \c Name.
name|virtual
name|std
operator|::
name|error_code
name|visitCategoryRecord
argument_list|(
argument|unsigned ID
argument_list|,
argument|StringRef Name
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a flag. This associates the flag's \c ID to a \c Name.
name|virtual
name|std
operator|::
name|error_code
name|visitDiagFlagRecord
argument_list|(
argument|unsigned ID
argument_list|,
argument|StringRef Name
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a diagnostic.
name|virtual
name|std
operator|::
name|error_code
name|visitDiagnosticRecord
argument_list|(
argument|unsigned Severity
argument_list|,
argument|const Location&Location
argument_list|,
argument|unsigned Category
argument_list|,
argument|unsigned Flag
argument_list|,
argument|StringRef Message
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a filename. This associates the file's \c ID to a \c Name.
name|virtual
name|std
operator|::
name|error_code
name|visitFilenameRecord
argument_list|(
argument|unsigned ID
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned Timestamp
argument_list|,
argument|StringRef Name
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a fixit hint.
name|virtual
name|std
operator|::
name|error_code
name|visitFixitRecord
argument_list|(
argument|const Location&Start
argument_list|,
argument|const Location&End
argument_list|,
argument|StringRef Text
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit a source range.
name|virtual
name|std
operator|::
name|error_code
name|visitSourceRangeRecord
argument_list|(
argument|const Location&Start
argument_list|,
argument|const Location&End
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
comment|/// \brief Visit the version of the set of diagnostics.
name|virtual
name|std
operator|::
name|error_code
name|visitVersionRecord
argument_list|(
argument|unsigned Version
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
block|}
comment|// end serialized_diags namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|clang
operator|::
name|serialized_diags
operator|::
name|SDError
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

