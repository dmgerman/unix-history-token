begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)Locore.c	7.4 (Berkeley) 12/16/90  */
end_comment

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"sys/systm.h"
end_include

begin_include
include|#
directive|include
file|"sys/user.h"
end_include

begin_include
include|#
directive|include
file|"sys/vm.h"
end_include

begin_include
include|#
directive|include
file|"sys/ioctl.h"
end_include

begin_include
include|#
directive|include
file|"sys/tty.h"
end_include

begin_include
include|#
directive|include
file|"sys/proc.h"
end_include

begin_include
include|#
directive|include
file|"sys/buf.h"
end_include

begin_include
include|#
directive|include
file|"sys/msgbuf.h"
end_include

begin_include
include|#
directive|include
file|"sys/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"sys/protosw.h"
end_include

begin_include
include|#
directive|include
file|"sys/domain.h"
end_include

begin_include
include|#
directive|include
file|"sys/map.h"
end_include

begin_include
include|#
directive|include
file|"../include/cpu.h"
end_include

begin_include
include|#
directive|include
file|"../include/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"../include/trap.h"
end_include

begin_include
include|#
directive|include
file|"../include/psl.h"
end_include

begin_include
include|#
directive|include
file|"../include/pte.h"
end_include

begin_include
include|#
directive|include
file|"scb.h"
end_include

begin_include
include|#
directive|include
file|"cp.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"../math/fp.h"
end_include

begin_comment
comment|/*  * Pseudo file for lint to show what is used/defined in locore.s.  */
end_comment

begin_decl_stmt
name|struct
name|scb
name|scb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rpb
name|rpb
decl_stmt|;
end_decl_stmt

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
name|masterpaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* p_addr of current process on master cpu */
end_comment

begin_decl_stmt
name|struct
name|user
name|u
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
name|quad
name|catcher
index|[
name|SCB_LASTIV
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
name|doadump
argument_list|()
end_macro

begin_block
block|{
name|dumpsys
argument_list|()
expr_stmt|;
block|}
end_block

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
name|rpb
operator|=
name|rpb
expr_stmt|;
name|scb
operator|=
name|scb
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
comment|/* 	 * Routines called from interrupt vectors. 	 */
name|buserror
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|)
expr_stmt|;
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
name|rawintr
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|INET
name|ipintr
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NS
name|nsintr
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|cnrint
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|cnxint
argument_list|(
literal|0
argument_list|)
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
name|fpemulate
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|trap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|syscall
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
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
if|if
condition|(
name|rmget
argument_list|(
operator|(
expr|struct
name|map
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
return|return;
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

begin_decl_stmt
name|caddr_t
name|Sysbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|VMEMmap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|vmem
decl_stmt|,
name|vmembeg
decl_stmt|,
name|vmemend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|VMEMmap1
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|vmem1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|VBmap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|vbbase
decl_stmt|,
name|vbend
decl_stmt|;
end_decl_stmt

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
name|CMAP1
index|[
literal|1
index|]
decl_stmt|,
name|CMAP2
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|CADDR1
decl_stmt|,
name|CADDR2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|mmap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|vmmap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|msgbufmap
index|[
literal|3
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|msgbuf
name|msgbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|kmempt
index|[
literal|100
index|]
decl_stmt|,
name|ekmempt
index|[
literal|1
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

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_decl_stmt
name|struct
name|pte
name|Nfsiomap
index|[
name|MAXPHYS
operator|/
name|NBPG
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|nfsiobuf
index|[
name|MAXPHYS
operator|+
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|caddr_t
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
name|ovbcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|len
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
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

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
name|longjmp
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
comment|/*NOTREACHED*/
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
if|if
condition|(
name|masterpaddr
condition|)
name|masterpaddr
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|resume
argument_list|(
argument|pcbpf
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|pcbpf
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
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
block|{
name|CMAP1
index|[
literal|0
index|]
operator|=
name|CMAP1
index|[
literal|0
index|]
expr_stmt|;
name|CADDR1
index|[
literal|0
index|]
operator|=
name|CADDR1
index|[
literal|0
index|]
expr_stmt|;
block|}
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
block|{
name|CMAP2
index|[
literal|0
index|]
operator|=
name|CMAP2
index|[
literal|0
index|]
expr_stmt|;
name|CADDR2
index|[
literal|0
index|]
operator|=
name|CADDR2
index|[
literal|0
index|]
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|useracc
argument_list|(
argument|udaddr
argument_list|,
argument|bcnt
argument_list|,
argument|rw
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|udaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|bcnt
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
name|kernacc
argument_list|(
argument|addr
argument_list|,
argument|bcnt
argument_list|,
argument|rw
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|bcnt
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
name|addupc
argument_list|(
argument|pc
argument_list|,
argument|prof
argument_list|,
argument|counts
argument_list|)
end_macro

begin_decl_stmt
name|int
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
name|counts
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

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
name|u_char
modifier|*
name|cp
decl_stmt|,
name|table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Routines expanded by inline.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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
name|fubyte
argument_list|(
name|base
argument_list|)
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

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
name|fuword
argument_list|(
name|base
argument_list|)
operator|)
return|;
block|}
end_block

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
name|subyte
argument_list|(
name|base
argument_list|,
name|i
argument_list|)
operator|)
return|;
block|}
end_block

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
name|suword
argument_list|(
name|base
argument_list|,
name|i
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|setjmp
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
name|bcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|len
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
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|bzero
argument_list|(
argument|base
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|blkclr
argument_list|(
argument|base
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_comment
comment|/*VARARGS1*/
end_comment

begin_macro
name|mtpr
argument_list|(
argument|reg
argument_list|,
argument|v
argument_list|)
end_macro

begin_decl_stmt
name|int
name|reg
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|mfpr
argument_list|(
argument|reg
argument_list|)
end_macro

begin_decl_stmt
name|int
name|reg
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
name|_movow
argument_list|(
argument|dst
argument_list|,
argument|v
argument_list|)
end_macro

begin_decl_stmt
name|u_short
modifier|*
name|dst
decl_stmt|,
name|v
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|_movob
argument_list|(
argument|dst
argument_list|,
argument|v
argument_list|)
end_macro

begin_decl_stmt
name|u_char
modifier|*
name|dst
decl_stmt|,
name|v
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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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

end_unit

