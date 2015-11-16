begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defines for converting physical address to VideoCore bus address and back  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCM2835_VCBUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCM2835_VCBUS_H_
end_define

begin_define
define|#
directive|define
name|BCM2835_VCBUS_SDRAM_CACHED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BCM2835_VCBUS_IO_BASE
value|0x7E000000
end_define

begin_define
define|#
directive|define
name|BCM2835_VCBUS_SDRAM_UNCACHED
value|0xC0000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOC_BCM2836
end_ifdef

begin_define
define|#
directive|define
name|BCM2835_ARM_IO_BASE
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|BCM2835_VCBUS_SDRAM_BASE
value|BCM2835_VCBUS_SDRAM_UNCACHED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BCM2835_ARM_IO_BASE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BCM2835_VCBUS_SDRAM_BASE
value|BCM2835_VCBUS_SDRAM_CACHED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BCM2835_ARM_IO_SIZE
value|0x01000000
end_define

begin_comment
comment|/*  * Convert physical address to VC bus address. Should be used   * when submitting address over mailbox interface   */
end_comment

begin_define
define|#
directive|define
name|PHYS_TO_VCBUS
parameter_list|(
name|pa
parameter_list|)
value|((pa) + BCM2835_VCBUS_SDRAM_BASE)
end_define

begin_comment
comment|/* Check whether pa bellong top IO window */
end_comment

begin_define
define|#
directive|define
name|BCM2835_ARM_IS_IO
parameter_list|(
name|pa
parameter_list|)
value|(((pa)>= BCM2835_ARM_IO_BASE)&& \     ((pa)< BCM2835_ARM_IO_BASE + BCM2835_ARM_IO_SIZE))
end_define

begin_comment
comment|/*  * Convert physical address in IO space to VC bus address.   */
end_comment

begin_define
define|#
directive|define
name|IO_TO_VCBUS
parameter_list|(
name|pa
parameter_list|)
value|((pa - BCM2835_ARM_IO_BASE) + \     BCM2835_VCBUS_IO_BASE)
end_define

begin_comment
comment|/*  * Convert address from VC bus space to physical. Should be used  * when address is returned by VC over mailbox interface. e.g.  * framebuffer base  */
end_comment

begin_define
define|#
directive|define
name|VCBUS_TO_PHYS
parameter_list|(
name|vca
parameter_list|)
value|((vca)& ~(BCM2835_VCBUS_SDRAM_BASE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCM2835_VCBUS_H_ */
end_comment

end_unit

