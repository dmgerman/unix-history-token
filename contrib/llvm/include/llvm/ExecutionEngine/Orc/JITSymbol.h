begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------- JITSymbol.h - JIT symbol abstraction -----------*- C++ -*-===//
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
comment|// Abstraction for target process addresses.
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
name|LLVM_EXECUTIONENGINE_ORC_JITSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_JITSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbolFlags.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Represents an address in the target process's address space.
typedef|typedef
name|uint64_t
name|TargetAddress
typedef|;
comment|/// @brief Represents a symbol in the JIT.
name|class
name|JITSymbol
range|:
name|public
name|JITSymbolBase
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|TargetAddress
argument_list|()
operator|>
name|GetAddressFtor
expr_stmt|;
comment|/// @brief Create a 'null' symbol that represents failure to find a symbol
comment|///        definition.
name|JITSymbol
argument_list|(
name|std
operator|::
name|nullptr_t
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|JITSymbolFlags
operator|::
name|None
argument_list|)
block|,
name|CachedAddr
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// @brief Create a symbol for a definition with a known address.
name|JITSymbol
argument_list|(
argument|TargetAddress Addr
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|Flags
argument_list|)
decl_stmt|,
name|CachedAddr
argument_list|(
name|Addr
argument_list|)
block|{}
comment|/// @brief Create a symbol for a definition that doesn't have a known address
comment|///        yet.
comment|/// @param GetAddress A functor to materialize a definition (fixing the
comment|///        address) on demand.
comment|///
comment|///   This constructor allows a JIT layer to provide a reference to a symbol
comment|/// definition without actually materializing the definition up front. The
comment|/// user can materialize the definition at any time by calling the getAddress
comment|/// method.
name|JITSymbol
argument_list|(
argument|GetAddressFtor GetAddress
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
block|:
name|JITSymbolBase
argument_list|(
name|Flags
argument_list|)
operator|,
name|GetAddress
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|GetAddress
argument_list|)
argument_list|)
operator|,
name|CachedAddr
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// @brief Create a JITSymbol from a RuntimeDyld::SymbolInfo.
name|JITSymbol
argument_list|(
specifier|const
name|RuntimeDyld
operator|::
name|SymbolInfo
operator|&
name|Sym
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|Sym
operator|.
name|getFlags
argument_list|()
argument_list|)
operator|,
name|CachedAddr
argument_list|(
argument|Sym.getAddress()
argument_list|)
block|{}
comment|/// @brief Returns true if the symbol exists, false otherwise.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|CachedAddr
operator|||
name|GetAddress
return|;
block|}
comment|/// @brief Get the address of the symbol in the target address space. Returns
comment|///        '0' if the symbol does not exist.
name|TargetAddress
name|getAddress
parameter_list|()
block|{
if|if
condition|(
name|GetAddress
condition|)
block|{
name|CachedAddr
operator|=
name|GetAddress
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|CachedAddr
operator|&&
literal|"Symbol could not be materialized."
argument_list|)
expr_stmt|;
name|GetAddress
operator|=
name|nullptr
expr_stmt|;
block|}
return|return
name|CachedAddr
return|;
block|}
comment|/// @brief Convert this JITSymbol to a RuntimeDyld::SymbolInfo.
name|RuntimeDyld
operator|::
name|SymbolInfo
name|toRuntimeDyldSymbol
argument_list|()
block|{
return|return
name|RuntimeDyld
operator|::
name|SymbolInfo
argument_list|(
name|getAddress
argument_list|()
argument_list|,
name|getFlags
argument_list|()
argument_list|)
return|;
block|}
name|private
label|:
name|GetAddressFtor
name|GetAddress
decl_stmt|;
name|TargetAddress
name|CachedAddr
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace orc.
end_comment

begin_comment
unit|}
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_JITSYMBOL_H
end_comment

end_unit

