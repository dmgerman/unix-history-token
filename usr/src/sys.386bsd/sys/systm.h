begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)systm.h	7.17 (Berkeley) 5/25/91  *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         2       00158  * --------------------         -----   ----------------------  *  * 11 Dec 92	Williams Jolitz		Fixed and tty handling  * 25 Apr 93	Bruce Evans		Support for intr-0.1  * 16 May 93	Rodney W. Grimes	Added prototype for spinwait  *					Disabled prototype for wakeup, timeout  */
end_comment

begin_decl_stmt
specifier|extern
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
name|char
name|copyright
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system copyright */
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
name|selwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select timeout address */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|curpri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* priority of current process */
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

begin_struct
specifier|extern
struct|struct
name|sysent
block|{
comment|/* system call table */
name|int
name|sy_narg
decl_stmt|;
comment|/* number of arguments */
name|int
function_decl|(
modifier|*
name|sy_call
function_decl|)
parameter_list|()
function_decl|;
comment|/* implementing function */
block|}
name|sysent
index|[]
struct|;
end_struct

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

begin_comment
comment|/* casts to keep lint happy */
end_comment

begin_define
define|#
directive|define
name|insque
parameter_list|(
name|q
parameter_list|,
name|p
parameter_list|)
value|_insque((caddr_t)q,(caddr_t)p)
end_define

begin_define
define|#
directive|define
name|remque
parameter_list|(
name|q
parameter_list|)
value|_remque((caddr_t)q)
end_define

begin_comment
comment|/*  * General function declarations.  */
end_comment

begin_decl_stmt
name|int
name|nullop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|enodev
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|enoioctl
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|enxio
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eopnotsupp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|selscan
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|fd_set
operator|*
name|ibits
operator|,
name|fd_set
operator|*
name|obits
operator|,
name|int
name|nfd
operator|,
name|int
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seltrue
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|which
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|selwakeup
name|__P
argument_list|(
operator|(
name|pid_t
name|pid
operator|,
name|int
name|coll
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|panic
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tablefull
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addlog
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|log
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttyprintf
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bcopy
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ovbcopy
name|__P
argument_list|(
operator|(
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bzero
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buf
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bcmp
name|__P
argument_list|(
operator|(
name|void
operator|*
name|str1
operator|,
name|void
operator|*
name|str2
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|strlen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copystr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|kfaddr
operator|,
name|void
operator|*
name|kdaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyinstr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyoutstr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|kaddr
operator|,
name|void
operator|*
name|udaddr
operator|,
name|u_int
name|len
operator|,
name|u_int
operator|*
name|done
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyin
name|__P
argument_list|(
operator|(
name|void
operator|*
name|udaddr
operator|,
name|void
operator|*
name|kaddr
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|copyout
name|__P
argument_list|(
operator|(
name|void
operator|*
name|kaddr
operator|,
name|void
operator|*
name|udaddr
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fubyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
name|int
name|fuibyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|subyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|byte
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suibyte
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|byte
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuiword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suiword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scanc
name|__P
argument_list|(
operator|(
name|unsigned
name|size
operator|,
name|u_char
operator|*
name|cp
operator|,
name|u_char
operator|*
name|table
operator|,
name|int
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|skpc
name|__P
argument_list|(
operator|(
name|int
name|mask
operator|,
name|int
name|size
operator|,
name|char
operator|*
name|cp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|locc
name|__P
argument_list|(
operator|(
name|int
name|mask
operator|,
name|char
operator|*
name|cp
operator|,
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ffs
name|__P
argument_list|(
operator|(
name|long
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX - a lot were missing.  A lot are still missing.  Some of the above  * are inconsistent with ANSI C.  I fixed strlen.  Others are inconsistent  * with with non-ANSI C due to having unpromoted args.  */
end_comment

begin_define
define|#
directive|define
name|nonint
value|int
end_define

begin_comment
comment|/* really void */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ringb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|speedtab
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|nonint
argument_list|(
argument|*timeout_func_t
argument_list|)
name|__P
argument_list|(
operator|(
name|caddr_t
name|arg
operator|,
name|int
name|ticks
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|nonint
name|DELAY
name|__P
argument_list|(
operator|(
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getc
name|__P
argument_list|(
operator|(
expr|struct
name|ringb
operator|*
name|rbp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|psignal
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|sig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|rb_write
name|__P
argument_list|(
operator|(
expr|struct
name|ringb
operator|*
name|to
operator|,
name|char
operator|*
name|buf
operator|,
name|size_t
name|nfrom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spinwait
name|__P
argument_list|(
operator|(
name|int
name|millisecs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|splhigh
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spltty
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|splx
name|__P
argument_list|(
operator|(
name|int
name|new_pri
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_decl_stmt
name|nonint
name|timeout
name|__P
argument_list|(
operator|(
name|timeout_func_t
name|func
operator|,
name|caddr_t
name|arg
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|trapsignal
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|sig
operator|,
name|unsigned
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttioctl
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|int
name|com
operator|,
name|caddr_t
name|data
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nonint
name|ttsetwater
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nonint
name|ttstart
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nonint
name|ttychars
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttyclose
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nonint
name|ttyinput
name|__P
argument_list|(
operator|(
name|int
name|c
operator|,
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttysleep
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|,
name|caddr_t
name|chan
operator|,
name|int
name|pri
operator|,
name|char
operator|*
name|wmesg
operator|,
name|int
name|timo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttspeedtab
name|__P
argument_list|(
operator|(
name|int
name|speed
operator|,
expr|struct
name|speedtab
operator|*
name|table
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nonint
name|ttwakeup
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
name|tp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_decl_stmt
name|nonint
name|wakeup
name|__P
argument_list|(
operator|(
name|caddr_t
name|chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|nonint
end_undef

begin_comment
comment|/*  * Machine-dependent function declarations.  */
end_comment

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

end_unit

