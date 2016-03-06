begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineCombinerPattern.h - Instruction pattern supported by
end_comment

begin_comment
comment|// combiner  ------*- C++ -*-===//
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
name|LLVM_CODEGEN_MACHINECOMBINERPATTERN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINECOMBINERPATTERN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// These are instruction patterns matched by the machine combiner pass.
name|enum
name|class
name|MachineCombinerPattern
block|{
comment|// These are commutative variants for reassociating a computation chain. See
comment|// the comments before getMachineCombinerPatterns() in TargetInstrInfo.cpp.
name|REASSOC_AX_BY
operator|,
name|REASSOC_AX_YB
operator|,
name|REASSOC_XA_BY
operator|,
name|REASSOC_XA_YB
operator|,
comment|// These are multiply-add patterns matched by the AArch64 machine combiner.
name|MULADDW_OP1
operator|,
name|MULADDW_OP2
operator|,
name|MULSUBW_OP1
operator|,
name|MULSUBW_OP2
operator|,
name|MULADDWI_OP1
operator|,
name|MULSUBWI_OP1
operator|,
name|MULADDX_OP1
operator|,
name|MULADDX_OP2
operator|,
name|MULSUBX_OP1
operator|,
name|MULSUBX_OP2
operator|,
name|MULADDXI_OP1
operator|,
name|MULSUBXI_OP1
block|}
empty_stmt|;
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

