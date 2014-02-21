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
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterClassInfo.h"
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
name|LiveRegMatrix
decl_stmt|;
name|class
name|Spiller
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
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|protected
label|:
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
name|LiveRegMatrix
modifier|*
name|Matrix
decl_stmt|;
name|RegisterClassInfo
name|RegClassInfo
decl_stmt|;
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
operator|,
name|Matrix
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
argument_list|,
name|LiveRegMatrix
operator|&
name|mat
argument_list|)
expr_stmt|;
comment|// The top-level driver. The output is a VirtRegMap that us updated with
comment|// physical register assignments.
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
name|unsigned
operator|>
operator|&
name|splitLVRs
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// Use this group name for NamedRegionTimer.
specifier|static
specifier|const
name|char
name|TimerGroupName
index|[]
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

