begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonTargetObjectFile.h -----------------------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

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
name|HexagonTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
name|public
operator|:
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isGlobalInSmallSection
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|bool
name|isSmallDataEnabled
argument_list|()
specifier|const
block|;
name|unsigned
name|getSmallDataSize
argument_list|()
specifier|const
block|;
name|bool
name|shouldPutJumpTableInFunctionSection
argument_list|(
argument|bool UsesLabelDifference
argument_list|,
argument|const Function&F
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|Function
operator|*
name|getLutUsedFunction
argument_list|(
argument|const GlobalObject *GO
argument_list|)
specifier|const
block|;
name|private
operator|:
name|MCSectionELF
operator|*
name|SmallDataSection
block|;
name|MCSectionELF
operator|*
name|SmallBSSSection
block|;
name|unsigned
name|getSmallestAddressableSize
argument_list|(
argument|const Type *Ty
argument_list|,
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|MCSection
operator|*
name|selectSmallSectionForGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|MCSection
operator|*
name|selectSectionForLookupTable
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|const Function *Fn
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

