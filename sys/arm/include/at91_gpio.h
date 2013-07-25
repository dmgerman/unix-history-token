begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006 M. Warner Losh. All rights reserved.  * Copyright (C) 2012 Ian Lepore. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AT91_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AT91_GPIO_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Userland GPIO API for Atmel AT91 series SOC.  *  * Open /dev/pioN (where N is 0 for PIOA, 1 for PIOB, etc), and use ioctl(2)  * calls to configure the pin(s) as needed.  *  * The userland interrupt support allows you to use read(2) and/or select(2) to  * get notified of interrupts on PIO pins for which you enabled interrupt  * notifications.  Each time an interrupt occurs on a given pin, that pin number  * is written into a buffer as a uint8_t.  Thus, reading from /dev/pioN delivers  * info on which interrupt(s) have occurred since the last read.  You can also  * use select() to block until an interrupt occurs (you still need to read() to  * consume the interrupt number bytes from the buffer.)  */
end_comment

begin_struct
struct|struct
name|at91_gpio_info
block|{
name|uint32_t
name|output_status
decl_stmt|;
comment|/* Current state of output pins */
name|uint32_t
name|input_status
decl_stmt|;
comment|/* 1->out 0->in bitmask */
name|uint32_t
name|highz_status
decl_stmt|;
comment|/* 1->highz 0->driven bitmask */
name|uint32_t
name|pullup_status
decl_stmt|;
comment|/* 1->floating 0->pullup engaged */
name|uint32_t
name|glitch_status
decl_stmt|;
comment|/* 0-> no glitch filter 1->gf */
name|uint32_t
name|enabled_status
decl_stmt|;
comment|/* 1->used for pio 0->other */
name|uint32_t
name|periph_status
decl_stmt|;
comment|/* 0->A periph 1->B periph */
name|uint32_t
name|intr_status
decl_stmt|;
comment|/* 1-> ISR enabled, 0->disabled */
name|uint32_t
name|extra_status
index|[
literal|8
index|]
decl_stmt|;
comment|/* Extra status info, device depend */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91_gpio_cfg
block|{
name|uint32_t
name|cfgmask
decl_stmt|;
comment|/* which things change */
define|#
directive|define
name|AT91_GPIO_CFG_INPUT
value|0x01
comment|/* configure input/output pins */
define|#
directive|define
name|AT91_GPIO_CFG_HI_Z
value|0x02
comment|/* HiZ */
define|#
directive|define
name|AT91_GPIO_CFG_PULLUP
value|0x04
comment|/* Enable/disable pullup resistors */
define|#
directive|define
name|AT91_GPIO_CFG_GLITCH
value|0x08
comment|/* Glitch filtering */
define|#
directive|define
name|AT91_GPIO_CFG_GPIO
value|0x10
comment|/* Use pin for PIO or peripheral */
define|#
directive|define
name|AT91_GPIO_CFG_PERIPH
value|0x20
comment|/* Select which peripheral to use */
define|#
directive|define
name|AT91_GPIO_CFG_INTR
value|0x40
comment|/* Select pin for interrupts */
name|uint32_t
name|iomask
decl_stmt|;
comment|/* Mask of bits to change */
name|uint32_t
name|input
decl_stmt|;
comment|/* or output */
name|uint32_t
name|hi_z
decl_stmt|;
comment|/* Disable output */
name|uint32_t
name|pullup
decl_stmt|;
comment|/* Enable pullup resistor */
name|uint32_t
name|glitch
decl_stmt|;
comment|/* Glitch filtering */
name|uint32_t
name|gpio
decl_stmt|;
comment|/* Enabled for PIO (1) or periph (0) */
name|uint32_t
name|periph
decl_stmt|;
comment|/* Select periph A (0) or periph B (1) */
name|uint32_t
name|intr
decl_stmt|;
comment|/* Enable interrupt (1), or not (0) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91_gpio_bang
block|{
name|uint32_t
name|clockpin
decl_stmt|;
comment|/* clock pin MASK */
name|uint32_t
name|datapin
decl_stmt|;
comment|/* Data pin MASK */
name|uint32_t
name|bits
decl_stmt|;
comment|/* bits to clock out (all 32) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91_gpio_bang_many
block|{
name|uint32_t
name|clockpin
decl_stmt|;
comment|/* clock pin MASK */
name|uint32_t
name|datapin
decl_stmt|;
comment|/* Data pin MASK */
name|void
modifier|*
name|bits
decl_stmt|;
comment|/* bits to clock out */
name|uint32_t
name|numbits
decl_stmt|;
comment|/* Number of bits to clock out */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AT91_GPIO_SET
value|_IOW('g', 0, uint32_t)
end_define

begin_comment
comment|/* Turn bits on */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_CLR
value|_IOW('g', 1, uint32_t)
end_define

begin_comment
comment|/* Turn bits off */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_READ
value|_IOR('g', 2, uint32_t)
end_define

begin_comment
comment|/* Read input bit state */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_INFO
value|_IOR('g', 3, struct at91_gpio_info)
end_define

begin_comment
comment|/* State of pio cfg */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_CFG
value|_IOW('g', 4, struct at91_gpio_cfg)
end_define

begin_comment
comment|/* Configure pio */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_BANG
value|_IOW('g', 5, struct at91_gpio_bang)
end_define

begin_comment
comment|/* bit bang 32 bits */
end_comment

begin_define
define|#
directive|define
name|AT91_GPIO_BANG_MANY
value|_IOW('g', 6, struct at91_gpio_bang_many)
end_define

begin_comment
comment|/* bit bang>32 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AT91_GPIO_H */
end_comment

end_unit

