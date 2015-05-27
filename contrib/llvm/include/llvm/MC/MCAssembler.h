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
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
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
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
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
file|"llvm/MC/MCLinkerOptimizationHint.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
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
name|MCSubtargetInfo
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
specifier|const
name|MCFragment
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MCFragment
operator|&
operator|)
operator|=
name|delete
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
comment|/// The data for the section this fragment is in.
name|MCSection
operator|*
name|Parent
block|;
comment|/// Atom - The atom this fragment is in, as represented by it's defining
comment|/// symbol.
specifier|const
name|MCSymbol
operator|*
name|Atom
block|;
comment|/// \name Assembler Backend Data
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
argument|FragmentType Kind
argument_list|,
argument|MCSection *Parent = nullptr
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
name|MCSection
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
argument|MCSection *Value
argument_list|)
block|{
name|Parent
operator|=
name|Value
block|; }
specifier|const
name|MCSymbol
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
argument|const MCSymbol *Value
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
block|{}
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
block|{}
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
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FType
argument_list|,
name|Sec
argument_list|)
block|,
name|BundlePadding
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|MCEncodedFragment
argument_list|()
name|override
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
name|uint8_t
name|getBundlePadding
argument_list|()
specifier|const
name|override
block|{
return|return
name|BundlePadding
return|;
block|}
name|void
name|setBundlePadding
argument_list|(
argument|uint8_t N
argument_list|)
name|override
block|{
name|BundlePadding
operator|=
name|N
block|; }
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
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|MCEncodedFragmentWithFixups
argument_list|(
argument|MCFragment::FragmentType FType
argument_list|,
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCEncodedFragment
argument_list|(
argument|FType
argument_list|,
argument|Sec
argument_list|)
block|{}
operator|~
name|MCEncodedFragmentWithFixups
argument_list|()
name|override
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
name|void
name|anchor
argument_list|()
name|override
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
name|MCSection
operator|*
name|Sec
operator|=
name|nullptr
argument_list|)
operator|:
name|MCEncodedFragmentWithFixups
argument_list|(
name|FT_Data
argument_list|,
name|Sec
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
block|{}
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
name|override
block|{
return|return
name|Contents
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
specifier|const
name|override
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
name|override
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
name|override
block|{
return|return
name|Fixups
return|;
block|}
name|bool
name|hasInstructions
argument_list|()
specifier|const
name|override
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
name|bool
name|alignToBundleEnd
argument_list|()
specifier|const
name|override
block|{
return|return
name|AlignToBundleEnd
return|;
block|}
name|void
name|setAlignToBundleEnd
argument_list|(
argument|bool V
argument_list|)
name|override
block|{
name|AlignToBundleEnd
operator|=
name|V
block|; }
name|fixup_iterator
name|fixup_begin
argument_list|()
name|override
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
name|override
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
name|override
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
name|override
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
name|void
name|anchor
argument_list|()
name|override
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
name|MCSection
operator|*
name|Sec
operator|=
name|nullptr
argument_list|)
operator|:
name|MCEncodedFragment
argument_list|(
name|FT_CompactEncodedInst
argument_list|,
name|Sec
argument_list|)
block|,
name|AlignToBundleEnd
argument_list|(
argument|false
argument_list|)
block|{   }
name|bool
name|hasInstructions
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
name|override
block|{
return|return
name|Contents
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
specifier|const
name|override
block|{
return|return
name|Contents
return|;
block|}
name|bool
name|alignToBundleEnd
argument_list|()
specifier|const
name|override
block|{
return|return
name|AlignToBundleEnd
return|;
block|}
name|void
name|setAlignToBundleEnd
argument_list|(
argument|bool V
argument_list|)
name|override
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
name|void
name|anchor
argument_list|()
name|override
block|;
comment|/// Inst - The instruction this is a fragment for.
name|MCInst
name|Inst
block|;
comment|/// STI - The MCSubtargetInfo in effect when the instruction was encoded.
comment|/// Keep a copy instead of a reference to make sure that updates to STI
comment|/// in the assembler are not seen here.
specifier|const
name|MCSubtargetInfo
name|STI
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
name|Inst
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCSection
operator|*
name|Sec
operator|=
name|nullptr
argument_list|)
operator|:
name|MCEncodedFragmentWithFixups
argument_list|(
name|FT_Relaxable
argument_list|,
name|Sec
argument_list|)
block|,
name|Inst
argument_list|(
name|Inst
argument_list|)
block|,
name|STI
argument_list|(
argument|STI
argument_list|)
block|{}
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
name|override
block|{
return|return
name|Contents
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|getContents
argument_list|()
specifier|const
name|override
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
argument|const MCInst&Value
argument_list|)
block|{
name|Inst
operator|=
name|Value
block|; }
specifier|const
name|MCSubtargetInfo
operator|&
name|getSubtargetInfo
argument_list|()
block|{
return|return
name|STI
return|;
block|}
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|getFixups
argument_list|()
name|override
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
name|override
block|{
return|return
name|Fixups
return|;
block|}
name|bool
name|hasInstructions
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|fixup_iterator
name|fixup_begin
argument_list|()
name|override
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
name|override
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
name|override
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
name|override
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
argument|unsigned Alignment
argument_list|,
argument|int64_t Value
argument_list|,
argument|unsigned ValueSize
argument_list|,
argument|unsigned MaxBytesToEmit
argument_list|,
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Align
argument_list|,
name|Sec
argument_list|)
block|,
name|Alignment
argument_list|(
name|Alignment
argument_list|)
block|,
name|Value
argument_list|(
name|Value
argument_list|)
block|,
name|ValueSize
argument_list|(
name|ValueSize
argument_list|)
block|,
name|MaxBytesToEmit
argument_list|(
name|MaxBytesToEmit
argument_list|)
block|,
name|EmitNops
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \name Accessors
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
argument|int64_t Value
argument_list|,
argument|unsigned ValueSize
argument_list|,
argument|uint64_t Size
argument_list|,
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Fill
argument_list|,
name|Sec
argument_list|)
block|,
name|Value
argument_list|(
name|Value
argument_list|)
block|,
name|ValueSize
argument_list|(
name|ValueSize
argument_list|)
block|,
name|Size
argument_list|(
argument|Size
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
comment|/// \name Accessors
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
argument|const MCExpr&Offset
argument_list|,
argument|int8_t Value
argument_list|,
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Org
argument_list|,
name|Sec
argument_list|)
block|,
name|Offset
argument_list|(
operator|&
name|Offset
argument_list|)
block|,
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
comment|/// \name Accessors
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
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_LEB
argument_list|,
name|Sec
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
block|;   }
comment|/// \name Accessors
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
argument|int64_t LineDelta
argument_list|,
argument|const MCExpr&AddrDelta
argument_list|,
argument|MCSection *Sec = nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_Dwarf
argument_list|,
name|Sec
argument_list|)
block|,
name|LineDelta
argument_list|(
name|LineDelta
argument_list|)
block|,
name|AddrDelta
argument_list|(
argument|&AddrDelta
argument_list|)
block|{
name|Contents
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|;   }
comment|/// \name Accessors
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
name|AddrDelta
argument_list|,
name|MCSection
operator|*
name|Sec
operator|=
name|nullptr
argument_list|)
operator|:
name|MCFragment
argument_list|(
name|FT_DwarfFrame
argument_list|,
name|Sec
argument_list|)
block|,
name|AddrDelta
argument_list|(
argument|&AddrDelta
argument_list|)
block|{
name|Contents
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|;   }
comment|/// \name Accessors
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
comment|// FIXME: This really doesn't belong here. See comments below.
block|struct
name|IndirectSymbolData
block|{
name|MCSymbol
operator|*
name|Symbol
block|;
name|MCSection
operator|*
name|Section
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
name|SetVector
operator|<
name|MCSection
operator|*
operator|>
name|SectionListType
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|MCSymbol
operator|*
operator|>
name|SymbolDataListType
expr_stmt|;
typedef|typedef
name|pointee_iterator
operator|<
name|SectionListType
operator|::
name|const_iterator
operator|>
name|const_iterator
expr_stmt|;
typedef|typedef
name|pointee_iterator
operator|<
name|SectionListType
operator|::
name|iterator
operator|>
name|iterator
expr_stmt|;
typedef|typedef
name|pointee_iterator
operator|<
name|SymbolDataListType
operator|::
name|const_iterator
operator|>
name|const_symbol_iterator
expr_stmt|;
typedef|typedef
name|pointee_iterator
operator|<
name|SymbolDataListType
operator|::
name|iterator
operator|>
name|symbol_iterator
expr_stmt|;
typedef|typedef
name|iterator_range
operator|<
name|symbol_iterator
operator|>
name|symbol_range
expr_stmt|;
typedef|typedef
name|iterator_range
operator|<
name|const_symbol_iterator
operator|>
name|const_symbol_range
expr_stmt|;
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
typedef|typedef
name|FileNameVectorType
operator|::
name|const_iterator
name|const_file_name_iterator
expr_stmt|;
end_decl_stmt

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

begin_comment
comment|/// MachO specific deployment target version info.
end_comment

begin_comment
comment|// A Major version of 0 indicates that no version information was supplied
end_comment

begin_comment
comment|// and so the corresponding load command should not be emitted.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MCVersionMinType
name|Kind
decl_stmt|;
name|unsigned
name|Major
decl_stmt|;
name|unsigned
name|Minor
decl_stmt|;
name|unsigned
name|Update
decl_stmt|;
block|}
name|VersionMinInfoType
typedef|;
end_typedef

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|MCAssembler
argument_list|(
specifier|const
name|MCAssembler
operator|&
argument_list|)
operator|=
name|delete
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
operator|=
name|delete
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

begin_decl_stmt
name|SectionListType
name|Sections
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SymbolDataListType
name|Symbols
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DenseSet
operator|<
specifier|const
name|MCSymbol
operator|*
operator|>
name|LocalsUsedInReloc
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
operator|>>
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
name|mutable
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

begin_comment
comment|/// Used to communicate Linker Optimization Hint information between
end_comment

begin_comment
comment|/// the Streamer and the .o writer
end_comment

begin_decl_stmt
name|MCLOHContainer
name|LOHContainer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VersionMinInfoType
name|VersionMinInfo
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
name|MCSection
modifier|&
name|Sec
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

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|bool
operator|>
name|handleFixup
argument_list|(
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
name|MCFragment
operator|&
name|F
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
name|void
name|addLocalUsedInReloc
parameter_list|(
specifier|const
name|MCSymbol
modifier|&
name|Sym
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|isLocalUsedInReloc
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Sym
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|MCSymbol
modifier|*
name|getAtom
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|S
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
name|MCSection
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
decl_stmt|;
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

begin_comment
comment|/// MachO deployment target version information.
end_comment

begin_expr_stmt
specifier|const
name|VersionMinInfoType
operator|&
name|getVersionMinInfo
argument_list|()
specifier|const
block|{
return|return
name|VersionMinInfo
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setVersionMinInfo
parameter_list|(
name|MCVersionMinType
name|Kind
parameter_list|,
name|unsigned
name|Major
parameter_list|,
name|unsigned
name|Minor
parameter_list|,
name|unsigned
name|Update
parameter_list|)
block|{
name|VersionMinInfo
operator|.
name|Kind
operator|=
name|Kind
expr_stmt|;
name|VersionMinInfo
operator|.
name|Major
operator|=
name|Major
expr_stmt|;
name|VersionMinInfo
operator|.
name|Minor
operator|=
name|Minor
expr_stmt|;
name|VersionMinInfo
operator|.
name|Update
operator|=
name|Update
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
comment|/// \name Section List Access
end_comment

begin_comment
comment|/// @{
end_comment

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
comment|/// \name Symbol List Access
end_comment

begin_comment
comment|/// @{
end_comment

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

begin_function
name|symbol_range
name|symbols
parameter_list|()
block|{
return|return
name|make_range
argument_list|(
name|symbol_begin
argument_list|()
argument_list|,
name|symbol_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_symbol_range
name|symbols
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|symbol_begin
argument_list|()
argument_list|,
name|symbol_end
argument_list|()
argument_list|)
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
comment|/// \name Indirect Symbol List Access
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
comment|/// \name Linker Option List Access
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
operator|>>
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
comment|/// \name Data Region List Access
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
comment|/// \name Data Region List Access
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

begin_function
name|MCLOHContainer
modifier|&
name|getLOHContainer
parameter_list|()
block|{
return|return
name|LOHContainer
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|MCLOHContainer
operator|&
name|getLOHContainer
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MCAssembler
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLOHContainer
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Backend Data Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_function
name|bool
name|registerSection
parameter_list|(
name|MCSection
modifier|&
name|Section
parameter_list|)
block|{
return|return
name|Sections
operator|.
name|insert
argument_list|(
operator|&
name|Section
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|bool
name|hasSymbolData
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
decl|const
block|{
return|return
name|Symbol
operator|.
name|hasData
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|MCSymbolData
modifier|&
name|getSymbolData
parameter_list|(
specifier|const
name|MCSymbol
modifier|&
name|Symbol
parameter_list|)
block|{
return|return
name|const_cast
operator|<
name|MCSymbolData
operator|&
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|MCAssembler
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
operator|.
name|getSymbolData
argument_list|(
name|Symbol
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|const
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
return|return
name|Symbol
operator|.
name|getData
argument_list|()
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
name|nullptr
parameter_list|)
block|{
if|if
condition|(
name|Created
condition|)
operator|*
name|Created
operator|=
operator|!
name|hasSymbolData
argument_list|(
name|Symbol
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasSymbolData
argument_list|(
name|Symbol
argument_list|)
condition|)
block|{
name|Symbol
operator|.
name|initializeData
argument_list|()
expr_stmt|;
name|Symbols
operator|.
name|push_back
argument_list|(
operator|&
name|Symbol
argument_list|)
expr_stmt|;
block|}
return|return
name|Symbol
operator|.
name|getData
argument_list|()
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
comment|/// \brief Write the necessary bundle padding to the given object writer.
end_comment

begin_comment
comment|/// Expects a fragment \p F containing instructions and its size \p FSize.
end_comment

begin_decl_stmt
name|void
name|writeFragmentPadding
argument_list|(
specifier|const
name|MCFragment
operator|&
name|F
argument_list|,
name|uint64_t
name|FSize
argument_list|,
name|MCObjectWriter
operator|*
name|OW
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
unit|};
comment|/// \brief Compute the amount of padding required before the fragment \p F to
end_comment

begin_comment
comment|/// obey bundling restrictions, where \p FOffset is the fragment's offset in
end_comment

begin_comment
comment|/// its section and \p FSize is the fragment's size.
end_comment

begin_function_decl
name|uint64_t
name|computeBundlePadding
parameter_list|(
specifier|const
name|MCAssembler
modifier|&
name|Assembler
parameter_list|,
specifier|const
name|MCFragment
modifier|*
name|F
parameter_list|,
name|uint64_t
name|FOffset
parameter_list|,
name|uint64_t
name|FSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

