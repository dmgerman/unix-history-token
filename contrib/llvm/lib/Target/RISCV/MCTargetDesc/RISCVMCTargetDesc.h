begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RISCVMCTargetDesc.h - RISCV Target Descriptions ---------*- C++ -*-===//
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
comment|// This file provides RISCV specific target descriptions.
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
name|LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVMCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCTargetOptions.h"
end_include

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
name|StringRef
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|Target
modifier|&
name|getTheRISCV32Target
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getTheRISCV64Target
parameter_list|()
function_decl|;
name|MCCodeEmitter
modifier|*
name|createRISCVMCCodeEmitter
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
name|createRISCVAsmBackend
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
name|createRISCVELFObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|,
name|bool
name|Is64Bit
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// Defines symbolic names for RISC-V registers.
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"RISCVGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for RISC-V instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"RISCVGenInstrInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

