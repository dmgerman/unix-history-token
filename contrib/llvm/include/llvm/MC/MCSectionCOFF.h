begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionCOFF.h - COFF Machine Code Sections -------------*- C++ -*-===//
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
comment|// This file declares the MCSectionCOFF class.
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
name|LLVM_MC_MCSECTIONCOFF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONCOFF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/COFF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCSectionCOFF - This represents a section on Windows
name|class
name|MCSectionCOFF
range|:
name|public
name|MCSection
block|{
comment|// The memory for this string is stored in the same MCContext as *this.
name|StringRef
name|SectionName
block|;
comment|/// Characteristics - This is the Characteristics field of a section,
comment|//  drawn from the enums below.
name|unsigned
name|Characteristics
block|;
comment|/// Selection - This is the Selection field for the section symbol, if
comment|/// it is a COMDAT section (Characteristics& IMAGE_SCN_LNK_COMDAT) != 0
name|int
name|Selection
block|;
name|private
operator|:
name|friend
name|class
name|MCContext
block|;
name|MCSectionCOFF
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned Characteristics
argument_list|,
argument|int Selection
argument_list|,
argument|SectionKind K
argument_list|)
operator|:
name|MCSection
argument_list|(
name|SV_COFF
argument_list|,
name|K
argument_list|)
block|,
name|SectionName
argument_list|(
name|Section
argument_list|)
block|,
name|Characteristics
argument_list|(
name|Characteristics
argument_list|)
block|,
name|Selection
argument_list|(
argument|Selection
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Characteristics
operator|&
literal|0x00F00000
operator|)
operator|==
literal|0
operator|&&
literal|"alignment must not be set upon section creation"
argument_list|)
block|;     }
operator|~
name|MCSectionCOFF
argument_list|()
block|;
name|public
operator|:
comment|/// ShouldOmitSectionDirective - Decides whether a '.section' directive
comment|/// should be printed before the section name
name|bool
name|ShouldOmitSectionDirective
argument_list|(
argument|StringRef Name
argument_list|,
argument|const MCAsmInfo&MAI
argument_list|)
specifier|const
block|;
name|StringRef
name|getSectionName
argument_list|()
specifier|const
block|{
return|return
name|SectionName
return|;
block|}
name|virtual
name|std
operator|::
name|string
name|getLabelBeginName
argument_list|()
specifier|const
block|{
return|return
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|"_begin"
return|;
block|}
name|virtual
name|std
operator|::
name|string
name|getLabelEndName
argument_list|()
specifier|const
block|{
return|return
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|"_end"
return|;
block|}
name|unsigned
name|getCharacteristics
argument_list|()
specifier|const
block|{
return|return
name|Characteristics
return|;
block|}
name|int
name|getSelection
argument_list|()
specifier|const
block|{
return|return
name|Selection
return|;
block|}
name|virtual
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|const MCExpr *Subsection
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isVirtualSection
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getVariant
argument_list|()
operator|==
name|SV_COFF
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

