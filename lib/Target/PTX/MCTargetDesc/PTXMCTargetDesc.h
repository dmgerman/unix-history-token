begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTXMCTargetDesc.h - PTX Target Descriptions ------------*- C++ -*-===//
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
comment|// This file provides PTX specific target descriptions.
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
name|PTXMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|PTXMCTARGETDESC_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
specifier|extern
name|Target
name|ThePTX32Target
decl_stmt|;
specifier|extern
name|Target
name|ThePTX64Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for PTX registers.
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"PTXGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PTX instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"PTXGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"PTXGenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

