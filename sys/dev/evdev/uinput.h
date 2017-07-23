begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * Copyright (c) 2015-2016 Vladimir Kondratyev<wulf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVDEV_UINPUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_EVDEV_UINPUT_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/evdev/input.h>
end_include

begin_define
define|#
directive|define
name|UINPUT_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|UINPUT_MAX_NAME_SIZE
value|80
end_define

begin_struct
struct|struct
name|uinput_ff_upload
block|{
name|uint32_t
name|request_id
decl_stmt|;
name|int32_t
name|retval
decl_stmt|;
name|struct
name|ff_effect
name|effect
decl_stmt|;
name|struct
name|ff_effect
name|old
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uinput_ff_erase
block|{
name|uint32_t
name|request_id
decl_stmt|;
name|int32_t
name|retval
decl_stmt|;
name|uint32_t
name|effect_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ioctl */
end_comment

begin_define
define|#
directive|define
name|UINPUT_IOCTL_BASE
value|'U'
end_define

begin_define
define|#
directive|define
name|UI_DEV_CREATE
value|_IO(UINPUT_IOCTL_BASE, 1)
end_define

begin_define
define|#
directive|define
name|UI_DEV_DESTROY
value|_IO(UINPUT_IOCTL_BASE, 2)
end_define

begin_struct
struct|struct
name|uinput_setup
block|{
name|struct
name|input_id
name|id
decl_stmt|;
name|char
name|name
index|[
name|UINPUT_MAX_NAME_SIZE
index|]
decl_stmt|;
name|uint32_t
name|ff_effects_max
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UI_DEV_SETUP
value|_IOW(UINPUT_IOCTL_BASE, 3, struct uinput_setup)
end_define

begin_struct
struct|struct
name|uinput_abs_setup
block|{
name|uint16_t
name|code
decl_stmt|;
comment|/* axis code */
name|struct
name|input_absinfo
name|absinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UI_ABS_SETUP
value|_IOW(UINPUT_IOCTL_BASE, 4, struct uinput_abs_setup)
end_define

begin_define
define|#
directive|define
name|UI_GET_SYSNAME
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, UINPUT_IOCTL_BASE, 44, len)
end_define

begin_define
define|#
directive|define
name|UI_GET_VERSION
value|_IOR(UINPUT_IOCTL_BASE, 45, unsigned int)
end_define

begin_define
define|#
directive|define
name|UI_SET_EVBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 100)
end_define

begin_define
define|#
directive|define
name|UI_SET_KEYBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 101)
end_define

begin_define
define|#
directive|define
name|UI_SET_RELBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 102)
end_define

begin_define
define|#
directive|define
name|UI_SET_ABSBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 103)
end_define

begin_define
define|#
directive|define
name|UI_SET_MSCBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 104)
end_define

begin_define
define|#
directive|define
name|UI_SET_LEDBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 105)
end_define

begin_define
define|#
directive|define
name|UI_SET_SNDBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 106)
end_define

begin_define
define|#
directive|define
name|UI_SET_FFBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 107)
end_define

begin_define
define|#
directive|define
name|UI_SET_PHYS
value|_IO(UINPUT_IOCTL_BASE, 108)
end_define

begin_define
define|#
directive|define
name|UI_SET_SWBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 109)
end_define

begin_define
define|#
directive|define
name|UI_SET_PROPBIT
value|_IOWINT(UINPUT_IOCTL_BASE, 110)
end_define

begin_define
define|#
directive|define
name|UI_BEGIN_FF_UPLOAD
value|_IOWR(UINPUT_IOCTL_BASE, 200, struct uinput_ff_upload)
end_define

begin_define
define|#
directive|define
name|UI_END_FF_UPLOAD
value|_IOW(UINPUT_IOCTL_BASE, 201, struct uinput_ff_upload)
end_define

begin_define
define|#
directive|define
name|UI_BEGIN_FF_ERASE
value|_IOWR(UINPUT_IOCTL_BASE, 202, struct uinput_ff_erase)
end_define

begin_define
define|#
directive|define
name|UI_END_FF_ERASE
value|_IOW(UINPUT_IOCTL_BASE, 203, struct uinput_ff_erase)
end_define

begin_define
define|#
directive|define
name|EV_UINPUT
value|0x0101
end_define

begin_define
define|#
directive|define
name|UI_FF_UPLOAD
value|1
end_define

begin_define
define|#
directive|define
name|UI_FF_ERASE
value|2
end_define

begin_struct
struct|struct
name|uinput_user_dev
block|{
name|char
name|name
index|[
name|UINPUT_MAX_NAME_SIZE
index|]
decl_stmt|;
name|struct
name|input_id
name|id
decl_stmt|;
name|uint32_t
name|ff_effects_max
decl_stmt|;
name|int32_t
name|absmax
index|[
name|ABS_CNT
index|]
decl_stmt|;
name|int32_t
name|absmin
index|[
name|ABS_CNT
index|]
decl_stmt|;
name|int32_t
name|absfuzz
index|[
name|ABS_CNT
index|]
decl_stmt|;
name|int32_t
name|absflat
index|[
name|ABS_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EVDEV_UINPUT_H_ */
end_comment

end_unit

