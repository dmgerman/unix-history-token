begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCAsmLayout.h - Assembly Layout Object -------------------*- C++ -*-===//
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
name|LLVM_MC_MCASMLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMLAYOUT_H
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCFragment
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
comment|/// Encapsulates the layout of an assembly file at a particular point in time.
comment|///
comment|/// Assembly may require computing multiple layouts for a particular assembly
comment|/// file as part of the relaxation process. This class encapsulates the layout
comment|/// at a single point in time in such a way that it is always possible to
comment|/// efficiently compute the exact address of any symbol in the assembly file,
comment|/// even during the relaxation process.
name|class
name|MCAsmLayout
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|MCSectionData
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|MCSectionData
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|private
label|:
name|MCAssembler
modifier|&
name|Assembler
decl_stmt|;
comment|/// List of sections in layout order.
name|llvm
operator|::
name|SmallVector
operator|<
name|MCSectionData
operator|*
operator|,
literal|16
operator|>
name|SectionOrder
expr_stmt|;
comment|/// The last fragment which was laid out, or 0 if nothing has been laid
comment|/// out. Fragments are always laid out in order, so all fragments with a
comment|/// lower ordinal will be valid.
name|mutable
name|DenseMap
operator|<
specifier|const
name|MCSectionData
operator|*
operator|,
name|MCFragment
operator|*
operator|>
name|LastValidFragment
expr_stmt|;
comment|/// \brief Make sure that the layout for the given fragment is valid, lazily
comment|/// computing it if necessary.
name|void
name|ensureValid
argument_list|(
specifier|const
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Is the layout for this fragment valid?
name|bool
name|isFragmentValid
argument_list|(
specifier|const
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Compute the amount of padding required before this fragment to
comment|/// obey bundling restrictions.
name|uint64_t
name|computeBundlePadding
parameter_list|(
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
name|public
label|:
name|MCAsmLayout
argument_list|(
name|MCAssembler
operator|&
name|_Assembler
argument_list|)
expr_stmt|;
comment|/// Get the assembler object this is a layout for.
name|MCAssembler
operator|&
name|getAssembler
argument_list|()
specifier|const
block|{
return|return
name|Assembler
return|;
block|}
comment|/// \brief Invalidate the fragments starting with F because it has been
comment|/// resized. The fragment's size should have already been updated, but
comment|/// its bundle padding will be recomputed.
name|void
name|invalidateFragmentsFrom
parameter_list|(
name|MCFragment
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Perform layout for a single fragment, assuming that the previous
comment|/// fragment has already been laid out correctly, and the parent section has
comment|/// been initialized.
name|void
name|layoutFragment
parameter_list|(
name|MCFragment
modifier|*
name|Fragment
parameter_list|)
function_decl|;
comment|/// @name Section Access (in layout order)
comment|/// @{
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|MCSectionData
operator|*
operator|>
operator|&
name|getSectionOrder
argument_list|()
block|{
return|return
name|SectionOrder
return|;
block|}
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|MCSectionData
operator|*
operator|>
operator|&
name|getSectionOrder
argument_list|()
specifier|const
block|{
return|return
name|SectionOrder
return|;
block|}
comment|/// @}
comment|/// @name Fragment Layout Data
comment|/// @{
comment|/// \brief Get the offset of the given fragment inside its containing section.
name|uint64_t
name|getFragmentOffset
argument_list|(
specifier|const
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Utility Functions
comment|/// @{
comment|/// \brief Get the address space size of the given section, as it effects
comment|/// layout. This may differ from the size reported by \see getSectionSize() by
comment|/// not including section tail padding.
name|uint64_t
name|getSectionAddressSize
argument_list|(
specifier|const
name|MCSectionData
operator|*
name|SD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the data size of the given section, as emitted to the object
comment|/// file. This may include additional padding, or be 0 for virtual sections.
name|uint64_t
name|getSectionFileSize
argument_list|(
specifier|const
name|MCSectionData
operator|*
name|SD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the offset of the given symbol, as computed in the current
comment|/// layout.
comment|/// \result True on success.
name|bool
name|getSymbolOffset
argument_list|(
specifier|const
name|MCSymbolData
operator|*
name|SD
argument_list|,
name|uint64_t
operator|&
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Variant that reports a fatal error if the offset is not computable.
name|uint64_t
name|getSymbolOffset
argument_list|(
specifier|const
name|MCSymbolData
operator|*
name|SD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief If this symbol is equivalent to A + Constant, return A.
specifier|const
name|MCSymbol
modifier|*
name|getBaseSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

