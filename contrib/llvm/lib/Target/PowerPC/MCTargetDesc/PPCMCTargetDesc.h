begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCMCTargetDesc.h - PowerPC Target Descriptions ---------*- C++ -*-===//
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
comment|// This file provides PowerPC specific target descriptions.
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
name|LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCMCTARGETDESC_H
end_define

begin_comment
comment|// GCC #defines PPC on Linux but we use it as our namespace name
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|Target
modifier|&
name|getThePPC32Target
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getThePPC64Target
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getThePPC64LETarget
parameter_list|()
function_decl|;
name|MCCodeEmitter
modifier|*
name|createPPCMCCodeEmitter
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
name|createPPCAsmBackend
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
comment|/// Construct an PPC ELF object writer.
name|MCObjectWriter
modifier|*
name|createPPCELFObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|)
function_decl|;
comment|/// Construct a PPC Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createPPCMachObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|uint32_t
name|CPUType
parameter_list|,
name|uint32_t
name|CPUSubtype
parameter_list|)
function_decl|;
comment|/// Returns true iff Val consists of one contiguous run of 1s with any number of
comment|/// 0s on either side.  The 1s are allowed to wrap from LSB to MSB, so
comment|/// 0x000FFF0, 0x0000FFFF, and 0xFF0000FF are all runs.  0x0F0F0000 is not,
comment|/// since all 1s are not contiguous.
specifier|static
specifier|inline
name|bool
name|isRunOfOnes
parameter_list|(
name|unsigned
name|Val
parameter_list|,
name|unsigned
modifier|&
name|MB
parameter_list|,
name|unsigned
modifier|&
name|ME
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Val
condition|)
return|return
name|false
return|;
if|if
condition|(
name|isShiftedMask_32
argument_list|(
name|Val
argument_list|)
condition|)
block|{
comment|// look for the first non-zero bit
name|MB
operator|=
name|countLeadingZeros
argument_list|(
name|Val
argument_list|)
expr_stmt|;
comment|// look for the first zero bit after the run of ones
name|ME
operator|=
name|countLeadingZeros
argument_list|(
operator|(
name|Val
operator|-
literal|1
operator|)
operator|^
name|Val
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
else|else
block|{
name|Val
operator|=
operator|~
name|Val
expr_stmt|;
comment|// invert mask
if|if
condition|(
name|isShiftedMask_32
argument_list|(
name|Val
argument_list|)
condition|)
block|{
comment|// effectively look for the first zero bit
name|ME
operator|=
name|countLeadingZeros
argument_list|(
name|Val
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|// effectively look for the first one bit after the run of zeros
name|MB
operator|=
name|countLeadingZeros
argument_list|(
operator|(
name|Val
operator|-
literal|1
operator|)
operator|^
name|Val
argument_list|)
operator|+
literal|1
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
comment|// no run present
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_comment
comment|// Generated files will use "namespace PPC". To avoid symbol clash,
end_comment

begin_comment
comment|// undefine PPC here. PPC may be predefined on some hosts.
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_comment
comment|// Defines symbolic names for PowerPC registers.  This defines a mapping from
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
file|"PPCGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PowerPC instructions.
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
file|"PPCGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"PPCGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCMCTARGETDESC_H
end_comment

end_unit

