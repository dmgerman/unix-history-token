begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64MCTargetDesc.h - AArch64 Target Descriptions -----*- C++ -*-===//
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
comment|// This file provides AArch64 specific target descriptions.
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
name|AArch64MCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|AArch64MCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCObjectWriter
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
name|raw_ostream
decl_stmt|;
specifier|extern
name|Target
name|TheAArch64leTarget
decl_stmt|;
specifier|extern
name|Target
name|TheAArch64beTarget
decl_stmt|;
specifier|extern
name|Target
name|TheARM64leTarget
decl_stmt|;
specifier|extern
name|Target
name|TheARM64beTarget
decl_stmt|;
name|MCCodeEmitter
modifier|*
name|createAArch64MCCodeEmitter
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
name|createAArch64leAsmBackend
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
name|MCAsmBackend
modifier|*
name|createAArch64beAsmBackend
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
name|createAArch64ELFObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|)
function_decl|;
name|MCObjectWriter
modifier|*
name|createAArch64MachObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|uint32_t
name|CPUType
parameter_list|,
name|uint32_t
name|CPUSubtype
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for AArch64 registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AArch64GenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the AArch64 instructions.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AArch64GenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"AArch64GenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

