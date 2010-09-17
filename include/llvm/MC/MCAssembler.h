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
name|MCAsmLayout
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCBinaryExpr
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
name|TargetAsmBackend
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
name|FT_Align
block|,
name|FT_Data
block|,
name|FT_Fill
block|,
name|FT_Inst
block|,
name|FT_Org
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
comment|/// EffectiveSize - The compute size of this section. This is ~0 until
comment|/// initialized.
name|uint64_t
name|EffectiveSize
block|;
comment|/// LayoutOrder - The global layout order of this fragment. This is the index
comment|/// across all fragments in the file, not just within the section.
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
name|void
name|dump
argument_list|()
block|; }
decl_stmt|;
name|class
name|MCDataFragment
range|:
name|public
name|MCFragment
block|{
name|SmallString
operator|<
literal|32
operator|>
name|Contents
block|;
comment|/// Fixups - The list of fixups in this fragment.
name|std
operator|::
name|vector
operator|<
name|MCFixup
operator|>
name|Fixups
block|;
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCFixup
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
name|MCFixup
operator|>
operator|::
name|iterator
name|fixup_iterator
expr_stmt|;
name|public
label|:
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
comment|/// @name Fixup Access
comment|/// @{
name|void
name|addFixup
parameter_list|(
name|MCFixup
name|Fixup
parameter_list|)
block|{
comment|// Enforce invariant that fixups are in offset order.
name|assert
argument_list|(
operator|(
name|Fixups
operator|.
name|empty
argument_list|()
operator|||
name|Fixup
operator|.
name|getOffset
argument_list|()
operator|>
name|Fixups
operator|.
name|back
argument_list|()
operator|.
name|getOffset
argument_list|()
operator|)
operator|&&
literal|"Fixups must be added in order!"
argument_list|)
expr_stmt|;
name|Fixups
operator|.
name|push_back
argument_list|(
name|Fixup
argument_list|)
expr_stmt|;
block|}
name|std
operator|::
name|vector
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
name|std
operator|::
name|vector
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
name|fixup_iterator
name|fixup_begin
parameter_list|()
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
parameter_list|()
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
parameter_list|(
specifier|const
name|MCDataFragment
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// FIXME: This current incarnation of MCInstFragment doesn't make much sense, as
end_comment

begin_comment
comment|// it is almost entirely a duplicate of MCDataFragment. If we decide to stick
end_comment

begin_comment
comment|// with this approach (as opposed to making MCInstFragment a very light weight
end_comment

begin_comment
comment|// object with just the MCInst and a code size, then we should just change
end_comment

begin_comment
comment|// MCDataFragment to have an optional MCInst at its end.
end_comment

begin_decl_stmt
name|class
name|MCInstFragment
range|:
name|public
name|MCFragment
block|{
comment|/// Inst - The instruction this is a fragment for.
name|MCInst
name|Inst
block|;
comment|/// Code - Binary data for the currently encoded instruction.
name|SmallString
operator|<
literal|8
operator|>
name|Code
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
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|::
name|const_iterator
name|const_fixup_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|::
name|iterator
name|fixup_iterator
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_macro
name|MCInstFragment
argument_list|(
argument|MCInst _Inst
argument_list|,
argument|MCSectionData *SD =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|MCFragment
argument_list|(
name|FT_Inst
argument_list|,
name|SD
argument_list|)
operator|,
name|Inst
argument_list|(
argument|_Inst
argument_list|)
block|{   }
comment|/// @name Accessors
comment|/// @{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getCode
argument_list|()
block|{
return|return
name|Code
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|Code
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getInstSize
argument_list|()
specifier|const
block|{
return|return
name|Code
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|MCInst
modifier|&
name|getInst
parameter_list|()
block|{
return|return
name|Inst
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setInst
parameter_list|(
name|MCInst
name|Value
parameter_list|)
block|{
name|Inst
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Fixup Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|fixup_iterator
name|fixup_begin
parameter_list|()
block|{
return|return
name|Fixups
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|fixup_iterator
name|fixup_end
parameter_list|()
block|{
return|return
name|Fixups
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_function
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
return|return
name|F
operator|->
name|getKind
argument_list|()
operator|==
name|MCFragment
operator|::
name|FT_Inst
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCInstFragment
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|class
name|MCAlignFragment
range|:
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
comment|/// EmitNops - Flag to indicate that (optimal) NOPs should be emitted instead
comment|/// of using the provided value. The exact interpretation of this flag is
comment|/// target dependent.
name|bool
name|EmitNops
operator|:
literal|1
block|;
comment|/// OnlyAlignAddress - Flag to indicate that this align is only used to adjust
comment|/// the address space size of a section and that it should not be included as
comment|/// part of the section size. This flag can only be used on the last fragment
comment|/// in a section.
name|bool
name|OnlyAlignAddress
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
name|false
argument_list|)
block|,
name|OnlyAlignAddress
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
name|bool
name|hasOnlyAlignAddress
argument_list|()
specifier|const
block|{
return|return
name|OnlyAlignAddress
return|;
block|}
name|void
name|setOnlyAlignAddress
argument_list|(
argument|bool Value
argument_list|)
block|{
name|OnlyAlignAddress
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
name|int64_t
name|Value
block|;
comment|/// ValueSize - The size (in bytes) of \arg Value to use when filling, or 0 if
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
end_decl_stmt

begin_typedef
typedef|typedef
name|FragmentListType
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|FragmentListType
name|Fragments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MCSection
modifier|*
name|Section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Ordinal - The section index in the assemblers section list.
end_comment

begin_decl_stmt
name|unsigned
name|Ordinal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LayoutOrder - The index of this section in the layout order.
end_comment

begin_decl_stmt
name|unsigned
name|LayoutOrder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Alignment - The maximum alignment seen in this section.
end_comment

begin_decl_stmt
name|unsigned
name|Alignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @name Assembler Backend Data
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This could all be kept private to the assembler implementation.
end_comment

begin_comment
comment|/// Address - The computed address of this section. This is ~0 until
end_comment

begin_comment
comment|/// initialized.
end_comment

begin_decl_stmt
name|uint64_t
name|Address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HasInstructions - Whether this section has had instructions emitted into
end_comment

begin_comment
comment|/// it.
end_comment

begin_decl_stmt
name|unsigned
name|HasInstructions
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|// Only for use as sentinel.
end_comment

begin_expr_stmt
name|MCSectionData
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setAlignment
parameter_list|(
name|unsigned
name|Value
parameter_list|)
block|{
name|Alignment
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|hasInstructions
argument_list|()
specifier|const
block|{
return|return
name|HasInstructions
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasInstructions
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|HasInstructions
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getOrdinal
argument_list|()
specifier|const
block|{
return|return
name|Ordinal
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setOrdinal
parameter_list|(
name|unsigned
name|Value
parameter_list|)
block|{
name|Ordinal
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getLayoutOrder
argument_list|()
specifier|const
block|{
return|return
name|LayoutOrder
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLayoutOrder
parameter_list|(
name|unsigned
name|Value
parameter_list|)
block|{
name|LayoutOrder
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @name Fragment Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
name|FragmentListType
modifier|&
name|getFragmentList
parameter_list|()
block|{
return|return
name|Fragments
return|;
block|}
end_function

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Fragments
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
name|Fragments
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
name|Fragments
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
name|Fragments
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|Fragments
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|Fragments
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|void
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|// FIXME: Same concerns as with SectionData.
end_comment

begin_decl_stmt
name|class
name|MCSymbolData
range|:
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: This really doesn't belong here. See comments below.
end_comment

begin_struct
struct|struct
name|IndirectSymbolData
block|{
name|MCSymbol
modifier|*
name|Symbol
decl_stmt|;
name|MCSectionData
modifier|*
name|SectionData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|MCAssembler
block|{
name|friend
name|class
name|MCAsmLayout
decl_stmt|;
name|public
label|:
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
name|const_iterator
name|const_indirect_symbol_iterator
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
name|TargetAsmBackend
modifier|&
name|Backend
decl_stmt|;
name|MCCodeEmitter
modifier|&
name|Emitter
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
comment|/// The map of sections to their associated assembler backend data.
comment|//
comment|// FIXME: Avoid this indirection?
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
comment|/// The map of symbols to their associated assembler backend data.
comment|//
comment|// FIXME: Avoid this indirection?
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
name|std
operator|::
name|vector
operator|<
name|IndirectSymbolData
operator|>
name|IndirectSymbols
expr_stmt|;
name|unsigned
name|RelaxAll
range|:
literal|1
decl_stmt|;
name|unsigned
name|SubsectionsViaSymbols
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|/// Evaluate a fixup to a relocatable expression and the value which should be
comment|/// placed into the fixup.
comment|///
comment|/// \param Layout The layout to use for evaluation.
comment|/// \param Fixup The fixup to evaluate.
comment|/// \param DF The fragment the fixup is inside.
comment|/// \param Target [out] On return, the relocatable expression the fixup
comment|/// evaluates to.
comment|/// \param Value [out] On return, the value of the fixup as currently layed
comment|/// out.
comment|/// \return Whether the fixup value was fully resolved. This is true if the
comment|/// \arg Value result is fixed, otherwise the value may change due to
comment|/// relocation.
name|bool
name|EvaluateFixup
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
comment|/// Check whether a fixup can be satisfied, or whether it needs to be relaxed
comment|/// (increased in size, in order to hold its value correctly).
name|bool
name|FixupNeedsRelaxation
argument_list|(
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
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// Check whether the given fragment needs relaxation.
name|bool
name|FragmentNeedsRelaxation
argument_list|(
specifier|const
name|MCInstFragment
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
comment|/// Compute the effective fragment size assuming it is layed out at the given
comment|/// \arg SectionAddress and \arg FragmentOffset.
name|uint64_t
name|ComputeFragmentSize
argument_list|(
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
specifier|const
name|MCFragment
operator|&
name|F
argument_list|,
name|uint64_t
name|SectionAddress
argument_list|,
name|uint64_t
name|FragmentOffset
argument_list|)
decl|const
decl_stmt|;
comment|/// LayoutOnce - Perform one layout iteration and return true if any offsets
comment|/// were adjusted.
name|bool
name|LayoutOnce
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|)
function_decl|;
comment|/// FinishLayout - Finalize a layout, including fragment lowering.
name|void
name|FinishLayout
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Find the symbol which defines the atom containing the given symbol, or
comment|/// null if there is no such symbol.
specifier|const
name|MCSymbolData
modifier|*
name|getAtom
argument_list|(
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
specifier|const
name|MCSymbolData
operator|*
name|Symbol
argument_list|)
decl|const
decl_stmt|;
comment|/// Check whether a particular symbol is visible to the linker and is required
comment|/// in the symbol table, or whether it can be discarded by the assembler. This
comment|/// also effects whether the assembler treats the label as potentially
comment|/// defining a separate atom.
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
comment|/// Emit the section contents using the given object writer.
comment|//
comment|// FIXME: Should MCAssembler always have a reference to the object writer?
name|void
name|WriteSectionData
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
argument_list|,
name|MCObjectWriter
operator|*
name|OW
argument_list|)
decl|const
decl_stmt|;
name|void
name|AddSectionToTheEnd
parameter_list|(
name|MCSectionData
modifier|&
name|SD
parameter_list|,
name|MCAsmLayout
modifier|&
name|Layout
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
name|TargetAsmBackend
operator|&
name|_Backend
argument_list|,
name|MCCodeEmitter
operator|&
name|_Emitter
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
name|TargetAsmBackend
operator|&
name|getBackend
argument_list|()
specifier|const
block|{
return|return
name|Backend
return|;
block|}
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
comment|/// Finish - Do final processing and write the object to the output stream.
comment|/// \arg Writer is used for custom object writer (as the MCJIT does),
comment|/// if not specified it is automatically created from backend.
name|void
name|Finish
parameter_list|(
name|MCObjectWriter
modifier|*
name|Writer
init|=
literal|0
parameter_list|)
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
name|bool
name|getRelaxAll
argument_list|()
specifier|const
block|{
return|return
name|RelaxAll
return|;
block|}
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
comment|/// @name Backend Data Access
comment|/// @{
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
comment|/// @}
name|void
name|dump
parameter_list|()
function_decl|;
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

