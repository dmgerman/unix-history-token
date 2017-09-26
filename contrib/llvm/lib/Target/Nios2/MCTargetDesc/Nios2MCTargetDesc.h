begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Nios2MCTargetDesc.h - Nios2 Target Descriptions ---------*- C++ -*-===//
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
comment|// This file provides Nios2 specific target descriptions.
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
name|LLVM_LIB_TARGET_NIOS2_MCTARGETDESC_NIOS2MCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NIOS2_MCTARGETDESC_NIOS2MCTARGETDESC_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|Target
modifier|&
name|getTheNios2Target
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_comment
comment|// Defines symbolic names for Nios2 registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"Nios2GenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Nios2 instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"Nios2GenInstrInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

