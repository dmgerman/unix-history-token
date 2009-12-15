begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Passes.h - Target independent code generation passes ----*- C++ -*-===//
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
comment|// This file defines interfaces to access the target independent code generation
end_comment

begin_comment
comment|// passes provided by the LLVM backend.
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
name|LLVM_CODEGEN_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|RegisterCoalescer
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// createUnreachableBlockEliminationPass - The LLVM code generator does not
comment|/// work well with unreachable basic blocks (what live ranges make sense for a
comment|/// block that cannot be reached?).  As such, a code generator should either
comment|/// not instruction select unreachable blocks, or it can run this pass as it's
comment|/// last LLVM modifying pass to clean up blocks that are not reachable from
comment|/// the entry block.
name|FunctionPass
modifier|*
name|createUnreachableBlockEliminationPass
parameter_list|()
function_decl|;
comment|/// MachineFunctionPrinter pass - This pass prints out the machine function to
comment|/// the given stream, as a debugging tool.
name|FunctionPass
modifier|*
name|createMachineFunctionPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// MachineLoopInfo pass - This pass is a loop analysis pass.
comment|///
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|MachineLoopInfoID
decl_stmt|;
comment|/// MachineDominators pass - This pass is a machine dominators analysis pass.
comment|///
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|MachineDominatorsID
decl_stmt|;
comment|/// PHIElimination pass - This pass eliminates machine instruction PHI nodes
comment|/// by inserting copy instructions.  This destroys SSA information, but is the
comment|/// desired input for some register allocators.  This pass is "required" by
comment|/// these register allocator like this: AU.addRequiredID(PHIEliminationID);
comment|///
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|PHIEliminationID
decl_stmt|;
comment|/// StrongPHIElimination pass - This pass eliminates machine instruction PHI
comment|/// nodes by inserting copy instructions.  This destroys SSA information, but
comment|/// is the desired input for some register allocators.  This pass is
comment|/// "required" by these register allocator like this:
comment|///    AU.addRequiredID(PHIEliminationID);
comment|///  This pass is still in development
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|StrongPHIEliminationID
decl_stmt|;
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|PreAllocSplittingID
decl_stmt|;
comment|/// SimpleRegisterCoalescing pass.  Aggressively coalesces every register
comment|/// copy it can.
comment|///
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|SimpleRegisterCoalescingID
decl_stmt|;
comment|/// TwoAddressInstruction pass - This pass reduces two-address instructions to
comment|/// use two operands. This destroys SSA information but it is desired by
comment|/// register allocators.
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|TwoAddressInstructionPassID
decl_stmt|;
comment|/// UnreachableMachineBlockElimination pass - This pass removes unreachable
comment|/// machine basic blocks.
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|UnreachableMachineBlockElimID
decl_stmt|;
comment|/// DeadMachineInstructionElim pass - This pass removes dead machine
comment|/// instructions.
comment|///
name|FunctionPass
modifier|*
name|createDeadMachineInstructionElimPass
parameter_list|()
function_decl|;
comment|/// Creates a register allocator as the user specified on the command line.
comment|///
name|FunctionPass
modifier|*
name|createRegisterAllocator
parameter_list|()
function_decl|;
comment|/// LocalRegisterAllocation Pass - This pass register allocates the input code
comment|/// a basic block at a time, yielding code better than the simple register
comment|/// allocator, but not as good as a global allocator.
comment|///
name|FunctionPass
modifier|*
name|createLocalRegisterAllocator
parameter_list|()
function_decl|;
comment|/// LinearScanRegisterAllocation Pass - This pass implements the linear scan
comment|/// register allocation algorithm, a global register allocator.
comment|///
name|FunctionPass
modifier|*
name|createLinearScanRegisterAllocator
parameter_list|()
function_decl|;
comment|/// PBQPRegisterAllocation Pass - This pass implements the Partitioned Boolean
comment|/// Quadratic Prograaming (PBQP) based register allocator.
comment|///
name|FunctionPass
modifier|*
name|createPBQPRegisterAllocator
parameter_list|()
function_decl|;
comment|/// SimpleRegisterCoalescing Pass - Coalesce all copies possible.  Can run
comment|/// independently of the register allocator.
comment|///
name|RegisterCoalescer
modifier|*
name|createSimpleRegisterCoalescer
parameter_list|()
function_decl|;
comment|/// PrologEpilogCodeInserter Pass - This pass inserts prolog and epilog code,
comment|/// and eliminates abstract frame references.
comment|///
name|FunctionPass
modifier|*
name|createPrologEpilogCodeInserter
parameter_list|()
function_decl|;
comment|/// LowerSubregs Pass - This pass lowers subregs to register-register copies
comment|/// which yields suboptimal, but correct code if the register allocator
comment|/// cannot coalesce all subreg operations during allocation.
comment|///
name|FunctionPass
modifier|*
name|createLowerSubregsPass
parameter_list|()
function_decl|;
comment|/// createPostRAScheduler - This pass performs post register allocation
comment|/// scheduling.
name|FunctionPass
modifier|*
name|createPostRAScheduler
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
comment|/// BranchFolding Pass - This pass performs machine code CFG based
comment|/// optimizations to delete branches to branches, eliminate branches to
comment|/// successor blocks (creating fall throughs), and eliminating branches over
comment|/// branches.
name|FunctionPass
modifier|*
name|createBranchFoldingPass
parameter_list|(
name|bool
name|DefaultEnableTailMerge
parameter_list|)
function_decl|;
comment|/// TailDuplicate Pass - Duplicate blocks with unconditional branches
comment|/// into tails of their predecessors.
name|FunctionPass
modifier|*
name|createTailDuplicatePass
parameter_list|(
name|bool
name|PreRegAlloc
init|=
name|false
parameter_list|)
function_decl|;
comment|/// IfConverter Pass - This pass performs machine code if conversion.
name|FunctionPass
modifier|*
name|createIfConverterPass
parameter_list|()
function_decl|;
comment|/// Code Placement Pass - This pass optimize code placement and aligns loop
comment|/// headers to target specific alignment boundary.
name|FunctionPass
modifier|*
name|createCodePlacementOptPass
parameter_list|()
function_decl|;
comment|/// getRegisterAllocator - This creates an instance of the register allocator
comment|/// for the Sparc.
name|FunctionPass
modifier|*
name|getRegisterAllocator
parameter_list|(
name|TargetMachine
modifier|&
name|T
parameter_list|)
function_decl|;
comment|/// IntrinsicLowering Pass - Performs target-independent LLVM IR
comment|/// transformations for highly portable strategies.
name|FunctionPass
modifier|*
name|createGCLoweringPass
parameter_list|()
function_decl|;
comment|/// MachineCodeAnalysis Pass - Target-independent pass to mark safe points in
comment|/// machine code. Must be added very late during code generation, just prior
comment|/// to output, and importantly after all CFG transformations (such as branch
comment|/// folding).
name|FunctionPass
modifier|*
name|createGCMachineCodeAnalysisPass
parameter_list|()
function_decl|;
comment|/// Deleter Pass - Releases GC metadata.
comment|///
name|FunctionPass
modifier|*
name|createGCInfoDeleter
parameter_list|()
function_decl|;
comment|/// Creates a pass to print GC metadata.
comment|///
name|FunctionPass
modifier|*
name|createGCInfoPrinter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// createMachineLICMPass - This pass performs LICM on machine instructions.
comment|///
name|FunctionPass
modifier|*
name|createMachineLICMPass
parameter_list|()
function_decl|;
comment|/// createMachineSinkingPass - This pass performs sinking on machine
comment|/// instructions.
name|FunctionPass
modifier|*
name|createMachineSinkingPass
parameter_list|()
function_decl|;
comment|/// createStackSlotColoringPass - This pass performs stack slot coloring.
name|FunctionPass
modifier|*
name|createStackSlotColoringPass
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// createStackProtectorPass - This pass adds stack protectors to functions.
name|FunctionPass
modifier|*
name|createStackProtectorPass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|)
function_decl|;
comment|/// createMachineVerifierPass - This pass verifies cenerated machine code
comment|/// instructions for correctness.
comment|///
comment|/// @param allowPhysDoubleDefs ignore double definitions of
comment|///        registers. Useful before LiveVariables has run.
name|FunctionPass
modifier|*
name|createMachineVerifierPass
parameter_list|(
name|bool
name|allowDoubleDefs
parameter_list|)
function_decl|;
comment|/// createDwarfEHPass - This pass mulches exception handling code into a form
comment|/// adapted to code generation.  Required if using dwarf exception handling.
name|FunctionPass
modifier|*
name|createDwarfEHPass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|,
name|bool
name|fast
parameter_list|)
function_decl|;
comment|/// createSjLjEHPass - This pass adapts exception handling code to use
comment|/// the GCC-style builtin setjmp/longjmp (sjlj) to handling EH control flow.
name|FunctionPass
modifier|*
name|createSjLjEHPass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|)
function_decl|;
comment|/// createMaxStackAlignmentCalculatorPass() - Determine the maximum required
comment|/// alignment for a function.
name|FunctionPass
modifier|*
name|createMaxStackAlignmentCalculatorPass
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

