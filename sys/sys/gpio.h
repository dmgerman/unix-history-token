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
value|0x0001
end_define

begin_comment
comment|/* input direction */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_OUTPUT
value|0x0002
end_define

begin_comment
comment|/* output direction */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_OPENDRAIN
value|0x0004
end_define

begin_comment
comment|/* open-drain output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PUSHPULL
value|0x0008
end_define

begin_comment
comment|/* push-pull output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_TRISTATE
value|0x0010
end_define

begin_comment
comment|/* output disabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULLUP
value|0x0020
end_define

begin_comment
comment|/* internal pull-up enabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULLDOWN
value|0x0040
end_define

begin_comment
comment|/* internal pull-down enabled */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_INVIN
value|0x0080
end_define

begin_comment
comment|/* invert input */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_INVOUT
value|0x0100
end_define

begin_comment
comment|/* invert output */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_PULSATE
value|0x0200
end_define

begin_comment
comment|/* pulsate in hardware */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GPIO_H__ */
end_comment

end_unit

