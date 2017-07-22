begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WebAssemblyMCAsmInfo.h - WebAssembly asm properties -----*- C++ -*-===//
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
comment|/// \brief This file contains the declaration of the WebAssemblyMCAsmInfo class.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYMCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoWasm.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
name|class
name|WebAssemblyMCAsmInfoELF
name|final
range|:
name|public
name|MCAsmInfoELF
block|{
name|public
operator|:
name|explicit
name|WebAssemblyMCAsmInfoELF
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|;
operator|~
name|WebAssemblyMCAsmInfoELF
argument_list|()
name|override
block|; }
decl_stmt|;
name|class
name|WebAssemblyMCAsmInfo
name|final
range|:
name|public
name|MCAsmInfoWasm
block|{
name|public
operator|:
name|explicit
name|WebAssemblyMCAsmInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|;
operator|~
name|WebAssemblyMCAsmInfo
argument_list|()
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

