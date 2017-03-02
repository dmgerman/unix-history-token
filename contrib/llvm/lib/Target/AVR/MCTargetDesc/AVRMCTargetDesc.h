begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRMCTargetDesc.h - AVR Target Descriptions -------------*- C++ -*-===//
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
comment|// This file provides AVR specific target descriptions.
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
name|LLVM_AVR_MCTARGET_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_MCTARGET_DESC_H
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
name|getTheAVRTarget
parameter_list|()
function_decl|;
comment|/// Creates a machine code emitter for AVR.
name|MCCodeEmitter
modifier|*
name|createAVRMCCodeEmitter
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
comment|/// Creates an assembly backend for AVR.
name|MCAsmBackend
modifier|*
name|createAVRAsmBackend
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|Triple
operator|&
name|TT
argument_list|,
name|StringRef
name|CPU
argument_list|,
specifier|const
name|llvm
operator|::
name|MCTargetOptions
operator|&
name|TO
argument_list|)
decl_stmt|;
comment|/// Creates an ELF object writer for AVR.
name|MCObjectWriter
modifier|*
name|createAVRELFObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AVRGenRegisterInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AVRGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AVRGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_MCTARGET_DESC_H
end_comment

end_unit

