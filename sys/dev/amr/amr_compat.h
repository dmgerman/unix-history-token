begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Backwards compatibility support.  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500003
end_if

begin_comment
comment|/* old buf style */
end_comment

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_define
define|#
directive|define
name|FREEBSD_4
end_define

begin_define
define|#
directive|define
name|bio
value|buf
end_define

begin_define
define|#
directive|define
name|bioq_init
parameter_list|(
name|x
parameter_list|)
value|bufq_init(x)
end_define

begin_define
define|#
directive|define
name|bioq_insert_tail
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|bufq_insert_tail(x, y)
end_define

begin_define
define|#
directive|define
name|bioq_remove
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|bufq_remove(x, y)
end_define

begin_define
define|#
directive|define
name|bioq_first
parameter_list|(
name|x
parameter_list|)
value|bufq_first(x)
end_define

begin_define
define|#
directive|define
name|bio_queue_head
value|buf_queue_head
end_define

begin_define
define|#
directive|define
name|bio_bcount
value|b_bcount
end_define

begin_define
define|#
directive|define
name|bio_blkno
value|b_blkno
end_define

begin_define
define|#
directive|define
name|bio_caller1
value|b_caller1
end_define

begin_define
define|#
directive|define
name|bio_data
value|b_data
end_define

begin_define
define|#
directive|define
name|bio_dev
value|b_dev
end_define

begin_define
define|#
directive|define
name|bio_driver1
value|b_driver1
end_define

begin_define
define|#
directive|define
name|bio_driver2
value|b_driver2
end_define

begin_define
define|#
directive|define
name|bio_error
value|b_error
end_define

begin_define
define|#
directive|define
name|bio_flags
value|b_flags
end_define

begin_define
define|#
directive|define
name|bio_pblkno
value|b_pblkno
end_define

begin_define
define|#
directive|define
name|bio_resid
value|b_resid
end_define

begin_define
define|#
directive|define
name|BIO_ERROR
value|B_ERROR
end_define

begin_define
define|#
directive|define
name|devstat_end_transaction_bio
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|devstat_end_transaction_buf(x, y)
end_define

begin_define
define|#
directive|define
name|BIO_IS_READ
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags& B_READ)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_define
define|#
directive|define
name|BIO_IS_READ
parameter_list|(
name|x
parameter_list|)
value|((x)->bio_cmd == BIO_READ)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

