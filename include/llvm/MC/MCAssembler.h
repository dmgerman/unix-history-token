begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCAssembler.h - Object File Generation -------------------*- C++ -*-===//
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
name|LLVM_MC_MCASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// FIXME: Shouldn't be needed.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSectionData
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCFragment
range|:
name|public
name|ilist_node
operator|<
name|MCFragment
operator|>
block|{
name|MCFragment
argument_list|(
specifier|const
name|MCFragment
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCFragment
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|public
operator|:
expr|enum
name|FragmentType
block|{
name|FT_Data
block|,
name|FT_Align
block|,
name|FT_Fill
block|,
name|FT_Org
block|,
name|FT_ZeroFill
block|}
block|;
name|private
operator|:
name|FragmentType
name|Kind
block|;
comment|/// Parent - The data for the section this fragment is in.
name|MCSectionData
operator|*
name|Parent
block|;
comment|/// @name Assembler Backend Data
comment|/// @{
comment|//
comment|// FIXME: This could all be kept private to the assembler implementation.
comment|/// Offset - The offset of this fragment in its section. This is ~0 until
comment|/// initialized.
name|uint64_t
name|Offset
block|;
comment|/// FileSize - The file size of this section. This is ~0 until initialized.
name|uint64_t
name|FileSize
block|;
comment|/// @}
name|protected
operator|:
name|MCFragment
argument_list|(
argument|FragmentType _Kind
argument_list|,
argument|MCSectionData *_Parent =
literal|0
argument_list|)
block|;
name|public
operator|:
comment|// Only for sentinel.
name|MCFragment
argument_list|()
block|;
name|virtual
operator|~
name|MCFragment
argument_list|()
block|;
name|FragmentType
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|MCSectionData
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
name|void
name|setParent
argument_list|(
argument|MCSectionData *Value
argument_list|)
block|{
name|Parent
operator|=
name|Value
block|; }
comment|// FIXME: This should be abstract, fix sentinel.
name|virtual
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Invalid getMaxFileSize call!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
comment|/// @name Assembler Backend Support
comment|/// @{
comment|//
comment|// FIXME: This could all be kept private to the assembler implementation.
name|uint64_t
name|getAddress
argument_list|()
specifier|const
block|;
name|uint64_t
name|getFileSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FileSize
operator|!=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
operator|&&
literal|"File size not set!"
argument_list|)
block|;
return|return
name|FileSize
return|;
block|}
name|void
name|setFileSize
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|assert
argument_list|(
name|Value
operator|<=
name|getMaxFileSize
argument_list|()
operator|&&
literal|"Invalid file size!"
argument_list|)
block|;
name|FileSize
operator|=
name|Value
block|;   }
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Offset
operator|!=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
operator|&&
literal|"File offset not set!"
argument_list|)
block|;
return|return
name|Offset
return|;
block|}
name|void
name|setOffset
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|Offset
operator|=
name|Value
block|; }
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *O
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|MCDataFragment
operator|:
name|public
name|MCFragment
block|{
name|SmallString
operator|<
literal|32
operator|>
name|Contents
block|;
name|public
operator|:
name|MCDataFragment
argument_list|(
name|MCSectionData
operator|*
name|SD
operator|=
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
argument|FT_Data
argument_list|,
argument|SD
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
return|return
name|Contents
operator|.
name|size
argument_list|()
return|;
block|}
name|SmallString
operator|<
literal|32
operator|>
operator|&
name|getContents
argument_list|()
block|{
return|return
name|Contents
return|;
block|}
specifier|const
name|SmallString
operator|<
literal|32
operator|>
operator|&
name|getContents
argument_list|()
specifier|const
block|{
return|return
name|Contents
return|;
block|}
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_Data
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCDataFragment *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|MCAlignFragment
operator|:
name|public
name|MCFragment
block|{
comment|/// Alignment - The alignment to ensure, in bytes.
name|unsigned
name|Alignment
block|;
comment|/// Value - Value to use for filling padding bytes.
name|int64_t
name|Value
block|;
comment|/// ValueSize - The size of the integer (in bytes) of \arg Value.
name|unsigned
name|ValueSize
block|;
comment|/// MaxBytesToEmit - The maximum number of bytes to emit; if the alignment
comment|/// cannot be satisfied in this width then this fragment is ignored.
name|unsigned
name|MaxBytesToEmit
block|;
name|public
operator|:
name|MCAlignFragment
argument_list|(
argument|unsigned _Alignment
argument_list|,
argument|int64_t _Value
argument_list|,
argument|unsigned _ValueSize
argument_list|,
argument|unsigned _MaxBytesToEmit
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Align
argument_list|,
name|SD
argument_list|)
block|,
name|Alignment
argument_list|(
name|_Alignment
argument_list|)
block|,
name|Value
argument_list|(
name|_Value
argument_list|)
block|,
name|ValueSize
argument_list|(
name|_ValueSize
argument_list|)
block|,
name|MaxBytesToEmit
argument_list|(
argument|_MaxBytesToEmit
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|Alignment
operator|-
literal|1
argument_list|,
name|MaxBytesToEmit
argument_list|)
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
name|int64_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|unsigned
name|getValueSize
argument_list|()
specifier|const
block|{
return|return
name|ValueSize
return|;
block|}
name|unsigned
name|getMaxBytesToEmit
argument_list|()
specifier|const
block|{
return|return
name|MaxBytesToEmit
return|;
block|}
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_Align
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCAlignFragment *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|MCFillFragment
operator|:
name|public
name|MCFragment
block|{
comment|/// Value - Value to use for filling bytes.
specifier|const
name|MCExpr
operator|*
name|Value
block|;
comment|/// ValueSize - The size (in bytes) of \arg Value to use when filling.
name|unsigned
name|ValueSize
block|;
comment|/// Count - The number of copies of \arg Value to insert.
name|uint64_t
name|Count
block|;
name|public
operator|:
name|MCFillFragment
argument_list|(
argument|const MCExpr&_Value
argument_list|,
argument|unsigned _ValueSize
argument_list|,
argument|uint64_t _Count
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Fill
argument_list|,
name|SD
argument_list|)
block|,
name|Value
argument_list|(
operator|&
name|_Value
argument_list|)
block|,
name|ValueSize
argument_list|(
name|_ValueSize
argument_list|)
block|,
name|Count
argument_list|(
argument|_Count
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
return|return
name|ValueSize
operator|*
name|Count
return|;
block|}
specifier|const
name|MCExpr
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Value
return|;
block|}
name|unsigned
name|getValueSize
argument_list|()
specifier|const
block|{
return|return
name|ValueSize
return|;
block|}
name|uint64_t
name|getCount
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_Fill
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFillFragment *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|MCOrgFragment
operator|:
name|public
name|MCFragment
block|{
comment|/// Offset - The offset this fragment should start at.
specifier|const
name|MCExpr
operator|*
name|Offset
block|;
comment|/// Value - Value to use for filling bytes.
name|int8_t
name|Value
block|;
name|public
operator|:
name|MCOrgFragment
argument_list|(
argument|const MCExpr&_Offset
argument_list|,
argument|int8_t _Value
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Org
argument_list|,
name|SD
argument_list|)
block|,
name|Offset
argument_list|(
operator|&
name|_Offset
argument_list|)
block|,
name|Value
argument_list|(
argument|_Value
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
comment|// FIXME: This doesn't make much sense.
return|return
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|MCExpr
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Offset
return|;
block|}
name|uint8_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_Org
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCOrgFragment *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// MCZeroFillFragment - Represent data which has a fixed size and alignment,
comment|/// but requires no physical space in the object file.
name|class
name|MCZeroFillFragment
operator|:
name|public
name|MCFragment
block|{
comment|/// Size - The size of this fragment.
name|uint64_t
name|Size
block|;
comment|/// Alignment - The alignment for this fragment.
name|unsigned
name|Alignment
block|;
name|public
operator|:
name|MCZeroFillFragment
argument_list|(
argument|uint64_t _Size
argument_list|,
argument|unsigned _Alignment
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_ZeroFill
argument_list|,
name|SD
argument_list|)
block|,
name|Size
argument_list|(
name|_Size
argument_list|)
block|,
name|Alignment
argument_list|(
argument|_Alignment
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
name|uint64_t
name|getMaxFileSize
argument_list|()
specifier|const
block|{
comment|// FIXME: This also doesn't make much sense, this method is misnamed.
return|return
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
comment|/// @}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_ZeroFill
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCZeroFillFragment *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|// FIXME: Should this be a separate class, or just merged into MCSection? Since
comment|// we anticipate the fast path being through an MCAssembler, the only reason to
comment|// keep it out is for API abstraction.
name|class
name|MCSectionData
operator|:
name|public
name|ilist_node
operator|<
name|MCSectionData
operator|>
block|{
name|MCSectionData
argument_list|(
specifier|const
name|MCSectionData
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCSectionData
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|public
operator|:
comment|/// Fixup - Represent a fixed size region of bytes inside some fragment which
comment|/// needs to be rewritten. This region will either be rewritten by the
comment|/// assembler or cause a relocation entry to be generated.
expr|struct
name|Fixup
block|{
comment|/// Fragment - The fragment containing the fixup.
name|MCFragment
operator|*
name|Fragment
block|;
comment|/// Offset - The offset inside the fragment which needs to be rewritten.
name|uint64_t
name|Offset
block|;
comment|/// Value - The expression to eventually write into the fragment.
specifier|const
name|MCExpr
operator|*
name|Value
block|;
comment|/// Size - The fixup size.
name|unsigned
name|Size
block|;
comment|/// FixedValue - The value to replace the fix up by.
comment|//
comment|// FIXME: This should not be here.
name|uint64_t
name|FixedValue
block|;
name|public
operator|:
name|Fixup
argument_list|(
argument|MCFragment&_Fragment
argument_list|,
argument|uint64_t _Offset
argument_list|,
argument|const MCExpr&_Value
argument_list|,
argument|unsigned _Size
argument_list|)
operator|:
name|Fragment
argument_list|(
operator|&
name|_Fragment
argument_list|)
block|,
name|Offset
argument_list|(
name|_Offset
argument_list|)
block|,
name|Value
argument_list|(
operator|&
name|_Value
argument_list|)
block|,
name|Size
argument_list|(
name|_Size
argument_list|)
block|,
name|FixedValue
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
typedef|typedef
name|iplist
operator|<
name|MCFragment
operator|>
name|FragmentListType
expr_stmt|;
typedef|typedef
name|FragmentListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|FragmentListType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Fixup
operator|>
operator|::
name|const_iterator
name|const_fixup_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Fixup
operator|>
operator|::
name|iterator
name|fixup_iterator
expr_stmt|;
name|private
operator|:
name|iplist
operator|<
name|MCFragment
operator|>
name|Fragments
block|;
specifier|const
name|MCSection
operator|*
name|Section
block|;
comment|/// Alignment - The maximum alignment seen in this section.
name|unsigned
name|Alignment
block|;
comment|/// @name Assembler Backend Data
comment|/// @{
comment|//
comment|// FIXME: This could all be kept private to the assembler implementation.
comment|/// Address - The computed address of this section. This is ~0 until
comment|/// initialized.
name|uint64_t
name|Address
block|;
comment|/// Size - The content size of this section. This is ~0 until initialized.
name|uint64_t
name|Size
block|;
comment|/// FileSize - The size of this section in the object file. This is ~0 until
comment|/// initialized.
name|uint64_t
name|FileSize
block|;
comment|/// LastFixupLookup - Cache for the last looked up fixup.
name|mutable
name|unsigned
name|LastFixupLookup
block|;
comment|/// Fixups - The list of fixups in this section.
name|std
operator|::
name|vector
operator|<
name|Fixup
operator|>
name|Fixups
block|;
comment|/// @}
name|public
operator|:
comment|// Only for use as sentinel.
name|MCSectionData
argument_list|()
block|;
name|MCSectionData
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|,
name|MCAssembler
operator|*
name|A
operator|=
literal|0
argument_list|)
block|;
specifier|const
name|MCSection
operator|&
name|getSection
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Section
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Value
argument_list|)
block|{
name|Alignment
operator|=
name|Value
block|; }
comment|/// @name Fragment Access
comment|/// @{
specifier|const
name|FragmentListType
operator|&
name|getFragmentList
argument_list|()
specifier|const
block|{
return|return
name|Fragments
return|;
block|}
name|FragmentListType
operator|&
name|getFragmentList
argument_list|()
block|{
return|return
name|Fragments
return|;
block|}
name|iterator
name|begin
argument_list|()
block|{
return|return
name|Fragments
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|Fragments
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Fixup Access
comment|/// @{
name|std
operator|::
name|vector
operator|<
name|Fixup
operator|>
operator|&
name|getFixups
argument_list|()
block|{
return|return
name|Fixups
return|;
block|}
name|fixup_iterator
name|fixup_begin
argument_list|()
block|{
return|return
name|Fixups
operator|.
name|begin
argument_list|()
return|;
block|}
name|fixup_iterator
name|fixup_end
argument_list|()
block|{
return|return
name|Fixups
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|fixup_size
argument_list|()
specifier|const
block|{
return|return
name|Fixups
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Assembler Backend Support
comment|/// @{
comment|//
comment|// FIXME: This could all be kept private to the assembler implementation.
comment|/// LookupFixup - Look up the fixup for the given \arg Fragment and \arg
comment|/// Offset.
comment|///
comment|/// If multiple fixups exist for the same fragment and offset it is undefined
comment|/// which one is returned.
comment|//
comment|// FIXME: This isn't horribly slow in practice, but there are much nicer
comment|// solutions to applying the fixups.
specifier|const
name|Fixup
operator|*
name|LookupFixup
argument_list|(
argument|const MCFragment *Fragment
argument_list|,
argument|uint64_t Offset
argument_list|)
specifier|const
block|;
name|uint64_t
name|getAddress
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Address
operator|!=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
operator|&&
literal|"Address not set!"
argument_list|)
block|;
return|return
name|Address
return|;
block|}
name|void
name|setAddress
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|Address
operator|=
name|Value
block|; }
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Size
operator|!=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
operator|&&
literal|"File size not set!"
argument_list|)
block|;
return|return
name|Size
return|;
block|}
name|void
name|setSize
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|Size
operator|=
name|Value
block|; }
name|uint64_t
name|getFileSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FileSize
operator|!=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
operator|&&
literal|"File size not set!"
argument_list|)
block|;
return|return
name|FileSize
return|;
block|}
name|void
name|setFileSize
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|FileSize
operator|=
name|Value
block|; }
comment|/// @}
expr|}
block|;
comment|// FIXME: Same concerns as with SectionData.
name|class
name|MCSymbolData
operator|:
name|public
name|ilist_node
operator|<
name|MCSymbolData
operator|>
block|{
name|public
operator|:
specifier|const
name|MCSymbol
operator|*
name|Symbol
block|;
comment|/// Fragment - The fragment this symbol's value is relative to, if any.
name|MCFragment
operator|*
name|Fragment
block|;
comment|/// Offset - The offset to apply to the fragment address to form this symbol's
comment|/// value.
name|uint64_t
name|Offset
block|;
comment|/// IsExternal - True if this symbol is visible outside this translation
comment|/// unit.
name|unsigned
name|IsExternal
operator|:
literal|1
block|;
comment|/// IsPrivateExtern - True if this symbol is private extern.
name|unsigned
name|IsPrivateExtern
operator|:
literal|1
block|;
comment|/// CommonSize - The size of the symbol, if it is 'common', or 0.
comment|//
comment|// FIXME: Pack this in with other fields? We could put it in offset, since a
comment|// common symbol can never get a definition.
name|uint64_t
name|CommonSize
block|;
comment|/// CommonAlign - The alignment of the symbol, if it is 'common'.
comment|//
comment|// FIXME: Pack this in with other fields?
name|unsigned
name|CommonAlign
block|;
comment|/// Flags - The Flags field is used by object file implementations to store
comment|/// additional per symbol information which is not easily classified.
name|uint32_t
name|Flags
block|;
comment|/// Index - Index field, for use by the object file implementation.
name|uint64_t
name|Index
block|;
name|public
operator|:
comment|// Only for use as sentinel.
name|MCSymbolData
argument_list|()
block|;
name|MCSymbolData
argument_list|(
argument|const MCSymbol&_Symbol
argument_list|,
argument|MCFragment *_Fragment
argument_list|,
argument|uint64_t _Offset
argument_list|,
argument|MCAssembler *A =
literal|0
argument_list|)
block|;
comment|/// @name Accessors
comment|/// @{
specifier|const
name|MCSymbol
operator|&
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Symbol
return|;
block|}
name|MCFragment
operator|*
name|getFragment
argument_list|()
specifier|const
block|{
return|return
name|Fragment
return|;
block|}
name|void
name|setFragment
argument_list|(
argument|MCFragment *Value
argument_list|)
block|{
name|Fragment
operator|=
name|Value
block|; }
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|void
name|setOffset
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|Offset
operator|=
name|Value
block|; }
comment|/// @}
comment|/// @name Symbol Attributes
comment|/// @{
name|bool
name|isExternal
argument_list|()
specifier|const
block|{
return|return
name|IsExternal
return|;
block|}
name|void
name|setExternal
argument_list|(
argument|bool Value
argument_list|)
block|{
name|IsExternal
operator|=
name|Value
block|; }
name|bool
name|isPrivateExtern
argument_list|()
specifier|const
block|{
return|return
name|IsPrivateExtern
return|;
block|}
name|void
name|setPrivateExtern
argument_list|(
argument|bool Value
argument_list|)
block|{
name|IsPrivateExtern
operator|=
name|Value
block|; }
comment|/// isCommon - Is this a 'common' symbol.
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
name|CommonSize
operator|!=
literal|0
return|;
block|}
comment|/// setCommon - Mark this symbol as being 'common'.
comment|///
comment|/// \param Size - The size of the symbol.
comment|/// \param Align - The alignment of the symbol.
name|void
name|setCommon
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned Align
argument_list|)
block|{
name|CommonSize
operator|=
name|Size
block|;
name|CommonAlign
operator|=
name|Align
block|;   }
comment|/// getCommonSize - Return the size of a 'common' symbol.
name|uint64_t
name|getCommonSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCommon
argument_list|()
operator|&&
literal|"Not a 'common' symbol!"
argument_list|)
block|;
return|return
name|CommonSize
return|;
block|}
comment|/// getCommonAlignment - Return the alignment of a 'common' symbol.
name|unsigned
name|getCommonAlignment
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCommon
argument_list|()
operator|&&
literal|"Not a 'common' symbol!"
argument_list|)
block|;
return|return
name|CommonAlign
return|;
block|}
comment|/// getFlags - Get the (implementation defined) symbol flags.
name|uint32_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// setFlags - Set the (implementation defined) symbol flags.
name|void
name|setFlags
argument_list|(
argument|uint32_t Value
argument_list|)
block|{
name|Flags
operator|=
name|Value
block|; }
comment|/// getIndex - Get the (implementation defined) index.
name|uint64_t
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|/// setIndex - Set the (implementation defined) index.
name|void
name|setIndex
argument_list|(
argument|uint64_t Value
argument_list|)
block|{
name|Index
operator|=
name|Value
block|; }
comment|/// @}
expr|}
block|;
comment|// FIXME: This really doesn't belong here. See comments below.
block|struct
name|IndirectSymbolData
block|{
name|MCSymbol
operator|*
name|Symbol
block|;
name|MCSectionData
operator|*
name|SectionData
block|; }
block|;
name|class
name|MCAssembler
block|{
name|public
operator|:
typedef|typedef
name|iplist
operator|<
name|MCSectionData
operator|>
name|SectionDataListType
expr_stmt|;
typedef|typedef
name|iplist
operator|<
name|MCSymbolData
operator|>
name|SymbolDataListType
expr_stmt|;
typedef|typedef
name|SectionDataListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|SectionDataListType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|SymbolDataListType
operator|::
name|const_iterator
name|const_symbol_iterator
expr_stmt|;
typedef|typedef
name|SymbolDataListType
operator|::
name|iterator
name|symbol_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
operator|::
name|iterator
name|indirect_symbol_iterator
expr_stmt|;
name|private
label|:
name|MCAssembler
argument_list|(
specifier|const
name|MCAssembler
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAssembler
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|MCContext
modifier|&
name|Context
decl_stmt|;
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|iplist
operator|<
name|MCSectionData
operator|>
name|Sections
expr_stmt|;
name|iplist
operator|<
name|MCSymbolData
operator|>
name|Symbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
name|IndirectSymbols
expr_stmt|;
name|unsigned
name|SubsectionsViaSymbols
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|/// LayoutSection - Assign offsets and sizes to the fragments in the section
comment|/// \arg SD, and update the section size. The section file offset should
comment|/// already have been computed.
name|void
name|LayoutSection
parameter_list|(
name|MCSectionData
modifier|&
name|SD
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Construct a new assembler instance.
comment|///
comment|/// \arg OS - The stream to output to.
comment|//
comment|// FIXME: How are we going to parameterize this? Two obvious options are stay
comment|// concrete and require clients to pass in a target like object. The other
comment|// option is to make this abstract, and have targets provide concrete
comment|// implementations as we do with AsmParser.
name|MCAssembler
argument_list|(
name|MCContext
operator|&
name|_Context
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
operator|~
name|MCAssembler
argument_list|()
expr_stmt|;
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
comment|/// Finish - Do final processing and write the object to the output stream.
name|void
name|Finish
parameter_list|()
function_decl|;
comment|// FIXME: This does not belong here.
name|bool
name|getSubsectionsViaSymbols
argument_list|()
specifier|const
block|{
return|return
name|SubsectionsViaSymbols
return|;
block|}
name|void
name|setSubsectionsViaSymbols
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|SubsectionsViaSymbols
operator|=
name|Value
expr_stmt|;
block|}
comment|/// @name Section List Access
comment|/// @{
specifier|const
name|SectionDataListType
operator|&
name|getSectionList
argument_list|()
specifier|const
block|{
return|return
name|Sections
return|;
block|}
name|SectionDataListType
modifier|&
name|getSectionList
parameter_list|()
block|{
return|return
name|Sections
return|;
block|}
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Sections
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Sections
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Sections
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Sections
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Sections
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Symbol List Access
comment|/// @{
specifier|const
name|SymbolDataListType
operator|&
name|getSymbolList
argument_list|()
specifier|const
block|{
return|return
name|Symbols
return|;
block|}
name|SymbolDataListType
modifier|&
name|getSymbolList
parameter_list|()
block|{
return|return
name|Symbols
return|;
block|}
name|symbol_iterator
name|symbol_begin
parameter_list|()
block|{
return|return
name|Symbols
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_symbol_iterator
name|symbol_begin
argument_list|()
specifier|const
block|{
return|return
name|Symbols
operator|.
name|begin
argument_list|()
return|;
block|}
name|symbol_iterator
name|symbol_end
parameter_list|()
block|{
return|return
name|Symbols
operator|.
name|end
argument_list|()
return|;
block|}
name|const_symbol_iterator
name|symbol_end
argument_list|()
specifier|const
block|{
return|return
name|Symbols
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|symbol_size
argument_list|()
specifier|const
block|{
return|return
name|Symbols
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Indirect Symbol List Access
comment|/// @{
comment|// FIXME: This is a total hack, this should not be here. Once things are
comment|// factored so that the streamer has direct access to the .o writer, it can
comment|// disappear.
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
operator|&
name|getIndirectSymbols
argument_list|()
block|{
return|return
name|IndirectSymbols
return|;
block|}
name|indirect_symbol_iterator
name|indirect_symbol_begin
parameter_list|()
block|{
return|return
name|IndirectSymbols
operator|.
name|begin
argument_list|()
return|;
block|}
name|indirect_symbol_iterator
name|indirect_symbol_end
parameter_list|()
block|{
return|return
name|IndirectSymbols
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|indirect_symbol_size
argument_list|()
specifier|const
block|{
return|return
name|IndirectSymbols
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
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

end_unit

