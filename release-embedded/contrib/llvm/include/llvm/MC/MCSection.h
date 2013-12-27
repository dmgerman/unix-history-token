begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSection.h - Machine Code Sections ----------------------*- C++ -*-===//
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
comment|// This file declares the MCSection class.
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
name|LLVM_MC_MCSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCSection - Instances of this class represent a uniqued identifier for a
comment|/// section in the current translation unit.  The MCContext class uniques and
comment|/// creates these.
name|class
name|MCSection
block|{
name|public
label|:
enum|enum
name|SectionVariant
block|{
name|SV_COFF
init|=
literal|0
block|,
name|SV_ELF
block|,
name|SV_MachO
block|}
enum|;
name|private
label|:
name|MCSection
argument_list|(
argument|const MCSection&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MCSection
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
name|MCSection
argument_list|(
argument|SectionVariant V
argument_list|,
argument|SectionKind K
argument_list|)
block|:
name|Variant
argument_list|(
name|V
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K
argument_list|)
block|{}
name|SectionVariant
name|Variant
expr_stmt|;
name|SectionKind
name|Kind
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCSection
argument_list|()
expr_stmt|;
name|SectionKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|SectionVariant
name|getVariant
argument_list|()
specifier|const
block|{
return|return
name|Variant
return|;
block|}
name|virtual
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
init|=
literal|0
decl_stmt|;
comment|// Convenience routines to get label names for the beginning/end of a
comment|// section.
name|virtual
name|std
operator|::
name|string
name|getLabelBeginName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|getLabelEndName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isBaseAddressKnownZero - Return true if we know that this section will
comment|/// get a base address of zero.  In cases where we know that this is true we
comment|/// can emit section offsets as direct references to avoid a subtraction
comment|/// from the base of the section, saving a relocation.
name|virtual
name|bool
name|isBaseAddressKnownZero
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// UseCodeAlign - Return true if a .align directive should use
comment|// "optimized nops" to fill instead of 0s.
name|virtual
name|bool
name|UseCodeAlign
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isVirtualSection - Check whether this section is "virtual", that is
comment|/// has no actual object file contents.
name|virtual
name|bool
name|isVirtualSection
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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

