begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|pcmchan_children
block|{
name|SLIST_ENTRY
argument_list|(
argument|pcmchan_children
argument_list|)
name|link
expr_stmt|;
name|struct
name|pcm_channel
modifier|*
name|channel
decl_stmt|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|CHN_NAMELEN
value|32
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
name|volume
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
name|u_int32_t
name|blocks
decl_stmt|;
name|int
name|direction
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
name|char
name|name
index|[
name|CHN_NAMELEN
index|]
decl_stmt|;
name|void
modifier|*
name|lock
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcmchan_children
argument_list|)
name|children
expr_stmt|;
block|}
struct|;
end_struct

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
name|proc
modifier|*
name|p
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
name|chn_setdir
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|dir
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
name|chn_setspeed
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
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
name|u_int32_t
name|fmt
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
name|chn_wrfeed
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
name|chn_rdfeed
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
name|void
name|chn_wrupdate
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
name|chn_rdupdate
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

begin_ifdef
ifdef|#
directive|ifdef
name|USING_MUTEX
end_ifdef

begin_define
define|#
directive|define
name|CHN_LOCK
parameter_list|(
name|c
parameter_list|)
value|mtx_lock((struct mtx *)((c)->lock))
end_define

begin_define
define|#
directive|define
name|CHN_UNLOCK
parameter_list|(
name|c
parameter_list|)
value|mtx_unlock((struct mtx *)((c)->lock))
end_define

begin_define
define|#
directive|define
name|CHN_LOCKASSERT
parameter_list|(
name|c
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHN_LOCK
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CHN_UNLOCK
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CHN_LOCKASSERT
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|fmtvalid
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|,
name|u_int32_t
modifier|*
name|fmtlist
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PCMDIR_VIRTUAL
value|2
end_define

begin_define
define|#
directive|define
name|PCMDIR_PLAY
value|1
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
name|CHN_F_CLOSING
value|0x00000004
end_define

begin_comment
comment|/* a pending close */
end_comment

begin_define
define|#
directive|define
name|CHN_F_ABORTING
value|0x00000008
end_define

begin_comment
comment|/* a pending abort */
end_comment

begin_define
define|#
directive|define
name|CHN_F_RUNNING
value|0x00000010
end_define

begin_comment
comment|/* dma is running */
end_comment

begin_define
define|#
directive|define
name|CHN_F_TRIGGERED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHN_F_NOTRIGGER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHN_F_BUSY
value|0x00001000
end_define

begin_comment
comment|/* has been opened 	*/
end_comment

begin_define
define|#
directive|define
name|CHN_F_HAS_SIZE
value|0x00002000
end_define

begin_comment
comment|/* user set block size */
end_comment

begin_define
define|#
directive|define
name|CHN_F_NBIO
value|0x00004000
end_define

begin_comment
comment|/* do non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|CHN_F_MAPPED
value|0x00010000
end_define

begin_comment
comment|/* has been mmap()ed */
end_comment

begin_define
define|#
directive|define
name|CHN_F_DEAD
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CHN_F_BADSETTING
value|0x00040000
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
name|CHN_F_RESET
value|(CHN_F_BUSY | CHN_F_DEAD | CHN_F_VIRTUAL)
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
name|CHN_DEFAULT_HZ
value|50
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

