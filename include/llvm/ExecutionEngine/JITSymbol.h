begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- JITSymbol.h - JIT symbol abstraction ---------------------*- C++ -*-===//
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
name|LLVM_EXECUTIONENGINE_JITSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_JITSYMBOL_H
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|BasicSymbolRef
decl_stmt|;
block|}
comment|// end namespace object
comment|/// @brief Represents an address in the target process's address space.
name|using
name|JITTargetAddress
init|=
name|uint64_t
decl_stmt|;
comment|/// @brief Flags for symbols in the JIT.
name|class
name|JITSymbolFlags
block|{
name|public
label|:
name|using
name|UnderlyingType
init|=
name|uint8_t
decl_stmt|;
enum|enum
name|FlagNames
enum|:
name|UnderlyingType
block|{
name|None
init|=
literal|0
block|,
name|Weak
init|=
literal|1U
operator|<<
literal|0
block|,
name|Common
init|=
literal|1U
operator|<<
literal|1
block|,
name|Absolute
init|=
literal|1U
operator|<<
literal|2
block|,
name|Exported
init|=
literal|1U
operator|<<
literal|3
block|}
enum|;
comment|/// @brief Default-construct a JITSymbolFlags instance.
name|JITSymbolFlags
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// @brief Construct a JITSymbolFlags instance from the given flags.
name|JITSymbolFlags
argument_list|(
argument|FlagNames Flags
argument_list|)
block|:
name|Flags
argument_list|(
argument|Flags
argument_list|)
block|{}
comment|/// @brief Returns true is the Weak flag is set.
name|bool
name|isWeak
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|Weak
operator|)
operator|==
name|Weak
return|;
block|}
comment|/// @brief Returns true is the Weak flag is set.
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|Common
operator|)
operator|==
name|Common
return|;
block|}
name|bool
name|isStrongDefinition
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isWeak
argument_list|()
operator|&&
operator|!
name|isCommon
argument_list|()
return|;
block|}
comment|/// @brief Returns true is the Weak flag is set.
name|bool
name|isExported
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|Exported
operator|)
operator|==
name|Exported
return|;
block|}
name|operator
name|UnderlyingType
function|&()
block|{
return|return
name|Flags
return|;
block|}
comment|/// Construct a JITSymbolFlags value based on the flags of the given global
comment|/// value.
specifier|static
name|JITSymbolFlags
name|fromGlobalValue
parameter_list|(
specifier|const
name|GlobalValue
modifier|&
name|GV
parameter_list|)
function_decl|;
comment|/// Construct a JITSymbolFlags value based on the flags of the given libobject
comment|/// symbol.
specifier|static
name|JITSymbolFlags
name|fromObjectSymbol
argument_list|(
specifier|const
name|object
operator|::
name|BasicSymbolRef
operator|&
name|Symbol
argument_list|)
decl_stmt|;
name|private
label|:
name|UnderlyingType
name|Flags
init|=
name|None
decl_stmt|;
block|}
empty_stmt|;
comment|/// @brief Represents a symbol that has been evaluated to an address already.
name|class
name|JITEvaluatedSymbol
block|{
name|public
label|:
comment|/// @brief Create a 'null' symbol.
name|JITEvaluatedSymbol
argument_list|(
argument|std::nullptr_t
argument_list|)
block|{}
comment|/// @brief Create a symbol for the given address and flags.
name|JITEvaluatedSymbol
argument_list|(
argument|JITTargetAddress Address
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
block|:
name|Address
argument_list|(
name|Address
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Flags
argument_list|)
block|{}
comment|/// @brief An evaluated symbol converts to 'true' if its address is non-zero.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Address
operator|!=
literal|0
return|;
block|}
comment|/// @brief Return the address of this symbol.
name|JITTargetAddress
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// @brief Return the flags for this symbol.
name|JITSymbolFlags
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|private
label|:
name|JITTargetAddress
name|Address
init|=
literal|0
decl_stmt|;
name|JITSymbolFlags
name|Flags
decl_stmt|;
block|}
empty_stmt|;
comment|/// @brief Represents a symbol in the JIT.
name|class
name|JITSymbol
block|{
name|public
label|:
name|using
name|GetAddressFtor
init|=
name|std
operator|::
name|function
operator|<
name|JITTargetAddress
argument_list|()
operator|>
decl_stmt|;
comment|/// @brief Create a 'null' symbol that represents failure to find a symbol
comment|///        definition.
name|JITSymbol
argument_list|(
argument|std::nullptr_t
argument_list|)
block|{}
comment|/// @brief Create a symbol for a definition with a known address.
name|JITSymbol
argument_list|(
argument|JITTargetAddress Addr
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
block|:
name|CachedAddr
argument_list|(
name|Addr
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Flags
argument_list|)
block|{}
comment|/// @brief Construct a JITSymbol from a JITEvaluatedSymbol.
name|JITSymbol
argument_list|(
argument|JITEvaluatedSymbol Sym
argument_list|)
operator|:
name|CachedAddr
argument_list|(
name|Sym
operator|.
name|getAddress
argument_list|()
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Sym.getFlags()
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
operator|:
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
name|Flags
argument_list|(
argument|Flags
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
name|JITTargetAddress
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
name|JITSymbolFlags
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|private
label|:
name|GetAddressFtor
name|GetAddress
decl_stmt|;
name|JITTargetAddress
name|CachedAddr
init|=
literal|0
decl_stmt|;
name|JITSymbolFlags
name|Flags
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Symbol resolution.
name|class
name|JITSymbolResolver
block|{
name|public
label|:
name|virtual
operator|~
name|JITSymbolResolver
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// This method returns the address of the specified symbol if it exists
comment|/// within the logical dynamic library represented by this JITSymbolResolver.
comment|/// Unlike findSymbol, queries through this interface should return addresses
comment|/// for hidden symbols.
comment|///
comment|/// This is of particular importance for the Orc JIT APIs, which support lazy
comment|/// compilation by breaking up modules: Each of those broken out modules
comment|/// must be able to resolve hidden symbols provided by the others. Clients
comment|/// writing memory managers for MCJIT can usually ignore this method.
comment|///
comment|/// This method will be queried by RuntimeDyld when checking for previous
comment|/// definitions of common symbols.
name|virtual
name|JITSymbol
name|findSymbolInLogicalDylib
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// This method returns the address of the specified function or variable.
comment|/// It is used to resolve symbols during module linking.
comment|///
comment|/// If the returned symbol's address is equal to ~0ULL then RuntimeDyld will
comment|/// skip all relocations for that symbol, and the client will be responsible
comment|/// for handling them manually.
name|virtual
name|JITSymbol
name|findSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
init|=
literal|0
decl_stmt|;
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
block|}
empty_stmt|;
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
comment|// LLVM_EXECUTIONENGINE_JITSYMBOL_H
end_comment

end_unit

