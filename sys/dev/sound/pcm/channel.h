begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|chn_write
parameter_list|(
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
name|chn_sync
parameter_list|(
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
name|chn_setdir
parameter_list|(
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
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_setvolume
parameter_list|(
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
name|pcm_channel
modifier|*
name|c
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
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcmchan_caps
modifier|*
name|chn_getcaps
parameter_list|(
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_allocbuf
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|,
name|bus_dma_tag_t
name|parent_dmat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_resetbuf
parameter_list|(
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
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chn_dmaupdate
parameter_list|(
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
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buf_isadma
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|,
name|int
name|go
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_isadmaptr
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_feedchain
parameter_list|(
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|pcm_feeder
name|feeder_root
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
name|CHN_F_READING
value|0x00000001
end_define

begin_comment
comment|/* have a pending read */
end_comment

begin_define
define|#
directive|define
name|CHN_F_WRITING
value|0x00000002
end_define

begin_comment
comment|/* have a pending write */
end_comment

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
name|CHN_F_PENDING_IO
value|(CHN_F_READING | CHN_F_WRITING)
end_define

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
name|CHN_F_INIT
value|0x00008000
end_define

begin_comment
comment|/* changed parameters. need init */
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
name|CHN_F_RESET
value|(CHN_F_BUSY)
end_define

end_unit

