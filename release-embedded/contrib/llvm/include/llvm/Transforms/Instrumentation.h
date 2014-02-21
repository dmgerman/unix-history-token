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
comment|// Insert DataFlowSanitizer (dynamic data flow analysis) instrumentation
name|ModulePass
modifier|*
name|createDataFlowSanitizerPass
parameter_list|(
name|StringRef
name|ABIListFile
init|=
name|StringRef
argument_list|()
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|getArgTLS
function_decl|)
parameter_list|()
init|=
literal|0
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|getRetValTLS
function_decl|)
parameter_list|()
init|=
literal|0
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
specifier|inline
name|ModulePass
modifier|*
name|createDataFlowSanitizerPassForJIT
parameter_list|(
name|StringRef
name|ABIListFile
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
return|return
name|createDataFlowSanitizerPass
argument_list|(
name|ABIListFile
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
comment|/// createDebugIRPass - Enable interactive stepping through LLVM IR in LLDB (or
comment|///                     GDB) and generate a file with the LLVM IR to be
comment|///                     displayed in the debugger.
comment|///
comment|/// Existing debug metadata is preserved (but may be modified) in order to allow
comment|/// accessing variables in the original source. The line table and file
comment|/// information is modified to correspond to the lines in the LLVM IR. If
comment|/// Filename and Directory are empty, a file name is generated based on existing
comment|/// debug information. If no debug information is available, a temporary file
comment|/// name is generated.
comment|///
comment|/// @param HideDebugIntrinsics  Omit debug intrinsics in emitted IR source file.
comment|/// @param HideDebugMetadata    Omit debug metadata in emitted IR source file.
comment|/// @param Directory            Embed this directory in the debug information.
comment|/// @param Filename             Embed this file name in the debug information.
name|ModulePass
modifier|*
name|createDebugIRPass
parameter_list|(
name|bool
name|HideDebugIntrinsics
parameter_list|,
name|bool
name|HideDebugMetadata
parameter_list|,
name|StringRef
name|Directory
init|=
name|StringRef
argument_list|()
parameter_list|,
name|StringRef
name|Filename
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|/// createDebugIRPass - Enable interactive stepping through LLVM IR in LLDB
comment|///                     (or GDB) with an existing IR file on disk. When creating
comment|///                     a DebugIR pass with this function, no source file is
comment|///                     output to disk and the existing one is unmodified. Debug
comment|///                     metadata in the Module is created/updated to point to
comment|///                     the existing textual IR file on disk.
comment|/// NOTE: If the IR file to be debugged is not on disk, use the version of this
comment|///       function with parameters in order to generate the file that will be
comment|///       seen by the debugger.
name|ModulePass
modifier|*
name|createDebugIRPass
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

