begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2009 Ariff Abdullah<ariff@FreeBSD.org>  * Portions Copyright (c) Ryan Beasley<ryan.beasley@gmail.com> - GSoC 2006  * Copyright (c) 1999 Cameron Grant<cg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|pcmchan_caps
block|{
name|u_int32_t
name|minspeed
decl_stmt|,
name|maxspeed
decl_stmt|;
name|u_int32_t
modifier|*
name|fmtlist
decl_stmt|;
name|u_int32_t
name|caps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcmchan_matrix
block|{
name|int
name|id
decl_stmt|;
name|uint8_t
name|channels
decl_stmt|,
name|ext
decl_stmt|;
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|uint32_t
name|members
decl_stmt|;
block|}
name|map
index|[
name|SND_CHN_T_MAX
operator|+
literal|1
index|]
struct|;
name|uint32_t
name|mask
decl_stmt|;
name|int8_t
name|offset
index|[
name|SND_CHN_T_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|pcm_channel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcmchan_syncgroup
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcmchan_syncmember
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|snd_pcm_syncgroups_mtx
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SLIST_HEAD(pcm_synclist
operator|,
extern|pcmchan_syncgroup
end_extern

begin_expr_stmt
unit|)
name|snd_pcm_syncgroups
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PCM_SG_LOCK
parameter_list|()
value|mtx_lock(&snd_pcm_syncgroups_mtx)
end_define

begin_define
define|#
directive|define
name|PCM_SG_TRYLOCK
parameter_list|()
value|mtx_trylock(&snd_pcm_syncgroups_mtx)
end_define

begin_define
define|#
directive|define
name|PCM_SG_UNLOCK
parameter_list|()
value|mtx_unlock(&snd_pcm_syncgroups_mtx)
end_define

begin_define
define|#
directive|define
name|PCM_SG_LOCKASSERT
parameter_list|(
name|arg
parameter_list|)
value|mtx_assert(&snd_pcm_syncgroups_mtx, arg)
end_define

begin_comment
comment|/**  * @brief Specifies an audio device sync group  */
end_comment

begin_struct
struct|struct
name|pcmchan_syncgroup
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcmchan_syncgroup
argument_list|)
name|link
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcmchan_syncmember
argument_list|)
name|members
expr_stmt|;
name|int
name|id
decl_stmt|;
comment|/**< Group identifier; set to address of group. */
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief Specifies a container for members of a sync group  */
end_comment

begin_struct
struct|struct
name|pcmchan_syncmember
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcmchan_syncmember
argument_list|)
name|link
expr_stmt|;
name|struct
name|pcmchan_syncgroup
modifier|*
name|parent
decl_stmt|;
comment|/**< group head */
name|struct
name|pcm_channel
modifier|*
name|ch
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHN_NAMELEN
value|32
end_define

begin_define
define|#
directive|define
name|CHN_COMM_UNUSED
value|"<UNUSED>"
end_define

begin_define
define|#
directive|define
name|CHN_COMM_UNKNOWN
value|"<UNKNOWN>"
end_define

begin_struct
struct|struct
name|pcm_channel
block|{
name|kobj_t
name|methods
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|int
name|refcount
decl_stmt|;
name|struct
name|pcm_feeder
modifier|*
name|feeder
decl_stmt|;
name|u_int32_t
name|align
decl_stmt|;
name|int
name|latency
decl_stmt|;
name|u_int32_t
name|speed
decl_stmt|;
name|u_int32_t
name|format
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|feederflags
decl_stmt|;
name|u_int64_t
name|blocks
decl_stmt|;
name|int
name|direction
decl_stmt|;
name|unsigned
name|int
name|interrupts
decl_stmt|,
name|xruns
decl_stmt|,
name|feedcount
decl_stmt|;
name|unsigned
name|int
name|timeout
decl_stmt|;
name|struct
name|snd_dbuf
modifier|*
name|bufhard
decl_stmt|,
modifier|*
name|bufsoft
decl_stmt|;
name|struct
name|snddev_info
modifier|*
name|parentsnddev
decl_stmt|;
name|struct
name|pcm_channel
modifier|*
name|parentchannel
decl_stmt|;
name|void
modifier|*
name|devinfo
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
name|name
index|[
name|CHN_NAMELEN
index|]
decl_stmt|;
name|char
name|comm
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
name|int
name|trigger
decl_stmt|;
comment|/** 	 * For interrupt manipulations. 	 */
name|struct
name|cv
name|intr_cv
decl_stmt|;
comment|/** 	 * Increment,decrement this around operations that temporarily yield 	 * lock. 	 */
name|unsigned
name|int
name|inprog
decl_stmt|;
comment|/** 	 * Special channel operations should examine @c inprog after acquiring 	 * lock.  If zero, operations may continue.  Else, thread should 	 * wait on this cv for previous operation to finish. 	 */
name|struct
name|cv
name|cv
decl_stmt|;
comment|/** 	 * Low water mark for select()/poll(). 	 * 	 * This is initialized to the channel's fragment size, and will be 	 * overwritten if a new fragment size is set.  Users may alter this 	 * value directly with the @c SNDCTL_DSP_LOW_WATER ioctl. 	 */
name|unsigned
name|int
name|lw
decl_stmt|;
comment|/** 	 * If part of a sync group, this will point to the syncmember 	 * container. 	 */
name|struct
name|pcmchan_syncmember
modifier|*
name|sm
decl_stmt|;
ifdef|#
directive|ifdef
name|OSSV4_EXPERIMENT
name|u_int16_t
name|lpeak
decl_stmt|,
name|rpeak
decl_stmt|;
comment|/**< Peak value from 0-32767. */
endif|#
directive|endif
struct|struct
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcm_channel
argument_list|)
name|head
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|pcm_channel
argument_list|)
name|link
expr_stmt|;
struct|struct
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcm_channel
argument_list|)
name|head
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|pcm_channel
argument_list|)
name|link
expr_stmt|;
block|}
name|busy
struct|;
block|}
name|children
struct|;
struct|struct
block|{
struct|struct
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcm_channel
argument_list|)
name|link
expr_stmt|;
struct|struct
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcm_channel
argument_list|)
name|link
expr_stmt|;
block|}
name|busy
struct|;
struct|struct
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcm_channel
argument_list|)
name|link
expr_stmt|;
block|}
name|opened
struct|;
block|}
name|pcm
struct|;
block|}
name|channels
struct|;
name|struct
name|pcmchan_matrix
name|matrix
decl_stmt|;
name|struct
name|pcmchan_matrix
name|matrix_scratch
decl_stmt|;
name|int
name|volume
index|[
name|SND_VOL_C_MAX
index|]
index|[
name|SND_CHN_T_VOL_MAX
index|]
decl_stmt|;
name|void
modifier|*
name|data1
decl_stmt|,
modifier|*
name|data2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHN_HEAD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|&(x)->y.head
end_define

begin_define
define|#
directive|define
name|CHN_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SLIST_INIT(CHN_HEAD(x, y))
end_define

begin_define
define|#
directive|define
name|CHN_LINK
parameter_list|(
name|y
parameter_list|)
value|y.link
end_define

begin_define
define|#
directive|define
name|CHN_EMPTY
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SLIST_EMPTY(CHN_HEAD(x, y))
end_define

begin_define
define|#
directive|define
name|CHN_FIRST
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SLIST_FIRST(CHN_HEAD(x, y))
end_define

begin_define
define|#
directive|define
name|CHN_FOREACH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SLIST_FOREACH(x, CHN_HEAD(y, z), CHN_LINK(z))
end_define

begin_define
define|#
directive|define
name|CHN_FOREACH_SAFE
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SLIST_FOREACH_SAFE(w, CHN_HEAD(x, z), CHN_LINK(z), y)
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_HEAD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SLIST_INSERT_HEAD(CHN_HEAD(x, z), y, CHN_LINK(z))
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_AFTER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SLIST_INSERT_AFTER(x, y, CHN_LINK(z))
end_define

begin_define
define|#
directive|define
name|CHN_REMOVE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|SLIST_REMOVE(CHN_HEAD(x, z), y, pcm_channel, CHN_LINK(z))
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_HEAD_SAFE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|do {			\ 	struct pcm_channel *t = NULL;					\ 	CHN_FOREACH(t, x, z) {						\ 		if (t == y)						\ 			break;						\ 	} 								\ 	if (t != y)							\ 		CHN_INSERT_HEAD(x, y, z);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_AFTER_SAFE
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|do {			\ 	struct pcm_channel *t = NULL;					\ 	CHN_FOREACH(t, w, z) {						\ 		if (t == y)						\ 			break;						\ 	} 								\ 	if (t != y)							\ 		CHN_INSERT_AFTER(x, y, z);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHN_REMOVE_SAFE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|do {			\ 	struct pcm_channel *t = NULL;					\ 	CHN_FOREACH(t, x, z) {						\ 		if (t == y)						\ 			break;						\ 	} 								\ 	if (t == y)							\ 		CHN_REMOVE(x, y, z);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_SORT
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|do {			\ 	struct pcm_channel *t, *a = NULL;				\ 	CHN_FOREACH(t, x, z) {						\ 		if ((y)->unit w t->unit)				\ 			a = t;						\ 		else							\ 			break;						\ 	}								\ 	if (a != NULL)							\ 		CHN_INSERT_AFTER(a, y, z);				\ 	else								\ 		CHN_INSERT_HEAD(x, y, z);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_SORT_ASCEND
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|CHN_INSERT_SORT(>, x, y, z)
end_define

begin_define
define|#
directive|define
name|CHN_INSERT_SORT_DESCEND
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|CHN_INSERT_SORT(<, x, y, z)
end_define

begin_define
define|#
directive|define
name|CHN_UNIT
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2u((x)->unit))
end_define

begin_define
define|#
directive|define
name|CHN_DEV
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2d((x)->unit))
end_define

begin_define
define|#
directive|define
name|CHN_CHAN
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2c((x)->unit))
end_define

begin_define
define|#
directive|define
name|CHN_BUF_PARENT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((x) != NULL&& (x)->parentchannel != NULL&&			\ 	(x)->parentchannel->bufhard != NULL) ?				\ 	(x)->parentchannel->bufhard : (y))
end_define

begin_define
define|#
directive|define
name|CHN_BROADCAST
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if ((x)->cv_waiters != 0)					\ 		cv_broadcastpri(x, PRIBIO);				\ } while (0)
end_define

begin_include
include|#
directive|include
file|"channel_if.h"
end_include

begin_function_decl
name|int
name|chn_reinit
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_write
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|struct
name|uio
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_read
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|struct
name|uio
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|chn_start
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_sync
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_flush
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_poll
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|ev
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_init
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_kill
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_reset
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|u_int32_t
name|fmt
parameter_list|,
name|u_int32_t
name|spd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setvolume
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|left
parameter_list|,
name|int
name|right
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setvolume_multi
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|vc
parameter_list|,
name|int
name|left
parameter_list|,
name|int
name|right
parameter_list|,
name|int
name|center
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setvolume_matrix
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|vc
parameter_list|,
name|int
name|vt
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_getvolume_matrix
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|vc
parameter_list|,
name|int
name|vt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_vpc_reset
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|vc
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setparam
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|uint32_t
name|format
parameter_list|,
name|uint32_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setspeed
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|uint32_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setformat
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|uint32_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setblocksize
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|blkcnt
parameter_list|,
name|int
name|blksz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setlatency
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|latency
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_syncstate
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_trigger
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|go
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_getptr
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcmchan_caps
modifier|*
name|chn_getcaps
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|chn_getformats
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcmchan_matrix
modifier|*
name|chn_getmatrix
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setmatrix
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|,
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_oss_getorder
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_oss_setorder
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_oss_getmask
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_resetbuf
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_intr_locked
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_intr
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_abort
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_notify
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|u_int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_getrates
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
modifier|*
modifier|*
name|rates
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_syncdestroy
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CHN_SETVOLUME
parameter_list|(
modifier|...
parameter_list|)
value|chn_setvolume_matrix(__VA_ARGS__)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SND_DIAGNOSTIC
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CHN_GETVOLUME
parameter_list|(
modifier|...
parameter_list|)
value|chn_getvolume_matrix(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHN_GETVOLUME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((x)->volume[y][z])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OSSV4_EXPERIMENT
end_ifdef

begin_function_decl
name|int
name|chn_getpeaks
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
modifier|*
name|lpeak
parameter_list|,
name|int
modifier|*
name|rpeak
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHN_LOCKOWNED
parameter_list|(
name|c
parameter_list|)
value|mtx_owned((c)->lock)
end_define

begin_define
define|#
directive|define
name|CHN_LOCK
parameter_list|(
name|c
parameter_list|)
value|mtx_lock((c)->lock)
end_define

begin_define
define|#
directive|define
name|CHN_UNLOCK
parameter_list|(
name|c
parameter_list|)
value|mtx_unlock((c)->lock)
end_define

begin_define
define|#
directive|define
name|CHN_TRYLOCK
parameter_list|(
name|c
parameter_list|)
value|mtx_trylock((c)->lock)
end_define

begin_define
define|#
directive|define
name|CHN_LOCKASSERT
parameter_list|(
name|c
parameter_list|)
value|mtx_assert((c)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|CHN_UNLOCKASSERT
parameter_list|(
name|c
parameter_list|)
value|mtx_assert((c)->lock, MA_NOTOWNED)
end_define

begin_function_decl
name|int
name|snd_fmtvalid
parameter_list|(
name|uint32_t
name|fmt
parameter_list|,
name|uint32_t
modifier|*
name|fmtlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_str2afmt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_afmt2str
parameter_list|(
name|uint32_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AFMTSTR_LEN
value|16
end_define

begin_decl_stmt
specifier|extern
name|int
name|chn_latency
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|chn_latency_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|report_soft_formats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|report_soft_matrix
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCMDIR_PLAY
value|1
end_define

begin_define
define|#
directive|define
name|PCMDIR_PLAY_VIRTUAL
value|2
end_define

begin_define
define|#
directive|define
name|PCMDIR_REC
value|-1
end_define

begin_define
define|#
directive|define
name|PCMDIR_REC_VIRTUAL
value|-2
end_define

begin_define
define|#
directive|define
name|PCMTRIG_START
value|1
end_define

begin_define
define|#
directive|define
name|PCMTRIG_EMLDMAWR
value|2
end_define

begin_define
define|#
directive|define
name|PCMTRIG_EMLDMARD
value|3
end_define

begin_define
define|#
directive|define
name|PCMTRIG_STOP
value|0
end_define

begin_define
define|#
directive|define
name|PCMTRIG_ABORT
value|-1
end_define

begin_define
define|#
directive|define
name|PCMTRIG_COMMON
parameter_list|(
name|x
parameter_list|)
value|((x) == PCMTRIG_START ||		\ 				 (x) == PCMTRIG_STOP ||			\ 				 (x) == PCMTRIG_ABORT)
end_define

begin_define
define|#
directive|define
name|CHN_F_CLOSING
value|0x00000001
end_define

begin_comment
comment|/* a pending close */
end_comment

begin_define
define|#
directive|define
name|CHN_F_ABORTING
value|0x00000002
end_define

begin_comment
comment|/* a pending abort */
end_comment

begin_define
define|#
directive|define
name|CHN_F_RUNNING
value|0x00000004
end_define

begin_comment
comment|/* dma is running */
end_comment

begin_define
define|#
directive|define
name|CHN_F_TRIGGERED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHN_F_NOTRIGGER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHN_F_SLEEPING
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHN_F_NBIO
value|0x00000040
end_define

begin_comment
comment|/* do non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|CHN_F_MMAP
value|0x00000080
end_define

begin_comment
comment|/* has been mmap()ed */
end_comment

begin_define
define|#
directive|define
name|CHN_F_BUSY
value|0x00000100
end_define

begin_comment
comment|/* has been opened 	*/
end_comment

begin_define
define|#
directive|define
name|CHN_F_DIRTY
value|0x00000200
end_define

begin_comment
comment|/* need re-config */
end_comment

begin_define
define|#
directive|define
name|CHN_F_DEAD
value|0x00000400
end_define

begin_comment
comment|/* too many errors, dead, mdk */
end_comment

begin_define
define|#
directive|define
name|CHN_F_SILENCE
value|0x00000800
end_define

begin_comment
comment|/* silence, nil, null, yada */
end_comment

begin_define
define|#
directive|define
name|CHN_F_HAS_SIZE
value|0x00001000
end_define

begin_comment
comment|/* user set block size */
end_comment

begin_define
define|#
directive|define
name|CHN_F_HAS_VCHAN
value|0x00002000
end_define

begin_comment
comment|/* vchan master */
end_comment

begin_define
define|#
directive|define
name|CHN_F_VCHAN_PASSTHROUGH
value|0x00004000
end_define

begin_comment
comment|/* digital ac3/dts passthrough */
end_comment

begin_define
define|#
directive|define
name|CHN_F_VCHAN_ADAPTIVE
value|0x00008000
end_define

begin_comment
comment|/* adaptive format/rate selection */
end_comment

begin_define
define|#
directive|define
name|CHN_F_VCHAN_DYNAMIC
value|(CHN_F_VCHAN_PASSTHROUGH | CHN_F_VCHAN_ADAPTIVE)
end_define

begin_define
define|#
directive|define
name|CHN_F_VIRTUAL
value|0x10000000
end_define

begin_comment
comment|/* not backed by hardware */
end_comment

begin_define
define|#
directive|define
name|CHN_F_BITPERFECT
value|0x20000000
end_define

begin_comment
comment|/* un-cooked, Heh.. */
end_comment

begin_define
define|#
directive|define
name|CHN_F_PASSTHROUGH
value|0x40000000
end_define

begin_comment
comment|/* passthrough re-config */
end_comment

begin_define
define|#
directive|define
name|CHN_F_EXCLUSIVE
value|0x80000000
end_define

begin_comment
comment|/* exclusive access */
end_comment

begin_define
define|#
directive|define
name|CHN_F_BITS
value|"\020"					\ 				"\001CLOSING"				\ 				"\002ABORTING"				\ 				"\003RUNNING"				\ 				"\004TRIGGERED"				\ 				"\005NOTRIGGER"				\ 				"\006SLEEPING"				\ 				"\007NBIO"				\ 				"\010MMAP"				\ 				"\011BUSY"				\ 				"\012DIRTY"				\ 				"\013DEAD"				\ 				"\014SILENCE"				\ 				"\015HAS_SIZE"				\ 				"\016HAS_VCHAN"				\ 				"\017VCHAN_PASSTHROUGH"			\ 				"\020VCHAN_ADAPTIVE"			\ 				"\035VIRTUAL"				\ 				"\036BITPERFECT"			\ 				"\037PASSTHROUGH"			\ 				"\040EXCLUSIVE"
end_define

begin_define
define|#
directive|define
name|CHN_F_RESET
value|(CHN_F_BUSY | CHN_F_DEAD |		\ 				 CHN_F_VIRTUAL | CHN_F_HAS_VCHAN |	\ 				 CHN_F_VCHAN_DYNAMIC |			\ 				 CHN_F_PASSTHROUGH | CHN_F_EXCLUSIVE)
end_define

begin_define
define|#
directive|define
name|CHN_F_MMAP_INVALID
value|(CHN_F_DEAD | CHN_F_RUNNING)
end_define

begin_define
define|#
directive|define
name|CHN_N_RATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CHN_N_FORMAT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHN_N_VOLUME
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHN_N_BLOCKSIZE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHN_N_TRIGGER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_MAX
value|10
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|CHN_POLICY_MIN
value|CHN_LATENCY_MIN
end_define

begin_define
define|#
directive|define
name|CHN_POLICY_MAX
value|CHN_LATENCY_MAX
end_define

begin_define
define|#
directive|define
name|CHN_POLICY_DEFAULT
value|CHN_LATENCY_DEFAULT
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_PROFILE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_PROFILE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|CHN_LATENCY_PROFILE_DEFAULT
value|CHN_LATENCY_PROFILE_MAX
end_define

begin_define
define|#
directive|define
name|CHN_STARTED
parameter_list|(
name|c
parameter_list|)
value|((c)->flags& CHN_F_TRIGGERED)
end_define

begin_define
define|#
directive|define
name|CHN_STOPPED
parameter_list|(
name|c
parameter_list|)
value|(!CHN_STARTED(c))
end_define

begin_define
define|#
directive|define
name|CHN_DIRSTR
parameter_list|(
name|c
parameter_list|)
value|(((c)->direction == PCMDIR_PLAY) ? \ 				"PCMDIR_PLAY" : "PCMDIR_REC")
end_define

begin_define
define|#
directive|define
name|CHN_BITPERFECT
parameter_list|(
name|c
parameter_list|)
value|((c)->flags& CHN_F_BITPERFECT)
end_define

begin_define
define|#
directive|define
name|CHN_PASSTHROUGH
parameter_list|(
name|c
parameter_list|)
value|((c)->flags& CHN_F_PASSTHROUGH)
end_define

begin_define
define|#
directive|define
name|CHN_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|CHN_TIMEOUT_MIN
value|1
end_define

begin_define
define|#
directive|define
name|CHN_TIMEOUT_MAX
value|10
end_define

begin_comment
comment|/*  * This should be large enough to hold all pcm data between  * tsleeps in chn_{read,write} at the highest sample rate.  * (which is usually 48kHz * 16bit * stereo = 192000 bytes/sec)  */
end_comment

begin_define
define|#
directive|define
name|CHN_2NDBUFBLKSIZE
value|(2 * 1024)
end_define

begin_comment
comment|/* The total number of blocks per secondary bufhard. */
end_comment

begin_define
define|#
directive|define
name|CHN_2NDBUFBLKNUM
value|(32)
end_define

begin_comment
comment|/* The size of a whole secondary bufhard. */
end_comment

begin_define
define|#
directive|define
name|CHN_2NDBUFMAXSIZE
value|(131072)
end_define

begin_define
define|#
directive|define
name|CHANNEL_DECLARE
parameter_list|(
name|name
parameter_list|)
value|static DEFINE_CLASS(name, name ## _methods, sizeof(struct kobj))
end_define

end_unit

