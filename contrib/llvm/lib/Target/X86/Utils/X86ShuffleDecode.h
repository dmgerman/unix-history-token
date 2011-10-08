begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86ShuffleDecode.h - X86 shuffle decode logic -----------*-C++-*---===//
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
comment|// Define several functions to decode x86 specific shuffle semantics into a
end_comment

begin_comment
comment|// generic vector mask.
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
name|X86_SHUFFLE_DECODE_H
end_ifndef

begin_define
define|#
directive|define
name|X86_SHUFFLE_DECODE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
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
enum|enum
block|{
name|SM_SentinelZero
init|=
operator|~
literal|0U
block|}
enum|;
name|void
name|DecodeINSERTPSMask
argument_list|(
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|//<3,1> or<6,7,2,3>
name|void
name|DecodeMOVHLPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|//<0,2> or<0,1,4,5>
name|void
name|DecodeMOVLHPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePSHUFMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePSHUFHWMask
argument_list|(
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePSHUFLWMask
argument_list|(
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKLBWMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKLWDMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKLDQMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKLQDQMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKLMask
argument_list|(
name|EVT
name|VT
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePUNPCKHMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeSHUFPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeUNPCKHPMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeUNPCKLPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeUNPCKLPDMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// DecodeUNPCKLPMask - This decodes the shuffle masks for unpcklps/unpcklpd
comment|/// etc.  VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodeUNPCKLPMask
argument_list|(
name|EVT
name|VT
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
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

