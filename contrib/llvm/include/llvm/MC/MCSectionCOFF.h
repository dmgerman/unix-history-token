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
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
comment|/// This represents a section on Windows
name|class
name|MCSectionCOFF
name|final
range|:
name|public
name|MCSection
block|{
comment|// The memory for this string is stored in the same MCContext as *this.
name|StringRef
name|SectionName
block|;
comment|// FIXME: The following fields should not be mutable, but are for now so the
comment|// asm parser can honor the .linkonce directive.
comment|/// This is the Characteristics field of a section, drawn from the enums
comment|/// below.
name|mutable
name|unsigned
name|Characteristics
block|;
comment|/// The unique IDs used with the .pdata and .xdata sections created internally
comment|/// by the assembler. This ID is used to ensure that for every .text section,
comment|/// there is exactly one .pdata and one .xdata section, which is required by
comment|/// the Microsoft incremental linker. This data is mutable because this ID is
comment|/// not notionally part of the section.
name|mutable
name|unsigned
name|WinCFISectionID
operator|=
operator|~
literal|0U
block|;
comment|/// The COMDAT symbol of this section. Only valid if this is a COMDAT section.
comment|/// Two COMDAT sections are merged if they have the same COMDAT symbol.
name|MCSymbol
operator|*
name|COMDATSymbol
block|;
comment|/// This is the Selection field for the section symbol, if it is a COMDAT
comment|/// section (Characteristics& IMAGE_SCN_LNK_COMDAT) != 0
name|mutable
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
argument|MCSymbol *COMDATSymbol
argument_list|,
argument|int Selection
argument_list|,
argument|SectionKind K
argument_list|,
argument|MCSymbol *Begin
argument_list|)
operator|:
name|MCSection
argument_list|(
name|SV_COFF
argument_list|,
name|K
argument_list|,
name|Begin
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
name|COMDATSymbol
argument_list|(
name|COMDATSymbol
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
block|;   }
name|public
operator|:
operator|~
name|MCSectionCOFF
argument_list|()
block|;
comment|/// Decides whether a '.section' directive should be printed before the
comment|/// section name
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
name|unsigned
name|getCharacteristics
argument_list|()
specifier|const
block|{
return|return
name|Characteristics
return|;
block|}
name|MCSymbol
operator|*
name|getCOMDATSymbol
argument_list|()
specifier|const
block|{
return|return
name|COMDATSymbol
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
name|void
name|setSelection
argument_list|(
argument|int Selection
argument_list|)
specifier|const
block|;
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|const Triple&T
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|const MCExpr *Subsection
argument_list|)
specifier|const
name|override
block|;
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isVirtualSection
argument_list|()
specifier|const
name|override
block|;
name|unsigned
name|getOrAssignWinCFISectionID
argument_list|(
argument|unsigned *NextID
argument_list|)
specifier|const
block|{
if|if
condition|(
name|WinCFISectionID
operator|==
operator|~
literal|0U
condition|)
name|WinCFISectionID
operator|=
operator|(
operator|*
name|NextID
operator|)
operator|++
expr_stmt|;
return|return
name|WinCFISectionID
return|;
block|}
specifier|static
name|bool
name|isImplicitlyDiscardable
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
return|return
name|Name
operator|.
name|startswith
argument_list|(
literal|".debug"
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|S
parameter_list|)
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

begin_comment
comment|// LLVM_MC_MCSECTIONCOFF_H
end_comment

end_unit

