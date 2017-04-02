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
name|ModuleArch
name|module_arch
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
name|FillModuleInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|mod_name
parameter_list|,
name|uptr
name|mod_offset
parameter_list|,
name|ModuleArch
name|arch
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
name|ModuleArch
name|module_arch
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|uptr
name|line
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
name|SymbolizerTool
decl_stmt|;
name|class
name|Symbolizer
name|final
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
specifier|static
name|void
name|LateInitialize
parameter_list|()
function_decl|;
comment|// Returns a list of symbolized frames for a given address (containing
comment|// all inlined functions, if necessary).
name|SymbolizedStack
modifier|*
name|SymbolizePC
parameter_list|(
name|uptr
name|address
parameter_list|)
function_decl|;
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
function_decl|;
comment|// The module names Symbolizer returns are stable and unique for every given
comment|// module.  It is safe to store and compare them as pointers.
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
function_decl|;
specifier|const
name|char
modifier|*
name|GetModuleNameForPc
parameter_list|(
name|uptr
name|pc
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|module_name
init|=
name|nullptr
decl_stmt|;
name|uptr
name|unused
decl_stmt|;
if|if
condition|(
name|GetModuleNameAndOffsetForPC
argument_list|(
name|pc
argument_list|,
operator|&
name|module_name
argument_list|,
operator|&
name|unused
argument_list|)
condition|)
return|return
name|module_name
return|;
return|return
name|nullptr
return|;
block|}
comment|// Release internal caches (if any).
name|void
name|Flush
parameter_list|()
function_decl|;
comment|// Attempts to demangle the provided C++ mangled name.
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
function_decl|;
name|void
name|PrepareForSandboxing
parameter_list|()
function_decl|;
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
specifier|const
name|LoadedModule
modifier|*
name|FindModuleForAddress
parameter_list|(
name|uptr
name|address
parameter_list|)
function_decl|;
name|private
label|:
comment|// GetModuleNameAndOffsetForPC has to return a string to the caller.
comment|// Since the corresponding module might get unloaded later, we should create
comment|// our owned copies of the strings that we can safely return.
comment|// ModuleNameOwner does not provide any synchronization, thus calls to
comment|// its method should be protected by |mu_|.
name|class
name|ModuleNameOwner
block|{
name|public
label|:
name|explicit
name|ModuleNameOwner
argument_list|(
name|BlockingMutex
operator|*
name|synchronized_by
argument_list|)
operator|:
name|storage_
argument_list|(
name|kInitialCapacity
argument_list|)
operator|,
name|last_match_
argument_list|(
name|nullptr
argument_list|)
operator|,
name|mu_
argument_list|(
argument|synchronized_by
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|GetOwnedCopy
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
expr_stmt|;
name|private
label|:
specifier|static
specifier|const
name|uptr
name|kInitialCapacity
init|=
literal|1000
decl_stmt|;
name|InternalMmapVector
operator|<
specifier|const
name|char
operator|*
operator|>
name|storage_
expr_stmt|;
specifier|const
name|char
modifier|*
name|last_match_
decl_stmt|;
name|BlockingMutex
modifier|*
name|mu_
decl_stmt|;
block|}
name|module_names_
expr_stmt|;
comment|/// Platform-specific function for creating a Symbolizer object.
specifier|static
name|Symbolizer
modifier|*
name|PlatformInit
parameter_list|()
function_decl|;
name|bool
name|FindModuleNameAndOffsetForAddress
parameter_list|(
name|uptr
name|address
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|module_name
parameter_list|,
name|uptr
modifier|*
name|module_offset
parameter_list|,
name|ModuleArch
modifier|*
name|module_arch
parameter_list|)
function_decl|;
name|ListOfModules
name|modules_
decl_stmt|;
comment|// If stale, need to reload the modules before looking up addresses.
name|bool
name|modules_fresh_
decl_stmt|;
comment|// Platform-specific default demangler, must not return nullptr.
specifier|const
name|char
modifier|*
name|PlatformDemangle
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|PlatformPrepareForSandboxing
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
comment|// Mutex locked from public methods of |Symbolizer|, so that the internals
comment|// (including individual symbolizer tools and platform-specific methods) are
comment|// always synchronized.
name|BlockingMutex
name|mu_
decl_stmt|;
name|IntrusiveList
operator|<
name|SymbolizerTool
operator|>
name|tools_
expr_stmt|;
name|explicit
name|Symbolizer
argument_list|(
name|IntrusiveList
operator|<
name|SymbolizerTool
operator|>
name|tools
argument_list|)
decl_stmt|;
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
ifdef|#
directive|ifdef
name|SANITIZER_WINDOWS
name|void
name|InitializeDbgHelpIfNeeded
parameter_list|()
function_decl|;
endif|#
directive|endif
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

