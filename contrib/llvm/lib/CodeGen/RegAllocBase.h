begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegAllocBase.h - basic regalloc interface and driver --*- C++ -*---===//
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
comment|// This file defines the RegAllocBase class, which is the skeleton of a basic
end_comment

begin_comment
comment|// register allocation algorithm and interface for extending it. It provides the
end_comment

begin_comment
comment|// building blocks on which to construct other experimental allocators and test
end_comment

begin_comment
comment|// the validity of two principles:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - If virtual and physical register liveness is modeled using intervals, then
end_comment

begin_comment
comment|// on-the-fly interference checking is cheap. Furthermore, interferences can be
end_comment

begin_comment
comment|// lazily cached and reused.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - Register allocation complexity, and generated code performance is
end_comment

begin_comment
comment|// determined by the effectiveness of live range splitting rather than optimal
end_comment

begin_comment
comment|// coloring.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Following the first principle, interfering checking revolves around the
end_comment

begin_comment
comment|// LiveIntervalUnion data structure.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To fulfill the second principle, the basic allocator provides a driver for
end_comment

begin_comment
comment|// incremental splitting. It essentially punts on the problem of register
end_comment

begin_comment
comment|// coloring, instead driving the assignment of virtual to physical registers by
end_comment

begin_comment
comment|// the cost of splitting. The basic allocator allows for heuristic reassignment
end_comment

begin_comment
comment|// of registers, if a more sophisticated allocator chooses to do that.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This framework provides a way to engineer the compile time vs. code
end_comment

begin_comment
comment|// quality trade-off without relying on a particular theoretical solver.
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
name|LLVM_CODEGEN_REGALLOCBASE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGALLOCBASE
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"LiveIntervalUnion.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|Spiller
decl_stmt|;
comment|// Forward declare a priority queue of live virtual registers. If an
comment|// implementation needs to prioritize by anything other than spill weight, then
comment|// this will become an abstract base class with virtual calls to push/get.
name|class
name|LiveVirtRegQueue
decl_stmt|;
comment|/// RegAllocBase provides the register allocation driver and interface that can
comment|/// be extended to add interesting heuristics.
comment|///
comment|/// Register allocators must override the selectOrSplit() method to implement
comment|/// live range splitting. They must also override enqueue/dequeue to provide an
comment|/// assignment order.
name|class
name|RegAllocBase
block|{
name|LiveIntervalUnion
operator|::
name|Allocator
name|UnionAllocator
expr_stmt|;
name|protected
label|:
comment|// Array of LiveIntervalUnions indexed by physical register.
name|class
name|LiveUnionArray
block|{
name|unsigned
name|NumRegs
decl_stmt|;
name|LiveIntervalUnion
modifier|*
name|Array
decl_stmt|;
name|public
label|:
name|LiveUnionArray
argument_list|()
operator|:
name|NumRegs
argument_list|(
literal|0
argument_list|)
operator|,
name|Array
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|LiveUnionArray
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|unsigned
name|numRegs
argument_list|()
specifier|const
block|{
return|return
name|NumRegs
return|;
block|}
name|void
name|init
argument_list|(
name|LiveIntervalUnion
operator|::
name|Allocator
operator|&
argument_list|,
name|unsigned
name|NRegs
argument_list|)
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|LiveIntervalUnion
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|PhysReg
parameter_list|)
block|{
name|assert
argument_list|(
name|PhysReg
operator|<
name|NumRegs
operator|&&
literal|"physReg out of bounds"
argument_list|)
expr_stmt|;
return|return
name|Array
index|[
name|PhysReg
index|]
return|;
block|}
block|}
empty_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
name|VirtRegMap
modifier|*
name|VRM
decl_stmt|;
name|LiveIntervals
modifier|*
name|LIS
decl_stmt|;
name|LiveUnionArray
name|PhysReg2LiveUnion
decl_stmt|;
comment|// Current queries, one per physreg. They must be reinitialized each time we
comment|// query on a new live virtual register.
name|OwningArrayPtr
operator|<
name|LiveIntervalUnion
operator|::
name|Query
operator|>
name|Queries
expr_stmt|;
name|RegAllocBase
argument_list|()
operator|:
name|TRI
argument_list|(
literal|0
argument_list|)
operator|,
name|MRI
argument_list|(
literal|0
argument_list|)
operator|,
name|VRM
argument_list|(
literal|0
argument_list|)
operator|,
name|LIS
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|RegAllocBase
argument_list|()
block|{}
comment|// A RegAlloc pass should call this before allocatePhysRegs.
name|void
name|init
argument_list|(
name|VirtRegMap
operator|&
name|vrm
argument_list|,
name|LiveIntervals
operator|&
name|lis
argument_list|)
expr_stmt|;
comment|// Get an initialized query to check interferences between lvr and preg.  Note
comment|// that Query::init must be called at least once for each physical register
comment|// before querying a new live virtual register. This ties Queries and
comment|// PhysReg2LiveUnion together.
name|LiveIntervalUnion
operator|::
name|Query
operator|&
name|query
argument_list|(
argument|LiveInterval&VirtReg
argument_list|,
argument|unsigned PhysReg
argument_list|)
block|{
name|Queries
index|[
name|PhysReg
index|]
operator|.
name|init
argument_list|(
operator|&
name|VirtReg
argument_list|,
operator|&
name|PhysReg2LiveUnion
index|[
name|PhysReg
index|]
argument_list|)
block|;
return|return
name|Queries
index|[
name|PhysReg
index|]
return|;
block|}
comment|// The top-level driver. The output is a VirtRegMap that us updated with
comment|// physical register assignments.
comment|//
comment|// If an implementation wants to override the LiveInterval comparator, we
comment|// should modify this interface to allow passing in an instance derived from
comment|// LiveVirtRegQueue.
name|void
name|allocatePhysRegs
parameter_list|()
function_decl|;
comment|// Get a temporary reference to a Spiller instance.
name|virtual
name|Spiller
modifier|&
name|spiller
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// enqueue - Add VirtReg to the priority queue of unassigned registers.
name|virtual
name|void
name|enqueue
parameter_list|(
name|LiveInterval
modifier|*
name|LI
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// dequeue - Return the next unassigned register, or NULL.
name|virtual
name|LiveInterval
modifier|*
name|dequeue
parameter_list|()
init|=
literal|0
function_decl|;
comment|// A RegAlloc pass should override this to provide the allocation heuristics.
comment|// Each call must guarantee forward progess by returning an available PhysReg
comment|// or new set of split live virtual registers. It is up to the splitter to
comment|// converge quickly toward fully spilled live ranges.
name|virtual
name|unsigned
name|selectOrSplit
argument_list|(
name|LiveInterval
operator|&
name|VirtReg
argument_list|,
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|splitLVRs
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// A RegAlloc pass should call this when PassManager releases its memory.
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|// Helper for checking interference between a live virtual register and a
comment|// physical register, including all its register aliases. If an interference
comment|// exists, return the interfering register, which may be preg or an alias.
name|unsigned
name|checkPhysRegInterference
parameter_list|(
name|LiveInterval
modifier|&
name|VirtReg
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|)
function_decl|;
comment|/// assign - Assign VirtReg to PhysReg.
comment|/// This should not be called from selectOrSplit for the current register.
name|void
name|assign
parameter_list|(
name|LiveInterval
modifier|&
name|VirtReg
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|)
function_decl|;
comment|/// unassign - Undo a previous assignment of VirtReg to PhysReg.
comment|/// This can be invoked from selectOrSplit, but be careful to guarantee that
comment|/// allocation is making progress.
name|void
name|unassign
parameter_list|(
name|LiveInterval
modifier|&
name|VirtReg
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|)
function_decl|;
comment|// Helper for spilling all live virtual registers currently unified under preg
comment|// that interfere with the most recently queried lvr.  Return true if spilling
comment|// was successful, and append any new spilled/split intervals to splitLVRs.
name|bool
name|spillInterferences
argument_list|(
name|LiveInterval
operator|&
name|VirtReg
argument_list|,
name|unsigned
name|PhysReg
argument_list|,
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|SplitVRegs
argument_list|)
decl_stmt|;
comment|/// addMBBLiveIns - Add physreg liveins to basic blocks.
name|void
name|addMBBLiveIns
parameter_list|(
name|MachineFunction
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Verify each LiveIntervalUnion.
name|void
name|verify
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// Use this group name for NamedRegionTimer.
specifier|static
specifier|const
name|char
modifier|*
name|TimerGroupName
decl_stmt|;
name|public
label|:
comment|/// VerifyEnabled - True when -verify-regalloc is given.
specifier|static
name|bool
name|VerifyEnabled
decl_stmt|;
name|private
label|:
name|void
name|seedLiveRegs
parameter_list|()
function_decl|;
name|void
name|spillReg
argument_list|(
name|LiveInterval
operator|&
name|VirtReg
argument_list|,
name|unsigned
name|PhysReg
argument_list|,
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|SplitVRegs
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(LLVM_CODEGEN_REGALLOCBASE)
end_comment

end_unit

