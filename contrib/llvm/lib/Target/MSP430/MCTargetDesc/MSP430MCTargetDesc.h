begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MSP430MCTargetDesc.h - MSP430 Target Descriptions -------*- C++ -*-===//
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
comment|// This file provides MSP430 specific target descriptions.
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
name|LLVM_LIB_TARGET_MSP430_MCTARGETDESC_MSP430MCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MSP430_MCTARGETDESC_MSP430MCTARGETDESC_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
specifier|extern
name|Target
name|TheMSP430Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for MSP430 registers.
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
file|"MSP430GenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the MSP430 instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"MSP430GenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"MSP430GenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

