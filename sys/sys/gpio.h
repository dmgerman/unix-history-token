begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: gpio.h,v 1.7 2009/09/25 20:27:50 mbalmer Exp $ */
end_comment

begin_comment
comment|/*	$OpenBSD: gpio.h,v 1.7 2008/11/26 14:51:20 mbalmer Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009 Marc Balmer<marc@msys.ch>  * Copyright (c) 2004 Alexander Yurchenko<grange@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GPIO_H__
end_ifndef

begin_define
define|#
directive|define
name|__GPIO_H__
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* GPIO pin states */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_LOW
value|0x00
end_define

begin_comment
comment|/* low level (logical 0) */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_HIGH
value|0x01
end_define

begin_comment
comment|/* high level (logical 1) */
end_comment

begin_comment
comment|/* Max name length of a pin */
end_comment

begin_define
define|#
directive|define
name|GPIOMAXNAME
value|64
end_define

begin_comment
comment|/* GPIO pin configuration flags */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_INPUT
value|0x00000001
end_define

begin_comment
comment|/* input direction */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_OUTPUT
value|0x00000002
end_define

begin_comment
comment|/* output direction */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_OPENDRAIN
value|0x00000004
end_define

begin_comment
comment|/* open-drain output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PUSHPULL
value|0x00000008
end_define

begin_comment
comment|/* push-pull output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_TRISTATE
value|0x00000010
end_define

begin_comment
comment|/* output disabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULLUP
value|0x00000020
end_define

begin_comment
comment|/* internal pull-up enabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULLDOWN
value|0x00000040
end_define

begin_comment
comment|/* internal pull-down enabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_INVIN
value|0x00000080
end_define

begin_comment
comment|/* invert input */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_INVOUT
value|0x00000100
end_define

begin_comment
comment|/* invert output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULSATE
value|0x00000200
end_define

begin_comment
comment|/* pulsate in hardware */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PRESET_LOW
value|0x00000400
end_define

begin_comment
comment|/* preset pin to high or */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PRESET_HIGH
value|0x00000800
end_define

begin_comment
comment|/* low before enabling output */
end_comment

begin_comment
comment|/* GPIO interrupt capabilities */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_NONE
value|0x00000000
end_define

begin_comment
comment|/* no interrupt support */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_LEVEL_LOW
value|0x00010000
end_define

begin_comment
comment|/* level trigger, low */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_LEVEL_HIGH
value|0x00020000
end_define

begin_comment
comment|/* level trigger, high */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_EDGE_RISING
value|0x00040000
end_define

begin_comment
comment|/* edge trigger, rising */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_EDGE_FALLING
value|0x00080000
end_define

begin_comment
comment|/* edge trigger, falling */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_EDGE_BOTH
value|0x00100000
end_define

begin_comment
comment|/* edge trigger, both */
end_comment

begin_define
define|#
directive|define
name|GPIO_INTR_MASK
value|(GPIO_INTR_LEVEL_LOW | GPIO_INTR_LEVEL_HIGH | \ 				GPIO_INTR_EDGE_RISING |			      \ 				GPIO_INTR_EDGE_FALLING | GPIO_INTR_EDGE_BOTH)
end_define

begin_struct
struct|struct
name|gpio_pin
block|{
name|uint32_t
name|gp_pin
decl_stmt|;
comment|/* pin number */
name|char
name|gp_name
index|[
name|GPIOMAXNAME
index|]
decl_stmt|;
comment|/* human-readable name */
name|uint32_t
name|gp_caps
decl_stmt|;
comment|/* capabilities */
name|uint32_t
name|gp_flags
decl_stmt|;
comment|/* current flags */
block|}
struct|;
end_struct

begin_comment
comment|/* GPIO pin request (read/write/toggle) */
end_comment

begin_struct
struct|struct
name|gpio_req
block|{
name|uint32_t
name|gp_pin
decl_stmt|;
comment|/* pin number */
name|uint32_t
name|gp_value
decl_stmt|;
comment|/* value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * gpio_access_32 / GPIOACCESS32  *  * Simultaneously read and/or change up to 32 adjacent pins.  * If the device cannot change the pins simultaneously, returns EOPNOTSUPP.  *  * This accesses an adjacent set of up to 32 pins starting at first_pin within  * the device's collection of pins.  How the hardware pins are mapped to the 32  * bits in the arguments is device-specific.  It is expected that lower-numbered  * pins in the device's number space map linearly to lower-ordered bits within  * the 32-bit words (i.e., bit 0 is first_pin, bit 1 is first_pin+1, etc).  * Other mappings are possible; know your device.  *  * Some devices may limit the value of first_pin to 0, or to multiples of 16 or  * 32 or some other hardware-specific number; to access pin 2 would require  * first_pin to be zero and then manipulate bit (1<< 2) in the 32-bit word.  * Invalid values in first_pin result in an EINVAL error return.  *  * The starting state of the pins is captured and stored in orig_pins, then the  * pins are set to ((starting_state& ~clear_pins) ^ change_pins).   *  *   Clear  Change  Hardware pin after call  *     0      0        No change  *     0      1        Opposite of current value  *     1      0        Cleared  *     1      1        Set  */
end_comment

begin_struct
struct|struct
name|gpio_access_32
block|{
name|uint32_t
name|first_pin
decl_stmt|;
comment|/* First pin in group of 32 adjacent */
name|uint32_t
name|clear_pins
decl_stmt|;
comment|/* Pins are changed using: */
name|uint32_t
name|change_pins
decl_stmt|;
comment|/* ((hwstate& ~clear_pins) ^ change_pins) */
name|uint32_t
name|orig_pins
decl_stmt|;
comment|/* Returned hwstate of pins before change. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * gpio_config_32 / GPIOCONFIG32  *  * Simultaneously configure up to 32 adjacent pins.  This is intended to change  * the configuration of all the pins simultaneously, such that pins configured  * for output all begin to drive the configured values simultaneously, but not  * all hardware can do that, so the driver "does the best it can" in this  * regard.  Notably unlike pin_access_32(), this does NOT fail if the pins  * cannot be atomically configured; it is expected that callers understand the  * hardware and have decided to live with any such limitations it may have.  *  * The pin_flags argument is an array of GPIO_PIN_xxxx flags.  If the array  * contains any GPIO_PIN_OUTPUT flags, the driver will manipulate the hardware  * such that all output pins become driven with the proper initial values  * simultaneously if it can.  The elements in the array map to pins in the same  * way that bits are mapped by pin_acces_32(), and the same restrictions may  * apply.  For example, to configure pins 2 and 3 it may be necessary to set  * first_pin to zero and only populate pin_flags[2] and pin_flags[3].  If a  * given array entry doesn't contain GPIO_PIN_INPUT or GPIO_PIN_OUTPUT then no  * configuration is done for that pin.  *  * Some devices may limit the value of first_pin to 0, or to multiples of 16 or  * 32 or some other hardware-specific number.  Invalid values in first_pin or  * num_pins result in an error return with errno set to EINVAL.  */
end_comment

begin_struct
struct|struct
name|gpio_config_32
block|{
name|uint32_t
name|first_pin
decl_stmt|;
name|uint32_t
name|num_pins
decl_stmt|;
name|uint32_t
name|pin_flags
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ioctls  */
end_comment

begin_define
define|#
directive|define
name|GPIOMAXPIN
value|_IOR('G', 0, int)
end_define

begin_define
define|#
directive|define
name|GPIOGETCONFIG
value|_IOWR('G', 1, struct gpio_pin)
end_define

begin_define
define|#
directive|define
name|GPIOSETCONFIG
value|_IOW('G', 2, struct gpio_pin)
end_define

begin_define
define|#
directive|define
name|GPIOGET
value|_IOWR('G', 3, struct gpio_req)
end_define

begin_define
define|#
directive|define
name|GPIOSET
value|_IOW('G', 4, struct gpio_req)
end_define

begin_define
define|#
directive|define
name|GPIOTOGGLE
value|_IOWR('G', 5, struct gpio_req)
end_define

begin_define
define|#
directive|define
name|GPIOSETNAME
value|_IOW('G', 6, struct gpio_pin)
end_define

begin_define
define|#
directive|define
name|GPIOACCESS32
value|_IOWR('G', 7, struct gpio_access_32)
end_define

begin_define
define|#
directive|define
name|GPIOCONFIG32
value|_IOW('G', 8, struct gpio_config_32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GPIO_H__ */
end_comment

end_unit

