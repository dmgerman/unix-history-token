begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionPIC16.h - PIC16-specific section representation -*- C++ -*-===//
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
comment|// This file declares the MCSectionPIC16 class.
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
name|LLVM_PIC16SECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PIC16SECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCSectionPIC16 - Represents a physical section in PIC16 COFF.
comment|/// Contains data objects.
comment|///
name|class
name|MCSectionPIC16
range|:
name|public
name|MCSection
block|{
comment|/// Name of the section to uniquely identify it.
name|std
operator|::
name|string
name|Name
block|;
comment|/// User can specify an address at which a section should be placed.
comment|/// Negative value here means user hasn't specified any.
name|int
name|Address
block|;
comment|/// Overlay information - Sections with same color can be overlaid on
comment|/// one another.
name|int
name|Color
block|;
comment|/// Conatined data objects.
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|Items
block|;
comment|/// Total size of all data objects contained here.
name|unsigned
name|Size
block|;
name|MCSectionPIC16
argument_list|(
argument|const StringRef&name
argument_list|,
argument|SectionKind K
argument_list|,
argument|int addr
argument_list|,
argument|int color
argument_list|)
operator|:
name|MCSection
argument_list|(
name|K
argument_list|)
block|,
name|Name
argument_list|(
name|name
argument_list|)
block|,
name|Address
argument_list|(
name|addr
argument_list|)
block|,
name|Color
argument_list|(
argument|color
argument_list|)
block|{     }
name|public
operator|:
comment|/// Return the name of the section.
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// Return the Address of the section.
name|int
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// Return the Color of the section.
name|int
name|getColor
argument_list|()
specifier|const
block|{
return|return
name|Color
return|;
block|}
comment|/// PIC16 Terminology for section kinds is as below.
comment|/// UDATA - BSS
comment|/// IDATA - initialized data (equiv to Metadata)
comment|/// ROMDATA - ReadOnly.
comment|/// UDATA_OVR - Sections that can be overlaid. Section of such type is
comment|///             used to contain function autos an frame. We can think of
comment|///             it as equiv to llvm ThreadBSS)
comment|/// So, let's have some convenience functions to Map PIC16 Section types
comment|/// to SectionKind just for the sake of better readability.
specifier|static
name|SectionKind
name|UDATA_Kind
argument_list|()
block|{
return|return
name|SectionKind
operator|::
name|getBSS
argument_list|()
return|;
block|}
specifier|static
name|SectionKind
name|IDATA_Kind
argument_list|()
block|{
return|return
name|SectionKind
operator|::
name|getMetadata
argument_list|()
return|;
block|}
specifier|static
name|SectionKind
name|ROMDATA_Kind
argument_list|()
block|{
return|return
name|SectionKind
operator|::
name|getReadOnly
argument_list|()
return|;
block|}
specifier|static
name|SectionKind
name|UDATA_OVR_Kind
argument_list|()
block|{
return|return
name|SectionKind
operator|::
name|getThreadBSS
argument_list|()
return|;
block|}
comment|// If we could just do getKind() == UDATA_Kind() ?
name|bool
name|isUDATA_Kind
argument_list|()
block|{
return|return
name|getKind
argument_list|()
operator|.
name|isBSS
argument_list|()
return|;
block|}
name|bool
name|isIDATA_Kind
argument_list|()
block|{
return|return
name|getKind
argument_list|()
operator|.
name|isMetadata
argument_list|()
return|;
block|}
name|bool
name|isROMDATA_Kind
argument_list|()
block|{
return|return
name|getKind
argument_list|()
operator|.
name|isMetadata
argument_list|()
return|;
block|}
name|bool
name|isUDATA_OVR_Kind
argument_list|()
block|{
return|return
name|getKind
argument_list|()
operator|.
name|isThreadBSS
argument_list|()
return|;
block|}
comment|/// This would be the only way to create a section.
specifier|static
name|MCSectionPIC16
operator|*
name|Create
argument_list|(
argument|const StringRef&Name
argument_list|,
argument|SectionKind K
argument_list|,
argument|int Address
argument_list|,
argument|int Color
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// Override this as PIC16 has its own way of printing switching
comment|/// to a section.
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;   }
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

end_unit

