begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/ARMTargetObjectFile.h - ARM Object Info -----*- C++ -*-===//
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
name|LLVM_TARGET_ARM_TARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_ARM_TARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|ARMElfTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
name|protected
operator|:
specifier|const
name|MCSection
operator|*
name|AttributesSection
block|;
name|public
operator|:
name|ARMElfTargetObjectFile
argument_list|()
operator|:
name|TargetLoweringObjectFileELF
argument_list|()
block|,
name|AttributesSection
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;
specifier|const
name|MCExpr
operator|*
name|getTTypeGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Describe a TLS variable address within debug info.
specifier|const
name|MCExpr
operator|*
name|getDebugThreadLocalSymbol
argument_list|(
argument|const MCSymbol *Sym
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

