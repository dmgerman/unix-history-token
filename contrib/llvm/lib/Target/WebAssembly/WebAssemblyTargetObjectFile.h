begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WebAssemblyTargetObjectFile.h - WebAssembly Object Info -*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares the WebAssembly-specific subclass of
end_comment

begin_comment
comment|/// TargetLoweringObjectFile.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYTARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYTARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|WebAssemblyTargetObjectFile
name|final
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|public
operator|:
name|WebAssemblyTargetObjectFile
argument_list|()
block|{
name|TextSection
operator|=
name|nullptr
block|;
name|DataSection
operator|=
name|nullptr
block|;
name|BSSSection
operator|=
name|nullptr
block|;
name|ReadOnlySection
operator|=
name|nullptr
block|;
name|StaticCtorSection
operator|=
name|nullptr
block|;
name|StaticDtorSection
operator|=
name|nullptr
block|;
name|LSDASection
operator|=
name|nullptr
block|;
name|EHFrameSection
operator|=
name|nullptr
block|;
name|DwarfAbbrevSection
operator|=
name|nullptr
block|;
name|DwarfInfoSection
operator|=
name|nullptr
block|;
name|DwarfLineSection
operator|=
name|nullptr
block|;
name|DwarfFrameSection
operator|=
name|nullptr
block|;
name|DwarfPubTypesSection
operator|=
name|nullptr
block|;
name|DwarfDebugInlineSection
operator|=
name|nullptr
block|;
name|DwarfStrSection
operator|=
name|nullptr
block|;
name|DwarfLocSection
operator|=
name|nullptr
block|;
name|DwarfARangesSection
operator|=
name|nullptr
block|;
name|DwarfRangesSection
operator|=
name|nullptr
block|;   }
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|,
argument|const Constant *C
argument_list|)
specifier|const
name|override
block|{
return|return
name|ReadOnlySection
return|;
block|}
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|{
return|return
name|DataSection
return|;
block|}
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|; }
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

