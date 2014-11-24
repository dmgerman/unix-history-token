begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86.h - Top-level interface for X86 representation ------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the x86
end_comment

begin_comment
comment|// target library, as used by the LLVM JIT.
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
name|TARGET_X86_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_X86_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ImmutablePass
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
comment|/// createX86AtomicExpandPass - This pass expands atomic operations that cannot
comment|/// be handled natively in terms of a loop using cmpxchg.
name|FunctionPass
modifier|*
name|createX86AtomicExpandPass
parameter_list|(
specifier|const
name|X86TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createX86ISelDag - This pass converts a legalized DAG into a
comment|/// X86-specific DAG, ready for instruction scheduling.
comment|///
name|FunctionPass
modifier|*
name|createX86ISelDag
argument_list|(
name|X86TargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
comment|/// createX86GlobalBaseRegPass - This pass initializes a global base
comment|/// register for PIC on x86-32.
name|FunctionPass
modifier|*
name|createX86GlobalBaseRegPass
parameter_list|()
function_decl|;
comment|/// createCleanupLocalDynamicTLSPass() - This pass combines multiple accesses
comment|/// to local-dynamic TLS variables so that the TLS base address for the module
comment|/// is only fetched once per execution path through the function.
name|FunctionPass
modifier|*
name|createCleanupLocalDynamicTLSPass
parameter_list|()
function_decl|;
comment|/// createX86FloatingPointStackifierPass - This function returns a pass which
comment|/// converts floating point register references and pseudo instructions into
comment|/// floating point stack references and physical instructions.
comment|///
name|FunctionPass
modifier|*
name|createX86FloatingPointStackifierPass
parameter_list|()
function_decl|;
comment|/// createX86IssueVZeroUpperPass - This pass inserts AVX vzeroupper instructions
comment|/// before each call to avoid transition penalty between functions encoded with
comment|/// AVX and SSE.
name|FunctionPass
modifier|*
name|createX86IssueVZeroUpperPass
parameter_list|()
function_decl|;
comment|/// createX86CodeEmitterPass - Return a pass that emits the collected X86 code
comment|/// to the specified MCE object.
name|FunctionPass
modifier|*
name|createX86JITCodeEmitterPass
parameter_list|(
name|X86TargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
function_decl|;
comment|/// createX86EmitCodeToMemory - Returns a pass that converts a register
comment|/// allocated function into raw machine code in a dynamically
comment|/// allocated chunk of memory.
comment|///
name|FunctionPass
modifier|*
name|createEmitX86CodeToMemory
parameter_list|()
function_decl|;
comment|/// \brief Creates an X86-specific Target Transformation Info pass.
name|ImmutablePass
modifier|*
name|createX86TargetTransformInfoPass
parameter_list|(
specifier|const
name|X86TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createX86PadShortFunctions - Return a pass that pads short functions
comment|/// with NOOPs. This will prevent a stall when returning on the Atom.
name|FunctionPass
modifier|*
name|createX86PadShortFunctions
parameter_list|()
function_decl|;
comment|/// createX86FixupLEAs - Return a a pass that selectively replaces
comment|/// certain instructions (like add, sub, inc, dec, some shifts,
comment|/// and some multiplies) by equivalent LEA instructions, in order
comment|/// to eliminate execution delays in some Atom processors.
name|FunctionPass
modifier|*
name|createX86FixupLEAs
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

