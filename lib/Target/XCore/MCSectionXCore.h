begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionXCore.h - XCore-specific section representation -*- C++ -*-===//
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
comment|// This file declares the MCSectionXCore class.
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
name|LLVM_MCSECTION_XCORE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MCSECTION_XCORE_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSectionELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSectionXCore
range|:
name|public
name|MCSectionELF
block|{
name|MCSectionXCore
argument_list|(
argument|const StringRef&Section
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Flags
argument_list|,
argument|SectionKind K
argument_list|,
argument|bool isExplicit
argument_list|)
operator|:
name|MCSectionELF
argument_list|(
argument|Section
argument_list|,
argument|Type
argument_list|,
argument|Flags
argument_list|,
argument|K
argument_list|,
argument|isExplicit
argument_list|)
block|{}
name|public
operator|:
expr|enum
block|{
comment|/// SHF_CP_SECTION - All sections with the "c" flag are grouped together
comment|/// by the linker to form the constant pool and the cp register is set to
comment|/// the start of the constant pool by the boot code.
name|SHF_CP_SECTION
operator|=
name|FIRST_TARGET_DEP_FLAG
block|,
comment|/// SHF_DP_SECTION - All sections with the "d" flag are grouped together
comment|/// by the linker to form the data section and the dp register is set to
comment|/// the start of the section by the boot code.
name|SHF_DP_SECTION
operator|=
name|FIRST_TARGET_DEP_FLAG
operator|<<
literal|1
block|}
block|;
specifier|static
name|MCSectionXCore
operator|*
name|Create
argument_list|(
argument|const StringRef&Section
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Flags
argument_list|,
argument|SectionKind K
argument_list|,
argument|bool isExplicit
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// PrintTargetSpecificSectionFlags - This handles the XCore-specific cp/dp
comment|/// section flags.
name|virtual
name|void
name|PrintTargetSpecificSectionFlags
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;  }
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

