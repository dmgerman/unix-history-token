begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64WinCOFFStreamer.h - WinCOFF Streamer for AArch64 -*- C++ -*-===//
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
comment|// This file implements WinCOFF streamer information for the AArch64 backend.
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
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64WINCOFFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64WINCOFFSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"AArch64TargetStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCWinCOFFStreamer.h"
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
name|class
name|AArch64WinCOFFStreamer
decl_stmt|;
name|class
name|AArch64TargetWinCOFFStreamer
range|:
name|public
name|llvm
operator|::
name|AArch64TargetStreamer
block|{
name|private
operator|:
name|AArch64WinCOFFStreamer
operator|&
name|getStreamer
argument_list|()
block|;
name|public
operator|:
name|AArch64TargetWinCOFFStreamer
argument_list|(
name|llvm
operator|::
name|MCStreamer
operator|&
name|S
argument_list|)
operator|:
name|AArch64TargetStreamer
argument_list|(
argument|S
argument_list|)
block|{}
block|}
decl_stmt|;
block|}
end_block

begin_comment
comment|// end anonymous namespace
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|MCWinCOFFStreamer
modifier|*
name|createAArch64WinCOFFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|Emitter
parameter_list|,
name|bool
name|RelaxAll
parameter_list|,
name|bool
name|IncrementalLinkerCompatible
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

