begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)Locore.c	7.1 (Berkeley) 5/8/90  */
end_comment

begin_include
include|#
directive|include
file|"pte.h"
end_include

begin_include
include|#
directive|include
file|"cpu.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"vm.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"msgbuf.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"dkbad.h"
end_include

begin_comment
comment|/*  * Pseudo file for lint to show what is used/defined in locore.s.  */
end_comment

begin_decl_stmt
name|int
name|machineid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mmutype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ectype
decl_stmt|;
end_decl_stmt

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
name|u_int
name|lowram
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|ssir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Usrptsize
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
name|doboot
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
name|struct
name|frame
name|frame
decl_stmt|;
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
name|machineid
operator|=
name|machineid
expr_stmt|;
name|mmutype
operator|=
name|mmutype
expr_stmt|;
name|ectype
operator|=
name|ectype
expr_stmt|;
name|lowram
operator|=
name|lowram
expr_stmt|;
name|ssir
operator|=
name|ssir
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
name|Usrptsize
operator|=
name|Usrptsize
expr_stmt|;
name|main
argument_list|(
literal|0
argument_list|)
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
name|hilint
argument_list|()
expr_stmt|;
if|if
condition|(
name|dmaintr
argument_list|()
condition|)
return|return;
name|intrhand
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|regdump
argument_list|(
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
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
name|nmihand
argument_list|(
name|frame
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
name|frame
argument_list|)
expr_stmt|;
name|syscall
argument_list|(
literal|0
argument_list|,
name|frame
argument_list|)
expr_stmt|;
name|straytrap
argument_list|(
literal|0
argument_list|)
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
comment|/*	dumpflag = 0; dumpflag = dumpflag; */
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
name|int
name|cold
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Sysmap
index|[
name|SYSPTSIZE
index|]
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
name|int
name|Usrptsize
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
name|char
name|mbutl
index|[
name|NMBCLUSTERS
index|]
index|[
name|MCLBYTES
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
name|kmempt
index|[
literal|200
index|]
decl_stmt|,
name|ekmempt
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|IObase
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
name|char
name|usrio
index|[
name|USRIOSIZE
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ste
name|Sysseg
index|[
name|NPTEPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
name|Grfmap
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|grfregs
index|[
literal|1024
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

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

begin_macro
name|TBIA
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|TBIS
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|TBIAS
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|TBIAU
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|ICIA
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|DCIA
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|DCIS
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|DCIU
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|PCIA
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|ecacheon
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|ecacheoff
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|getsfc
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
name|getdfc
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
name|loadustp
argument_list|(
argument|ustp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ustp
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|flushustp
argument_list|(
argument|ustp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ustp
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|ploadw
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|addr
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

begin_macro
name|spl0
argument_list|()
end_macro

begin_block
block|{ }
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
name|spl1
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
name|spl2
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
name|spl3
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

begin_macro
name|bcmp
argument_list|(
argument|str1
argument_list|,
argument|str2
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|str1
decl_stmt|,
name|str2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|count
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
name|caddr_t
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
name|qsetjmp
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

begin_ifdef
ifdef|#
directive|ifdef
name|FPCOPROC
end_ifdef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|m68881_save
argument_list|(
argument|fpframep
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|fpframe
modifier|*
name|fpframep
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|m68881_restore
argument_list|(
argument|fpframep
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|fpframe
modifier|*
name|fpframep
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|doboot
argument_list|()
end_macro

begin_block
block|{
comment|/*NOTREACHED*/
block|}
end_block

end_unit

