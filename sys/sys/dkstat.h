begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dkstat.h	8.2 (Berkeley) 1/21/94  * $Id: dkstat.h,v 1.5 1994/10/16 05:03:05 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DKSTAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DKSTAT_H_
value|1
end_define

begin_define
define|#
directive|define
name|CP_USER
value|0
end_define

begin_define
define|#
directive|define
name|CP_NICE
value|1
end_define

begin_define
define|#
directive|define
name|CP_SYS
value|2
end_define

begin_define
define|#
directive|define
name|CP_INTR
value|3
end_define

begin_define
define|#
directive|define
name|CP_IDLE
value|4
end_define

begin_define
define|#
directive|define
name|CPUSTATES
value|5
end_define

begin_define
define|#
directive|define
name|DK_NDRIVE
value|8
end_define

begin_define
define|#
directive|define
name|DK_NAMELEN
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|cp_time
index|[
name|CPUSTATES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|dk_seek
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # seeks */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dk_time
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time busy (in statclock ticks) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dk_wds
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # blocks of 32*16-bit words transferred */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dk_wpms
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* transfer rate in 16-bit words per second */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dk_xfer
index|[
name|DK_NDRIVE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # transfers */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|dk_names
index|[
name|DK_NDRIVE
index|]
index|[
name|DK_NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of drive */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dk_busy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bit field of busy drives */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dk_ndrive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of installed drives */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|tk_cancc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tk_nin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tk_nout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tk_rawcc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DKSTAT_H_ */
end_comment

end_unit

