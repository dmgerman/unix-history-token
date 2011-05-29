begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PTXFrameLowering.h - Define frame lowering for PTX --*- C++ -*----===//
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
comment|//
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
name|PTX_FRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_FRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"PTX.h"
end_include

begin_include
include|#
directive|include
file|"PTXSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PTXSubtarget
decl_stmt|;
name|class
name|PTXFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|protected
operator|:
specifier|const
name|PTXSubtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|PTXFrameLowering
argument_list|(
specifier|const
name|PTXSubtarget
operator|&
name|sti
argument_list|)
operator|:
name|TargetFrameLowering
argument_list|(
name|TargetFrameLowering
operator|::
name|StackGrowsDown
argument_list|,
literal|2
argument_list|,
operator|-
literal|2
argument_list|)
block|,
name|STI
argument_list|(
argument|sti
argument_list|)
block|{   }
comment|/// emitProlog/emitEpilog - These methods insert prolog and epilog code into
comment|/// the function.
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
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

