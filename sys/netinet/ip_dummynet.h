begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2010 Luigi Rizzo, Universita` di Pisa  * Portions Copyright (c) 2000 Akamba Corp.  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DUMMYNET_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DUMMYNET_H
end_define

begin_comment
comment|/*  * Definition of the kernel-userland API for dummynet.  *  * Setsockopt() and getsockopt() pass a batch of objects, each  * of them starting with a "struct dn_id" which should fully identify  * the object and its relation with others in the sequence.  * The first object in each request should have  *	 type= DN_CMD_*, id = DN_API_VERSION.  * For other objects, type and subtype specify the object, len indicates  * the total length including the header, and 'id' identifies the specific  * object.  *  * Most objects are numbered with an identifier in the range 1..65535.  * DN_MAX_ID indicates the first value outside the range.  */
end_comment

begin_define
define|#
directive|define
name|DN_API_VERSION
value|12500000
end_define

begin_define
define|#
directive|define
name|DN_MAX_ID
value|0x10000
end_define

begin_struct
struct|struct
name|dn_id
block|{
name|uint16_t
name|len
decl_stmt|;
comment|/* total obj len including this header */
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|subtype
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
comment|/* generic id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These values are in the type field of struct dn_id.  * To preserve the ABI, never rearrange the list or delete  * entries with the exception of DN_LAST  */
end_comment

begin_enum
enum|enum
block|{
name|DN_NONE
init|=
literal|0
block|,
name|DN_LINK
init|=
literal|1
block|,
name|DN_FS
block|,
name|DN_SCH
block|,
name|DN_SCH_I
block|,
name|DN_QUEUE
block|,
name|DN_DELAY_LINE
block|,
name|DN_PROFILE
block|,
name|DN_FLOW
block|,
comment|/* struct dn_flow */
name|DN_TEXT
block|,
comment|/* opaque text is the object */
name|DN_CMD_CONFIG
init|=
literal|0x80
block|,
comment|/* objects follow */
name|DN_CMD_DELETE
block|,
comment|/* subtype + list of entries */
name|DN_CMD_GET
block|,
comment|/* subtype + list of entries */
name|DN_CMD_FLUSH
block|,
comment|/* for compatibility with FreeBSD 7.2/8 */
name|DN_COMPAT_PIPE
block|,
name|DN_COMPAT_QUEUE
block|,
name|DN_GET_COMPAT
block|,
comment|/* special commands for emulation of sysctl variables */
name|DN_SYSCTL_GET
block|,
name|DN_SYSCTL_SET
block|,
name|DN_LAST
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* subtype for schedulers, flowset and the like */
name|DN_SCHED_UNKNOWN
init|=
literal|0
block|,
name|DN_SCHED_FIFO
init|=
literal|1
block|,
name|DN_SCHED_WF2QP
init|=
literal|2
block|,
comment|/* others are in individual modules */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* user flags */
name|DN_HAVE_MASK
init|=
literal|0x0001
block|,
comment|/* fs or sched has a mask */
name|DN_NOERROR
init|=
literal|0x0002
block|,
comment|/* do not report errors */
name|DN_QHT_HASH
init|=
literal|0x0004
block|,
comment|/* qht is a hash table */
name|DN_QSIZE_BYTES
init|=
literal|0x0008
block|,
comment|/* queue size is in bytes */
name|DN_HAS_PROFILE
init|=
literal|0x0010
block|,
comment|/* a link has a profile */
name|DN_IS_RED
init|=
literal|0x0020
block|,
name|DN_IS_GENTLE_RED
init|=
literal|0x0040
block|,
name|DN_IS_ECN
init|=
literal|0x0080
block|,
name|DN_PIPE_CMD
init|=
literal|0x1000
block|,
comment|/* pipe config... */
block|}
enum|;
end_enum

begin_comment
comment|/*  * link template.  */
end_comment

begin_struct
struct|struct
name|dn_link
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
comment|/* 	 * Userland sets bw and delay in bits/s and milliseconds. 	 * The kernel converts this back and forth to bits/tick and ticks. 	 * XXX what about burst ? 	 */
name|int32_t
name|link_nr
decl_stmt|;
name|int
name|bandwidth
decl_stmt|;
comment|/* bit/s or bits/tick.   */
name|int
name|delay
decl_stmt|;
comment|/* ms and ticks */
name|uint64_t
name|burst
decl_stmt|;
comment|/* scaled. bits*Hz  XXX */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A flowset, which is a template for flows. Contains parameters  * from the command line: id, target scheduler, queue sizes, plr,  * flow masks, buckets for the flow hash, and possibly scheduler-  * specific parameters (weight, quantum and so on).  */
end_comment

begin_struct
struct|struct
name|dn_fs
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
name|uint32_t
name|fs_nr
decl_stmt|;
comment|/* the flowset number */
name|uint32_t
name|flags
decl_stmt|;
comment|/* userland flags */
name|int
name|qsize
decl_stmt|;
comment|/* queue size in slots or bytes */
name|int32_t
name|plr
decl_stmt|;
comment|/* PLR, pkt loss rate (2^31-1 means 100%) */
name|uint32_t
name|buckets
decl_stmt|;
comment|/* buckets used for the queue hash table */
name|struct
name|ipfw_flow_id
name|flow_mask
decl_stmt|;
name|uint32_t
name|sched_nr
decl_stmt|;
comment|/* the scheduler we attach to */
comment|/* generic scheduler parameters. Leave them at -1 if unset. 	 * Now we use 0: weight, 1: lmax, 2: priority 	 */
name|int
name|par
index|[
literal|4
index|]
decl_stmt|;
comment|/* RED/GRED parameters. 	 * weight and probabilities are in the range 0..1 represented 	 * in fixed point arithmetic with SCALE_RED decimal bits. 	 */
define|#
directive|define
name|SCALE_RED
value|16
define|#
directive|define
name|SCALE
parameter_list|(
name|x
parameter_list|)
value|( (x)<< SCALE_RED )
define|#
directive|define
name|SCALE_VAL
parameter_list|(
name|x
parameter_list|)
value|( (x)>> SCALE_RED )
define|#
directive|define
name|SCALE_MUL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( ( (x) * (y) )>> SCALE_RED )
name|int
name|w_q
decl_stmt|;
comment|/* queue weight (scaled) */
name|int
name|max_th
decl_stmt|;
comment|/* maximum threshold for queue (scaled) */
name|int
name|min_th
decl_stmt|;
comment|/* minimum threshold for queue (scaled) */
name|int
name|max_p
decl_stmt|;
comment|/* maximum value for p_b (scaled) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * dn_flow collects flow_id and stats for queues and scheduler  * instances, and is used to pass these info to userland.  * oid.type/oid.subtype describe the object, oid.id is number  * of the parent object.  */
end_comment

begin_struct
struct|struct
name|dn_flow
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
name|struct
name|ipfw_flow_id
name|fid
decl_stmt|;
name|uint64_t
name|tot_pkts
decl_stmt|;
comment|/* statistics counters  */
name|uint64_t
name|tot_bytes
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
comment|/* Queue length, in packets */
name|uint32_t
name|len_bytes
decl_stmt|;
comment|/* Queue length, in bytes */
name|uint32_t
name|drops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scheduler template, mostly indicating the name, number,  * sched_mask and buckets.  */
end_comment

begin_struct
struct|struct
name|dn_sch
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
name|uint32_t
name|sched_nr
decl_stmt|;
comment|/* N, scheduler number */
name|uint32_t
name|buckets
decl_stmt|;
comment|/* number of buckets for the instances */
name|uint32_t
name|flags
decl_stmt|;
comment|/* have_mask, ... */
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* null terminated */
comment|/* mask to select the appropriate scheduler instance */
name|struct
name|ipfw_flow_id
name|sched_mask
decl_stmt|;
comment|/* M */
block|}
struct|;
end_struct

begin_comment
comment|/* A delay profile is attached to a link.  * Note that a profile, as any other object, cannot be longer than 2^16  */
end_comment

begin_define
define|#
directive|define
name|ED_MAX_SAMPLES_NO
value|1024
end_define

begin_struct
struct|struct
name|dn_profile
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
comment|/* fields to simulate a delay profile */
define|#
directive|define
name|ED_MAX_NAME_LEN
value|32
name|char
name|name
index|[
name|ED_MAX_NAME_LEN
index|]
decl_stmt|;
name|int
name|link_nr
decl_stmt|;
name|int
name|loss_level
decl_stmt|;
name|int
name|bandwidth
decl_stmt|;
comment|// XXX use link bandwidth?
name|int
name|samples_no
decl_stmt|;
comment|/* actual len of samples[] */
name|int
name|samples
index|[
name|ED_MAX_SAMPLES_NO
index|]
decl_stmt|;
comment|/* may be shorter */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Overall structure of dummynet  In dummynet, packets are selected with the firewall rules, and passed to two different objects: PIPE or QUEUE (bad name).  A QUEUE defines a classifier, which groups packets into flows according to a 'mask', puts them into independent queues (one per flow) with configurable size and queue management policy, and passes flows to a scheduler:                   (flow_mask|sched_mask)  sched_mask 	 +---------+   weight Wx  +-------------+          |         |->-[flow]-->--|             |-+     -->--| QUEUE x |   ...        |             | |          |         |->-[flow]-->--| SCHEDuler N | | 	 +---------+              |             | | 	     ...                  |             +--[LINK N]-->-- 	 +---------+   weight Wy  |             | +--[LINK N]-->--          |         |->-[flow]-->--|             | |     -->--| QUEUE y |   ...        |             | |          |         |->-[flow]-->--|             | | 	 +---------+              +-------------+ | 	                            +-------------+  Many QUEUE objects can connect to the same scheduler, each QUEUE object can have its own set of parameters.  In turn, the SCHEDuler 'forks' multiple instances according to a 'sched_mask', each instance manages its own set of queues and transmits on a private instance of a configurable LINK.  A PIPE is a simplified version of the above, where there is no flow_mask, and each scheduler instance handles a single queue.  The following data structures (visible from userland) describe the objects used by dummynet:   + dn_link, contains the main configuration parameters related    to delay and bandwidth;  + dn_profile describes a delay profile;  + dn_flow describes the flow status (flow id, statistics)      + dn_sch describes a scheduler  + dn_fs describes a flowset (msk, weight, queue parameters)   *  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_DUMMYNET_H */
end_comment

end_unit

