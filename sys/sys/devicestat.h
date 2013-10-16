begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999 Kenneth D. Merry.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVICESTAT_H
end_ifndef

begin_define
define|#
directive|define
name|_DEVICESTAT_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * XXX: Should really be SPECNAMELEN  */
end_comment

begin_define
define|#
directive|define
name|DEVSTAT_NAME_LEN
value|16
end_define

begin_comment
comment|/*  * device name for the mmap device  */
end_comment

begin_define
define|#
directive|define
name|DEVSTAT_DEVICE_NAME
value|"devstat"
end_define

begin_comment
comment|/*  * ATTENTION:  The devstat version below should be incremented any time a  * change is made in struct devstat, or any time a change is made in the  * enumerated types that struct devstat uses.  (Only if those changes  * would require a recompile -- i.e. re-arranging the order of an  * enumerated type or something like that.)  This version number is used by  * userland utilities to determine whether or not they are in sync with the  * kernel.  */
end_comment

begin_define
define|#
directive|define
name|DEVSTAT_VERSION
value|6
end_define

begin_comment
comment|/*  * These flags specify which statistics features are supported or not  * supported by a particular device.  The default is all statistics are  * supported.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVSTAT_ALL_SUPPORTED
init|=
literal|0x00
block|,
name|DEVSTAT_NO_BLOCKSIZE
init|=
literal|0x01
block|,
name|DEVSTAT_NO_ORDERED_TAGS
init|=
literal|0x02
block|,
name|DEVSTAT_BS_UNAVAILABLE
init|=
literal|0x04
block|}
name|devstat_support_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVSTAT_NO_DATA
init|=
literal|0x00
block|,
name|DEVSTAT_READ
init|=
literal|0x01
block|,
name|DEVSTAT_WRITE
init|=
literal|0x02
block|,
name|DEVSTAT_FREE
init|=
literal|0x03
block|}
name|devstat_trans_flags
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEVSTAT_N_TRANS_FLAGS
value|4
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVSTAT_TAG_SIMPLE
init|=
literal|0x00
block|,
name|DEVSTAT_TAG_HEAD
init|=
literal|0x01
block|,
name|DEVSTAT_TAG_ORDERED
init|=
literal|0x02
block|,
name|DEVSTAT_TAG_NONE
init|=
literal|0x03
block|}
name|devstat_tag_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVSTAT_PRIORITY_MIN
init|=
literal|0x000
block|,
name|DEVSTAT_PRIORITY_OTHER
init|=
literal|0x020
block|,
name|DEVSTAT_PRIORITY_PASS
init|=
literal|0x030
block|,
name|DEVSTAT_PRIORITY_FD
init|=
literal|0x040
block|,
name|DEVSTAT_PRIORITY_WFD
init|=
literal|0x050
block|,
name|DEVSTAT_PRIORITY_TAPE
init|=
literal|0x060
block|,
name|DEVSTAT_PRIORITY_CD
init|=
literal|0x090
block|,
name|DEVSTAT_PRIORITY_DISK
init|=
literal|0x110
block|,
name|DEVSTAT_PRIORITY_ARRAY
init|=
literal|0x120
block|,
name|DEVSTAT_PRIORITY_MAX
init|=
literal|0xfff
block|}
name|devstat_priority
typedef|;
end_typedef

begin_comment
comment|/*  * These types are intended to aid statistics gathering/display programs.  * The first 13 types (up to the 'target' flag) are identical numerically  * to the SCSI device type numbers.  The next 3 types designate the device  * interface.  Currently the choices are IDE, SCSI, and 'other'.  The last  * flag specifies whether or not the given device is a passthrough device  * or not.  If it is a passthrough device, the lower 4 bits specify which  * type of physical device lies under the passthrough device, and the next  * 4 bits specify the interface.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVSTAT_TYPE_DIRECT
init|=
literal|0x000
block|,
name|DEVSTAT_TYPE_SEQUENTIAL
init|=
literal|0x001
block|,
name|DEVSTAT_TYPE_PRINTER
init|=
literal|0x002
block|,
name|DEVSTAT_TYPE_PROCESSOR
init|=
literal|0x003
block|,
name|DEVSTAT_TYPE_WORM
init|=
literal|0x004
block|,
name|DEVSTAT_TYPE_CDROM
init|=
literal|0x005
block|,
name|DEVSTAT_TYPE_SCANNER
init|=
literal|0x006
block|,
name|DEVSTAT_TYPE_OPTICAL
init|=
literal|0x007
block|,
name|DEVSTAT_TYPE_CHANGER
init|=
literal|0x008
block|,
name|DEVSTAT_TYPE_COMM
init|=
literal|0x009
block|,
name|DEVSTAT_TYPE_ASC0
init|=
literal|0x00a
block|,
name|DEVSTAT_TYPE_ASC1
init|=
literal|0x00b
block|,
name|DEVSTAT_TYPE_STORARRAY
init|=
literal|0x00c
block|,
name|DEVSTAT_TYPE_ENCLOSURE
init|=
literal|0x00d
block|,
name|DEVSTAT_TYPE_FLOPPY
init|=
literal|0x00e
block|,
name|DEVSTAT_TYPE_MASK
init|=
literal|0x00f
block|,
name|DEVSTAT_TYPE_IF_SCSI
init|=
literal|0x010
block|,
name|DEVSTAT_TYPE_IF_IDE
init|=
literal|0x020
block|,
name|DEVSTAT_TYPE_IF_OTHER
init|=
literal|0x030
block|,
name|DEVSTAT_TYPE_IF_MASK
init|=
literal|0x0f0
block|,
name|DEVSTAT_TYPE_PASS
init|=
literal|0x100
block|}
name|devstat_type_flags
typedef|;
end_typedef

begin_comment
comment|/*  * XXX: Next revision should add  *	off_t		offset[DEVSTAT_N_TRANS_FLAGS];  * XXX: which should contain the offset of the last completed transfer.  */
end_comment

begin_struct
struct|struct
name|devstat
block|{
comment|/* Internal house-keeping fields */
name|u_int
name|sequence0
decl_stmt|;
comment|/* Update sequence# */
name|int
name|allocated
decl_stmt|;
comment|/* Allocated entry */
name|u_int
name|start_count
decl_stmt|;
comment|/* started ops */
name|u_int
name|end_count
decl_stmt|;
comment|/* completed ops */
name|struct
name|bintime
name|busy_from
decl_stmt|;
comment|/* 						      * busy time unaccounted 						      * for since this time 						      */
name|STAILQ_ENTRY
argument_list|(
argument|devstat
argument_list|)
name|dev_links
expr_stmt|;
name|u_int32_t
name|device_number
decl_stmt|;
comment|/* 						      * Devstat device 						      * number. 						      */
name|char
name|device_name
index|[
name|DEVSTAT_NAME_LEN
index|]
decl_stmt|;
name|int
name|unit_number
decl_stmt|;
name|u_int64_t
name|bytes
index|[
name|DEVSTAT_N_TRANS_FLAGS
index|]
decl_stmt|;
name|u_int64_t
name|operations
index|[
name|DEVSTAT_N_TRANS_FLAGS
index|]
decl_stmt|;
name|struct
name|bintime
name|duration
index|[
name|DEVSTAT_N_TRANS_FLAGS
index|]
decl_stmt|;
name|struct
name|bintime
name|busy_time
decl_stmt|;
name|struct
name|bintime
name|creation_time
decl_stmt|;
comment|/*  						      * Time the device was 						      * created. 						      */
name|u_int32_t
name|block_size
decl_stmt|;
comment|/* Block size, bytes */
name|u_int64_t
name|tag_types
index|[
literal|3
index|]
decl_stmt|;
comment|/* 						      * The number of 						      * simple, ordered,  						      * and head of queue  						      * tags sent. 						      */
name|devstat_support_flags
name|flags
decl_stmt|;
comment|/* 						      * Which statistics 						      * are supported by a  						      * given device. 						      */
name|devstat_type_flags
name|device_type
decl_stmt|;
comment|/* Device type */
name|devstat_priority
name|priority
decl_stmt|;
comment|/* Controls list pos. */
specifier|const
name|void
modifier|*
name|id
decl_stmt|;
comment|/* 						      * Identification for 						      * GEOM nodes 						      */
name|u_int
name|sequence1
decl_stmt|;
comment|/* Update sequence# */
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|devstatlist
argument_list|,
name|devstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|devstat
modifier|*
name|devstat_new_entry
parameter_list|(
specifier|const
name|void
modifier|*
name|dev_name
parameter_list|,
name|int
name|unit_number
parameter_list|,
name|u_int32_t
name|block_size
parameter_list|,
name|devstat_support_flags
name|flags
parameter_list|,
name|devstat_type_flags
name|device_type
parameter_list|,
name|devstat_priority
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_remove_entry
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_start_transaction
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|,
name|struct
name|bintime
modifier|*
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_start_transaction_bio
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_end_transaction
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|,
name|u_int32_t
name|bytes
parameter_list|,
name|devstat_tag_type
name|tag_type
parameter_list|,
name|devstat_trans_flags
name|flags
parameter_list|,
name|struct
name|bintime
modifier|*
name|now
parameter_list|,
name|struct
name|bintime
modifier|*
name|then
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_end_transaction_bio
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devstat_end_transaction_bio_bt
parameter_list|(
name|struct
name|devstat
modifier|*
name|ds
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|struct
name|bintime
modifier|*
name|now
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
comment|/* _DEVICESTAT_H */
end_comment

end_unit

