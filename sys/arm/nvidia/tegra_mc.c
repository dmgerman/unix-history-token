begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*  * Memory controller driver for Tegra SoCs.  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|"clock_if.h"
end_include

begin_define
define|#
directive|define
name|MC_INTSTATUS
value|0x000
end_define

begin_define
define|#
directive|define
name|MC_INTMASK
value|0x004
end_define

begin_define
define|#
directive|define
name|MC_INT_DECERR_MTS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MC_INT_SECERR_SEC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MC_INT_DECERR_VPR
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MC_INT_INVALID_APB_ASID_UPDATE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MC_INT_INVALID_SMMU_PAGE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MC_INT_ARBITRATION_EMEM
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MC_INT_SECURITY_VIOLATION
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MC_INT_DECERR_EMEM
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MC_INT_INT_MASK
value|(MC_INT_DECERR_MTS |			\ 				 MC_INT_SECERR_SEC |			\ 				 MC_INT_DECERR_VPR |			\ 				 MC_INT_INVALID_APB_ASID_UPDATE |	\ 				 MC_INT_INVALID_SMMU_PAGE |		\ 				 MC_INT_ARBITRATION_EMEM |		\ 				 MC_INT_SECURITY_VIOLATION |		\ 				 MC_INT_DECERR_EMEM)
end_define

begin_define
define|#
directive|define
name|MC_ERR_STATUS
value|0x008
end_define

begin_define
define|#
directive|define
name|MC_ERR_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x7)
end_define

begin_define
define|#
directive|define
name|MC_ERR_TYPE_DECERR_EMEM
value|2
end_define

begin_define
define|#
directive|define
name|MC_ERR_TYPE_SECURITY_TRUSTZONE
value|3
end_define

begin_define
define|#
directive|define
name|MC_ERR_TYPE_SECURITY_CARVEOUT
value|4
end_define

begin_define
define|#
directive|define
name|MC_ERR_TYPE_INVALID_SMMU_PAGE
value|6
end_define

begin_define
define|#
directive|define
name|MC_ERR_INVALID_SMMU_PAGE_READABLE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MC_ERR_INVALID_SMMU_PAGE_WRITABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|MC_ERR_INVALID_SMMU_PAGE_NONSECURE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|MC_ERR_ADR_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x3)
end_define

begin_define
define|#
directive|define
name|MC_ERR_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MC_ERR_SECURITY
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MC_ERR_RW
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MC_ERR_ADR1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
end_define

begin_define
define|#
directive|define
name|MC_ERR_ID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 07F)
end_define

begin_define
define|#
directive|define
name|MC_ERR_ADDR
value|0x00C
end_define

begin_define
define|#
directive|define
name|MC_EMEM_CFG
value|0x050
end_define

begin_define
define|#
directive|define
name|MC_EMEM_ADR_CFG
value|0x054
end_define

begin_define
define|#
directive|define
name|MC_EMEM_NUMDEV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0 )& 0x1)
end_define

begin_define
define|#
directive|define
name|MC_EMEM_ADR_CFG_DEV0
value|0x058
end_define

begin_define
define|#
directive|define
name|MC_EMEM_ADR_CFG_DEV1
value|0x05C
end_define

begin_define
define|#
directive|define
name|EMEM_DEV_DEVSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|EMEM_DEV_BANKWIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0x3)
end_define

begin_define
define|#
directive|define
name|EMEM_DEV_COLWIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0x3)
end_define

begin_define
define|#
directive|define
name|WR4
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|,
name|_v
parameter_list|)
value|bus_write_4((_sc)->mem_res, (_r), (_v))
end_define

begin_define
define|#
directive|define
name|RD4
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|)
value|bus_read_4((_sc)->mem_res, (_r))
end_define

begin_define
define|#
directive|define
name|LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|_sc
parameter_list|,
name|timeout
parameter_list|)
value|mtx_sleep(sc,&sc->mtx, 0, "tegra_mc", timeout);
end_define

begin_define
define|#
directive|define
name|LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&_sc->mtx, device_get_nameunit(_sc->dev), "tegra_mc", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&_sc->mtx)
end_define

begin_define
define|#
directive|define
name|ASSERT_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ASSERT_UNLOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->mtx, MA_NOTOWNED)
end_define

begin_decl_stmt
specifier|static
name|struct
name|ofw_compat_data
name|compat_data
index|[]
init|=
block|{
block|{
literal|"nvidia,tegra124-mc"
block|,
literal|1
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|tegra_mc_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|irq_h
decl_stmt|;
name|clk_t
name|clk
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|char
modifier|*
name|smmu_err_tbl
index|[
literal|16
index|]
init|=
block|{
literal|"reserved"
block|,
comment|/*  0 */
literal|"reserved"
block|,
comment|/*  1 */
literal|"DRAM decode"
block|,
comment|/*  2 */
literal|"Trustzome Security"
block|,
comment|/*  3 */
literal|"Security carveout"
block|,
comment|/*  4 */
literal|"reserved"
block|,
comment|/*  5 */
literal|"Invalid SMMU page"
block|,
comment|/*  6 */
literal|"reserved"
block|,
comment|/*  7 */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|tegra_mc_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|tegra_mc_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|stat
decl_stmt|,
name|err
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|sc
operator|=
operator|(
expr|struct
name|tegra_mc_softc
operator|*
operator|)
name|arg
expr_stmt|;
name|stat
operator|=
name|RD4
argument_list|(
name|sc
argument_list|,
name|MC_INTSTATUS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|stat
operator|&
name|MC_INT_INT_MASK
operator|)
operator|==
literal|0
condition|)
block|{
name|WR4
argument_list|(
name|sc
argument_list|,
name|MC_INTSTATUS
argument_list|,
name|stat
argument_list|)
expr_stmt|;
return|return;
block|}
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"Memory Controller Interrupt:\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_DECERR_MTS
condition|)
name|printf
argument_list|(
literal|" - MTS carveout violation\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_SECERR_SEC
condition|)
name|printf
argument_list|(
literal|" - SEC carveout violation\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_DECERR_VPR
condition|)
name|printf
argument_list|(
literal|" - VPR requirements violated\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_INVALID_APB_ASID_UPDATE
condition|)
name|printf
argument_list|(
literal|" - ivalid APB ASID update\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_INVALID_SMMU_PAGE
condition|)
name|printf
argument_list|(
literal|" - SMMU address translation error\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_ARBITRATION_EMEM
condition|)
name|printf
argument_list|(
literal|" - arbitration deadlock-prevention threshold hit\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_SECURITY_VIOLATION
condition|)
name|printf
argument_list|(
literal|" - SMMU address translation security error\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
operator|&
name|MC_INT_DECERR_EMEM
condition|)
name|printf
argument_list|(
literal|" - SMMU address decode error\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|stat
operator|&
operator|(
name|MC_INT_INVALID_SMMU_PAGE
operator||
name|MC_INT_SECURITY_VIOLATION
operator||
name|MC_INT_DECERR_EMEM
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|err
operator|=
name|RD4
argument_list|(
name|sc
argument_list|,
name|MC_ERR_STATUS
argument_list|)
expr_stmt|;
name|addr
operator|=
name|RD4
argument_list|(
name|sc
argument_list|,
name|MC_ERR_STATUS
argument_list|)
expr_stmt|;
name|addr
operator||=
call|(
name|uint64_t
call|)
argument_list|(
name|MC_ERR_ADR_HI
argument_list|(
name|err
argument_list|)
argument_list|)
operator|<<
literal|32
expr_stmt|;
name|printf
argument_list|(
literal|" at 0x%012llX [%s %s %s]  - %s error.\n"
argument_list|,
name|addr
argument_list|,
name|stat
operator|&
name|MC_ERR_SWAP
condition|?
literal|"Swap, "
else|:
literal|""
argument_list|,
name|stat
operator|&
name|MC_ERR_SECURITY
condition|?
literal|"Sec, "
else|:
literal|""
argument_list|,
name|stat
operator|&
name|MC_ERR_RW
condition|?
literal|"Write"
else|:
literal|"Read"
argument_list|,
name|smmu_err_tbl
index|[
name|MC_ERR_TYPE
argument_list|(
name|err
argument_list|)
index|]
argument_list|)
expr_stmt|;
block|}
name|WR4
argument_list|(
name|sc
argument_list|,
name|MC_INTSTATUS
argument_list|,
name|stat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|tegra_mc_init_hw
parameter_list|(
name|struct
name|tegra_mc_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* Disable and acknowledge all interrupts */
name|WR4
argument_list|(
name|sc
argument_list|,
name|MC_INTMASK
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|WR4
argument_list|(
name|sc
argument_list|,
name|MC_INTSTATUS
argument_list|,
name|MC_INT_INT_MASK
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|tegra_mc_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|ofw_bus_search_compatible
argument_list|(
name|dev
argument_list|,
name|compat_data
argument_list|)
operator|->
name|ocd_data
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Tegra Memory Controller"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|tegra_mc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|rv
decl_stmt|,
name|rid
decl_stmt|;
name|struct
name|tegra_mc_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
name|LOCK_INIT
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Get the memory resource for the register mapping. */
name|rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|mem_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|mem_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot map registers.\n"
argument_list|)
expr_stmt|;
name|rv
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Allocate our IRQ resource. */
name|rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|irq_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot allocate interrupt.\n"
argument_list|)
expr_stmt|;
name|rv
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* OFW resources. */
name|rv
operator|=
name|clk_get_by_ofw_name
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|"mc"
argument_list|,
operator|&
name|sc
operator|->
name|clk
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot get mc clock: %d\n"
argument_list|,
name|rv
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|rv
operator|=
name|clk_enable
argument_list|(
name|sc
operator|->
name|clk
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot enable clock: %d\n"
argument_list|,
name|rv
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Init hardware. */
name|tegra_mc_init_hw
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Setup  interrupt */
name|rv
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|irq_res
argument_list|,
name|INTR_TYPE_MISC
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|tegra_mc_intr
argument_list|,
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|irq_h
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot setup interrupt.\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Enable Interrupts */
name|WR4
argument_list|(
name|sc
argument_list|,
name|MC_INTMASK
argument_list|,
name|MC_INT_INT_MASK
argument_list|)
expr_stmt|;
return|return
operator|(
name|bus_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
name|fail
label|:
if|if
condition|(
name|sc
operator|->
name|clk
operator|!=
name|NULL
condition|)
name|clk_release
argument_list|(
name|sc
operator|->
name|clk
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_h
operator|!=
name|NULL
condition|)
name|bus_teardown_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|irq_res
argument_list|,
name|sc
operator|->
name|irq_h
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_res
operator|!=
name|NULL
condition|)
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
literal|0
argument_list|,
name|sc
operator|->
name|irq_res
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|mem_res
operator|!=
name|NULL
condition|)
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
literal|0
argument_list|,
name|sc
operator|->
name|mem_res
argument_list|)
expr_stmt|;
name|LOCK_DESTROY
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|tegra_mc_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|tegra_mc_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_h
operator|!=
name|NULL
condition|)
name|bus_teardown_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|irq_res
argument_list|,
name|sc
operator|->
name|irq_h
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_res
operator|!=
name|NULL
condition|)
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
literal|0
argument_list|,
name|sc
operator|->
name|irq_res
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|mem_res
operator|!=
name|NULL
condition|)
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
literal|0
argument_list|,
name|sc
operator|->
name|mem_res
argument_list|)
expr_stmt|;
name|LOCK_DESTROY
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
name|bus_generic_detach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|tegra_mc_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|tegra_mc_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|tegra_mc_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|tegra_mc_detach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|tegra_mc_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|DEFINE_CLASS_0
argument_list|(
name|mc
argument_list|,
name|tegra_mc_driver
argument_list|,
name|tegra_mc_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tegra_mc_softc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|tegra_mc
argument_list|,
name|simplebus
argument_list|,
name|tegra_mc_driver
argument_list|,
name|tegra_mc_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

