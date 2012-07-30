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

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|ProcessMaps
block|{
name|public
label|:
name|ProcessMaps
argument_list|()
expr_stmt|;
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
parameter_list|)
function_decl|;
operator|~
name|ProcessMaps
argument_list|()
expr_stmt|;
name|private
label|:
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
name|defined
name|__linux__
name|char
modifier|*
name|proc_self_maps_buff_
decl_stmt|;
name|uptr
name|proc_self_maps_buff_mmaped_size_
decl_stmt|;
name|uptr
name|proc_self_maps_buff_len_
decl_stmt|;
name|char
modifier|*
name|current_
decl_stmt|;
elif|#
directive|elif
name|defined
name|__APPLE__
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
argument_list|)
expr_stmt|;
name|int
name|current_image_
decl_stmt|;
name|u32
name|current_magic_
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

