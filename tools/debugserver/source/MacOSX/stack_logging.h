begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2007 Apple Inc. All rights reserved.  *  * @APPLE_LICENSE_HEADER_START@  *  * This file contains Original Code and/or Modifications of Original Code  * as defined in and that are subject to the Apple Public Source License  * Version 2.0 (the 'License'). You may not use this file except in  * compliance with the License. Please obtain a copy of the License at  * http://www.opensource.apple.com/apsl/ and read it before using this  * file.  *  * The Original Code and all software distributed under the License are  * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER  * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,  * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.  * Please see the License for the specific language governing rights and  * limitations under the License.  *  * @APPLE_LICENSE_HEADER_END@  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|malloc_history_test_stack_logging_h
end_ifndef

begin_define
define|#
directive|define
name|malloc_history_test_stack_logging_h
end_define

begin_empty
empty|#import<malloc/malloc.h>
end_empty

begin_define
define|#
directive|define
name|stack_logging_type_free
value|0
end_define

begin_define
define|#
directive|define
name|stack_logging_type_generic
define|\
value|1
end_define

begin_comment
comment|/* anything that is not allocation/deallocation */
end_comment

begin_define
define|#
directive|define
name|stack_logging_type_alloc
value|2
end_define

begin_comment
comment|/* malloc, realloc, etc... */
end_comment

begin_define
define|#
directive|define
name|stack_logging_type_dealloc
value|4
end_define

begin_comment
comment|/* free, realloc, etc... */
end_comment

begin_comment
comment|// Following flags are absorbed by stack_logging_log_stack()
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_zone
value|8
end_define

begin_comment
comment|/* NSZoneMalloc, etc... */
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_calloc
value|16
end_define

begin_comment
comment|/* multiply arguments to get the size */
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_object
define|\
value|32
end_define

begin_comment
comment|/* NSAllocateObject(Class, extraBytes, zone) */
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_cleared
value|64
end_define

begin_comment
comment|/* for NewEmptyHandle */
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_handle
value|128
end_define

begin_comment
comment|/* for Handle (de-)allocation routines   \                                          */
end_comment

begin_define
define|#
directive|define
name|stack_logging_flag_set_handle_size
define|\
value|256
end_define

begin_comment
comment|/* (Handle, newSize) treated specially */
end_comment

begin_comment
comment|/* Macro used to disguise addresses so that leak finding can work */
end_comment

begin_define
define|#
directive|define
name|STACK_LOGGING_DISGUISE
parameter_list|(
name|address
parameter_list|)
define|\
value|((address) ^ 0x00005555)
end_define

begin_comment
comment|/* nicely idempotent */
end_comment

begin_extern
extern|extern
literal|"C"
name|int
name|stack_logging_enable_logging
decl_stmt|;
end_extern

begin_comment
comment|/* when clear, no logging takes place */
end_comment

begin_extern
extern|extern
literal|"C"
name|int
name|stack_logging_dontcompact
decl_stmt|;
end_extern

begin_comment
comment|/* default is to compact; when set                                              does not compact alloc/free logs;                                              useful for tracing history */
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|stack_logging_log_stack
parameter_list|(
name|unsigned
name|type
parameter_list|,
name|unsigned
name|arg1
parameter_list|,
name|unsigned
name|arg2
parameter_list|,
name|unsigned
name|arg3
parameter_list|,
name|unsigned
name|result
parameter_list|,
name|unsigned
name|num_hot_to_skip
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* This is the old log-to-memory logger, which is now deprecated.  It remains  * for compatibility with performance tools that haven't been updated to  * disk_stack_logging_log_stack() yet. */
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|__disk_stack_logging_log_stack
parameter_list|(
name|uint32_t
name|type_flags
parameter_list|,
name|uintptr_t
name|zone_ptr
parameter_list|,
name|uintptr_t
name|size
parameter_list|,
name|uintptr_t
name|ptr_arg
parameter_list|,
name|uintptr_t
name|return_val
parameter_list|,
name|uint32_t
name|num_hot_to_skip
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Fits as the malloc_logger; logs malloc/free/realloc events and can log custom  * events if called directly */
end_comment

begin_comment
comment|/* 64-bit-aware stack log access. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|type_flags
decl_stmt|;
name|uint64_t
name|stack_identifier
decl_stmt|;
name|uint64_t
name|argument
decl_stmt|;
name|mach_vm_address_t
name|address
decl_stmt|;
block|}
name|mach_stack_logging_record_t
typedef|;
end_typedef

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|__mach_stack_logging_get_frames
parameter_list|(
name|task_t
name|task
parameter_list|,
name|mach_vm_address_t
name|address
parameter_list|,
name|mach_vm_address_t
modifier|*
name|stack_frames_buffer
parameter_list|,
name|uint32_t
name|max_stack_frames
parameter_list|,
name|uint32_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Gets the last allocation record (malloc, realloc, or free) about address */
end_comment

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|__mach_stack_logging_enumerate_records
parameter_list|(
name|task_t
name|task
parameter_list|,
name|mach_vm_address_t
name|address
parameter_list|,
name|void
name|enumerator
parameter_list|(
name|mach_stack_logging_record_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Applies enumerator to all records involving address sending context as  * enumerator's second parameter; if !address, applies enumerator to all records  */
end_comment

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|__mach_stack_logging_frames_for_uniqued_stack
parameter_list|(
name|task_t
name|task
parameter_list|,
name|uint64_t
name|stack_identifier
parameter_list|,
name|mach_vm_address_t
modifier|*
name|stack_frames_buffer
parameter_list|,
name|uint32_t
name|max_stack_frames
parameter_list|,
name|uint32_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Given a uniqued_stack fills stack_frames_buffer */
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|-
end_pragma

begin_pragma
pragma|#
directive|pragma
name|mark
name|Legacy
end_pragma

begin_comment
comment|/* The following is the old 32-bit-only, in-process-memory stack logging.  This  * is deprecated and clients should move to the above 64-bit-aware disk stack  * logging SPI. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|uniqued_stack
decl_stmt|;
name|unsigned
name|argument
decl_stmt|;
name|unsigned
name|address
decl_stmt|;
comment|/* disguised, to avoid confusing leaks */
block|}
name|stack_logging_record_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|overall_num_bytes
decl_stmt|;
name|unsigned
name|num_records
decl_stmt|;
name|unsigned
name|lock
decl_stmt|;
comment|/* 0 means OK to lock; used for inter-process locking */
name|unsigned
modifier|*
name|uniquing_table
decl_stmt|;
comment|/* allocated using vm_allocate() */
comment|/* hashtable organized as (PC, uniqued parent)    Only the second half of the table is active    To enable us to grow dynamically */
name|unsigned
name|uniquing_table_num_pages
decl_stmt|;
comment|/* number of pages of the table */
name|unsigned
name|extra_retain_count
decl_stmt|;
comment|/* not used by stack_logging_log_stack */
name|unsigned
name|filler
index|[
literal|2
index|]
decl_stmt|;
comment|/* align to cache lines for better performance */
name|stack_logging_record_t
name|records
index|[
literal|0
index|]
decl_stmt|;
comment|/* records follow here */
block|}
name|stack_logging_record_list_t
typedef|;
end_typedef

begin_extern
extern|extern
literal|"C"
name|stack_logging_record_list_t
modifier|*
name|stack_logging_the_record_list
decl_stmt|;
end_extern

begin_comment
comment|/* This is the global variable containing all logs */
end_comment

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|stack_logging_get_frames
parameter_list|(
name|task_t
name|task
parameter_list|,
name|memory_reader_t
name|reader
parameter_list|,
name|vm_address_t
name|address
parameter_list|,
name|vm_address_t
modifier|*
name|stack_frames_buffer
parameter_list|,
name|unsigned
name|max_stack_frames
parameter_list|,
name|unsigned
modifier|*
name|num_frames
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Gets the last record in stack_logging_the_record_list about address */
end_comment

begin_define
define|#
directive|define
name|STACK_LOGGING_ENUMERATION_PROVIDED
define|\
value|1
end_define

begin_comment
comment|// temporary to avoid dependencies between projects
end_comment

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|stack_logging_enumerate_records
parameter_list|(
name|task_t
name|task
parameter_list|,
name|memory_reader_t
name|reader
parameter_list|,
name|vm_address_t
name|address
parameter_list|,
name|void
name|enumerator
parameter_list|(
name|stack_logging_record_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Gets all the records about address;  If !address, gets all records */
end_comment

begin_extern
extern|extern
literal|"C"
name|kern_return_t
name|stack_logging_frames_for_uniqued_stack
parameter_list|(
name|task_t
name|task
parameter_list|,
name|memory_reader_t
name|reader
parameter_list|,
name|unsigned
name|uniqued_stack
parameter_list|,
name|vm_address_t
modifier|*
name|stack_frames_buffer
parameter_list|,
name|unsigned
name|max_stack_frames
parameter_list|,
name|unsigned
modifier|*
name|num_frames
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Given a uniqued_stack fills stack_frames_buffer */
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|thread_stack_pcs
parameter_list|(
name|vm_address_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|max
parameter_list|,
name|unsigned
modifier|*
name|num
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Convenience to fill buffer with the PCs of the frames, starting with the hot  frames;  num: returned number of frames  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

