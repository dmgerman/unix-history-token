begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SampleProfWriter.h - Write LLVM sample profile data ------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// This file contains definitions needed for writing sample profiles.
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
name|LLVM_PROFILEDATA_SAMPLEPROFWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_SAMPLEPROFWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
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
file|"llvm/IR/ProfileSummary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ProfileData/SampleProf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sampleprof
block|{
enum|enum
name|SampleProfileFormat
block|{
name|SPF_None
init|=
literal|0
block|,
name|SPF_Text
block|,
name|SPF_Binary
block|,
name|SPF_GCC
block|}
enum|;
comment|/// \brief Sample-based profile writer. Base class.
name|class
name|SampleProfileWriter
block|{
name|public
label|:
name|virtual
operator|~
name|SampleProfileWriter
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Write sample profiles in \p S.
comment|///
comment|/// \returns status code of the file update operation.
name|virtual
name|std
operator|::
name|error_code
name|write
argument_list|(
specifier|const
name|FunctionSamples
operator|&
name|S
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Write all the sample profiles in the given map of samples.
comment|///
comment|/// \returns status code of the file update operation.
name|std
operator|::
name|error_code
name|write
argument_list|(
specifier|const
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|ProfileMap
argument_list|)
expr_stmt|;
name|raw_ostream
modifier|&
name|getOutputStream
parameter_list|()
block|{
return|return
operator|*
name|OutputStream
return|;
block|}
comment|/// Profile writer factory.
comment|///
comment|/// Create a new file writer based on the value of \p Format.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileWriter
operator|>>
name|create
argument_list|(
argument|StringRef Filename
argument_list|,
argument|SampleProfileFormat Format
argument_list|)
expr_stmt|;
comment|/// Create a new stream writer based on the value of \p Format.
comment|/// For testing.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileWriter
operator|>>
name|create
argument_list|(
argument|std::unique_ptr<raw_ostream>&OS
argument_list|,
argument|SampleProfileFormat Format
argument_list|)
expr_stmt|;
name|protected
label|:
name|SampleProfileWriter
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|raw_ostream
operator|>
operator|&
name|OS
argument_list|)
operator|:
name|OutputStream
argument_list|(
argument|std::move(OS)
argument_list|)
block|{}
comment|/// \brief Write a file header for the profile file.
name|virtual
name|std
operator|::
name|error_code
name|writeHeader
argument_list|(
specifier|const
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|ProfileMap
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Output stream where to emit the profile to.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_ostream
operator|>
name|OutputStream
expr_stmt|;
comment|/// \brief Profile summary.
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummary
operator|>
name|Summary
expr_stmt|;
comment|/// \brief Compute summary for this profile.
name|void
name|computeSummary
argument_list|(
specifier|const
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|ProfileMap
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Sample-based profile writer (text format).
name|class
name|SampleProfileWriterText
range|:
name|public
name|SampleProfileWriter
block|{
name|public
operator|:
name|std
operator|::
name|error_code
name|write
argument_list|(
argument|const FunctionSamples&S
argument_list|)
name|override
block|;
name|protected
operator|:
name|SampleProfileWriterText
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|raw_ostream
operator|>
operator|&
name|OS
argument_list|)
operator|:
name|SampleProfileWriter
argument_list|(
name|OS
argument_list|)
block|,
name|Indent
argument_list|(
literal|0
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|writeHeader
argument_list|(
argument|const StringMap<FunctionSamples>&ProfileMap
argument_list|)
name|override
block|{
return|return
name|sampleprof_error
operator|::
name|success
return|;
block|}
name|private
operator|:
comment|/// Indent level to use when writing.
comment|///
comment|/// This is used when printing inlined callees.
name|unsigned
name|Indent
block|;
name|friend
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileWriter
operator|>>
name|SampleProfileWriter
operator|::
name|create
argument_list|(
argument|std::unique_ptr<raw_ostream>&OS
argument_list|,
argument|SampleProfileFormat Format
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Sample-based profile writer (binary format).
name|class
name|SampleProfileWriterBinary
range|:
name|public
name|SampleProfileWriter
block|{
name|public
operator|:
name|std
operator|::
name|error_code
name|write
argument_list|(
argument|const FunctionSamples&S
argument_list|)
name|override
block|;
name|protected
operator|:
name|SampleProfileWriterBinary
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|raw_ostream
operator|>
operator|&
name|OS
argument_list|)
operator|:
name|SampleProfileWriter
argument_list|(
argument|OS
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|writeHeader
argument_list|(
argument|const StringMap<FunctionSamples>&ProfileMap
argument_list|)
name|override
block|;
name|std
operator|::
name|error_code
name|writeSummary
argument_list|()
block|;
name|std
operator|::
name|error_code
name|writeNameIdx
argument_list|(
argument|StringRef FName
argument_list|)
block|;
name|std
operator|::
name|error_code
name|writeBody
argument_list|(
specifier|const
name|FunctionSamples
operator|&
name|S
argument_list|)
block|;
name|private
operator|:
name|void
name|addName
argument_list|(
argument|StringRef FName
argument_list|)
block|;
name|void
name|addNames
argument_list|(
specifier|const
name|FunctionSamples
operator|&
name|S
argument_list|)
block|;
name|MapVector
operator|<
name|StringRef
block|,
name|uint32_t
operator|>
name|NameTable
block|;
name|friend
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileWriter
operator|>>
name|SampleProfileWriter
operator|::
name|create
argument_list|(
argument|std::unique_ptr<raw_ostream>&OS
argument_list|,
argument|SampleProfileFormat Format
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// end namespace sampleprof
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_PROFILEDATA_SAMPLEPROFWRITER_H
end_comment

end_unit

