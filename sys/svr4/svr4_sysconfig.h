begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1995 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SYSCONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SYSCONFIG_H_
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_UNUSED
value|0x01
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_NGROUPS
value|0x02
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_CHILD_MAX
value|0x03
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_OPEN_FILES
value|0x04
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_POSIX_VER
value|0x05
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_PAGESIZE
value|0x06
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_CLK_TCK
value|0x07
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_XOPEN_VER
value|0x08
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_UNUSED_9
value|0x09
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_PROF_TCK
value|0x0a
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_NPROC_CONF
value|0x0b
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_NPROC_ONLN
value|0x0c
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_AIO_LISTIO_MAX
value|0x0e
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_AIO_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_AIO_PRIO_DELTA_MAX
value|0x10
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_DELAYTIMER_MAX
value|0x11
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_MQ_OPEN_MAX
value|0x12
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_MQ_PRIO_MAX
value|0x13
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_RTSIG_MAX
value|0x14
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_SEM_NSEMS_MAX
value|0x15
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_SEM_VALUE_MAX
value|0x16
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_SIGQUEUE_MAX
value|0x17
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_SIGRT_MIN
value|0x18
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_SIGRT_MAX
value|0x19
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_TIMER_MAX
value|0x20
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_PHYS_PAGES
value|0x21
end_define

begin_define
define|#
directive|define
name|SVR4_CONFIG_AVPHYS_PAGES
value|0x22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SYSCONFIG_H_ */
end_comment

end_unit

