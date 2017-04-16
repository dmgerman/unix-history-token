begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionWasm.h - Wasm Machine Code Sections -------------*- C++ -*-===//
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
comment|// This file declares the MCSectionWasm class.
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
name|LLVM_MC_MCSECTIONWASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONWASM_H
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
file|"llvm/MC/MCSymbolWasm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
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
comment|/// This represents a section on wasm.
name|class
name|MCSectionWasm
name|final
range|:
name|public
name|MCSection
block|{
comment|/// This is the name of the section.  The referenced memory is owned by
comment|/// TargetLoweringObjectFileWasm's WasmUniqueMap.
name|StringRef
name|SectionName
block|;
comment|/// This is the sh_type field of a section, drawn from the enums below.
name|unsigned
name|Type
block|;
comment|/// This is the sh_flags field of a section, drawn from the enums below.
name|unsigned
name|Flags
block|;
name|unsigned
name|UniqueID
block|;
specifier|const
name|MCSymbolWasm
operator|*
name|Group
block|;
comment|// The offset of the MC function section in the wasm code section.
name|uint64_t
name|SectionOffset
block|;
name|private
operator|:
name|friend
name|class
name|MCContext
block|;
name|MCSectionWasm
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned type
argument_list|,
argument|unsigned flags
argument_list|,
argument|SectionKind K
argument_list|,
argument|const MCSymbolWasm *group
argument_list|,
argument|unsigned UniqueID
argument_list|,
argument|MCSymbol *Begin
argument_list|)
operator|:
name|MCSection
argument_list|(
name|SV_Wasm
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
name|UniqueID
argument_list|(
name|UniqueID
argument_list|)
block|,
name|Group
argument_list|(
name|group
argument_list|)
block|,
name|SectionOffset
argument_list|(
literal|0
argument_list|)
block|{   }
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
operator|~
name|MCSectionWasm
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
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|void
name|setFlags
argument_list|(
argument|unsigned F
argument_list|)
block|{
name|Flags
operator|=
name|F
block|; }
specifier|const
name|MCSymbolWasm
operator|*
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|Group
return|;
block|}
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
name|bool
name|isUnique
argument_list|()
specifier|const
block|{
return|return
name|UniqueID
operator|!=
operator|~
literal|0U
return|;
block|}
name|unsigned
name|getUniqueID
argument_list|()
specifier|const
block|{
return|return
name|UniqueID
return|;
block|}
name|uint64_t
name|getSectionOffset
argument_list|()
specifier|const
block|{
return|return
name|SectionOffset
return|;
block|}
name|void
name|setSectionOffset
argument_list|(
argument|uint64_t Offset
argument_list|)
block|{
name|SectionOffset
operator|=
name|Offset
block|; }
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
name|SV_Wasm
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

