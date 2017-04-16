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
name|LLVM_LIB_TARGET_X86_X86_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86_H
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
name|InstructionSelector
decl_stmt|;
name|class
name|PassRegistry
decl_stmt|;
name|class
name|X86RegisterBankInfo
decl_stmt|;
name|class
name|X86Subtarget
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
comment|/// This pass converts a legalized DAG into a X86-specific DAG, ready for
comment|/// instruction scheduling.
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
comment|/// This pass initializes a global base register for PIC on x86-32.
name|FunctionPass
modifier|*
name|createX86GlobalBaseRegPass
parameter_list|()
function_decl|;
comment|/// This pass combines multiple accesses to local-dynamic TLS variables so that
comment|/// the TLS base address for the module is only fetched once per execution path
comment|/// through the function.
name|FunctionPass
modifier|*
name|createCleanupLocalDynamicTLSPass
parameter_list|()
function_decl|;
comment|/// This function returns a pass which converts floating-point register
comment|/// references and pseudo instructions into floating-point stack references and
comment|/// physical instructions.
name|FunctionPass
modifier|*
name|createX86FloatingPointStackifierPass
parameter_list|()
function_decl|;
comment|/// This pass inserts AVX vzeroupper instructions before each call to avoid
comment|/// transition penalty between functions encoded with AVX and SSE.
name|FunctionPass
modifier|*
name|createX86IssueVZeroUpperPass
parameter_list|()
function_decl|;
comment|/// Return a pass that pads short functions with NOOPs.
comment|/// This will prevent a stall when returning on the Atom.
name|FunctionPass
modifier|*
name|createX86PadShortFunctions
parameter_list|()
function_decl|;
comment|/// Return a pass that selectively replaces certain instructions (like add,
comment|/// sub, inc, dec, some shifts, and some multiplies) by equivalent LEA
comment|/// instructions, in order to eliminate execution delays in some processors.
name|FunctionPass
modifier|*
name|createX86FixupLEAs
parameter_list|()
function_decl|;
comment|/// Return a pass that removes redundant LEA instructions and redundant address
comment|/// recalculations.
name|FunctionPass
modifier|*
name|createX86OptimizeLEAs
parameter_list|()
function_decl|;
comment|/// Return a pass that transforms setcc + movzx pairs into xor + setcc.
name|FunctionPass
modifier|*
name|createX86FixupSetCC
parameter_list|()
function_decl|;
comment|/// Return a pass that expands WinAlloca pseudo-instructions.
name|FunctionPass
modifier|*
name|createX86WinAllocaExpander
parameter_list|()
function_decl|;
comment|/// Return a pass that optimizes the code-size of x86 call sequences. This is
comment|/// done by replacing esp-relative movs with pushes.
name|FunctionPass
modifier|*
name|createX86CallFrameOptimization
parameter_list|()
function_decl|;
comment|/// Return an IR pass that inserts EH registration stack objects and explicit
comment|/// EH state updates. This pass must run after EH preparation, which does
comment|/// Windows-specific but architecture-neutral preparation.
name|FunctionPass
modifier|*
name|createX86WinEHStatePass
parameter_list|()
function_decl|;
comment|/// Return a Machine IR pass that expands X86-specific pseudo
comment|/// instructions into a sequence of actual instructions. This pass
comment|/// must run after prologue/epilogue insertion and before lowering
comment|/// the MachineInstr to MC.
name|FunctionPass
modifier|*
name|createX86ExpandPseudoPass
parameter_list|()
function_decl|;
comment|/// Return a Machine IR pass that selectively replaces
comment|/// certain byte and word instructions by equivalent 32 bit instructions,
comment|/// in order to eliminate partial register usage, false dependences on
comment|/// the upper portions of registers, and to save code size.
name|FunctionPass
modifier|*
name|createX86FixupBWInsts
parameter_list|()
function_decl|;
name|void
name|initializeFixupBWInstPassPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
comment|/// This pass replaces EVEX ecnoded of AVX-512 instructiosn by VEX
comment|/// encoding when possible in order to reduce code size.
name|FunctionPass
modifier|*
name|createX86EvexToVexInsts
parameter_list|()
function_decl|;
name|InstructionSelector
modifier|*
name|createX86InstructionSelector
parameter_list|(
name|X86Subtarget
modifier|&
parameter_list|,
name|X86RegisterBankInfo
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializeEvexToVexInstPassPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
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

