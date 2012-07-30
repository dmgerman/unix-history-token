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
block|}
struct|;
comment|// Fills at most "max_frames" elements of "frames" with descriptions
comment|// for a given address (in all inlined functions). Returns the number
comment|// of descriptions actually filled.
comment|// This function should NOT be called from two threads simultaneously.
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
function_decl|;
comment|// Debug info routines
struct|struct
name|DWARFSection
block|{
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
name|uptr
name|size
decl_stmt|;
name|DWARFSection
argument_list|()
block|{
name|data
operator|=
literal|0
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
block|}
block|}
struct|;
comment|// Returns true on success.
name|bool
name|FindDWARFSection
parameter_list|(
name|uptr
name|object_file_addr
parameter_list|,
specifier|const
name|char
modifier|*
name|section_name
parameter_list|,
name|DWARFSection
modifier|*
name|section
parameter_list|)
function_decl|;
name|bool
name|IsFullNameOfDWARFSection
parameter_list|(
specifier|const
name|char
modifier|*
name|full_name
parameter_list|,
specifier|const
name|char
modifier|*
name|short_name
parameter_list|)
function_decl|;
name|class
name|ModuleDIContext
block|{
name|public
label|:
name|ModuleDIContext
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
name|void
name|getAddressInfo
parameter_list|(
name|AddressInfo
modifier|*
name|info
parameter_list|)
function_decl|;
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
name|private
label|:
name|void
name|CreateDIContext
parameter_list|()
function_decl|;
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
name|char
modifier|*
name|short_name_
decl_stmt|;
name|uptr
name|base_address_
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kMaxNumberOfAddressRanges
init|=
literal|8
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
name|uptr
name|mapped_addr_
decl_stmt|;
name|uptr
name|mapped_size_
decl_stmt|;
block|}
empty_stmt|;
comment|// OS-dependent function that gets the linked list of all loaded modules.
name|uptr
name|GetListOfModules
parameter_list|(
name|ModuleDIContext
modifier|*
name|modules
parameter_list|,
name|uptr
name|max_modules
parameter_list|)
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

