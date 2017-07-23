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
name|LLVM_LIB_TARGET_X86_UTILS_X86SHUFFLEDECODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_UTILS_X86SHUFFLEDECODE_H
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|MVT
decl_stmt|;
enum|enum
block|{
name|SM_SentinelUndef
init|=
operator|-
literal|1
block|,
name|SM_SentinelZero
init|=
operator|-
literal|2
block|}
enum|;
comment|/// Decode a 128-bit INSERTPS instruction as a v4f32 shuffle mask.
name|void
name|DecodeINSERTPSMask
argument_list|(
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|// Insert the bottom Len elements from a second source into a vector starting at
comment|// element Idx.
name|void
name|DecodeInsertElementMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Idx
argument_list|,
name|unsigned
name|Len
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a MOVHLPS instruction as a v2f64/v4f32 shuffle mask.
comment|/// i.e.<3,1> or<6,7,2,3>
name|void
name|DecodeMOVHLPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a MOVLHPS instruction as a v2f64/v4f32 shuffle mask.
comment|/// i.e.<0,2> or<0,1,4,5>
name|void
name|DecodeMOVLHPSMask
argument_list|(
name|unsigned
name|NElts
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeMOVSLDUPMask
argument_list|(
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
name|void
name|DecodeMOVSHDUPMask
argument_list|(
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
name|void
name|DecodeMOVDDUPMask
argument_list|(
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
name|void
name|DecodePSLLDQMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePSRLDQMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodePALIGNRMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeVALIGNMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes the shuffle masks for pshufd/pshufw/vpermilpd/vpermilps.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodePSHUFMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes the shuffle masks for pshufhw.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodePSHUFHWMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes the shuffle masks for pshuflw.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodePSHUFLWMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes a PSWAPD 3DNow! instruction.
name|void
name|DecodePSWAPMask
argument_list|(
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
comment|/// Decodes the shuffle masks for shufp*.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodeSHUFPMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes the shuffle masks for unpckhps/unpckhpd and punpckh*.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodeUNPCKHMask
argument_list|(
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
comment|/// Decodes the shuffle masks for unpcklps/unpcklpd and punpckl*.
comment|/// VT indicates the type of the vector allowing it to handle different
comment|/// datatypes and vector widths.
name|void
name|DecodeUNPCKLMask
argument_list|(
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
comment|/// Decodes a broadcast of the first element of a vector.
name|void
name|DecodeVectorBroadcast
argument_list|(
name|MVT
name|DstVT
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes a broadcast of a subvector to a larger vector type.
name|void
name|DecodeSubVectorBroadcast
argument_list|(
name|MVT
name|DstVT
argument_list|,
name|MVT
name|SrcVT
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a PSHUFB mask from a raw array of constants such as from
comment|/// BUILD_VECTOR.
name|void
name|DecodePSHUFBMask
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a BLEND immediate mask into a shuffle mask.
name|void
name|DecodeBLENDMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
name|void
name|DecodeVPERM2X128Mask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a shuffle packed values at 128-bit granularity
comment|/// immediate mask into a shuffle mask.
name|void
name|decodeVSHUF64x2FamilyMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decodes the shuffle masks for VPERMQ/VPERMPD.
name|void
name|DecodeVPERMMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|Imm
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a VPPERM mask from a raw array of constants such as from
comment|/// BUILD_VECTOR.
comment|/// This can only basic masks (permutes + zeros), not any of the other
comment|/// operations that VPPERM can perform.
name|void
name|DecodeVPPERMMask
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a zero extension instruction as a shuffle mask.
name|void
name|DecodeZeroExtendMask
argument_list|(
name|MVT
name|SrcScalarVT
argument_list|,
name|MVT
name|DstVT
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a move lower and zero upper instruction as a shuffle mask.
name|void
name|DecodeZeroMoveLowMask
argument_list|(
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
comment|/// Decode a scalar float move instruction as a shuffle mask.
name|void
name|DecodeScalarMoveMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|bool
name|IsLoad
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a SSE4A EXTRQ instruction as a shuffle mask.
name|void
name|DecodeEXTRQIMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|int
name|Len
argument_list|,
name|int
name|Idx
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a SSE4A INSERTQ instruction as a shuffle mask.
name|void
name|DecodeINSERTQIMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|int
name|Len
argument_list|,
name|int
name|Idx
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a VPERMILPD/VPERMILPS variable mask from a raw array of constants.
name|void
name|DecodeVPERMILPMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a VPERMIL2PD/VPERMIL2PS variable mask from a raw array of constants.
name|void
name|DecodeVPERMIL2PMask
argument_list|(
name|MVT
name|VT
argument_list|,
name|unsigned
name|M2Z
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a VPERM W/D/Q/PS/PD mask from a raw array of constants.
name|void
name|DecodeVPERMVMask
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|ShuffleMask
argument_list|)
decl_stmt|;
comment|/// Decode a VPERMT2 W/D/Q/PS/PD mask from a raw array of constants.
name|void
name|DecodeVPERMV3Mask
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|RawMask
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

