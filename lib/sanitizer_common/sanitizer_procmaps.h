begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_procmaps.h ------------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Information about the process mappings.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_PROCMAPS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_PROCMAPS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
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
if|#
directive|if
name|SANITIZER_WINDOWS
name|class
name|MemoryMappingLayout
block|{
name|public
label|:
name|explicit
name|MemoryMappingLayout
parameter_list|(
name|bool
name|cache_enabled
parameter_list|)
block|{
operator|(
name|void
operator|)
name|cache_enabled
expr_stmt|;
block|}
name|bool
name|GetObjectNameAndOffset
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
modifier|*
name|offset
parameter_list|,
name|char
name|filename
index|[]
parameter_list|,
name|uptr
name|filename_size
parameter_list|,
name|uptr
modifier|*
name|protection
parameter_list|)
block|{
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
else|#
directive|else
comment|// SANITIZER_WINDOWS
if|#
directive|if
name|SANITIZER_LINUX
struct|struct
name|ProcSelfMapsBuff
block|{
name|char
modifier|*
name|data
decl_stmt|;
name|uptr
name|mmaped_size
decl_stmt|;
name|uptr
name|len
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|// SANITIZER_LINUX
name|class
name|MemoryMappingLayout
block|{
name|public
label|:
name|explicit
name|MemoryMappingLayout
parameter_list|(
name|bool
name|cache_enabled
parameter_list|)
function_decl|;
name|bool
name|Next
parameter_list|(
name|uptr
modifier|*
name|start
parameter_list|,
name|uptr
modifier|*
name|end
parameter_list|,
name|uptr
modifier|*
name|offset
parameter_list|,
name|char
name|filename
index|[]
parameter_list|,
name|uptr
name|filename_size
parameter_list|,
name|uptr
modifier|*
name|protection
parameter_list|)
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
comment|// Gets the object file name and the offset in that object for a given
comment|// address 'addr'. Returns true on success.
name|bool
name|GetObjectNameAndOffset
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
modifier|*
name|offset
parameter_list|,
name|char
name|filename
index|[]
parameter_list|,
name|uptr
name|filename_size
parameter_list|,
name|uptr
modifier|*
name|protection
parameter_list|)
function_decl|;
comment|// In some cases, e.g. when running under a sandbox on Linux, ASan is unable
comment|// to obtain the memory mappings. It should fall back to pre-cached data
comment|// instead of aborting.
specifier|static
name|void
name|CacheMemoryMappings
parameter_list|()
function_decl|;
operator|~
name|MemoryMappingLayout
argument_list|()
expr_stmt|;
comment|// Memory protection masks.
specifier|static
specifier|const
name|uptr
name|kProtectionRead
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kProtectionWrite
init|=
literal|2
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kProtectionExecute
init|=
literal|4
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kProtectionShared
init|=
literal|8
decl_stmt|;
name|private
label|:
name|void
name|LoadFromCache
parameter_list|()
function_decl|;
comment|// Default implementation of GetObjectNameAndOffset.
comment|// Quite slow, because it iterates through the whole process map for each
comment|// lookup.
name|bool
name|IterateForObjectNameAndOffset
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|uptr
modifier|*
name|offset
parameter_list|,
name|char
name|filename
index|[]
parameter_list|,
name|uptr
name|filename_size
parameter_list|,
name|uptr
modifier|*
name|protection
parameter_list|)
block|{
name|Reset
argument_list|()
expr_stmt|;
name|uptr
name|start
decl_stmt|,
name|end
decl_stmt|,
name|file_offset
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|Next
argument_list|(
operator|&
name|start
argument_list|,
operator|&
name|end
argument_list|,
operator|&
name|file_offset
argument_list|,
name|filename
argument_list|,
name|filename_size
argument_list|,
name|protection
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|addr
operator|>=
name|start
operator|&&
name|addr
operator|<
name|end
condition|)
block|{
comment|// Don't subtract 'start' for the first entry:
comment|// * If a binary is compiled w/o -pie, then the first entry in
comment|//   process maps is likely the binary itself (all dynamic libs
comment|//   are mapped higher in address space). For such a binary,
comment|//   instruction offset in binary coincides with the actual
comment|//   instruction address in virtual memory (as code section
comment|//   is mapped to a fixed memory range).
comment|// * If a binary is compiled with -pie, all the modules are
comment|//   mapped high at address space (in particular, higher than
comment|//   shadow memory of the tool), so the module can't be the
comment|//   first entry.
operator|*
name|offset
operator|=
operator|(
name|addr
operator|-
operator|(
name|i
condition|?
name|start
else|:
literal|0
operator|)
operator|)
operator|+
name|file_offset
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
if|if
condition|(
name|filename_size
condition|)
name|filename
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|false
return|;
block|}
if|#
directive|if
name|SANITIZER_LINUX
name|ProcSelfMapsBuff
name|proc_self_maps_
decl_stmt|;
name|char
modifier|*
name|current_
decl_stmt|;
comment|// Static mappings cache.
specifier|static
name|ProcSelfMapsBuff
name|cached_proc_self_maps_
decl_stmt|;
specifier|static
name|StaticSpinMutex
name|cache_lock_
decl_stmt|;
comment|// protects cached_proc_self_maps_.
elif|#
directive|elif
name|SANITIZER_MAC
name|template
operator|<
name|u32
name|kLCSegment
operator|,
name|typename
name|SegmentCommand
operator|>
name|bool
name|NextSegmentLoad
argument_list|(
argument|uptr *start
argument_list|,
argument|uptr *end
argument_list|,
argument|uptr *offset
argument_list|,
argument|char filename[]
argument_list|,
argument|uptr filename_size
argument_list|,
argument|uptr *protection
argument_list|)
expr_stmt|;
name|int
name|current_image_
decl_stmt|;
name|u32
name|current_magic_
decl_stmt|;
name|u32
name|current_filetype_
decl_stmt|;
name|int
name|current_load_cmd_count_
decl_stmt|;
name|char
modifier|*
name|current_load_cmd_addr_
decl_stmt|;
endif|#
directive|endif
block|}
empty_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|fill_profile_f
function_decl|)
parameter_list|(
name|uptr
name|start
parameter_list|,
name|uptr
name|rss
parameter_list|,
name|bool
name|file
parameter_list|,
comment|/*out*/
name|uptr
modifier|*
name|stats
parameter_list|,
name|uptr
name|stats_size
parameter_list|)
function_decl|;
comment|// Parse the contents of /proc/self/smaps and generate a memory profile.
comment|// |cb| is a tool-specific callback that fills the |stats| array containing
comment|// |stats_size| elements.
name|void
name|GetMemoryProfile
parameter_list|(
name|fill_profile_f
name|cb
parameter_list|,
name|uptr
modifier|*
name|stats
parameter_list|,
name|uptr
name|stats_size
parameter_list|)
function_decl|;
comment|// Returns code range for the specified module.
name|bool
name|GetCodeRangeForFile
parameter_list|(
specifier|const
name|char
modifier|*
name|module
parameter_list|,
name|uptr
modifier|*
name|start
parameter_list|,
name|uptr
modifier|*
name|end
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// SANITIZER_WINDOWS
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
comment|// SANITIZER_PROCMAPS_H
end_comment

end_unit

