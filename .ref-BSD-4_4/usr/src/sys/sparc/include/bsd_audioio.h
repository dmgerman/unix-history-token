begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)bsd_audioio.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: bsd_audioio.h,v 1.5 92/11/21 20:46:46 van Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_AUDIOIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSD_AUDIOIO_H_
end_define

begin_comment
comment|/*  * /dev/audio ioctls.  needs comments!  */
end_comment

begin_define
define|#
directive|define
name|AUDIO_MIN_GAIN
value|(0)
end_define

begin_define
define|#
directive|define
name|AUDIO_MAX_GAIN
value|(255)
end_define

begin_define
define|#
directive|define
name|AUDIO_ENCODING_ULAW
value|(1)
end_define

begin_define
define|#
directive|define
name|AUDIO_ENCODING_ALAW
value|(2)
end_define

begin_struct
struct|struct
name|audio_prinfo
block|{
name|u_int
name|sample_rate
decl_stmt|;
name|u_int
name|channels
decl_stmt|;
name|u_int
name|precision
decl_stmt|;
name|u_int
name|encoding
decl_stmt|;
name|u_int
name|gain
decl_stmt|;
name|u_int
name|port
decl_stmt|;
name|u_long
name|seek
decl_stmt|;
comment|/* BSD extension */
name|u_int
name|ispare
index|[
literal|3
index|]
decl_stmt|;
name|u_int
name|samples
decl_stmt|;
name|u_int
name|eof
decl_stmt|;
name|u_char
name|pause
decl_stmt|;
name|u_char
name|error
decl_stmt|;
name|u_char
name|waiting
decl_stmt|;
name|u_char
name|cspare
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|open
decl_stmt|;
name|u_char
name|active
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|audio_info
block|{
name|struct
name|audio_prinfo
name|play
decl_stmt|;
name|struct
name|audio_prinfo
name|record
decl_stmt|;
name|u_int
name|monitor_gain
decl_stmt|;
comment|/* BSD extensions */
name|u_int
name|blocksize
decl_stmt|;
comment|/* input blocking threshold */
name|u_int
name|hiwat
decl_stmt|;
comment|/* output high water mark */
name|u_int
name|lowat
decl_stmt|;
comment|/* output low water mark */
name|u_int
name|backlog
decl_stmt|;
comment|/* samples of output backlog to gen. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|audio_info
name|audio_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AUDIO_INITINFO
parameter_list|(
name|p
parameter_list|)
define|\
value|(void)memset((void *)(p), 0xff, sizeof(struct audio_info))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|AUDIO_GETINFO
value|_IOR(A, 21, struct audio_info)
end_define

begin_define
define|#
directive|define
name|AUDIO_SETINFO
value|_IOWR(A, 22, struct audio_info)
end_define

begin_define
define|#
directive|define
name|AUDIO_DRAIN
value|_IO(A, 23)
end_define

begin_define
define|#
directive|define
name|AUDIO_FLUSH
value|_IO(A, 24)
end_define

begin_define
define|#
directive|define
name|AUDIO_WSEEK
value|_IOR(A, 25, u_long)
end_define

begin_define
define|#
directive|define
name|AUDIO_RERROR
value|_IOR(A, 26, int)
end_define

begin_define
define|#
directive|define
name|AUDIO_GETMAP
value|_IOR(A, 27, struct mapreg)
end_define

begin_define
define|#
directive|define
name|AUDIO_SETMAP
value|_IOW(A, 28, struct mapreg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AUDIO_GETINFO
value|_IOR('A', 21, struct audio_info)
end_define

begin_define
define|#
directive|define
name|AUDIO_SETINFO
value|_IOWR('A', 22, struct audio_info)
end_define

begin_define
define|#
directive|define
name|AUDIO_DRAIN
value|_IO('A', 23)
end_define

begin_define
define|#
directive|define
name|AUDIO_FLUSH
value|_IO('A', 24)
end_define

begin_define
define|#
directive|define
name|AUDIO_WSEEK
value|_IOR('A', 25, u_long)
end_define

begin_define
define|#
directive|define
name|AUDIO_RERROR
value|_IOR('A', 26, int)
end_define

begin_define
define|#
directive|define
name|AUDIO_GETMAP
value|_IOR('A', 27, struct mapreg)
end_define

begin_define
define|#
directive|define
name|AUDIO_SETMAP
value|_IOW('A', 28, struct mapreg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AUDIO_SPEAKER
value|1
end_define

begin_define
define|#
directive|define
name|AUDIO_HEADPHONE
value|2
end_define

begin_comment
comment|/*  * Low level interface.  */
end_comment

begin_struct
struct|struct
name|mapreg
block|{
name|u_short
name|mr_x
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|mr_r
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|mr_gx
decl_stmt|;
name|u_short
name|mr_gr
decl_stmt|;
name|u_short
name|mr_ger
decl_stmt|;
name|u_short
name|mr_stgr
decl_stmt|;
name|u_short
name|mr_ftgr
decl_stmt|;
name|u_short
name|mr_atgr
decl_stmt|;
name|u_char
name|mr_mmr1
decl_stmt|;
name|u_char
name|mr_mmr2
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_AUDIOIO_H_ */
end_comment

end_unit

