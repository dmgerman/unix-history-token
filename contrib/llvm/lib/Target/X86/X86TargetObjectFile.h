begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86TargetObjectFile.h - X86 Object Info -----------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_X86_X86TARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86TARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
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
comment|/// X86_64MachoTargetObjectFile - This TLOF implementation is used for Darwin
comment|/// x86-64.
name|class
name|X86_64MachoTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileMachO
block|{
name|public
operator|:
specifier|const
name|MCExpr
operator|*
name|getTTypeGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|unsigned Encoding
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
comment|// getCFIPersonalitySymbol - The symbol that gets passed to
comment|// .cfi_personality.
name|MCSymbol
operator|*
name|getCFIPersonalitySymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCExpr
operator|*
name|getIndirectSymViaGOTPCRel
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|const MCValue&MV
argument_list|,
argument|int64_t Offset
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;   }
decl_stmt|;
comment|/// \brief This implemenatation is used for X86 ELF targets that don't
comment|/// have a further specialization.
name|class
name|X86ELFTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
name|public
operator|:
name|X86ELFTargetObjectFile
argument_list|()
block|{
name|PLTRelativeVariantKind
operator|=
name|MCSymbolRefExpr
operator|::
name|VK_PLT
block|;     }
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
block|;   }
decl_stmt|;
comment|/// X86FreeBSDTargetObjectFile - This implementation is used for FreeBSD
comment|/// on x86 and x86-64.
name|class
name|X86FreeBSDTargetObjectFile
range|:
name|public
name|X86ELFTargetObjectFile
block|{
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;   }
decl_stmt|;
comment|/// \brief This implementation is used for Fuchsia on x86-64.
name|class
name|X86FuchsiaTargetObjectFile
range|:
name|public
name|X86ELFTargetObjectFile
block|{
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;   }
decl_stmt|;
comment|/// X86LinuxNaClTargetObjectFile - This implementation is used for linux and
comment|/// Native Client on x86 and x86-64.
name|class
name|X86LinuxNaClTargetObjectFile
range|:
name|public
name|X86ELFTargetObjectFile
block|{
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;   }
decl_stmt|;
comment|/// \brief This implementation is used for Solaris on x86/x86-64.
name|class
name|X86SolarisTargetObjectFile
range|:
name|public
name|X86ELFTargetObjectFile
block|{
name|void
name|Initialize
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
block|;   }
decl_stmt|;
comment|/// \brief This implementation is used for Windows targets on x86 and x86-64.
name|class
name|X86WindowsTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileCOFF
block|{
specifier|const
name|MCExpr
operator|*
name|lowerRelativeReference
argument_list|(
argument|const GlobalValue *LHS
argument_list|,
argument|const GlobalValue *RHS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Given a mergeable constant with the specified size and relocation
comment|/// information, return a section that it should be placed in.
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const Constant *C
argument_list|,
argument|unsigned&Align
argument_list|)
specifier|const
name|override
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

