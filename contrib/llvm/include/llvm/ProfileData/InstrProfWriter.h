begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- InstrProfWriter.h - Instrumented profiling writer -----------*- C++ -*-=//
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
comment|// This file contains support for writing profiling data for instrumentation
end_comment

begin_comment
comment|// based PGO and coverage.
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
name|LLVM_PROFILEDATA_INSTRPROFWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_INSTRPROFWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

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
file|"llvm/ProfileData/InstrProf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Writer for instrumentation based profile data.
name|class
name|InstrProfWriter
block|{
name|public
label|:
typedef|typedef
name|SmallDenseMap
operator|<
name|uint64_t
operator|,
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
operator|,
literal|1
operator|>
name|CounterData
expr_stmt|;
name|private
label|:
name|StringMap
operator|<
name|CounterData
operator|>
name|FunctionData
expr_stmt|;
name|uint64_t
name|MaxFunctionCount
decl_stmt|;
name|public
label|:
name|InstrProfWriter
argument_list|()
operator|:
name|MaxFunctionCount
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Add function counts for the given function. If there are already counts
comment|/// for this function and the hash and number of counts match, each counter is
comment|/// summed.
name|std
operator|::
name|error_code
name|addFunctionCounts
argument_list|(
argument|StringRef FunctionName
argument_list|,
argument|uint64_t FunctionHash
argument_list|,
argument|ArrayRef<uint64_t> Counters
argument_list|)
expr_stmt|;
comment|/// Ensure that all data is written to disk.
name|void
name|write
parameter_list|(
name|raw_fd_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

