begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXBaseInfo.h - Top-level definitions for NVPTX -------*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the NVPTX target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
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
name|LLVM_LIB_TARGET_NVPTX_MCTARGETDESC_NVPTXBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_MCTARGETDESC_NVPTXBASEINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
enum|enum
name|AddressSpace
block|{
name|ADDRESS_SPACE_GENERIC
init|=
literal|0
block|,
name|ADDRESS_SPACE_GLOBAL
init|=
literal|1
block|,
name|ADDRESS_SPACE_SHARED
init|=
literal|3
block|,
name|ADDRESS_SPACE_CONST
init|=
literal|4
block|,
name|ADDRESS_SPACE_LOCAL
init|=
literal|5
block|,
comment|// NVVM Internal
name|ADDRESS_SPACE_PARAM
init|=
literal|101
block|}
enum|;
name|namespace
name|NVPTXII
block|{
enum|enum
block|{
comment|// These must be kept in sync with TSFlags in NVPTXInstrFormats.td
name|IsTexFlag
init|=
literal|0x80
block|,
name|IsSuldMask
init|=
literal|0x300
block|,
name|IsSuldShift
init|=
literal|8
block|,
name|IsSustFlag
init|=
literal|0x400
block|,
name|IsSurfTexQueryFlag
init|=
literal|0x800
block|,
name|IsTexModeUnifiedFlag
init|=
literal|0x1000
block|}
enum|;
block|}
comment|// namespace NVPTXII
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

