begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) Dirk Husemann, Computer Science Department IV,  * 		 University of Erlangen-Nuremberg, Germany, 1990, 1991, 1992  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dll.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_DLL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_DLL_H_
end_define

begin_comment
comment|/*  * We define the additional PRC_* codes in here  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PRC_IFUP
end_ifndef

begin_define
define|#
directive|define
name|PRC_IFUP
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRC_CONNECT_INDICATION
value|8
end_define

begin_define
define|#
directive|define
name|PRC_CONNECT_REQUEST
value|9
end_define

begin_define
define|#
directive|define
name|PRC_DISCONNECT_REQUEST
value|10
end_define

begin_define
define|#
directive|define
name|PRC_DISCONNECT_INDICATION
value|11
end_define

begin_define
define|#
directive|define
name|PRC_RESET_REQUEST
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Data link layer configuration --- basically a copy of the relevant parts  * of x25config, implemented to become a little bit more network  * layer independent. (Probably only used for casting et al.)  */
end_comment

begin_struct
struct|struct
name|dllconfig
block|{
name|u_short
name|dllcfg_unused0
range|:
literal|4
decl_stmt|,
name|dllcfg_unused1
range|:
literal|4
decl_stmt|,
name|dllcfg_trace
range|:
literal|1
decl_stmt|,
comment|/* link level tracing flag */
name|dllcfg_window
range|:
literal|7
decl_stmt|;
comment|/* link level window size */
name|u_short
name|dllcfg_xchxid
range|:
literal|1
decl_stmt|,
comment|/* exchange XID (not yet) */
name|dllcfg_unused2
range|:
literal|7
decl_stmt|;
comment|/* here be dragons */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dll_ctlinfo
block|{
union|union
block|{
struct|struct
block|{
name|struct
name|dllconfig
modifier|*
name|dctli_up_cfg
decl_stmt|;
name|u_char
name|dctli_up_lsap
decl_stmt|;
block|}
name|CTLI_UP
struct|;
struct|struct
block|{
name|caddr_t
name|dctli_down_pcb
decl_stmt|;
name|struct
name|rtentry
modifier|*
name|dctli_down_rt
decl_stmt|;
name|struct
name|dllconfig
modifier|*
name|dctli_down_llconf
decl_stmt|;
block|}
name|CTLI_DOWN
struct|;
block|}
name|CTLIun
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dlcti_cfg
value|CTLIun.CTLI_UP.dctli_up_cfg
end_define

begin_define
define|#
directive|define
name|dlcti_lsap
value|CTLIun.CTLI_UP.dctli_up_lsap
end_define

begin_define
define|#
directive|define
name|dlcti_pcb
value|CTLIun.CTLI_DOWN.dctli_down_pcb
end_define

begin_define
define|#
directive|define
name|dlcti_rt
value|CTLIun.CTLI_DOWN.dctli_down_rt
end_define

begin_define
define|#
directive|define
name|dlcti_conf
value|CTLIun.CTLI_DOWN.dctli_down_llconf
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

