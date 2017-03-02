begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ NullResolver.h - Reject symbol lookup requests ------*- C++ -*-===//
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
comment|//   Defines a RuntimeDyld::SymbolResolver subclass that rejects all symbol
end_comment

begin_comment
comment|// resolution requests, for clients that have no cross-object fixups.
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
name|LLVM_EXECUTIONENGINE_ORC_NULLRESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_NULLRESOLVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// SymbolResolver impliementation that rejects all resolution requests.
comment|/// Useful for clients that have no cross-object fixups.
name|class
name|NullResolver
range|:
name|public
name|JITSymbolResolver
block|{
name|public
operator|:
name|JITSymbol
name|findSymbol
argument_list|(
argument|const std::string&Name
argument_list|)
name|final
block|;
name|JITSymbol
name|findSymbolInLogicalDylib
argument_list|(
argument|const std::string&Name
argument_list|)
name|final
block|; }
decl_stmt|;
block|}
comment|// End namespace orc.
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_NULLRESOLVER_H
end_comment

end_unit

