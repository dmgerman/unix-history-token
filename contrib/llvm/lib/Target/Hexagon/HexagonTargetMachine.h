begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- HexagonTargetMachine.h - Define TargetMachine for Hexagon ---*- C++ -*-=//
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
comment|// This file declares the Hexagon specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"HexagonInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"HexagonSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"HexagonTargetObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|HexagonTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|HexagonSubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|HexagonTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
operator|~
name|HexagonTargetMachine
argument_list|()
name|override
block|;
specifier|const
name|HexagonSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|unsigned
name|getModuleMatchQuality
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|adjustPassManager
argument_list|(
argument|PassManagerBuilder&PMB
argument_list|)
name|override
block|;
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
name|override
block|;
name|HexagonTargetObjectFile
operator|*
name|getObjFileLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|static_cast
operator|<
name|HexagonTargetObjectFile
operator|*
operator|>
operator|(
name|TLOF
operator|.
name|get
argument_list|()
operator|)
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

