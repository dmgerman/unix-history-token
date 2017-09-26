begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// CodeGen/RuntimeLibcallSignatures.h - R.T. Lib. Call Signatures -*- C++ -*--//
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
comment|/// \brief This file provides signature information for runtime libcalls.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_RUNTIME_LIBCALL_SIGNATURES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_RUNTIME_LIBCALL_SIGNATURES_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/WebAssemblyMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RuntimeLibcalls.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblySubtarget
decl_stmt|;
specifier|extern
name|void
name|GetSignature
argument_list|(
specifier|const
name|WebAssemblySubtarget
operator|&
name|Subtarget
argument_list|,
name|RTLIB
operator|::
name|Libcall
name|LC
argument_list|,
name|SmallVectorImpl
operator|<
name|wasm
operator|::
name|ValType
operator|>
operator|&
name|Rets
argument_list|,
name|SmallVectorImpl
operator|<
name|wasm
operator|::
name|ValType
operator|>
operator|&
name|Params
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|GetSignature
argument_list|(
specifier|const
name|WebAssemblySubtarget
operator|&
name|Subtarget
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
name|SmallVectorImpl
operator|<
name|wasm
operator|::
name|ValType
operator|>
operator|&
name|Rets
argument_list|,
name|SmallVectorImpl
operator|<
name|wasm
operator|::
name|ValType
operator|>
operator|&
name|Params
argument_list|)
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

