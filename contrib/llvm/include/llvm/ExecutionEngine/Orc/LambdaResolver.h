begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LambdaResolverMM - Redirect symbol lookup via a functor --*- C++ -*-===//
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
comment|//   Defines a RuntimeDyld::SymbolResolver subclass that uses a user-supplied
end_comment

begin_comment
comment|// functor for symbol resolution.
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
name|LLVM_EXECUTIONENGINE_ORC_LAMBDARESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_LAMBDARESOLVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
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
name|namespace
name|orc
block|{
name|template
operator|<
name|typename
name|DylibLookupFtorT
operator|,
name|typename
name|ExternalLookupFtorT
operator|>
name|class
name|LambdaResolver
operator|:
name|public
name|JITSymbolResolver
block|{
name|public
operator|:
name|LambdaResolver
argument_list|(
argument|DylibLookupFtorT DylibLookupFtor
argument_list|,
argument|ExternalLookupFtorT ExternalLookupFtor
argument_list|)
operator|:
name|DylibLookupFtor
argument_list|(
name|DylibLookupFtor
argument_list|)
block|,
name|ExternalLookupFtor
argument_list|(
argument|ExternalLookupFtor
argument_list|)
block|{}
name|JITSymbol
name|findSymbolInLogicalDylib
argument_list|(
argument|const std::string&Name
argument_list|)
name|final
block|{
return|return
name|DylibLookupFtor
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|JITSymbol
name|findSymbol
argument_list|(
argument|const std::string&Name
argument_list|)
name|final
block|{
return|return
name|ExternalLookupFtor
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|private
operator|:
name|DylibLookupFtorT
name|DylibLookupFtor
block|;
name|ExternalLookupFtorT
name|ExternalLookupFtor
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|DylibLookupFtorT
operator|,
name|typename
name|ExternalLookupFtorT
operator|>
name|std
operator|::
name|shared_ptr
operator|<
name|LambdaResolver
operator|<
name|DylibLookupFtorT
operator|,
name|ExternalLookupFtorT
operator|>>
name|createLambdaResolver
argument_list|(
argument|DylibLookupFtorT DylibLookupFtor
argument_list|,
argument|ExternalLookupFtorT ExternalLookupFtor
argument_list|)
block|{
name|using
name|LR
operator|=
name|LambdaResolver
operator|<
name|DylibLookupFtorT
block|,
name|ExternalLookupFtorT
operator|>
block|;
return|return
name|make_unique
operator|<
name|LR
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|DylibLookupFtor
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|ExternalLookupFtor
argument_list|)
operator|)
return|;
block|}
block|}
comment|// end namespace orc
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_LAMBDARESOLVER_H
end_comment

end_unit

