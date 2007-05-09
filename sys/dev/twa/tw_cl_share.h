begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_CL_SHARE_H
end_ifndef

begin_define
define|#
directive|define
name|TW_CL_SHARE_H
end_define

begin_comment
comment|/*  * Macros, structures and functions shared between OSL and CL,  * and defined by CL.  */
end_comment

begin_define
define|#
directive|define
name|TW_CL_NULL
value|((TW_VOID *)0)
end_define

begin_define
define|#
directive|define
name|TW_CL_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|TW_CL_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TW_CL_VENDOR_ID
value|0x13C1
end_define

begin_comment
comment|/* 3ware vendor id */
end_comment

begin_define
define|#
directive|define
name|TW_CL_DEVICE_ID_9K
value|0x1002
end_define

begin_comment
comment|/* 9000 PCI series device id */
end_comment

begin_define
define|#
directive|define
name|TW_CL_DEVICE_ID_9K_X
value|0x1003
end_define

begin_comment
comment|/* 9000 PCI-X series device id */
end_comment

begin_define
define|#
directive|define
name|TW_CL_DEVICE_ID_9K_E
value|0x1004
end_define

begin_comment
comment|/* 9000 PCIe series device id */
end_comment

begin_define
define|#
directive|define
name|TW_CL_BAR_TYPE_IO
value|1
end_define

begin_comment
comment|/* I/O base address */
end_comment

begin_define
define|#
directive|define
name|TW_CL_BAR_TYPE_MEM
value|2
end_define

begin_comment
comment|/* memory base address */
end_comment

begin_define
define|#
directive|define
name|TW_CL_BAR_TYPE_SBUF
value|3
end_define

begin_comment
comment|/* SBUF base address */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_ENCLOSURE_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|TW_CL_MAX_NUM_UNITS
value|65
end_define

begin_comment
comment|/* max # of units we support 						-- enclosure target id is 64 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TW_OSL_ENCLOSURE_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_NUM_UNITS
value|32
end_define

begin_comment
comment|/* max # of units we support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_ENCLOSURE_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_NUM_LUNS
value|16
end_define

begin_comment
comment|/* max # of LUN's we support */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_IO_SIZE
value|0x20000
end_define

begin_comment
comment|/* 128K */
end_comment

begin_comment
comment|/*  * Though we can support 256 simultaneous requests, we advertise as capable  * of supporting only 255, since we want to keep one CL internal request  * context packet always available for internal requests.  */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_SIMULTANEOUS_REQUESTS
value|0xFF
end_define

begin_comment
comment|/* max simult reqs supported */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_32BIT_SG_ELEMENTS
value|109
end_define

begin_comment
comment|/* max 32-bit sg elements */
end_comment

begin_define
define|#
directive|define
name|TW_CL_MAX_64BIT_SG_ELEMENTS
value|72
end_define

begin_comment
comment|/* max 64-bit sg elements */
end_comment

begin_comment
comment|/* Possible values of ctlr->flags */
end_comment

begin_define
define|#
directive|define
name|TW_CL_64BIT_ADDRESSES
value|(1<<0)
end_define

begin_comment
comment|/* 64 bit cmdpkt& SG addresses */
end_comment

begin_define
define|#
directive|define
name|TW_CL_64BIT_SG_LENGTH
value|(1<<1)
end_define

begin_comment
comment|/* 64 bit SG length */
end_comment

begin_define
define|#
directive|define
name|TW_CL_START_CTLR_ONLY
value|(1<<2)
end_define

begin_comment
comment|/* Start ctlr only */
end_comment

begin_define
define|#
directive|define
name|TW_CL_STOP_CTLR_ONLY
value|(1<<3)
end_define

begin_comment
comment|/* Stop ctlr only */
end_comment

begin_define
define|#
directive|define
name|TW_CL_DEFERRED_INTR_USED
value|(1<<5)
end_define

begin_comment
comment|/* OS Layer uses deferred intr */
end_comment

begin_comment
comment|/* Possible error values from the Common Layer. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_GENERAL_FAILURE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_INVALID_TARGET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_INVALID_LUN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_SCSI_ERROR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_AUTO_SENSE_VALID
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_BUS_RESET
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TW_CL_ERR_REQ_UNABLE_TO_SUBMIT_COMMAND
value|(1<<6)
end_define

begin_comment
comment|/* Possible values of req_pkt->flags */
end_comment

begin_define
define|#
directive|define
name|TW_CL_REQ_RETRY_ON_BUSY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TW_CL_REQ_CALLBACK_FOR_SGLIST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_CONTROLLER_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_CONTROLLER_EVENT
value|4
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_COMMON_LAYER_ERROR
value|21
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_COMMON_LAYER_EVENT
value|22
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_FREEBSD_DRIVER
value|5
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_FREEBSD_OS
value|8
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_WINDOWS_DRIVER
value|7
end_define

begin_define
define|#
directive|define
name|TW_CL_MESSAGE_SOURCE_WINDOWS_OS
value|10
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_WARNING
value|0x2
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_INFO
value|0x3
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_DEBUG
value|0x4
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_ERROR_STRING
value|"ERROR"
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_WARNING_STRING
value|"WARNING"
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_INFO_STRING
value|"INFO"
end_define

begin_define
define|#
directive|define
name|TW_CL_SEVERITY_DEBUG_STRING
value|"DEBUG"
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/*  * Structure, a pointer to which is used as the controller handle in  * communications between the OS Layer and the Common Layer.  */
end_comment

begin_struct
struct|struct
name|tw_cl_ctlr_handle
block|{
name|TW_VOID
modifier|*
name|osl_ctlr_ctxt
decl_stmt|;
comment|/* OSL's ctlr context */
name|TW_VOID
modifier|*
name|cl_ctlr_ctxt
decl_stmt|;
comment|/* CL's ctlr context */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure, a pointer to which is used as the request handle in  * communications between the OS Layer and the Common Layer.  */
end_comment

begin_struct
struct|struct
name|tw_cl_req_handle
block|{
name|TW_VOID
modifier|*
name|osl_req_ctxt
decl_stmt|;
comment|/* OSL's request context */
name|TW_VOID
modifier|*
name|cl_req_ctxt
decl_stmt|;
comment|/* CL's request context */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure used to describe SCSI requests to CL. */
end_comment

begin_struct
struct|struct
name|tw_cl_scsi_req_packet
block|{
name|TW_UINT32
name|unit
decl_stmt|;
comment|/* unit # to send cmd to */
name|TW_UINT32
name|lun
decl_stmt|;
comment|/* LUN to send cmd to */
name|TW_UINT8
modifier|*
name|cdb
decl_stmt|;
comment|/* ptr to SCSI cdb */
name|TW_UINT32
name|cdb_len
decl_stmt|;
comment|/* # of valid cdb bytes */
name|TW_UINT32
name|sense_len
decl_stmt|;
comment|/* # of bytes of valid sense info */
name|TW_UINT8
modifier|*
name|sense_data
decl_stmt|;
comment|/* ptr to sense data, if any */
name|TW_UINT32
name|scsi_status
decl_stmt|;
comment|/* SCSI status returned by fw */
name|TW_UINT32
name|sgl_entries
decl_stmt|;
comment|/* # of SG descriptors */
name|TW_UINT8
modifier|*
name|sg_list
decl_stmt|;
comment|/* ptr to SG list */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure used to describe pass through command packets to CL. */
end_comment

begin_struct
struct|struct
name|tw_cl_passthru_req_packet
block|{
name|TW_UINT8
modifier|*
name|cmd_pkt
decl_stmt|;
comment|/* ptr to passthru cmd pkt */
name|TW_UINT32
name|cmd_pkt_length
decl_stmt|;
comment|/* size of cmd pkt */
name|TW_UINT32
name|sgl_entries
decl_stmt|;
comment|/* # of SG descriptors */
name|TW_UINT8
modifier|*
name|sg_list
decl_stmt|;
comment|/* ptr to SG list */
block|}
struct|;
end_struct

begin_comment
comment|/* Request packet submitted to the Common Layer, by the OS Layer. */
end_comment

begin_struct
struct|struct
name|tw_cl_req_packet
block|{
name|TW_UINT32
name|cmd
decl_stmt|;
comment|/* Common Layer cmd */
name|TW_UINT32
name|flags
decl_stmt|;
comment|/* flags describing request */
name|TW_UINT32
name|status
decl_stmt|;
comment|/* Common Layer returned status */
name|TW_VOID
function_decl|(
modifier|*
name|tw_osl_callback
function_decl|)
parameter_list|(
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
comment|/* OSL routine to be called by CL on req completion */
name|TW_VOID
function_decl|(
modifier|*
name|tw_osl_sgl_callback
function_decl|)
parameter_list|(
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|,
name|TW_VOID
modifier|*
name|sg_list
parameter_list|,
name|TW_UINT32
modifier|*
name|num_sgl_entries
parameter_list|)
function_decl|;
comment|/* OSL callback to get SG list. */
union|union
block|{
name|struct
name|tw_cl_scsi_req_packet
name|scsi_req
decl_stmt|;
comment|/* SCSI req */
name|struct
name|tw_cl_passthru_req_packet
name|pt_req
decl_stmt|;
comment|/*Passthru req*/
block|}
name|gen_req_pkt
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packet that describes an AEN/error generated by the controller,  * Common Layer, or even the OS Layer.  */
end_comment

begin_struct
struct|struct
name|tw_cl_event_packet
block|{
name|TW_UINT32
name|sequence_id
decl_stmt|;
name|TW_UINT32
name|time_stamp_sec
decl_stmt|;
name|TW_UINT16
name|aen_code
decl_stmt|;
name|TW_UINT8
name|severity
decl_stmt|;
name|TW_UINT8
name|retrieved
decl_stmt|;
name|TW_UINT8
name|repeat_count
decl_stmt|;
name|TW_UINT8
name|parameter_len
decl_stmt|;
name|TW_UINT8
name|parameter_data
index|[
literal|98
index|]
decl_stmt|;
name|TW_UINT32
name|event_src
decl_stmt|;
name|TW_UINT8
name|severity_str
index|[
literal|20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to link 2 adjacent elements in a list. */
end_comment

begin_struct
struct|struct
name|tw_cl_link
block|{
name|struct
name|tw_cl_link
modifier|*
name|next
decl_stmt|;
name|struct
name|tw_cl_link
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Scatter/Gather list entry with 32 bit addresses. */
end_comment

begin_struct
struct|struct
name|tw_cl_sg_desc32
block|{
name|TW_UINT32
name|address
decl_stmt|;
name|TW_UINT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Scatter/Gather list entry with 64 bit addresses. */
end_comment

begin_struct
struct|struct
name|tw_cl_sg_desc64
block|{
name|TW_UINT64
name|address
decl_stmt|;
name|TW_UINT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* Byte swap functions.  Valid only if running on big endian platforms. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|TW_CL_SWAP16_WITH_CAST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x<< 8) | (x>> 8))
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP32_WITH_CAST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x<< 24) | ((x<< 8)& (0xFF0000)) |				\ 	((x>> 8)& (0xFF00)) | (x>> 24))
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP64_WITH_CAST
parameter_list|(
name|x
parameter_list|)
define|\
value|((((TW_UINT64)(TW_CL_SWAP32(((TW_UINT32 *)(&(x)))[1])))<< 32) |\ 	((TW_UINT32)(TW_CL_SWAP32(((TW_UINT32 *)(&(x)))[0]))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TW_OSL_BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|TW_CL_SWAP16_WITH_CAST
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP32_WITH_CAST
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP64_WITH_CAST
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|TW_CL_SWAP16
parameter_list|(
name|x
parameter_list|)
value|TW_CL_SWAP16_WITH_CAST((TW_UINT16)(x))
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP32
parameter_list|(
name|x
parameter_list|)
value|TW_CL_SWAP32_WITH_CAST((TW_UINT32)(x))
end_define

begin_define
define|#
directive|define
name|TW_CL_SWAP64
parameter_list|(
name|x
parameter_list|)
value|TW_CL_SWAP64_WITH_CAST((TW_UINT64)(x))
end_define

begin_comment
comment|/* Queue manipulation functions. */
end_comment

begin_comment
comment|/* Initialize a queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_INIT
parameter_list|(
name|head
parameter_list|)
value|do {		\ 	(head)->prev = (head)->next = head;	\ } while (0)
end_define

begin_comment
comment|/* Insert an item at the head of the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|item
parameter_list|)
value|do {	\ 	(item)->next = (head)->next;		\ 	(item)->prev = head;			\ 	(head)->next->prev = item;		\ 	(head)->next = item;			\ } while (0)
end_define

begin_comment
comment|/* Insert an item at the tail of the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|item
parameter_list|)
value|do {	\ 	(item)->next = head;			\ 	(item)->prev = (head)->prev;		\ 	(head)->prev->next = item;		\ 	(head)->prev = item;			\ } while (0)
end_define

begin_comment
comment|/* Remove an item from the head of the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_REMOVE_ITEM
parameter_list|(
name|head
parameter_list|,
name|item
parameter_list|)
value|do {	\ 	(item)->prev->next = (item)->next;	\ 	(item)->next->prev = (item)->prev;	\ } while (0)
end_define

begin_comment
comment|/* Retrieve the item at the head of the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_FIRST_ITEM
parameter_list|(
name|head
parameter_list|)
define|\
value|(((head)->next != head) ? ((head)->next) : TW_CL_NULL)
end_define

begin_comment
comment|/* Retrieve the item at the tail of the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_LAST_ITEM
parameter_list|(
name|head
parameter_list|)
define|\
value|(((head)->prev != head) ? ((head)->prev) : TW_CL_NULL)
end_define

begin_comment
comment|/* Retrieve the item next to a given item in the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_NEXT_ITEM
parameter_list|(
name|head
parameter_list|,
name|item
parameter_list|)
define|\
value|(((item)->next != head) ? ((item)->next) : TW_CL_NULL)
end_define

begin_comment
comment|/* Retrieve the item previous to a given item in the queue. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_Q_PREV_ITEM
parameter_list|(
name|head
parameter_list|,
name|item
parameter_list|)
define|\
value|(((item)->prev != head) ? ((item)->prev) : TW_CL_NULL)
end_define

begin_comment
comment|/* Determine the offset of a field from the head of the structure it is in. */
end_comment

begin_define
define|#
directive|define
name|TW_CL_STRUCT_OFFSET
parameter_list|(
name|struct_type
parameter_list|,
name|field
parameter_list|)
define|\
value|(TW_INT8 *)(&((struct_type *)0)->field)
end_define

begin_comment
comment|/*  * Determine the address of the head of a structure, given the address of a  * field within it.  */
end_comment

begin_define
define|#
directive|define
name|TW_CL_STRUCT_HEAD
parameter_list|(
name|addr
parameter_list|,
name|struct_type
parameter_list|,
name|field
parameter_list|)
define|\
value|(struct_type *)((TW_INT8 *)addr -		\ 	TW_CL_STRUCT_OFFSET(struct_type, field))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TW_BUILDING_API
end_ifndef

begin_include
include|#
directive|include
file|"tw_osl_inline.h"
end_include

begin_comment
comment|/*  * The following are extern declarations of OS Layer defined functions called  * by the Common Layer.  If any function has been defined as a macro in  * tw_osl_share.h, we will not make the extern declaration here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_breakpoint
end_ifndef

begin_comment
comment|/* Allows setting breakpoints in the CL code for debugging purposes. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_breakpoint
parameter_list|(
name|TW_VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_ctlr_busy
end_ifndef

begin_comment
comment|/* Called when CL is too busy to accept new requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_ctlr_busy
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_ctlr_ready
end_ifndef

begin_comment
comment|/* Called on cmd interrupt.  Allows re-submission of any pending requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_ctlr_ready
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_cur_func
end_ifndef

begin_comment
comment|/* Text name of current function. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT8
modifier|*
name|tw_osl_cur_func
parameter_list|(
name|TW_VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_dbg_printf
end_ifndef

begin_comment
comment|/* Print to syslog/event log/debug console, as applicable. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osl_dbg_printf
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
specifier|const
name|TW_INT8
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_delay
end_ifndef

begin_comment
comment|/* Cause a delay of usecs micro-seconds. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_delay
parameter_list|(
name|TW_INT32
name|usecs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_destroy_lock
end_ifndef

begin_comment
comment|/* Create/initialize a lock for CL's use. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_destroy_lock
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_LOCK_HANDLE
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_free_lock
end_ifndef

begin_comment
comment|/* Free a previously held lock. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_free_lock
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_LOCK_HANDLE
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_get_local_time
end_ifndef

begin_comment
comment|/* Get local time. */
end_comment

begin_function_decl
specifier|extern
name|TW_TIME
name|tw_osl_get_local_time
parameter_list|(
name|TW_VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_get_lock
end_ifndef

begin_comment
comment|/* Acquire a lock. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_get_lock
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_LOCK_HANDLE
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_init_lock
end_ifndef

begin_comment
comment|/* Create/initialize a lock for CL's use. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_init_lock
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT8
modifier|*
name|lock_name
parameter_list|,
name|TW_LOCK_HANDLE
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_memcpy
end_ifndef

begin_comment
comment|/* Copy 'size' bytes from 'src' to 'dest'. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_memcpy
parameter_list|(
name|TW_VOID
modifier|*
name|src
parameter_list|,
name|TW_VOID
modifier|*
name|dest
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_memzero
end_ifndef

begin_comment
comment|/* Zero 'size' bytes starting at 'addr'. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_memzero
parameter_list|(
name|TW_VOID
modifier|*
name|addr
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_notify_event
end_ifndef

begin_comment
comment|/* Notify OSL of a controller/CL (or even OSL) event. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_notify_event
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|struct
name|tw_cl_event_packet
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_PCI_CONFIG_ACCESSIBLE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_read_pci_config
end_ifndef

begin_comment
comment|/* Read 'size' bytes from 'offset' in the PCI config space. */
end_comment

begin_function_decl
specifier|extern
name|TW_UINT32
name|tw_osl_read_pci_config
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_PCI_CONFIG_ACCESSIBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_read_reg
end_ifndef

begin_comment
comment|/* Read 'size' bytes at 'offset' from base address of this controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_UINT32
name|tw_osl_read_reg
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_scan_bus
end_ifndef

begin_comment
comment|/* Request OSL for a bus scan. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_scan_bus
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_CAN_SLEEP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_sleep
end_ifndef

begin_comment
comment|/* Sleep for 'timeout' ms or until woken up (by tw_osl_wakeup). */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osl_sleep
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_SLEEP_HANDLE
modifier|*
name|sleep_handle
parameter_list|,
name|TW_INT32
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_CAN_SLEEP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_sprintf
end_ifndef

begin_comment
comment|/* Standard sprintf. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osl_sprintf
parameter_list|(
name|TW_INT8
modifier|*
name|dest
parameter_list|,
specifier|const
name|TW_INT8
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_strcpy
end_ifndef

begin_comment
comment|/* Copy string 'src' to 'dest'. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT8
modifier|*
name|tw_osl_strcpy
parameter_list|(
name|TW_INT8
modifier|*
name|dest
parameter_list|,
name|TW_INT8
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_strlen
end_ifndef

begin_comment
comment|/* Return length of string pointed at by 'str'. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osl_strlen
parameter_list|(
name|TW_VOID
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_vsprintf
end_ifndef

begin_comment
comment|/* Standard vsprintf. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osl_vsprintf
parameter_list|(
name|TW_INT8
modifier|*
name|dest
parameter_list|,
specifier|const
name|TW_INT8
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_CAN_SLEEP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_wakeup
end_ifndef

begin_comment
comment|/* Wake up a thread sleeping by a call to tw_osl_sleep. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_wakeup
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_SLEEP_HANDLE
modifier|*
name|sleep_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_CAN_SLEEP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_PCI_CONFIG_ACCESSIBLE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_write_pci_config
end_ifndef

begin_comment
comment|/* Write 'value' of 'size' bytes at 'offset' in the PCI config space. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_write_pci_config
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|value
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_PCI_CONFIG_ACCESSIBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tw_osl_write_reg
end_ifndef

begin_comment
comment|/*  * Write 'value' of 'size' (max 4) bytes at 'offset' from base address of  * this controller.  */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_write_reg
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|offset
parameter_list|,
name|TW_INT32
name|value
parameter_list|,
name|TW_INT32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions in the Common Layer */
end_comment

begin_comment
comment|/* Creates and queues AEN's.  Also notifies OS Layer. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cl_create_event
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_UINT8
name|queue_event
parameter_list|,
name|TW_UINT8
name|event_src
parameter_list|,
name|TW_UINT16
name|event_code
parameter_list|,
name|TW_UINT8
name|severity
parameter_list|,
name|TW_UINT8
modifier|*
name|severity_str
parameter_list|,
name|TW_UINT8
modifier|*
name|event_desc
parameter_list|,
name|TW_UINT8
modifier|*
name|event_specific_desc
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Indicates whether a ctlr is supported by CL. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_ctlr_supported
parameter_list|(
name|TW_INT32
name|vendor_id
parameter_list|,
name|TW_INT32
name|device_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deferred interrupt handler. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cl_deferred_interrupt
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Submit a firmware cmd packet. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_fw_passthru
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|struct
name|tw_cl_req_packet
modifier|*
name|req_pkt
parameter_list|,
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find out how much memory CL needs. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_get_mem_requirements
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_UINT32
name|flags
parameter_list|,
name|TW_INT32
name|device_id
parameter_list|,
name|TW_INT32
name|max_simult_reqs
parameter_list|,
name|TW_INT32
name|max_aens
parameter_list|,
name|TW_UINT32
modifier|*
name|alignment
parameter_list|,
name|TW_UINT32
modifier|*
name|sg_size_factor
parameter_list|,
name|TW_UINT32
modifier|*
name|non_dma_mem_size
parameter_list|,
name|TW_UINT32
modifier|*
name|dma_mem_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return PCI BAR info. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_get_pci_bar_info
parameter_list|(
name|TW_INT32
name|device_id
parameter_list|,
name|TW_INT32
name|bar_type
parameter_list|,
name|TW_INT32
modifier|*
name|bar_num
parameter_list|,
name|TW_INT32
modifier|*
name|bar0_offset
parameter_list|,
name|TW_INT32
modifier|*
name|bar_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize Common Layer for a given controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_init_ctlr
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_UINT32
name|flags
parameter_list|,
name|TW_INT32
name|device_id
parameter_list|,
name|TW_INT32
name|max_simult_reqs
parameter_list|,
name|TW_INT32
name|max_aens
parameter_list|,
name|TW_VOID
modifier|*
name|non_dma_mem
parameter_list|,
name|TW_VOID
modifier|*
name|dma_mem
parameter_list|,
name|TW_UINT64
name|dma_mem_phys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CL's interrupt handler. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_interrupt
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CL's ioctl handler. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_ioctl
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_INT32
name|cmd
parameter_list|,
name|TW_VOID
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_comment
comment|/* Print CL's state/statistics for a controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cl_print_ctlr_stats
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prints CL internal details of a given request. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cl_print_req_info
parameter_list|(
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/* Soft reset controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_reset_ctlr
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_comment
comment|/* Reset CL's statistics for a controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cl_reset_stats
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/* Stop a controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_shutdown_ctlr
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|TW_UINT32
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Submit a SCSI I/O request. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cl_start_io
parameter_list|(
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
name|struct
name|tw_cl_req_packet
modifier|*
name|req_pkt
parameter_list|,
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_BUILDING_API */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_CL_SHARE_H */
end_comment

end_unit

