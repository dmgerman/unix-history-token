begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUMCTargetDesc.h - AMDGPU Target Descriptions -----*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Provides AMDGPU specific target descriptions.
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUMCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
specifier|extern
name|Target
name|TheAMDGPUTarget
decl_stmt|;
specifier|extern
name|Target
name|TheGCNTarget
decl_stmt|;
name|MCCodeEmitter
modifier|*
name|createR600MCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|MCCodeEmitter
modifier|*
name|createSIMCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCAsmBackend
modifier|*
name|createAMDGPUAsmBackend
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
name|MCObjectWriter
modifier|*
name|createAMDGPUELFObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenRegisterInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

