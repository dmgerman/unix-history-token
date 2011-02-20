begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterCoalescer.h - Register Coalescing Interface ------*- C++ -*-===//
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
comment|// This file contains the abstract interface for register coalescers,
end_comment

begin_comment
comment|// allowing them to interact with and query register allocators.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/IncludeFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_REGISTER_COALESCER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGISTER_COALESCER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegallocQuery
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// An abstract interface for register coalescers.  Coalescers must
comment|/// implement this interface to be part of the coalescer analysis
comment|/// group.
name|class
name|RegisterCoalescer
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification, replacement for typeinfo
name|RegisterCoalescer
argument_list|()
block|{}
name|virtual
operator|~
name|RegisterCoalescer
argument_list|()
expr_stmt|;
comment|// We want to be subclassed
comment|/// Run the coalescer on this function, providing interference
comment|/// data to query.  Return whether we removed any copies.
name|virtual
name|bool
name|coalesceFunction
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|,
name|RegallocQuery
modifier|&
name|ifd
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Reset state.  Can be used to allow a coalescer run by
comment|/// PassManager to be run again by the register allocator.
name|virtual
name|void
name|reset
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|)
block|{}
comment|/// Register allocators must call this from their own
comment|/// getAnalysisUsage to cover the case where the coalescer is not
comment|/// a Pass in the proper sense and isn't managed by PassManager.
comment|/// PassManager needs to know which analyses to make available and
comment|/// which to invalidate when running the register allocator or any
comment|/// pass that might call coalescing.  The long-term solution is to
comment|/// allow hierarchies of PassManagers.
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
block|{}
block|}
empty_stmt|;
comment|/// An abstract interface for register allocators to interact with
comment|/// coalescers
comment|///
comment|/// Example:
comment|///
comment|/// This is simply an example of how to use the RegallocQuery
comment|/// interface.  It is not meant to be used in production.
comment|///
comment|///   class LinearScanRegallocQuery : public RegallocQuery {
comment|///   private:
comment|///     const LiveIntervals \&li;
comment|///
comment|///   public:
comment|///     LinearScanRegallocQuery(LiveIntervals&intervals)
comment|///         : li(intervals) {}
comment|///
comment|///     /// This is pretty slow and conservative, but since linear scan
comment|///     /// allocation doesn't pre-compute interference information it's
comment|///     /// the best we can do.  Coalescers are always free to ignore this
comment|///     /// and implement their own discovery strategy.  See
comment|///     /// SimpleRegisterCoalescing for an example.
comment|///     void getInterferences(IntervalSet&interferences,
comment|///                           const LiveInterval&a) const {
comment|///       for(LiveIntervals::const_iterator iv = li.begin(),
comment|///             ivend = li.end();
comment|///           iv != ivend;
comment|///           ++iv) {
comment|///         if (interfere(a, iv->second)) {
comment|///           interferences.insert(&iv->second);
comment|///         }
comment|///       }
comment|///     }
comment|///
comment|///     /// This is *really* slow and stupid.  See above.
comment|///     int getNumberOfInterferences(const LiveInterval&a) const {
comment|///       IntervalSet intervals;
comment|///       getInterferences(intervals, a);
comment|///       return intervals.size();
comment|///     }
comment|///   };
comment|///
comment|///   In the allocator:
comment|///
comment|///   RegisterCoalescer&coalescer = getAnalysis<RegisterCoalescer>();
comment|///
comment|///   // We don't reset the coalescer so if it's already been run this
comment|///   // takes almost no time.
comment|///   LinearScanRegallocQuery ifd(*li_);
comment|///   coalescer.coalesceFunction(fn, ifd);
comment|///
name|class
name|RegallocQuery
block|{
name|public
label|:
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|LiveInterval
operator|*
operator|,
literal|8
operator|>
name|IntervalSet
expr_stmt|;
name|virtual
operator|~
name|RegallocQuery
argument_list|()
block|{}
comment|/// Return whether two live ranges interfere.
name|virtual
name|bool
name|interfere
argument_list|(
argument|const LiveInterval&a
argument_list|,
argument|const LiveInterval&b
argument_list|)
specifier|const
block|{
comment|// A naive test
return|return
name|a
operator|.
name|overlaps
argument_list|(
name|b
argument_list|)
return|;
block|}
comment|/// Return the set of intervals that interfere with this one.
name|virtual
name|void
name|getInterferences
argument_list|(
name|IntervalSet
operator|&
name|interferences
argument_list|,
specifier|const
name|LiveInterval
operator|&
name|a
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// This can often be cheaper than actually returning the
comment|/// interferences.
name|virtual
name|int
name|getNumberOfInterferences
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|a
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Make any data structure updates necessary to reflect
comment|/// coalescing or other modifications.
name|virtual
name|void
name|updateDataForMerge
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|a
parameter_list|,
specifier|const
name|LiveInterval
modifier|&
name|b
parameter_list|,
specifier|const
name|MachineInstr
modifier|&
name|copy
parameter_list|)
block|{}
comment|/// Allow the register allocator to communicate when it doesn't
comment|/// want a copy coalesced.  This may be due to assumptions made by
comment|/// the allocator about various invariants and so this question is
comment|/// a matter of legality, not performance.  Performance decisions
comment|/// about which copies to coalesce should be made by the
comment|/// coalescer.
name|virtual
name|bool
name|isLegalToCoalesce
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|inst
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// CoalescerPair - A helper class for register coalescers. When deciding if
comment|/// two registers can be coalesced, CoalescerPair can determine if a copy
comment|/// instruction would become an identity copy after coalescing.
name|class
name|CoalescerPair
block|{
specifier|const
name|TargetInstrInfo
modifier|&
name|tii_
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|&
name|tri_
decl_stmt|;
comment|/// dstReg_ - The register that will be left after coalescing. It can be a
comment|/// virtual or physical register.
name|unsigned
name|dstReg_
decl_stmt|;
comment|/// srcReg_ - the virtual register that will be coalesced into dstReg.
name|unsigned
name|srcReg_
decl_stmt|;
comment|/// subReg_ - The subregister index of srcReg in dstReg_. It is possible the
comment|/// coalesce srcReg_ into a subreg of the larger dstReg_ when dstReg_ is a
comment|/// virtual register.
name|unsigned
name|subIdx_
decl_stmt|;
comment|/// partial_ - True when the original copy was a partial subregister copy.
name|bool
name|partial_
decl_stmt|;
comment|/// crossClass_ - True when both regs are virtual, and newRC is constrained.
name|bool
name|crossClass_
decl_stmt|;
comment|/// flipped_ - True when DstReg and SrcReg are reversed from the oriignal copy
comment|/// instruction.
name|bool
name|flipped_
decl_stmt|;
comment|/// newRC_ - The register class of the coalesced register, or NULL if dstReg_
comment|/// is a physreg.
specifier|const
name|TargetRegisterClass
modifier|*
name|newRC_
decl_stmt|;
comment|/// compose - Compose subreg indices a and b, either may be 0.
name|unsigned
name|compose
argument_list|(
name|unsigned
argument_list|,
name|unsigned
argument_list|)
decl|const
decl_stmt|;
comment|/// isMoveInstr - Return true if MI is a move or subreg instruction.
name|bool
name|isMoveInstr
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
operator|&
name|Src
argument_list|,
name|unsigned
operator|&
name|Dst
argument_list|,
name|unsigned
operator|&
name|SrcSub
argument_list|,
name|unsigned
operator|&
name|DstSub
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|CoalescerPair
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|tri
argument_list|)
operator|:
name|tii_
argument_list|(
name|tii
argument_list|)
operator|,
name|tri_
argument_list|(
name|tri
argument_list|)
operator|,
name|dstReg_
argument_list|(
literal|0
argument_list|)
operator|,
name|srcReg_
argument_list|(
literal|0
argument_list|)
operator|,
name|subIdx_
argument_list|(
literal|0
argument_list|)
operator|,
name|partial_
argument_list|(
name|false
argument_list|)
operator|,
name|crossClass_
argument_list|(
name|false
argument_list|)
operator|,
name|flipped_
argument_list|(
name|false
argument_list|)
operator|,
name|newRC_
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// setRegisters - set registers to match the copy instruction MI. Return
comment|/// false if MI is not a coalescable copy instruction.
name|bool
name|setRegisters
argument_list|(
specifier|const
name|MachineInstr
operator|*
argument_list|)
expr_stmt|;
comment|/// flip - Swap srcReg_ and dstReg_. Return false if swapping is impossible
comment|/// because dstReg_ is a physical register, or subIdx_ is set.
name|bool
name|flip
parameter_list|()
function_decl|;
comment|/// isCoalescable - Return true if MI is a copy instruction that will become
comment|/// an identity copy after coalescing.
name|bool
name|isCoalescable
argument_list|(
specifier|const
name|MachineInstr
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// isPhys - Return true if DstReg is a physical register.
name|bool
name|isPhys
argument_list|()
specifier|const
block|{
return|return
operator|!
name|newRC_
return|;
block|}
comment|/// isPartial - Return true if the original copy instruction did not copy the
comment|/// full register, but was a subreg operation.
name|bool
name|isPartial
argument_list|()
specifier|const
block|{
return|return
name|partial_
return|;
block|}
comment|/// isCrossClass - Return true if DstReg is virtual and NewRC is a smaller register class than DstReg's.
name|bool
name|isCrossClass
argument_list|()
specifier|const
block|{
return|return
name|crossClass_
return|;
block|}
comment|/// isFlipped - Return true when getSrcReg is the register being defined by
comment|/// the original copy instruction.
name|bool
name|isFlipped
argument_list|()
specifier|const
block|{
return|return
name|flipped_
return|;
block|}
comment|/// getDstReg - Return the register (virtual or physical) that will remain
comment|/// after coalescing.
name|unsigned
name|getDstReg
argument_list|()
specifier|const
block|{
return|return
name|dstReg_
return|;
block|}
comment|/// getSrcReg - Return the virtual register that will be coalesced away.
name|unsigned
name|getSrcReg
argument_list|()
specifier|const
block|{
return|return
name|srcReg_
return|;
block|}
comment|/// getSubIdx - Return the subregister index in DstReg that SrcReg will be
comment|/// coalesced into, or 0.
name|unsigned
name|getSubIdx
argument_list|()
specifier|const
block|{
return|return
name|subIdx_
return|;
block|}
comment|/// getNewRC - Return the register class of the coalesced register.
specifier|const
name|TargetRegisterClass
operator|*
name|getNewRC
argument_list|()
specifier|const
block|{
return|return
name|newRC_
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Because of the way .a files work, we must force the SimpleRC
end_comment

begin_comment
comment|// implementation to be pulled in if the RegisterCoalescing header is
end_comment

begin_comment
comment|// included.  Otherwise we run the risk of RegisterCoalescing being
end_comment

begin_comment
comment|// used, but the default implementation not being linked into the tool
end_comment

begin_comment
comment|// that uses it.
end_comment

begin_macro
name|FORCE_DEFINING_FILE_TO_BE_LINKED
argument_list|(
argument|RegisterCoalescer
argument_list|)
end_macro

begin_macro
name|FORCE_DEFINING_FILE_TO_BE_LINKED
argument_list|(
argument|SimpleRegisterCoalescing
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

