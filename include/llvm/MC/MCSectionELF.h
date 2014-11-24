begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionELF.h - ELF Machine Code Sections ---------------*- C++ -*-===//
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
comment|// This file declares the MCSectionELF class.
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
name|LLVM_MC_MCSECTIONELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
comment|/// MCSectionELF - This represents a section on linux, lots of unix variants
comment|/// and some bare metal systems.
name|class
name|MCSectionELF
range|:
name|public
name|MCSection
block|{
comment|/// SectionName - This is the name of the section.  The referenced memory is
comment|/// owned by TargetLoweringObjectFileELF's ELFUniqueMap.
name|StringRef
name|SectionName
block|;
comment|/// Type - This is the sh_type field of a section, drawn from the enums below.
name|unsigned
name|Type
block|;
comment|/// Flags - This is the sh_flags field of a section, drawn from the enums.
comment|/// below.
name|unsigned
name|Flags
block|;
comment|/// EntrySize - The size of each entry in this section. This size only
comment|/// makes sense for sections that contain fixed-sized entries. If a
comment|/// section does not contain fixed-sized entries 'EntrySize' will be 0.
name|unsigned
name|EntrySize
block|;
specifier|const
name|MCSymbol
operator|*
name|Group
block|;
name|private
operator|:
name|friend
name|class
name|MCContext
block|;
name|MCSectionELF
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned type
argument_list|,
argument|unsigned flags
argument_list|,
argument|SectionKind K
argument_list|,
argument|unsigned entrySize
argument_list|,
argument|const MCSymbol *group
argument_list|)
operator|:
name|MCSection
argument_list|(
name|SV_ELF
argument_list|,
name|K
argument_list|)
block|,
name|SectionName
argument_list|(
name|Section
argument_list|)
block|,
name|Type
argument_list|(
name|type
argument_list|)
block|,
name|Flags
argument_list|(
name|flags
argument_list|)
block|,
name|EntrySize
argument_list|(
name|entrySize
argument_list|)
block|,
name|Group
argument_list|(
argument|group
argument_list|)
block|{}
operator|~
name|MCSectionELF
argument_list|()
block|;
name|void
name|setSectionName
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|SectionName
operator|=
name|Name
block|; }
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
name|std
operator|::
name|string
name|getLabelBeginName
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|Group
condition|)
return|return
operator|(
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|'_'
operator|+
name|Group
operator|->
name|getName
argument_list|()
operator|+
literal|"_begin"
operator|)
operator|.
name|str
argument_list|()
return|;
return|return
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|"_begin"
return|;
block|}
name|std
operator|::
name|string
name|getLabelEndName
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|Group
condition|)
return|return
operator|(
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|'_'
operator|+
name|Group
operator|->
name|getName
argument_list|()
operator|+
literal|"_end"
operator|)
operator|.
name|str
argument_list|()
return|;
return|return
name|SectionName
operator|.
name|str
argument_list|()
operator|+
literal|"_end"
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getEntrySize
argument_list|()
specifier|const
block|{
return|return
name|EntrySize
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|MCSymbol
operator|*
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|Group
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|PrintSwitchToSection
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Subsection
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isVirtualSection
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isBaseAddressKnownZero - We know that non-allocatable sections (like
end_comment

begin_comment
comment|/// debug info) have a base of zero.
end_comment

begin_expr_stmt
name|bool
name|isBaseAddressKnownZero
argument_list|()
specifier|const
name|override
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|ELF
operator|::
name|SHF_ALLOC
operator|)
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_function
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
name|SV_ELF
return|;
block|}
end_function

begin_comment
comment|// Return the entry size for sections with fixed-width data.
end_comment

begin_function_decl
specifier|static
name|unsigned
name|DetermineEntrySize
parameter_list|(
name|SectionKind
name|Kind
parameter_list|)
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

