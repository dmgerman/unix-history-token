begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernel.h	8.3 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KERNEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KERNEL_H_
end_define

begin_comment
comment|/* Global variables for the kernel. */
end_comment

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|domainname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|domainnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|kernelname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|struct
name|timeval
name|mono_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|runtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usec per tick (1000000 / hz) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stathz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profhz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* profiling clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ticks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* once a second sleep address */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tickdelta
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|timedelta
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following macros are used to declare global sets of objects, which  * are collected by the linker into a `struct linker_set' as defined below.  *  * NB: the constants defined below must match those defined in  * ld/ld.h.  Since their calculation requires arithmetic, we  * can't name them symbolically (e.g., 23 is N_SETT | N_EXT).  */
end_comment

begin_define
define|#
directive|define
name|MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|,
name|type
parameter_list|)
define|\
value|asm(".stabs \"_" #set "\", " #type ", 0, 0, _" #sym)
end_define

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 23)
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 25)
end_define

begin_define
define|#
directive|define
name|BSS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 27)
end_define

begin_define
define|#
directive|define
name|ABS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|MAKE_SET(set, sym, 21)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PSEUDO_LKM
end_ifdef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_define
define|#
directive|define
name|PSEUDO_SET
parameter_list|(
name|init
parameter_list|,
name|name
parameter_list|)
define|\
value|extern struct linker_set MODVNOPS; \ 	MOD_MISC(#name); \         int name ## _load(struct lkm_table *lkmtp, int cmd) \ 		{ init(); return 0; } \ 	int name ## _unload(struct lkm_table *lkmtp, int cmd) \ 		{ return EINVAL; } \ 	int \ 	name ## _mod(struct lkm_table *lkmtp, int cmd, int ver) { \ 		DISPATCH(lkmtp, cmd, ver, name ## _load, name ## _unload, \ 			 nosys); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PSEUDO_LKM */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_SET
parameter_list|(
name|sym
parameter_list|,
name|name
parameter_list|)
value|TEXT_SET(pseudo_set, sym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PSEUDO_LKM */
end_comment

begin_struct
struct|struct
name|linker_set
block|{
name|int
name|ls_length
decl_stmt|;
name|caddr_t
name|ls_items
index|[
literal|1
index|]
decl_stmt|;
comment|/* really ls_length of them, trailing NULL */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|linker_set
name|execsw_set
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

