begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)systm.h	7.17 (Berkeley) %G%  */
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
name|int
name|strlen
name|__P
argument_list|(
operator|(
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

end_unit

