begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LLVMCConfigurationEmitter.cpp - Generate LLVMCC config ---*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|// This tablegen backend is responsible for emitting LLVMCC configuration code.
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
name|LLVM_UTILS_TABLEGEN_LLVMCCONF_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_LLVMCCONF_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// LLVMCConfigurationEmitter - TableGen backend that generates
comment|/// configuration code for LLVMC.
name|class
name|LLVMCConfigurationEmitter
range|:
name|public
name|TableGenBackend
block|{
name|public
operator|:
name|explicit
name|LLVMCConfigurationEmitter
argument_list|(
argument|RecordKeeper&
argument_list|)
block|{}
comment|// run - Output the asmwriter, returning true on failure.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//LLVM_UTILS_TABLEGEN_LLVMCCONF_EMITTER_H
end_comment

end_unit

