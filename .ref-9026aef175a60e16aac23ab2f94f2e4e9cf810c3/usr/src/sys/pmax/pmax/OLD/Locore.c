begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)Locore.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_comment
comment|/*  * Pseudo file for lint to show what is used/defined in locore.s.  */
end_comment

begin_decl_stmt
name|int
name|dumpflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intstack
index|[
literal|3
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|icode
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|szicode
init|=
sizeof|sizeof
argument_list|(
name|icode
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|MachUTLBMiss
index|[
literal|10
index|]
decl_stmt|,
name|MachUTLBMissEnd
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|MachException
index|[
literal|10
index|]
decl_stmt|,
name|MachException
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variables declared for savecore, or  * implicitly, such as by config or the loader.  */
end_comment

begin_decl_stmt
name|char
name|version
index|[]
init|=
literal|"4.3 BSD UNIX ...."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|etext
decl_stmt|;
end_decl_stmt

begin_macro
name|lowinit
argument_list|()
end_macro

begin_block
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GPROF
argument_list|)
name|caddr_t
name|cp
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|int
name|dumpmag
decl_stmt|;
specifier|extern
name|int
name|rthashsize
decl_stmt|;
specifier|extern
name|int
name|arptab_size
decl_stmt|;
specifier|extern
name|int
name|dk_ndrive
decl_stmt|;
specifier|extern
name|struct
name|domain
name|unixdomain
decl_stmt|;
ifdef|#
directive|ifdef
name|INET
specifier|extern
name|struct
name|domain
name|inetdomain
decl_stmt|;
endif|#
directive|endif
include|#
directive|include
file|"imp.h"
if|#
directive|if
name|NIMP
operator|>
literal|0
specifier|extern
name|struct
name|domain
name|impdomain
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NS
specifier|extern
name|struct
name|domain
name|nsdomain
decl_stmt|;
endif|#
directive|endif
comment|/* cpp messes these up for lint so put them here */
name|unixdomain
operator|.
name|dom_next
operator|=
name|domains
expr_stmt|;
name|domains
operator|=
operator|&
name|unixdomain
expr_stmt|;
ifdef|#
directive|ifdef
name|INET
name|inetdomain
operator|.
name|dom_next
operator|=
name|domains
expr_stmt|;
name|domains
operator|=
operator|&
name|inetdomain
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NIMP
operator|>
literal|0
name|impdomain
operator|.
name|dom_next
operator|=
name|domains
expr_stmt|;
name|domains
operator|=
operator|&
name|impdomain
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NS
name|nsdomain
operator|.
name|dom_next
operator|=
name|domains
expr_stmt|;
name|domains
operator|=
operator|&
name|nsdomain
expr_stmt|;
endif|#
directive|endif
name|dumpmag
operator|=
literal|0
expr_stmt|;
comment|/* used only by savecore */
name|rthashsize
operator|=
name|rthashsize
expr_stmt|;
comment|/* used by netstat, etc. */
name|arptab_size
operator|=
name|arptab_size
expr_stmt|;
comment|/* used by arp command */
name|dk_ndrive
operator|=
name|dk_ndrive
expr_stmt|;
comment|/* used by vmstat, iostat, etc. */
comment|/* 	 * Pseudo-uses of globals. 	 */
name|lowinit
argument_list|()
expr_stmt|;
name|intstack
index|[
literal|0
index|]
operator|=
name|intstack
index|[
literal|1
index|]
expr_stmt|;
name|maxmem
operator|=
name|physmem
operator|=
name|freemem
operator|=
literal|0
expr_stmt|;
name|u
operator|=
name|u
expr_stmt|;
name|fixctlrmask
argument_list|()
expr_stmt|;
name|main
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|Xustray
argument_list|()
expr_stmt|;
comment|/* 	 * Routines called from interrupt vectors. 	 */
name|panic
argument_list|(
literal|"Machine check"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Write timeout"
argument_list|)
expr_stmt|;
name|consdin
argument_list|()
expr_stmt|;
name|consdout
argument_list|()
expr_stmt|;
name|hardclock
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|softclock
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|trap
argument_list|(
operator|(
name|unsigned
operator|)
literal|0
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|)
expr_stmt|;
name|memerr
argument_list|()
expr_stmt|;
comment|/* 	 * Miscellaneous routines called from configurable 	 * drivers. 	 */
name|disksort
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
literal|0
argument_list|,
operator|(
expr|struct
name|buf
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|uwritec
argument_list|(
operator|(
expr|struct
name|uio
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|todr
argument_list|()
expr_stmt|;
if|if
condition|(
name|vmemall
argument_list|(
operator|(
expr|struct
name|pte
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
return|return;
comment|/* use value */
name|boothowto
operator|=
literal|0
expr_stmt|;
name|dumpflag
operator|=
literal|0
expr_stmt|;
name|dumpflag
operator|=
name|dumpflag
expr_stmt|;
ifdef|#
directive|ifdef
name|KADB
name|bootesym
operator|=
literal|0
expr_stmt|;
name|bootesym
operator|=
name|bootesym
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GPROF
argument_list|)
name|cp
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|etext
expr_stmt|;
name|cp
operator|=
name|cp
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_decl_stmt
name|struct
name|pte
name|Sysmap
index|[
literal|6
operator|*
name|NPTEPG
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KADB
end_ifdef

begin_decl_stmt
name|char
name|Sysbase
index|[
literal|6
operator|*
name|NPTEPG
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|pte
name|Usrptmap
index|[
name|USRPTSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|usrpt
index|[
name|USRPTSIZE
operator|*
name|NPTEPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Usriomap
index|[
name|USRIOSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|usrio
index|[
name|USRIOSIZE
operator|*
name|NPTEPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Forkmap
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|forkutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Xswapmap
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|xswaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Xswap2map
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|xswap2utl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Swapmap
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|swaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Pushmap
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|pushutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Vfmap
index|[
name|UPAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
name|vfutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Mbmap
index|[
name|NMBCLUSTERS
operator|/
name|CLSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
name|mbutl
index|[
name|NMBCLUSTERS
operator|*
name|CLBYTES
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|mbuf
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|kmempt
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|kmembase
index|[
literal|100
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|badaddr
argument_list|(
argument|addr
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|copyinstr
argument_list|(
argument|udaddr
argument_list|,
argument|kaddr
argument_list|,
argument|maxlength
argument_list|,
argument|lencopied
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|udaddr
decl_stmt|,
name|kaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|maxlength
decl_stmt|,
modifier|*
name|lencopied
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|kaddr
operator|=
operator|*
name|udaddr
expr_stmt|;
operator|*
name|lencopied
operator|=
name|maxlength
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|copyoutstr
argument_list|(
argument|kaddr
argument_list|,
argument|udaddr
argument_list|,
argument|maxlength
argument_list|,
argument|lencopied
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|kaddr
decl_stmt|,
name|udaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|maxlength
decl_stmt|,
modifier|*
name|lencopied
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|udaddr
operator|=
operator|*
name|kaddr
expr_stmt|;
operator|*
name|lencopied
operator|=
name|maxlength
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|copystr
argument_list|(
argument|kfaddr
argument_list|,
argument|kdaddr
argument_list|,
argument|maxlength
argument_list|,
argument|lencopied
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|kfaddr
decl_stmt|,
name|kdaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|maxlength
decl_stmt|,
modifier|*
name|lencopied
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|kdaddr
operator|=
operator|*
name|kfaddr
expr_stmt|;
operator|*
name|lencopied
operator|=
name|maxlength
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|copyin
argument_list|(
argument|udaddr
argument_list|,
argument|kaddr
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|udaddr
decl_stmt|,
name|kaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|copyout
argument_list|(
argument|kaddr
argument_list|,
argument|udaddr
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|kaddr
decl_stmt|,
name|udaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|bzero
argument_list|(
argument|to
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|bcmp
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|from
decl_stmt|,
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|bcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|from
decl_stmt|,
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|CopyToBuffer
argument_list|(
argument|src
argument_list|,
argument|dst
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|u_short
modifier|*
name|src
decl_stmt|,
modifier|*
name|dst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|dst
operator|=
operator|*
name|src
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|CopyFromBuffer
argument_list|(
argument|src
argument_list|,
argument|dst
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|u_short
modifier|*
name|src
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|dst
operator|=
operator|*
name|src
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|savectx
argument_list|(
argument|lp
argument_list|)
end_macro

begin_decl_stmt
name|label_t
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|setrq
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|remrq
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|swtch
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|whichqs
condition|)
name|whichqs
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|fubyte
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|fuibyte
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|subyte
argument_list|(
argument|base
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|suibyte
argument_list|(
argument|base
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|fuword
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|fuiword
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|suword
argument_list|(
argument|base
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|suiword
argument_list|(
argument|base
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|copyseg
argument_list|(
argument|udaddr
argument_list|,
argument|pf
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|udaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|pf
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|clearseg
argument_list|(
argument|pf
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|pf
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|addupc
argument_list|(
argument|pc
argument_list|,
argument|prof
argument_list|,
argument|ticks
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uprof
modifier|*
name|prof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ticks
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_function
name|void
name|MachEnableIntr
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|setsoftnet
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|clearsoftnet
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|setsoftclock
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|clearsoftclock
parameter_list|()
block|{ }
end_function

begin_macro
name|spl0
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|splsoftclock
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|splnet
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|splimp
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* XXX */
end_comment

begin_macro
name|splbio
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|spltty
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|splclock
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|splhigh
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|splx
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|scanc
argument_list|(
argument|size
argument_list|,
argument|cp
argument_list|,
argument|table
argument_list|,
argument|mask
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
name|table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|skpc
argument_list|(
argument|mask
argument_list|,
argument|size
argument_list|,
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|locc
argument_list|(
argument|mask
argument_list|,
argument|size
argument_list|,
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|_insque
argument_list|(
argument|p
argument_list|,
argument|q
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|p
decl_stmt|,
name|q
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|_remque
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|ffs
argument_list|(
argument|v
argument_list|)
end_macro

begin_decl_stmt
name|long
name|v
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|strlen
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_macro
name|imin
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_block

begin_macro
name|imax
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_block

begin_function
name|unsigned
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|u_int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
name|unsigned
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|u_int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|u_short
name|ntohs
parameter_list|(
name|s
parameter_list|)
name|u_short
name|s
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|u_short
operator|)
name|s
operator|)
return|;
block|}
end_function

begin_function
name|u_short
name|htons
parameter_list|(
name|s
parameter_list|)
name|u_short
name|s
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|u_short
operator|)
name|s
operator|)
return|;
block|}
end_function

begin_function
name|u_long
name|ntohl
parameter_list|(
name|l
parameter_list|)
name|u_long
name|l
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|u_long
operator|)
name|l
operator|)
return|;
block|}
end_function

begin_function
name|u_long
name|htonl
parameter_list|(
name|l
parameter_list|)
name|u_long
name|l
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|u_long
operator|)
name|l
operator|)
return|;
block|}
end_function

begin_function
name|void
name|MachKernGenException
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|MachUserGenException
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|MachTLBModException
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|MachTLBMissException
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|MachEmptyWriteBuffer
parameter_list|()
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachTLBWriteIndexed
parameter_list|(
name|index
parameter_list|,
name|highEntry
parameter_list|,
name|lowEntry
parameter_list|)
name|int
name|index
decl_stmt|,
name|highEntry
decl_stmt|,
name|lowEntry
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachSetPID
parameter_list|(
name|pid
parameter_list|)
name|int
name|pid
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|newptes
parameter_list|(
name|pte
parameter_list|,
name|v
parameter_list|,
name|size
parameter_list|)
name|struct
name|pte
modifier|*
name|pte
decl_stmt|;
name|u_int
name|v
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{ }
end_function

begin_function
name|void
name|MachTLBFlush
parameter_list|()
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachTLBFlushPID
parameter_list|(
name|pid
parameter_list|)
name|int
name|pid
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachTLBFlushAddr
parameter_list|(
name|virt
parameter_list|)
name|caddr_t
name|virt
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachSwitchFPState
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
name|struct
name|proc
modifier|*
name|from
decl_stmt|;
name|struct
name|user
modifier|*
name|to
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachGetCurFPState
parameter_list|(
name|p
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachFPInterrupt
parameter_list|(
name|p
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachFPInterrupt
parameter_list|(
name|statusReg
parameter_list|,
name|causeReg
parameter_list|,
name|pc
parameter_list|)
name|unsigned
name|statusReg
decl_stmt|,
name|causeReg
decl_stmt|,
name|pc
decl_stmt|;
block|{ }
end_function

begin_function
name|void
name|MachConfigCache
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|MachFlushCache
parameter_list|()
block|{ }
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|MachFlushICache
parameter_list|(
name|vaddr
parameter_list|,
name|len
parameter_list|)
name|caddr_t
name|vaddr
decl_stmt|,
name|int
name|len
decl_stmt|;
block|{ }
end_function

end_unit

