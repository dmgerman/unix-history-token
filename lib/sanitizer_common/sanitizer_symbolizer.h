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
file|"sanitizer_allocator_internal.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_libc.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
struct|struct
name|AddressInfo
block|{
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
name|char
modifier|*
name|function
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
block|{
name|internal_memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|AddressInfo
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Deletes all strings and sets all fields to zero.
name|void
name|Clear
parameter_list|()
block|{
name|InternalFree
argument_list|(
name|module
argument_list|)
expr_stmt|;
name|InternalFree
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|InternalFree
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|internal_memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|AddressInfo
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
block|{
name|address
operator|=
name|addr
expr_stmt|;
name|module
operator|=
name|internal_strdup
argument_list|(
name|mod_name
argument_list|)
expr_stmt|;
name|module_offset
operator|=
name|mod_offset
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|DataInfo
block|{
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
block|}
struct|;
name|class
name|Symbolizer
block|{
name|public
label|:
comment|/// Returns platform-specific implementation of Symbolizer. The symbolizer
comment|/// must be initialized (with init or disable) before calling this function.
specifier|static
name|Symbolizer
modifier|*
name|Get
parameter_list|()
function_decl|;
comment|/// Returns platform-specific implementation of Symbolizer, or null if not
comment|/// initialized.
specifier|static
name|Symbolizer
modifier|*
name|GetOrNull
parameter_list|()
function_decl|;
comment|/// Returns platform-specific implementation of Symbolizer.  Will
comment|/// automatically initialize symbolizer as if by calling Init(0) if needed.
specifier|static
name|Symbolizer
modifier|*
name|GetOrInit
parameter_list|()
function_decl|;
comment|/// Initialize and return the symbolizer, given an optional path to an
comment|/// external symbolizer.  The path argument is only required for legacy
comment|/// reasons as this function will check $PATH for an external symbolizer.  Not
comment|/// thread safe.
specifier|static
name|Symbolizer
modifier|*
name|Init
parameter_list|(
specifier|const
name|char
modifier|*
name|path_to_external
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Initialize the symbolizer in a disabled state.  Not thread safe.
specifier|static
name|Symbolizer
modifier|*
name|Disable
parameter_list|()
function_decl|;
comment|// Fills at most "max_frames" elements of "frames" with descriptions
comment|// for a given address (in all inlined functions). Returns the number
comment|// of descriptions actually filled.
name|virtual
name|uptr
name|SymbolizeCode
parameter_list|(
name|uptr
name|address
parameter_list|,
name|AddressInfo
modifier|*
name|frames
parameter_list|,
name|uptr
name|max_frames
parameter_list|)
block|{
return|return
literal|0
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
name|IsAvailable
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|IsExternalAvailable
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
parameter_list|(
specifier|const
name|char
modifier|*
name|path_to_external
parameter_list|)
function_decl|;
comment|/// Create a symbolizer and store it to symbolizer_ without checking if one
comment|/// already exists.  Not thread safe.
specifier|static
name|Symbolizer
modifier|*
name|CreateAndStore
parameter_list|(
specifier|const
name|char
modifier|*
name|path_to_external
parameter_list|)
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

