begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Jamil J. Weatherbee  * All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Industrial Computer Source model AIO8-P  * 128 channel MUX capability via daisy chained AT-16P units  * alogio.h, definitions for alog ioctl(), last revised December 9 1997  * See http://www.indcompsrc.com/products/data/html/aio8g-p.html  *     http://www.indcompsrc.com/products/data/html/at16-p.html  *  * Written by: Jamil J. Weatherbee<jamil@freebsd.org>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ALOGIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ALOGIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
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

begin_comment
comment|/* Note: By default A/D conversions are started when a channel is open */
end_comment

begin_comment
comment|/* Halt clocked A/D conversion on an open channel */
end_comment

begin_define
define|#
directive|define
name|AD_STOP
value|_IO('A', 100)
end_define

begin_comment
comment|/* Restart clocked A/D conversion on an open channel */
end_comment

begin_define
define|#
directive|define
name|AD_START
value|_IO('A', 101)
end_define

begin_comment
comment|/* Get the number of entries the fifo for this channel will hold */
end_comment

begin_define
define|#
directive|define
name|AD_FIFOSIZE_GET
value|_IOR('A', 102, int)
end_define

begin_comment
comment|/* Set the minimum number of entries a fifo must contain before it  * notifies a poll() or read() that is waiting for it to fill */
end_comment

begin_define
define|#
directive|define
name|AD_FIFO_TRIGGER_SET
value|_IOW('A', 103, int)
end_define

begin_comment
comment|/* This gets the the fifo trigger setting */
end_comment

begin_define
define|#
directive|define
name|AD_FIFO_TRIGGER_GET
value|_IOR('A', 104, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

