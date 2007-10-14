begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: lm78var.h,v 1.12 2007/05/25 02:26:43 cnst Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005, 2006 Mark Kettenis  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * National Semiconductor LM78/79/81 registers  */
end_comment

begin_define
define|#
directive|define
name|LM_POST_RAM
value|0x00
end_define

begin_comment
comment|/* POST RAM occupies 0x00 -- 0x1f */
end_comment

begin_define
define|#
directive|define
name|LM_VALUE_RAM
value|0x20
end_define

begin_comment
comment|/* Value RAM occupies 0x20 -- 0x3f */
end_comment

begin_define
define|#
directive|define
name|LM_FAN1
value|0x28
end_define

begin_comment
comment|/* FAN1 reading */
end_comment

begin_define
define|#
directive|define
name|LM_FAN2
value|0x29
end_define

begin_comment
comment|/* FAN2 reading */
end_comment

begin_define
define|#
directive|define
name|LM_FAN3
value|0x2a
end_define

begin_comment
comment|/* FAN3 reading */
end_comment

begin_define
define|#
directive|define
name|LM_CONFIG
value|0x40
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|LM_ISR1
value|0x41
end_define

begin_comment
comment|/* Interrupt Status 1 */
end_comment

begin_define
define|#
directive|define
name|LM_ISR2
value|0x42
end_define

begin_comment
comment|/* Interrupt Status 2 */
end_comment

begin_define
define|#
directive|define
name|LM_SMI1
value|0x43
end_define

begin_comment
comment|/* SMI# Mask 1 */
end_comment

begin_define
define|#
directive|define
name|LM_SMI2
value|0x44
end_define

begin_comment
comment|/* SMI# Mask 2 */
end_comment

begin_define
define|#
directive|define
name|LM_NMI1
value|0x45
end_define

begin_comment
comment|/* NMI Mask 1 */
end_comment

begin_define
define|#
directive|define
name|LM_NMI2
value|0x46
end_define

begin_comment
comment|/* NMI Mask 2 */
end_comment

begin_define
define|#
directive|define
name|LM_VIDFAN
value|0x47
end_define

begin_comment
comment|/* VID/Fan Divisor */
end_comment

begin_define
define|#
directive|define
name|LM_SBUSADDR
value|0x48
end_define

begin_comment
comment|/* Serial Bus Address */
end_comment

begin_define
define|#
directive|define
name|LM_CHIPID
value|0x49
end_define

begin_comment
comment|/* Chip Reset/ID */
end_comment

begin_comment
comment|/* Chip IDs */
end_comment

begin_define
define|#
directive|define
name|LM_CHIPID_LM78
value|0x00
end_define

begin_define
define|#
directive|define
name|LM_CHIPID_LM78J
value|0x40
end_define

begin_define
define|#
directive|define
name|LM_CHIPID_LM79
value|0xC0
end_define

begin_define
define|#
directive|define
name|LM_CHIPID_LM81
value|0x80
end_define

begin_define
define|#
directive|define
name|LM_CHIPID_MASK
value|0xfe
end_define

begin_comment
comment|/*  * Winbond registers  *  * Several models exists.  The W83781D is mostly compatible with the  * LM78, but has two extra temperatures.  Later models add extra  * voltage sensors, fans and bigger fan divisors to accomodate slow  * running fans.  To accomodate the extra sensors some models have  * different memory banks.  */
end_comment

begin_define
define|#
directive|define
name|WB_T23ADDR
value|0x4a
end_define

begin_comment
comment|/* Temperature 2 and 3 Serial Bus Address */
end_comment

begin_define
define|#
directive|define
name|WB_PIN
value|0x4b
end_define

begin_comment
comment|/* Pin Control */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL
value|0x4e
end_define

begin_comment
comment|/* Bank Select */
end_comment

begin_define
define|#
directive|define
name|WB_VENDID
value|0x4f
end_define

begin_comment
comment|/* Vendor ID */
end_comment

begin_comment
comment|/* Bank 0 regs */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_CHIPID
value|0x58
end_define

begin_comment
comment|/* Chip ID */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_FAN45
value|0x5c
end_define

begin_comment
comment|/* Fan 4/5 Divisor Control (W83791D only) */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_VBAT
value|0x5d
end_define

begin_comment
comment|/* VBAT Monitor Control */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_FAN4
value|0xba
end_define

begin_comment
comment|/* Fan 4 reading (W83791D only) */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_FAN5
value|0xbb
end_define

begin_comment
comment|/* Fan 5 reading (W83791D only) */
end_comment

begin_define
define|#
directive|define
name|WB_BANK0_CONFIG
value|0x18
end_define

begin_comment
comment|/* VRM& OVT Config (W83627THF/W83637HF) */
end_comment

begin_comment
comment|/* Bank 1 registers */
end_comment

begin_define
define|#
directive|define
name|WB_BANK1_T2H
value|0x50
end_define

begin_comment
comment|/* Temperature 2 High Byte */
end_comment

begin_define
define|#
directive|define
name|WB_BANK1_T2L
value|0x51
end_define

begin_comment
comment|/* Temperature 2 Low Byte */
end_comment

begin_comment
comment|/* Bank 2 registers */
end_comment

begin_define
define|#
directive|define
name|WB_BANK2_T3H
value|0x50
end_define

begin_comment
comment|/* Temperature 3 High Byte */
end_comment

begin_define
define|#
directive|define
name|WB_BANK2_T3L
value|0x51
end_define

begin_comment
comment|/* Temperature 3 Low Byte */
end_comment

begin_comment
comment|/* Bank 4 registers (W83782D/W83627HF and later models only) */
end_comment

begin_define
define|#
directive|define
name|WB_BANK4_T1OFF
value|0x54
end_define

begin_comment
comment|/* Temperature 1 Offset */
end_comment

begin_define
define|#
directive|define
name|WB_BANK4_T2OFF
value|0x55
end_define

begin_comment
comment|/* Temperature 2 Offset */
end_comment

begin_define
define|#
directive|define
name|WB_BANK4_T3OFF
value|0x56
end_define

begin_comment
comment|/* Temperature 3 Offset */
end_comment

begin_comment
comment|/* Bank 5 registers (W83782D/W83627HF and later models only) */
end_comment

begin_define
define|#
directive|define
name|WB_BANK5_5VSB
value|0x50
end_define

begin_comment
comment|/* 5VSB reading */
end_comment

begin_define
define|#
directive|define
name|WB_BANK5_VBAT
value|0x51
end_define

begin_comment
comment|/* VBAT reading */
end_comment

begin_comment
comment|/* Bank selection */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B0
value|0x00
end_define

begin_comment
comment|/* Bank 0 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B1
value|0x01
end_define

begin_comment
comment|/* Bank 1 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B2
value|0x02
end_define

begin_comment
comment|/* Bank 2 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B3
value|0x03
end_define

begin_comment
comment|/* Bank 3 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B4
value|0x04
end_define

begin_comment
comment|/* Bank 4 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_B5
value|0x05
end_define

begin_comment
comment|/* Bank 5 */
end_comment

begin_define
define|#
directive|define
name|WB_BANKSEL_HBAC
value|0x80
end_define

begin_comment
comment|/* Register 0x4f High Byte Access */
end_comment

begin_comment
comment|/* Vendor IDs */
end_comment

begin_define
define|#
directive|define
name|WB_VENDID_WINBOND
value|0x5ca3
end_define

begin_comment
comment|/* Winbond */
end_comment

begin_define
define|#
directive|define
name|WB_VENDID_ASUS
value|0x12c3
end_define

begin_comment
comment|/* ASUS */
end_comment

begin_comment
comment|/* Chip IDs */
end_comment

begin_define
define|#
directive|define
name|WB_CHIPID_W83781D
value|0x10
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83781D_2
value|0x11
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83627HF
value|0x21
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_AS99127F
value|0x31
end_define

begin_comment
comment|/* Asus W83781D clone */
end_comment

begin_define
define|#
directive|define
name|WB_CHIPID_W83782D
value|0x30
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83783S
value|0x40
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83697HF
value|0x60
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83791D
value|0x71
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83791SD
value|0x72
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83792D
value|0x7a
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83637HF
value|0x80
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83627THF
value|0x90
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83627EHF
value|0xa1
end_define

begin_define
define|#
directive|define
name|WB_CHIPID_W83627DHG
value|0xc1
end_define

begin_comment
comment|/* Config bits */
end_comment

begin_define
define|#
directive|define
name|WB_CONFIG_VMR9
value|0x01
end_define

begin_comment
comment|/* Reference voltage (mV) */
end_comment

begin_define
define|#
directive|define
name|WB_VREF
value|3600
end_define

begin_define
define|#
directive|define
name|WB_W83627EHF_VREF
value|2048
end_define

begin_define
define|#
directive|define
name|WB_MAX_SENSORS
value|19
end_define

begin_struct_decl
struct_decl|struct
name|lm_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|lm_sensor
block|{
name|char
modifier|*
name|desc
decl_stmt|;
name|enum
name|sensor_type
name|type
decl_stmt|;
name|u_int8_t
name|bank
decl_stmt|;
name|u_int8_t
name|reg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|refresh
function_decl|)
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|rfact
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lm_softc
block|{
name|struct
name|device
modifier|*
name|sc_dev
decl_stmt|;
name|struct
name|ksensor
name|sensors
index|[
name|WB_MAX_SENSORS
index|]
decl_stmt|;
name|struct
name|ksensordev
name|sensordev
decl_stmt|;
name|struct
name|lm_sensor
modifier|*
name|lm_sensors
decl_stmt|;
name|u_int
name|numsensors
decl_stmt|;
name|void
function_decl|(
modifier|*
name|refresh_sensor_data
function_decl|)
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|)
function_decl|;
name|u_int8_t
function_decl|(
modifier|*
name|lm_readreg
function_decl|)
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lm_writereg
function_decl|)
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|u_int8_t
name|sbusaddr
decl_stmt|;
name|u_int8_t
name|chipid
decl_stmt|;
name|u_int8_t
name|vrm9
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|lm_probe
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_attach
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lm_detach
parameter_list|(
name|struct
name|lm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

