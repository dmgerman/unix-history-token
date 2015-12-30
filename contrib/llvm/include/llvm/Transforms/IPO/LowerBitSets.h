begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LowerBitSets.h - Bitset lowering pass --------------------*- C++ -*-===//
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
comment|// This file defines parts of the bitset lowering pass implementation that may
end_comment

begin_comment
comment|// be usefully unit tested.
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
name|LLVM_TRANSFORMS_IPO_LOWERBITSETS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_LOWERBITSETS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|GlobalObject
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
struct|struct
name|BitSetInfo
block|{
comment|// The indices of the set bits in the bitset.
name|std
operator|::
name|set
operator|<
name|uint64_t
operator|>
name|Bits
expr_stmt|;
comment|// The byte offset into the combined global represented by the bitset.
name|uint64_t
name|ByteOffset
decl_stmt|;
comment|// The size of the bitset in bits.
name|uint64_t
name|BitSize
decl_stmt|;
comment|// Log2 alignment of the bit set relative to the combined global.
comment|// For example, a log2 alignment of 3 means that bits in the bitset
comment|// represent addresses 8 bytes apart.
name|unsigned
name|AlignLog2
decl_stmt|;
name|bool
name|isSingleOffset
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
name|bool
name|isAllOnes
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|.
name|size
argument_list|()
operator|==
name|BitSize
return|;
block|}
name|bool
name|containsGlobalOffset
argument_list|(
name|uint64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|bool
name|containsValue
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|DenseMap
operator|<
name|GlobalObject
operator|*
argument_list|,
name|uint64_t
operator|>
operator|&
name|GlobalLayout
argument_list|,
name|Value
operator|*
name|V
argument_list|,
name|uint64_t
name|COffset
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
struct|struct
name|BitSetBuilder
block|{
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|Offsets
expr_stmt|;
name|uint64_t
name|Min
decl_stmt|,
name|Max
decl_stmt|;
name|BitSetBuilder
argument_list|()
operator|:
name|Min
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|uint64_t
operator|>
operator|::
name|max
argument_list|()
argument_list|)
operator|,
name|Max
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|addOffset
argument_list|(
argument|uint64_t Offset
argument_list|)
block|{
if|if
condition|(
name|Min
operator|>
name|Offset
condition|)
name|Min
operator|=
name|Offset
expr_stmt|;
if|if
condition|(
name|Max
operator|<
name|Offset
condition|)
name|Max
operator|=
name|Offset
expr_stmt|;
name|Offsets
operator|.
name|push_back
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
block|}
name|BitSetInfo
name|build
argument_list|()
struct|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// This class implements a layout algorithm for globals referenced by bit sets
end_comment

begin_comment
comment|/// that tries to keep members of small bit sets together. This can
end_comment

begin_comment
comment|/// significantly reduce bit set sizes in many cases.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It works by assembling fragments of layout from sets of referenced globals.
end_comment

begin_comment
comment|/// Each set of referenced globals causes the algorithm to create a new
end_comment

begin_comment
comment|/// fragment, which is assembled by appending each referenced global in the set
end_comment

begin_comment
comment|/// into the fragment. If a referenced global has already been referenced by an
end_comment

begin_comment
comment|/// fragment created earlier, we instead delete that fragment and append its
end_comment

begin_comment
comment|/// contents into the fragment we are assembling.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By starting with the smallest fragments, we minimize the size of the
end_comment

begin_comment
comment|/// fragments that are copied into larger fragments. This is most intuitively
end_comment

begin_comment
comment|/// thought about when considering the case where the globals are virtual tables
end_comment

begin_comment
comment|/// and the bit sets represent their derived classes: in a single inheritance
end_comment

begin_comment
comment|/// hierarchy, the optimum layout would involve a depth-first search of the
end_comment

begin_comment
comment|/// class hierarchy (and in fact the computed layout ends up looking a lot like
end_comment

begin_comment
comment|/// a DFS), but a naive DFS would not work well in the presence of multiple
end_comment

begin_comment
comment|/// inheritance. This aspect of the algorithm ends up fitting smaller
end_comment

begin_comment
comment|/// hierarchies inside larger ones where that would be beneficial.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, consider this class hierarchy:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A       B
end_comment

begin_comment
comment|///   \   / | \
end_comment

begin_comment
comment|///     C   D   E
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We have five bit sets: bsA (A, C), bsB (B, C, D, E), bsC (C), bsD (D) and
end_comment

begin_comment
comment|/// bsE (E). If we laid out our objects by DFS traversing B followed by A, our
end_comment

begin_comment
comment|/// layout would be {B, C, D, E, A}. This is optimal for bsB as it needs to
end_comment

begin_comment
comment|/// cover the only 4 objects in its hierarchy, but not for bsA as it needs to
end_comment

begin_comment
comment|/// cover 5 objects, i.e. the entire layout. Our algorithm proceeds as follows:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Add bsC, fragments {{C}}
end_comment

begin_comment
comment|/// Add bsD, fragments {{C}, {D}}
end_comment

begin_comment
comment|/// Add bsE, fragments {{C}, {D}, {E}}
end_comment

begin_comment
comment|/// Add bsA, fragments {{A, C}, {D}, {E}}
end_comment

begin_comment
comment|/// Add bsB, fragments {{B, A, C, D, E}}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This layout is optimal for bsA, as it now only needs to cover two (i.e. 3
end_comment

begin_comment
comment|/// fewer) objects, at the cost of bsB needing to cover 1 more object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The bit set lowering pass assigns an object index to each object that needs
end_comment

begin_comment
comment|/// to be laid out, and calls addFragment for each bit set passing the object
end_comment

begin_comment
comment|/// indices of its referenced globals. It then assembles a layout from the
end_comment

begin_comment
comment|/// computed layout in the Fragments field.
end_comment

begin_struct
struct|struct
name|GlobalLayoutBuilder
block|{
comment|/// The computed layout. Each element of this vector contains a fragment of
comment|/// layout (which may be empty) consisting of object indices.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>>
name|Fragments
expr_stmt|;
comment|/// Mapping from object index to fragment index.
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|FragmentMap
expr_stmt|;
name|GlobalLayoutBuilder
argument_list|(
argument|uint64_t NumObjects
argument_list|)
block|:
name|Fragments
argument_list|(
literal|1
argument_list|)
operator|,
name|FragmentMap
argument_list|(
argument|NumObjects
argument_list|)
block|{}
comment|/// Add F to the layout while trying to keep its indices contiguous.
comment|/// If a previously seen fragment uses any of F's indices, that
comment|/// fragment will be laid out inside F.
name|void
name|addFragment
argument_list|(
specifier|const
name|std
operator|::
name|set
operator|<
name|uint64_t
operator|>
operator|&
name|F
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// This class is used to build a byte array containing overlapping bit sets. By
end_comment

begin_comment
comment|/// loading from indexed offsets into the byte array and applying a mask, a
end_comment

begin_comment
comment|/// program can test bits from the bit set with a relatively short instruction
end_comment

begin_comment
comment|/// sequence. For example, suppose we have 15 bit sets to lay out:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A (16 bits), B (15 bits), C (14 bits), D (13 bits), E (12 bits),
end_comment

begin_comment
comment|/// F (11 bits), G (10 bits), H (9 bits), I (7 bits), J (6 bits), K (5 bits),
end_comment

begin_comment
comment|/// L (4 bits), M (3 bits), N (2 bits), O (1 bit)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These bits can be laid out in a 16-byte array like this:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       Byte Offset
end_comment

begin_comment
comment|///     0123456789ABCDEF
end_comment

begin_comment
comment|/// Bit
end_comment

begin_comment
comment|///   7 HHHHHHHHHIIIIIII
end_comment

begin_comment
comment|///   6 GGGGGGGGGGJJJJJJ
end_comment

begin_comment
comment|///   5 FFFFFFFFFFFKKKKK
end_comment

begin_comment
comment|///   4 EEEEEEEEEEEELLLL
end_comment

begin_comment
comment|///   3 DDDDDDDDDDDDDMMM
end_comment

begin_comment
comment|///   2 CCCCCCCCCCCCCCNN
end_comment

begin_comment
comment|///   1 BBBBBBBBBBBBBBBO
end_comment

begin_comment
comment|///   0 AAAAAAAAAAAAAAAA
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, to test bit X of A, we evaluate ((bits[X]& 1) != 0), or to
end_comment

begin_comment
comment|/// test bit X of I, we evaluate ((bits[9 + X]& 0x80) != 0). This can be done
end_comment

begin_comment
comment|/// in 1-2 machine instructions on x86, or 4-6 instructions on ARM.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a byte array, rather than (say) a 2-byte array or a 4-byte array,
end_comment

begin_comment
comment|/// because for one thing it gives us better packing (the more bins there are,
end_comment

begin_comment
comment|/// the less evenly they will be filled), and for another, the instruction
end_comment

begin_comment
comment|/// sequences can be slightly shorter, both on x86 and ARM.
end_comment

begin_struct
struct|struct
name|ByteArrayBuilder
block|{
comment|/// The byte array built so far.
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|Bytes
expr_stmt|;
enum|enum
block|{
name|BitsPerByte
init|=
literal|8
block|}
enum|;
comment|/// The number of bytes allocated so far for each of the bits.
name|uint64_t
name|BitAllocs
index|[
name|BitsPerByte
index|]
decl_stmt|;
name|ByteArrayBuilder
argument_list|()
block|{
name|memset
argument_list|(
name|BitAllocs
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|BitAllocs
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Allocate BitSize bits in the byte array where Bits contains the bits to
comment|/// set. AllocByteOffset is set to the offset within the byte array and
comment|/// AllocMask is set to the bitmask for those bits. This uses the LPT (Longest
comment|/// Processing Time) multiprocessor scheduling algorithm to lay out the bits
comment|/// efficiently; the pass allocates bit sets in decreasing size order.
name|void
name|allocate
argument_list|(
specifier|const
name|std
operator|::
name|set
operator|<
name|uint64_t
operator|>
operator|&
name|Bits
argument_list|,
name|uint64_t
name|BitSize
argument_list|,
name|uint64_t
operator|&
name|AllocByteOffset
argument_list|,
name|uint8_t
operator|&
name|AllocMask
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

