begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"opt_ar71xx.h"
end_include

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
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
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
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcib_private.h>
end_include

begin_include
include|#
directive|include
file|"pcib_if.h"
end_include

begin_include
include|#
directive|include
file|<mips/atheros/ar71xxreg.h>
end_include

begin_include
include|#
directive|include
file|<mips/atheros/ar71xx_pci_bus_space.h>
end_include

begin_include
include|#
directive|include
file|<mips/atheros/ar71xx_cpudef.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/firmware.h>
end_include

begin_include
include|#
directive|include
file|<mips/atheros/ar71xx_fixup.h>
end_include

begin_comment
comment|/*  * Take a copy of the EEPROM contents and squirrel it away in a firmware.  * The SPI flash will eventually cease to be memory-mapped, so we need  * to take a copy of this before the SPI driver initialises.  */
end_comment

begin_function
name|void
name|ar71xx_pci_slot_create_eeprom_firmware
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|bus
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|u_int
name|func
parameter_list|,
name|long
name|int
name|flash_addr
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
name|uint16_t
modifier|*
name|cal_data
init|=
operator|(
name|uint16_t
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG1
argument_list|(
name|flash_addr
argument_list|)
decl_stmt|;
name|void
modifier|*
name|eeprom
init|=
name|NULL
decl_stmt|;
specifier|const
name|struct
name|firmware
modifier|*
name|fw
init|=
name|NULL
decl_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"EEPROM firmware: 0x%lx @ %d bytes\n"
argument_list|,
name|flash_addr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|eeprom
operator|=
name|malloc
argument_list|(
name|size
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|eeprom
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"%s: malloc failed for '%s', aborting EEPROM\n"
argument_list|,
name|__func__
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return;
block|}
name|memcpy
argument_list|(
name|eeprom
argument_list|,
name|cal_data
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* 	 * Generate a flash EEPROM 'firmware' from the given memory 	 * region.  Since the SPI controller will eventually 	 * go into port-IO mode instead of memory-mapped IO 	 * mode, a copy of the EEPROM contents is required. 	 */
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s.%d.bus.%d.%d.%d.eeprom_firmware"
argument_list|,
name|device_get_name
argument_list|(
name|dev
argument_list|)
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
name|bus
argument_list|,
name|slot
argument_list|,
name|func
argument_list|)
expr_stmt|;
name|fw
operator|=
name|firmware_register
argument_list|(
name|buf
argument_list|,
name|eeprom
argument_list|,
name|size
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|fw
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"%s: firmware_register (%s) failed\n"
argument_list|,
name|__func__
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|eeprom
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
return|return;
block|}
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"device EEPROM '%s' registered\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

