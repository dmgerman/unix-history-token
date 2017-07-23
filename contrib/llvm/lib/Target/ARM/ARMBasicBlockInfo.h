begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMBasicBlockInfo.h - Basic Block Information -----------*- C++ -*-===//
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
comment|// Utility functions and data structure for computing block size.
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
name|LLVM_LIB_TARGET_ARM_ARMBASICBLOCKINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMBASICBLOCKINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// UnknownPadding - Return the worst case padding that could result from
comment|/// unknown offset bits.  This does not include alignment padding caused by
comment|/// known offset bits.
comment|///
comment|/// @param LogAlign log2(alignment)
comment|/// @param KnownBits Number of known low offset bits.
specifier|inline
name|unsigned
name|UnknownPadding
parameter_list|(
name|unsigned
name|LogAlign
parameter_list|,
name|unsigned
name|KnownBits
parameter_list|)
block|{
if|if
condition|(
name|KnownBits
operator|<
name|LogAlign
condition|)
return|return
operator|(
literal|1u
operator|<<
name|LogAlign
operator|)
operator|-
operator|(
literal|1u
operator|<<
name|KnownBits
operator|)
return|;
return|return
literal|0
return|;
block|}
comment|/// BasicBlockInfo - Information about the offset and size of a single
comment|/// basic block.
struct|struct
name|BasicBlockInfo
block|{
comment|/// Offset - Distance from the beginning of the function to the beginning
comment|/// of this basic block.
comment|///
comment|/// Offsets are computed assuming worst case padding before an aligned
comment|/// block. This means that subtracting basic block offsets always gives a
comment|/// conservative estimate of the real distance which may be smaller.
comment|///
comment|/// Because worst case padding is used, the computed offset of an aligned
comment|/// block may not actually be aligned.
name|unsigned
name|Offset
init|=
literal|0
decl_stmt|;
comment|/// Size - Size of the basic block in bytes.  If the block contains
comment|/// inline assembly, this is a worst case estimate.
comment|///
comment|/// The size does not include any alignment padding whether from the
comment|/// beginning of the block, or from an aligned jump table at the end.
name|unsigned
name|Size
init|=
literal|0
decl_stmt|;
comment|/// KnownBits - The number of low bits in Offset that are known to be
comment|/// exact.  The remaining bits of Offset are an upper bound.
name|uint8_t
name|KnownBits
init|=
literal|0
decl_stmt|;
comment|/// Unalign - When non-zero, the block contains instructions (inline asm)
comment|/// of unknown size.  The real size may be smaller than Size bytes by a
comment|/// multiple of 1<< Unalign.
name|uint8_t
name|Unalign
init|=
literal|0
decl_stmt|;
comment|/// PostAlign - When non-zero, the block terminator contains a .align
comment|/// directive, so the end of the block is aligned to 1<< PostAlign
comment|/// bytes.
name|uint8_t
name|PostAlign
init|=
literal|0
decl_stmt|;
name|BasicBlockInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Compute the number of known offset bits internally to this block.
comment|/// This number should be used to predict worst case padding when
comment|/// splitting the block.
name|unsigned
name|internalKnownBits
argument_list|()
specifier|const
block|{
name|unsigned
name|Bits
operator|=
name|Unalign
operator|?
name|Unalign
operator|:
name|KnownBits
block|;
comment|// If the block size isn't a multiple of the known bits, assume the
comment|// worst case padding.
if|if
condition|(
name|Size
operator|&
operator|(
operator|(
literal|1u
operator|<<
name|Bits
operator|)
operator|-
literal|1
operator|)
condition|)
name|Bits
operator|=
name|countTrailingZeros
argument_list|(
name|Size
argument_list|)
expr_stmt|;
return|return
name|Bits
return|;
block|}
comment|/// Compute the offset immediately following this block.  If LogAlign is
comment|/// specified, return the offset the successor block will get if it has
comment|/// this alignment.
name|unsigned
name|postOffset
argument_list|(
name|unsigned
name|LogAlign
operator|=
literal|0
argument_list|)
decl|const
block|{
name|unsigned
name|PO
init|=
name|Offset
operator|+
name|Size
decl_stmt|;
name|unsigned
name|LA
init|=
name|std
operator|::
name|max
argument_list|(
name|unsigned
argument_list|(
name|PostAlign
argument_list|)
argument_list|,
name|LogAlign
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|LA
condition|)
return|return
name|PO
return|;
comment|// Add alignment padding from the terminator.
return|return
name|PO
operator|+
name|UnknownPadding
argument_list|(
name|LA
argument_list|,
name|internalKnownBits
argument_list|()
argument_list|)
return|;
block|}
comment|/// Compute the number of known low bits of postOffset.  If this block
comment|/// contains inline asm, the number of known bits drops to the
comment|/// instruction alignment.  An aligned terminator may increase the number
comment|/// of know bits.
comment|/// If LogAlign is given, also consider the alignment of the next block.
name|unsigned
name|postKnownBits
argument_list|(
name|unsigned
name|LogAlign
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|std
operator|::
name|max
argument_list|(
name|unsigned
argument_list|(
name|PostAlign
argument_list|)
argument_list|,
name|LogAlign
argument_list|)
argument_list|,
name|internalKnownBits
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARMBASICBLOCKINFO_H
end_comment

end_unit

