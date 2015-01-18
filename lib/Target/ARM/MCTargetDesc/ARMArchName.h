begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMArchName.h - List of the ARM arch names --------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMARCHNAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMARCHNAME_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
enum|enum
name|ArchKind
block|{
name|INVALID_ARCH
init|=
literal|0
define|#
directive|define
name|ARM_ARCH_NAME
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|DEFAULT_CPU_NAME
parameter_list|,
name|DEFAULT_CPU_ARCH
parameter_list|)
value|, ID
define|#
directive|define
name|ARM_ARCH_ALIAS
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
comment|/* empty */
include|#
directive|include
file|"ARMArchName.def"
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

end_unit

