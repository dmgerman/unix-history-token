begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MIB_H_
end_define

begin_function_decl
name|void
name|linux_osd_jail_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_osd_jail_deregister
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_get_osname
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_get_osrelease
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_get_oss_version
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_kernver
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LINUX_KVERSION
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_KPATCHLEVEL
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_KSUBLEVEL
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_KERNVER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(((a)<< 16) + ((b)<< 8) + (c))
end_define

begin_define
define|#
directive|define
name|LINUX_VERSION_CODE
value|LINUX_KERNVER(LINUX_KVERSION,		\ 				    LINUX_KPATCHLEVEL, LINUX_KSUBLEVEL)
end_define

begin_define
define|#
directive|define
name|LINUX_KERNVERSTR
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|LINUX_XKERNVERSTR
parameter_list|(
name|x
parameter_list|)
value|LINUX_KERNVERSTR(x)
end_define

begin_define
define|#
directive|define
name|LINUX_VERSION_STR
value|LINUX_XKERNVERSTR(LINUX_KVERSION.LINUX_KPATCHLEVEL.LINUX_KSUBLEVEL)
end_define

begin_define
define|#
directive|define
name|LINUX_KERNVER_2004000
value|LINUX_KERNVER(2,4,0)
end_define

begin_define
define|#
directive|define
name|LINUX_KERNVER_2006000
value|LINUX_KERNVER(2,6,0)
end_define

begin_define
define|#
directive|define
name|linux_use26
parameter_list|(
name|t
parameter_list|)
value|(linux_kernver(t)>= LINUX_KERNVER_2006000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MIB_H_ */
end_comment

end_unit

