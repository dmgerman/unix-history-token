begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * All rights reserved.  * Copyright (c) 2000 Jake Burkholder<jake@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_GLOBALS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_GLOBALS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|globaldata
operator|*
name|_global_globaldata
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|globaldata
operator|*
name|gd
block|;
name|int
name|offset
block|;
name|offset
operator|=
name|offsetof
argument_list|(
expr|struct
name|globaldata
argument_list|,
name|gd_prvspace
argument_list|)
block|;
asm|__asm __volatile("movl %%fs:%1,%0"
operator|:
literal|"=r"
operator|(
name|gd
operator|)
operator|:
literal|"m"
operator|(
operator|*
operator|(
expr|struct
name|globaldata
operator|*
operator|)
operator|(
name|offset
operator|)
operator|)
block|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|gd
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|GLOBALDATA
value|(_global_globaldata())
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(GLOBALDATA->gd_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&GLOBALDATA->gd_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|(GLOBALDATA->gd_ ## member = (val))
end_define

begin_define
define|#
directive|define
name|CURPROC
value|PCPU_GET(curproc)
end_define

begin_define
define|#
directive|define
name|CURTHD
value|PCPU_GET(curproc)
end_define

begin_define
define|#
directive|define
name|astpending
value|PCPU_GET(astpending)
end_define

begin_define
define|#
directive|define
name|common_tss
value|(*PCPU_PTR(common_tss))
end_define

begin_define
define|#
directive|define
name|common_tssd
value|(*PCPU_PTR(common_tssd))
end_define

begin_define
define|#
directive|define
name|cpuid
value|PCPU_GET(cpuid)
end_define

begin_define
define|#
directive|define
name|currentldt
value|PCPU_GET(currentldt)
end_define

begin_define
define|#
directive|define
name|curpcb
value|PCPU_GET(curpcb)
end_define

begin_define
define|#
directive|define
name|curproc
value|PCPU_GET(curproc)
end_define

begin_define
define|#
directive|define
name|idleproc
value|PCPU_GET(idleproc)
end_define

begin_define
define|#
directive|define
name|inside_intr
value|(*PCPU_PTR(inside_intr))
end_define

begin_define
define|#
directive|define
name|intr_nesting_level
value|PCPU_GET(intr_nesting_level)
end_define

begin_define
define|#
directive|define
name|npxproc
value|PCPU_GET(npxproc)
end_define

begin_define
define|#
directive|define
name|prv_CMAP1
value|(*PCPU_PTR(prv_CMAP1))
end_define

begin_define
define|#
directive|define
name|prv_CMAP2
value|(*PCPU_PTR(prv_CMAP2))
end_define

begin_define
define|#
directive|define
name|prv_CMAP3
value|(*PCPU_PTR(prv_CMAP3))
end_define

begin_define
define|#
directive|define
name|prv_PMAP1
value|(*PCPU_PTR(prv_PMAP1))
end_define

begin_define
define|#
directive|define
name|prv_CADDR1
value|PCPU_GET(prv_CADDR1)
end_define

begin_define
define|#
directive|define
name|prv_CADDR2
value|PCPU_GET(prv_CADDR2)
end_define

begin_define
define|#
directive|define
name|prv_CADDR3
value|PCPU_GET(prv_CADDR3)
end_define

begin_define
define|#
directive|define
name|prv_PADDR1
value|PCPU_GET(prv_PADDR1)
end_define

begin_define
define|#
directive|define
name|other_cpus
value|(*PCPU_PTR(other_cpus))
end_define

begin_define
define|#
directive|define
name|switchticks
value|(*PCPU_PTR(switchticks))
end_define

begin_define
define|#
directive|define
name|switchtime
value|(*PCPU_PTR(switchtime))
end_define

begin_define
define|#
directive|define
name|tss_gdt
value|(*PCPU_PTR(tss_gdt))
end_define

begin_define
define|#
directive|define
name|witness_spin_check
value|PCPU_GET(witness_spin_check)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_GLOBALS_H_ */
end_comment

end_unit

