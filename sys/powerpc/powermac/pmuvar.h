begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Michael Lorenz  * Copyright (c) 2008 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PMUVAR_H
end_ifndef

begin_define
define|#
directive|define
name|PMUVAR_H
end_define

begin_comment
comment|/* PMU commands */
end_comment

begin_define
define|#
directive|define
name|PMU_POWER_CTRL0
value|0x10
end_define

begin_comment
comment|/* control power of some devices */
end_comment

begin_define
define|#
directive|define
name|PMU_POWER_CTRL
value|0x11
end_define

begin_comment
comment|/* control power of some devices */
end_comment

begin_define
define|#
directive|define
name|PMU_POWER_OFF
value|0x7e
end_define

begin_comment
comment|/* Turn Power off */
end_comment

begin_define
define|#
directive|define
name|PMU_RESET_CPU
value|0xd0
end_define

begin_comment
comment|/* Reset CPU */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_RTC
value|0x30
end_define

begin_comment
comment|/* Set realtime clock */
end_comment

begin_define
define|#
directive|define
name|PMU_READ_RTC
value|0x38
end_define

begin_comment
comment|/* Read realtime clock */
end_comment

begin_define
define|#
directive|define
name|PMU_WRITE_PRAM
value|0x32
end_define

begin_comment
comment|/* Write PRAM */
end_comment

begin_define
define|#
directive|define
name|PMU_READ_PRAM
value|0x3a
end_define

begin_comment
comment|/* Read PRAM */
end_comment

begin_define
define|#
directive|define
name|PMU_WRITE_NVRAM
value|0x33
end_define

begin_comment
comment|/* Write NVRAM */
end_comment

begin_define
define|#
directive|define
name|PMU_READ_NVRAM
value|0x3b
end_define

begin_comment
comment|/* Read NVRAM */
end_comment

begin_define
define|#
directive|define
name|PMU_EJECT_PCMCIA
value|0x4c
end_define

begin_comment
comment|/* Eject PCMCIA slot */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_BRIGHTNESS
value|0x41
end_define

begin_comment
comment|/* Set backlight brightness */
end_comment

begin_define
define|#
directive|define
name|PMU_READ_BRIGHTNESS
value|0xd9
end_define

begin_comment
comment|/* Read brightness button position */
end_comment

begin_define
define|#
directive|define
name|PMU_POWER_EVENTS
value|0x8f
end_define

begin_comment
comment|/* Send power-event commands to PMU */
end_comment

begin_define
define|#
directive|define
name|PMU_SYSTEM_READY
value|0xdf
end_define

begin_comment
comment|/* tell PMU we are awake */
end_comment

begin_define
define|#
directive|define
name|PMU_BATTERY_STATE
value|0x6b
end_define

begin_comment
comment|/* Read old battery state */
end_comment

begin_define
define|#
directive|define
name|PMU_SMART_BATTERY_STATE
value|0x6f
end_define

begin_comment
comment|/* Read battery state */
end_comment

begin_define
define|#
directive|define
name|PMU_ADB_CMD
value|0x20
end_define

begin_comment
comment|/* Send ADB packet */
end_comment

begin_define
define|#
directive|define
name|PMU_ADB_POLL_OFF
value|0x21
end_define

begin_comment
comment|/* Disable ADB auto-poll */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_VOL
value|0x40
end_define

begin_comment
comment|/* Set volume button position */
end_comment

begin_define
define|#
directive|define
name|PMU_GET_VOL
value|0x48
end_define

begin_comment
comment|/* Get volume button position */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_IMASK
value|0x70
end_define

begin_comment
comment|/* Set interrupt mask */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_ACK
value|0x78
end_define

begin_comment
comment|/* Read interrupt bits */
end_comment

begin_define
define|#
directive|define
name|PMU_CPU_SPEED
value|0x7d
end_define

begin_comment
comment|/* Control CPU speed on some models */
end_comment

begin_define
define|#
directive|define
name|PMU_SLEEP
value|0x7f
end_define

begin_comment
comment|/* Put CPU to sleep */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_POLL_MASK
value|0x86
end_define

begin_comment
comment|/* 					 * 16bit mask enables autopolling per 					 * device 					 */
end_comment

begin_define
define|#
directive|define
name|PMU_I2C_CMD
value|0x9a
end_define

begin_comment
comment|/* i2c commands */
end_comment

begin_define
define|#
directive|define
name|PMU_GET_LID_STATE
value|0xdc
end_define

begin_comment
comment|/* Report lid state */
end_comment

begin_define
define|#
directive|define
name|PMU_GET_VERSION
value|0xea
end_define

begin_comment
comment|/* Identify thyself */
end_comment

begin_define
define|#
directive|define
name|PMU_SET_SLEEPLED
value|0xee
end_define

begin_comment
comment|/* Set sleep LED on/off */
end_comment

begin_comment
comment|/* Bits in PMU interrupt and interrupt mask bytes */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_ADB_AUTO
value|0x04
end_define

begin_comment
comment|/* ADB autopoll, when PMU_INT_ADB */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_PCEJECT
value|0x04
end_define

begin_comment
comment|/* PC-card eject buttons */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_SNDBRT
value|0x08
end_define

begin_comment
comment|/* sound/brightness up/down buttons */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_ADB
value|0x10
end_define

begin_comment
comment|/* ADB autopoll or reply data */
end_comment

begin_define
define|#
directive|define
name|PMU_INT_BATTERY
value|0x20
end_define

begin_define
define|#
directive|define
name|PMU_INT_ENVIRONMENT
value|0x40
end_define

begin_define
define|#
directive|define
name|PMU_INT_TICK
value|0x80
end_define

begin_comment
comment|/* 1-second tick interrupt */
end_comment

begin_comment
comment|/* Bits to use with the PMU_POWER_CTRL0 command */
end_comment

begin_define
define|#
directive|define
name|PMU_POW0_ON
value|0x80
end_define

begin_comment
comment|/* OR this to power ON the device */
end_comment

begin_define
define|#
directive|define
name|PMU_POW0_OFF
value|0x00
end_define

begin_comment
comment|/* leave bit 7 to 0 to power it OFF */
end_comment

begin_define
define|#
directive|define
name|PMU_POW0_HARD_DRIVE
value|0x04
end_define

begin_comment
comment|/* wallstreet/lombard? */
end_comment

begin_comment
comment|/* Bits to use with the PMU_POWER_CTRL command */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_ON
value|0x80
end_define

begin_comment
comment|/* OR this to power ON the device */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_OFF
value|0x00
end_define

begin_comment
comment|/* leave bit 7 to 0 to power it OFF */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_BACKLIGHT
value|0x01
end_define

begin_comment
comment|/* backlight power */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_CHARGER
value|0x02
end_define

begin_comment
comment|/* battery charger power */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_IRLED
value|0x04
end_define

begin_comment
comment|/* IR led power (on wallstreet) */
end_comment

begin_define
define|#
directive|define
name|PMU_POW_MEDIABAY
value|0x08
end_define

begin_comment
comment|/* media bay power (wallstreet/lombard ?) */
end_comment

begin_comment
comment|/* Bits from PMU_GET_LID_STATE or PMU_INT_ENVIRONMENT on core99 */
end_comment

begin_define
define|#
directive|define
name|PMU_ENV_LID_CLOSED
value|0x01
end_define

begin_comment
comment|/* The lid is closed */
end_comment

begin_comment
comment|/* PMU PMU_POWER_EVENTS commands */
end_comment

begin_enum
enum|enum
block|{
name|PMU_PWR_GET_POWERUP_EVENTS
init|=
literal|0x00
block|,
name|PMU_PWR_SET_POWERUP_EVENTS
init|=
literal|0x01
block|,
name|PMU_PWR_CLR_POWERUP_EVENTS
init|=
literal|0x02
block|,
name|PMU_PWR_GET_WAKEUP_EVENTS
init|=
literal|0x03
block|,
name|PMU_PWR_SET_WAKEUP_EVENTS
init|=
literal|0x04
block|,
name|PMU_PWR_CLR_WAKEUP_EVENTS
init|=
literal|0x05
block|, }
enum|;
end_enum

begin_comment
comment|/* PMU Power Information */
end_comment

begin_define
define|#
directive|define
name|PMU_PWR_AC_PRESENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PMU_PWR_BATT_CHARGING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PMU_PWR_BATT_PRESENT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PMU_PWR_BATT_FULL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PMU_PWR_PCHARGE_RESET
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PMU_PWR_BATT_EXIST
value|(1<< 7)
end_define

begin_comment
comment|/* I2C related definitions */
end_comment

begin_define
define|#
directive|define
name|PMU_I2C_MODE_SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|PMU_I2C_MODE_STDSUB
value|1
end_define

begin_define
define|#
directive|define
name|PMU_I2C_MODE_COMBINED
value|2
end_define

begin_define
define|#
directive|define
name|PMU_I2C_BUS_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|PMU_I2C_BUS_SYSCLK
value|1
end_define

begin_define
define|#
directive|define
name|PMU_I2C_BUS_POWER
value|2
end_define

begin_define
define|#
directive|define
name|PMU_I2C_STATUS_OK
value|0
end_define

begin_define
define|#
directive|define
name|PMU_I2C_STATUS_DATAREAD
value|1
end_define

begin_define
define|#
directive|define
name|PMU_I2C_STATUS_BUSY
value|0xfe
end_define

begin_comment
comment|/* Power events wakeup bits */
end_comment

begin_enum
enum|enum
block|{
name|PMU_PWR_WAKEUP_KEY
init|=
literal|0x01
block|,
comment|/* Wake on key press */
name|PMU_PWR_WAKEUP_AC_INSERT
init|=
literal|0x02
block|,
comment|/* Wake on AC adapter plug */
name|PMU_PWR_WAKEUP_AC_CHANGE
init|=
literal|0x04
block|,
name|PMU_PWR_WAKEUP_LID_OPEN
init|=
literal|0x08
block|,
name|PMU_PWR_WAKEUP_RING
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PMU_NOTREADY
value|0x1
end_define

begin_comment
comment|/* has not been initialized yet */
end_comment

begin_define
define|#
directive|define
name|PMU_IDLE
value|0x2
end_define

begin_comment
comment|/* the bus is currently idle */
end_comment

begin_define
define|#
directive|define
name|PMU_OUT
value|0x3
end_define

begin_comment
comment|/* sending out a command */
end_comment

begin_define
define|#
directive|define
name|PMU_IN
value|0x4
end_define

begin_comment
comment|/* receiving data */
end_comment

begin_struct
struct|struct
name|pmu_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|sc_memrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_memr
decl_stmt|;
name|int
name|sc_irqrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|struct
name|mtx
name|sc_mutex
decl_stmt|;
name|device_t
name|adb_bus
decl_stmt|;
specifier|volatile
name|int
name|sc_autopoll
decl_stmt|;
name|int
name|sc_batteries
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_leddev
decl_stmt|;
name|int
name|lid_closed
decl_stmt|;
name|uint8_t
name|saved_regs
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmu_battstate
block|{
name|int
name|state
decl_stmt|;
name|int
name|charge
decl_stmt|;
name|int
name|maxcharge
decl_stmt|;
name|int
name|current
decl_stmt|;
name|int
name|voltage
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|pmu_set_speed
parameter_list|(
name|int
name|low_speed
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PMUVAR_H */
end_comment

end_unit

