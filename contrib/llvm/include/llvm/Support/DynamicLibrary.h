begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/DynamicLibrary.h - Portable Dynamic Library -*- C++ -*-===//
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
name|LLVM_SUPPORT_DYNAMICLIBRARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DYNAMICLIBRARY_H
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
name|class
name|StringRef
decl_stmt|;
name|namespace
name|sys
block|{
comment|/// This class provides a portable interface to dynamic libraries which also
comment|/// might be known as shared libraries, shared objects, dynamic shared
comment|/// objects, or dynamic link libraries. Regardless of the terminology or the
comment|/// operating system interface, this class provides a portable interface that
comment|/// allows dynamic libraries to be loaded and searched for externally
comment|/// defined symbols. This is typically used to provide "plug-in" support.
comment|/// It also allows for symbols to be defined which don't live in any library,
comment|/// but rather the main program itself, useful on Windows where the main
comment|/// executable cannot be searched.
comment|///
comment|/// Note: there is currently no interface for temporarily loading a library,
comment|/// or for unloading libraries when the LLVM library is unloaded.
name|class
name|DynamicLibrary
block|{
comment|// Placeholder whose address represents an invalid library.
comment|// We use this instead of NULL or a pointer-int pair because the OS library
comment|// might define 0 or 1 to be "special" handles, such as "search all".
specifier|static
name|char
name|Invalid
decl_stmt|;
comment|// Opaque data used to interface with OS-specific dynamic library handling.
name|void
modifier|*
name|Data
decl_stmt|;
name|public
label|:
name|explicit
name|DynamicLibrary
argument_list|(
name|void
operator|*
name|data
operator|=
operator|&
name|Invalid
argument_list|)
operator|:
name|Data
argument_list|(
argument|data
argument_list|)
block|{}
comment|/// Returns true if the object refers to a valid library.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|!=
operator|&
name|Invalid
return|;
block|}
comment|/// Searches through the library for the symbol \p symbolName. If it is
comment|/// found, the address of that symbol is returned. If not, NULL is returned.
comment|/// Note that NULL will also be returned if the library failed to load.
comment|/// Use isValid() to distinguish these cases if it is important.
comment|/// Note that this will \e not search symbols explicitly registered by
comment|/// AddSymbol().
name|void
modifier|*
name|getAddressOfSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|)
function_decl|;
comment|/// This function permanently loads the dynamic library at the given path.
comment|/// The library will only be unloaded when llvm_shutdown() is called.
comment|/// This returns a valid DynamicLibrary instance on success and an invalid
comment|/// instance on failure (see isValid()). \p *errMsg will only be modified
comment|/// if the library fails to load.
comment|///
comment|/// It is safe to call this function multiple times for the same library.
comment|/// @brief Open a dynamic library permanently.
specifier|static
name|DynamicLibrary
name|getPermanentLibrary
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
name|errMsg
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// Registers an externally loaded library. The library will be unloaded
comment|/// when the program terminates.
comment|///
comment|/// It is safe to call this function multiple times for the same library,
comment|/// though ownership is only taken if there was no error.
comment|///
comment|/// \returns An empty \p DynamicLibrary if the library was already loaded.
specifier|static
name|DynamicLibrary
name|addPermanentLibrary
argument_list|(
name|void
operator|*
name|handle
argument_list|,
name|std
operator|::
name|string
operator|*
name|errMsg
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// This function permanently loads the dynamic library at the given path.
comment|/// Use this instead of getPermanentLibrary() when you won't need to get
comment|/// symbols from the library itself.
comment|///
comment|/// It is safe to call this function multiple times for the same library.
specifier|static
name|bool
name|LoadLibraryPermanently
argument_list|(
specifier|const
name|char
operator|*
name|Filename
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
name|nullptr
argument_list|)
block|{
return|return
operator|!
name|getPermanentLibrary
argument_list|(
name|Filename
argument_list|,
name|ErrMsg
argument_list|)
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// This function will search through all previously loaded dynamic
comment|/// libraries for the symbol \p symbolName. If it is found, the address of
comment|/// that symbol is returned. If not, null is returned. Note that this will
comment|/// search permanently loaded libraries (getPermanentLibrary()) as well
comment|/// as explicitly registered symbols (AddSymbol()).
comment|/// @throws std::string on error.
comment|/// @brief Search through libraries for address of a symbol
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
specifier|static
name|void
name|AddSymbol
parameter_list|(
name|StringRef
name|symbolName
parameter_list|,
name|void
modifier|*
name|symbolValue
parameter_list|)
function_decl|;
name|class
name|HandleSet
decl_stmt|;
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

end_unit

