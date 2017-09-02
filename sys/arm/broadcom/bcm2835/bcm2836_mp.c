begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2015 Daisuke Aoyama<aoyama@peach.ne.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/broadcom/bcm2835/bcm2836_mp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	printf("%s:%u: ", __func__, __LINE__);	\ 	printf(fmt, ##__VA_ARGS__);		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARM_LOCAL_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ARM_LOCAL_SIZE
value|0x00001000
end_define

begin_comment
comment|/* mailbox registers */
end_comment

begin_define
define|#
directive|define
name|MBOXINTRCTRL_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x00000050 + (0x04 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX0SET_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x00000080 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX1SET_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x00000084 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX2SET_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x00000088 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX3SET_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x0000008C + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX0CLR_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x000000C0 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX1CLR_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x000000C4 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX2CLR_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x000000C8 + (0x10 * (n)))
end_define

begin_define
define|#
directive|define
name|MBOX3CLR_CORE
parameter_list|(
name|n
parameter_list|)
value|(0x000000CC + (0x10 * (n)))
end_define

begin_decl_stmt
specifier|static
name|bus_space_handle_t
name|bs_periph
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BSRD4
parameter_list|(
name|addr
parameter_list|)
define|\
value|bus_space_read_4(fdtbus_bs_tag, bs_periph, (addr))
end_define

begin_define
define|#
directive|define
name|BSWR4
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(fdtbus_bs_tag, bs_periph, (addr), (val))
end_define

begin_function
name|void
name|bcm2836_mp_setmaxid
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|DPRINTF
argument_list|(
literal|"platform_mp_setmaxid\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mp_ncpus
operator|!=
literal|0
condition|)
return|return;
name|mp_ncpus
operator|=
literal|4
expr_stmt|;
name|mp_maxid
operator|=
name|mp_ncpus
operator|-
literal|1
expr_stmt|;
name|DPRINTF
argument_list|(
literal|"mp_maxid=%d\n"
argument_list|,
name|mp_maxid
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bcm2836_mp_start_ap
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
name|int
name|i
decl_stmt|,
name|retry
decl_stmt|;
name|DPRINTF
argument_list|(
literal|"platform_mp_start_ap\n"
argument_list|)
expr_stmt|;
comment|/* initialize */
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ARM_LOCAL_BASE
argument_list|,
name|ARM_LOCAL_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|bs_periph
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"can't map local peripheral\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mp_ncpus
condition|;
name|i
operator|++
control|)
block|{
comment|/* clear mailbox 0/3 */
name|BSWR4
argument_list|(
name|MBOX0CLR_CORE
argument_list|(
name|i
argument_list|)
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
name|BSWR4
argument_list|(
name|MBOX3CLR_CORE
argument_list|(
name|i
argument_list|)
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
block|}
name|wmb
argument_list|()
expr_stmt|;
name|dcache_wbinv_poc_all
argument_list|()
expr_stmt|;
comment|/* boot secondary CPUs */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|mp_ncpus
condition|;
name|i
operator|++
control|)
block|{
comment|/* set entry point to mailbox 3 */
name|BSWR4
argument_list|(
name|MBOX3SET_CORE
argument_list|(
name|i
argument_list|)
argument_list|,
operator|(
name|uint32_t
operator|)
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|mpentry
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Firmware put cores in WFE state, need SEV to wake up. */
name|dsb
argument_list|()
expr_stmt|;
name|sev
argument_list|()
expr_stmt|;
comment|/* wait for bootup */
name|retry
operator|=
literal|1000
expr_stmt|;
do|do
block|{
comment|/* check entry point */
name|val
operator|=
name|BSRD4
argument_list|(
name|MBOX3CLR_CORE
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
break|break;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|retry
operator|--
expr_stmt|;
if|if
condition|(
name|retry
operator|<=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"can't start for CPU%d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
literal|1
condition|)
do|;
comment|/* dsb and sev */
name|dsb
argument_list|()
expr_stmt|;
name|sev
argument_list|()
expr_stmt|;
comment|/* recode AP in CPU map */
name|CPU_SET
argument_list|(
name|i
argument_list|,
operator|&
name|all_cpus
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

