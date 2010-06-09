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
file|"llvm/MC/MCSection.h"
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
comment|//FIXME: all COFF enumerations/flags should be standardized into one place...
comment|// Target/X86COFF.h doesn't seem right as COFF can be used for other targets,
comment|// MC/WinCOFF.h maybe right as it isn't target or entity specific, and it is
comment|//   pretty low on the dependancy graph (is there any need to support non
comment|//   windows COFF?)
comment|// here is good for section stuff, but others should go elsewhere
comment|/// Valid section flags.
block|enum
block|{
name|IMAGE_SCN_TYPE_NO_PAD
operator|=
literal|0x00000008
block|,
name|IMAGE_SCN_CNT_CODE
operator|=
literal|0x00000020
block|,
name|IMAGE_SCN_CNT_INITIALIZED_DATA
operator|=
literal|0x00000040
block|,
name|IMAGE_SCN_CNT_UNINITIALIZED_DATA
operator|=
literal|0x00000080
block|,
name|IMAGE_SCN_LNK_OTHER
operator|=
literal|0x00000100
block|,
name|IMAGE_SCN_LNK_INFO
operator|=
literal|0x00000200
block|,
name|IMAGE_SCN_LNK_REMOVE
operator|=
literal|0x00000800
block|,
name|IMAGE_SCN_LNK_COMDAT
operator|=
literal|0x00001000
block|,
name|IMAGE_SCN_MEM_FARDATA
operator|=
literal|0x00008000
block|,
name|IMAGE_SCN_MEM_PURGEABLE
operator|=
literal|0x00020000
block|,
name|IMAGE_SCN_MEM_16BIT
operator|=
literal|0x00020000
block|,
name|IMAGE_SCN_MEM_LOCKED
operator|=
literal|0x00040000
block|,
name|IMAGE_SCN_MEM_PRELOAD
operator|=
literal|0x00080000
block|,
comment|/* these are handled elsewhere       IMAGE_SCN_ALIGN_1BYTES                    = 0x00100000,       IMAGE_SCN_ALIGN_2BYTES                    = 0x00200000,       IMAGE_SCN_ALIGN_4BYTES                    = 0x00300000,       IMAGE_SCN_ALIGN_8BYTES                    = 0x00400000,       IMAGE_SCN_ALIGN_16BYTES                   = 0x00500000,       IMAGE_SCN_ALIGN_32BYTES                   = 0x00600000,       IMAGE_SCN_ALIGN_64BYTES                   = 0x00700000,       */
name|IMAGE_SCN_LNK_NRELOC_OVFL
operator|=
literal|0x01000000
block|,
name|IMAGE_SCN_MEM_DISCARDABLE
operator|=
literal|0x02000000
block|,
name|IMAGE_SCN_MEM_NOT_CACHED
operator|=
literal|0x04000000
block|,
name|IMAGE_SCN_MEM_NOT_PAGED
operator|=
literal|0x08000000
block|,
name|IMAGE_SCN_MEM_SHARED
operator|=
literal|0x10000000
block|,
name|IMAGE_SCN_MEM_EXECUTE
operator|=
literal|0x20000000
block|,
name|IMAGE_SCN_MEM_READ
operator|=
literal|0x40000000
block|,
name|IMAGE_SCN_MEM_WRITE
operator|=
literal|0x80000000
block|}
block|;      enum
block|{
name|IMAGE_COMDAT_SELECT_NODUPLICATES
operator|=
literal|1
block|,
name|IMAGE_COMDAT_SELECT_ANY
block|,
name|IMAGE_COMDAT_SELECT_SAME_SIZE
block|,
name|IMAGE_COMDAT_SELECT_EXACT_MATCH
block|,
name|IMAGE_COMDAT_SELECT_ASSOCIATIVE
block|,
name|IMAGE_COMDAT_SELECT_LARGEST
block|}
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
argument_list|)
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSectionCOFF *
argument_list|)
block|{
return|return
name|true
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

