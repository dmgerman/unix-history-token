begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe<takawata@shidahara1.planet.sci.kobe-u.ac.jp>  * Copyright (c) 1999 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/* Generic Address structure */
end_comment

begin_struct
struct|struct
name|ACPIgas
block|{
name|u_int8_t
name|address_space_id
decl_stmt|;
define|#
directive|define
name|ACPI_GAS_MEMORY
value|0
define|#
directive|define
name|ACPI_GAS_IO
value|1
define|#
directive|define
name|ACPI_GAS_PCI
value|2
define|#
directive|define
name|ACPI_GAS_EMBEDDED
value|3
define|#
directive|define
name|ACPI_GAS_SMBUS
value|4
define|#
directive|define
name|ACPI_GAS_FIXED
value|0x7f
name|u_int8_t
name|register_bit_width
decl_stmt|;
name|u_int8_t
name|register_bit_offset
decl_stmt|;
name|u_int8_t
name|res
decl_stmt|;
name|u_int64_t
name|address
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Root System Description Pointer */
end_comment

begin_struct
struct|struct
name|ACPIrsdp
block|{
name|u_char
name|signature
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|sum
decl_stmt|;
name|u_char
name|oem
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|res
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* System Description Table */
end_comment

begin_struct
struct|struct
name|ACPIsdt
block|{
name|u_char
name|signature
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|u_char
name|rev
decl_stmt|;
name|u_char
name|check
decl_stmt|;
name|u_char
name|oemid
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|oemtblid
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|oemrev
decl_stmt|;
name|u_char
name|creator
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|crerev
decl_stmt|;
define|#
directive|define
name|SIZEOF_SDT_HDR
value|36
comment|/* struct size except body */
name|u_int32_t
name|body
index|[
literal|1
index|]
decl_stmt|;
comment|/* This member should be casted */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Fixed ACPI Description Table (body) */
end_comment

begin_struct
struct|struct
name|FACPbody
block|{
name|u_int32_t
name|facs_ptr
decl_stmt|;
name|u_int32_t
name|dsdt_ptr
decl_stmt|;
name|u_int8_t
name|int_model
decl_stmt|;
define|#
directive|define
name|ACPI_FACP_INTMODEL_PIC
value|0
comment|/* Standard PC-AT PIC */
define|#
directive|define
name|ACPI_FACP_INTMODEL_APIC
value|1
comment|/* Multiple APIC */
name|u_char
name|reserved1
decl_stmt|;
name|u_int16_t
name|sci_int
decl_stmt|;
name|u_int32_t
name|smi_cmd
decl_stmt|;
name|u_int8_t
name|acpi_enable
decl_stmt|;
name|u_int8_t
name|acpi_disable
decl_stmt|;
name|u_int8_t
name|s4biosreq
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int32_t
name|pm1a_evt_blk
decl_stmt|;
name|u_int32_t
name|pm1b_evt_blk
decl_stmt|;
name|u_int32_t
name|pm1a_cnt_blk
decl_stmt|;
name|u_int32_t
name|pm1b_cnt_blk
decl_stmt|;
name|u_int32_t
name|pm2_cnt_blk
decl_stmt|;
name|u_int32_t
name|pm_tmr_blk
decl_stmt|;
name|u_int32_t
name|gpe0_blk
decl_stmt|;
name|u_int32_t
name|gpe1_blk
decl_stmt|;
name|u_int8_t
name|pm1_evt_len
decl_stmt|;
name|u_int8_t
name|pm1_cnt_len
decl_stmt|;
name|u_int8_t
name|pm2_cnt_len
decl_stmt|;
name|u_int8_t
name|pm_tmr_len
decl_stmt|;
name|u_int8_t
name|gpe0_len
decl_stmt|;
name|u_int8_t
name|gpe1_len
decl_stmt|;
name|u_int8_t
name|gpe1_base
decl_stmt|;
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int16_t
name|p_lvl2_lat
decl_stmt|;
name|u_int16_t
name|p_lvl3_lat
decl_stmt|;
name|u_int16_t
name|flush_size
decl_stmt|;
name|u_int16_t
name|flush_stride
decl_stmt|;
name|u_int8_t
name|duty_off
decl_stmt|;
name|u_int8_t
name|duty_width
decl_stmt|;
name|u_int8_t
name|day_alrm
decl_stmt|;
name|u_int8_t
name|mon_alrm
decl_stmt|;
name|u_int8_t
name|century
decl_stmt|;
name|u_int16_t
name|iapc_boot_arch
decl_stmt|;
name|u_char
name|reserved4
index|[
literal|1
index|]
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|ACPI_FACP_FLAG_WBINVD
value|1
comment|/* WBINVD is correctly supported */
define|#
directive|define
name|ACPI_FACP_FLAG_WBINVD_FLUSH
value|2
comment|/* WBINVD flushes caches */
define|#
directive|define
name|ACPI_FACP_FLAG_PROC_C1
value|4
comment|/* C1 power state supported */
define|#
directive|define
name|ACPI_FACP_FLAG_P_LVL2_UP
value|8
comment|/* C2 power state works on SMP */
define|#
directive|define
name|ACPI_FACP_FLAG_PWR_BUTTON
value|16
comment|/* Power button uses control method */
define|#
directive|define
name|ACPI_FACP_FLAG_SLP_BUTTON
value|32
comment|/* Sleep button uses control method */
define|#
directive|define
name|ACPI_FACP_FLAG_FIX_RTC
value|64
comment|/* RTC wakeup not supported */
define|#
directive|define
name|ACPI_FACP_FLAG_RTC_S4
value|128
comment|/* RTC can wakeup from S4 state */
define|#
directive|define
name|ACPI_FACP_FLAG_TMR_VAL_EXT
value|256
comment|/* TMR_VAL is 32bit */
define|#
directive|define
name|ACPI_FACP_FLAG_DCK_CAP
value|512
comment|/* Can support docking */
name|struct
name|ACPIgas
name|reset_reg
decl_stmt|;
name|u_int8_t
name|reset_value
decl_stmt|;
name|u_int8_t
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|u_int64_t
name|x_firmware_ctrl
decl_stmt|;
name|u_int64_t
name|x_dsdt
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm1a_evt_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm1b_evt_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm1a_cnt_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm1b_cnt_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm2_cnt_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_pm_tmr_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_gpe0_blk
decl_stmt|;
name|struct
name|ACPIgas
name|x_gpe1_blk
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Firmware ACPI Control Structure */
end_comment

begin_struct
struct|struct
name|FACS
block|{
name|u_char
name|signature
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|u_char
name|hard_sig
index|[
literal|4
index|]
decl_stmt|;
comment|/* 	 * NOTE This should be filled with physical address below 1MB!! 	 * sigh.... 	 */
name|u_int32_t
name|firm_wake_vec
decl_stmt|;
name|u_int32_t
name|g_lock
decl_stmt|;
comment|/* bit field */
comment|/* 5.2.6.1 Global Lock */
define|#
directive|define
name|ACPI_GLOBAL_LOCK_PENDING
value|1
define|#
directive|define
name|ACPI_GLOBAL_LOCK_OWNED
value|2
name|u_int32_t
name|flags
decl_stmt|;
comment|/* bit field */
define|#
directive|define
name|ACPI_FACS_FLAG_S4BIOS_F
value|1
comment|/* Supports S4BIOS_SEQ */
name|char
name|reserved
index|[
literal|40
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Bits for ACPI registers  */
end_comment

begin_comment
comment|/* Power Management 1 Event Regisers (4.7.3.1 Table 4-9, 4-10) */
end_comment

begin_comment
comment|/* these bits are for status and enable regiser */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM1_TMR_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_GBL_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_PWRBTN_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_SLPBTN_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_RTC_EN
value|0x0400
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_ALL_ENABLE_BITS
value|0x0721
end_define

begin_comment
comment|/* these bits are for status regiser only */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM1_BM_STS
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_WAK_STS
value|0x8000
end_define

begin_comment
comment|/* Power Management 1 Control Regisers (4.7.3.2 Table 4-11) */
end_comment

begin_define
define|#
directive|define
name|ACPI_CNT_SCI_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_CNT_BM_RLD
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_CNT_GBL_RLS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACPI_CNT_SLP_TYPX
value|0x1c00
end_define

begin_define
define|#
directive|define
name|ACPI_CNT_SLP_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|ACPI_CNT_SET_SLP_TYP
parameter_list|(
name|x
parameter_list|)
value|(x<< 10)
end_define

begin_comment
comment|/* Power Management Timer (4.7.3.3 Table 4-12) */
end_comment

begin_comment
comment|/* Not yet */
end_comment

begin_comment
comment|/* Power Management 2 Control (4.7.3.4 Table 4-13) */
end_comment

begin_comment
comment|/* Not yet */
end_comment

begin_comment
comment|/* Processor Register Block (4.7.3.5 Table 4-14, 4-15, 4-16) */
end_comment

begin_comment
comment|/* Not yet */
end_comment

begin_comment
comment|/* Sleep state constants */
end_comment

begin_define
define|#
directive|define
name|ACPI_S_STATE_S0
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_S1
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_S2
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_S3
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_S4
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_S5
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure for System State Package (7.5.2).  */
end_comment

begin_struct
struct|struct
name|acpi_system_state_package
block|{
struct|struct
block|{
name|u_int8_t
name|slp_typ_a
decl_stmt|;
comment|/* 3-bit only. */
name|u_int8_t
name|slp_typ_b
decl_stmt|;
comment|/* (4.7.3.2.1) */
block|}
name|mode
index|[
literal|6
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACPI_UNSUPPORTSLPTYP
value|0xff
end_define

begin_comment
comment|/* unsupported sleeping type */
end_comment

begin_comment
comment|/*  * ACPICA compatibility  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IA64
end_ifdef

begin_typedef
typedef|typedef
name|signed
name|char
name|INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|INT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT64
name|NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_TBLPTR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_IA64 */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT32
name|NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_TBLPTR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IA64 */
end_comment

begin_comment
comment|/* common types */
end_comment

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_IO_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_STATUS
typedef|;
end_typedef

begin_comment
comment|/*   * Exceptions returned by external ACPI interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SUCCESS
parameter_list|(
name|a
parameter_list|)
value|(!(a))
end_define

begin_define
define|#
directive|define
name|ACPI_FAILURE
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|AE_OK
value|(ACPI_STATUS) 0x0000
end_define

begin_define
define|#
directive|define
name|AE_CTRL_RETURN_VALUE
value|(ACPI_STATUS) 0x0001
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PENDING
value|(ACPI_STATUS) 0x0002
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TERMINATE
value|(ACPI_STATUS) 0x0003
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TRUE
value|(ACPI_STATUS) 0x0004
end_define

begin_define
define|#
directive|define
name|AE_CTRL_FALSE
value|(ACPI_STATUS) 0x0005
end_define

begin_define
define|#
directive|define
name|AE_CTRL_DEPTH
value|(ACPI_STATUS) 0x0006
end_define

begin_define
define|#
directive|define
name|AE_CTRL_RESERVED
value|(ACPI_STATUS) 0x0007
end_define

begin_define
define|#
directive|define
name|AE_AML_ERROR
value|(ACPI_STATUS) 0x0008
end_define

begin_define
define|#
directive|define
name|AE_AML_PARSE
value|(ACPI_STATUS) 0x0009
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_OPCODE
value|(ACPI_STATUS) 0x000A
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_OPERAND
value|(ACPI_STATUS) 0x000B
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_TYPE
value|(ACPI_STATUS) 0x000C
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_VALUE
value|(ACPI_STATUS) 0x000D
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_LOCAL
value|(ACPI_STATUS) 0x000E
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ARG
value|(ACPI_STATUS) 0x000F
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ELEMENT
value|(ACPI_STATUS) 0x0010
end_define

begin_define
define|#
directive|define
name|AE_AML_NUMERIC_OVERFLOW
value|(ACPI_STATUS) 0x0011
end_define

begin_define
define|#
directive|define
name|AE_AML_REGION_LIMIT
value|(ACPI_STATUS) 0x0012
end_define

begin_define
define|#
directive|define
name|AE_AML_BUFFER_LIMIT
value|(ACPI_STATUS) 0x0013
end_define

begin_define
define|#
directive|define
name|AE_AML_PACKAGE_LIMIT
value|(ACPI_STATUS) 0x0014
end_define

begin_define
define|#
directive|define
name|AE_AML_DIVIDE_BY_ZERO
value|(ACPI_STATUS) 0x0015
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_NAME
value|(ACPI_STATUS) 0x0016
end_define

begin_define
define|#
directive|define
name|AE_AML_NAME_NOT_FOUND
value|(ACPI_STATUS) 0x0017
end_define

begin_define
define|#
directive|define
name|AE_AML_INTERNAL
value|(ACPI_STATUS) 0x0018
end_define

begin_define
define|#
directive|define
name|AE_AML_RESERVED
value|(ACPI_STATUS) 0x0019
end_define

begin_define
define|#
directive|define
name|AE_ERROR
value|(ACPI_STATUS) 0x001A
end_define

begin_define
define|#
directive|define
name|AE_NO_ACPI_TABLES
value|(ACPI_STATUS) 0x001B
end_define

begin_define
define|#
directive|define
name|AE_NO_NAMESPACE
value|(ACPI_STATUS) 0x001C
end_define

begin_define
define|#
directive|define
name|AE_NO_MEMORY
value|(ACPI_STATUS) 0x001D
end_define

begin_define
define|#
directive|define
name|AE_BAD_SIGNATURE
value|(ACPI_STATUS) 0x001E
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEADER
value|(ACPI_STATUS) 0x001F
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHECKSUM
value|(ACPI_STATUS) 0x0020
end_define

begin_define
define|#
directive|define
name|AE_BAD_PARAMETER
value|(ACPI_STATUS) 0x0021
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHARACTER
value|(ACPI_STATUS) 0x0022
end_define

begin_define
define|#
directive|define
name|AE_BAD_PATHNAME
value|(ACPI_STATUS) 0x0023
end_define

begin_define
define|#
directive|define
name|AE_BAD_DATA
value|(ACPI_STATUS) 0x0024
end_define

begin_define
define|#
directive|define
name|AE_BAD_ADDRESS
value|(ACPI_STATUS) 0x0025
end_define

begin_define
define|#
directive|define
name|AE_NOT_FOUND
value|(ACPI_STATUS) 0x0026
end_define

begin_define
define|#
directive|define
name|AE_NOT_EXIST
value|(ACPI_STATUS) 0x0027
end_define

begin_define
define|#
directive|define
name|AE_EXIST
value|(ACPI_STATUS) 0x0028
end_define

begin_define
define|#
directive|define
name|AE_TYPE
value|(ACPI_STATUS) 0x0029
end_define

begin_define
define|#
directive|define
name|AE_NULL_OBJECT
value|(ACPI_STATUS) 0x002A
end_define

begin_define
define|#
directive|define
name|AE_NULL_ENTRY
value|(ACPI_STATUS) 0x002B
end_define

begin_define
define|#
directive|define
name|AE_BUFFER_OVERFLOW
value|(ACPI_STATUS) 0x002C
end_define

begin_define
define|#
directive|define
name|AE_STACK_OVERFLOW
value|(ACPI_STATUS) 0x002D
end_define

begin_define
define|#
directive|define
name|AE_STACK_UNDERFLOW
value|(ACPI_STATUS) 0x002E
end_define

begin_define
define|#
directive|define
name|AE_NOT_IMPLEMENTED
value|(ACPI_STATUS) 0x002F
end_define

begin_define
define|#
directive|define
name|AE_VERSION_MISMATCH
value|(ACPI_STATUS) 0x0030
end_define

begin_define
define|#
directive|define
name|AE_SUPPORT
value|(ACPI_STATUS) 0x0031
end_define

begin_define
define|#
directive|define
name|AE_SHARE
value|(ACPI_STATUS) 0x0032
end_define

begin_define
define|#
directive|define
name|AE_LIMIT
value|(ACPI_STATUS) 0x0033
end_define

begin_define
define|#
directive|define
name|AE_TIME
value|(ACPI_STATUS) 0x0034
end_define

begin_define
define|#
directive|define
name|AE_UNKNOWN_STATUS
value|(ACPI_STATUS) 0x0035
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_STATUS
value|(ACPI_STATUS) 0x0035
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_STATUS
value|(ACPI_STATUS) 0x0036
end_define

begin_comment
comment|/*  * ACPICA Osd family functions  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NO_OSDFUNC_INLINE
end_ifdef

begin_function_decl
name|ACPI_STATUS
name|OsdMapMemory
parameter_list|(
name|void
modifier|*
parameter_list|,
name|UINT32
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsdUnMapMemory
parameter_list|(
name|void
modifier|*
parameter_list|,
name|UINT32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|OsdIn8
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|OsdIn16
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|OsdIn32
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsdOut8
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|,
name|UINT8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsdOut16
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|,
name|UINT16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OsdOut32
parameter_list|(
name|ACPI_IO_ADDRESS
parameter_list|,
name|UINT32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdReadPciCfgByte
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdReadPciCfgWord
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdReadPciCfgDword
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdWritePciCfgByte
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdWritePciCfgWord
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OsdWritePciCfgDword
parameter_list|(
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|,
name|UINT32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_OSDFUNC_INLINE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function_decl
name|void
modifier|*
name|acpi_map_physical
parameter_list|(
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ACPIrsdp
modifier|*
name|acpi_find_rsd_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_checksum
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ACPIsdt
modifier|*
name|acpi_map_sdt
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_print_rsd_ptr
parameter_list|(
name|struct
name|ACPIrsdp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_print_sdt
parameter_list|(
name|struct
name|ACPIsdt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_print_rsdt
parameter_list|(
name|struct
name|ACPIsdt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_print_facp
parameter_list|(
name|struct
name|FACPbody
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_print_dsdt
parameter_list|(
name|struct
name|ACPIsdt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

