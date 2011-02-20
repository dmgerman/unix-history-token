begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- BlackfinFrameLowering.h - Define frame lowering for Blackfin -*- C++ -*-=//
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
name|ALPHA_FRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHA_FRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"Blackfin.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinSubtarget.h"
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
name|BlackfinSubtarget
decl_stmt|;
name|class
name|BlackfinFrameLowering
range|:
name|public
name|TargetFrameLowering
block|{
name|protected
operator|:
specifier|const
name|BlackfinSubtarget
operator|&
name|STI
block|;
name|public
operator|:
name|explicit
name|BlackfinFrameLowering
argument_list|(
specifier|const
name|BlackfinSubtarget
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
literal|4
argument_list|,
literal|0
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
block|;
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

