begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- AArch64MachineFuctionInfo.h - AArch64 machine function info -*- C++ -*-==//
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
comment|// This file declares AArch64-specific per-machine-function information.
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
name|AARCH64MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|AARCH64MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class is derived from MachineFunctionInfo and contains private AArch64
comment|/// target-specific information for each MachineFunction.
name|class
name|AArch64MachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Number of bytes of arguments this function has on the stack. If the callee
comment|/// is expected to restore the argument stack this should be a multiple of 16,
comment|/// all usable during a tail call.
comment|///
comment|/// The alternative would forbid tail call optimisation in some cases: if we
comment|/// want to transfer control from a function with 8-bytes of stack-argument
comment|/// space to a function with 16-bytes then misalignment of this value would
comment|/// make a stack adjustment necessary, which could not be undone by the
comment|/// callee.
name|unsigned
name|BytesInStackArgArea
block|;
comment|/// The number of bytes to restore to deallocate space for incoming
comment|/// arguments. Canonically 0 in the C calling convention, but non-zero when
comment|/// callee is expected to pop the args.
name|unsigned
name|ArgumentStackToRestore
block|;
comment|/// If the stack needs to be adjusted on frame entry in two stages, this
comment|/// records the size of the first adjustment just prior to storing
comment|/// callee-saved registers. The callee-saved slots are addressed assuming
comment|/// SP ==<incoming-SP> - InitialStackAdjust.
name|unsigned
name|InitialStackAdjust
block|;
comment|/// Number of local-dynamic TLS accesses.
name|unsigned
name|NumLocalDynamics
block|;
comment|/// @see AArch64 Procedure Call Standard, B.3
comment|///
comment|/// The Frame index of the area where LowerFormalArguments puts the
comment|/// general-purpose registers that might contain variadic parameters.
name|int
name|VariadicGPRIdx
block|;
comment|/// @see AArch64 Procedure Call Standard, B.3
comment|///
comment|/// The size of the frame object used to store the general-purpose registers
comment|/// which might contain variadic arguments. This is the offset from
comment|/// VariadicGPRIdx to what's stored in __gr_top.
name|unsigned
name|VariadicGPRSize
block|;
comment|/// @see AArch64 Procedure Call Standard, B.3
comment|///
comment|/// The Frame index of the area where LowerFormalArguments puts the
comment|/// floating-point registers that might contain variadic parameters.
name|int
name|VariadicFPRIdx
block|;
comment|/// @see AArch64 Procedure Call Standard, B.3
comment|///
comment|/// The size of the frame object used to store the floating-point registers
comment|/// which might contain variadic arguments. This is the offset from
comment|/// VariadicFPRIdx to what's stored in __vr_top.
name|unsigned
name|VariadicFPRSize
block|;
comment|/// @see AArch64 Procedure Call Standard, B.3
comment|///
comment|/// The Frame index of an object pointing just past the last known stacked
comment|/// argument on entry to a variadic function. This goes into the __stack field
comment|/// of the va_list type.
name|int
name|VariadicStackIdx
block|;
comment|/// The offset of the frame pointer from the stack pointer on function
comment|/// entry. This is expected to be negative.
name|int
name|FramePointerOffset
block|;
name|public
operator|:
name|AArch64MachineFunctionInfo
argument_list|()
operator|:
name|BytesInStackArgArea
argument_list|(
literal|0
argument_list|)
block|,
name|ArgumentStackToRestore
argument_list|(
literal|0
argument_list|)
block|,
name|InitialStackAdjust
argument_list|(
literal|0
argument_list|)
block|,
name|NumLocalDynamics
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicGPRIdx
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicGPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicFPRIdx
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicFPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicStackIdx
argument_list|(
literal|0
argument_list|)
block|,
name|FramePointerOffset
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AArch64MachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|BytesInStackArgArea
argument_list|(
literal|0
argument_list|)
block|,
name|ArgumentStackToRestore
argument_list|(
literal|0
argument_list|)
block|,
name|InitialStackAdjust
argument_list|(
literal|0
argument_list|)
block|,
name|NumLocalDynamics
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicGPRIdx
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicGPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicFPRIdx
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicFPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VariadicStackIdx
argument_list|(
literal|0
argument_list|)
block|,
name|FramePointerOffset
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getBytesInStackArgArea
argument_list|()
specifier|const
block|{
return|return
name|BytesInStackArgArea
return|;
block|}
name|void
name|setBytesInStackArgArea
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|BytesInStackArgArea
operator|=
name|bytes
block|;}
name|unsigned
name|getArgumentStackToRestore
argument_list|()
specifier|const
block|{
return|return
name|ArgumentStackToRestore
return|;
block|}
name|void
name|setArgumentStackToRestore
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|ArgumentStackToRestore
operator|=
name|bytes
block|;   }
name|unsigned
name|getInitialStackAdjust
argument_list|()
specifier|const
block|{
return|return
name|InitialStackAdjust
return|;
block|}
name|void
name|setInitialStackAdjust
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|InitialStackAdjust
operator|=
name|bytes
block|; }
name|unsigned
name|getNumLocalDynamicTLSAccesses
argument_list|()
specifier|const
block|{
return|return
name|NumLocalDynamics
return|;
block|}
name|void
name|incNumLocalDynamicTLSAccesses
argument_list|()
block|{
operator|++
name|NumLocalDynamics
block|; }
name|int
name|getVariadicGPRIdx
argument_list|()
specifier|const
block|{
return|return
name|VariadicGPRIdx
return|;
block|}
name|void
name|setVariadicGPRIdx
argument_list|(
argument|int Idx
argument_list|)
block|{
name|VariadicGPRIdx
operator|=
name|Idx
block|; }
name|unsigned
name|getVariadicGPRSize
argument_list|()
specifier|const
block|{
return|return
name|VariadicGPRSize
return|;
block|}
name|void
name|setVariadicGPRSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|VariadicGPRSize
operator|=
name|Size
block|; }
name|int
name|getVariadicFPRIdx
argument_list|()
specifier|const
block|{
return|return
name|VariadicFPRIdx
return|;
block|}
name|void
name|setVariadicFPRIdx
argument_list|(
argument|int Idx
argument_list|)
block|{
name|VariadicFPRIdx
operator|=
name|Idx
block|; }
name|unsigned
name|getVariadicFPRSize
argument_list|()
specifier|const
block|{
return|return
name|VariadicFPRSize
return|;
block|}
name|void
name|setVariadicFPRSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|VariadicFPRSize
operator|=
name|Size
block|; }
name|int
name|getVariadicStackIdx
argument_list|()
specifier|const
block|{
return|return
name|VariadicStackIdx
return|;
block|}
name|void
name|setVariadicStackIdx
argument_list|(
argument|int Idx
argument_list|)
block|{
name|VariadicStackIdx
operator|=
name|Idx
block|; }
name|int
name|getFramePointerOffset
argument_list|()
specifier|const
block|{
return|return
name|FramePointerOffset
return|;
block|}
name|void
name|setFramePointerOffset
argument_list|(
argument|int Idx
argument_list|)
block|{
name|FramePointerOffset
operator|=
name|Idx
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

