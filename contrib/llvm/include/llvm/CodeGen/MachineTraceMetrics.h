begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/CodeGen/MachineTraceMetrics.h - Super-scalar metrics -*- C++ -*-===//
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
comment|// This file defines the interface for the MachineTraceMetrics analysis pass
end_comment

begin_comment
comment|// that estimates CPU resource usage and critical data dependency paths through
end_comment

begin_comment
comment|// preferred traces. This is useful for super-scalar CPUs where execution speed
end_comment

begin_comment
comment|// can be limited both by data dependencies and by limited execution resources.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Out-of-order CPUs will often be executing instructions from multiple basic
end_comment

begin_comment
comment|// blocks at the same time. This makes it difficult to estimate the resource
end_comment

begin_comment
comment|// usage accurately in a single basic block. Resources can be estimated better
end_comment

begin_comment
comment|// by looking at a trace through the current basic block.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For every block, the MachineTraceMetrics pass will pick a preferred trace
end_comment

begin_comment
comment|// that passes through the block. The trace is chosen based on loop structure,
end_comment

begin_comment
comment|// branch probabilities, and resource usage. The intention is to pick likely
end_comment

begin_comment
comment|// traces that would be the most affected by code transformations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It is expensive to compute a full arbitrary trace for every block, so to
end_comment

begin_comment
comment|// save some computations, traces are chosen to be convergent. This means that
end_comment

begin_comment
comment|// if the traces through basic blocks A and B ever cross when moving away from
end_comment

begin_comment
comment|// A and B, they never diverge again. This applies in both directions - If the
end_comment

begin_comment
comment|// traces meet above A and B, they won't diverge when going further back.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Traces tend to align with loops. The trace through a block in an inner loop
end_comment

begin_comment
comment|// will begin at the loop entry block and end at a back edge. If there are
end_comment

begin_comment
comment|// nested loops, the trace may begin and end at those instead.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For each trace, we compute the critical path length, which is the number of
end_comment

begin_comment
comment|// cycles required to execute the trace when execution is limited by data
end_comment

begin_comment
comment|// dependencies only. We also compute the resource height, which is the number
end_comment

begin_comment
comment|// of cycles required to execute all instructions in the trace when ignoring
end_comment

begin_comment
comment|// data dependencies.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Every instruction in the current block has a slack - the number of cycles
end_comment

begin_comment
comment|// execution of the instruction can be delayed without extending the critical
end_comment

begin_comment
comment|// path.
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
name|LLVM_CODEGEN_MACHINETRACEMETRICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINETRACEMETRICS_H
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
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetSchedule.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
struct_decl|struct
name|MCSchedClassDesc
struct_decl|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|MachineTraceMetrics
range|:
name|public
name|MachineFunctionPass
block|{
specifier|const
name|MachineFunction
operator|*
name|MF
operator|=
name|nullptr
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|TII
operator|=
name|nullptr
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|nullptr
block|;
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
operator|=
name|nullptr
block|;
specifier|const
name|MachineLoopInfo
operator|*
name|Loops
operator|=
name|nullptr
block|;
name|TargetSchedModel
name|SchedModel
block|;
name|public
operator|:
name|friend
name|class
name|Ensemble
block|;
name|friend
name|class
name|Trace
block|;
name|class
name|Ensemble
block|;
specifier|static
name|char
name|ID
block|;
name|MachineTraceMetrics
argument_list|()
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|verifyAnalysis
argument_list|()
specifier|const
name|override
block|;
comment|/// Per-basic block information that doesn't depend on the trace through the
comment|/// block.
block|struct
name|FixedBlockInfo
block|{
comment|/// The number of non-trivial instructions in the block.
comment|/// Doesn't count PHI and COPY instructions that are likely to be removed.
name|unsigned
name|InstrCount
operator|=
operator|~
literal|0u
block|;
comment|/// True when the block contains calls.
name|bool
name|HasCalls
operator|=
name|false
block|;
name|FixedBlockInfo
argument_list|()
operator|=
expr|default
block|;
comment|/// Returns true when resource information for this block has been computed.
name|bool
name|hasResources
argument_list|()
specifier|const
block|{
return|return
name|InstrCount
operator|!=
operator|~
literal|0u
return|;
block|}
comment|/// Invalidate resource information.
name|void
name|invalidate
argument_list|()
block|{
name|InstrCount
operator|=
operator|~
literal|0u
block|; }
expr|}
block|;
comment|/// Get the fixed resource information about MBB. Compute it on demand.
specifier|const
name|FixedBlockInfo
operator|*
name|getResources
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
comment|/// Get the scaled number of cycles used per processor resource in MBB.
comment|/// This is an array with SchedModel.getNumProcResourceKinds() entries.
comment|/// The getResources() function above must have been called first.
comment|///
comment|/// These numbers have already been scaled by SchedModel.getResourceFactor().
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getProcResourceCycles
argument_list|(
argument|unsigned MBBNum
argument_list|)
specifier|const
block|;
comment|/// A virtual register or regunit required by a basic block or its trace
comment|/// successors.
block|struct
name|LiveInReg
block|{
comment|/// The virtual register required, or a register unit.
name|unsigned
name|Reg
block|;
comment|/// For virtual registers: Minimum height of the defining instruction.
comment|/// For regunits: Height of the highest user in the trace.
name|unsigned
name|Height
block|;
name|LiveInReg
argument_list|(
argument|unsigned Reg
argument_list|,
argument|unsigned Height =
literal|0
argument_list|)
operator|:
name|Reg
argument_list|(
name|Reg
argument_list|)
block|,
name|Height
argument_list|(
argument|Height
argument_list|)
block|{}
block|}
block|;
comment|/// Per-basic block information that relates to a specific trace through the
comment|/// block. Convergent traces means that only one of these is required per
comment|/// block in a trace ensemble.
block|struct
name|TraceBlockInfo
block|{
comment|/// Trace predecessor, or NULL for the first block in the trace.
comment|/// Valid when hasValidDepth().
specifier|const
name|MachineBasicBlock
operator|*
name|Pred
operator|=
name|nullptr
block|;
comment|/// Trace successor, or NULL for the last block in the trace.
comment|/// Valid when hasValidHeight().
specifier|const
name|MachineBasicBlock
operator|*
name|Succ
operator|=
name|nullptr
block|;
comment|/// The block number of the head of the trace. (When hasValidDepth()).
name|unsigned
name|Head
block|;
comment|/// The block number of the tail of the trace. (When hasValidHeight()).
name|unsigned
name|Tail
block|;
comment|/// Accumulated number of instructions in the trace above this block.
comment|/// Does not include instructions in this block.
name|unsigned
name|InstrDepth
operator|=
operator|~
literal|0u
block|;
comment|/// Accumulated number of instructions in the trace below this block.
comment|/// Includes instructions in this block.
name|unsigned
name|InstrHeight
operator|=
operator|~
literal|0u
block|;
name|TraceBlockInfo
argument_list|()
operator|=
expr|default
block|;
comment|/// Returns true if the depth resources have been computed from the trace
comment|/// above this block.
name|bool
name|hasValidDepth
argument_list|()
specifier|const
block|{
return|return
name|InstrDepth
operator|!=
operator|~
literal|0u
return|;
block|}
comment|/// Returns true if the height resources have been computed from the trace
comment|/// below this block.
name|bool
name|hasValidHeight
argument_list|()
specifier|const
block|{
return|return
name|InstrHeight
operator|!=
operator|~
literal|0u
return|;
block|}
comment|/// Invalidate depth resources when some block above this one has changed.
name|void
name|invalidateDepth
argument_list|()
block|{
name|InstrDepth
operator|=
operator|~
literal|0u
block|;
name|HasValidInstrDepths
operator|=
name|false
block|; }
comment|/// Invalidate height resources when a block below this one has changed.
name|void
name|invalidateHeight
argument_list|()
block|{
name|InstrHeight
operator|=
operator|~
literal|0u
block|;
name|HasValidInstrHeights
operator|=
name|false
block|; }
comment|/// Assuming that this is a dominator of TBI, determine if it contains
comment|/// useful instruction depths. A dominating block can be above the current
comment|/// trace head, and any dependencies from such a far away dominator are not
comment|/// expected to affect the critical path.
comment|///
comment|/// Also returns true when TBI == this.
name|bool
name|isUsefulDominator
argument_list|(
argument|const TraceBlockInfo&TBI
argument_list|)
specifier|const
block|{
comment|// The trace for TBI may not even be calculated yet.
if|if
condition|(
operator|!
name|hasValidDepth
argument_list|()
operator|||
operator|!
name|TBI
operator|.
name|hasValidDepth
argument_list|()
condition|)
return|return
name|false
return|;
comment|// Instruction depths are only comparable if the traces share a head.
if|if
condition|(
name|Head
operator|!=
name|TBI
operator|.
name|Head
condition|)
return|return
name|false
return|;
comment|// It is almost always the case that TBI belongs to the same trace as
comment|// this block, but rare convoluted cases involving irreducible control
comment|// flow, a dominator may share a trace head without actually being on the
comment|// same trace as TBI. This is not a big problem as long as it doesn't
comment|// increase the instruction depth.
return|return
name|HasValidInstrDepths
operator|&&
name|InstrDepth
operator|<=
name|TBI
operator|.
name|InstrDepth
return|;
block|}
comment|// Data-dependency-related information. Per-instruction depth and height
comment|// are computed from data dependencies in the current trace, using
comment|// itinerary data.
comment|/// Instruction depths have been computed. This implies hasValidDepth().
name|bool
name|HasValidInstrDepths
operator|=
name|false
block|;
comment|/// Instruction heights have been computed. This implies hasValidHeight().
name|bool
name|HasValidInstrHeights
operator|=
name|false
block|;
comment|/// Critical path length. This is the number of cycles in the longest data
comment|/// dependency chain through the trace. This is only valid when both
comment|/// HasValidInstrDepths and HasValidInstrHeights are set.
name|unsigned
name|CriticalPath
block|;
comment|/// Live-in registers. These registers are defined above the current block
comment|/// and used by this block or a block below it.
comment|/// This does not include PHI uses in the current block, but it does
comment|/// include PHI uses in deeper blocks.
name|SmallVector
operator|<
name|LiveInReg
block|,
literal|4
operator|>
name|LiveIns
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|/// InstrCycles represents the cycle height and depth of an instruction in a
comment|/// trace.
struct|struct
name|InstrCycles
block|{
comment|/// Earliest issue cycle as determined by data dependencies and instruction
comment|/// latencies from the beginning of the trace. Data dependencies from
comment|/// before the trace are not included.
name|unsigned
name|Depth
decl_stmt|;
comment|/// Minimum number of cycles from this instruction is issued to the of the
comment|/// trace, as determined by data dependencies and instruction latencies.
name|unsigned
name|Height
decl_stmt|;
block|}
struct|;
comment|/// A trace represents a plausible sequence of executed basic blocks that
comment|/// passes through the current basic block one. The Trace class serves as a
comment|/// handle to internal cached data structures.
name|class
name|Trace
block|{
name|Ensemble
modifier|&
name|TE
decl_stmt|;
name|TraceBlockInfo
modifier|&
name|TBI
decl_stmt|;
name|unsigned
name|getBlockNum
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TBI
operator|-
operator|&
name|TE
operator|.
name|BlockInfo
index|[
literal|0
index|]
return|;
block|}
name|public
label|:
name|explicit
name|Trace
argument_list|(
name|Ensemble
operator|&
name|te
argument_list|,
name|TraceBlockInfo
operator|&
name|tbi
argument_list|)
operator|:
name|TE
argument_list|(
name|te
argument_list|)
operator|,
name|TBI
argument_list|(
argument|tbi
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|)
specifier|const
expr_stmt|;
comment|/// Compute the total number of instructions in the trace.
name|unsigned
name|getInstrCount
argument_list|()
specifier|const
block|{
return|return
name|TBI
operator|.
name|InstrDepth
operator|+
name|TBI
operator|.
name|InstrHeight
return|;
block|}
comment|/// Return the resource depth of the top/bottom of the trace center block.
comment|/// This is the number of cycles required to execute all instructions from
comment|/// the trace head to the trace center block. The resource depth only
comment|/// considers execution resources, it ignores data dependencies.
comment|/// When Bottom is set, instructions in the trace center block are included.
name|unsigned
name|getResourceDepth
argument_list|(
name|bool
name|Bottom
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the resource length of the trace. This is the number of cycles
comment|/// required to execute the instructions in the trace if they were all
comment|/// independent, exposing the maximum instruction-level parallelism.
comment|///
comment|/// Any blocks in Extrablocks are included as if they were part of the
comment|/// trace. Likewise, extra resources required by the specified scheduling
comment|/// classes are included. For the caller to account for extra machine
comment|/// instructions, it must first resolve each instruction's scheduling class.
name|unsigned
name|getResourceLength
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
name|Extrablocks
operator|=
name|None
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MCSchedClassDesc
operator|*
operator|>
name|ExtraInstrs
operator|=
name|None
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MCSchedClassDesc
operator|*
operator|>
name|RemoveInstrs
operator|=
name|None
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the length of the (data dependency) critical path through the
comment|/// trace.
name|unsigned
name|getCriticalPath
argument_list|()
specifier|const
block|{
return|return
name|TBI
operator|.
name|CriticalPath
return|;
block|}
comment|/// Return the depth and height of MI. The depth is only valid for
comment|/// instructions in or above the trace center block. The height is only
comment|/// valid for instructions in or below the trace center block.
name|InstrCycles
name|getInstrCycles
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
block|{
return|return
name|TE
operator|.
name|Cycles
operator|.
name|lookup
argument_list|(
operator|&
name|MI
argument_list|)
return|;
block|}
comment|/// Return the slack of MI. This is the number of cycles MI can be delayed
comment|/// before the critical path becomes longer.
comment|/// MI must be an instruction in the trace center block.
name|unsigned
name|getInstrSlack
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the Depth of a PHI instruction in a trace center block successor.
comment|/// The PHI does not have to be part of the trace.
name|unsigned
name|getPHIDepth
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|PHI
argument_list|)
decl|const
decl_stmt|;
comment|/// A dependence is useful if the basic block of the defining instruction
comment|/// is part of the trace of the user instruction. It is assumed that DefMI
comment|/// dominates UseMI (see also isUsefulDominator).
name|bool
name|isDepInTrace
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|DefMI
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|UseMI
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// A trace ensemble is a collection of traces selected using the same
comment|/// strategy, for example 'minimum resource height'. There is one trace for
comment|/// every block in the function.
name|class
name|Ensemble
block|{
name|friend
name|class
name|Trace
decl_stmt|;
name|SmallVector
operator|<
name|TraceBlockInfo
operator|,
literal|4
operator|>
name|BlockInfo
expr_stmt|;
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
name|InstrCycles
operator|>
name|Cycles
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|0
operator|>
name|ProcResourceDepths
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|0
operator|>
name|ProcResourceHeights
expr_stmt|;
name|void
name|computeTrace
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|computeDepthResources
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|computeHeightResources
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|computeCrossBlockCriticalPath
parameter_list|(
specifier|const
name|TraceBlockInfo
modifier|&
parameter_list|)
function_decl|;
name|void
name|computeInstrDepths
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|computeInstrHeights
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|addLiveIns
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefOp
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
name|Trace
argument_list|)
decl_stmt|;
name|protected
label|:
name|MachineTraceMetrics
modifier|&
name|MTM
decl_stmt|;
name|explicit
name|Ensemble
parameter_list|(
name|MachineTraceMetrics
modifier|*
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|MachineBasicBlock
modifier|*
name|pickTracePred
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|MachineBasicBlock
modifier|*
name|pickTraceSucc
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
specifier|const
name|MachineLoop
modifier|*
name|getLoopFor
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|TraceBlockInfo
modifier|*
name|getDepthResources
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|TraceBlockInfo
modifier|*
name|getHeightResources
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
decl|const
decl_stmt|;
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getProcResourceDepths
argument_list|(
argument|unsigned MBBNum
argument_list|)
specifier|const
expr_stmt|;
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getProcResourceHeights
argument_list|(
argument|unsigned MBBNum
argument_list|)
specifier|const
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|Ensemble
argument_list|()
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|invalidate
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|void
name|verify
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the trace that passes through MBB.
comment|/// The trace is computed on demand.
name|Trace
name|getTrace
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Strategies for selecting traces.
enum|enum
name|Strategy
block|{
comment|/// Select the trace through a block that has the fewest instructions.
name|TS_MinInstrCount
block|,
name|TS_NumStrategies
block|}
enum|;
comment|/// Get the trace ensemble representing the given trace selection strategy.
comment|/// The returned Ensemble object is owned by the MachineTraceMetrics analysis,
comment|/// and valid for the lifetime of the analysis pass.
name|Ensemble
modifier|*
name|getEnsemble
parameter_list|(
name|Strategy
parameter_list|)
function_decl|;
comment|/// Invalidate cached information about MBB. This must be called *before* MBB
comment|/// is erased, or the CFG is otherwise changed.
comment|///
comment|/// This invalidates per-block information about resource usage for MBB only,
comment|/// and it invalidates per-trace information for any trace that passes
comment|/// through MBB.
comment|///
comment|/// Call Ensemble::getTrace() again to update any trace handles.
name|void
name|invalidate
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|private
label|:
comment|// One entry per basic block, indexed by block number.
name|SmallVector
operator|<
name|FixedBlockInfo
operator|,
literal|4
operator|>
name|BlockInfo
expr_stmt|;
comment|// Cycles consumed on each processor resource per block.
comment|// The number of processor resource kinds is constant for a given subtarget,
comment|// but it is not known at compile time. The number of cycles consumed by
comment|// block B on processor resource R is at ProcResourceCycles[B*Kinds + R]
comment|// where Kinds = SchedModel.getNumProcResourceKinds().
name|SmallVector
operator|<
name|unsigned
operator|,
literal|0
operator|>
name|ProcResourceCycles
expr_stmt|;
comment|// One ensemble per strategy.
name|Ensemble
modifier|*
name|Ensembles
index|[
name|TS_NumStrategies
index|]
decl_stmt|;
comment|// Convert scaled resource usage to a cycle count that can be compared with
comment|// latencies.
name|unsigned
name|getCycles
parameter_list|(
name|unsigned
name|Scaled
parameter_list|)
block|{
name|unsigned
name|Factor
init|=
name|SchedModel
operator|.
name|getLatencyFactor
argument_list|()
decl_stmt|;
return|return
operator|(
name|Scaled
operator|+
name|Factor
operator|-
literal|1
operator|)
operator|/
name|Factor
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineTraceMetrics
operator|::
name|Trace
operator|&
name|Tr
operator|)
block|{
name|Tr
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineTraceMetrics
operator|::
name|Ensemble
operator|&
name|En
operator|)
block|{
name|En
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACHINETRACEMETRICS_H
end_comment

end_unit

