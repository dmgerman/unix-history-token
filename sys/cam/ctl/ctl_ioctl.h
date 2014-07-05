begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * Copyright (c) 2011 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_ioctl.h#4 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer ioctl interface.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_IOCTL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|CTL_DEFAULT_DEV
value|"/dev/cam/ctl"
end_define

begin_comment
comment|/*  * Maximum number of targets we support.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_TARGETS
value|1
end_define

begin_comment
comment|/*  * Maximum target ID we support.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_TARGID
value|15
end_define

begin_comment
comment|/*  * Maximum number of LUNs we support at the moment.  MUST be a power of 2.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_LUNS
value|256
end_define

begin_comment
comment|/*  * Maximum number of initiators per port.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_INIT_PER_PORT
value|2048
end_define

begin_comment
comment|// Was 16
end_comment

begin_comment
comment|/*  * Maximum number of ports registered at one time.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_PORTS
value|32
end_define

begin_comment
comment|/*  * Maximum number of initiators we support.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAX_INITIATORS
value|(CTL_MAX_INIT_PER_PORT * CTL_MAX_PORTS)
end_define

begin_comment
comment|/* Hopefully this won't conflict with new misc devices that pop up */
end_comment

begin_define
define|#
directive|define
name|CTL_MINOR
value|225
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_OOA_INVALID_LUN
block|,
name|CTL_OOA_SUCCESS
block|}
name|ctl_ooa_status
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_ooa_info
block|{
name|uint32_t
name|target_id
decl_stmt|;
comment|/* Passed in to CTL */
name|uint32_t
name|lun_id
decl_stmt|;
comment|/* Passed in to CTL */
name|uint32_t
name|num_entries
decl_stmt|;
comment|/* Returned from CTL */
name|ctl_ooa_status
name|status
decl_stmt|;
comment|/* Returned from CTL */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_hard_startstop_info
block|{
name|cfi_mt_status
name|status
decl_stmt|;
name|int
name|total_luns
decl_stmt|;
name|int
name|luns_complete
decl_stmt|;
name|int
name|luns_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_bbrread_info
block|{
name|int
name|lun_num
decl_stmt|;
comment|/* Passed in to CTL */
name|uint64_t
name|lba
decl_stmt|;
comment|/* Passed in to CTL */
name|int
name|len
decl_stmt|;
comment|/* Passed in to CTL */
name|cfi_mt_status
name|status
decl_stmt|;
comment|/* Returned from CTL */
name|cfi_bbrread_status
name|bbr_status
decl_stmt|;
comment|/* Returned from CTL */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* Returned from CTL */
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
comment|/* Returned from CTL */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_DELAY_TYPE_NONE
block|,
name|CTL_DELAY_TYPE_CONT
block|,
name|CTL_DELAY_TYPE_ONESHOT
block|}
name|ctl_delay_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_DELAY_LOC_NONE
block|,
name|CTL_DELAY_LOC_DATAMOVE
block|,
name|CTL_DELAY_LOC_DONE
block|, }
name|ctl_delay_location
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_DELAY_STATUS_NONE
block|,
name|CTL_DELAY_STATUS_OK
block|,
name|CTL_DELAY_STATUS_INVALID_LUN
block|,
name|CTL_DELAY_STATUS_INVALID_TYPE
block|,
name|CTL_DELAY_STATUS_INVALID_LOC
block|,
name|CTL_DELAY_STATUS_NOT_IMPLEMENTED
block|}
name|ctl_delay_status
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_io_delay_info
block|{
name|uint32_t
name|target_id
decl_stmt|;
name|uint32_t
name|lun_id
decl_stmt|;
name|ctl_delay_type
name|delay_type
decl_stmt|;
name|ctl_delay_location
name|delay_loc
decl_stmt|;
name|uint32_t
name|delay_secs
decl_stmt|;
name|ctl_delay_status
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_GS_SYNC_NONE
block|,
name|CTL_GS_SYNC_OK
block|,
name|CTL_GS_SYNC_NO_LUN
block|}
name|ctl_gs_sync_status
typedef|;
end_typedef

begin_comment
comment|/*  * The target and LUN id specify which device to modify.  The sync interval  * means that we will let through every N SYNCHRONIZE CACHE commands.  */
end_comment

begin_struct
struct|struct
name|ctl_sync_info
block|{
name|uint32_t
name|target_id
decl_stmt|;
comment|/* passed to kernel */
name|uint32_t
name|lun_id
decl_stmt|;
comment|/* passed to kernel */
name|int
name|sync_interval
decl_stmt|;
comment|/* depends on whether get/set */
name|ctl_gs_sync_status
name|status
decl_stmt|;
comment|/* passed from kernel */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_STATS_NO_IO
block|,
name|CTL_STATS_READ
block|,
name|CTL_STATS_WRITE
block|}
name|ctl_stat_types
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CTL_STATS_NUM_TYPES
value|3
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_STATS_NO_BLOCKSIZE
init|=
literal|0x01
block|}
name|ctl_lun_stats_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_lun_io_port_stats
block|{
name|uint32_t
name|targ_port
decl_stmt|;
name|uint64_t
name|bytes
index|[
name|CTL_STATS_NUM_TYPES
index|]
decl_stmt|;
name|uint64_t
name|operations
index|[
name|CTL_STATS_NUM_TYPES
index|]
decl_stmt|;
name|struct
name|bintime
name|time
index|[
name|CTL_STATS_NUM_TYPES
index|]
decl_stmt|;
name|uint64_t
name|num_dmas
index|[
name|CTL_STATS_NUM_TYPES
index|]
decl_stmt|;
name|struct
name|bintime
name|dma_time
index|[
name|CTL_STATS_NUM_TYPES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_lun_io_stats
block|{
name|uint8_t
name|device_type
decl_stmt|;
name|uint64_t
name|lun_number
decl_stmt|;
name|uint32_t
name|blocksize
decl_stmt|;
name|ctl_lun_stats_flags
name|flags
decl_stmt|;
name|struct
name|ctl_lun_io_port_stats
name|ports
index|[
name|CTL_MAX_PORTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_SS_OK
block|,
name|CTL_SS_NEED_MORE_SPACE
block|,
name|CTL_SS_ERROR
block|}
name|ctl_stats_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_STATS_FLAG_NONE
init|=
literal|0x00
block|,
name|CTL_STATS_FLAG_TIME_VALID
init|=
literal|0x01
block|}
name|ctl_stats_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_stats
block|{
name|int
name|alloc_len
decl_stmt|;
comment|/* passed to kernel */
name|struct
name|ctl_lun_io_stats
modifier|*
name|lun_stats
decl_stmt|;
comment|/* passed to/from kernel */
name|int
name|fill_len
decl_stmt|;
comment|/* passed to userland */
name|int
name|num_luns
decl_stmt|;
comment|/* passed to userland */
name|ctl_stats_status
name|status
decl_stmt|;
comment|/* passed to userland */
name|ctl_stats_flags
name|flags
decl_stmt|;
comment|/* passed to userland */
name|struct
name|timespec
name|timestamp
decl_stmt|;
comment|/* passed to userland */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The types of errors that can be injected:  *  * NONE:	No error specified.  * ABORTED:	SSD_KEY_ABORTED_COMMAND, 0x45, 0x00  * MEDIUM_ERR:	Medium error, different asc/ascq depending on read/write.  * UA:		Unit attention.  * CUSTOM:	User specifies the sense data.  * TYPE:	Mask to use with error types.  *  * Flags that affect injection behavior:  * CONTINUOUS:	This error will stay around until explicitly cleared.  * DESCRIPTOR:	Use descriptor sense instead of fixed sense.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_INJ_NONE
init|=
literal|0x000
block|,
name|CTL_LUN_INJ_ABORTED
init|=
literal|0x001
block|,
name|CTL_LUN_INJ_MEDIUM_ERR
init|=
literal|0x002
block|,
name|CTL_LUN_INJ_UA
init|=
literal|0x003
block|,
name|CTL_LUN_INJ_CUSTOM
init|=
literal|0x004
block|,
name|CTL_LUN_INJ_TYPE
init|=
literal|0x0ff
block|,
name|CTL_LUN_INJ_CONTINUOUS
init|=
literal|0x100
block|,
name|CTL_LUN_INJ_DESCRIPTOR
init|=
literal|0x200
block|}
name|ctl_lun_error
typedef|;
end_typedef

begin_comment
comment|/*  * Flags to specify what type of command the given error pattern will  * execute on.  The first group of types can be ORed together.  *  * READ:	Any read command.  * WRITE:	Any write command.  * READWRITE:	Any read or write command.  * READCAP:	Any read capacity command.  * TUR:		Test Unit Ready.  * ANY:		Any command.  * MASK:	Mask for basic command patterns.  *  * Special types:  *  * CMD:		The CDB to act on is specified in struct ctl_error_desc_cmd.  * RANGE:	For read/write commands, act when the LBA is in the  *		specified range.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_PAT_NONE
init|=
literal|0x000
block|,
name|CTL_LUN_PAT_READ
init|=
literal|0x001
block|,
name|CTL_LUN_PAT_WRITE
init|=
literal|0x002
block|,
name|CTL_LUN_PAT_READWRITE
init|=
name|CTL_LUN_PAT_READ
operator||
name|CTL_LUN_PAT_WRITE
block|,
name|CTL_LUN_PAT_READCAP
init|=
literal|0x004
block|,
name|CTL_LUN_PAT_TUR
init|=
literal|0x008
block|,
name|CTL_LUN_PAT_ANY
init|=
literal|0x0ff
block|,
name|CTL_LUN_PAT_MASK
init|=
literal|0x0ff
block|,
name|CTL_LUN_PAT_CMD
init|=
literal|0x100
block|,
name|CTL_LUN_PAT_RANGE
init|=
literal|0x200
block|}
name|ctl_lun_error_pattern
typedef|;
end_typedef

begin_comment
comment|/*  * This structure allows the user to specify a particular CDB pattern to  * look for.  *  * cdb_pattern:		Fill in the relevant bytes to look for in the CDB.  * cdb_valid_bytes:	Bitmask specifying valid bytes in the cdb_pattern.  * flags:		Specify any command flags (see ctl_io_flags) that  *			should be set.  */
end_comment

begin_struct
struct|struct
name|ctl_error_desc_cmd
block|{
name|uint8_t
name|cdb_pattern
index|[
name|CTL_MAX_CDBLEN
index|]
decl_stmt|;
name|uint32_t
name|cdb_valid_bytes
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error injection descriptor.  *  * target_id:	   Target ID to act on.  * lun_id	   LUN to act on.  * lun_error:	   The type of error to inject.  See above for descriptions.  * error_pattern:  What kind of command to act on.  See above.  * cmd_desc:	   For CTL_LUN_PAT_CMD only.  * lba_range:	   For CTL_LUN_PAT_RANGE only.  * custom_sense:   Specify sense.  For CTL_LUN_INJ_CUSTOM only.  * serial:	   Serial number returned by the kernel.  Use for deletion.  * links:	   Kernel use only.  */
end_comment

begin_struct
struct|struct
name|ctl_error_desc
block|{
name|uint32_t
name|target_id
decl_stmt|;
comment|/* To kernel */
name|uint32_t
name|lun_id
decl_stmt|;
comment|/* To kernel */
name|ctl_lun_error
name|lun_error
decl_stmt|;
comment|/* To kernel */
name|ctl_lun_error_pattern
name|error_pattern
decl_stmt|;
comment|/* To kernel */
name|struct
name|ctl_error_desc_cmd
name|cmd_desc
decl_stmt|;
comment|/* To kernel */
name|struct
name|ctl_lba_len
name|lba_range
decl_stmt|;
comment|/* To kernel */
name|struct
name|scsi_sense_data
name|custom_sense
decl_stmt|;
comment|/* To kernel */
name|uint64_t
name|serial
decl_stmt|;
comment|/* From kernel */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_error_desc
argument_list|)
name|links
expr_stmt|;
comment|/* Kernel use only */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_OOA_FLAG_NONE
init|=
literal|0x00
block|,
name|CTL_OOA_FLAG_ALL_LUNS
init|=
literal|0x01
block|}
name|ctl_ooa_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_OOA_OK
block|,
name|CTL_OOA_NEED_MORE_SPACE
block|,
name|CTL_OOA_ERROR
block|}
name|ctl_get_ooa_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_OOACMD_FLAG_NONE
init|=
literal|0x00
block|,
name|CTL_OOACMD_FLAG_DMA
init|=
literal|0x01
block|,
name|CTL_OOACMD_FLAG_BLOCKED
init|=
literal|0x02
block|,
name|CTL_OOACMD_FLAG_ABORT
init|=
literal|0x04
block|,
name|CTL_OOACMD_FLAG_RTR
init|=
literal|0x08
block|,
name|CTL_OOACMD_FLAG_DMA_QUEUED
init|=
literal|0x10
block|}
name|ctl_ooa_cmd_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_ooa_entry
block|{
name|ctl_ooa_cmd_flags
name|cmd_flags
decl_stmt|;
name|uint8_t
name|cdb
index|[
name|CTL_MAX_CDBLEN
index|]
decl_stmt|;
name|uint8_t
name|cdb_len
decl_stmt|;
name|uint32_t
name|tag_num
decl_stmt|;
name|uint32_t
name|lun_num
decl_stmt|;
name|struct
name|bintime
name|start_bt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_ooa
block|{
name|ctl_ooa_flags
name|flags
decl_stmt|;
comment|/* passed to kernel */
name|uint64_t
name|lun_num
decl_stmt|;
comment|/* passed to kernel */
name|uint32_t
name|alloc_len
decl_stmt|;
comment|/* passed to kernel */
name|uint32_t
name|alloc_num
decl_stmt|;
comment|/* passed to kernel */
name|struct
name|ctl_ooa_entry
modifier|*
name|entries
decl_stmt|;
comment|/* filled in kernel */
name|uint32_t
name|fill_len
decl_stmt|;
comment|/* passed to userland */
name|uint32_t
name|fill_num
decl_stmt|;
comment|/* passed to userland */
name|uint32_t
name|dropped_num
decl_stmt|;
comment|/* passed to userland */
name|struct
name|bintime
name|cur_bt
decl_stmt|;
comment|/* passed to userland */
name|ctl_get_ooa_status
name|status
decl_stmt|;
comment|/* passed to userland */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_PORT_LIST_NONE
block|,
name|CTL_PORT_LIST_OK
block|,
name|CTL_PORT_LIST_NEED_MORE_SPACE
block|,
name|CTL_PORT_LIST_ERROR
block|}
name|ctl_port_list_status
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_port_list
block|{
name|uint32_t
name|alloc_len
decl_stmt|;
comment|/* passed to kernel */
name|uint32_t
name|alloc_num
decl_stmt|;
comment|/* passed to kernel */
name|struct
name|ctl_port_entry
modifier|*
name|entries
decl_stmt|;
comment|/* filled in kernel */
name|uint32_t
name|fill_len
decl_stmt|;
comment|/* passed to userland */
name|uint32_t
name|fill_num
decl_stmt|;
comment|/* passed to userland */
name|uint32_t
name|dropped_num
decl_stmt|;
comment|/* passed to userland */
name|ctl_port_list_status
name|status
decl_stmt|;
comment|/* passed to userland */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_NOSTATUS
block|,
name|CTL_LUN_OK
block|,
name|CTL_LUN_ERROR
block|}
name|ctl_lun_status
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CTL_ERROR_STR_LEN
value|160
end_define

begin_define
define|#
directive|define
name|CTL_BEARG_RD
value|0x01
end_define

begin_define
define|#
directive|define
name|CTL_BEARG_WR
value|0x02
end_define

begin_define
define|#
directive|define
name|CTL_BEARG_RW
value|(CTL_BEARG_RD|CTL_BEARG_WR)
end_define

begin_define
define|#
directive|define
name|CTL_BEARG_ASCII
value|0x04
end_define

begin_comment
comment|/*  * Backend Argument:  *  * namelen:	Length of the name field, including the terminating NUL.  *  * name:	Name of the paramter.  This must be NUL-terminated.  *  * flags:	Flags for the parameter, see above for values.  *  * vallen:	Length of the value in bytes.  *  * value:	Value to be set/fetched.  *  * kname:	For kernel use only.  *  * kvalue:	For kernel use only.  */
end_comment

begin_struct
struct|struct
name|ctl_be_arg
block|{
name|int
name|namelen
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|vallen
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
name|char
modifier|*
name|kname
decl_stmt|;
name|void
modifier|*
name|kvalue
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUNREQ_CREATE
block|,
name|CTL_LUNREQ_RM
block|,
name|CTL_LUNREQ_MODIFY
block|, }
name|ctl_lunreq_type
typedef|;
end_typedef

begin_comment
comment|/*  * LUN creation parameters:  *  * flags:		Various LUN flags, see ctl_backend.h for a  *			description of the flag values and meanings.  *  * device_type:		The SCSI device type.  e.g. 0 for Direct Access,  *			3 for Processor, etc.  Only certain backends may  *			support setting this field.  The CTL_LUN_FLAG_DEV_TYPE  *			flag should be set in the flags field if the device  *			type is set.  *  * lun_size_bytes:	The size of the LUN in bytes.  For some backends  *			this is relevant (e.g. ramdisk), for others, it may  *			be ignored in favor of using the properties of the  *			backing store.  If specified, this should be a  *			multiple of the blocksize.  *  *			The actual size of the LUN is returned in this  *			field.  *  * blocksize_bytes:	The LUN blocksize in bytes.  For some backends this  *			is relevant, for others it may be ignored in  *			favor of using the properties of the backing store.   *  *			The actual blocksize of the LUN is returned in this  *			field.  *  * req_lun_id:		The requested LUN ID.  The CTL_LUN_FLAG_ID_REQ flag  *			should be set if this is set.  The request will be  *			granted if the LUN number is available, otherwise  * 			the LUN addition request will fail.  *  *			The allocated LUN number is returned in this field.  *  * serial_num:		This is the value returned in SCSI INQUIRY VPD page  *			0x80.  If it is specified, the CTL_LUN_FLAG_SERIAL_NUM  *			flag should be set.  *  *			The serial number value used is returned in this  *			field.  *  * device_id:		This is the value returned in the T10 vendor ID  *			based DESIGNATOR field in the SCSI INQUIRY VPD page  *			0x83 data.  If it is specified, the CTL_LUN_FLAG_DEVID  *			flag should be set.  *  *			The device id value used is returned in this field.  */
end_comment

begin_struct
struct|struct
name|ctl_lun_create_params
block|{
name|ctl_backend_lun_flags
name|flags
decl_stmt|;
name|uint8_t
name|device_type
decl_stmt|;
name|uint64_t
name|lun_size_bytes
decl_stmt|;
name|uint32_t
name|blocksize_bytes
decl_stmt|;
name|uint32_t
name|req_lun_id
decl_stmt|;
name|uint8_t
name|serial_num
index|[
name|CTL_SN_LEN
index|]
decl_stmt|;
name|uint8_t
name|device_id
index|[
name|CTL_DEVID_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LUN removal parameters:  *  * lun_id:		The number of the LUN to delete.  This must be set.  *			The LUN must be backed by the given backend.  */
end_comment

begin_struct
struct|struct
name|ctl_lun_rm_params
block|{
name|uint32_t
name|lun_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LUN modification parameters:  *  * lun_id:		The number of the LUN to modify.  This must be set.  *			The LUN must be backed by the given backend.  *  * lun_size_bytes:	The size of the LUN in bytes.  If zero, update  * 			the size using the backing file size, if possible.  */
end_comment

begin_struct
struct|struct
name|ctl_lun_modify_params
block|{
name|uint32_t
name|lun_id
decl_stmt|;
name|uint64_t
name|lun_size_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Union of request type data.  Fill in the appropriate union member for  * the request type.  */
end_comment

begin_union
union|union
name|ctl_lunreq_data
block|{
name|struct
name|ctl_lun_create_params
name|create
decl_stmt|;
name|struct
name|ctl_lun_rm_params
name|rm
decl_stmt|;
name|struct
name|ctl_lun_modify_params
name|modify
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * LUN request interface:  *  * backend:		This is required, and is NUL-terminated a string  *			that is the name of the backend, like "ramdisk" or  *			"block".  *  * reqtype:		The type of request, CTL_LUNREQ_CREATE to create a  *			LUN, CTL_LUNREQ_RM to delete a LUN.  *  * reqdata:		Request type-specific information.  See the  *			description of individual the union members above  *			for more information.  *  * num_be_args:		This is the number of backend-specific arguments  *			in the be_args array.  *  * be_args:		This is an array of backend-specific arguments.  *			See above for a description of the fields in this  *			structure.  *  * status:		Status of the LUN request.  *  * error_str:		If the status is CTL_LUN_ERROR, this will  *			contain a string describing the error.  *  * kern_be_args:	For kernel use only.  */
end_comment

begin_struct
struct|struct
name|ctl_lun_req
block|{
name|char
name|backend
index|[
name|CTL_BE_NAME_LEN
index|]
decl_stmt|;
name|ctl_lunreq_type
name|reqtype
decl_stmt|;
name|union
name|ctl_lunreq_data
name|reqdata
decl_stmt|;
name|int
name|num_be_args
decl_stmt|;
name|struct
name|ctl_be_arg
modifier|*
name|be_args
decl_stmt|;
name|ctl_lun_status
name|status
decl_stmt|;
name|char
name|error_str
index|[
name|CTL_ERROR_STR_LEN
index|]
decl_stmt|;
name|struct
name|ctl_be_arg
modifier|*
name|kern_be_args
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LUN list status:  *  * NONE:		No status.  *  * OK:			Request completed successfully.  *  * NEED_MORE_SPACE:	The allocated length of the entries field is too  * 			small for the available data.  *  * ERROR:		An error occured, look at the error string for a  *			description of the error.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_LUN_LIST_NONE
block|,
name|CTL_LUN_LIST_OK
block|,
name|CTL_LUN_LIST_NEED_MORE_SPACE
block|,
name|CTL_LUN_LIST_ERROR
block|}
name|ctl_lun_list_status
typedef|;
end_typedef

begin_comment
comment|/*  * LUN list interface  *  * backend_name:	This is a NUL-terminated string.  If the string  *			length is 0, then all LUNs on all backends will  *			be enumerated.  Otherwise this is the name of the  *			backend to be enumerated, like "ramdisk" or "block".  *  * alloc_len:		The length of the data buffer allocated for entries.  *			In order to properly size the buffer, make one call  *			with alloc_len set to 0, and then use the returned  *			dropped_len as the buffer length to allocate and  *			pass in on a subsequent call.  *  * lun_xml:		XML-formatted information on the requested LUNs.  *  * fill_len:		The amount of data filled in the storage for entries.  *  * status:		The status of the request.  See above for the   *			description of the values of this field.  *  * error_str:		If the status indicates an error, this string will  *			be filled in to describe the error.  */
end_comment

begin_struct
struct|struct
name|ctl_lun_list
block|{
name|char
name|backend
index|[
name|CTL_BE_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to kernel*/
name|uint32_t
name|alloc_len
decl_stmt|;
comment|/* passed to kernel */
name|char
modifier|*
name|lun_xml
decl_stmt|;
comment|/* filled in kernel */
name|uint32_t
name|fill_len
decl_stmt|;
comment|/* passed to userland */
name|ctl_lun_list_status
name|status
decl_stmt|;
comment|/* passed to userland */
name|char
name|error_str
index|[
name|CTL_ERROR_STR_LEN
index|]
decl_stmt|;
comment|/* passed to userland */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Port request interface:  *  * driver:		This is required, and is NUL-terminated a string  *			that is the name of the frontend, like "iscsi" .  *  * reqtype:		The type of request, CTL_REQ_CREATE to create a  *			port, CTL_REQ_REMOVE to delete a port.  *  * num_be_args:		This is the number of frontend-specific arguments  *			in the be_args array.  *  * be_args:		This is an array of frontend-specific arguments.  *			See above for a description of the fields in this  *			structure.  *  * status:		Status of the request.  *  * error_str:		If the status is CTL_LUN_ERROR, this will  *			contain a string describing the error.  *  * kern_be_args:	For kernel use only.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_REQ_CREATE
block|,
name|CTL_REQ_REMOVE
block|,
name|CTL_REQ_MODIFY
block|, }
name|ctl_req_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_req
block|{
name|char
name|driver
index|[
name|CTL_DRIVER_NAME_LEN
index|]
decl_stmt|;
name|ctl_req_type
name|reqtype
decl_stmt|;
name|int
name|num_args
decl_stmt|;
name|struct
name|ctl_be_arg
modifier|*
name|args
decl_stmt|;
name|ctl_lun_status
name|status
decl_stmt|;
name|char
name|error_str
index|[
name|CTL_ERROR_STR_LEN
index|]
decl_stmt|;
name|struct
name|ctl_be_arg
modifier|*
name|kern_args
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI status  *  * OK:			Request completed successfully.  *  * ERROR:		An error occured, look at the error string for a  *			description of the error.  *  * CTL_ISCSI_LIST_NEED_MORE_SPACE:  * 			User has to pass larger buffer for CTL_ISCSI_LIST ioctl.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_ISCSI_OK
block|,
name|CTL_ISCSI_ERROR
block|,
name|CTL_ISCSI_LIST_NEED_MORE_SPACE
block|,
name|CTL_ISCSI_SESSION_NOT_FOUND
block|}
name|ctl_iscsi_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_ISCSI_HANDOFF
block|,
name|CTL_ISCSI_LIST
block|,
name|CTL_ISCSI_LOGOUT
block|,
name|CTL_ISCSI_TERMINATE
block|,
if|#
directive|if
name|defined
argument_list|(
name|ICL_KERNEL_PROXY
argument_list|)
operator|||
literal|1
comment|/* 	 * We actually need those in all cases, but leave the ICL_KERNEL_PROXY, 	 * to remember to remove them along with rest of proxy code, eventually. 	 */
name|CTL_ISCSI_LISTEN
block|,
name|CTL_ISCSI_ACCEPT
block|,
name|CTL_ISCSI_SEND
block|,
name|CTL_ISCSI_RECEIVE
block|,
endif|#
directive|endif
block|}
name|ctl_iscsi_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_ISCSI_DIGEST_NONE
block|,
name|CTL_ISCSI_DIGEST_CRC32C
block|}
name|ctl_iscsi_digest
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CTL_ISCSI_NAME_LEN
value|224
end_define

begin_comment
comment|/* 223 bytes, by RFC 3720, + '\0' */
end_comment

begin_define
define|#
directive|define
name|CTL_ISCSI_ADDR_LEN
value|47
end_define

begin_comment
comment|/* INET6_ADDRSTRLEN + '\0' */
end_comment

begin_define
define|#
directive|define
name|CTL_ISCSI_ALIAS_LEN
value|128
end_define

begin_comment
comment|/* Arbitrary. */
end_comment

begin_struct
struct|struct
name|ctl_iscsi_handoff_params
block|{
name|char
name|initiator_name
index|[
name|CTL_ISCSI_NAME_LEN
index|]
decl_stmt|;
name|char
name|initiator_addr
index|[
name|CTL_ISCSI_ADDR_LEN
index|]
decl_stmt|;
name|char
name|initiator_alias
index|[
name|CTL_ISCSI_ALIAS_LEN
index|]
decl_stmt|;
name|uint8_t
name|initiator_isid
index|[
literal|6
index|]
decl_stmt|;
name|char
name|target_name
index|[
name|CTL_ISCSI_NAME_LEN
index|]
decl_stmt|;
name|int
name|socket
decl_stmt|;
name|int
name|portal_group_tag
decl_stmt|;
comment|/* 	 * Connection parameters negotiated by ctld(8). 	 */
name|ctl_iscsi_digest
name|header_digest
decl_stmt|;
name|ctl_iscsi_digest
name|data_digest
decl_stmt|;
name|uint32_t
name|cmdsn
decl_stmt|;
name|uint32_t
name|statsn
decl_stmt|;
name|uint32_t
name|max_recv_data_segment_length
decl_stmt|;
name|uint32_t
name|max_burst_length
decl_stmt|;
name|uint32_t
name|first_burst_length
decl_stmt|;
name|uint32_t
name|immediate_data
decl_stmt|;
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
name|int
name|connection_id
decl_stmt|;
name|int
name|spare
index|[
literal|3
index|]
decl_stmt|;
else|#
directive|else
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_list_params
block|{
name|uint32_t
name|alloc_len
decl_stmt|;
comment|/* passed to kernel */
name|char
modifier|*
name|conn_xml
decl_stmt|;
comment|/* filled in kernel */
name|uint32_t
name|fill_len
decl_stmt|;
comment|/* passed to userland */
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_logout_params
block|{
name|int
name|connection_id
decl_stmt|;
comment|/* passed to kernel */
name|char
name|initiator_name
index|[
name|CTL_ISCSI_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to kernel */
name|char
name|initiator_addr
index|[
name|CTL_ISCSI_ADDR_LEN
index|]
decl_stmt|;
comment|/* passed to kernel */
name|int
name|all
decl_stmt|;
comment|/* passed to kernel */
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_terminate_params
block|{
name|int
name|connection_id
decl_stmt|;
comment|/* passed to kernel */
name|char
name|initiator_name
index|[
name|CTL_ISCSI_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to kernel */
name|char
name|initiator_addr
index|[
name|CTL_ISCSI_NAME_LEN
index|]
decl_stmt|;
comment|/* passed to kernel */
name|int
name|all
decl_stmt|;
comment|/* passed to kernel */
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
end_ifdef

begin_struct
struct|struct
name|ctl_iscsi_listen_params
block|{
name|int
name|iser
decl_stmt|;
name|int
name|domain
decl_stmt|;
name|int
name|socktype
decl_stmt|;
name|int
name|protocol
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
name|socklen_t
name|addrlen
decl_stmt|;
name|int
name|portal_id
decl_stmt|;
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_accept_params
block|{
name|int
name|connection_id
decl_stmt|;
name|int
name|portal_id
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|initiator_addr
decl_stmt|;
name|socklen_t
name|initiator_addrlen
decl_stmt|;
name|int
name|spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_send_params
block|{
name|int
name|connection_id
decl_stmt|;
name|void
modifier|*
name|bhs
decl_stmt|;
name|size_t
name|spare
decl_stmt|;
name|void
modifier|*
name|spare2
decl_stmt|;
name|size_t
name|data_segment_len
decl_stmt|;
name|void
modifier|*
name|data_segment
decl_stmt|;
name|int
name|spare3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_iscsi_receive_params
block|{
name|int
name|connection_id
decl_stmt|;
name|void
modifier|*
name|bhs
decl_stmt|;
name|size_t
name|spare
decl_stmt|;
name|void
modifier|*
name|spare2
decl_stmt|;
name|size_t
name|data_segment_len
decl_stmt|;
name|void
modifier|*
name|data_segment
decl_stmt|;
name|int
name|spare3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ICL_KERNEL_PROXY */
end_comment

begin_union
union|union
name|ctl_iscsi_data
block|{
name|struct
name|ctl_iscsi_handoff_params
name|handoff
decl_stmt|;
name|struct
name|ctl_iscsi_list_params
name|list
decl_stmt|;
name|struct
name|ctl_iscsi_logout_params
name|logout
decl_stmt|;
name|struct
name|ctl_iscsi_terminate_params
name|terminate
decl_stmt|;
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
name|struct
name|ctl_iscsi_listen_params
name|listen
decl_stmt|;
name|struct
name|ctl_iscsi_accept_params
name|accept
decl_stmt|;
name|struct
name|ctl_iscsi_send_params
name|send
decl_stmt|;
name|struct
name|ctl_iscsi_receive_params
name|receive
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI interface  *  * status:		The status of the request.  See above for the   *			description of the values of this field.  *  * error_str:		If the status indicates an error, this string will  *			be filled in to describe the error.  */
end_comment

begin_struct
struct|struct
name|ctl_iscsi
block|{
name|ctl_iscsi_type
name|type
decl_stmt|;
comment|/* passed to kernel */
name|union
name|ctl_iscsi_data
name|data
decl_stmt|;
comment|/* passed to kernel */
name|ctl_iscsi_status
name|status
decl_stmt|;
comment|/* passed to userland */
name|char
name|error_str
index|[
name|CTL_ERROR_STR_LEN
index|]
decl_stmt|;
comment|/* passed to userland */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTL_IO
value|_IOWR(CTL_MINOR, 0x00, union ctl_io)
end_define

begin_define
define|#
directive|define
name|CTL_ENABLE_PORT
value|_IOW(CTL_MINOR, 0x04, struct ctl_port_entry)
end_define

begin_define
define|#
directive|define
name|CTL_DISABLE_PORT
value|_IOW(CTL_MINOR, 0x05, struct ctl_port_entry)
end_define

begin_define
define|#
directive|define
name|CTL_DUMP_OOA
value|_IO(CTL_MINOR, 0x06)
end_define

begin_define
define|#
directive|define
name|CTL_CHECK_OOA
value|_IOWR(CTL_MINOR, 0x07, struct ctl_ooa_info)
end_define

begin_define
define|#
directive|define
name|CTL_HARD_STOP
value|_IOR(CTL_MINOR, 0x08, \ 				     struct ctl_hard_startstop_info)
end_define

begin_define
define|#
directive|define
name|CTL_HARD_START
value|_IOR(CTL_MINOR, 0x09, \ 				     struct ctl_hard_startstop_info)
end_define

begin_define
define|#
directive|define
name|CTL_DELAY_IO
value|_IOWR(CTL_MINOR, 0x10, struct ctl_io_delay_info)
end_define

begin_define
define|#
directive|define
name|CTL_REALSYNC_GET
value|_IOR(CTL_MINOR, 0x11, int)
end_define

begin_define
define|#
directive|define
name|CTL_REALSYNC_SET
value|_IOW(CTL_MINOR, 0x12, int)
end_define

begin_define
define|#
directive|define
name|CTL_SETSYNC
value|_IOWR(CTL_MINOR, 0x13, struct ctl_sync_info)
end_define

begin_define
define|#
directive|define
name|CTL_GETSYNC
value|_IOWR(CTL_MINOR, 0x14, struct ctl_sync_info)
end_define

begin_define
define|#
directive|define
name|CTL_GETSTATS
value|_IOWR(CTL_MINOR, 0x15, struct ctl_stats)
end_define

begin_define
define|#
directive|define
name|CTL_ERROR_INJECT
value|_IOWR(CTL_MINOR, 0x16, struct ctl_error_desc)
end_define

begin_define
define|#
directive|define
name|CTL_BBRREAD
value|_IOWR(CTL_MINOR, 0x17, struct ctl_bbrread_info)
end_define

begin_define
define|#
directive|define
name|CTL_GET_OOA
value|_IOWR(CTL_MINOR, 0x18, struct ctl_ooa)
end_define

begin_define
define|#
directive|define
name|CTL_DUMP_STRUCTS
value|_IO(CTL_MINOR, 0x19)
end_define

begin_define
define|#
directive|define
name|CTL_GET_PORT_LIST
value|_IOWR(CTL_MINOR, 0x20, struct ctl_port_list)
end_define

begin_define
define|#
directive|define
name|CTL_LUN_REQ
value|_IOWR(CTL_MINOR, 0x21, struct ctl_lun_req)
end_define

begin_define
define|#
directive|define
name|CTL_LUN_LIST
value|_IOWR(CTL_MINOR, 0x22, struct ctl_lun_list)
end_define

begin_define
define|#
directive|define
name|CTL_ERROR_INJECT_DELETE
value|_IOW(CTL_MINOR, 0x23, struct ctl_error_desc)
end_define

begin_define
define|#
directive|define
name|CTL_SET_PORT_WWNS
value|_IOW(CTL_MINOR, 0x24, struct ctl_port_entry)
end_define

begin_define
define|#
directive|define
name|CTL_ISCSI
value|_IOWR(CTL_MINOR, 0x25, struct ctl_iscsi)
end_define

begin_define
define|#
directive|define
name|CTL_PORT_REQ
value|_IOWR(CTL_MINOR, 0x26, struct ctl_req)
end_define

begin_define
define|#
directive|define
name|CTL_PORT_LIST
value|_IOWR(CTL_MINOR, 0x27, struct ctl_lun_list)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_IOCTL_H_ */
end_comment

begin_comment
comment|/*  * vim: ts=8  */
end_comment

end_unit

