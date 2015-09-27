begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * This is a skeleton for folks who wish to build a loadable module  * containing an alternative entropy-processing algorithm for random(4).  *  * The functions below should be completed with the appropriate code,  * and the nearby yarrow.c and fortuna.c may be consulted for examples  * of working code.  *  * The author is willing to provide reasonable help to those wishing to  * write such a module for themselves. Please use the markm@ FreeBSD  * email address, and ensure that you are developing this on a suitably  * supported branch (This is currently 11-CURRENT, and will be no  * older than 11-STABLE in the future).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_OTHER_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_OTHER_H_INCLUDED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|mtx
name|mtx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RANDOM_RESEED_INIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_init(&other_mtx, "reseed mutex", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_DEINIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_destroy(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_ASSERT_LOCK_OWNED
parameter_list|(
name|x
parameter_list|)
value|mtx_assert(&other_mtx, MA_OWNED)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RANDOM_RESEED_INIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_init(&other_mtx, mtx_plain)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_DEINIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_destroy(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(&other_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_RESEED_ASSERT_LOCK_OWNED
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_OTHER_H_INCLUDED */
end_comment

end_unit

