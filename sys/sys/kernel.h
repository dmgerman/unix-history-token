begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)kernel.h	7.4 (Berkeley) 2/15/91  *	$Id: kernel.h,v 1.8 1993/12/20 19:31:42 wollman Exp $  */
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
value|1
end_define

begin_comment
comment|/* Global variables for the kernel. */
end_comment

begin_function_decl
name|long
name|rmalloc
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* 1.2 */
end_comment

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
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|phz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alternate clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usec per clock tick */
end_comment

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
name|fixpt_t
name|averunnable
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_43 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_decl_stmt
specifier|extern
name|u_long
name|s_textsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|kcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|s_lowpc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|panicstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* panic message */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system version */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|ostype
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operating system type */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|osrelease
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operating system release */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|osbuild
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operating system build number */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|osconfig
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operating system configuration name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nblkdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in bdevsw */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in cdevsw */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nswdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of swap devices */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nswap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of swap space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max memory per process */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|physmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical memory */
end_comment

begin_decl_stmt
specifier|extern
name|dev_t
name|dumpdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump device */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dumplo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset into dumpdev */
end_comment

begin_decl_stmt
specifier|extern
name|dev_t
name|rootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root device */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|rootvp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode equivalent to above */
end_comment

begin_decl_stmt
specifier|extern
name|dev_t
name|swapdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swapping device */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|swapdev_vp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode equivalent to above */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|boothowto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reboot flags, from console subsystem */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KADB
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bootesym
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of symbol info from boot */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|u_char
name|curpri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* priority of current process */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_KERNEL_H_ */
end_comment

end_unit

