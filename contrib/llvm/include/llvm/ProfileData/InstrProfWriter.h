begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrProfWriter.h - Instrumented profiling writer --------*- C++ -*-===//
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
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Writer for instrumentation based profile data.
name|class
name|InstrProfRecordWriterTrait
decl_stmt|;
name|class
name|ProfOStream
decl_stmt|;
name|class
name|raw_fd_ostream
decl_stmt|;
name|class
name|InstrProfWriter
block|{
name|public
label|:
name|using
name|ProfilingData
init|=
name|SmallDenseMap
operator|<
name|uint64_t
decl_stmt|,
name|InstrProfRecord
decl|>
decl_stmt|;
enum|enum
name|ProfKind
block|{
name|PF_Unknown
init|=
literal|0
block|,
name|PF_FE
block|,
name|PF_IRLevel
block|}
enum|;
name|private
label|:
name|bool
name|Sparse
decl_stmt|;
name|StringMap
operator|<
name|ProfilingData
operator|>
name|FunctionData
expr_stmt|;
name|ProfKind
name|ProfileKind
init|=
name|PF_Unknown
decl_stmt|;
comment|// Use raw pointer here for the incomplete type object.
name|InstrProfRecordWriterTrait
modifier|*
name|InfoObj
decl_stmt|;
name|public
label|:
name|InstrProfWriter
argument_list|(
argument|bool Sparse = false
argument_list|)
empty_stmt|;
operator|~
name|InstrProfWriter
argument_list|()
expr_stmt|;
comment|/// Add function counts for the given function. If there are already counts
comment|/// for this function and the hash and number of counts match, each counter is
comment|/// summed. Optionally scale counts by \p Weight.
name|void
name|addRecord
argument_list|(
name|NamedInstrProfRecord
operator|&&
name|I
argument_list|,
name|uint64_t
name|Weight
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|Error
argument_list|)
operator|>
name|Warn
argument_list|)
decl_stmt|;
name|void
name|addRecord
argument_list|(
name|NamedInstrProfRecord
operator|&&
name|I
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|Error
argument_list|)
operator|>
name|Warn
argument_list|)
block|{
name|addRecord
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|I
argument_list|)
argument_list|,
literal|1
argument_list|,
name|Warn
argument_list|)
expr_stmt|;
block|}
comment|/// Merge existing function counts from the given writer.
name|void
name|mergeRecordsFromWriter
argument_list|(
name|InstrProfWriter
operator|&&
name|IPW
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|Error
argument_list|)
operator|>
name|Warn
argument_list|)
decl_stmt|;
comment|/// Write the profile to \c OS
name|void
name|write
parameter_list|(
name|raw_fd_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// Write the profile in text format to \c OS
name|Error
name|writeText
parameter_list|(
name|raw_fd_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// Write \c Record in text format to \c OS
specifier|static
name|void
name|writeRecordInText
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
name|Hash
parameter_list|,
specifier|const
name|InstrProfRecord
modifier|&
name|Counters
parameter_list|,
name|InstrProfSymtab
modifier|&
name|Symtab
parameter_list|,
name|raw_fd_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// Write the profile, returning the raw data. For testing.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|writeBuffer
argument_list|()
expr_stmt|;
comment|/// Set the ProfileKind. Report error if mixing FE and IR level profiles.
name|Error
name|setIsIRLevelProfile
parameter_list|(
name|bool
name|IsIRLevel
parameter_list|)
block|{
if|if
condition|(
name|ProfileKind
operator|==
name|PF_Unknown
condition|)
block|{
name|ProfileKind
operator|=
name|IsIRLevel
condition|?
name|PF_IRLevel
else|:
name|PF_FE
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
return|return
operator|(
name|IsIRLevel
operator|==
operator|(
name|ProfileKind
operator|==
name|PF_IRLevel
operator|)
operator|)
condition|?
name|Error
operator|::
name|success
argument_list|()
else|:
name|make_error
operator|<
name|InstrProfError
operator|>
operator|(
name|instrprof_error
operator|::
name|unsupported_version
operator|)
return|;
block|}
comment|// Internal interface for testing purpose only.
name|void
name|setValueProfDataEndianness
argument_list|(
name|support
operator|::
name|endianness
name|Endianness
argument_list|)
decl_stmt|;
name|void
name|setOutputSparse
parameter_list|(
name|bool
name|Sparse
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|addRecord
argument_list|(
name|StringRef
name|Name
argument_list|,
name|uint64_t
name|Hash
argument_list|,
name|InstrProfRecord
operator|&&
name|I
argument_list|,
name|uint64_t
name|Weight
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|Error
argument_list|)
operator|>
name|Warn
argument_list|)
decl_stmt|;
name|bool
name|shouldEncodeData
parameter_list|(
specifier|const
name|ProfilingData
modifier|&
name|PD
parameter_list|)
function_decl|;
name|void
name|writeImpl
parameter_list|(
name|ProfOStream
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

begin_comment
comment|// LLVM_PROFILEDATA_INSTRPROFWRITER_H
end_comment

end_unit

