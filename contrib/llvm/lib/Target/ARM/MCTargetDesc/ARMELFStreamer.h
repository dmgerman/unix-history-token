begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMELFStreamer.h - ELF Streamer for ARM ------------*- C++ -*-===//
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
comment|// This file implements ELF streamer information for the ARM backend.
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
name|ARM_ELF_STREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_ELF_STREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|MCELFStreamer
modifier|*
name|createARMELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
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
name|NoExecStack
parameter_list|,
name|bool
name|IsThumb
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ARM_ELF_STREAMER_H
end_comment

end_unit

