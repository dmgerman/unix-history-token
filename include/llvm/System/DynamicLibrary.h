begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/System/DynamicLibrary.h - Portable Dynamic Library -*- C++ -*-===//
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
comment|// This file declares the sys::DynamicLibrary class.
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
name|LLVM_SYSTEM_DYNAMIC_LIBRARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_DYNAMIC_LIBRARY_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This class provides a portable interface to dynamic libraries which also
comment|/// might be known as shared libraries, shared objects, dynamic shared
comment|/// objects, or dynamic link libraries. Regardless of the terminology or the
comment|/// operating system interface, this class provides a portable interface that
comment|/// allows dynamic libraries to be loaded and and searched for externally
comment|/// defined symbols. This is typically used to provide "plug-in" support.
comment|/// It also allows for symbols to be defined which don't live in any library,
comment|/// but rather the main program itself, useful on Windows where the main
comment|/// executable cannot be searched.
name|class
name|DynamicLibrary
block|{
name|DynamicLibrary
argument_list|()
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|/// This function allows a library to be loaded without instantiating a
comment|/// DynamicLibrary object. Consequently, it is marked as being permanent
comment|/// and will only be unloaded when the program terminates.  This returns
comment|/// false on success or returns true and fills in *ErrMsg on failure.
comment|/// @brief Open a dynamic library permanently.
comment|///
comment|/// NOTE: This function is not thread safe.
comment|///
specifier|static
name|bool
name|LoadLibraryPermanently
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// This function will search through all previously loaded dynamic
comment|/// libraries for the symbol \p symbolName. If it is found, the addressof
comment|/// that symbol is returned. If not, null is returned. Note that this will
comment|/// search permanently loaded libraries (LoadLibraryPermanently) as well
comment|/// as ephemerally loaded libraries (constructors).
comment|/// @throws std::string on error.
comment|/// @brief Search through libraries for address of a symbol
comment|///
comment|/// NOTE: This function is not thread safe.
comment|///
specifier|static
name|void
modifier|*
name|SearchForAddressOfSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|)
function_decl|;
comment|/// @brief Convenience function for C++ophiles.
comment|///
comment|/// NOTE: This function is not thread safe.
comment|///
specifier|static
name|void
modifier|*
name|SearchForAddressOfSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|symbolName
argument_list|)
block|{
return|return
name|SearchForAddressOfSymbol
argument_list|(
name|symbolName
operator|.
name|c_str
argument_list|()
argument_list|)
return|;
block|}
comment|/// This functions permanently adds the symbol \p symbolName with the
comment|/// value \p symbolValue.  These symbols are searched before any
comment|/// libraries.
comment|/// @brief Add searchable symbol/value pair.
comment|///
comment|/// NOTE: This function is not thread safe.
comment|///
specifier|static
name|void
name|AddSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|,
name|void
modifier|*
name|symbolValue
parameter_list|)
function_decl|;
comment|/// @brief Convenience function for C++ophiles.
comment|///
comment|/// NOTE: This function is not thread safe.
comment|///
specifier|static
name|void
name|AddSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|symbolName
argument_list|,
name|void
operator|*
name|symbolValue
argument_list|)
block|{
name|AddSymbol
argument_list|(
name|symbolName
operator|.
name|c_str
argument_list|()
argument_list|,
name|symbolValue
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
comment|// End sys namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SYSTEM_DYNAMIC_LIBRARY_H
end_comment

end_unit

