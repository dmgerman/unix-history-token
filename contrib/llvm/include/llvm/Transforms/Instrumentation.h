begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Transforms/Instrumentation.h - Instrumentation passes ----*- C++ -*-===//
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
comment|// This file defines constructor functions for instrumentation passes.
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
name|LLVM_TRANSFORMS_INSTRUMENTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_INSTRUMENTATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ANDROID
argument_list|)
end_if

begin_function
specifier|inline
name|void
modifier|*
name|getDFSanArgTLSPtrForJIT
parameter_list|()
block|{
specifier|extern
name|__thread
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"initial-exec"
argument_list|)
operator|)
argument_list|)
name|void
modifier|*
name|__dfsan_arg_tls
decl_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|__dfsan_arg_tls
return|;
block|}
end_function

begin_function
specifier|inline
name|void
modifier|*
name|getDFSanRetValTLSPtrForJIT
parameter_list|()
block|{
specifier|extern
name|__thread
name|__attribute__
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"initial-exec"
argument_list|)
operator|)
argument_list|)
name|void
modifier|*
name|__dfsan_retval_tls
decl_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|__dfsan_retval_tls
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ModulePass
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
comment|// Insert GCOV profiling instrumentation
struct|struct
name|GCOVOptions
block|{
specifier|static
name|GCOVOptions
name|getDefault
parameter_list|()
function_decl|;
comment|// Specify whether to emit .gcno files.
name|bool
name|EmitNotes
decl_stmt|;
comment|// Specify whether to modify the program to emit .gcda files when run.
name|bool
name|EmitData
decl_stmt|;
comment|// A four-byte version string. The meaning of a version string is described in
comment|// gcc's gcov-io.h
name|char
name|Version
index|[
literal|4
index|]
decl_stmt|;
comment|// Emit a "cfg checksum" that follows the "line number checksum" of a
comment|// function. This affects both .gcno and .gcda files.
name|bool
name|UseCfgChecksum
decl_stmt|;
comment|// Add the 'noredzone' attribute to added runtime library calls.
name|bool
name|NoRedZone
decl_stmt|;
comment|// Emit the name of the function in the .gcda files. This is redundant, as
comment|// the function identifier can be used to find the name from the .gcno file.
name|bool
name|FunctionNamesInData
decl_stmt|;
comment|// Emit the exit block immediately after the start block, rather than after
comment|// all of the function body's blocks.
name|bool
name|ExitBlockBeforeBody
decl_stmt|;
block|}
struct|;
name|ModulePass
modifier|*
name|createGCOVProfilerPass
parameter_list|(
specifier|const
name|GCOVOptions
modifier|&
name|Options
init|=
name|GCOVOptions
operator|::
name|getDefault
argument_list|()
parameter_list|)
function_decl|;
comment|/// Options for the frontend instrumentation based profiling pass.
struct|struct
name|InstrProfOptions
block|{
name|InstrProfOptions
argument_list|()
operator|:
name|NoRedZone
argument_list|(
argument|false
argument_list|)
block|{}
comment|// Add the 'noredzone' attribute to added runtime library calls.
name|bool
name|NoRedZone
expr_stmt|;
comment|// Name of the profile file to use as output
name|std
operator|::
name|string
name|InstrProfileOutput
expr_stmt|;
block|}
struct|;
comment|/// Insert frontend instrumentation based profiling.
name|ModulePass
modifier|*
name|createInstrProfilingPass
parameter_list|(
specifier|const
name|InstrProfOptions
modifier|&
name|Options
init|=
name|InstrProfOptions
argument_list|()
parameter_list|)
function_decl|;
comment|// Insert AddressSanitizer (address sanity checking) instrumentation
name|FunctionPass
modifier|*
name|createAddressSanitizerFunctionPass
parameter_list|()
function_decl|;
name|ModulePass
modifier|*
name|createAddressSanitizerModulePass
parameter_list|()
function_decl|;
comment|// Insert MemorySanitizer instrumentation (detection of uninitialized reads)
name|FunctionPass
modifier|*
name|createMemorySanitizerPass
parameter_list|(
name|int
name|TrackOrigins
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Insert ThreadSanitizer (race detection) instrumentation
name|FunctionPass
modifier|*
name|createThreadSanitizerPass
parameter_list|()
function_decl|;
comment|// Insert DataFlowSanitizer (dynamic data flow analysis) instrumentation
name|ModulePass
modifier|*
name|createDataFlowSanitizerPass
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|ABIListFiles
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
argument_list|,
name|void
operator|*
call|(
modifier|*
name|getArgTLS
call|)
argument_list|()
operator|=
name|nullptr
argument_list|,
name|void
operator|*
call|(
modifier|*
name|getRetValTLS
call|)
argument_list|()
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|// Options for sanitizer coverage instrumentation.
struct|struct
name|SanitizerCoverageOptions
block|{
name|SanitizerCoverageOptions
argument_list|()
operator|:
name|CoverageType
argument_list|(
name|SCK_None
argument_list|)
operator|,
name|IndirectCalls
argument_list|(
name|false
argument_list|)
operator|,
name|TraceBB
argument_list|(
name|false
argument_list|)
operator|,
name|TraceCmp
argument_list|(
name|false
argument_list|)
operator|,
name|Use8bitCounters
argument_list|(
argument|false
argument_list|)
block|{}
expr|enum
name|Type
block|{
name|SCK_None
operator|=
literal|0
block|,
name|SCK_Function
block|,
name|SCK_BB
block|,
name|SCK_Edge
block|}
name|CoverageType
expr_stmt|;
name|bool
name|IndirectCalls
decl_stmt|;
name|bool
name|TraceBB
decl_stmt|;
name|bool
name|TraceCmp
decl_stmt|;
name|bool
name|Use8bitCounters
decl_stmt|;
block|}
struct|;
comment|// Insert SanitizerCoverage instrumentation.
name|ModulePass
modifier|*
name|createSanitizerCoverageModulePass
parameter_list|(
specifier|const
name|SanitizerCoverageOptions
modifier|&
name|Options
init|=
name|SanitizerCoverageOptions
argument_list|()
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ANDROID
argument_list|)
specifier|inline
name|ModulePass
modifier|*
name|createDataFlowSanitizerPassForJIT
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|ABIListFiles
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
argument_list|)
block|{
return|return
name|createDataFlowSanitizerPass
argument_list|(
name|ABIListFiles
argument_list|,
name|getDFSanArgTLSPtrForJIT
argument_list|,
name|getDFSanRetValTLSPtrForJIT
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// BoundsChecking - This pass instruments the code to perform run-time bounds
comment|// checking on loads, stores, and other memory intrinsics.
name|FunctionPass
modifier|*
name|createBoundsCheckingPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

