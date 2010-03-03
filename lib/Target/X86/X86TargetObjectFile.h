begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/X86/X86TargetObjectFile.h - X86 Object Info -*- C++ -*-===//
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
name|LLVM_TARGET_X86_TARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_X86_TARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

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
name|X86TargetMachine
decl_stmt|;
comment|/// X8664_MachoTargetObjectFile - This TLOF implementation is used for
comment|/// Darwin/x86-64.
name|class
name|X8664_MachoTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileMachO
block|{
name|public
operator|:
name|virtual
specifier|const
name|MCExpr
operator|*
name|getSymbolForDwarfGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|unsigned Encoding
argument_list|)
specifier|const
block|;   }
decl_stmt|;
name|class
name|X8632_ELFTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
specifier|const
name|X86TargetMachine
operator|&
name|TM
block|;
name|public
operator|:
name|X8632_ELFTargetObjectFile
argument_list|(
specifier|const
name|X86TargetMachine
operator|&
name|tm
argument_list|)
operator|:
name|TM
argument_list|(
argument|tm
argument_list|)
block|{ }
name|virtual
name|unsigned
name|getPersonalityEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getLSDAEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getFDEEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getTTypeEncoding
argument_list|()
specifier|const
block|;   }
decl_stmt|;
name|class
name|X8664_ELFTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
specifier|const
name|X86TargetMachine
operator|&
name|TM
block|;
name|public
operator|:
name|X8664_ELFTargetObjectFile
argument_list|(
specifier|const
name|X86TargetMachine
operator|&
name|tm
argument_list|)
operator|:
name|TM
argument_list|(
argument|tm
argument_list|)
block|{ }
name|virtual
name|unsigned
name|getPersonalityEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getLSDAEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getFDEEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getTTypeEncoding
argument_list|()
specifier|const
block|;   }
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

