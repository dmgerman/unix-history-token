begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: awictl.h,v 1.1 2000/03/23 06:04:24 onoe Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Atsushi Onoe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IC_AWICTL_H
end_ifndef

begin_define
define|#
directive|define
name|_IC_AWICTL_H
end_define

begin_define
define|#
directive|define
name|AWICTL_BUFSIZE
value|32
end_define

begin_define
define|#
directive|define
name|AWICTL_REGION
value|1
end_define

begin_comment
comment|/* u_int8_t: region code */
end_comment

begin_define
define|#
directive|define
name|AWICTL_CHANSET
value|2
end_define

begin_comment
comment|/* u_int8_t[3]: cur, min, max */
end_comment

begin_define
define|#
directive|define
name|AWICTL_RAWBPF
value|3
end_define

begin_comment
comment|/* u_int8_t: pass raw 802.11 header to bpf */
end_comment

begin_define
define|#
directive|define
name|AWICTL_DESSID
value|4
end_define

begin_comment
comment|/* u_int8_t[IEEE80211_NWID_LEN]: desired ESSID*/
end_comment

begin_define
define|#
directive|define
name|AWICTL_CESSID
value|5
end_define

begin_comment
comment|/* u_int8_t[IEEE80211_NWID_LEN]: current ESSID*/
end_comment

begin_define
define|#
directive|define
name|AWICTL_MODE
value|6
end_define

begin_comment
comment|/* u_int8_t: mode */
end_comment

begin_define
define|#
directive|define
name|AWICTL_MODE_INFRA
value|0
end_define

begin_comment
comment|/* infrastructure mode */
end_comment

begin_define
define|#
directive|define
name|AWICTL_MODE_ADHOC
value|1
end_define

begin_comment
comment|/* adhoc mode */
end_comment

begin_define
define|#
directive|define
name|AWICTL_MODE_NOBSSID
value|2
end_define

begin_comment
comment|/* adhoc without bssid mode */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCSDRVSPEC
end_ifndef

begin_define
define|#
directive|define
name|SIOCSDRVSPEC
value|_IOW('i', 123, struct ifdrv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGDRVSPEC
end_ifndef

begin_define
define|#
directive|define
name|SIOCGDRVSPEC
value|_IOWR('i', 122, struct ifdrv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_struct
struct|struct
name|ifdrv
block|{
name|char
name|ifd_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|unsigned
name|long
name|ifd_cmd
decl_stmt|;
name|size_t
name|ifd_len
decl_stmt|;
name|void
modifier|*
name|ifd_data
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IC_AWICTL_H */
end_comment

end_unit

