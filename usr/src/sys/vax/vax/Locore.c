begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Locore.c	4.17	81/12/02	*/
end_comment

begin_include
include|#
directive|include
file|"dz.h"
end_include

begin_include
include|#
directive|include
file|"mba.h"
end_include

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/pte.h"
end_include

begin_include
include|#
directive|include
file|"../h/vm.h"
end_include

begin_include
include|#
directive|include
file|"../h/tty.h"
end_include

begin_include
include|#
directive|include
file|"../h/proc.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/ubavar.h"
end_include

begin_include
include|#
directive|include
file|"../h/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"../h/nexus.h"
end_include

begin_include
include|#
directive|include
file|"../h/msgbuf.h"
end_include

begin_include
include|#
directive|include
file|"../h/mbuf.h"
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

begin_function_decl
name|int
function_decl|(
modifier|*
name|UNIvec
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|rpb
name|rpb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|intstack
index|[
literal|3
operator|*
literal|128
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
name|Xmba3int
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|Xmba2int
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|Xmba1int
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|Xmba0int
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|lowinit
argument_list|()
end_macro

begin_block
block|{
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
call|(
modifier|*
name|UNIvec
index|[
literal|0
index|]
call|)
argument_list|()
expr_stmt|;
name|ubaerror
argument_list|(
literal|0
argument_list|,
operator|(
expr|struct
name|uba_hd
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|uba_regs
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
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
name|consdin
argument_list|()
expr_stmt|;
name|consdout
argument_list|()
expr_stmt|;
if|#
directive|if
name|NDZ
operator|>
literal|0
name|dzdma
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NMBA
operator|>
literal|0
name|mbintr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|ipintr
argument_list|()
expr_stmt|;
name|rawintr
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
name|machinecheck
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|)
expr_stmt|;
name|memerr
argument_list|()
expr_stmt|;
name|boothowto
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
name|consdin
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|consdout
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_if
if|#
directive|if
name|NDZ
operator|>
literal|0
end_if

begin_macro
name|dzdma
argument_list|()
end_macro

begin_block
block|{
name|dzxint
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|catcher
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cold
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|Xustray
argument_list|()
end_macro

begin_block
block|{ }
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

begin_decl_stmt
name|int
name|umbabeg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Nexmap
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nexus
name|nexus
index|[
name|MAXNNEXUS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|UMEMmap
index|[
literal|4
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|umem
index|[
literal|4
index|]
index|[
literal|16
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|umbaend
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|CADDR1
index|[
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|CMAP2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|CADDR2
index|[
name|NBPG
index|]
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

begin_decl_stmt
name|struct
name|pte
name|msgbufmap
index|[
name|CLSIZE
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
name|camap
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cabase
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|unneeded
end_ifdef

begin_decl_stmt
name|char
name|caspace
index|[
literal|32
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
name|int
name|calimit
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
name|addupc
argument_list|(
argument|pc
argument_list|,
argument|prof
argument_list|,
argument|n
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

begin_block
block|{ }
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
name|unsigned
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
name|unsigned
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
name|setjmp
argument_list|(
argument|lp
argument_list|)
end_macro

begin_decl_stmt
name|label_t
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
name|longjmp
argument_list|(
argument|lp
argument_list|)
end_macro

begin_decl_stmt
name|label_t
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
block|{
name|CMAP1
operator|=
name|CMAP1
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
operator|=
name|CMAP2
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
comment|/*VARARGS1*/
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|mtpr
argument_list|(
argument|reg
argument_list|,
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|int
name|reg
decl_stmt|,
name|value
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

begin_macro
name|spl0
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|spl4
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
name|spl5
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
name|spl6
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
name|spl7
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
argument|count
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
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
empty_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|ffs
argument_list|(
argument|i
argument_list|)
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

end_unit

