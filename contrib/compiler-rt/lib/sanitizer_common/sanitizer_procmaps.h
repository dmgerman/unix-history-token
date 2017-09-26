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
file|"sanitizer_common.h"
end_include

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
name|SANITIZER_FREEBSD
operator|||
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
comment|// Reads process memory map in an OS-specific way.
name|void
name|ReadProcMaps
parameter_list|(
name|ProcSelfMapsBuff
modifier|*
name|proc_maps
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// SANITIZER_FREEBSD || SANITIZER_LINUX
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
struct|struct
name|MemoryMappedSegment
block|{
name|MemoryMappedSegment
argument_list|(
argument|char *buff = nullptr
argument_list|,
argument|uptr size =
literal|0
argument_list|)
block|:
name|filename
argument_list|(
name|buff
argument_list|)
operator|,
name|filename_size
argument_list|(
argument|size
argument_list|)
block|{}
operator|~
name|MemoryMappedSegment
argument_list|()
block|{}
name|bool
name|IsReadable
argument_list|()
block|{
return|return
name|protection
operator|&
name|kProtectionRead
return|;
block|}
name|bool
name|IsWritable
parameter_list|()
block|{
return|return
name|protection
operator|&
name|kProtectionWrite
return|;
block|}
name|bool
name|IsExecutable
parameter_list|()
block|{
return|return
name|protection
operator|&
name|kProtectionExecute
return|;
block|}
name|bool
name|IsShared
parameter_list|()
block|{
return|return
name|protection
operator|&
name|kProtectionShared
return|;
block|}
name|uptr
name|start
decl_stmt|;
name|uptr
name|end
decl_stmt|;
name|uptr
name|offset
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
comment|// owned by caller
name|uptr
name|filename_size
decl_stmt|;
name|uptr
name|protection
decl_stmt|;
name|ModuleArch
name|arch
decl_stmt|;
name|u8
name|uuid
index|[
name|kModuleUUIDSize
index|]
decl_stmt|;
block|}
struct|;
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
operator|~
name|MemoryMappingLayout
argument_list|()
expr_stmt|;
name|bool
name|Next
parameter_list|(
name|MemoryMappedSegment
modifier|*
name|segment
parameter_list|)
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
comment|// In some cases, e.g. when running under a sandbox on Linux, ASan is unable
comment|// to obtain the memory mappings. It should fall back to pre-cached data
comment|// instead of aborting.
specifier|static
name|void
name|CacheMemoryMappings
parameter_list|()
function_decl|;
comment|// Adds all mapped objects into a vector.
name|void
name|DumpListOfModules
argument_list|(
name|InternalMmapVector
operator|<
name|LoadedModule
operator|>
operator|*
name|modules
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|LoadFromCache
parameter_list|()
function_decl|;
comment|// FIXME: Hide implementation details for different platforms in
comment|// platform-specific files.
if|#
directive|if
name|SANITIZER_FREEBSD
operator|||
name|SANITIZER_LINUX
name|ProcSelfMapsBuff
name|proc_self_maps_
decl_stmt|;
specifier|const
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
name|MemoryMappedSegment
operator|*
name|segment
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
name|ModuleArch
name|current_arch_
decl_stmt|;
name|u8
name|current_uuid_
index|[
name|kModuleUUIDSize
index|]
decl_stmt|;
name|int
name|current_load_cmd_count_
decl_stmt|;
name|char
modifier|*
name|current_load_cmd_addr_
decl_stmt|;
name|bool
name|current_instrumented_
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
name|bool
name|IsDecimal
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
name|uptr
name|ParseDecimal
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|p
parameter_list|)
function_decl|;
name|bool
name|IsHex
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
name|uptr
name|ParseHex
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|p
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
comment|// SANITIZER_PROCMAPS_H
end_comment

end_unit

