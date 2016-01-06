begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86ShuffleDecodeConstantPool.h - X86 shuffle decode -----*-C++-*---===//
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
comment|// Define several functions to decode x86 specific shuffle semantics using
end_comment

begin_comment
comment|// constants from the constant pool.
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
name|LLVM_LIB_TARGET_X86_X86SHUFFLEDECODECONSTANTPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86SHUFFLEDECODECONSTANTPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//  Vector Mask Decoding
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|MVT
decl_stmt|;
comment|/// \brief Decode a PSHUFB mask from an IR-level vector constant.
name|void
name|DecodePSHUFBMask
argument_list|(
specifier|const
name|Constant
operator|*
name|C
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// \brief Decode a VPERMILP variable mask from an IR-level vector constant.
name|void
name|DecodeVPERMILPMask
argument_list|(
specifier|const
name|Constant
operator|*
name|C
argument_list|,
name|unsigned
name|ElSize
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// \brief Decode a VPERM W/D/Q/PS/PD mask from an IR-level vector constant.
name|void
name|DecodeVPERMVMask
argument_list|(
specifier|const
name|Constant
operator|*
name|C
argument_list|,
name|MVT
name|VT
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// \brief Decode a VPERMT2 W/D/Q/PS/PD mask from an IR-level vector constant.
name|void
name|DecodeVPERMV3Mask
argument_list|(
specifier|const
name|Constant
operator|*
name|C
argument_list|,
name|MVT
name|VT
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

