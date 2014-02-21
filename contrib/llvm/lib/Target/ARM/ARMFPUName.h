begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMFPUName.h - List of the ARM FPU names ----------------*- C++ -*-===//
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
name|ARMFPUNAME_H
end_ifndef

begin_define
define|#
directive|define
name|ARMFPUNAME_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
enum|enum
name|FPUKind
block|{
name|INVALID_FPU
init|=
literal|0
define|#
directive|define
name|ARM_FPU_NAME
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
value|, ID
include|#
directive|include
file|"ARMFPUName.def"
block|}
enum|;
block|}
comment|// namespace ARM
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ARMFPUNAME_H
end_comment

end_unit

