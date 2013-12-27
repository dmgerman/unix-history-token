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
comment|// Insert edge profiling instrumentation
name|ModulePass
modifier|*
name|createEdgeProfilerPass
parameter_list|()
function_decl|;
comment|// Insert optimal edge profiling instrumentation
name|ModulePass
modifier|*
name|createOptimalEdgeProfilerPass
parameter_list|()
function_decl|;
comment|// Insert path profiling instrumentation
name|ModulePass
modifier|*
name|createPathProfilerPass
parameter_list|()
function_decl|;
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
comment|// Insert AddressSanitizer (address sanity checking) instrumentation
name|FunctionPass
modifier|*
name|createAddressSanitizerFunctionPass
parameter_list|(
name|bool
name|CheckInitOrder
init|=
name|true
parameter_list|,
name|bool
name|CheckUseAfterReturn
init|=
name|false
parameter_list|,
name|bool
name|CheckLifetime
init|=
name|false
parameter_list|,
name|StringRef
name|BlacklistFile
init|=
name|StringRef
argument_list|()
parameter_list|,
name|bool
name|ZeroBaseShadow
init|=
name|false
parameter_list|)
function_decl|;
name|ModulePass
modifier|*
name|createAddressSanitizerModulePass
parameter_list|(
name|bool
name|CheckInitOrder
init|=
name|true
parameter_list|,
name|StringRef
name|BlacklistFile
init|=
name|StringRef
argument_list|()
parameter_list|,
name|bool
name|ZeroBaseShadow
init|=
name|false
parameter_list|)
function_decl|;
comment|// Insert MemorySanitizer instrumentation (detection of uninitialized reads)
name|FunctionPass
modifier|*
name|createMemorySanitizerPass
parameter_list|(
name|bool
name|TrackOrigins
init|=
name|false
parameter_list|,
name|StringRef
name|BlacklistFile
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|// Insert ThreadSanitizer (race detection) instrumentation
name|FunctionPass
modifier|*
name|createThreadSanitizerPass
parameter_list|(
name|StringRef
name|BlacklistFile
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
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

