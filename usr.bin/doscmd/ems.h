begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Helmut Wirth<hfwirth@ping.at>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, witout modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EMS_H
end_ifndef

begin_define
define|#
directive|define
name|EMS_H
end_define

begin_comment
comment|/* Header for ems.c, the EMS emulation */
end_comment

begin_comment
comment|/* Global definitions, some of them will be configurable in the future */
end_comment

begin_define
define|#
directive|define
name|EMS_NUM_HANDLES
value|256
end_define

begin_comment
comment|/* Includes OS handle 0 */
end_comment

begin_define
define|#
directive|define
name|EMS_MAXSIZE
value|10240
end_define

begin_comment
comment|/* In kbytes */
end_comment

begin_define
define|#
directive|define
name|EMS_MAX_PHYS
value|4
end_define

begin_comment
comment|/* Frame is 64kB */
end_comment

begin_define
define|#
directive|define
name|EMS_FRAME_ADDR
value|0xe0000
end_define

begin_define
define|#
directive|define
name|EMS_VERSION
value|0x40
end_define

begin_comment
comment|/* Version 4.0 */
end_comment

begin_define
define|#
directive|define
name|EMS_PAGESIZE
value|(16 *1024)
end_define

begin_comment
comment|/* page size in bytes */
end_comment

begin_define
define|#
directive|define
name|EMS_SAVEMAGIC
value|0xAFFE
end_define

begin_comment
comment|/* magic number */
end_comment

begin_comment
comment|/* These are the LIM EMS 3.0 calls */
end_comment

begin_define
define|#
directive|define
name|GET_MANAGER_STATUS
value|0x40
end_define

begin_define
define|#
directive|define
name|GET_PAGE_FRAME_SEGMENT
value|0x41
end_define

begin_define
define|#
directive|define
name|GET_PAGE_COUNTS
value|0x42
end_define

begin_define
define|#
directive|define
name|GET_HANDLE_AND_ALLOCATE
value|0x43
end_define

begin_define
define|#
directive|define
name|MAP_UNMAP
value|0x44
end_define

begin_define
define|#
directive|define
name|DEALLOCATE_HANDLE
value|0x45
end_define

begin_define
define|#
directive|define
name|GET_EMM_VERSION
value|0x46
end_define

begin_define
define|#
directive|define
name|SAVE_PAGE_MAP
value|0x47
end_define

begin_define
define|#
directive|define
name|RESTORE_PAGE_MAP
value|0x48
end_define

begin_define
define|#
directive|define
name|RESERVED_1
value|0x49
end_define

begin_define
define|#
directive|define
name|RESERVED_2
value|0x4a
end_define

begin_define
define|#
directive|define
name|GET_HANDLE_COUNT
value|0x4b
end_define

begin_define
define|#
directive|define
name|GET_PAGES_OWNED
value|0x4c
end_define

begin_define
define|#
directive|define
name|GET_PAGES_FOR_ALL
value|0x4d
end_define

begin_comment
comment|/* LIM EMS 4.0 calls */
end_comment

begin_comment
comment|/* Global subfunctions for the LIM EMS 4.0 calls */
end_comment

begin_define
define|#
directive|define
name|GET
value|0x0
end_define

begin_define
define|#
directive|define
name|SET
value|0x1
end_define

begin_comment
comment|/* Modes for Map/Unmap and AlterandCall/AlterAndJump */
end_comment

begin_define
define|#
directive|define
name|PHYS_ADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|SEG_ADDR
value|0x0
end_define

begin_comment
comment|/* Page map functions */
end_comment

begin_define
define|#
directive|define
name|PAGE_MAP
value|0x4e
end_define

begin_define
define|#
directive|define
name|PAGE_MAP_PARTIAL
value|0x4f
end_define

begin_comment
comment|/* Page map subfunctions */
end_comment

begin_define
define|#
directive|define
name|GET_SET
value|0x2
end_define

begin_define
define|#
directive|define
name|GET_SIZE
value|0x3
end_define

begin_define
define|#
directive|define
name|MAP_UNMAP_MULTI_HANDLE
value|0x50
end_define

begin_define
define|#
directive|define
name|REALLOC_PAGES
value|0x51
end_define

begin_define
define|#
directive|define
name|HANDLE_ATTRIBUTES
value|0x52
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|HANDLE_CAPABILITY
value|0x2
end_define

begin_define
define|#
directive|define
name|HANDLE_NAME
value|0x53
end_define

begin_define
define|#
directive|define
name|HANDLE_DIRECTORY
value|0x54
end_define

begin_define
define|#
directive|define
name|HANDLE_SEARCH
value|0x1
end_define

begin_define
define|#
directive|define
name|GET_TOTAL_HANDLES
value|0x2
end_define

begin_define
define|#
directive|define
name|ALTER_PAGEMAP_JUMP
value|0x55
end_define

begin_define
define|#
directive|define
name|ALTER_PAGEMAP_CALL
value|0x56
end_define

begin_comment
comment|/* Subfunction for call */
end_comment

begin_define
define|#
directive|define
name|GET_STACK_SIZE
value|0x2
end_define

begin_define
define|#
directive|define
name|MOVE_MEMORY_REGION
value|0x57
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|MOVE
value|0x0
end_define

begin_define
define|#
directive|define
name|EXCHANGE
value|0x1
end_define

begin_define
define|#
directive|define
name|GET_MAPPABLE_PHYS_ADDR
value|0x58
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|GET_ARRAY
value|0x0
end_define

begin_define
define|#
directive|define
name|GET_ARRAY_ENTRIES
value|0x1
end_define

begin_define
define|#
directive|define
name|GET_HW_CONFIGURATION
value|0x59
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|GET_HW_ARRAY
value|0x0
end_define

begin_define
define|#
directive|define
name|GET_RAW_PAGE_COUNT
value|0x1
end_define

begin_define
define|#
directive|define
name|ALLOCATE_PAGES
value|0x5a
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|ALLOC_STANDARD
value|0x0
end_define

begin_define
define|#
directive|define
name|ALLOC_RAW
value|0x1
end_define

begin_define
define|#
directive|define
name|ALTERNATE_MAP_REGISTER
value|0x5b
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|GET_SAVE_ARRAY_SIZE
value|0x2
end_define

begin_define
define|#
directive|define
name|ALLOCATE_REGISTER_SET
value|0x3
end_define

begin_define
define|#
directive|define
name|DEALLOCATE_REGISTER_SET
value|0x4
end_define

begin_define
define|#
directive|define
name|ALLOCATE_DMA
value|0x5
end_define

begin_define
define|#
directive|define
name|ENABLE_DMA
value|0x6
end_define

begin_define
define|#
directive|define
name|DISABLE_DMA
value|0x7
end_define

begin_define
define|#
directive|define
name|DEALLOCATE_DMA
value|0x8
end_define

begin_define
define|#
directive|define
name|PREPARE_WARMBOOT
value|0x5c
end_define

begin_define
define|#
directive|define
name|OS_FUNCTION_SET
value|0x5d
end_define

begin_comment
comment|/* Subfunctions */
end_comment

begin_define
define|#
directive|define
name|ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|DISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|RETURN_KEY
value|0x2
end_define

begin_comment
comment|/* End of call definitions */
end_comment

begin_comment
comment|/* EMS errors */
end_comment

begin_define
define|#
directive|define
name|EMS_SUCCESS
value|0x0
end_define

begin_define
define|#
directive|define
name|EMS_SW_MALFUNC
value|0x80
end_define

begin_define
define|#
directive|define
name|EMS_HW_MALFUNC
value|0x81
end_define

begin_define
define|#
directive|define
name|EMS_INV_HANDLE
value|0x83
end_define

begin_define
define|#
directive|define
name|EMS_FUNC_NOSUP
value|0x84
end_define

begin_define
define|#
directive|define
name|EMS_OUT_OF_HANDLES
value|0x85
end_define

begin_define
define|#
directive|define
name|EMS_SAVED_MAP
value|0x86
end_define

begin_define
define|#
directive|define
name|EMS_OUT_OF_PHYS
value|0x87
end_define

begin_define
define|#
directive|define
name|EMS_OUT_OF_LOG
value|0x88
end_define

begin_define
define|#
directive|define
name|EMS_ZERO_PAGES
value|0x89
end_define

begin_define
define|#
directive|define
name|EMS_LOGPAGE_TOOBIG
value|0x8a
end_define

begin_define
define|#
directive|define
name|EMS_ILL_PHYS
value|0x8b
end_define

begin_define
define|#
directive|define
name|EMS_NO_ROOM_TO_SAVE
value|0x8c
end_define

begin_define
define|#
directive|define
name|EMS_ALREADY_SAVED
value|0x8d
end_define

begin_define
define|#
directive|define
name|EMS_NO_SAVED_CONTEXT
value|0x8e
end_define

begin_define
define|#
directive|define
name|EMS_INVALID_SUB
value|0x8f
end_define

begin_define
define|#
directive|define
name|EMS_INVALID_ATTR
value|0x90
end_define

begin_define
define|#
directive|define
name|EMS_FEAT_NOSUP
value|0x91
end_define

begin_define
define|#
directive|define
name|EMS_MOVE_OVERLAP1
value|0x92
end_define

begin_define
define|#
directive|define
name|EMS_MOVE_OVERFLOW
value|0x93
end_define

begin_define
define|#
directive|define
name|EMS_PAGEOFFSET
value|0x95
end_define

begin_define
define|#
directive|define
name|EMS_MOVE_OVERLAP2
value|0x97
end_define

begin_define
define|#
directive|define
name|EMS_HNAME_NOT_FOUND
value|0xa0
end_define

begin_define
define|#
directive|define
name|EMS_NAME_EXISTS
value|0xa1
end_define

begin_define
define|#
directive|define
name|EMS_SAVED_CONTEXT_BAD
value|0xa3
end_define

begin_define
define|#
directive|define
name|EMS_FUNCTION_DISABLED
value|0xa4
end_define

begin_comment
comment|/*  * EMS handles: The handle contains at its end an array of pointers to  * its allocated pages. The array is of size npages. Handle structs are  * malloced at runtime.  * Page numbering: Every page is 16kB, always. The pages are numbered  * from 0 to highest page, depending on total EMS memory. Every handle  * has pages allocated and this pages too are numbered from 0 to highest  * page allocated. This are *not* the same numbers, because there may be  * holes in the allocation.  * Page numbers are unsigned short, which will give us 65536 * 16 kB (1GB)  * pages to handle at maximum. This should be enough for the next years.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|handle
index|[
literal|4
index|]
decl_stmt|;
comment|/* Handle for each mapping */
name|u_char
name|pos_mapped
index|[
literal|4
index|]
decl_stmt|;
comment|/* Boolean value, 1 if something is mapped */
name|u_char
name|pos_pagenum
index|[
literal|4
index|]
decl_stmt|;
comment|/* Page number currently mapped into position */
block|}
name|EMS_mapping_context
typedef|;
end_typedef

begin_comment
comment|/* This union is for copying operations of the handle name only */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_char
name|uc_hn
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|ul_hn
index|[
literal|2
index|]
decl_stmt|;
block|}
name|Hname
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Hname
name|hname
decl_stmt|;
name|u_long
name|npages
decl_stmt|;
comment|/* The mapping context for save/restore page map */
name|EMS_mapping_context
modifier|*
name|mcontext
decl_stmt|;
comment|/* The pagenum here is the number in the system page array. The       * logical page number connected with this handle is the index into      * this array.      */
name|u_short
name|pagenum
index|[
literal|0
index|]
decl_stmt|;
comment|/* Will grow here, depending on allocation */
block|}
name|EMS_handle
typedef|;
end_typedef

begin_comment
comment|/*  * The connection between every page in the system and the handles is  * maintained by an array of these structs. The array is indexed by the  * page numbers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|handle
decl_stmt|;
comment|/* The handle this page belongs to */
define|#
directive|define
name|EMS_FREE
value|0
define|#
directive|define
name|EMS_ALLOCED
value|1
define|#
directive|define
name|EMS_MAPPED
value|2
name|u_short
name|status
decl_stmt|;
comment|/* room for misc information */
block|}
name|EMS_page
typedef|;
end_typedef

begin_comment
comment|/*  * The combined pointer into EMS memory: offs is the offset into an EMS  * page, page is the page index inside the region allocated to a handle.  * This depends on EMS_PAGESIZE.  * This is used for copy and move operations.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|offs
range|:
literal|14
decl_stmt|;
name|u_long
name|page
range|:
literal|18
decl_stmt|;
block|}
name|EMS_combi
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|u_long
name|ua_addr
decl_stmt|;
comment|/* Conventional address pointer */
name|EMS_combi
name|ua_emsaddr
decl_stmt|;
comment|/* EMS address pointer */
block|}
name|EMS_addr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EMS_OFFS
parameter_list|(
name|u
parameter_list|)
value|u.ua_emsaddr.offs
end_define

begin_define
define|#
directive|define
name|EMS_PAGE
parameter_list|(
name|u
parameter_list|)
value|u.ua_emsaddr.page
end_define

begin_define
define|#
directive|define
name|EMS_PTR
parameter_list|(
name|u
parameter_list|)
value|u.ua_addr
end_define

begin_comment
comment|/*  * EMS info structure, only used to pass information to and from  * DOS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|handle
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* handle */
end_comment

begin_decl_stmt
name|u_short
name|npages
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pages allocated */
end_comment

begin_empty_stmt
unit|} EMShandlepage
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * EMS map/unmap multiple, only used to pass information to and from  * DOS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|log
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* logical page number */
end_comment

begin_decl_stmt
name|u_short
name|phys
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical page (position) or 					      segment address inside frame */
end_comment

begin_empty_stmt
unit|} EMSmapunmap
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * EMS handle directory, only used to pass information to and from  * DOS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|log
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* logical page number */
end_comment

begin_decl_stmt
name|Hname
name|name
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle name */
end_comment

begin_empty_stmt
unit|} EMShandledir
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Structure for get/set page map: This structure is used to save and  * restore the page map from DOS memory. A program can get the mapping  * context and later set (restore) it. To avoid errors we add a magic  * number and a checksum.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|magic
decl_stmt|;
comment|/* Magic number */
name|u_short
name|checksum
decl_stmt|;
comment|/* Checksum over entire structure */
name|EMS_mapping_context
name|ems_saved_context
decl_stmt|;
block|}
name|EMScontext
typedef|;
end_typedef

begin_comment
comment|/*  * EMS physical address array, only used to pass information to and from  * DOS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|segm
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* segment address inside frame */
end_comment

begin_decl_stmt
name|u_short
name|phys
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical page (position) */
end_comment

begin_empty_stmt
unit|} EMSaddrarray
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * EMS move memory call structure, only used to pass information to and from  * DOS   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|length
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* length of region */
end_comment

begin_define
define|#
directive|define
name|EMS_MOVE_CONV
value|0
end_define

begin_define
define|#
directive|define
name|EMS_MOVE_EMS
value|1
end_define

begin_decl_stmt
name|u_char
name|src_type
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source type (0,1) */
end_comment

begin_decl_stmt
name|u_short
name|src_handle
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source handle */
end_comment

begin_decl_stmt
name|u_short
name|src_offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source offset */
end_comment

begin_decl_stmt
name|u_short
name|src_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source type  */
end_comment

begin_decl_stmt
name|u_char
name|dst_type
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination type (0,1) */
end_comment

begin_decl_stmt
name|u_short
name|dst_handle
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination handle */
end_comment

begin_decl_stmt
name|u_short
name|dst_offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination offset */
end_comment

begin_decl_stmt
name|u_short
name|dst_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination type  */
end_comment

begin_empty_stmt
unit|} EMSmovemem
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMS_H */
end_comment

end_unit

