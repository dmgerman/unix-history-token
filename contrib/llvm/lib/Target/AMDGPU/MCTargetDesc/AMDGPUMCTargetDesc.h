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
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|MCTargetOptions
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|Target
modifier|&
name|getTheAMDGPUTarget
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getTheGCNTarget
parameter_list|()
function_decl|;
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
name|MCContext
modifier|&
name|Ctx
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
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
specifier|const
name|MCTargetOptions
modifier|&
name|Options
parameter_list|)
function_decl|;
name|MCObjectWriter
modifier|*
name|createAMDGPUELFObjectWriter
parameter_list|(
name|bool
name|Is64Bit
parameter_list|,
name|bool
name|HasRelocationAddend
parameter_list|,
name|raw_pwrite_stream
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

begin_undef
undef|#
directive|undef
name|GET_REGINFO_ENUM
end_undef

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_define
define|#
directive|define
name|GET_INSTRINFO_OPERAND_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenInstrInfo.inc"
end_include

begin_undef
undef|#
directive|undef
name|GET_INSTRINFO_OPERAND_ENUM
end_undef

begin_undef
undef|#
directive|undef
name|GET_INSTRINFO_ENUM
end_undef

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

begin_undef
undef|#
directive|undef
name|GET_SUBTARGETINFO_ENUM
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

