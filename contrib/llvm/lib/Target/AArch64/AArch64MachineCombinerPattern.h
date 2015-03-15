begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64MachineCombinerPattern.h                                    -===//
end_comment

begin_comment
comment|//===- AArch64 instruction pattern supported by combiner                  -===//
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
comment|// This file defines instruction pattern supported by combiner
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
name|LLVM_LIB_TARGET_AARCH64_AARCH64MACHINECOMBINERPATTERN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64MACHINECOMBINERPATTERN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Enumeration of instruction pattern supported by machine combiner
comment|///
comment|///
name|namespace
name|MachineCombinerPattern
block|{
enum|enum
name|MC_PATTERN
enum|:
name|int
block|{
name|MC_NONE
init|=
literal|0
block|,
name|MC_MULADDW_OP1
init|=
literal|1
block|,
name|MC_MULADDW_OP2
init|=
literal|2
block|,
name|MC_MULSUBW_OP1
init|=
literal|3
block|,
name|MC_MULSUBW_OP2
init|=
literal|4
block|,
name|MC_MULADDWI_OP1
init|=
literal|5
block|,
name|MC_MULSUBWI_OP1
init|=
literal|6
block|,
name|MC_MULADDX_OP1
init|=
literal|7
block|,
name|MC_MULADDX_OP2
init|=
literal|8
block|,
name|MC_MULSUBX_OP1
init|=
literal|9
block|,
name|MC_MULSUBX_OP2
init|=
literal|10
block|,
name|MC_MULADDXI_OP1
init|=
literal|11
block|,
name|MC_MULSUBXI_OP1
init|=
literal|12
block|}
enum|;
block|}
comment|// end namespace MachineCombinerPattern
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

