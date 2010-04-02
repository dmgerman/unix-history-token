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
name|MCSymbolData
decl_stmt|;
comment|/// Encapsulates the layout of an assembly file at a particular point in time.
comment|///
comment|/// Assembly may requiring compute multiple layouts for a particular assembly
comment|/// file as part of the relaxation process. This class encapsulates the layout
comment|/// at a single point in time in such a way that it is always possible to
comment|/// efficiently compute the exact addresses of any symbol in the assembly file,
comment|/// even during the relaxation process.
name|class
name|MCAsmLayout
block|{
name|private
label|:
name|MCAssembler
modifier|&
name|Assembler
decl_stmt|;
name|public
label|:
name|MCAsmLayout
argument_list|(
name|MCAssembler
operator|&
name|_Assembler
argument_list|)
operator|:
name|Assembler
argument_list|(
argument|_Assembler
argument_list|)
block|{}
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
comment|/// \brief Update the layout because a fragment has been resized. The
comment|/// fragments size should have already been updated, the \arg SlideAmount is
comment|/// the delta from the old size.
name|void
name|UpdateForSlide
parameter_list|(
name|MCFragment
modifier|*
name|F
parameter_list|,
name|int
name|SlideAmount
parameter_list|)
function_decl|;
comment|/// @name Fragment Layout Data
comment|/// @{
comment|/// \brief Get the effective size of the given fragment, as computed in the
comment|/// current layout.
name|uint64_t
name|getFragmentEffectiveSize
argument_list|(
specifier|const
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set the effective size of the given fragment.
name|void
name|setFragmentEffectiveSize
parameter_list|(
name|MCFragment
modifier|*
name|F
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
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
comment|/// \brief Set the offset of the given fragment inside its containing section.
name|void
name|setFragmentOffset
parameter_list|(
name|MCFragment
modifier|*
name|F
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Section Layout Data
comment|/// @{
comment|/// \brief Get the computed address of the given section.
name|uint64_t
name|getSectionAddress
argument_list|(
specifier|const
name|MCSectionData
operator|*
name|SD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set the computed address of the given section.
name|void
name|setSectionAddress
parameter_list|(
name|MCSectionData
modifier|*
name|SD
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
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
comment|/// \brief Set the data size of the given section.
name|void
name|setSectionFileSize
parameter_list|(
name|MCSectionData
modifier|*
name|SD
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Get the actual data size of the given section.
name|uint64_t
name|getSectionSize
argument_list|(
specifier|const
name|MCSectionData
operator|*
name|SD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set the actual data size of the given section.
name|void
name|setSectionSize
parameter_list|(
name|MCSectionData
modifier|*
name|SD
parameter_list|,
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Utility Functions
comment|/// @{
comment|/// \brief Get the address of the given fragment, as computed in the current
comment|/// layout.
name|uint64_t
name|getFragmentAddress
argument_list|(
specifier|const
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the address of the given symbol, as computed in the current
comment|/// layout.
name|uint64_t
name|getSymbolAddress
argument_list|(
specifier|const
name|MCSymbolData
operator|*
name|SD
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

