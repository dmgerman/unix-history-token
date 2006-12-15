begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_WATCHDOG_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_WATCHDOG_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|_PATH_WATCHDOG
value|"fido"
end_define

begin_define
define|#
directive|define
name|WDIOCPATPAT
value|_IOW('W', 42, u_int)
end_define

begin_define
define|#
directive|define
name|WD_ACTIVE
value|0x8000000
end_define

begin_comment
comment|/*  	 * Watchdog reset, timeout set to value in WD_INTERVAL field. 	 * The kernel will arm the watchdog and unless the userland 	 * program calls WDIOCPATPAT again before the timer expires 	 * the system will reinitialize. 	 */
end_comment

begin_define
define|#
directive|define
name|WD_PASSIVE
value|0x0400000
end_define

begin_comment
comment|/* 	 * Set the watchdog in passive mode. 	 * The kernel will chose an appropriate timeout duration and 	 * periodically reset the timer provided everything looks all 	 * right to the kernel.  	 */
end_comment

begin_define
define|#
directive|define
name|WD_INTERVAL
value|0x00000ff
end_define

begin_comment
comment|/* 	 * Mask for duration bits. 	 * The watchdog will have a nominal patience of 2^N * nanoseconds. 	 * Example:  N == 30 gives a patience of 2^30 nanoseconds ~= 1 second. 	 * NB: Expect variance in the +/- 10-20% range. 	 */
end_comment

begin_comment
comment|/* Handy macros for humans not used to power of two nanoseconds */
end_comment

begin_define
define|#
directive|define
name|WD_TO_NEVER
value|0
end_define

begin_define
define|#
directive|define
name|WD_TO_1MS
value|20
end_define

begin_define
define|#
directive|define
name|WD_TO_125MS
value|27
end_define

begin_define
define|#
directive|define
name|WD_TO_250MS
value|28
end_define

begin_define
define|#
directive|define
name|WD_TO_500MS
value|29
end_define

begin_define
define|#
directive|define
name|WD_TO_1SEC
value|30
end_define

begin_define
define|#
directive|define
name|WD_TO_2SEC
value|31
end_define

begin_define
define|#
directive|define
name|WD_TO_4SEC
value|32
end_define

begin_define
define|#
directive|define
name|WD_TO_8SEC
value|33
end_define

begin_define
define|#
directive|define
name|WD_TO_16SEC
value|34
end_define

begin_define
define|#
directive|define
name|WD_TO_32SEC
value|35
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|watchdog_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|watchdog_list
argument_list|,
name|watchdog_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_WATCHDOG_H */
end_comment

end_unit

