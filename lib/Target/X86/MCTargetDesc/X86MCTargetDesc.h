begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86MCTargetDesc.h - X86 Target Descriptions -------------*- C++ -*-===//
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
comment|// This file provides X86 specific target descriptions.
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
name|X86MCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|X86MCTARGETDESC_H
end_define

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
name|TheX86_32Target
decl_stmt|,
name|TheX86_64Target
decl_stmt|;
name|namespace
name|X86_MC
block|{
name|std
operator|::
name|string
name|ParseX86Triple
argument_list|(
argument|StringRef TT
argument_list|)
expr_stmt|;
comment|/// GetCpuIDAndInfo - Execute the specified cpuid and return the 4 values in
comment|/// the specified arguments.  If we can't run cpuid on the host, return true.
name|bool
name|GetCpuIDAndInfo
parameter_list|(
name|unsigned
name|value
parameter_list|,
name|unsigned
modifier|*
name|rEAX
parameter_list|,
name|unsigned
modifier|*
name|rEBX
parameter_list|,
name|unsigned
modifier|*
name|rECX
parameter_list|,
name|unsigned
modifier|*
name|rEDX
parameter_list|)
function_decl|;
name|void
name|DetectFamilyModel
parameter_list|(
name|unsigned
name|EAX
parameter_list|,
name|unsigned
modifier|&
name|Family
parameter_list|,
name|unsigned
modifier|&
name|Model
parameter_list|)
function_decl|;
comment|/// createARMMCSubtargetInfo - Create a X86 MCSubtargetInfo instance.
comment|/// This is exposed so Asm parser, etc. do not need to go through
comment|/// TargetRegistry.
name|MCSubtargetInfo
modifier|*
name|createX86MCSubtargetInfo
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|FS
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for X86 registers.  This defines a mapping from
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
file|"X86GenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the X86 instructions.
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
file|"X86GenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"X86GenSubtargetInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

