begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- AMDGPUELFStreamer.h - ELF Object Output ---------------------===//
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
comment|// This is a custom MCELFStreamer which allows us to insert some hooks before
end_comment

begin_comment
comment|// emitting data into an actual object file.
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
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUELFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUELFSTREAMER_H
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
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|AMDGPUELFStreamer
range|:
name|public
name|MCELFStreamer
block|{
name|public
operator|:
name|AMDGPUELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|MAB
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|)
operator|:
name|MCELFStreamer
argument_list|(
argument|Context
argument_list|,
argument|MAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|)
block|{ }
name|virtual
name|void
name|InitSections
argument_list|(
argument|bool NoExecStac
argument_list|)
name|override
block|; }
decl_stmt|;
name|MCELFStreamer
modifier|*
name|createAMDGPUELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|MAB
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
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

