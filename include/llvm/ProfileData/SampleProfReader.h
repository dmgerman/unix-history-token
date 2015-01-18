begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SampleProfReader.h - Read LLVM sample profile data -----------------===//
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
comment|// This file contains definitions needed for reading sample profiles.
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
name|LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ProfileData/SampleProf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sampleprof
block|{
comment|/// \brief Sample-based profile reader.
comment|///
comment|/// Each profile contains sample counts for all the functions
comment|/// executed. Inside each function, statements are annotated with the
comment|/// collected samples on all the instructions associated with that
comment|/// statement.
comment|///
comment|/// For this to produce meaningful data, the program needs to be
comment|/// compiled with some debug information (at minimum, line numbers:
comment|/// -gline-tables-only). Otherwise, it will be impossible to match IR
comment|/// instructions to the line numbers collected by the profiler.
comment|///
comment|/// From the profile file, we are interested in collecting the
comment|/// following information:
comment|///
comment|/// * A list of functions included in the profile (mangled names).
comment|///
comment|/// * For each function F:
comment|///   1. The total number of samples collected in F.
comment|///
comment|///   2. The samples collected at each line in F. To provide some
comment|///      protection against source code shuffling, line numbers should
comment|///      be relative to the start of the function.
comment|///
comment|/// The reader supports two file formats: text and binary. The text format
comment|/// is useful for debugging and testing, while the binary format is more
comment|/// compact. They can both be used interchangeably.
name|class
name|SampleProfileReader
block|{
name|public
label|:
name|SampleProfileReader
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|Profiles
argument_list|(
literal|0
argument_list|)
operator|,
name|Ctx
argument_list|(
name|C
argument_list|)
operator|,
name|Buffer
argument_list|(
argument|std::move(B)
argument_list|)
block|{}
name|virtual
operator|~
name|SampleProfileReader
argument_list|()
block|{}
comment|/// \brief Read and validate the file header.
name|virtual
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \brief Read sample profiles from the associated file.
name|virtual
name|std
operator|::
name|error_code
name|read
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \brief Print the profile for \p FName on stream \p OS.
name|void
name|dumpFunctionProfile
parameter_list|(
name|StringRef
name|FName
parameter_list|,
name|raw_ostream
modifier|&
name|OS
init|=
name|dbgs
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Print all the profiles on stream \p OS.
name|void
name|dump
parameter_list|(
name|raw_ostream
modifier|&
name|OS
init|=
name|dbgs
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Return the samples collected for function \p F.
name|FunctionSamples
modifier|*
name|getSamplesFor
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
block|{
return|return
operator|&
name|Profiles
index|[
name|F
operator|.
name|getName
argument_list|()
index|]
return|;
block|}
comment|/// \brief Return all the profiles.
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|getProfiles
argument_list|()
block|{
return|return
name|Profiles
return|;
block|}
comment|/// \brief Report a parse error message.
name|void
name|reportParseError
argument_list|(
name|int64_t
name|LineNumber
argument_list|,
name|Twine
name|Msg
argument_list|)
decl|const
block|{
name|Ctx
operator|.
name|diagnose
argument_list|(
name|DiagnosticInfoSampleProfile
argument_list|(
name|Buffer
operator|->
name|getBufferIdentifier
argument_list|()
argument_list|,
name|LineNumber
argument_list|,
name|Msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Create a sample profile reader appropriate to the file format.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileReader
operator|>>
name|create
argument_list|(
argument|StringRef Filename
argument_list|,
argument|LLVMContext&C
argument_list|)
expr_stmt|;
name|protected
label|:
comment|/// \brief Map every function to its associated profile.
comment|///
comment|/// The profile of every function executed at runtime is collected
comment|/// in the structure FunctionSamples. This maps function objects
comment|/// to their corresponding profiles.
name|StringMap
operator|<
name|FunctionSamples
operator|>
name|Profiles
expr_stmt|;
comment|/// \brief LLVM context used to emit diagnostics.
name|LLVMContext
modifier|&
name|Ctx
decl_stmt|;
comment|/// \brief Memory buffer holding the profile file.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
block|}
empty_stmt|;
name|class
name|SampleProfileReaderText
range|:
name|public
name|SampleProfileReader
block|{
name|public
operator|:
name|SampleProfileReaderText
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|SampleProfileReader
argument_list|(
argument|std::move(B)
argument_list|,
argument|C
argument_list|)
block|{}
comment|/// \brief Read and validate the file header.
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
name|override
block|{
return|return
name|sampleprof_error
operator|::
name|success
return|;
block|}
comment|/// \brief Read sample profiles from the associated file.
name|std
operator|::
name|error_code
name|read
argument_list|()
name|override
block|; }
decl_stmt|;
name|class
name|SampleProfileReaderBinary
range|:
name|public
name|SampleProfileReader
block|{
name|public
operator|:
name|SampleProfileReaderBinary
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|SampleProfileReader
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|B
argument_list|)
argument_list|,
name|C
argument_list|)
block|,
name|Data
argument_list|(
name|nullptr
argument_list|)
block|,
name|End
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Read and validate the file header.
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
name|override
block|;
comment|/// \brief Read sample profiles from the associated file.
name|std
operator|::
name|error_code
name|read
argument_list|()
name|override
block|;
comment|/// \brief Return true if \p Buffer is in the format supported by this class.
specifier|static
name|bool
name|hasFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|&
name|Buffer
argument_list|)
block|;
name|protected
operator|:
comment|/// \brief Read a numeric value of type T from the profile.
comment|///
comment|/// If an error occurs during decoding, a diagnostic message is emitted and
comment|/// EC is set.
comment|///
comment|/// \returns the read value.
name|template
operator|<
name|typename
name|T
operator|>
name|ErrorOr
operator|<
name|T
operator|>
name|readNumber
argument_list|()
block|;
comment|/// \brief Read a string from the profile.
comment|///
comment|/// If an error occurs during decoding, a diagnostic message is emitted and
comment|/// EC is set.
comment|///
comment|/// \returns the read value.
name|ErrorOr
operator|<
name|StringRef
operator|>
name|readString
argument_list|()
block|;
comment|/// \brief Return true if we've reached the end of file.
name|bool
name|at_eof
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|>=
name|End
return|;
block|}
comment|/// \brief Points to the current location in the buffer.
specifier|const
name|uint8_t
operator|*
name|Data
block|;
comment|/// \brief Points to the end of the buffer.
specifier|const
name|uint8_t
operator|*
name|End
block|; }
decl_stmt|;
block|}
comment|// End namespace sampleprof
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_comment

end_unit

