begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/Target/TargetSubtarget.h - Target Information --------*- C++ -*-==//
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
comment|// This file describes the subtarget options of a Target machine.
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
name|LLVM_TARGET_TARGETSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSUBTARGET_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SDep
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// TargetSubtarget - Generic base class for all target subtargets.  All
comment|/// Target-specific options that control code generation and printing should
comment|/// be exposed through a TargetSubtarget-derived class.
comment|///
name|class
name|TargetSubtarget
block|{
name|TargetSubtarget
argument_list|(
specifier|const
name|TargetSubtarget
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetSubtarget
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses...
name|TargetSubtarget
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|TargetSubtarget
argument_list|()
expr_stmt|;
comment|/// getSpecialAddressLatency - For targets where it is beneficial to
comment|/// backschedule instructions that compute addresses, return a value
comment|/// indicating the number of scheduling cycles of backscheduling that
comment|/// should be attempted.
name|virtual
name|unsigned
name|getSpecialAddressLatency
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|// enablePostRAScheduler - Return true to enable
comment|// post-register-allocation scheduling.
name|virtual
name|bool
name|enablePostRAScheduler
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// adjustSchedDependency - Perform target specific adjustments to
comment|// the latency of a schedule dependency.
name|virtual
name|void
name|adjustSchedDependency
argument_list|(
name|SUnit
operator|*
name|def
argument_list|,
name|SUnit
operator|*
name|use
argument_list|,
name|SDep
operator|&
name|dep
argument_list|)
decl|const
block|{ }
block|}
empty_stmt|;
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

