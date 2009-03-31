begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  * @(#) $Header: /tcpdump/master/libpcap/pcap.h,v 1.59 2006/10/04 18:09:22 guy Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lib_pcap_h
end_ifndef

begin_define
define|#
directive|define
name|lib_pcap_h
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pcap-stdinc.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* u_int, u_char etc. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UN*X */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32/MSDOS/UN*X */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCAP_DONT_INCLUDE_PCAP_BPF_H
end_ifndef

begin_include
include|#
directive|include
file|<pcap-bpf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|PCAP_VERSION_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|PCAP_VERSION_MINOR
value|4
end_define

begin_define
define|#
directive|define
name|PCAP_ERRBUF_SIZE
value|256
end_define

begin_comment
comment|/*  * For backwards compatibility.  *  * Note to OS vendors: do NOT get rid of this file!  Many applications  * expect to be able to include<pcap.h>, and at least some of them  * go through contortions in their configure scripts to try to detect  * OSes that have "helpfully" moved pcap.h to<pcap/pcap.h> without  * leaving behind a<pcap.h> file.  */
end_comment

begin_include
include|#
directive|include
file|<pcap/pcap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

