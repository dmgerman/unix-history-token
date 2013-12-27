begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Adaptec Inc.  * All rights reserved.  *  * Written by: David Jeffery  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  *   IPS CONSTANTS  */
end_comment

begin_define
define|#
directive|define
name|IPS_VENDOR_ID
value|0x1014
end_define

begin_define
define|#
directive|define
name|IPS_VENDOR_ID_ADAPTEC
value|0x9005
end_define

begin_define
define|#
directive|define
name|IPS_MORPHEUS_DEVICE_ID
value|0x01BD
end_define

begin_define
define|#
directive|define
name|IPS_COPPERHEAD_DEVICE_ID
value|0x002E
end_define

begin_define
define|#
directive|define
name|IPS_MARCO_DEVICE_ID
value|0x0250
end_define

begin_define
define|#
directive|define
name|IPS_CSL
value|0xff
end_define

begin_define
define|#
directive|define
name|IPS_POCL
value|0x30
end_define

begin_comment
comment|/* amounts of memory to allocate for certain commands */
end_comment

begin_define
define|#
directive|define
name|IPS_ADAPTER_INFO_LEN
value|(sizeof(ips_adapter_info_t))
end_define

begin_define
define|#
directive|define
name|IPS_DRIVE_INFO_LEN
value|(sizeof(ips_drive_info_t))
end_define

begin_define
define|#
directive|define
name|IPS_COMMAND_LEN
value|24
end_define

begin_define
define|#
directive|define
name|IPS_MAX_SG_LEN
value|(sizeof(ips_sg_element_t) * IPS_MAX_SG_ELEMENTS)
end_define

begin_define
define|#
directive|define
name|IPS_NVRAM_PAGE_SIZE
value|128
end_define

begin_comment
comment|/* various flags */
end_comment

begin_define
define|#
directive|define
name|IPS_STATIC_FLAG
value|0x01
end_define

begin_comment
comment|/* states for the card to be in */
end_comment

begin_define
define|#
directive|define
name|IPS_DEV_OPEN
value|0x01
end_define

begin_define
define|#
directive|define
name|IPS_TIMEOUT
value|0x02
end_define

begin_comment
comment|/* command time out, need reset */
end_comment

begin_define
define|#
directive|define
name|IPS_OFFLINE
value|0x04
end_define

begin_comment
comment|/* can't reset card/card failure */
end_comment

begin_define
define|#
directive|define
name|IPS_STATIC_BUSY
value|0x08
end_define

begin_comment
comment|/* max number of commands set to something low for now */
end_comment

begin_define
define|#
directive|define
name|IPS_MAX_CMD_NUM
value|128
end_define

begin_define
define|#
directive|define
name|IPS_MAX_NUM_DRIVES
value|8
end_define

begin_define
define|#
directive|define
name|IPS_MAX_SG_ELEMENTS
value|32
end_define

begin_define
define|#
directive|define
name|IPS_MAX_IOBUF_SIZE
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|IPS_BLKSIZE
value|512
end_define

begin_define
define|#
directive|define
name|IPS_MAX_LD
value|8
end_define

begin_define
define|#
directive|define
name|IPS_MAX_CHANNELS
value|4
end_define

begin_define
define|#
directive|define
name|IPS_MAX_TARGETS
value|15
end_define

begin_define
define|#
directive|define
name|IPS_MAX_CHUNKS
value|16
end_define

begin_comment
comment|/* logical drive states */
end_comment

begin_define
define|#
directive|define
name|IPS_LD_OFFLINE
value|0x02
end_define

begin_define
define|#
directive|define
name|IPS_LD_OKAY
value|0x03
end_define

begin_define
define|#
directive|define
name|IPS_LD_DEGRADED
value|0x04
end_define

begin_define
define|#
directive|define
name|IPS_LD_FREE
value|0x00
end_define

begin_define
define|#
directive|define
name|IPS_LD_SYS
value|0x06
end_define

begin_define
define|#
directive|define
name|IPS_LD_CRS
value|0x24
end_define

begin_comment
comment|/* register offsets */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_OMR0
value|0x0018
end_define

begin_comment
comment|/* Outbound Msg. Reg. 0 */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_OMR1
value|0x001C
end_define

begin_comment
comment|/* Outbound Msg. Reg. 1 */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_IDR
value|0x0020
end_define

begin_comment
comment|/* Inbound Doorbell Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_IISR
value|0x0024
end_define

begin_comment
comment|/* Inbound IRQ Status Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_IIMR
value|0x0028
end_define

begin_comment
comment|/* Inbound IRQ Mask Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_OISR
value|0x0030
end_define

begin_comment
comment|/* Outbound IRQ Status Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_OIMR
value|0x0034
end_define

begin_comment
comment|/* Outbound IRQ Mask Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_IQPR
value|0x0040
end_define

begin_comment
comment|/* Inbound Queue Port Reg. */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_REG_OQPR
value|0x0044
end_define

begin_comment
comment|/* Outbound Queue Port Reg. */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_SCPR
value|0x05
end_define

begin_comment
comment|/* Subsystem Ctrl. Port Reg. */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_ISPR
value|0x06
end_define

begin_comment
comment|/* IRQ Status Port Reg. */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_CBSP
value|0x07
end_define

begin_comment
comment|/* ? Reg. */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_HISR
value|0x08
end_define

begin_comment
comment|/* Host IRQ Status Reg.    */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_CCSAR
value|0x10
end_define

begin_comment
comment|/* Cmd. Channel Sys Addr Reg.*/
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_CCCR
value|0x14
end_define

begin_comment
comment|/* Cmd. Channel Ctrl. Reg. */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_SQHR
value|0x20
end_define

begin_comment
comment|/* Status Queue Head Reg.  */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_SQTR
value|0x24
end_define

begin_comment
comment|/* Status Queue Tail Reg.  */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_SQER
value|0x28
end_define

begin_comment
comment|/* Status Queue End Reg.   */
end_comment

begin_define
define|#
directive|define
name|COPPER_REG_SQSR
value|0x2C
end_define

begin_comment
comment|/* Status Queue Start Reg. */
end_comment

begin_comment
comment|/* bit definitions */
end_comment

begin_define
define|#
directive|define
name|MORPHEUS_BIT_POST1
value|0x01
end_define

begin_define
define|#
directive|define
name|MORPHEUS_BIT_POST2
value|0x02
end_define

begin_define
define|#
directive|define
name|MORPHEUS_BIT_CMD_IRQ
value|0x08
end_define

begin_define
define|#
directive|define
name|COPPER_CMD_START
value|0x101A
end_define

begin_define
define|#
directive|define
name|COPPER_SEM_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|COPPER_EI_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|COPPER_EBM_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|COPPER_RESET_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|COPPER_GHI_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|COPPER_SCE_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|COPPER_OP_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|COPPER_ILE_BIT
value|0x10
end_define

begin_comment
comment|/* status defines */
end_comment

begin_define
define|#
directive|define
name|IPS_POST1_OK
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPS_POST2_OK
value|0x000f
end_define

begin_comment
comment|/* command op codes */
end_comment

begin_define
define|#
directive|define
name|IPS_READ_CMD
value|0x02
end_define

begin_define
define|#
directive|define
name|IPS_WRITE_CMD
value|0x03
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_INFO_CMD
value|0x05
end_define

begin_define
define|#
directive|define
name|IPS_CACHE_FLUSH_CMD
value|0x0A
end_define

begin_define
define|#
directive|define
name|IPS_REBUILD_STATUS_CMD
value|0x0C
end_define

begin_define
define|#
directive|define
name|IPS_ERROR_TABLE_CMD
value|0x17
end_define

begin_define
define|#
directive|define
name|IPS_DRIVE_INFO_CMD
value|0x19
end_define

begin_define
define|#
directive|define
name|IPS_CMD_READ_CONF
value|0x38
end_define

begin_define
define|#
directive|define
name|IPS_SUBSYS_PARAM_CMD
value|0x40
end_define

begin_define
define|#
directive|define
name|IPS_CONFIG_SYNC_CMD
value|0x58
end_define

begin_define
define|#
directive|define
name|IPS_SG_READ_CMD
value|0x82
end_define

begin_define
define|#
directive|define
name|IPS_SG_WRITE_CMD
value|0x83
end_define

begin_define
define|#
directive|define
name|IPS_RW_NVRAM_CMD
value|0xBC
end_define

begin_define
define|#
directive|define
name|IPS_FFDC_CMD
value|0xD7
end_define

begin_comment
comment|/* basic_status information returned by the adapter */
end_comment

begin_define
define|#
directive|define
name|IPS_MIN_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|IPS_BASIC_STATUS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IPS_GSC_STATUS_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|IPS_CMD_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|IPS_CMD_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|IPS_DRV_ERROR
value|0x02
end_define

begin_comment
comment|/* Driver supplied error */
end_comment

begin_define
define|#
directive|define
name|IPS_INVAL_OPCO
value|0x03
end_define

begin_define
define|#
directive|define
name|IPS_INVAL_CMD_BLK
value|0x04
end_define

begin_define
define|#
directive|define
name|IPS_INVAL_PARM_BLK
value|0x05
end_define

begin_define
define|#
directive|define
name|IPS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|IPS_CMD_CMPLT_WERROR
value|0x0C
end_define

begin_define
define|#
directive|define
name|IPS_LD_ERROR
value|0x0D
end_define

begin_define
define|#
directive|define
name|IPS_CMD_TIMEOUT
value|0x0E
end_define

begin_define
define|#
directive|define
name|IPS_PHYS_DRV_ERROR
value|0x0F
end_define

begin_comment
comment|/* extended_status information returned by the adapter */
end_comment

begin_define
define|#
directive|define
name|IPS_ERR_SEL_TO
value|0xF0
end_define

begin_define
define|#
directive|define
name|IPS_ERR_OU_RUN
value|0xF2
end_define

begin_define
define|#
directive|define
name|IPS_ERR_HOST_RESET
value|0xF7
end_define

begin_define
define|#
directive|define
name|IPS_ERR_DEV_RESET
value|0xF8
end_define

begin_define
define|#
directive|define
name|IPS_ERR_RECOVERY
value|0xFC
end_define

begin_define
define|#
directive|define
name|IPS_ERR_CKCOND
value|0xFF
end_define

begin_define
define|#
directive|define
name|IPS_OS_FREEBSD
value|8
end_define

begin_define
define|#
directive|define
name|IPS_VERSION_MAJOR
value|"0.90"
end_define

begin_define
define|#
directive|define
name|IPS_VERSION_MINOR
value|".10"
end_define

begin_comment
comment|/* Adapter Types */
end_comment

begin_define
define|#
directive|define
name|IPS_ADAPTER_COPPERHEAD
value|0x01
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_COPPERHEAD2
value|0x02
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_COPPERHEADOB1
value|0x03
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_COPPERHEADOB2
value|0x04
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_CLARINET
value|0x05
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_CLARINETLITE
value|0x06
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_TROMBONE
value|0x07
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_MORPHEUS
value|0x08
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_MORPHEUSLITE
value|0x09
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_NEO
value|0x0A
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_NEOLITE
value|0x0B
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_SARASOTA2
value|0x0C
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_SARASOTA1
value|0x0D
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_MARCO
value|0x0E
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_SEBRING
value|0x0F
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_7T
value|0x10
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_7K
value|0x11
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_7M
value|0x12
end_define

begin_define
define|#
directive|define
name|IPS_ADAPTER_MAX_T
value|IPS_ADAPTER_7M
end_define

begin_comment
comment|/* values for ffdc_settime (from gmtime) */
end_comment

begin_define
define|#
directive|define
name|IPS_SECSPERMIN
value|60
end_define

begin_define
define|#
directive|define
name|IPS_MINSPERHOUR
value|60
end_define

begin_define
define|#
directive|define
name|IPS_HOURSPERDAY
value|24
end_define

begin_define
define|#
directive|define
name|IPS_DAYSPERWEEK
value|7
end_define

begin_define
define|#
directive|define
name|IPS_DAYSPERNYEAR
value|365
end_define

begin_define
define|#
directive|define
name|IPS_DAYSPERLYEAR
value|366
end_define

begin_define
define|#
directive|define
name|IPS_SECSPERHOUR
value|(IPS_SECSPERMIN * IPS_MINSPERHOUR)
end_define

begin_define
define|#
directive|define
name|IPS_SECSPERDAY
value|((long) IPS_SECSPERHOUR * IPS_HOURSPERDAY)
end_define

begin_define
define|#
directive|define
name|IPS_MONSPERYEAR
value|12
end_define

begin_define
define|#
directive|define
name|IPS_EPOCH_YEAR
value|1970
end_define

begin_define
define|#
directive|define
name|IPS_LEAPS_THRU_END_OF
parameter_list|(
name|y
parameter_list|)
value|((y) / 4 - (y) / 100 + (y) / 400)
end_define

begin_define
define|#
directive|define
name|ips_isleap
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4) == 0&& (((y) % 100) != 0 || ((y) % 400) == 0))
end_define

begin_comment
comment|/*  *   IPS STRUCTS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|drivenum
decl_stmt|;
name|u_int8_t
name|reserve2
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|u_int32_t
name|buffaddr
decl_stmt|;
name|u_int32_t
name|reserve3
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_generic_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|drivenum
decl_stmt|;
name|u_int8_t
name|segnum
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|u_int32_t
name|buffaddr
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int16_t
name|reserve1
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_io_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|pagenum
decl_stmt|;
name|u_int8_t
name|rw
decl_stmt|;
name|u_int32_t
name|reserve1
decl_stmt|;
name|u_int32_t
name|buffaddr
decl_stmt|;
name|u_int32_t
name|reserve3
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_rw_nvram_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|drivenum
decl_stmt|;
name|u_int8_t
name|reserve1
decl_stmt|;
name|u_int32_t
name|reserve2
decl_stmt|;
name|u_int32_t
name|buffaddr
decl_stmt|;
name|u_int32_t
name|reserve3
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_drive_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|reserve1
decl_stmt|;
name|u_int8_t
name|commandtype
decl_stmt|;
name|u_int32_t
name|reserve2
decl_stmt|;
name|u_int32_t
name|buffaddr
decl_stmt|;
name|u_int32_t
name|reserve3
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_adapter_info_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|reset_count
decl_stmt|;
name|u_int8_t
name|reset_type
decl_stmt|;
name|u_int8_t
name|second
decl_stmt|;
name|u_int8_t
name|minute
decl_stmt|;
name|u_int8_t
name|hour
decl_stmt|;
name|u_int8_t
name|day
decl_stmt|;
name|u_int8_t
name|reserve1
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|month
decl_stmt|;
name|u_int8_t
name|yearH
decl_stmt|;
name|u_int8_t
name|yearL
decl_stmt|;
name|u_int8_t
name|reserve2
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_adapter_ffdc_cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ips_generic_cmd
name|generic_cmd
decl_stmt|;
name|ips_drive_cmd
name|drive_cmd
decl_stmt|;
name|ips_adapter_info_cmd
name|adapter_info_cmd
decl_stmt|;
block|}
name|ips_cmd_buff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|signature
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|adapter_slot
decl_stmt|;
name|u_int16_t
name|adapter_type
decl_stmt|;
name|u_int8_t
name|bios_high
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|bios_low
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|reserve2
decl_stmt|;
name|u_int8_t
name|reserve3
decl_stmt|;
name|u_int8_t
name|operating_system
decl_stmt|;
name|u_int8_t
name|driver_high
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|driver_low
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|reserve4
index|[
literal|100
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_nvram_page5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
block|}
name|ips_sg_element_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|drivenum
decl_stmt|;
name|u_int8_t
name|merge_id
decl_stmt|;
name|u_int8_t
name|raid_lvl
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
name|u_int32_t
name|sector_count
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_drive_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|drivecount
decl_stmt|;
name|u_int8_t
name|reserve1
decl_stmt|;
name|u_int16_t
name|reserve2
decl_stmt|;
name|ips_drive_t
name|drives
index|[
name|IPS_MAX_NUM_DRIVES
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_drive_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|drivecount
decl_stmt|;
name|u_int8_t
name|miscflags
decl_stmt|;
name|u_int8_t
name|SLTflags
decl_stmt|;
name|u_int8_t
name|BSTflags
decl_stmt|;
name|u_int8_t
name|pwr_chg_count
decl_stmt|;
name|u_int8_t
name|wrong_addr_count
decl_stmt|;
name|u_int8_t
name|unident_count
decl_stmt|;
name|u_int8_t
name|nvram_dev_chg_count
decl_stmt|;
name|u_int8_t
name|codeblock_version
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|bootblock_version
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|drive_sector_count
index|[
name|IPS_MAX_NUM_DRIVES
index|]
decl_stmt|;
name|u_int8_t
name|max_concurrent_cmds
decl_stmt|;
name|u_int8_t
name|max_phys_devices
decl_stmt|;
name|u_int16_t
name|flash_prog_count
decl_stmt|;
name|u_int8_t
name|defunct_disks
decl_stmt|;
name|u_int8_t
name|rebuildflags
decl_stmt|;
name|u_int8_t
name|offline_drivecount
decl_stmt|;
name|u_int8_t
name|critical_drivecount
decl_stmt|;
name|u_int16_t
name|config_update_count
decl_stmt|;
name|u_int8_t
name|blockedflags
decl_stmt|;
name|u_int8_t
name|psdn_error
decl_stmt|;
name|u_int16_t
name|addr_dead_disk
index|[
name|IPS_MAX_CHANNELS
index|]
index|[
name|IPS_MAX_TARGETS
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_adapter_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|initiator
decl_stmt|;
name|u_int8_t
name|parameters
decl_stmt|;
name|u_int8_t
name|miscflag
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
name|u_int32_t
name|blkcount
decl_stmt|;
name|u_int8_t
name|deviceid
index|[
literal|28
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_devstate_t
typedef|;
end_typedef

begin_comment
comment|/*  * The states that a physical drive can be in.  The 'present' value can be  * OR'd with the other values.  */
end_comment

begin_define
define|#
directive|define
name|IPS_DEVSTATE_PRESENT
value|0x81
end_define

begin_define
define|#
directive|define
name|IPS_DEVSTATE_REBUILD
value|0x02
end_define

begin_define
define|#
directive|define
name|IPS_DEVSTATE_SPARE
value|0x04
end_define

begin_define
define|#
directive|define
name|IPS_DEVSTATE_MEMBER
value|0x08
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|startsectors
decl_stmt|;
name|u_int32_t
name|numsectors
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_chunk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|userfield
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
name|u_int8_t
name|raidcacheparam
decl_stmt|;
name|u_int8_t
name|numchunkunits
decl_stmt|;
name|u_int8_t
name|stripesize
decl_stmt|;
name|u_int8_t
name|params
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int32_t
name|ldsize
decl_stmt|;
name|ips_chunk_t
name|chunk
index|[
name|IPS_MAX_CHUNKS
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_ld_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|boarddisc
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|processor
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|numchantype
decl_stmt|;
name|u_int8_t
name|numhostinttype
decl_stmt|;
name|u_int8_t
name|compression
decl_stmt|;
name|u_int8_t
name|nvramtype
decl_stmt|;
name|u_int32_t
name|nvramsize
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_hardware_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|ldcount
decl_stmt|;
name|u_int8_t
name|day
decl_stmt|;
name|u_int8_t
name|month
decl_stmt|;
name|u_int8_t
name|year
decl_stmt|;
name|u_int8_t
name|initiatorid
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|hostid
index|[
literal|12
index|]
decl_stmt|;
name|u_int8_t
name|timesign
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|useropt
decl_stmt|;
name|u_int16_t
name|userfield
decl_stmt|;
name|u_int8_t
name|rebuildrate
decl_stmt|;
name|u_int8_t
name|reserve
decl_stmt|;
name|ips_hardware_t
name|hardwaredisc
decl_stmt|;
name|ips_ld_t
name|ld
index|[
name|IPS_MAX_LD
index|]
decl_stmt|;
name|ips_devstate_t
name|dev
index|[
name|IPS_MAX_CHANNELS
index|]
index|[
name|IPS_MAX_TARGETS
operator|+
literal|1
index|]
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|512
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|ips_conf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|command_id
decl_stmt|;
name|u_int8_t
name|basic_status
decl_stmt|;
name|u_int8_t
name|extended_status
decl_stmt|;
block|}
name|fields
struct|;
specifier|volatile
name|u_int32_t
name|value
decl_stmt|;
block|}
name|ips_cmd_status_t
typedef|;
end_typedef

end_unit

