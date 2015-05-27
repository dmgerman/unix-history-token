begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SampleProfWriter.h - Write LLVM sample profile data ----------------===//
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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
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
file|"llvm/Support/FileSystem.h"
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
name|SampleProfileWriter
argument_list|(
argument|StringRef Filename
argument_list|,
argument|std::error_code&EC
argument_list|,
argument|sys::fs::OpenFlags Flags
argument_list|)
block|:
name|OS
argument_list|(
argument|Filename
argument_list|,
argument|EC
argument_list|,
argument|Flags
argument_list|)
block|{}
name|virtual
operator|~
name|SampleProfileWriter
argument_list|()
block|{}
comment|/// \brief Write sample profiles in \p S for function \p FName.
comment|///
comment|/// \returns true if the file was updated successfully. False, otherwise.
name|virtual
name|bool
name|write
argument_list|(
argument|StringRef FName
argument_list|,
argument|const FunctionSamples&S
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Write sample profiles in \p S for function \p F.
name|bool
name|write
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
specifier|const
name|FunctionSamples
modifier|&
name|S
parameter_list|)
block|{
return|return
name|write
argument_list|(
name|F
operator|.
name|getName
argument_list|()
argument_list|,
name|S
argument_list|)
return|;
block|}
comment|/// \brief Write all the sample profiles for all the functions in \p M.
comment|///
comment|/// \returns true if the file was updated successfully. False, otherwise.
name|bool
name|write
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|P
argument_list|)
block|{
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|F
range|:
name|M
control|)
block|{
name|StringRef
name|Name
init|=
name|F
operator|.
name|getName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|write
argument_list|(
name|Name
argument_list|,
name|P
index|[
name|Name
index|]
argument_list|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
comment|/// \brief Write all the sample profiles in the given map of samples.
comment|///
comment|/// \returns true if the file was updated successfully. False, otherwise.
name|bool
name|write
argument_list|(
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|ProfileMap
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|I
operator|:
name|ProfileMap
control|)
block|{
name|StringRef
name|FName
init|=
name|I
operator|.
name|first
argument_list|()
decl_stmt|;
name|FunctionSamples
modifier|&
name|Profile
init|=
name|I
operator|.
name|second
decl_stmt|;
if|if
condition|(
operator|!
name|write
argument_list|(
name|FName
argument_list|,
name|Profile
argument_list|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
comment|/// \brief Profile writer factory. Create a new writer based on the value of
comment|/// \p Format.
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
name|protected
label|:
comment|/// \brief Output stream where to emit the profile to.
name|raw_fd_ostream
name|OS
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
name|SampleProfileWriterText
argument_list|(
argument|StringRef F
argument_list|,
argument|std::error_code&EC
argument_list|)
operator|:
name|SampleProfileWriter
argument_list|(
argument|F
argument_list|,
argument|EC
argument_list|,
argument|sys::fs::F_Text
argument_list|)
block|{}
name|bool
name|write
argument_list|(
argument|StringRef FName
argument_list|,
argument|const FunctionSamples&S
argument_list|)
name|override
block|;
name|bool
name|write
argument_list|(
argument|const Module&M
argument_list|,
argument|StringMap<FunctionSamples>&P
argument_list|)
block|{
return|return
name|SampleProfileWriter
operator|::
name|write
argument_list|(
name|M
argument_list|,
name|P
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Sample-based profile writer (binary format).
name|class
name|SampleProfileWriterBinary
operator|:
name|public
name|SampleProfileWriter
block|{
name|public
operator|:
name|SampleProfileWriterBinary
argument_list|(
argument|StringRef F
argument_list|,
argument|std::error_code&EC
argument_list|)
block|;
name|bool
name|write
argument_list|(
argument|StringRef F
argument_list|,
argument|const FunctionSamples&S
argument_list|)
name|override
block|;
name|bool
name|write
argument_list|(
argument|const Module&M
argument_list|,
argument|StringMap<FunctionSamples>&P
argument_list|)
block|{
return|return
name|SampleProfileWriter
operator|::
name|write
argument_list|(
name|M
argument_list|,
name|P
argument_list|)
return|;
block|}
expr|}
block|;  }
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
comment|// LLVM_PROFILEDATA_SAMPLEPROFWRITER_H
end_comment

end_unit

