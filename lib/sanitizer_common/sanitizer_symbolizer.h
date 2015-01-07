begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_symbolizer.h ----------------------------------*- C++ -*-===//
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
comment|// Symbolizer is used by sanitizers to map instruction address to a location in
end_comment

begin_comment
comment|// source code at run-time. Symbolizer either uses __sanitizer_symbolize_*
end_comment

begin_comment
comment|// defined in the program, or (if they are missing) tries to find and
end_comment

begin_comment
comment|// launch "llvm-symbolizer" commandline tool in a separate process and
end_comment

begin_comment
comment|// communicate with it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generally we should try to avoid calling system library functions during
end_comment

begin_comment
comment|// symbolization (and use their replacements from sanitizer_libc.h instead).
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_SYMBOLIZER_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_mutex.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
struct|struct
name|AddressInfo
block|{
comment|// Owns all the string members. Storage for them is
comment|// (de)allocated using sanitizer internal allocator.
name|uptr
name|address
decl_stmt|;
name|char
modifier|*
name|module
decl_stmt|;
name|uptr
name|module_offset
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kUnknown
init|=
operator|~
operator|(
name|uptr
operator|)
literal|0
decl_stmt|;
name|char
modifier|*
name|function
decl_stmt|;
name|uptr
name|function_offset
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|int
name|column
decl_stmt|;
name|AddressInfo
argument_list|()
expr_stmt|;
comment|// Deletes all strings and resets all fields.
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|FillAddressAndModuleInfo
parameter_list|(
name|uptr
name|addr
parameter_list|,
specifier|const
name|char
modifier|*
name|mod_name
parameter_list|,
name|uptr
name|mod_offset
parameter_list|)
function_decl|;
block|}
struct|;
comment|// Linked list of symbolized frames (each frame is described by AddressInfo).
struct|struct
name|SymbolizedStack
block|{
name|SymbolizedStack
modifier|*
name|next
decl_stmt|;
name|AddressInfo
name|info
decl_stmt|;
specifier|static
name|SymbolizedStack
modifier|*
name|New
parameter_list|(
name|uptr
name|addr
parameter_list|)
function_decl|;
comment|// Deletes current, and all subsequent frames in the linked list.
comment|// The object cannot be accessed after the call to this function.
name|void
name|ClearAll
parameter_list|()
function_decl|;
name|private
label|:
name|SymbolizedStack
argument_list|()
expr_stmt|;
block|}
struct|;
comment|// For now, DataInfo is used to describe global variable.
struct|struct
name|DataInfo
block|{
comment|// Owns all the string members. Storage for them is
comment|// (de)allocated using sanitizer internal allocator.
name|char
modifier|*
name|module
decl_stmt|;
name|uptr
name|module_offset
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|uptr
name|start
decl_stmt|;
name|uptr
name|size
decl_stmt|;
name|DataInfo
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
block|}
struct|;
name|class
name|Symbolizer
block|{
name|public
label|:
comment|/// Initialize and return platform-specific implementation of symbolizer
comment|/// (if it wasn't already initialized).
specifier|static
name|Symbolizer
modifier|*
name|GetOrInit
parameter_list|()
function_decl|;
comment|// Returns a list of symbolized frames for a given address (containing
comment|// all inlined functions, if necessary).
name|virtual
name|SymbolizedStack
modifier|*
name|SymbolizePC
parameter_list|(
name|uptr
name|address
parameter_list|)
block|{
return|return
name|SymbolizedStack
operator|::
name|New
argument_list|(
name|address
argument_list|)
return|;
block|}
name|virtual
name|bool
name|SymbolizeData
parameter_list|(
name|uptr
name|address
parameter_list|,
name|DataInfo
modifier|*
name|info
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|GetModuleNameAndOffsetForPC
parameter_list|(
name|uptr
name|pc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|module_name
parameter_list|,
name|uptr
modifier|*
name|module_address
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|CanReturnFileLineInfo
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|// Release internal caches (if any).
name|virtual
name|void
name|Flush
parameter_list|()
block|{}
comment|// Attempts to demangle the provided C++ mangled name.
name|virtual
specifier|const
name|char
modifier|*
name|Demangle
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|name
return|;
block|}
name|virtual
name|void
name|PrepareForSandboxing
parameter_list|()
block|{}
comment|// Allow user to install hooks that would be called before/after Symbolizer
comment|// does the actual file/line info fetching. Specific sanitizers may need this
comment|// to distinguish system library calls made in user code from calls made
comment|// during in-process symbolization.
typedef|typedef
name|void
function_decl|(
modifier|*
name|StartSymbolizationHook
function_decl|)
parameter_list|()
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|EndSymbolizationHook
function_decl|)
parameter_list|()
function_decl|;
comment|// May be called at most once.
name|void
name|AddHooks
parameter_list|(
name|StartSymbolizationHook
name|start_hook
parameter_list|,
name|EndSymbolizationHook
name|end_hook
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Platform-specific function for creating a Symbolizer object.
specifier|static
name|Symbolizer
modifier|*
name|PlatformInit
parameter_list|()
function_decl|;
comment|/// Initialize the symbolizer in a disabled state.  Not thread safe.
specifier|static
name|Symbolizer
modifier|*
name|Disable
parameter_list|()
function_decl|;
specifier|static
name|Symbolizer
modifier|*
name|symbolizer_
decl_stmt|;
specifier|static
name|StaticSpinMutex
name|init_mu_
decl_stmt|;
name|protected
label|:
name|Symbolizer
argument_list|()
expr_stmt|;
specifier|static
name|LowLevelAllocator
name|symbolizer_allocator_
decl_stmt|;
name|StartSymbolizationHook
name|start_hook_
decl_stmt|;
name|EndSymbolizationHook
name|end_hook_
decl_stmt|;
name|class
name|SymbolizerScope
block|{
name|public
label|:
name|explicit
name|SymbolizerScope
parameter_list|(
specifier|const
name|Symbolizer
modifier|*
name|sym
parameter_list|)
function_decl|;
operator|~
name|SymbolizerScope
argument_list|()
expr_stmt|;
name|private
label|:
specifier|const
name|Symbolizer
modifier|*
name|sym_
decl_stmt|;
block|}
empty_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SYMBOLIZER_H
end_comment

end_unit

