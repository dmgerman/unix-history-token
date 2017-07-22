begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/CodeGen/ExecutionDepsFix.h - Execution Dependency Fix -*- C++ -*-==//
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
comment|/// \file Execution Dependency Fix pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Some X86 SSE instructions like mov, and, or, xor are available in different
end_comment

begin_comment
comment|/// variants for different operand types. These variant instructions are
end_comment

begin_comment
comment|/// equivalent, but on Nehalem and newer cpus there is extra latency
end_comment

begin_comment
comment|/// transferring data between integer and floating point domains.  ARM cores
end_comment

begin_comment
comment|/// have similar issues when they are configured with both VFP and NEON
end_comment

begin_comment
comment|/// pipelines.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This pass changes the variant instructions to minimize domain crossings.
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
name|LLVM_CODEGEN_EXECUTIONDEPSFIX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_EXECUTIONDEPSFIX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LivePhysRegs.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterClassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// A DomainValue is a bit like LiveIntervals' ValNo, but it also keeps track
comment|/// of execution domains.
comment|///
comment|/// An open DomainValue represents a set of instructions that can still switch
comment|/// execution domain. Multiple registers may refer to the same open
comment|/// DomainValue - they will eventually be collapsed to the same execution
comment|/// domain.
comment|///
comment|/// A collapsed DomainValue represents a single register that has been forced
comment|/// into one of more execution domains. There is a separate collapsed
comment|/// DomainValue for each register, but it may contain multiple execution
comment|/// domains. A register value is initially created in a single execution
comment|/// domain, but if we were forced to pay the penalty of a domain crossing, we
comment|/// keep track of the fact that the register is now available in multiple
comment|/// domains.
struct|struct
name|DomainValue
block|{
comment|// Basic reference counting.
name|unsigned
name|Refs
init|=
literal|0
decl_stmt|;
comment|// Bitmask of available domains. For an open DomainValue, it is the still
comment|// possible domains for collapsing. For a collapsed DomainValue it is the
comment|// domains where the register is available for free.
name|unsigned
name|AvailableDomains
decl_stmt|;
comment|// Pointer to the next DomainValue in a chain.  When two DomainValues are
comment|// merged, Victim.Next is set to point to Victor, so old DomainValue
comment|// references can be updated by following the chain.
name|DomainValue
modifier|*
name|Next
decl_stmt|;
comment|// Twiddleable instructions using or defining these registers.
name|SmallVector
operator|<
name|MachineInstr
operator|*
operator|,
literal|8
operator|>
name|Instrs
expr_stmt|;
name|DomainValue
argument_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// A collapsed DomainValue has no instructions to twiddle - it simply keeps
comment|// track of the domains where the registers are already available.
name|bool
name|isCollapsed
argument_list|()
specifier|const
block|{
return|return
name|Instrs
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// Is domain available?
name|bool
name|hasDomain
argument_list|(
name|unsigned
name|domain
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|domain
operator|<
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|unsigned
operator|>
operator|::
name|digits
operator|)
operator|&&
literal|"undefined behavior"
argument_list|)
expr_stmt|;
return|return
name|AvailableDomains
operator|&
operator|(
literal|1u
operator|<<
name|domain
operator|)
return|;
block|}
comment|// Mark domain as available.
name|void
name|addDomain
parameter_list|(
name|unsigned
name|domain
parameter_list|)
block|{
name|AvailableDomains
operator||=
literal|1u
operator|<<
name|domain
expr_stmt|;
block|}
comment|// Restrict to a single domain available.
name|void
name|setSingleDomain
parameter_list|(
name|unsigned
name|domain
parameter_list|)
block|{
name|AvailableDomains
operator|=
literal|1u
operator|<<
name|domain
expr_stmt|;
block|}
comment|// Return bitmask of domains that are available and in mask.
name|unsigned
name|getCommonDomains
argument_list|(
name|unsigned
name|mask
argument_list|)
decl|const
block|{
return|return
name|AvailableDomains
operator|&
name|mask
return|;
block|}
comment|// First domain available.
name|unsigned
name|getFirstDomain
argument_list|()
specifier|const
block|{
return|return
name|countTrailingZeros
argument_list|(
name|AvailableDomains
argument_list|)
return|;
block|}
comment|// Clear this DomainValue and point to next which has all its data.
name|void
name|clear
parameter_list|()
block|{
name|AvailableDomains
operator|=
literal|0
expr_stmt|;
name|Next
operator|=
name|nullptr
expr_stmt|;
name|Instrs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
comment|/// Information about a live register.
struct|struct
name|LiveReg
block|{
comment|/// Value currently in this register, or NULL when no value is being tracked.
comment|/// This counts as a DomainValue reference.
name|DomainValue
modifier|*
name|Value
decl_stmt|;
comment|/// Instruction that defined this register, relative to the beginning of the
comment|/// current basic block.  When a LiveReg is used to represent a live-out
comment|/// register, this value is relative to the end of the basic block, so it
comment|/// will be a negative number.
name|int
name|Def
decl_stmt|;
block|}
struct|;
name|class
name|ExecutionDepsFix
range|:
name|public
name|MachineFunctionPass
block|{
name|SpecificBumpPtrAllocator
operator|<
name|DomainValue
operator|>
name|Allocator
block|;
name|SmallVector
operator|<
name|DomainValue
operator|*
block|,
literal|16
operator|>
name|Avail
block|;
specifier|const
name|TargetRegisterClass
operator|*
specifier|const
name|RC
block|;
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
name|RegisterClassInfo
name|RegClassInfo
block|;
name|std
operator|::
name|vector
operator|<
name|SmallVector
operator|<
name|int
block|,
literal|1
operator|>>
name|AliasMap
block|;
specifier|const
name|unsigned
name|NumRegs
block|;
name|LiveReg
operator|*
name|LiveRegs
block|;   struct
name|MBBInfo
block|{
comment|// Keeps clearance and domain information for all registers. Note that this
comment|// is different from the usual definition notion of liveness. The CPU
comment|// doesn't care whether or not we consider a register killed.
name|LiveReg
operator|*
name|OutRegs
operator|=
name|nullptr
block|;
comment|// Whether we have gotten to this block in primary processing yet.
name|bool
name|PrimaryCompleted
operator|=
name|false
block|;
comment|// The number of predecessors for which primary processing has completed
name|unsigned
name|IncomingProcessed
operator|=
literal|0
block|;
comment|// The value of `IncomingProcessed` at the start of primary processing
name|unsigned
name|PrimaryIncoming
operator|=
literal|0
block|;
comment|// The number of predecessors for which all processing steps are done.
name|unsigned
name|IncomingCompleted
operator|=
literal|0
block|;
name|MBBInfo
argument_list|()
operator|=
expr|default
block|;   }
block|;
name|using
name|MBBInfoMap
operator|=
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
block|,
name|MBBInfo
operator|>
block|;
name|MBBInfoMap
name|MBBInfos
block|;
comment|/// List of undefined register reads in this block in forward order.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
block|,
name|unsigned
operator|>>
name|UndefReads
block|;
comment|/// Storage for register unit liveness.
name|LivePhysRegs
name|LiveRegSet
block|;
comment|/// Current instruction number.
comment|/// The first instruction in each basic block is 0.
name|int
name|CurInstr
block|;
name|public
operator|:
name|ExecutionDepsFix
argument_list|(
name|char
operator|&
name|PassID
argument_list|,
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
operator|:
name|MachineFunctionPass
argument_list|(
name|PassID
argument_list|)
block|,
name|RC
argument_list|(
operator|&
name|RC
argument_list|)
block|,
name|NumRegs
argument_list|(
argument|RC.getNumRegs()
argument_list|)
block|{}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;
name|MachineFunctionPass
operator|::
name|getAnalysisUsage
argument_list|(
name|AU
argument_list|)
block|;   }
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|MachineFunctionProperties
name|getRequiredProperties
argument_list|()
specifier|const
name|override
block|{
return|return
name|MachineFunctionProperties
argument_list|()
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|NoVRegs
argument_list|)
return|;
block|}
name|private
operator|:
name|iterator_range
operator|<
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|::
name|const_iterator
operator|>
name|regIndices
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|;
comment|// DomainValue allocation.
name|DomainValue
operator|*
name|alloc
argument_list|(
argument|int domain = -
literal|1
argument_list|)
block|;
name|DomainValue
operator|*
name|retain
argument_list|(
argument|DomainValue *DV
argument_list|)
block|{
if|if
condition|(
name|DV
condition|)
operator|++
name|DV
operator|->
name|Refs
expr_stmt|;
return|return
name|DV
return|;
block|}
name|void
name|release
parameter_list|(
name|DomainValue
modifier|*
parameter_list|)
function_decl|;
name|DomainValue
modifier|*
name|resolve
parameter_list|(
name|DomainValue
modifier|*
modifier|&
parameter_list|)
function_decl|;
comment|// LiveRegs manipulations.
name|void
name|setLiveReg
parameter_list|(
name|int
name|rx
parameter_list|,
name|DomainValue
modifier|*
name|DV
parameter_list|)
function_decl|;
name|void
name|kill
parameter_list|(
name|int
name|rx
parameter_list|)
function_decl|;
name|void
name|force
parameter_list|(
name|int
name|rx
parameter_list|,
name|unsigned
name|domain
parameter_list|)
function_decl|;
name|void
name|collapse
parameter_list|(
name|DomainValue
modifier|*
name|dv
parameter_list|,
name|unsigned
name|domain
parameter_list|)
function_decl|;
name|bool
name|merge
parameter_list|(
name|DomainValue
modifier|*
name|A
parameter_list|,
name|DomainValue
modifier|*
name|B
parameter_list|)
function_decl|;
name|void
name|enterBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|leaveBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|bool
name|isBlockDone
parameter_list|(
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|processBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|bool
name|PrimaryPass
parameter_list|)
function_decl|;
name|bool
name|visitInstr
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|)
function_decl|;
name|void
name|processDefs
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|,
name|bool
name|breakDependency
parameter_list|,
name|bool
name|Kill
parameter_list|)
function_decl|;
name|void
name|visitSoftInstr
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|,
name|unsigned
name|mask
parameter_list|)
function_decl|;
name|void
name|visitHardInstr
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|,
name|unsigned
name|domain
parameter_list|)
function_decl|;
name|bool
name|pickBestRegisterForUndef
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|OpIdx
parameter_list|,
name|unsigned
name|Pref
parameter_list|)
function_decl|;
name|bool
name|shouldBreakDependence
parameter_list|(
name|MachineInstr
modifier|*
parameter_list|,
name|unsigned
name|OpIdx
parameter_list|,
name|unsigned
name|Pref
parameter_list|)
function_decl|;
name|void
name|processUndefReads
parameter_list|(
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namepsace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_EXECUTIONDEPSFIX_H
end_comment

end_unit

