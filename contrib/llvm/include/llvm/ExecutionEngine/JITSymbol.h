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

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
name|HasError
init|=
literal|1U
operator|<<
literal|0
block|,
name|Weak
init|=
literal|1U
operator|<<
literal|1
block|,
name|Common
init|=
literal|1U
operator|<<
literal|2
block|,
name|Absolute
init|=
literal|1U
operator|<<
literal|3
block|,
name|Exported
init|=
literal|1U
operator|<<
literal|4
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
comment|/// @brief Return true if there was an error retrieving this symbol.
name|bool
name|hasError
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|HasError
operator|)
operator|==
name|HasError
return|;
block|}
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
name|Expected
operator|<
name|JITTargetAddress
operator|>
operator|(
operator|)
operator|>
decl_stmt|;
comment|/// @brief Create a 'null' symbol, used to represent a "symbol not found"
comment|///        result from a successful (non-erroneous) lookup.
name|JITSymbol
argument_list|(
name|std
operator|::
name|nullptr_t
argument_list|)
operator|:
name|CachedAddr
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// @brief Create a JITSymbol representing an error in the symbol lookup
comment|///        process (e.g. a network failure during a remote lookup).
name|JITSymbol
argument_list|(
argument|Error Err
argument_list|)
operator|:
name|Err
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|)
operator|,
name|Flags
argument_list|(
argument|JITSymbolFlags::HasError
argument_list|)
block|{}
comment|/// @brief Create a symbol for a definition with a known address.
name|JITSymbol
argument_list|(
argument|JITTargetAddress Addr
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
operator|:
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
name|CachedAddr
argument_list|(
literal|0
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Flags
argument_list|)
block|{}
name|JITSymbol
argument_list|(
specifier|const
name|JITSymbol
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|JITSymbol
modifier|&
name|operator
init|=
operator|(
specifier|const
name|JITSymbol
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|JITSymbol
argument_list|(
name|JITSymbol
operator|&&
name|Other
argument_list|)
operator|:
name|GetAddress
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|GetAddress
argument_list|)
argument_list|)
operator|,
name|Flags
argument_list|(
argument|std::move(Other.Flags)
argument_list|)
block|{
if|if
condition|(
name|Flags
operator|.
name|hasError
argument_list|()
condition|)
name|Err
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Err
argument_list|)
expr_stmt|;
else|else
name|CachedAddr
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|CachedAddr
argument_list|)
expr_stmt|;
block|}
name|JITSymbol
modifier|&
name|operator
init|=
operator|(
name|JITSymbol
operator|&&
name|Other
operator|)
block|{
name|GetAddress
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|GetAddress
argument_list|)
block|;
name|Flags
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Flags
argument_list|)
block|;
if|if
condition|(
name|Flags
operator|.
name|hasError
argument_list|()
condition|)
name|Err
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Err
argument_list|)
expr_stmt|;
else|else
name|CachedAddr
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|CachedAddr
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|JITSymbol
argument_list|()
block|{
if|if
condition|(
name|Flags
operator|.
name|hasError
argument_list|()
condition|)
name|Err
operator|.
expr|~
name|Error
argument_list|()
expr_stmt|;
else|else
name|CachedAddr
operator|.
expr|~
name|JITTargetAddress
argument_list|()
expr_stmt|;
block|}
comment|/// @brief Returns true if the symbol exists, false otherwise.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Flags
operator|.
name|hasError
argument_list|()
operator|&&
operator|(
name|CachedAddr
operator|||
name|GetAddress
operator|)
return|;
block|}
comment|/// @brief Move the error field value out of this JITSymbol.
name|Error
name|takeError
parameter_list|()
block|{
if|if
condition|(
name|Flags
operator|.
name|hasError
argument_list|()
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
return|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
comment|/// @brief Get the address of the symbol in the target address space. Returns
comment|///        '0' if the symbol does not exist.
name|Expected
operator|<
name|JITTargetAddress
operator|>
name|getAddress
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|Flags
operator|.
name|hasError
argument_list|()
operator|&&
literal|"getAddress called on error value"
argument_list|)
block|;
if|if
condition|(
name|GetAddress
condition|)
block|{
if|if
condition|(
name|auto
name|CachedAddrOrErr
init|=
name|GetAddress
argument_list|()
condition|)
block|{
name|GetAddress
operator|=
name|nullptr
expr_stmt|;
name|CachedAddr
operator|=
operator|*
name|CachedAddrOrErr
expr_stmt|;
name|assert
argument_list|(
name|CachedAddr
operator|&&
literal|"Symbol could not be materialized."
argument_list|)
expr_stmt|;
block|}
else|else
return|return
name|CachedAddrOrErr
operator|.
name|takeError
argument_list|()
return|;
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
union|union
block|{
name|JITTargetAddress
name|CachedAddr
decl_stmt|;
name|Error
name|Err
decl_stmt|;
block|}
union|;
name|JITSymbolFlags
name|Flags
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Symbol resolution.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

