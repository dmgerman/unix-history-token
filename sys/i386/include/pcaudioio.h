begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCAUDIOIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCAUDIOIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|audio_prinfo
block|{
name|unsigned
name|sample_rate
decl_stmt|;
comment|/* samples per second */
name|unsigned
name|channels
decl_stmt|;
comment|/* # of channels (interleaved) */
name|unsigned
name|precision
decl_stmt|;
comment|/* sample size in bits */
name|unsigned
name|encoding
decl_stmt|;
comment|/* encoding method used */
name|unsigned
name|gain
decl_stmt|;
comment|/* volume level: 0 - 255 */
name|unsigned
name|port
decl_stmt|;
comment|/* input/output device */
name|unsigned
name|_fill1
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|samples
decl_stmt|;
comment|/* samples played */
name|unsigned
name|eof
decl_stmt|;
comment|/* ?!? */
name|unsigned
name|char
name|pause
decl_stmt|;
comment|/* !=0 pause, ==0 continue */
name|unsigned
name|char
name|error
decl_stmt|;
comment|/* !=0 if overflow/underflow */
name|unsigned
name|char
name|waiting
decl_stmt|;
comment|/* !=0 if others wants access */
name|unsigned
name|char
name|_fill2
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|open
decl_stmt|;
comment|/* is device open */
name|unsigned
name|char
name|active
decl_stmt|;
comment|/* !=0 if sound hardware is active */
block|}
name|audio_prinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|audio_info
block|{
name|audio_prinfo_t
name|play
decl_stmt|;
name|audio_prinfo_t
name|record
decl_stmt|;
name|unsigned
name|monitor_gain
decl_stmt|;
name|unsigned
name|_fill
index|[
literal|4
index|]
decl_stmt|;
block|}
name|audio_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AUDIO_ENCODING_ULAW
value|(1)
end_define

begin_comment
comment|/* u-law encoding */
end_comment

begin_define
define|#
directive|define
name|AUDIO_ENCODING_ALAW
value|(2)
end_define

begin_comment
comment|/* A-law encoding */
end_comment

begin_define
define|#
directive|define
name|AUDIO_ENCODING_RAW
value|(3)
end_define

begin_comment
comment|/* linear encoding */
end_comment

begin_define
define|#
directive|define
name|AUDIO_MIN_GAIN
value|(0)
end_define

begin_comment
comment|/* minimum volume value */
end_comment

begin_define
define|#
directive|define
name|AUDIO_MAX_GAIN
value|(255)
end_define

begin_comment
comment|/* maximum volume value */
end_comment

begin_define
define|#
directive|define
name|AUDIO_INITINFO
parameter_list|(
name|i
parameter_list|)
value|memset((void*)i, 0xff, sizeof(audio_info_t))
end_define

begin_define
define|#
directive|define
name|AUDIO_GETINFO
value|_IOR('A', 1, audio_info_t)
end_define

begin_define
define|#
directive|define
name|AUDIO_SETINFO
value|_IOWR('A', 2, audio_info_t)
end_define

begin_define
define|#
directive|define
name|AUDIO_DRAIN
value|_IO('A', 3)
end_define

begin_define
define|#
directive|define
name|AUDIO_FLUSH
value|_IO('A', 4)
end_define

begin_comment
comment|/* compatibility to /dev/audio */
end_comment

begin_define
define|#
directive|define
name|AUDIO_COMPAT_DRAIN
value|_IO('P', 1)
end_define

begin_define
define|#
directive|define
name|AUDIO_COMPAT_FLUSH
value|_IO('P', 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCAUDIOIO_H_ */
end_comment

end_unit

