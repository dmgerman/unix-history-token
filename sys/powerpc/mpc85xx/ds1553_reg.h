begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006-2008 Semihalf, Grzegorz Bernacki  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_RTC_DS1553_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_RTC_DS1553_H_
end_define

begin_comment
comment|/* DS1553 registers */
end_comment

begin_define
define|#
directive|define
name|DS1553_NVRAM_SIZE
value|0x1ff0
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_FLAGS
value|0x1ff0
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_ALARM_SECONDS
value|0x1ff2
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_ALARM_MINUTES
value|0x1ff3
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_ALARM_HOURS
value|0x1ff4
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_ALARM_DATE
value|0x1ff5
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_INTERRUPTS
value|0x1ff6
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_WATCHDOG
value|0x1ff7
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_CONTROL
value|0x1ff8
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_SECONDS
value|0x1ff9
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_MINUTES
value|0x1ffa
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_HOURS
value|0x1ffb
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_DAYOFWEEK
value|0x1ffc
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_DATE
value|0x1ffd
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_MONTH
value|0x1ffe
end_define

begin_define
define|#
directive|define
name|DS1553_OFF_YEAR
value|0x1fff
end_define

begin_comment
comment|/* dayofweek register's bits */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_FREQ_TEST
value|0x40
end_define

begin_comment
comment|/* frequency test bit */
end_comment

begin_comment
comment|/* seconds register's bit */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_OSC
value|0x80
end_define

begin_comment
comment|/* oscillator start/stop bit */
end_comment

begin_comment
comment|/* control register's bits */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_WRITE
value|0x80
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_READ
value|0x40
end_define

begin_comment
comment|/* read */
end_comment

begin_comment
comment|/* watchdog register's bits */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_WATCHDOG
value|0x80
end_define

begin_comment
comment|/* watchdog steering bit */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BMB4
value|0x40
end_define

begin_comment
comment|/* watchdog multiplier bit4 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BMB3
value|0x20
end_define

begin_comment
comment|/* watchdog multiplier bit3 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BMB2
value|0x10
end_define

begin_comment
comment|/* watchdog multiplier bit2 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BMB1
value|0x8
end_define

begin_comment
comment|/* watchdog multiplier bit1 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BMB0
value|0x4
end_define

begin_comment
comment|/* watchdog multiplier bit0 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_RB1
value|0x2
end_define

begin_comment
comment|/* watchdog resolution bit1 */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_RB0
value|0x1
end_define

begin_comment
comment|/* watchdog resolution bit0 */
end_comment

begin_comment
comment|/* alarm seconds/minutes/hours/date register's bit */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_AM
value|0x80
end_define

begin_comment
comment|/* alarm mask bit */
end_comment

begin_comment
comment|/* flag register's bits */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_BLF
value|0x10
end_define

begin_comment
comment|/* battery flag */
end_comment

begin_define
define|#
directive|define
name|DS1553_BIT_WF
value|0x80
end_define

begin_comment
comment|/* watchdog flag */
end_comment

begin_comment
comment|/* register's mask */
end_comment

begin_define
define|#
directive|define
name|DS1553_MASK_MONTH
value|0x1f
end_define

begin_define
define|#
directive|define
name|DS1553_MASK_DATE
value|0x3f
end_define

begin_define
define|#
directive|define
name|DS1553_MASK_DAYOFWEEK
value|0x7
end_define

begin_define
define|#
directive|define
name|DS1553_MASK_HOUR
value|0x3f
end_define

begin_define
define|#
directive|define
name|DS1553_MASK_MINUTES
value|0x7f
end_define

begin_define
define|#
directive|define
name|DS1553_MASK_SECONDS
value|0x7f
end_define

begin_struct
struct|struct
name|ds1553_softc
block|{
name|bus_space_tag_t
name|sc_bst
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sc_bsh
decl_stmt|;
comment|/* bus space handle */
name|int
name|rid
decl_stmt|;
comment|/* resource id */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* hardware mutex */
name|uint32_t
name|year_offset
decl_stmt|;
comment|/* read/write functions */
name|uint8_t
function_decl|(
modifier|*
name|sc_read
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_write
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* device interface */
end_comment

begin_function_decl
name|int
name|ds1553_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* clock interface */
end_comment

begin_function_decl
name|int
name|ds1553_gettime
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ds1553_settime
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_RTC_DS1553_H_ */
end_comment

end_unit

