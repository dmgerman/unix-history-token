begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUCodeEmitter.h - AMDGPU Code Emitter interface -----------------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief CodeEmitter interface for R600 and SI codegen.
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
name|AMDGPUCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPUCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCCodeEmitter.h"
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
name|MCInst
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|AMDGPUMCCodeEmitter
range|:
name|public
name|MCCodeEmitter
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|uint64_t
name|getBinaryCodeForInstr
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|)
specifier|const
block|;
name|virtual
name|uint64_t
name|getMachineOpValue
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|const MCOperand&MO
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPUCODEEMITTER_H
end_comment

end_unit

