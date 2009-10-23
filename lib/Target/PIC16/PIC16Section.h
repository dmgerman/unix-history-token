begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PIC16Section.h - PIC16-specific section representation -*- C++ -*-===//
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
comment|// This file declares the PIC16Section class.
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

begin_include
include|#
directive|include
file|"llvm/GlobalVariable.h"
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
comment|/// PIC16Section - Represents a physical section in PIC16 COFF.
comment|/// Contains data objects.
comment|///
name|class
name|PIC16Section
range|:
name|public
name|MCSection
block|{
comment|/// PIC16 Sections does not really use the SectionKind class to
comment|/// to distinguish between various types of sections. PIC16 maintain
comment|/// its own Section Type info. See the PIC16SectionType enum in PIC16.h
comment|/// for various section types.
name|PIC16SectionType
name|T
block|;
comment|/// Name of the section to uniquely identify it.
name|std
operator|::
name|string
name|Name
block|;
comment|/// User can specify an address at which a section should be placed.
comment|/// Negative value here means user hasn't specified any.
name|std
operator|::
name|string
name|Address
block|;
comment|/// Overlay information - Sections with same color can be overlaid on
comment|/// one another.
name|int
name|Color
block|;
comment|/// Total size of all data objects contained here.
name|unsigned
name|Size
block|;
name|PIC16Section
argument_list|(
argument|const StringRef&name
argument_list|,
argument|SectionKind K
argument_list|,
argument|const std::string&addr
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
specifier|const
name|std
operator|::
name|string
operator|&
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
name|void
name|setColor
argument_list|(
argument|int color
argument_list|)
block|{
name|Color
operator|=
name|color
block|; }
comment|/// Return the size of the section.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|void
name|setSize
argument_list|(
argument|unsigned size
argument_list|)
block|{
name|Size
operator|=
name|size
block|; }
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
comment|/// Check section type.
name|bool
name|isUDATA_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|UDATA
return|;
block|}
name|bool
name|isIDATA_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|IDATA
return|;
block|}
name|bool
name|isROMDATA_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|ROMDATA
return|;
block|}
name|bool
name|isUDATA_OVR_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|UDATA_OVR
return|;
block|}
name|bool
name|isUDATA_SHR_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|UDATA_SHR
return|;
block|}
name|bool
name|isCODE_Type
argument_list|()
specifier|const
block|{
return|return
name|T
operator|==
name|CODE
return|;
block|}
name|PIC16SectionType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|T
return|;
block|}
comment|/// This would be the only way to create a section.
specifier|static
name|PIC16Section
operator|*
name|Create
argument_list|(
argument|const StringRef&Name
argument_list|,
argument|PIC16SectionType Ty
argument_list|,
argument|const std::string&Address
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

