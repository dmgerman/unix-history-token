begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disk.h	8.1 (Berkeley) 6/2/93  *  * $Id: disk.h,v 1.7 1997/02/22 09:45:04 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISK_H_
end_define

begin_comment
comment|/*  * Disk device structures.  *  * Note that this is only a preliminary outline.  The final disk structures  * may be somewhat different.  */
end_comment

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|dkdevice
block|{
name|struct
name|device
name|dk_dev
decl_stmt|;
comment|/* base device */
name|struct
name|dkdevice
modifier|*
name|dk_next
decl_stmt|;
comment|/* list of disks; not yet used */
name|int
name|dk_bps
decl_stmt|;
comment|/* xfer rate: bytes per second */
name|int
name|dk_bopenmask
decl_stmt|;
comment|/* block devices open */
name|int
name|dk_copenmask
decl_stmt|;
comment|/* character devices open */
name|int
name|dk_openmask
decl_stmt|;
comment|/* composite (bopen|copen) */
name|int
name|dk_state
decl_stmt|;
comment|/* label state   ### */
name|int
name|dk_blkshift
decl_stmt|;
comment|/* shift to convert DEV_BSIZE to blks */
name|int
name|dk_byteshift
decl_stmt|;
comment|/* shift to convert bytes to blks */
name|struct
name|dkdriver
modifier|*
name|dk_driver
decl_stmt|;
comment|/* pointer to driver */
name|daddr_t
name|dk_labelsector
decl_stmt|;
comment|/* sector containing label */
name|struct
name|disklabel
name|dk_label
decl_stmt|;
comment|/* label */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dkdriver
block|{
name|void
argument_list|(
argument|*d_strategy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|notyet
name|int
argument_list|(
argument|*d_open
argument_list|)
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|ifmt
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*d_close
argument_list|)
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
operator|,
name|int
name|ifmt
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*d_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*d_dump
argument_list|)
name|__P
argument_list|(
operator|(
name|dev_t
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*d_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|daddr_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*d_mklabel
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* states */
end_comment

begin_define
define|#
directive|define
name|DK_CLOSED
value|0
end_define

begin_comment
comment|/* drive is closed */
end_comment

begin_define
define|#
directive|define
name|DK_WANTOPEN
value|1
end_define

begin_comment
comment|/* drive being opened */
end_comment

begin_define
define|#
directive|define
name|DK_WANTOPENRAW
value|2
end_define

begin_comment
comment|/* drive being opened */
end_comment

begin_define
define|#
directive|define
name|DK_RDLABEL
value|3
end_define

begin_comment
comment|/* label being read */
end_comment

begin_define
define|#
directive|define
name|DK_OPEN
value|4
end_define

begin_comment
comment|/* label read, drive open */
end_comment

begin_define
define|#
directive|define
name|DK_OPENRAW
value|5
end_define

begin_comment
comment|/* open without label */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DISKSORT_STATS
end_ifdef

begin_comment
comment|/*  * Stats from disksort().  */
end_comment

begin_struct
struct|struct
name|disksort_stats
block|{
name|long
name|ds_newhead
decl_stmt|;
comment|/* # new queue heads created */
name|long
name|ds_newtail
decl_stmt|;
comment|/* # new queue tails created */
name|long
name|ds_midfirst
decl_stmt|;
comment|/* # insertions into sort list */
name|long
name|ds_endfirst
decl_stmt|;
comment|/* # insertions at end of sort list */
name|long
name|ds_newsecond
decl_stmt|;
comment|/* # inversions (2nd lists) created */
name|long
name|ds_midsecond
decl_stmt|;
comment|/* # insertions into 2nd list */
name|long
name|ds_endsecond
decl_stmt|;
comment|/* # insertions at end of 2nd list */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|bufqdisksort
name|__P
argument_list|(
operator|(
expr|struct
name|buf_queue_head
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|readdisklabel
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setdisklabel
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|,
expr|struct
name|disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|writedisklabel
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|diskerr
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

