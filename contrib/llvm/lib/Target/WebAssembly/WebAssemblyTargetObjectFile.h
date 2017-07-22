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
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblyTargetObjectFileELF
name|final
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
block|; }
decl_stmt|;
name|class
name|WebAssemblyTargetObjectFile
name|final
range|:
name|public
name|TargetLoweringObjectFileWasm
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

