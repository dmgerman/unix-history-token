begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZMCTargetDesc.h - SystemZ target descriptions -----*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZMCTARGETDESC_H
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
name|class
name|raw_ostream
decl_stmt|;
name|Target
modifier|&
name|getTheSystemZTarget
parameter_list|()
function_decl|;
name|namespace
name|SystemZMC
block|{
comment|// How many bytes are in the ABI-defined, caller-allocated part of
comment|// a stack frame.
specifier|const
name|int64_t
name|CallFrameSize
init|=
literal|160
decl_stmt|;
comment|// The offset of the DWARF CFA from the incoming stack pointer.
specifier|const
name|int64_t
name|CFAOffsetFromInitialSP
init|=
name|CallFrameSize
decl_stmt|;
comment|// Maps of asm register numbers to LLVM register numbers, with 0 indicating
comment|// an invalid register.  In principle we could use 32-bit and 64-bit register
comment|// classes directly, provided that we relegated the GPR allocation order
comment|// in SystemZRegisterInfo.td to an AltOrder and left the default order
comment|// as %r0-%r15.  It seems better to provide the same interface for
comment|// all classes though.
specifier|extern
specifier|const
name|unsigned
name|GR32Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|GRH32Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|GR64Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|GR128Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|FP32Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|FP64Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|FP128Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|VR32Regs
index|[
literal|32
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|VR64Regs
index|[
literal|32
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|VR128Regs
index|[
literal|32
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|AR32Regs
index|[
literal|16
index|]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|CR64Regs
index|[
literal|16
index|]
decl_stmt|;
comment|// Return the 0-based number of the first architectural register that
comment|// contains the given LLVM register.   E.g. R1D -> 1.
name|unsigned
name|getFirstReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|// Return the given register as a GR64.
specifier|inline
name|unsigned
name|getRegAsGR64
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
return|return
name|GR64Regs
index|[
name|getFirstReg
argument_list|(
name|Reg
argument_list|)
index|]
return|;
block|}
comment|// Return the given register as a low GR32.
specifier|inline
name|unsigned
name|getRegAsGR32
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
return|return
name|GR32Regs
index|[
name|getFirstReg
argument_list|(
name|Reg
argument_list|)
index|]
return|;
block|}
comment|// Return the given register as a high GR32.
specifier|inline
name|unsigned
name|getRegAsGRH32
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
return|return
name|GRH32Regs
index|[
name|getFirstReg
argument_list|(
name|Reg
argument_list|)
index|]
return|;
block|}
comment|// Return the given register as a VR128.
specifier|inline
name|unsigned
name|getRegAsVR128
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
return|return
name|VR128Regs
index|[
name|getFirstReg
argument_list|(
name|Reg
argument_list|)
index|]
return|;
block|}
block|}
comment|// end namespace SystemZMC
name|MCCodeEmitter
modifier|*
name|createSystemZMCCodeEmitter
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
name|createSystemZMCAsmBackend
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
name|createSystemZObjectWriter
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

begin_comment
comment|// Defines symbolic names for SystemZ registers.
end_comment

begin_comment
comment|// This defines a mapping from register name to register number.
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"SystemZGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the SystemZ instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"SystemZGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"SystemZGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

