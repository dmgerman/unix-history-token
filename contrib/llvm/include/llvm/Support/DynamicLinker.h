begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/DynamicLinker.h - Portable Dynamic Linker --*- C++ -*-===//
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
comment|// Lightweight interface to dynamic library linking and loading, and dynamic
end_comment

begin_comment
comment|// symbol lookup functionality, in whatever form the operating system
end_comment

begin_comment
comment|// provides it.
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
name|LLVM_SUPPORT_DYNAMICLINKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DYNAMICLINKER_H
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
comment|/// LinkDynamicObject - Load the named file as a dynamic library
comment|/// and link it with the currently running process. Returns false
comment|/// on success, true if there is an error (and sets ErrorMessage
comment|/// if it is not NULL). Analogous to dlopen().
comment|///
name|bool
name|LinkDynamicObject
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
name|ErrorMessage
argument_list|)
decl_stmt|;
comment|/// GetAddressOfSymbol - Returns the address of the named symbol in
comment|/// the currently running process, as reported by the dynamic linker,
comment|/// or NULL if the symbol does not exist or some other error has
comment|/// occurred.
comment|///
name|void
modifier|*
name|GetAddressOfSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|)
function_decl|;
name|void
modifier|*
name|GetAddressOfSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|symbolName
argument_list|)
decl_stmt|;
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
comment|// SUPPORT_DYNAMICLINKER_H
end_comment

end_unit

