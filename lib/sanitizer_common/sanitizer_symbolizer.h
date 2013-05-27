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
comment|// Symbolizer is intended to be used by both
end_comment

begin_comment
comment|// AddressSanitizer and ThreadSanitizer to symbolize a given
end_comment

begin_comment
comment|// address. It is an analogue of addr2line utility and allows to map
end_comment

begin_comment
comment|// instruction address to a location in source code at run-time.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbolizer is planned to use debug information (in DWARF format)
end_comment

begin_comment
comment|// in a binary via interface defined in "llvm/DebugInfo/DIContext.h"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Symbolizer code should be called from the run-time library of
end_comment

begin_comment
comment|// dynamic tools, and generally should not call memory allocation
end_comment

begin_comment
comment|// routines or other system library functions intercepted by those tools.
end_comment

begin_comment
comment|// Instead, Symbolizer code should use their replacements, defined in
end_comment

begin_comment
comment|// "compiler-rt/lib/sanitizer_common/sanitizer_libc.h".
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
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_libc.h"
end_include

begin_comment
comment|// WARNING: Do not include system headers here. See details above.
end_comment

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
comment|// Fills at most "max_frames" elements of "frames" with descriptions
comment|// for a given address (in all inlined functions). Returns the number
comment|// of descriptions actually filled.
comment|// This function should NOT be called from two threads simultaneously.
name|uptr
name|SymbolizeCode
argument_list|(
name|uptr
name|address
argument_list|,
name|AddressInfo
operator|*
name|frames
argument_list|,
name|uptr
name|max_frames
argument_list|)
name|SANITIZER_WEAK_ATTRIBUTE
decl_stmt|;
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
name|bool
name|IsSymbolizerAvailable
parameter_list|()
function_decl|;
name|void
name|FlushSymbolizer
parameter_list|()
function_decl|;
comment|// releases internal caches (if any)
comment|// Attempts to demangle the provided C++ mangled name.
specifier|const
name|char
modifier|*
name|Demangle
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|// Starts external symbolizer program in a subprocess. Sanitizer communicates
comment|// with external symbolizer via pipes.
name|bool
name|InitializeExternalSymbolizer
parameter_list|(
specifier|const
name|char
modifier|*
name|path_to_symbolizer
parameter_list|)
function_decl|;
name|class
name|LoadedModule
block|{
name|public
label|:
name|LoadedModule
argument_list|(
argument|const char *module_name
argument_list|,
argument|uptr base_address
argument_list|)
empty_stmt|;
name|void
name|addAddressRange
parameter_list|(
name|uptr
name|beg
parameter_list|,
name|uptr
name|end
parameter_list|)
function_decl|;
name|bool
name|containsAddress
argument_list|(
name|uptr
name|address
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
operator|*
name|full_name
argument_list|()
specifier|const
block|{
return|return
name|full_name_
return|;
block|}
name|uptr
name|base_address
argument_list|()
specifier|const
block|{
return|return
name|base_address_
return|;
block|}
name|private
label|:
struct|struct
name|AddressRange
block|{
name|uptr
name|beg
decl_stmt|;
name|uptr
name|end
decl_stmt|;
block|}
struct|;
name|char
modifier|*
name|full_name_
decl_stmt|;
name|uptr
name|base_address_
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kMaxNumberOfAddressRanges
init|=
literal|6
decl_stmt|;
name|AddressRange
name|ranges_
index|[
name|kMaxNumberOfAddressRanges
index|]
decl_stmt|;
name|uptr
name|n_ranges_
decl_stmt|;
block|}
empty_stmt|;
comment|// Creates external symbolizer connected via pipe, user should write
comment|// to output_fd and read from input_fd.
name|bool
name|StartSymbolizerSubprocess
parameter_list|(
specifier|const
name|char
modifier|*
name|path_to_symbolizer
parameter_list|,
name|int
modifier|*
name|input_fd
parameter_list|,
name|int
modifier|*
name|output_fd
parameter_list|)
function_decl|;
comment|// OS-dependent function that fills array with descriptions of at most
comment|// "max_modules" currently loaded modules. Returns the number of
comment|// initialized modules. If filter is nonzero, ignores modules for which
comment|// filter(full_name) is false.
typedef|typedef
name|bool
function_decl|(
modifier|*
name|string_predicate_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|uptr
name|GetListOfModules
parameter_list|(
name|LoadedModule
modifier|*
name|modules
parameter_list|,
name|uptr
name|max_modules
parameter_list|,
name|string_predicate_t
name|filter
parameter_list|)
function_decl|;
name|void
name|SymbolizerPrepareForSandboxing
parameter_list|()
function_decl|;
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

