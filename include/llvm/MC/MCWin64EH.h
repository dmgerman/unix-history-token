begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCWin64EH.h - Machine Code Win64 EH support --------------*- C++ -*-===//
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
comment|// This file contains declarations to support the Win64 Exception Handling
end_comment

begin_comment
comment|// scheme in MC.
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
name|LLVM_MC_MCWIN64EH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWIN64EH_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCWinEH.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Win64EH.h"
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
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|namespace
name|Win64EH
block|{
struct|struct
name|Instruction
block|{
specifier|static
name|WinEH
operator|::
name|Instruction
name|PushNonVol
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|unsigned Reg
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|Win64EH
operator|::
name|UOP_PushNonVol
argument_list|,
name|L
argument_list|,
name|Reg
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
specifier|static
name|WinEH
operator|::
name|Instruction
name|Alloc
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|unsigned Size
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|Size
operator|>
literal|128
operator|?
name|UOP_AllocLarge
operator|:
name|UOP_AllocSmall
argument_list|,
name|L
argument_list|,
operator|-
literal|1
argument_list|,
name|Size
argument_list|)
return|;
block|}
specifier|static
name|WinEH
operator|::
name|Instruction
name|PushMachFrame
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|bool Code
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|UOP_PushMachFrame
argument_list|,
name|L
argument_list|,
operator|-
literal|1
argument_list|,
name|Code
operator|?
literal|1
operator|:
literal|0
argument_list|)
return|;
block|}
specifier|static
name|WinEH
operator|::
name|Instruction
name|SaveNonVol
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned Offset
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|Offset
operator|>
literal|512
operator|*
literal|1024
operator|-
literal|8
operator|?
name|UOP_SaveNonVolBig
operator|:
name|UOP_SaveNonVol
argument_list|,
name|L
argument_list|,
name|Reg
argument_list|,
name|Offset
argument_list|)
return|;
block|}
specifier|static
name|WinEH
operator|::
name|Instruction
name|SaveXMM
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned Offset
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|Offset
operator|>
literal|512
operator|*
literal|1024
operator|-
literal|8
operator|?
name|UOP_SaveXMM128Big
operator|:
name|UOP_SaveXMM128
argument_list|,
name|L
argument_list|,
name|Reg
argument_list|,
name|Offset
argument_list|)
return|;
block|}
specifier|static
name|WinEH
operator|::
name|Instruction
name|SetFPReg
argument_list|(
argument|MCSymbol *L
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned Off
argument_list|)
block|{
return|return
name|WinEH
operator|::
name|Instruction
argument_list|(
name|UOP_SetFPReg
argument_list|,
name|L
argument_list|,
name|Reg
argument_list|,
name|Off
argument_list|)
return|;
block|}
block|}
struct|;
name|class
name|UnwindEmitter
range|:
name|public
name|WinEH
operator|::
name|UnwindEmitter
block|{
name|public
operator|:
name|void
name|Emit
argument_list|(
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;
name|void
name|EmitUnwindInfo
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|WinEH::FrameInfo *FI
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

