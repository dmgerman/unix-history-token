begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LowerTypeTests.h - type metadata lowering pass -----------*- C++ -*-===//
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
comment|// This file defines parts of the type test lowering pass implementation that
end_comment

begin_comment
comment|// may be usefully unit tested.
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
name|LLVM_TRANSFORMS_IPO_LOWERTYPETESTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_LOWERTYPETESTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstring>
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
name|raw_ostream
decl_stmt|;
name|namespace
name|lowertypetests
block|{
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
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|uint64_t
operator|>
operator|::
name|max
argument_list|()
decl_stmt|;
name|uint64_t
name|Max
init|=
literal|0
decl_stmt|;
name|BitSetBuilder
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|addOffset
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
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
parameter_list|()
function_decl|;
block|}
struct|;
comment|/// This class implements a layout algorithm for globals referenced by bit sets
comment|/// that tries to keep members of small bit sets together. This can
comment|/// significantly reduce bit set sizes in many cases.
comment|///
comment|/// It works by assembling fragments of layout from sets of referenced globals.
comment|/// Each set of referenced globals causes the algorithm to create a new
comment|/// fragment, which is assembled by appending each referenced global in the set
comment|/// into the fragment. If a referenced global has already been referenced by an
comment|/// fragment created earlier, we instead delete that fragment and append its
comment|/// contents into the fragment we are assembling.
comment|///
comment|/// By starting with the smallest fragments, we minimize the size of the
comment|/// fragments that are copied into larger fragments. This is most intuitively
comment|/// thought about when considering the case where the globals are virtual tables
comment|/// and the bit sets represent their derived classes: in a single inheritance
comment|/// hierarchy, the optimum layout would involve a depth-first search of the
comment|/// class hierarchy (and in fact the computed layout ends up looking a lot like
comment|/// a DFS), but a naive DFS would not work well in the presence of multiple
comment|/// inheritance. This aspect of the algorithm ends up fitting smaller
comment|/// hierarchies inside larger ones where that would be beneficial.
comment|///
comment|/// For example, consider this class hierarchy:
comment|///
comment|/// A       B
comment|///   \   / | \
comment|///     C   D   E
comment|///
comment|/// We have five bit sets: bsA (A, C), bsB (B, C, D, E), bsC (C), bsD (D) and
comment|/// bsE (E). If we laid out our objects by DFS traversing B followed by A, our
comment|/// layout would be {B, C, D, E, A}. This is optimal for bsB as it needs to
comment|/// cover the only 4 objects in its hierarchy, but not for bsA as it needs to
comment|/// cover 5 objects, i.e. the entire layout. Our algorithm proceeds as follows:
comment|///
comment|/// Add bsC, fragments {{C}}
comment|/// Add bsD, fragments {{C}, {D}}
comment|/// Add bsE, fragments {{C}, {D}, {E}}
comment|/// Add bsA, fragments {{A, C}, {D}, {E}}
comment|/// Add bsB, fragments {{B, A, C, D, E}}
comment|///
comment|/// This layout is optimal for bsA, as it now only needs to cover two (i.e. 3
comment|/// fewer) objects, at the cost of bsB needing to cover 1 more object.
comment|///
comment|/// The bit set lowering pass assigns an object index to each object that needs
comment|/// to be laid out, and calls addFragment for each bit set passing the object
comment|/// indices of its referenced globals. It then assembles a layout from the
comment|/// computed layout in the Fragments field.
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
comment|/// This class is used to build a byte array containing overlapping bit sets. By
comment|/// loading from indexed offsets into the byte array and applying a mask, a
comment|/// program can test bits from the bit set with a relatively short instruction
comment|/// sequence. For example, suppose we have 15 bit sets to lay out:
comment|///
comment|/// A (16 bits), B (15 bits), C (14 bits), D (13 bits), E (12 bits),
comment|/// F (11 bits), G (10 bits), H (9 bits), I (7 bits), J (6 bits), K (5 bits),
comment|/// L (4 bits), M (3 bits), N (2 bits), O (1 bit)
comment|///
comment|/// These bits can be laid out in a 16-byte array like this:
comment|///
comment|///       Byte Offset
comment|///     0123456789ABCDEF
comment|/// Bit
comment|///   7 HHHHHHHHHIIIIIII
comment|///   6 GGGGGGGGGGJJJJJJ
comment|///   5 FFFFFFFFFFFKKKKK
comment|///   4 EEEEEEEEEEEELLLL
comment|///   3 DDDDDDDDDDDDDMMM
comment|///   2 CCCCCCCCCCCCCCNN
comment|///   1 BBBBBBBBBBBBBBBO
comment|///   0 AAAAAAAAAAAAAAAA
comment|///
comment|/// For example, to test bit X of A, we evaluate ((bits[X]& 1) != 0), or to
comment|/// test bit X of I, we evaluate ((bits[9 + X]& 0x80) != 0). This can be done
comment|/// in 1-2 machine instructions on x86, or 4-6 instructions on ARM.
comment|///
comment|/// This is a byte array, rather than (say) a 2-byte array or a 4-byte array,
comment|/// because for one thing it gives us better packing (the more bins there are,
comment|/// the less evenly they will be filled), and for another, the instruction
comment|/// sequences can be slightly shorter, both on x86 and ARM.
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
block|}
comment|// end namespace lowertypetests
name|class
name|LowerTypeTestsPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LowerTypeTestsPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_LOWERTYPETESTS_H
end_comment

end_unit

