begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1982, 1986 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)genassym.c	7.11 (Berkeley) 5/9/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_define
define|#
directive|define
name|VAX780
value|1
end_define

begin_define
define|#
directive|define
name|VAX750
value|1
end_define

begin_define
define|#
directive|define
name|VAX730
value|1
end_define

begin_define
define|#
directive|define
name|VAX630
value|1
end_define

begin_define
define|#
directive|define
name|VAX650
value|1
end_define

begin_include
include|#
directive|include
file|"../include/pte.h"
end_include

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"sys/buf.h"
end_include

begin_include
include|#
directive|include
file|"sys/vmmeter.h"
end_include

begin_include
include|#
directive|include
file|"sys/vmparam.h"
end_include

begin_include
include|#
directive|include
file|"sys/user.h"
end_include

begin_include
include|#
directive|include
file|"sys/cmap.h"
end_include

begin_include
include|#
directive|include
file|"sys/map.h"
end_include

begin_include
include|#
directive|include
file|"../uba/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"../uba/ubavar.h"
end_include

begin_include
include|#
directive|include
file|"sys/proc.h"
end_include

begin_include
include|#
directive|include
file|"sys/text.h"
end_include

begin_include
include|#
directive|include
file|"rpb.h"
end_include

begin_include
include|#
directive|include
file|"sys/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"sys/msgbuf.h"
end_include

begin_decl_stmt
name|struct
name|uba_hd
name|uba_hd
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|struct
name|proc
modifier|*
name|p
init|=
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|struct
name|uba_regs
modifier|*
name|uba
init|=
operator|(
expr|struct
name|uba_regs
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|struct
name|uba_hd
modifier|*
name|uh
init|=
operator|(
expr|struct
name|uba_hd
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|struct
name|vmmeter
modifier|*
name|vm
init|=
operator|(
expr|struct
name|vmmeter
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|struct
name|user
modifier|*
name|up
init|=
operator|(
expr|struct
name|user
operator|*
operator|)
literal|0
decl_stmt|;
specifier|register
name|struct
name|rusage
modifier|*
name|rup
init|=
operator|(
expr|struct
name|rusage
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|rpb
modifier|*
name|rp
init|=
operator|(
expr|struct
name|rpb
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|text
modifier|*
name|tp
init|=
operator|(
expr|struct
name|text
operator|*
operator|)
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"#define\tP_LINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_link
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_RLINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_rlink
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_XLINK %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_xlink
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_ADDR %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_addr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_PRI %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_pri
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_STAT %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_stat
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_WCHAN %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_wchan
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_TSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_tsize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_DSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_dsize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_SSIZE %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_ssize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_P0BR %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_p0br
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_SZPT %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_szpt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_TEXTP %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_textp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tP_FLAG %d\n"
argument_list|,
operator|&
name|p
operator|->
name|p_flag
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSSLEEP %d\n"
argument_list|,
name|SSLEEP
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSRUN %d\n"
argument_list|,
name|SRUN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUBA_BRRVR %d\n"
argument_list|,
name|uba
operator|->
name|uba_brrvr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUH_UBA %d\n"
argument_list|,
operator|&
name|uh
operator|->
name|uh_uba
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUH_VEC %d\n"
argument_list|,
operator|&
name|uh
operator|->
name|uh_vec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUH_SIZE %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|uba_hd
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tRP_FLAG %d\n"
argument_list|,
operator|&
name|rp
operator|->
name|rp_flag
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tX_CADDR %d\n"
argument_list|,
operator|&
name|tp
operator|->
name|x_caddr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SWTCH %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_swtch
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_TRAP %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_trap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SYSCALL %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_syscall
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_INTR %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_intr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_SOFT %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_soft
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_PDMA %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_pdma
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_FAULTS %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_faults
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_PGREC %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_pgrec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tV_FASTPGREC %d\n"
argument_list|,
operator|&
name|vm
operator|->
name|v_fastpgrec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUPAGES %d\n"
argument_list|,
name|UPAGES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tCLSIZE %d\n"
argument_list|,
name|CLSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMAXPHYS %d\n"
argument_list|,
name|MAXPHYS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSYSPTSIZE %d\n"
argument_list|,
name|SYSPTSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tUSRPTSIZE %d\n"
argument_list|,
name|USRPTSIZE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMSGBUFPTECNT %d\n"
argument_list|,
name|btoc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|msgbuf
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tMCLBYTES %d\n"
argument_list|,
name|MCLBYTES
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNMBCLUSTERS %d\n"
argument_list|,
name|NMBCLUSTERS
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tNKMEMCLUSTERS %d\n"
argument_list|,
name|NKMEMCLUSTERS
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SYSVSHM
name|printf
argument_list|(
literal|"#define\tSHMMAXPGS %d\n"
argument_list|,
name|SHMMAXPGS
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"#define\tU_PROCP %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_procp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tU_RU %d\n"
argument_list|,
operator|&
name|up
operator|->
name|u_ru
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tRU_MINFLT %d\n"
argument_list|,
operator|&
name|rup
operator|->
name|ru_minflt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSZ_CMAP %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|cmap
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

