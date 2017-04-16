begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerInterface.h - Interface header for the Fuzzer ------*- C++ -* ===//
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
comment|// Define the interface between libFuzzer and the library being tested.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// NOTE: the libFuzzer interface is thin and in the majority of cases
end_comment

begin_comment
comment|// you should not include this file into your target. In 95% of cases
end_comment

begin_comment
comment|// all you need is to define the following function in your file:
end_comment

begin_comment
comment|// extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);
end_comment

begin_comment
comment|// WARNING: keep the interface in C.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// __cplusplus
comment|// Mandatory user-provided target function.
comment|// Executes the code under test with [Data, Data+Size) as the input.
comment|// libFuzzer will invoke this function *many* times with different inputs.
comment|// Must return 0.
name|int
name|LLVMFuzzerTestOneInput
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|// Optional user-provided initialization function.
comment|// If provided, this function will be called by libFuzzer once at startup.
comment|// It may read and modify argc/argv.
comment|// Must return 0.
name|int
name|LLVMFuzzerInitialize
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|// Optional user-provided custom mutator.
comment|// Mutates raw data in [Data, Data+Size) inplace.
comment|// Returns the new size, which is not greater than MaxSize.
comment|// Given the same Seed produces the same mutation.
name|size_t
name|LLVMFuzzerCustomMutator
parameter_list|(
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|,
name|size_t
name|MaxSize
parameter_list|,
name|unsigned
name|int
name|Seed
parameter_list|)
function_decl|;
comment|// Optional user-provided custom cross-over function.
comment|// Combines pieces of Data1& Data2 together into Out.
comment|// Returns the new size, which is not greater than MaxOutSize.
comment|// Should produce the same mutation given the same Seed.
name|size_t
name|LLVMFuzzerCustomCrossOver
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data1
parameter_list|,
name|size_t
name|Size1
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|Data2
parameter_list|,
name|size_t
name|Size2
parameter_list|,
name|uint8_t
modifier|*
name|Out
parameter_list|,
name|size_t
name|MaxOutSize
parameter_list|,
name|unsigned
name|int
name|Seed
parameter_list|)
function_decl|;
comment|// Experimental, may go away in future.
comment|// libFuzzer-provided function to be used inside LLVMFuzzerCustomMutator.
comment|// Mutates raw data in [Data, Data+Size) inplace.
comment|// Returns the new size, which is not greater than MaxSize.
name|size_t
name|LLVMFuzzerMutate
parameter_list|(
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|,
name|size_t
name|MaxSize
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_INTERFACE_H
end_comment

end_unit

