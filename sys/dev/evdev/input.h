begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * Copyright (c) 2015-2016 Vladimir Kondratyev<wulf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVDEV_INPUT_H
end_ifndef

begin_define
define|#
directive|define
name|_EVDEV_INPUT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

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
file|"input-event-codes.h"
end_include

begin_struct
struct|struct
name|input_event
block|{
name|struct
name|timeval
name|time
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|code
decl_stmt|;
name|int32_t
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EV_VERSION
value|0x010001
end_define

begin_struct
struct|struct
name|input_id
block|{
name|uint16_t
name|bustype
decl_stmt|;
name|uint16_t
name|vendor
decl_stmt|;
name|uint16_t
name|product
decl_stmt|;
name|uint16_t
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|input_absinfo
block|{
name|int32_t
name|value
decl_stmt|;
name|int32_t
name|minimum
decl_stmt|;
name|int32_t
name|maximum
decl_stmt|;
name|int32_t
name|fuzz
decl_stmt|;
name|int32_t
name|flat
decl_stmt|;
name|int32_t
name|resolution
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INPUT_KEYMAP_BY_INDEX
value|(1<< 0)
end_define

begin_struct
struct|struct
name|input_keymap_entry
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint16_t
name|index
decl_stmt|;
name|uint32_t
name|keycode
decl_stmt|;
name|uint8_t
name|scancode
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EVDEV_IOC_MAGIC
value|'E'
end_define

begin_define
define|#
directive|define
name|EVIOCGVERSION
value|_IOR(EVDEV_IOC_MAGIC, 0x01, int)
end_define

begin_comment
comment|/* get driver version */
end_comment

begin_define
define|#
directive|define
name|EVIOCGID
value|_IOR(EVDEV_IOC_MAGIC, 0x02, struct input_id)
end_define

begin_comment
comment|/* get device ID */
end_comment

begin_define
define|#
directive|define
name|EVIOCGREP
value|_IOR(EVDEV_IOC_MAGIC, 0x03, unsigned int[2])
end_define

begin_comment
comment|/* get repeat settings */
end_comment

begin_define
define|#
directive|define
name|EVIOCSREP
value|_IOW(EVDEV_IOC_MAGIC, 0x03, unsigned int[2])
end_define

begin_comment
comment|/* set repeat settings */
end_comment

begin_define
define|#
directive|define
name|EVIOCGKEYCODE
value|_IOWR(EVDEV_IOC_MAGIC, 0x04, unsigned int[2])
end_define

begin_comment
comment|/* get keycode */
end_comment

begin_define
define|#
directive|define
name|EVIOCGKEYCODE_V2
value|_IOWR(EVDEV_IOC_MAGIC, 0x04, struct input_keymap_entry)
end_define

begin_define
define|#
directive|define
name|EVIOCSKEYCODE
value|_IOW(EVDEV_IOC_MAGIC, 0x04, unsigned int[2])
end_define

begin_comment
comment|/* set keycode */
end_comment

begin_define
define|#
directive|define
name|EVIOCSKEYCODE_V2
value|_IOW(EVDEV_IOC_MAGIC, 0x04, struct input_keymap_entry)
end_define

begin_define
define|#
directive|define
name|EVIOCGNAME
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x06, len)
end_define

begin_comment
comment|/* get device name */
end_comment

begin_define
define|#
directive|define
name|EVIOCGPHYS
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x07, len)
end_define

begin_comment
comment|/* get physical location */
end_comment

begin_define
define|#
directive|define
name|EVIOCGUNIQ
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x08, len)
end_define

begin_comment
comment|/* get unique identifier */
end_comment

begin_define
define|#
directive|define
name|EVIOCGPROP
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x09, len)
end_define

begin_comment
comment|/* get device properties */
end_comment

begin_define
define|#
directive|define
name|EVIOCGMTSLOTS
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_INOUT,	EVDEV_IOC_MAGIC, 0x0a, len)
end_define

begin_comment
comment|/* get MT slots values */
end_comment

begin_define
define|#
directive|define
name|EVIOCGKEY
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x18, len)
end_define

begin_comment
comment|/* get global key state */
end_comment

begin_define
define|#
directive|define
name|EVIOCGLED
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x19, len)
end_define

begin_comment
comment|/* get all LEDs */
end_comment

begin_define
define|#
directive|define
name|EVIOCGSND
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x1a, len)
end_define

begin_comment
comment|/* get all sounds status */
end_comment

begin_define
define|#
directive|define
name|EVIOCGSW
parameter_list|(
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x1b, len)
end_define

begin_comment
comment|/* get all switch states */
end_comment

begin_define
define|#
directive|define
name|EVIOCGBIT
parameter_list|(
name|ev
parameter_list|,
name|len
parameter_list|)
value|_IOC(IOC_OUT, EVDEV_IOC_MAGIC, 0x20 + (ev), len)
end_define

begin_comment
comment|/* get event bits */
end_comment

begin_define
define|#
directive|define
name|EVIOCGABS
parameter_list|(
name|abs
parameter_list|)
value|_IOR(EVDEV_IOC_MAGIC, 0x40 + (abs), struct input_absinfo)
end_define

begin_comment
comment|/* get abs value/limits */
end_comment

begin_define
define|#
directive|define
name|EVIOCSABS
parameter_list|(
name|abs
parameter_list|)
value|_IOW(EVDEV_IOC_MAGIC, 0xc0 + (abs), struct input_absinfo)
end_define

begin_comment
comment|/* set abs value/limits */
end_comment

begin_define
define|#
directive|define
name|EVIOCSFF
value|_IOW(EVDEV_IOC_MAGIC, 0x80, struct ff_effect)
end_define

begin_comment
comment|/* send a force effect to a force feedback device */
end_comment

begin_define
define|#
directive|define
name|EVIOCRMFF
value|_IOWINT(EVDEV_IOC_MAGIC, 0x81)
end_define

begin_comment
comment|/* Erase a force effect */
end_comment

begin_define
define|#
directive|define
name|EVIOCGEFFECTS
value|_IOR(EVDEV_IOC_MAGIC, 0x84, int)
end_define

begin_comment
comment|/* Report number of effects playable at the same time */
end_comment

begin_define
define|#
directive|define
name|EVIOCGRAB
value|_IOWINT(EVDEV_IOC_MAGIC, 0x90)
end_define

begin_comment
comment|/* Grab/Release device */
end_comment

begin_define
define|#
directive|define
name|EVIOCREVOKE
value|_IOWINT(EVDEV_IOC_MAGIC, 0x91)
end_define

begin_comment
comment|/* Revoke device access */
end_comment

begin_define
define|#
directive|define
name|EVIOCSCLOCKID
value|_IOW(EVDEV_IOC_MAGIC, 0xa0, int)
end_define

begin_comment
comment|/* Set clockid to be used for timestamps */
end_comment

begin_comment
comment|/*  * IDs.  */
end_comment

begin_define
define|#
directive|define
name|ID_BUS
value|0
end_define

begin_define
define|#
directive|define
name|ID_VENDOR
value|1
end_define

begin_define
define|#
directive|define
name|ID_PRODUCT
value|2
end_define

begin_define
define|#
directive|define
name|ID_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|BUS_PCI
value|0x01
end_define

begin_define
define|#
directive|define
name|BUS_ISAPNP
value|0x02
end_define

begin_define
define|#
directive|define
name|BUS_USB
value|0x03
end_define

begin_define
define|#
directive|define
name|BUS_HIL
value|0x04
end_define

begin_define
define|#
directive|define
name|BUS_BLUETOOTH
value|0x05
end_define

begin_define
define|#
directive|define
name|BUS_VIRTUAL
value|0x06
end_define

begin_define
define|#
directive|define
name|BUS_ISA
value|0x10
end_define

begin_define
define|#
directive|define
name|BUS_I8042
value|0x11
end_define

begin_define
define|#
directive|define
name|BUS_XTKBD
value|0x12
end_define

begin_define
define|#
directive|define
name|BUS_RS232
value|0x13
end_define

begin_define
define|#
directive|define
name|BUS_GAMEPORT
value|0x14
end_define

begin_define
define|#
directive|define
name|BUS_PARPORT
value|0x15
end_define

begin_define
define|#
directive|define
name|BUS_AMIGA
value|0x16
end_define

begin_define
define|#
directive|define
name|BUS_ADB
value|0x17
end_define

begin_define
define|#
directive|define
name|BUS_I2C
value|0x18
end_define

begin_define
define|#
directive|define
name|BUS_HOST
value|0x19
end_define

begin_define
define|#
directive|define
name|BUS_GSC
value|0x1A
end_define

begin_define
define|#
directive|define
name|BUS_ATARI
value|0x1B
end_define

begin_define
define|#
directive|define
name|BUS_SPI
value|0x1C
end_define

begin_comment
comment|/*  * MT_TOOL types  */
end_comment

begin_define
define|#
directive|define
name|MT_TOOL_FINGER
value|0
end_define

begin_define
define|#
directive|define
name|MT_TOOL_PEN
value|1
end_define

begin_define
define|#
directive|define
name|MT_TOOL_PALM
value|2
end_define

begin_define
define|#
directive|define
name|MT_TOOL_MAX
value|2
end_define

begin_comment
comment|/*  * Values describing the status of a force-feedback effect  */
end_comment

begin_define
define|#
directive|define
name|FF_STATUS_STOPPED
value|0x00
end_define

begin_define
define|#
directive|define
name|FF_STATUS_PLAYING
value|0x01
end_define

begin_define
define|#
directive|define
name|FF_STATUS_MAX
value|0x01
end_define

begin_comment
comment|/* scheduling info for force feedback effect */
end_comment

begin_struct
struct|struct
name|ff_replay
block|{
name|uint16_t
name|length
decl_stmt|;
comment|/* length of the effect (ms) */
name|uint16_t
name|delay
decl_stmt|;
comment|/* delay before effect starts (ms) */
block|}
struct|;
end_struct

begin_comment
comment|/* trigger for force feedback effect */
end_comment

begin_struct
struct|struct
name|ff_trigger
block|{
name|uint16_t
name|button
decl_stmt|;
comment|/* trigger button number */
name|uint16_t
name|interval
decl_stmt|;
comment|/* delay between re-triggers */
block|}
struct|;
end_struct

begin_comment
comment|/* force feedback effect envelop */
end_comment

begin_struct
struct|struct
name|ff_envelope
block|{
name|uint16_t
name|attack_length
decl_stmt|;
comment|/* duration of the attach (ms) */
name|uint16_t
name|attack_level
decl_stmt|;
comment|/* level at the beginning (0x0000 - 0x7fff) */
name|uint16_t
name|fade_length
decl_stmt|;
comment|/* duratin of fade (ms) */
name|uint16_t
name|fade_level
decl_stmt|;
comment|/* level at the end of fade */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ff_constant_effect
block|{
name|int16_t
name|level
decl_stmt|;
name|struct
name|ff_envelope
name|envelope
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ff_ramp_effect
block|{
name|int16_t
name|start_level
decl_stmt|;
name|int16_t
name|end_level
decl_stmt|;
name|struct
name|ff_envelope
name|envelope
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ff_condition_effect
block|{
comment|/* maximum level when joystick moved to respective side */
name|uint16_t
name|right_saturation
decl_stmt|;
name|uint16_t
name|left_saturation
decl_stmt|;
comment|/* how fast force grows when joystick move to the respective side */
name|int16_t
name|right_coeff
decl_stmt|;
name|int16_t
name|left_coeff
decl_stmt|;
name|uint16_t
name|deadband
decl_stmt|;
comment|/* size of dead zone when no force is produced */
name|int16_t
name|center
decl_stmt|;
comment|/* center of dead zone */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Force feedback periodic effect types  */
end_comment

begin_define
define|#
directive|define
name|FF_SQUARE
value|0x58
end_define

begin_define
define|#
directive|define
name|FF_TRIANGLE
value|0x59
end_define

begin_define
define|#
directive|define
name|FF_SINE
value|0x5a
end_define

begin_define
define|#
directive|define
name|FF_SAW_UP
value|0x5b
end_define

begin_define
define|#
directive|define
name|FF_SAW_DOWN
value|0x5c
end_define

begin_define
define|#
directive|define
name|FF_CUSTOM
value|0x5d
end_define

begin_define
define|#
directive|define
name|FF_WAVEFORM_MIN
value|FF_SQUARE
end_define

begin_define
define|#
directive|define
name|FF_WAVEFORM_MAX
value|FF_CUSTOM
end_define

begin_struct
struct|struct
name|ff_periodic_effect
block|{
name|uint16_t
name|waveform
decl_stmt|;
name|uint16_t
name|period
decl_stmt|;
comment|/* ms */
name|int16_t
name|magnitude
decl_stmt|;
comment|/* peak */
name|int16_t
name|offset
decl_stmt|;
comment|/* mean, roughly */
name|uint16_t
name|phase
decl_stmt|;
comment|/* horizontal shift */
name|struct
name|ff_envelope
name|envelope
decl_stmt|;
name|uint32_t
name|custom_len
decl_stmt|;
comment|/* FF_CUSTOM waveform only */
name|int16_t
modifier|*
name|custom_data
decl_stmt|;
comment|/* FF_CUSTOM waveform only */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ff_rumble_effect
block|{
name|uint16_t
name|strong_magnitude
decl_stmt|;
comment|/* magnitude of the heavy motor */
name|uint16_t
name|weak_magnitude
decl_stmt|;
comment|/* magnitude of the light motor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Force feedback effect types  */
end_comment

begin_define
define|#
directive|define
name|FF_RUMBLE
value|0x50
end_define

begin_define
define|#
directive|define
name|FF_PERIODIC
value|0x51
end_define

begin_define
define|#
directive|define
name|FF_CONSTANT
value|0x52
end_define

begin_define
define|#
directive|define
name|FF_SPRING
value|0x53
end_define

begin_define
define|#
directive|define
name|FF_FRICTION
value|0x54
end_define

begin_define
define|#
directive|define
name|FF_DAMPER
value|0x55
end_define

begin_define
define|#
directive|define
name|FF_INERTIA
value|0x56
end_define

begin_define
define|#
directive|define
name|FF_RAMP
value|0x57
end_define

begin_define
define|#
directive|define
name|FF_EFFECT_MIN
value|FF_RUMBLE
end_define

begin_define
define|#
directive|define
name|FF_EFFECT_MAX
value|FF_RAMP
end_define

begin_struct
struct|struct
name|ff_effect
block|{
name|uint16_t
name|type
decl_stmt|;
name|int16_t
name|id
decl_stmt|;
name|uint16_t
name|direction
decl_stmt|;
comment|/* [0 .. 360) degrees -> [0 .. 0x10000) */
name|struct
name|ff_trigger
name|trigger
decl_stmt|;
name|struct
name|ff_replay
name|replay
decl_stmt|;
union|union
block|{
name|struct
name|ff_constant_effect
name|constant
decl_stmt|;
name|struct
name|ff_ramp_effect
name|ramp
decl_stmt|;
name|struct
name|ff_periodic_effect
name|periodic
decl_stmt|;
name|struct
name|ff_condition_effect
name|condition
index|[
literal|2
index|]
decl_stmt|;
comment|/* One for each axis */
name|struct
name|ff_rumble_effect
name|rumble
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * force feedback device properties  */
end_comment

begin_define
define|#
directive|define
name|FF_GAIN
value|0x60
end_define

begin_define
define|#
directive|define
name|FF_AUTOCENTER
value|0x61
end_define

begin_define
define|#
directive|define
name|FF_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|FF_CNT
value|(FF_MAX+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EVDEV_INPUT_H */
end_comment

end_unit

