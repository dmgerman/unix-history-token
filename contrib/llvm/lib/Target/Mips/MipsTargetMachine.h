begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsTargetMachine.h - Define TargetMachine for Mips ------*- C++ -*-===//
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
comment|// This file declares the Mips specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsABIInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|bool
name|isLittle
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
comment|// Selected ABI
name|MipsABIInfo
name|ABI
block|;
name|MipsSubtarget
operator|*
name|Subtarget
block|;
name|MipsSubtarget
name|DefaultSubtarget
block|;
name|MipsSubtarget
name|NoMips16Subtarget
block|;
name|MipsSubtarget
name|Mips16Subtarget
block|;
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MipsSubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|MipsTargetMachine
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
argument_list|,
argument|bool isLittle
argument_list|)
block|;
operator|~
name|MipsTargetMachine
argument_list|()
name|override
block|;
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
name|override
block|;
specifier|const
name|MipsSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Subtarget
condition|)
return|return
name|Subtarget
return|;
return|return
operator|&
name|DefaultSubtarget
return|;
block|}
specifier|const
name|MipsSubtarget
modifier|*
name|getSubtargetImpl
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// \brief Reset the subtarget for the Mips target.
name|void
name|resetSubtarget
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|// Pass Pipeline Configuration
name|TargetPassConfig
modifier|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
name|override
decl_stmt|;
name|TargetLoweringObjectFile
operator|*
name|getObjFileLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|TLOF
operator|.
name|get
argument_list|()
return|;
block|}
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|isLittle
return|;
block|}
specifier|const
name|MipsABIInfo
operator|&
name|getABI
argument_list|()
specifier|const
block|{
return|return
name|ABI
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Mips32/64 big endian target machine.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MipsebTargetMachine
range|:
name|public
name|MipsTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|MipsebTargetMachine
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
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Mips32/64 little endian target machine.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MipselTargetMachine
range|:
name|public
name|MipsTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|MipselTargetMachine
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
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_MIPS_MIPSTARGETMACHINE_H
end_comment

end_unit

