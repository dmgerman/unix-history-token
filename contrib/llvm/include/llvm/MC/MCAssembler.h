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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

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
file|"llvm/MC/MCFixup.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
name|MCAsmLayout
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCObjectWriter
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
name|MCSymbolData
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|MCAsmBackend
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
name|friend
name|class
name|MCAsmLayout
block|;
name|MCFragment
argument_list|(
argument|const MCFragment&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCFragment
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
expr|enum
name|FragmentType
block|{
name|FT_Align
block|,
name|FT_Data
block|,
name|FT_CompactEncodedInst
block|,
name|FT_Fill
block|,
name|FT_Relaxable
block|,
name|FT_Org
block|,
name|FT_Dwarf
block|,
name|FT_DwarfFrame
block|,
name|FT_LEB
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
comment|/// Atom - The atom this fragment is in, as represented by it's defining
comment|/// symbol. Atom's are only used by backends which set
comment|/// \see MCAsmBackend::hasReliableSymbolDifference().
name|MCSymbolData
operator|*
name|Atom
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
comment|/// LayoutOrder - The layout order of this fragment.
name|unsigned
name|LayoutOrder
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
name|MCSymbolData
operator|*
name|getAtom
argument_list|()
specifier|const
block|{
return|return
name|Atom
return|;
block|}
name|void
name|setAtom
argument_list|(
argument|MCSymbolData *Value
argument_list|)
block|{
name|Atom
operator|=
name|Value
block|; }
name|unsigned
name|getLayoutOrder
argument_list|()
specifier|const
block|{
return|return
name|LayoutOrder
return|;
block|}
name|void
name|setLayoutOrder
argument_list|(
argument|unsigned Value
argument_list|)
block|{
name|LayoutOrder
operator|=
name|Value
block|; }
comment|/// \brief Does this fragment have instructions emitted into it? By default
comment|/// this is false, but specific fragment types may set it to true.
name|virtual
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Should this fragment be placed at the end of an aligned bundle?
name|virtual
name|bool
name|alignToBundleEnd
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|setAlignToBundleEnd
argument_list|(
argument|bool V
argument_list|)
block|{ }
comment|/// \brief Get the padding size that must be inserted before this fragment.
comment|/// Used for bundling. By default, no padding is inserted.
comment|/// Note that padding size is restricted to 8 bits. This is an optimization
comment|/// to reduce the amount of space used for each fragment. In practice, larger
comment|/// padding should never be required.
name|virtual
name|uint8_t
name|getBundlePadding
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Set the padding size for this fragment. By default it's a no-op,
comment|/// and only some fragments have a meaningful implementation.
name|virtual
name|void
name|setBundlePadding
argument_list|(
argument|uint8_t N
argument_list|)
block|{   }
name|void
name|dump
argument_list|()
block|; }
decl_stmt|;
comment|/// Interface implemented by fragments that contain encoded instructions and/or
comment|/// data.
comment|///
name|class
name|MCEncodedFragment
range|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|uint8_t
name|BundlePadding
block|;
name|public
operator|:
name|MCEncodedFragment
argument_list|(
argument|MCFragment::FragmentType FType
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FType
argument_list|,
name|SD
argument_list|)
block|,
name|BundlePadding
argument_list|(
literal|0
argument_list|)
block|{   }
name|virtual
operator|~
name|MCEncodedFragment
argument_list|()
block|;
name|virtual
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|uint8_t
name|getBundlePadding
argument_list|()
specifier|const
block|{
return|return
name|BundlePadding
return|;
block|}
name|virtual
name|void
name|setBundlePadding
argument_list|(
argument|uint8_t N
argument_list|)
block|{
name|BundlePadding
operator|=
name|N
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCFragment *F
argument_list|)
block|{
name|MCFragment
operator|::
name|FragmentType
name|Kind
operator|=
name|F
operator|->
name|getKind
argument_list|()
block|;
switch|switch
condition|(
name|Kind
condition|)
block|{
default|default:
return|return
name|false
return|;
case|case
name|MCFragment
operator|::
name|FT_Relaxable
case|:
case|case
name|MCFragment
operator|::
name|FT_CompactEncodedInst
case|:
case|case
name|MCFragment
operator|::
name|FT_Data
case|:
return|return
name|true
return|;
block|}
block|}
expr|}
block|;
comment|/// Interface implemented by fragments that contain encoded instructions and/or
comment|/// data and also have fixups registered.
comment|///
name|class
name|MCEncodedFragmentWithFixups
operator|:
name|public
name|MCEncodedFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|MCEncodedFragmentWithFixups
argument_list|(
argument|MCFragment::FragmentType FType
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCEncodedFragment
argument_list|(
argument|FType
argument_list|,
argument|SD
argument_list|)
block|{   }
name|virtual
operator|~
name|MCEncodedFragmentWithFixups
argument_list|()
block|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|::
name|const_iterator
name|const_fixup_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|::
name|iterator
name|fixup_iterator
expr_stmt|;
name|virtual
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
operator|=
literal|0
decl_stmt|;
name|virtual
specifier|const
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|fixup_iterator
name|fixup_begin
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|const_fixup_iterator
name|fixup_begin
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|fixup_iterator
name|fixup_end
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|const_fixup_iterator
name|fixup_end
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCFragment
modifier|*
name|F
parameter_list|)
block|{
name|MCFragment
operator|::
name|FragmentType
name|Kind
operator|=
name|F
operator|->
name|getKind
argument_list|()
expr_stmt|;
return|return
name|Kind
operator|==
name|MCFragment
operator|::
name|FT_Relaxable
operator|||
name|Kind
operator|==
name|MCFragment
operator|::
name|FT_Data
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Fragment for data and encoded instructions.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MCDataFragment
range|:
name|public
name|MCEncodedFragmentWithFixups
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief Does this fragment contain encoded instructions anywhere in it?
name|bool
name|HasInstructions
block|;
comment|/// \brief Should this fragment be aligned to the end of a bundle?
name|bool
name|AlignToBundleEnd
block|;
name|SmallVector
operator|<
name|char
block|,
literal|32
operator|>
name|Contents
block|;
comment|/// Fixups - The list of fixups in this fragment.
name|SmallVector
operator|<
name|MCFixup
block|,
literal|4
operator|>
name|Fixups
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
name|MCEncodedFragmentWithFixups
argument_list|(
name|FT_Data
argument_list|,
name|SD
argument_list|)
block|,
name|HasInstructions
argument_list|(
name|false
argument_list|)
block|,
name|AlignToBundleEnd
argument_list|(
argument|false
argument_list|)
block|{   }
name|virtual
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
block|{
return|return
name|Contents
return|;
block|}
name|virtual
specifier|const
name|SmallVectorImpl
operator|<
name|char
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
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
block|{
return|return
name|Fixups
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
specifier|const
block|{
return|return
name|Fixups
return|;
block|}
name|virtual
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|HasInstructions
return|;
block|}
name|virtual
name|void
name|setHasInstructions
argument_list|(
argument|bool V
argument_list|)
block|{
name|HasInstructions
operator|=
name|V
block|; }
name|virtual
name|bool
name|alignToBundleEnd
argument_list|()
specifier|const
block|{
return|return
name|AlignToBundleEnd
return|;
block|}
name|virtual
name|void
name|setAlignToBundleEnd
argument_list|(
argument|bool V
argument_list|)
block|{
name|AlignToBundleEnd
operator|=
name|V
block|; }
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
name|const_fixup_iterator
name|fixup_begin
argument_list|()
specifier|const
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
name|const_fixup_iterator
name|fixup_end
argument_list|()
specifier|const
block|{
return|return
name|Fixups
operator|.
name|end
argument_list|()
return|;
block|}
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
expr|}
block|;
comment|/// This is a compact (memory-size-wise) fragment for holding an encoded
comment|/// instruction (non-relaxable) that has no fixups registered. When applicable,
comment|/// it can be used instead of MCDataFragment and lead to lower memory
comment|/// consumption.
comment|///
name|class
name|MCCompactEncodedInstFragment
operator|:
name|public
name|MCEncodedFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief Should this fragment be aligned to the end of a bundle?
name|bool
name|AlignToBundleEnd
block|;
name|SmallVector
operator|<
name|char
block|,
literal|4
operator|>
name|Contents
block|;
name|public
operator|:
name|MCCompactEncodedInstFragment
argument_list|(
name|MCSectionData
operator|*
name|SD
operator|=
literal|0
argument_list|)
operator|:
name|MCEncodedFragment
argument_list|(
name|FT_CompactEncodedInst
argument_list|,
name|SD
argument_list|)
block|,
name|AlignToBundleEnd
argument_list|(
argument|false
argument_list|)
block|{   }
name|virtual
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
block|{
return|return
name|Contents
return|;
block|}
name|virtual
specifier|const
name|SmallVectorImpl
operator|<
name|char
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
name|virtual
name|bool
name|alignToBundleEnd
argument_list|()
specifier|const
block|{
return|return
name|AlignToBundleEnd
return|;
block|}
name|virtual
name|void
name|setAlignToBundleEnd
argument_list|(
argument|bool V
argument_list|)
block|{
name|AlignToBundleEnd
operator|=
name|V
block|; }
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
name|FT_CompactEncodedInst
return|;
block|}
expr|}
block|;
comment|/// A relaxable fragment holds on to its MCInst, since it may need to be
comment|/// relaxed during the assembler layout and relaxation stage.
comment|///
name|class
name|MCRelaxableFragment
operator|:
name|public
name|MCEncodedFragmentWithFixups
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Inst - The instruction this is a fragment for.
name|MCInst
name|Inst
block|;
comment|/// Contents - Binary data for the currently encoded instruction.
name|SmallVector
operator|<
name|char
block|,
literal|8
operator|>
name|Contents
block|;
comment|/// Fixups - The list of fixups in this fragment.
name|SmallVector
operator|<
name|MCFixup
block|,
literal|1
operator|>
name|Fixups
block|;
name|public
operator|:
name|MCRelaxableFragment
argument_list|(
specifier|const
name|MCInst
operator|&
name|_Inst
argument_list|,
name|MCSectionData
operator|*
name|SD
operator|=
literal|0
argument_list|)
operator|:
name|MCEncodedFragmentWithFixups
argument_list|(
name|FT_Relaxable
argument_list|,
name|SD
argument_list|)
block|,
name|Inst
argument_list|(
argument|_Inst
argument_list|)
block|{   }
name|virtual
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
block|{
return|return
name|Contents
return|;
block|}
name|virtual
specifier|const
name|SmallVectorImpl
operator|<
name|char
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
specifier|const
name|MCInst
operator|&
name|getInst
argument_list|()
specifier|const
block|{
return|return
name|Inst
return|;
block|}
name|void
name|setInst
argument_list|(
argument|const MCInst& Value
argument_list|)
block|{
name|Inst
operator|=
name|Value
block|; }
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
block|{
return|return
name|Fixups
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
specifier|const
block|{
return|return
name|Fixups
return|;
block|}
name|virtual
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|true
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
name|const_fixup_iterator
name|fixup_begin
argument_list|()
specifier|const
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
name|const_fixup_iterator
name|fixup_end
argument_list|()
specifier|const
block|{
return|return
name|Fixups
operator|.
name|end
argument_list|()
return|;
block|}
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
name|FT_Relaxable
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
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Alignment - The alignment to ensure, in bytes.
name|unsigned
name|Alignment
block|;
comment|/// Value - Value to use for filling padding bytes.
name|int64_t
name|Value
block|;
comment|/// ValueSize - The size of the integer (in bytes) of \p Value.
name|unsigned
name|ValueSize
block|;
comment|/// MaxBytesToEmit - The maximum number of bytes to emit; if the alignment
comment|/// cannot be satisfied in this width then this fragment is ignored.
name|unsigned
name|MaxBytesToEmit
block|;
comment|/// EmitNops - Flag to indicate that (optimal) NOPs should be emitted instead
comment|/// of using the provided value. The exact interpretation of this flag is
comment|/// target dependent.
name|bool
name|EmitNops
operator|:
literal|1
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
name|_MaxBytesToEmit
argument_list|)
block|,
name|EmitNops
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// @name Accessors
comment|/// @{
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
name|bool
name|hasEmitNops
argument_list|()
specifier|const
block|{
return|return
name|EmitNops
return|;
block|}
name|void
name|setEmitNops
argument_list|(
argument|bool Value
argument_list|)
block|{
name|EmitNops
operator|=
name|Value
block|; }
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
expr|}
block|;
name|class
name|MCFillFragment
operator|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Value - Value to use for filling bytes.
name|int64_t
name|Value
block|;
comment|/// ValueSize - The size (in bytes) of \p Value to use when filling, or 0 if
comment|/// this is a virtual fill fragment.
name|unsigned
name|ValueSize
block|;
comment|/// Size - The number of bytes to insert.
name|uint64_t
name|Size
block|;
name|public
operator|:
name|MCFillFragment
argument_list|(
argument|int64_t _Value
argument_list|,
argument|unsigned _ValueSize
argument_list|,
argument|uint64_t _Size
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
name|_Value
argument_list|)
block|,
name|ValueSize
argument_list|(
name|_ValueSize
argument_list|)
block|,
name|Size
argument_list|(
argument|_Size
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|ValueSize
operator|||
operator|(
name|Size
operator|%
name|ValueSize
operator|)
operator|==
literal|0
operator|)
operator|&&
literal|"Fill size must be a multiple of the value size!"
argument_list|)
block|;   }
comment|/// @name Accessors
comment|/// @{
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
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
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
expr|}
block|;
name|class
name|MCOrgFragment
operator|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
expr|}
block|;
name|class
name|MCLEBFragment
operator|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Value - The value this fragment should contain.
specifier|const
name|MCExpr
operator|*
name|Value
block|;
comment|/// IsSigned - True if this is a sleb128, false if uleb128.
name|bool
name|IsSigned
block|;
name|SmallString
operator|<
literal|8
operator|>
name|Contents
block|;
name|public
operator|:
name|MCLEBFragment
argument_list|(
argument|const MCExpr&Value_
argument_list|,
argument|bool IsSigned_
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_LEB
argument_list|,
name|SD
argument_list|)
block|,
name|Value
argument_list|(
operator|&
name|Value_
argument_list|)
block|,
name|IsSigned
argument_list|(
argument|IsSigned_
argument_list|)
block|{
name|Contents
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|; }
comment|/// @name Accessors
comment|/// @{
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
name|bool
name|isSigned
argument_list|()
specifier|const
block|{
return|return
name|IsSigned
return|;
block|}
name|SmallString
operator|<
literal|8
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
literal|8
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
name|FT_LEB
return|;
block|}
expr|}
block|;
name|class
name|MCDwarfLineAddrFragment
operator|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// LineDelta - the value of the difference between the two line numbers
comment|/// between two .loc dwarf directives.
name|int64_t
name|LineDelta
block|;
comment|/// AddrDelta - The expression for the difference of the two symbols that
comment|/// make up the address delta between two .loc dwarf directives.
specifier|const
name|MCExpr
operator|*
name|AddrDelta
block|;
name|SmallString
operator|<
literal|8
operator|>
name|Contents
block|;
name|public
operator|:
name|MCDwarfLineAddrFragment
argument_list|(
argument|int64_t _LineDelta
argument_list|,
argument|const MCExpr&_AddrDelta
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Dwarf
argument_list|,
name|SD
argument_list|)
block|,
name|LineDelta
argument_list|(
name|_LineDelta
argument_list|)
block|,
name|AddrDelta
argument_list|(
argument|&_AddrDelta
argument_list|)
block|{
name|Contents
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|; }
comment|/// @name Accessors
comment|/// @{
name|int64_t
name|getLineDelta
argument_list|()
specifier|const
block|{
return|return
name|LineDelta
return|;
block|}
specifier|const
name|MCExpr
operator|&
name|getAddrDelta
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AddrDelta
return|;
block|}
name|SmallString
operator|<
literal|8
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
literal|8
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
name|FT_Dwarf
return|;
block|}
expr|}
block|;
name|class
name|MCDwarfCallFrameFragment
operator|:
name|public
name|MCFragment
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// AddrDelta - The expression for the difference of the two symbols that
comment|/// make up the address delta between two .cfi_* dwarf directives.
specifier|const
name|MCExpr
operator|*
name|AddrDelta
block|;
name|SmallString
operator|<
literal|8
operator|>
name|Contents
block|;
name|public
operator|:
name|MCDwarfCallFrameFragment
argument_list|(
specifier|const
name|MCExpr
operator|&
name|_AddrDelta
argument_list|,
name|MCSectionData
operator|*
name|SD
operator|=
literal|0
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_DwarfFrame
argument_list|,
name|SD
argument_list|)
block|,
name|AddrDelta
argument_list|(
argument|&_AddrDelta
argument_list|)
block|{
name|Contents
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|; }
comment|/// @name Accessors
comment|/// @{
specifier|const
name|MCExpr
operator|&
name|getAddrDelta
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AddrDelta
return|;
block|}
name|SmallString
operator|<
literal|8
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
literal|8
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
name|FT_DwarfFrame
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
name|friend
name|class
name|MCAsmLayout
block|;
name|MCSectionData
argument_list|(
argument|const MCSectionData&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCSectionData
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
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
name|FragmentListType
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
typedef|typedef
name|FragmentListType
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
comment|/// \brief Express the state of bundle locked groups while emitting code.
block|enum
name|BundleLockStateType
block|{
name|NotBundleLocked
block|,
name|BundleLocked
block|,
name|BundleLockedAlignToEnd
block|}
block|;
name|private
operator|:
name|FragmentListType
name|Fragments
block|;
specifier|const
name|MCSection
operator|*
name|Section
block|;
comment|/// Ordinal - The section index in the assemblers section list.
name|unsigned
name|Ordinal
block|;
comment|/// LayoutOrder - The index of this section in the layout order.
name|unsigned
name|LayoutOrder
block|;
comment|/// Alignment - The maximum alignment seen in this section.
name|unsigned
name|Alignment
block|;
comment|/// \brief Keeping track of bundle-locked state.
name|BundleLockStateType
name|BundleLockState
block|;
comment|/// \brief We've seen a bundle_lock directive but not its first instruction
comment|/// yet.
name|bool
name|BundleGroupBeforeFirstInst
block|;
comment|/// @name Assembler Backend Data
comment|/// @{
comment|//
comment|// FIXME: This could all be kept private to the assembler implementation.
comment|/// HasInstructions - Whether this section has had instructions emitted into
comment|/// it.
name|unsigned
name|HasInstructions
operator|:
literal|1
block|;
comment|/// Mapping from subsection number to insertion point for subsection numbers
comment|/// below that number.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|MCFragment
operator|*
operator|>
block|,
literal|1
operator|>
name|SubsectionFragmentMap
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
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|HasInstructions
return|;
block|}
name|void
name|setHasInstructions
argument_list|(
argument|bool Value
argument_list|)
block|{
name|HasInstructions
operator|=
name|Value
block|; }
name|unsigned
name|getOrdinal
argument_list|()
specifier|const
block|{
return|return
name|Ordinal
return|;
block|}
name|void
name|setOrdinal
argument_list|(
argument|unsigned Value
argument_list|)
block|{
name|Ordinal
operator|=
name|Value
block|; }
name|unsigned
name|getLayoutOrder
argument_list|()
specifier|const
block|{
return|return
name|LayoutOrder
return|;
block|}
name|void
name|setLayoutOrder
argument_list|(
argument|unsigned Value
argument_list|)
block|{
name|LayoutOrder
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
name|reverse_iterator
name|rbegin
argument_list|()
block|{
return|return
name|Fragments
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
argument_list|()
block|{
return|return
name|Fragments
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|Fragments
operator|.
name|rend
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
name|iterator
name|getSubsectionInsertionPoint
argument_list|(
argument|unsigned Subsection
argument_list|)
block|;
name|bool
name|isBundleLocked
argument_list|()
specifier|const
block|{
return|return
name|BundleLockState
operator|!=
name|NotBundleLocked
return|;
block|}
name|BundleLockStateType
name|getBundleLockState
argument_list|()
specifier|const
block|{
return|return
name|BundleLockState
return|;
block|}
name|void
name|setBundleLockState
argument_list|(
argument|BundleLockStateType NewState
argument_list|)
block|{
name|BundleLockState
operator|=
name|NewState
block|;   }
name|bool
name|isBundleGroupBeforeFirstInst
argument_list|()
specifier|const
block|{
return|return
name|BundleGroupBeforeFirstInst
return|;
block|}
name|void
name|setBundleGroupBeforeFirstInst
argument_list|(
argument|bool IsFirst
argument_list|)
block|{
name|BundleGroupBeforeFirstInst
operator|=
name|IsFirst
block|;   }
name|void
name|dump
argument_list|()
block|;
comment|/// @}
block|}
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
comment|/// SymbolSize - An expression describing how to calculate the size of
comment|/// a symbol. If a symbol has no size this field will be NULL.
specifier|const
name|MCExpr
operator|*
name|SymbolSize
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
name|void
name|setSize
argument_list|(
argument|const MCExpr *SS
argument_list|)
block|{
name|SymbolSize
operator|=
name|SS
block|;   }
specifier|const
name|MCExpr
operator|*
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|SymbolSize
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
comment|/// modifyFlags - Modify the flags via a mask
name|void
name|modifyFlags
argument_list|(
argument|uint32_t Value
argument_list|,
argument|uint32_t Mask
argument_list|)
block|{
name|Flags
operator|=
operator|(
name|Flags
operator|&
operator|~
name|Mask
operator|)
operator||
name|Value
block|;   }
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
name|void
name|dump
argument_list|()
block|; }
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
comment|// FIXME: Ditto this. Purely so the Streamer and the ObjectWriter can talk
comment|// to one another.
block|struct
name|DataRegionData
block|{
comment|// This enum should be kept in sync w/ the mach-o definition in
comment|// llvm/Object/MachOFormat.h.
block|enum
name|KindTy
block|{
name|Data
operator|=
literal|1
block|,
name|JumpTable8
block|,
name|JumpTable16
block|,
name|JumpTable32
block|}
name|Kind
block|;
name|MCSymbol
operator|*
name|Start
block|;
name|MCSymbol
operator|*
name|End
block|; }
block|;
name|class
name|MCAssembler
block|{
name|friend
name|class
name|MCAsmLayout
block|;
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
end_decl_stmt

begin_typedef
typedef|typedef
name|SymbolDataListType
operator|::
name|iterator
name|symbol_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|FileNameVectorType
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|FileNameVectorType
operator|::
name|const_iterator
name|const_file_name_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
operator|::
name|const_iterator
name|const_indirect_symbol_iterator
expr_stmt|;
end_typedef

begin_typedef
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
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DataRegionData
operator|>
operator|::
name|const_iterator
name|const_data_region_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DataRegionData
operator|>
operator|::
name|iterator
name|data_region_iterator
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_macro
name|MCAssembler
argument_list|(
argument|const MCAssembler&
argument_list|)
end_macro

begin_expr_stmt
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAssembler
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCContext
modifier|&
name|Context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCAsmBackend
modifier|&
name|Backend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCCodeEmitter
modifier|&
name|Emitter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCObjectWriter
modifier|&
name|Writer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iplist
operator|<
name|MCSectionData
operator|>
name|Sections
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iplist
operator|<
name|MCSymbolData
operator|>
name|Symbols
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The map of sections to their associated assembler backend data.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Avoid this indirection?
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|MCSectionData
operator|*
operator|>
name|SectionMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The map of symbols to their associated assembler backend data.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Avoid this indirection?
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|MCSymbolData
operator|*
operator|>
name|SymbolMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
name|IndirectSymbols
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DataRegionData
operator|>
name|DataRegions
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The list of linker options to propagate into the object file.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
expr|>
name|LinkerOptions
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// List of declared file names
end_comment

begin_decl_stmt
name|FileNameVectorType
name|FileNames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The set of function symbols for which a .thumb_func directive has
end_comment

begin_comment
comment|/// been seen.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: We really would like this in target specific code rather than
end_comment

begin_comment
comment|// here. Maybe when the relocation stuff moves to target specific,
end_comment

begin_comment
comment|// this can go with it? The streamer would need some target specific
end_comment

begin_comment
comment|// refactoring too.
end_comment

begin_expr_stmt
name|SmallPtrSet
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
literal|64
operator|>
name|ThumbFuncs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The bundle alignment size currently set in the assembler.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default it's 0, which means bundling is disabled.
end_comment

begin_decl_stmt
name|unsigned
name|BundleAlignSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|RelaxAll
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NoExecStack
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|SubsectionsViaSymbols
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ELF specific e_header flags
end_comment

begin_comment
comment|// It would be good if there were an MCELFAssembler class to hold this.
end_comment

begin_comment
comment|// ELF header flags are used both by the integrated and standalone assemblers.
end_comment

begin_comment
comment|// Access to the flags is necessary in cases where assembler directives affect
end_comment

begin_comment
comment|// which flags to be set.
end_comment

begin_decl_stmt
name|unsigned
name|ELFHeaderEFlags
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Evaluate a fixup to a relocatable expression and the value which should be
end_comment

begin_comment
comment|/// placed into the fixup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Layout The layout to use for evaluation.
end_comment

begin_comment
comment|/// \param Fixup The fixup to evaluate.
end_comment

begin_comment
comment|/// \param DF The fragment the fixup is inside.
end_comment

begin_comment
comment|/// \param Target [out] On return, the relocatable expression the fixup
end_comment

begin_comment
comment|/// evaluates to.
end_comment

begin_comment
comment|/// \param Value [out] On return, the value of the fixup as currently laid
end_comment

begin_comment
comment|/// out.
end_comment

begin_comment
comment|/// \return Whether the fixup value was fully resolved. This is true if the
end_comment

begin_comment
comment|/// \p Value result is fixed, otherwise the value may change due to
end_comment

begin_comment
comment|/// relocation.
end_comment

begin_decl_stmt
name|bool
name|evaluateFixup
argument_list|(
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
specifier|const
name|MCFragment
operator|*
name|DF
argument_list|,
name|MCValue
operator|&
name|Target
argument_list|,
name|uint64_t
operator|&
name|Value
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check whether a fixup can be satisfied, or whether it needs to be relaxed
end_comment

begin_comment
comment|/// (increased in size, in order to hold its value correctly).
end_comment

begin_decl_stmt
name|bool
name|fixupNeedsRelaxation
argument_list|(
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
specifier|const
name|MCRelaxableFragment
operator|*
name|DF
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check whether the given fragment needs relaxation.
end_comment

begin_decl_stmt
name|bool
name|fragmentNeedsRelaxation
argument_list|(
specifier|const
name|MCRelaxableFragment
operator|*
name|IF
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Perform one layout iteration and return true if any offsets
end_comment

begin_comment
comment|/// were adjusted.
end_comment

begin_function_decl
name|bool
name|layoutOnce
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Perform one layout iteration of the given section and return true
end_comment

begin_comment
comment|/// if any offsets were adjusted.
end_comment

begin_function_decl
name|bool
name|layoutSectionOnce
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCSectionData
modifier|&
name|SD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|relaxInstruction
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCRelaxableFragment
modifier|&
name|IF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|relaxLEB
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCLEBFragment
modifier|&
name|IF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|relaxDwarfLineAddr
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCDwarfLineAddrFragment
modifier|&
name|DF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|relaxDwarfCallFrameFragment
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCDwarfCallFrameFragment
modifier|&
name|DF
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// finishLayout - Finalize a layout, including fragment lowering.
end_comment

begin_function_decl
name|void
name|finishLayout
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|handleFixup
parameter_list|(
specifier|const
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCFragment
modifier|&
name|F
parameter_list|,
specifier|const
name|MCFixup
modifier|&
name|Fixup
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Compute the effective fragment size assuming it is laid out at the given
end_comment

begin_comment
comment|/// \p SectionAddress and \p FragmentOffset.
end_comment

begin_decl_stmt
name|uint64_t
name|computeFragmentSize
argument_list|(
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
specifier|const
name|MCFragment
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Find the symbol which defines the atom containing the given symbol, or
end_comment

begin_comment
comment|/// null if there is no such symbol.
end_comment

begin_decl_stmt
specifier|const
name|MCSymbolData
modifier|*
name|getAtom
argument_list|(
specifier|const
name|MCSymbolData
operator|*
name|Symbol
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check whether a particular symbol is visible to the linker and is required
end_comment

begin_comment
comment|/// in the symbol table, or whether it can be discarded by the assembler. This
end_comment

begin_comment
comment|/// also effects whether the assembler treats the label as potentially
end_comment

begin_comment
comment|/// defining a separate atom.
end_comment

begin_decl_stmt
name|bool
name|isSymbolLinkerVisible
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|SD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit the section contents using the given object writer.
end_comment

begin_decl_stmt
name|void
name|writeSectionData
argument_list|(
specifier|const
name|MCSectionData
operator|*
name|Section
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check whether a given symbol has been flagged with .thumb_func.
end_comment

begin_decl_stmt
name|bool
name|isThumbFunc
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Func
argument_list|)
decl|const
block|{
return|return
name|ThumbFuncs
operator|.
name|count
argument_list|(
name|Func
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Flag a function symbol as the target of a .thumb_func directive.
end_comment

begin_function
name|void
name|setIsThumbFunc
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Func
parameter_list|)
block|{
name|ThumbFuncs
operator|.
name|insert
argument_list|(
name|Func
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// ELF e_header flags
end_comment

begin_expr_stmt
name|unsigned
name|getELFHeaderEFlags
argument_list|()
specifier|const
block|{
return|return
name|ELFHeaderEFlags
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setELFHeaderEFlags
parameter_list|(
name|unsigned
name|Flags
parameter_list|)
block|{
name|ELFHeaderEFlags
operator|=
name|Flags
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Construct a new assembler instance.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OS The stream to output to.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: How are we going to parameterize this? Two obvious options are stay
end_comment

begin_comment
comment|// concrete and require clients to pass in a target like object. The other
end_comment

begin_comment
comment|// option is to make this abstract, and have targets provide concrete
end_comment

begin_comment
comment|// implementations as we do with AsmParser.
end_comment

begin_expr_stmt
name|MCAssembler
argument_list|(
name|MCContext
operator|&
name|Context_
argument_list|,
name|MCAsmBackend
operator|&
name|Backend_
argument_list|,
name|MCCodeEmitter
operator|&
name|Emitter_
argument_list|,
name|MCObjectWriter
operator|&
name|Writer_
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|MCAssembler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Reuse an assembler instance
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|MCAsmBackend
operator|&
name|getBackend
argument_list|()
specifier|const
block|{
return|return
name|Backend
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MCCodeEmitter
operator|&
name|getEmitter
argument_list|()
specifier|const
block|{
return|return
name|Emitter
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MCObjectWriter
operator|&
name|getWriter
argument_list|()
specifier|const
block|{
return|return
name|Writer
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Finish - Do final processing and write the object to the output stream.
end_comment

begin_comment
comment|/// \p Writer is used for custom object writer (as the MCJIT does),
end_comment

begin_comment
comment|/// if not specified it is automatically created from backend.
end_comment

begin_function_decl
name|void
name|Finish
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// FIXME: This does not belong here.
end_comment

begin_expr_stmt
name|bool
name|getSubsectionsViaSymbols
argument_list|()
specifier|const
block|{
return|return
name|SubsectionsViaSymbols
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|bool
name|getRelaxAll
argument_list|()
specifier|const
block|{
return|return
name|RelaxAll
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setRelaxAll
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|RelaxAll
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getNoExecStack
argument_list|()
specifier|const
block|{
return|return
name|NoExecStack
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNoExecStack
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|NoExecStack
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isBundlingEnabled
argument_list|()
specifier|const
block|{
return|return
name|BundleAlignSize
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getBundleAlignSize
argument_list|()
specifier|const
block|{
return|return
name|BundleAlignSize
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setBundleAlignSize
parameter_list|(
name|unsigned
name|Size
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|Size
operator|==
literal|0
operator|||
operator|!
operator|(
name|Size
operator|&
operator|(
name|Size
operator|-
literal|1
operator|)
operator|)
operator|)
operator|&&
literal|"Expect a power-of-two bundle align size"
argument_list|)
expr_stmt|;
name|BundleAlignSize
operator|=
name|Size
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @name Section List Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
name|SectionDataListType
modifier|&
name|getSectionList
parameter_list|()
block|{
return|return
name|Sections
return|;
block|}
end_function

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Symbol List Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
name|SymbolDataListType
modifier|&
name|getSymbolList
parameter_list|()
block|{
return|return
name|Symbols
return|;
block|}
end_function

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Indirect Symbol List Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// FIXME: This is a total hack, this should not be here. Once things are
end_comment

begin_comment
comment|// factored so that the streamer has direct access to the .o writer, it can
end_comment

begin_comment
comment|// disappear.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|const_indirect_symbol_iterator
name|indirect_symbol_begin
argument_list|()
specifier|const
block|{
return|return
name|IndirectSymbols
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|const_indirect_symbol_iterator
name|indirect_symbol_end
argument_list|()
specifier|const
block|{
return|return
name|IndirectSymbols
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Linker Option List Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
expr|>
operator|&
name|getLinkerOptions
argument_list|()
block|{
return|return
name|LinkerOptions
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Data Region List Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// FIXME: This is a total hack, this should not be here. Once things are
end_comment

begin_comment
comment|// factored so that the streamer has direct access to the .o writer, it can
end_comment

begin_comment
comment|// disappear.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DataRegionData
operator|>
operator|&
name|getDataRegions
argument_list|()
block|{
return|return
name|DataRegions
return|;
block|}
end_expr_stmt

begin_function
name|data_region_iterator
name|data_region_begin
parameter_list|()
block|{
return|return
name|DataRegions
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_data_region_iterator
name|data_region_begin
argument_list|()
specifier|const
block|{
return|return
name|DataRegions
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|data_region_iterator
name|data_region_end
parameter_list|()
block|{
return|return
name|DataRegions
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_data_region_iterator
name|data_region_end
argument_list|()
specifier|const
block|{
return|return
name|DataRegions
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_t
name|data_region_size
argument_list|()
specifier|const
block|{
return|return
name|DataRegions
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Backend Data Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_decl_stmt
name|MCSectionData
modifier|&
name|getSectionData
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|)
decl|const
block|{
name|MCSectionData
modifier|*
name|Entry
init|=
name|SectionMap
operator|.
name|lookup
argument_list|(
operator|&
name|Section
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Entry
operator|&&
literal|"Missing section data!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|Entry
return|;
block|}
end_decl_stmt

begin_function
name|MCSectionData
modifier|&
name|getOrCreateSectionData
parameter_list|(
specifier|const
name|MCSection
modifier|&
name|Section
parameter_list|,
name|bool
modifier|*
name|Created
init|=
literal|0
parameter_list|)
block|{
name|MCSectionData
modifier|*
modifier|&
name|Entry
init|=
name|SectionMap
index|[
operator|&
name|Section
index|]
decl_stmt|;
if|if
condition|(
name|Created
condition|)
operator|*
name|Created
operator|=
operator|!
name|Entry
expr_stmt|;
if|if
condition|(
operator|!
name|Entry
condition|)
name|Entry
operator|=
name|new
name|MCSectionData
argument_list|(
name|Section
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return
operator|*
name|Entry
return|;
block|}
end_function

begin_decl_stmt
name|MCSymbolData
modifier|&
name|getSymbolData
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
decl|const
block|{
name|MCSymbolData
modifier|*
name|Entry
init|=
name|SymbolMap
operator|.
name|lookup
argument_list|(
operator|&
name|Symbol
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Entry
operator|&&
literal|"Missing symbol data!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|Entry
return|;
block|}
end_decl_stmt

begin_function
name|MCSymbolData
modifier|&
name|getOrCreateSymbolData
parameter_list|(
specifier|const
name|MCSymbol
modifier|&
name|Symbol
parameter_list|,
name|bool
modifier|*
name|Created
init|=
literal|0
parameter_list|)
block|{
name|MCSymbolData
modifier|*
modifier|&
name|Entry
init|=
name|SymbolMap
index|[
operator|&
name|Symbol
index|]
decl_stmt|;
if|if
condition|(
name|Created
condition|)
operator|*
name|Created
operator|=
operator|!
name|Entry
expr_stmt|;
if|if
condition|(
operator|!
name|Entry
condition|)
name|Entry
operator|=
name|new
name|MCSymbolData
argument_list|(
name|Symbol
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return
operator|*
name|Entry
return|;
block|}
end_function

begin_expr_stmt
name|const_file_name_iterator
name|file_names_begin
argument_list|()
specifier|const
block|{
return|return
name|FileNames
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_file_name_iterator
name|file_names_end
argument_list|()
specifier|const
block|{
return|return
name|FileNames
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|addFileName
parameter_list|(
name|StringRef
name|FileName
parameter_list|)
block|{
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|file_names_begin
argument_list|()
argument_list|,
name|file_names_end
argument_list|()
argument_list|,
name|FileName
argument_list|)
operator|==
name|file_names_end
argument_list|()
condition|)
name|FileNames
operator|.
name|push_back
argument_list|(
name|FileName
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_function_decl
name|void
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

