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
name|LLVM_CODEGEN_MACHINE_TRACE_METRICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINE_TRACE_METRICS_H
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
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InstrItineraryData
decl_stmt|;
name|class
name|MachineBasicBlock
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
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|raw_ostream
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
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|TII
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
block|;
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
block|;
specifier|const
name|MachineLoopInfo
operator|*
name|Loops
block|;
name|public
operator|:
name|class
name|Ensemble
block|;
name|class
name|Trace
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
block|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
block|;
name|void
name|verifyAnalysis
argument_list|()
specifier|const
block|;
name|friend
name|class
name|Ensemble
block|;
name|friend
name|class
name|Trace
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
block|;
comment|/// True when the block contains calls.
name|bool
name|HasCalls
block|;
name|FixedBlockInfo
argument_list|()
operator|:
name|InstrCount
argument_list|(
operator|~
literal|0u
argument_list|)
block|,
name|HasCalls
argument_list|(
argument|false
argument_list|)
block|{}
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
block|;
comment|/// Trace successor, or NULL for the last block in the trace.
comment|/// Valid when hasValidHeight().
specifier|const
name|MachineBasicBlock
operator|*
name|Succ
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
block|;
comment|/// Accumulated number of instructions in the trace below this block.
comment|/// Includes instructions in this block.
name|unsigned
name|InstrHeight
block|;
name|TraceBlockInfo
argument_list|()
operator|:
name|Pred
argument_list|(
literal|0
argument_list|)
block|,
name|Succ
argument_list|(
literal|0
argument_list|)
block|,
name|InstrDepth
argument_list|(
operator|~
literal|0u
argument_list|)
block|,
name|InstrHeight
argument_list|(
operator|~
literal|0u
argument_list|)
block|,
name|HasValidInstrDepths
argument_list|(
name|false
argument_list|)
block|,
name|HasValidInstrHeights
argument_list|(
argument|false
argument_list|)
block|{}
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
comment|// Data-dependency-related information. Per-instruction depth and height
comment|// are computed from data dependencies in the current trace, using
comment|// itinerary data.
comment|/// Instruction depths have been computed. This implies hasValidDepth().
name|bool
name|HasValidInstrDepths
block|;
comment|/// Instruction heights have been computed. This implies hasValidHeight().
name|bool
name|HasValidInstrHeights
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
block|;
comment|/// InstrCycles represents the cycle height and depth of an instruction in a
comment|/// trace.
block|struct
name|InstrCycles
block|{
comment|/// Earliest issue cycle as determined by data dependencies and instruction
comment|/// latencies from the beginning of the trace. Data dependencies from
comment|/// before the trace are not included.
name|unsigned
name|Depth
block|;
comment|/// Minimum number of cycles from this instruction is issued to the of the
comment|/// trace, as determined by data dependencies and instruction latencies.
name|unsigned
name|Height
block|;   }
block|;
comment|/// A trace represents a plausible sequence of executed basic blocks that
comment|/// passes through the current basic block one. The Trace class serves as a
comment|/// handle to internal cached data structures.
name|class
name|Trace
block|{
name|Ensemble
operator|&
name|TE
block|;
name|TraceBlockInfo
operator|&
name|TBI
block|;
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
operator|:
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
block|,
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
block|;
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
argument|bool Bottom
argument_list|)
specifier|const
block|;
comment|/// Return the resource length of the trace. This is the number of cycles
comment|/// required to execute the instructions in the trace if they were all
comment|/// independent, exposing the maximum instruction-level parallelism.
comment|///
comment|/// Any blocks in Extrablocks are included as if they were part of the
comment|/// trace.
name|unsigned
name|getResourceLength
argument_list|(
argument|ArrayRef<const MachineBasicBlock*> Extrablocks =                                ArrayRef<const MachineBasicBlock*>()
argument_list|)
specifier|const
block|;
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
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|TE
operator|.
name|Cycles
operator|.
name|lookup
argument_list|(
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
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Return the Depth of a PHI instruction in a trace center block successor.
comment|/// The PHI does not have to be part of the trace.
name|unsigned
name|getPHIDepth
argument_list|(
argument|const MachineInstr *PHI
argument_list|)
specifier|const
block|;   }
block|;
comment|/// A trace ensemble is a collection of traces selected using the same
comment|/// strategy, for example 'minimum resource height'. There is one trace for
comment|/// every block in the function.
name|class
name|Ensemble
block|{
name|SmallVector
operator|<
name|TraceBlockInfo
block|,
literal|4
operator|>
name|BlockInfo
block|;
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
name|InstrCycles
operator|>
name|Cycles
block|;
name|friend
name|class
name|Trace
block|;
name|void
name|computeTrace
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
name|void
name|computeDepthResources
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
name|void
name|computeHeightResources
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
name|unsigned
name|computeCrossBlockCriticalPath
argument_list|(
specifier|const
name|TraceBlockInfo
operator|&
argument_list|)
block|;
name|void
name|computeInstrDepths
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
name|void
name|computeInstrHeights
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
block|;
name|void
name|addLiveIns
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
name|Trace
argument_list|)
block|;
name|protected
operator|:
name|MachineTraceMetrics
operator|&
name|MTM
block|;
name|virtual
specifier|const
name|MachineBasicBlock
operator|*
name|pickTracePred
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|MachineBasicBlock
operator|*
name|pickTraceSucc
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
argument_list|)
operator|=
literal|0
block|;
name|explicit
name|Ensemble
argument_list|(
name|MachineTraceMetrics
operator|*
argument_list|)
block|;
specifier|const
name|MachineLoop
operator|*
name|getLoopFor
argument_list|(
argument|const MachineBasicBlock*
argument_list|)
specifier|const
block|;
specifier|const
name|TraceBlockInfo
operator|*
name|getDepthResources
argument_list|(
argument|const MachineBasicBlock*
argument_list|)
specifier|const
block|;
specifier|const
name|TraceBlockInfo
operator|*
name|getHeightResources
argument_list|(
argument|const MachineBasicBlock*
argument_list|)
specifier|const
block|;
name|public
operator|:
name|virtual
operator|~
name|Ensemble
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|)
specifier|const
block|;
name|void
name|invalidate
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
name|void
name|verify
argument_list|()
specifier|const
block|;
comment|/// Get the trace that passes through MBB.
comment|/// The trace is computed on demand.
name|Trace
name|getTrace
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;   }
block|;
comment|/// Strategies for selecting traces.
block|enum
name|Strategy
block|{
comment|/// Select the trace through a block that has the fewest instructions.
name|TS_MinInstrCount
block|,
name|TS_NumStrategies
block|}
block|;
comment|/// Get the trace ensemble representing the given trace selection strategy.
comment|/// The returned Ensemble object is owned by the MachineTraceMetrics analysis,
comment|/// and valid for the lifetime of the analysis pass.
name|Ensemble
operator|*
name|getEnsemble
argument_list|(
name|Strategy
argument_list|)
block|;
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
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
name|private
operator|:
comment|// One entry per basic block, indexed by block number.
name|SmallVector
operator|<
name|FixedBlockInfo
block|,
literal|4
operator|>
name|BlockInfo
block|;
comment|// One ensemble per strategy.
name|Ensemble
operator|*
name|Ensembles
index|[
name|TS_NumStrategies
index|]
block|; }
block|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
expr|,
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
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
expr|,
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
expr|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

