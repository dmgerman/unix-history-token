begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  Module Name:     lxcommon.h Abstract:     TISA Initiator/target driver module constant define header file Environment:     Kernel or loadable module    ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_define
define|#
directive|define
name|LINUX_DMA_MEM_MAX
value|0x1ffe0
end_define

begin_comment
comment|/* 128k - 32, real 128k - 24 */
end_comment

begin_define
define|#
directive|define
name|DEK_MAX_TABLE_ITEMS
value|DEK_MAX_TABLE_ENTRIES
end_define

begin_comment
comment|// from tisa/api/titypes.h
end_comment

begin_comment
comment|/* ** IP address length based on character. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_IP6_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|IP_ADDR_CHAR_LEN
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IP_ADDR_CHAR_LEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSEC_PER_TICK
value|(1000/hz)
end_define

begin_comment
comment|/* milisecond per tick */
end_comment

begin_define
define|#
directive|define
name|USEC_PER_TICK
value|(1000000/hz)
end_define

begin_comment
comment|/* microsecond per tick */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_64BIT_ALIGN
value|8
end_define

begin_comment
comment|/* 64 bit environment alignment */
end_comment

begin_comment
comment|/* ** Max device supported */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_CARDS
value|4
end_define

begin_comment
comment|/* card supported up to system limit */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_TOO_MANY_CARDS
value|-1
end_define

begin_comment
comment|/* beyond defined max support */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_PORTALS
value|16
end_define

begin_comment
comment|/* max portal per card */
end_comment

begin_comment
comment|/* max device per portal */
end_comment

begin_comment
comment|/* ** Adjustable Parameter Options */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_OPTION_ON
value|1
end_define

begin_comment
comment|/* adjustable parameter available */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_KEY_MAX
value|64
end_define

begin_comment
comment|/* max number of keys */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_STRING_MAX
value|512
end_define

begin_comment
comment|/* max length for string */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_PARAM_MAX
value|256
end_define

begin_comment
comment|/* max number of parameters */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DRIVER
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_DMA_MEM_LIST_MAX
value|4096
end_define

begin_comment
comment|/* max number of DMA memory list */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_CACHE_MEM_LIST_MAX
value|24
end_define

begin_comment
comment|/* max number of CACHE memory list */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INITIATOR_DRIVER */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_DMA_MEM_LIST_MAX
value|1024
end_define

begin_comment
comment|/* max number of DMA memory list */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_CACHE_MEM_LIST_MAX
value|1024
end_define

begin_comment
comment|/* max number of CACHE memory list */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AGTIAPI_DYNAMIC_MAX
end_ifndef

begin_define
define|#
directive|define
name|AGTIAPI_DYNAMIC_MAX
value|4096
end_define

begin_comment
comment|/* max unreleased dynamic memory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AGTIAPI_LOOP_MAX
value|4
end_define

begin_comment
comment|/* max loop for init process */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_NAME
value|70
end_define

begin_comment
comment|// Max string name length
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MIN_NAME
value|10
end_define

begin_comment
comment|// minimum space for SAS name string
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_ID
value|8
end_define

begin_comment
comment|// Max string id length
end_comment

begin_comment
comment|/*  ** Card-port status definitions */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_INIT_TIME
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SOFT_RESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AGTIAPI_HAD_RESET
value|0x00000004
end_define

begin_comment
comment|// ###
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_DISC_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AGTIAPI_INSTALLED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGTIAPI_RESET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AGTIAPI_FLAG_UP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AGTIAPI_CB_DONE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AGTIAPI_DISC_COMPLETE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AGTIAPI_IOREGION_REQUESTED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AGTIAPI_IRQ_REQUESTED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SCSI_REGISTERED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AGTIAPI_NAME_SERVER_UP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_INITIALIZED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_LINK_UP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_LGN_LINK_UP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_PANIC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_RESET_SUCCESS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_START
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_STOPPED
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_SHUTDOWN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_IN_USE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SYS_INTR_ON
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PORT_DISC_READY
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SIG_DOWN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SIG_UP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_TASK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_INITIATOR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_TARGET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_TIMER_ON
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SHUT_DOWN
value|0x40000000
end_define

begin_comment
comment|/* reserved for ccb flag TASK_MANAGEMENT #define AGTIAPI_RESERVED            0x80000000 */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_RESET_ALL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* ** PCI defines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_HP
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_HP
value|0x103c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_PMC_SIERRA
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_PMC_SIERRA
value|0x11F8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_AGILENT
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_AGILENT
value|0x15bc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_CYCLONE
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_CYCLONE
value|0x113C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_SPCV_FPGA
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_SPCV_FPGA
value|0x1855
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_HIALEAH
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_HIALEAH
value|0x9005
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HP_TS
value|0x102a
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HP_TL
value|0x1028
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HP_XL2
value|0x1029
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_DX2
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_DX2PLUS
value|0x0101
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_QX2
value|0x0102
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_QX4
value|0x0103
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_QE4
value|0x1200
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_DE4
value|0x1203
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_XL10
value|0x0104
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_DX4PLUS
value|0x0105
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_DIXL
value|0x0110
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_AG_IDX1
value|0x050A
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPC
value|0x8001
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV
value|0x8008
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE
value|0x8009
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVPLUS
value|0x8018
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE_16
value|0x8019
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_SPCV_FPGA
value|0xabcd
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV12G
value|0x8070
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE12G
value|0x8071
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV12G_16
value|0x8072
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE12G_16
value|0x8073
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_HBA_SPC
value|0x8081
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_RAID_SPC
value|0x8091
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_HBA_SPCV
value|0x8088
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_RAID_SPCV
value|0x8098
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_HBA_SPCVE
value|0x8089
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_HIALEAH_RAID_SPCVE
value|0x8099
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_DELRAY_HBA_8PORTS_SPCV
value|0x8074
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_DELRAY_HBA_8PORTS_SPCVE
value|0x8075
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCV
value|0x8076
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCVE
value|0x8077
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCV_SATA
value|0x8006
end_define

begin_define
define|#
directive|define
name|PCI_SUB_VENDOR_ID_HP
value|PCI_VENDOR_ID_HP
end_define

begin_define
define|#
directive|define
name|PCI_SUB_VENDOR_ID_AG
value|PCI_VENDOR_ID_AGILENT
end_define

begin_define
define|#
directive|define
name|PCI_SUB_VENDOR_ID_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|PCI_SUB_SYSTEM_ID_AG
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCI_BASE_MEM_MASK
value|(~0x0F)
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_CYCLONE
value|0xB555
end_define

begin_define
define|#
directive|define
name|PCI_ENABLE_VALUE
value|0x0157
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PMC_SPC
end_ifdef

begin_define
define|#
directive|define
name|PCI_NUMBER_BARS
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IOCTL_MN_GET_CARD_INFO
value|0x11
end_define

begin_comment
comment|/* ** Constant defines */
end_comment

begin_define
define|#
directive|define
name|_08B
value|8
end_define

begin_define
define|#
directive|define
name|_16B
value|16
end_define

begin_define
define|#
directive|define
name|_24B
value|24
end_define

begin_define
define|#
directive|define
name|_32B
value|32
end_define

begin_define
define|#
directive|define
name|_64B
value|64
end_define

begin_define
define|#
directive|define
name|_128B
value|128
end_define

begin_define
define|#
directive|define
name|_256B
value|256
end_define

begin_define
define|#
directive|define
name|_512B
value|512
end_define

begin_define
define|#
directive|define
name|_1K
value|1024
end_define

begin_define
define|#
directive|define
name|_2K
value|2048
end_define

begin_define
define|#
directive|define
name|_4K
value|4096
end_define

begin_define
define|#
directive|define
name|_128K
value|(128*(_1K))
end_define

begin_comment
comment|// Card property related info.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_card_id
block|{
name|U16
name|vendorId
decl_stmt|;
comment|/* pci vendor id */
name|U16
name|deviceId
decl_stmt|;
comment|/* pci device id */
name|S32
name|cardNameIndex
decl_stmt|;
comment|/* structure index */
name|U16
name|membar
decl_stmt|;
comment|/* pci memory bar offset */
name|U16
name|iobar1
decl_stmt|;
comment|/* pci io bar 1 offset */
name|U16
name|iobar2
decl_stmt|;
comment|/* pci io bar 2 offest */
name|U16
name|reg
decl_stmt|;
comment|/* pci memory bar number */
block|}
name|ag_card_id_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_0
value|PCIR_BAR(0)
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_1
value|PCIR_BAR(1)
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_2
value|PCIR_BAR(2)
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_3
value|PCIR_BAR(3)
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_4
value|PCIR_BAR(4)
end_define

begin_decl_stmt
name|ag_card_id_t
name|ag_card_type
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|AGTIAPI_ISCSI
block|{
name|PCI_VENDOR_ID_AGILENTj
block|,
name|PCI_DEVICE_ID_AG_DIXL
block|,
literal|1
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_1
block|,
name|PCI_BASE_ADDRESS_0
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_IDX1
block|,
literal|2
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_1
block|,
name|PCI_BASE_ADDRESS_0
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AGTIAPI_FC
block|{
name|PCI_VENDOR_ID_HP
block|,
name|PCI_DEVICE_ID_HP_TS
block|,
literal|3
block|,
name|PCI_BASE_ADDRESS_3
block|,
name|PCI_BASE_ADDRESS_1
block|,
name|PCI_BASE_ADDRESS_2
block|,
literal|3
block|}
block|,
block|{
name|PCI_VENDOR_ID_HP
block|,
name|PCI_DEVICE_ID_HP_TL
block|,
literal|4
block|,
name|PCI_BASE_ADDRESS_3
block|,
name|PCI_BASE_ADDRESS_1
block|,
name|PCI_BASE_ADDRESS_2
block|,
literal|3
block|}
block|,
block|{
name|PCI_VENDOR_ID_HP
block|,
name|PCI_DEVICE_ID_HP_XL2
block|,
literal|5
block|,
name|PCI_BASE_ADDRESS_3
block|,
name|PCI_BASE_ADDRESS_1
block|,
name|PCI_BASE_ADDRESS_2
block|,
literal|3
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_DX2
block|,
literal|6
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_DX2PLUS
block|,
literal|7
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_DX4PLUS
block|,
literal|8
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_QX2
block|,
literal|9
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_QX4
block|,
literal|10
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_DE4
block|,
literal|11
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_QE4
block|,
literal|12
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
block|{
name|PCI_VENDOR_ID_AGILENT
block|,
name|PCI_DEVICE_ID_AG_XL10
block|,
literal|13
block|,
name|PCI_BASE_ADDRESS_4
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|4
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AGTIAPI_SA
ifdef|#
directive|ifdef
name|PMC_SPC
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPC
block|,
literal|14
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV
block|,
literal|15
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE
block|,
literal|16
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVPLUS
block|,
literal|17
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE_16
block|,
literal|18
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_SPCV_FPGA
block|,
name|PCI_DEVICE_ID_SPCV_FPGA
block|,
literal|19
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV12G
block|,
literal|20
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE12G
block|,
literal|21
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCV12G_16
block|,
literal|22
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_PMC_SIERRA
block|,
name|PCI_DEVICE_ID_PMC_SIERRA_SPCVE12G_16
block|,
literal|23
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_HBA_SPC
block|,
literal|24
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_RAID_SPC
block|,
literal|25
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_HBA_SPCV
block|,
literal|26
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_RAID_SPCV
block|,
literal|27
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_HBA_SPCVE
block|,
literal|28
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_HIALEAH_RAID_SPCVE
block|,
literal|29
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_DELRAY_HBA_8PORTS_SPCV
block|,
literal|30
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_DELRAY_HBA_8PORTS_SPCVE
block|,
literal|31
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCV
block|,
literal|32
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCVE
block|,
literal|33
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
block|{
name|PCI_VENDOR_ID_HIALEAH
block|,
name|PCI_DEVICE_ID_DELRAY_HBA_16PORTS_SPCV_SATA
block|,
literal|34
block|,
name|PCI_BASE_ADDRESS_0
block|,
name|PCI_BASE_ADDRESS_2
block|,
name|PCI_BASE_ADDRESS_3
block|,
literal|0
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|//AGTIAPI_SA
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ag_card_names
index|[]
init|=
block|{
literal|"Unknown"
block|,
literal|"iSCSI DiXL Card"
block|,
literal|"iSCSI iDX1 Card"
block|,
literal|"Tachyon TS Fibre Channel Card"
block|,
literal|"Tachyon TL Fibre Channel Card"
block|,
literal|"Tachyon XL2 Fibre Channel Card"
block|,
literal|"Tachyon DX2 Fibre Channel Card"
block|,
literal|"Tachyon DX2+ Fibre Channel Card"
block|,
literal|"Tachyon DX4+ Fibre Channel Card"
block|,
literal|"Tachyon QX2 Fibre Channel Card"
block|,
literal|"Tachyon QX4 Fibre Channel Card"
block|,
literal|"Tachyon DE4 Fibre Channel Card"
block|,
literal|"Tachyon QE4 Fibre Channel Card"
block|,
literal|"Tachyon XL10 Fibre Channel Card"
block|,
ifdef|#
directive|ifdef
name|AGTIAPI_SA
ifdef|#
directive|ifdef
name|PMC_SPC
literal|"PMC Sierra SPC SAS-SATA Card"
block|,
literal|"PMC Sierra SPC-V SAS-SATA Card"
block|,
literal|"PMC Sierra SPC-VE SAS-SATA Card"
block|,
literal|"PMC Sierra SPC-V 16 Port SAS-SATA Card"
block|,
literal|"PMC Sierra SPC-VE 16 Port SAS-SATA Card"
block|,
literal|"PMC Sierra FPGA"
block|,
literal|"PMC Sierra SPC-V SAS-SATA Card 12Gig"
block|,
literal|"PMC Sierra SPC-VE SAS-SATA Card 12Gig"
block|,
literal|"PMC Sierra SPC-V 16 Port SAS-SATA Card 12Gig"
block|,
literal|"PMC Sierra SPC-VE 16 Port SAS-SATA Card 12Gig"
block|,
literal|"Adaptec Hialeah 4/8 Port SAS-SATA HBA Card 6Gig"
block|,
literal|"Adaptec Hialeah 4/8 Port SAS-SATA RAID Card 6Gig"
block|,
literal|"Adaptec Hialeah 8/16 Port SAS-SATA HBA Card 6Gig"
block|,
literal|"Adaptec Hialeah 8/16 Port SAS-SATA RAID Card 6Gig"
block|,
literal|"Adaptec Hialeah 8/16 Port SAS-SATA HBA Encryption Card 6Gig"
block|,
literal|"Adaptec Hialeah 8/16 Port SAS-SATA RAID Encryption Card 6Gig"
block|,
literal|"Adaptec Delray 8 Port SAS-SATA HBA Card 12Gig"
block|,
literal|"Adaptec Delray 8 Port SAS-SATA HBA Encryption Card 12Gig"
block|,
literal|"Adaptec Delray 16 Port SAS-SATA HBA Card 12Gig"
block|,
literal|"Adaptec Delray 16 Port SAS-SATA HBA Encryption Card 12Gig"
block|,
literal|"Adaptec SATA Adapter"
block|,
endif|#
directive|endif
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Resource Info Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_resource_info
block|{
name|tiLoLevelResource_t
name|tiLoLevelResource
decl_stmt|;
comment|// Low level resource required
name|tiInitiatorResource_t
name|tiInitiatorResource
decl_stmt|;
comment|// Initiator resource required
name|tiTargetResource_t
name|tiTargetResource
decl_stmt|;
comment|// Target resource required
name|tiTdSharedMem_t
name|tiSharedMem
decl_stmt|;
comment|// Shared memory by ti and td
block|}
name|ag_resource_info_t
typedef|;
end_typedef

begin_comment
comment|//  DMA memory address pair
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_dma_addr
block|{
name|void
modifier|*
name|dmaVirtAddr
decl_stmt|;
name|vm_paddr_t
name|dmaPhysAddr
decl_stmt|;
name|U32
name|memSize
decl_stmt|;
name|bit32
name|type
decl_stmt|;
name|bus_addr_t
name|nocache_busaddr
decl_stmt|;
name|void
modifier|*
name|nocache_mem
decl_stmt|;
block|}
name|ag_dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CardInfo
block|{
name|U32
name|pciIOAddrLow
decl_stmt|;
comment|/* PCI IOBASE lower */
name|U32
name|pciIOAddrUp
decl_stmt|;
comment|/* PCI IOBASE Upper */
name|U32_64
name|pciMemBase
decl_stmt|;
comment|/* PCI MEMBASE, physical */
name|U32_64
name|pciMemBaseSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
comment|// PCI MEMBASE, physical
name|U16
name|deviceId
decl_stmt|;
comment|// PCI device id
name|U16
name|vendorId
decl_stmt|;
comment|// PCI Vendor id
name|U32
name|busNum
decl_stmt|;
name|U32
name|deviceNum
decl_stmt|;
block|}
name|CardInfo_t
typedef|;
end_typedef

begin_comment
comment|// Card info. for all cards and drivers
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_card_info
block|{
name|struct
name|mtx
name|pmIOLock
decl_stmt|;
name|device_t
name|pPCIDev
decl_stmt|;
comment|// PCI device pointer
name|void
modifier|*
name|pCard
decl_stmt|;
comment|// pointer to per card data structure
name|S32
name|cardNameIndex
decl_stmt|;
name|U32
name|cardID
decl_stmt|;
comment|// card system ID
name|U32
name|cardIdIndex
decl_stmt|;
name|U32
name|pciIOAddrLow
decl_stmt|;
comment|// PCI IOBASE lower
name|U32
name|pciIOAddrUp
decl_stmt|;
comment|// PCI IOBASE Upper
name|U32_64
name|pciMemBase
decl_stmt|;
comment|// PCI MEMBASE, physical
name|caddr_t
name|pciMemVirtAddr
decl_stmt|;
comment|// PCI MEMBASE, virtual ptr
name|U32
name|pciMemSize
decl_stmt|;
comment|// PCI MEMBASE memory size
ifdef|#
directive|ifdef
name|AGTIAPI_SA
ifdef|#
directive|ifdef
name|FPGA_CARD
name|U32_64
name|pciMemBase0
decl_stmt|;
comment|// PCI MEMBASE, physical
name|caddr_t
name|pciMemVirtAddr0
decl_stmt|;
comment|// PCI MEMBASE, virtual ptr
name|U32
name|pciMemSize0
decl_stmt|;
comment|// PCI MEMBASE memory size
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PMC_SPC
name|struct
name|resource
modifier|*
name|pciMemBaseRscSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
name|int
name|pciMemBaseRIDSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
name|U32_64
name|pciMemBaseSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
comment|// PCI MEMBASE, physical
name|caddr_t
name|pciMemVirtAddrSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
comment|//PCI MEMBASE, virt ptr
name|U32
name|pciMemSizeSpc
index|[
name|PCI_NUMBER_BARS
index|]
decl_stmt|;
comment|// PCI MEMBASE memory size
endif|#
directive|endif
endif|#
directive|endif
name|U16
name|memBar
decl_stmt|;
name|U16
name|memReg
decl_stmt|;
name|U32
name|cacheIndex
decl_stmt|;
name|U32
name|dmaIndex
decl_stmt|;
name|ag_dma_addr_t
name|tiDmaMem
index|[
name|AGTIAPI_DMA_MEM_LIST_MAX
index|]
decl_stmt|;
comment|// dma addr list
comment|// all (free and allocated) mem slots
name|ag_dma_addr_t
name|dynamicMem
index|[
name|AGTIAPI_DYNAMIC_MAX
index|]
decl_stmt|;
comment|// ptr to free mem slots
name|ag_dma_addr_t
modifier|*
name|freeDynamicMem
index|[
name|AGTIAPI_DYNAMIC_MAX
index|]
decl_stmt|;
name|U16
name|topOfFreeDynamicMem
decl_stmt|;
comment|// idx to the first free slot ptr
name|void
modifier|*
name|tiCachedMem
index|[
name|AGTIAPI_CACHE_MEM_LIST_MAX
index|]
decl_stmt|;
comment|// cached mem list
name|ag_resource_info_t
name|tiRscInfo
decl_stmt|;
comment|/* low level resource requirement */
name|U08
name|WWN
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
comment|/* WWN for this card */
name|U08
name|WWNLen
decl_stmt|;
comment|// #define MAX_MSIX_NUM_VECTOR 64 ##
define|#
directive|define
name|MAX_MSIX_NUM_VECTOR
value|16
comment|// 1 then 16 just for testing;
define|#
directive|define
name|MAX_MSIX_NUM_DPC
value|64
comment|// 16
define|#
directive|define
name|MAX_MSIX_NUM_ISR
value|64
comment|// 16
ifdef|#
directive|ifdef
name|SPC_MSIX_INTR
comment|// ## use as a map instead of presirq
name|struct
name|resource
modifier|*
name|msix_entries
index|[
name|MAX_MSIX_NUM_VECTOR
index|]
decl_stmt|;
endif|#
directive|endif
name|U32
name|maxInterruptVectors
decl_stmt|;
block|}
name|ag_card_info_t
typedef|;
end_typedef

begin_comment
comment|/* ** Optional Adjustable Parameters Structures. ** Not using pointer structure for easy read and access tree structure. ** In the future if more layer of key tree involved, it might be a good ** idea to change the structure and program.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_param_value
block|{
name|char
name|valueName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
name|char
name|valueString
index|[
name|AGTIAPI_STRING_MAX
index|]
decl_stmt|;
name|struct
name|_ag_param_value
modifier|*
name|next
decl_stmt|;
block|}
name|ag_value_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ag_param_key
block|{
name|char
name|keyName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
name|ag_value_t
modifier|*
name|pValueHead
decl_stmt|;
name|ag_value_t
modifier|*
name|pValueTail
decl_stmt|;
name|struct
name|_ag_param_key
modifier|*
name|pSubkeyHead
decl_stmt|;
name|struct
name|_ag_param_key
modifier|*
name|pSubkeyTail
decl_stmt|;
name|struct
name|_ag_param_key
modifier|*
name|next
decl_stmt|;
block|}
name|ag_key_t
typedef|;
end_typedef

begin_comment
comment|/* **  Portal info data structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_portal_info
block|{
name|U32
name|portID
decl_stmt|;
name|U32
name|portStatus
decl_stmt|;
name|U32
name|devTotal
decl_stmt|;
name|U32
name|devPrev
decl_stmt|;
name|tiPortInfo_t
name|tiPortInfo
decl_stmt|;
name|tiPortalContext_t
name|tiPortalContext
decl_stmt|;
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
name|void
modifier|*
name|pDevList
index|[
name|AGTIAPI_HW_LIMIT_DEVICE
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|ag_portal_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAP_TABLE_ENTRY
parameter_list|(
name|pC
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|(pC->encrypt_map +                        \                                      (c * pC->devDiscover * AGTIAPI_MAX_LUN) + \                                      (d * AGTIAPI_MAX_LUN) +                   \                                      (l))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CHAR_DEVICE
end_ifdef

begin_comment
comment|/************************************************************************* Purpose: Payload Wraper for ioctl commands ***********************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|datatosendt
block|{
name|bit32
name|datasize
decl_stmt|;
comment|//buffer size
name|bit8
modifier|*
name|data
decl_stmt|;
comment|//buffer
block|}
name|datatosend
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_IOCTL_BASE
value|'x'
end_define

begin_define
define|#
directive|define
name|AGTIAPI_IOCTL
value|_IOWR(AGTIAPI_IOCTL_BASE, 0,datatosend )
end_define

begin_comment
comment|//receiving payload here//
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_IOCTL_MAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_FLOW_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_FLOW
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_FLOW
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_PRINTK
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_PRINTK
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_INIT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_INIT
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_comment
comment|/* to avoid losing the logs */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_INIT_MDELAY
parameter_list|(
name|dly
parameter_list|)
value|mdelay(dly)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_INIT
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AGTIAPI_INIT_MDELAY
parameter_list|(
name|dly
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_INIT2_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_INIT2
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_INIT2
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_INIT_MEM_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_INITMEM
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_INITMEM
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_IO_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_IO
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
value|printf(format, ## a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_IO
parameter_list|(
name|format
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_LOAD_DELAY
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_INIT_DELAY
parameter_list|(
name|delay_time
parameter_list|)
define|\
value|{  \       agtiapi_DelayMSec(delay_time);  \     }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_INIT_DELAY
parameter_list|(
name|delay_time
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * AGTIAPI_KDB() will be used to drop into kernel debugger   * from driver code if kdb is involved.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_KDB_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|AGTIAPI_KDB
parameter_list|()
value|KDB_ENTER()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AGTIAPI_KDB
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
end_if

begin_comment
comment|//#if 1
end_comment

begin_define
define|#
directive|define
name|LOW_32_BITS
parameter_list|(
name|addr
parameter_list|)
value|(U32)(addr& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|HIGH_32_BITS
parameter_list|(
name|addr
parameter_list|)
value|(U32)((addr>> 32)& 0xffffffff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOW_32_BITS
parameter_list|(
name|addr
parameter_list|)
value|(U32)addr
end_define

begin_define
define|#
directive|define
name|HIGH_32_BITS
parameter_list|(
name|addr
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AG_SWAP16
parameter_list|(
name|data
parameter_list|)
value|(((data<<8)& 0xFF00) | (data>>8))
end_define

begin_define
define|#
directive|define
name|AG_SWAP24
parameter_list|(
name|data
parameter_list|)
value|(((data<<16)& 0xFF0000) | \                           ((data>>16)& 0xFF) | (data& 0xFF00))
end_define

begin_define
define|#
directive|define
name|AG_SWAP32
parameter_list|(
name|data
parameter_list|)
value|((data<<24) | ((data<<8)& 0xFF0000) | \                           ((data>>8)& 0xFF00) | (data>>24))
end_define

begin_define
define|#
directive|define
name|AG_PCI_DEV_INFO
parameter_list|(
name|pdev
parameter_list|)
value|( \   AGTIAPI_PRINTK("vendor id 0x%x device id 0x%x, slot %d, function %d\n", \     pdev->vendor, pdev->device, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn)) \                                )
end_define

begin_define
define|#
directive|define
name|COUNT
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof(arr[0]))
end_define

begin_define
define|#
directive|define
name|PORTAL_CONTEXT_TO_PORTALDATA
parameter_list|(
name|pPortalContext
parameter_list|)
define|\
value|((ag_portal_data_t *)(((tiPortalContext_t *)pPortalContext)->osData))
end_define

begin_define
define|#
directive|define
name|PORTAL_STATUS
parameter_list|(
name|pPortalData
parameter_list|)
value|(pPortalData->portalInfo.portStatus)
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEFINE_OSTI_PORT_EVENT_IN_IBE
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|DEFINE_OSTI_PORT_EVENT_IN_TFE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|TIROOT_TO_CARD
parameter_list|(
name|ptiRoot
parameter_list|)
define|\
value|((ag_card_t *)(((appRoot_t *)(ptiRoot->osData))->oscData))
end_define

begin_define
define|#
directive|define
name|TIROOT_TO_CARDINFO
parameter_list|(
name|ptiRoot
parameter_list|)
value|(TIROOT_TO_CARD(ptiRoot)->pCardInfo)
end_define

begin_define
define|#
directive|define
name|TIROOT_TO_PCIDEV
parameter_list|(
name|ptiRoot
parameter_list|)
value|(TIROOT_TO_CARDINFO(ptiRoot)->pPCIDev)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIROOT_TO_CARD
parameter_list|(
name|ptiRoot
parameter_list|)
value|((struct agtiapi_softc *)(ptiRoot->osData))
end_define

begin_define
define|#
directive|define
name|TIROOT_TO_CARDINFO
parameter_list|(
name|ptiRoot
parameter_list|)
value|(TIROOT_TO_CARD(ptiRoot)->pCardInfo)
end_define

begin_define
define|#
directive|define
name|TIROOT_TO_PCIDEV
parameter_list|(
name|ptiRoot
parameter_list|)
value|(TIROOT_TO_CARD(ptiRoot)->my_dev)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Is_ADP7H
parameter_list|(
name|pmsc
parameter_list|)
value|((0x90058088 == (pmsc->VidDid))?1:\ 					(0x90058089 == (pmsc->VidDid))?1:0)
end_define

begin_define
define|#
directive|define
name|Is_ADP8H
parameter_list|(
name|pmsc
parameter_list|)
value|((0x90058074 == (pmsc->VidDid))?1:\ 					(0x90058076 == (pmsc->VidDid))?1:0)
end_define

begin_define
define|#
directive|define
name|__cacheline_aligned
value|__attribute__((__aligned__(CACHE_LINE_SIZE)))
end_define

begin_comment
comment|/* ** link data, need to be included at the start (offset 0)  ** of any strutures that are to be stored in the link list */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LINK_NODE
block|{
name|struct
name|_LINK_NODE
modifier|*
name|pNext
decl_stmt|;
name|struct
name|_LINK_NODE
modifier|*
name|pPrev
decl_stmt|;
comment|/*    ** for assertion purpose only   */
name|struct
name|_LINK_NODE
modifier|*
name|pHead
decl_stmt|;
comment|// track the link list the link is a member of
name|void
modifier|*
name|pad
decl_stmt|;
block|}
name|LINK_NODE
operator|,
typedef|*
name|PLINK_NODE
name|__cacheline_aligned
typedef|;
end_typedef

begin_comment
comment|/* ** link list basic pointers */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LINK_LIST
block|{
name|PLINK_NODE
name|pHead
decl_stmt|;
name|bit32
name|Count
decl_stmt|;
name|LINK_NODE
name|Head
name|__cacheline_aligned
decl_stmt|;
comment|// always one link to speed up insert&rm
block|}
name|LINK_LIST
operator|,
typedef|*
name|PLINK_LIST
name|__cacheline_aligned
typedef|;
end_typedef

begin_comment
comment|/******************************************************************** ** MACROS ********************************************************************/
end_comment

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListInitialize             ** ** PURPOSE:     Initialize a link list. ** ** PARAMETERS:  PLINK_LIST  OUT - Link list definition. ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListInitialize
parameter_list|(
name|pList
parameter_list|)
value|{(pList)->pHead        =&((pList)->Head); \                                   (pList)->pHead->pNext = (pList)->pHead;   \                                   (pList)->pHead->pPrev = (pList)->pHead;   \                                   (pList)->Count        = 0;                \                                  }
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comLinkInitialize             ** ** PURPOSE:     Initialize a link. **              This function should be used to initialize a new link before it **              is used in the linked list. This will initialize the link so  **              the assertion will work ** ** PARAMETERS:  PLINK_NODE      IN  - Link to be initialized. ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comLinkInitialize
parameter_list|(
name|pLink
parameter_list|)
value|{ (pLink)->pHead = NULL;    \                                    (pLink)->pNext = NULL;    \                                    (pLink)->pPrev = NULL;    \                                  }
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListAdd                    ** ** PURPOSE:     add a link at the tail of the list ** ** PARAMETERS:  PLINK_LIST OUT - Link list definition. **              PLINK_NODE      IN  - Link to be inserted. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListAdd
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                          \                              (pLink)->pNext        = (pList)->pHead;        \                              (pLink)->pPrev        = (pList)->pHead->pPrev; \                              (pLink)->pPrev->pNext = (pLink);               \                              (pList)->pHead->pPrev = (pLink);               \                              (pList)->Count ++;                             \                              (pLink)->pHead = (pList)->pHead;               \                              }
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListInsert                        ** ** PURPOSE:     insert a link preceding the given one ** ** PARAMETERS:  PLINK_LIST OUT - Link list definition. **              PLINK_NODE      IN  - Link to be inserted after. **              PLINK_NODE      IN  - Link to be inserted. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListInsert
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|,
name|pNew
parameter_list|)
value|{                                 \                                  (pNew)->pNext        = (pLink);            \                                  (pNew)->pPrev        = (pLink)->pPrev;     \                                  (pNew)->pPrev->pNext = (pNew);             \                                  (pLink)->pPrev       = (pNew);             \                                  (pList)->Count ++;                         \                                  (pNew)->pHead = (pList)->pHead;            \                                  }
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListRemove                 ** ** PURPOSE:     remove the link from the list. ** ** PARAMETERS:  PLINK_LIST OUT  - Link list definition. **              PLINK_NODE      IN   - Link to delet from list ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list  ** ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListRemove
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|{                                   \                            (pLink)->pPrev->pNext = (pLink)->pNext;      \                            (pLink)->pNext->pPrev = (pLink)->pPrev;      \                            (pLink)->pHead = NULL;                       \                            (pList)->Count --;                           \                            }
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListGetHead          ** ** PURPOSE:     get the link following the head link. ** ** PARAMETERS:  PLINK_LIST  OUT - Link list definition. **              RETURNS - PLINK_NODE   the link following the head **                                  NULL if the following link is the head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListGetHead
parameter_list|(
name|pList
parameter_list|)
value|comListGetNext(pList,(pList)->pHead)
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListGetTail                      ** ** PURPOSE:     get the link preceding the tail link. ** ** PARAMETERS:  PLINK_LIST  OUT - Link list definition. **              RETURNS - PLINK_NODE   the link preceding the head  **                                  NULL if the preceding link is the head ** ** SIDE EFFECTS& CAVEATS: ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListGetTail
parameter_list|(
name|pList
parameter_list|)
value|comListGetPrev((pList), (pList)->pHead)
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListGetCount                     ** ** PURPOSE:     get the number of links in the list excluding head and tail. ** ** PARAMETERS:  LINK_LIST  OUT - Link list definition. ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListGetCount
parameter_list|(
name|pList
parameter_list|)
value|((pList)->Count)
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListGetNext             ** ** PURPOSE:     get the next link in the list. (one toward tail) ** ** PARAMETERS:  PLINK_LIST  OUT - Link list definition. **              PLINK_NODE       IN  - Link to get next to ** **           return PLINK  - points to next link **                           NULL if next link is head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list  ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|comListGetNext
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|(((pLink)->pNext == (pList)->pHead) ?  \                                       NULL : (pLink)->pNext)
end_define

begin_comment
comment|/******************************************************************************* ** ** MODULE NAME: comListGetPrev             ** ** PURPOSE:     get the previous link in the list. (one toward head) ** ** PARAMETERS:  PLINK_LIST  OUT - Link list definition. **              PLINK_NODE       IN  - Link to get prev to ** **           return PLINK  - points to previous link **                           NULL if previous link is head ** ** SIDE EFFECTS& CAVEATS: **   !!! assumes that fcllistInitialize has been called on the linklist **   !!! if not, this function behavior is un-predictable ** **   !!! No validation is made on the list or the validity of the link **   !!! the caller must make sure that the link is in the list  ** ** ALGORITHM: ** *******************************************************************************/
end_comment

begin_comment
comment|/*lint -emacro(613,fiLlistGetPrev) */
end_comment

begin_define
define|#
directive|define
name|comListGetPrev
parameter_list|(
name|pList
parameter_list|,
name|pLink
parameter_list|)
value|(((pLink)->pPrev == (pList)->pHead) ?  \                                       NULL : (pLink)->pPrev)
end_define

begin_define
define|#
directive|define
name|AGT_INTERRUPT
value|IRQF_DISABLED
end_define

begin_define
define|#
directive|define
name|AGT_SAMPLE_RANDOM
value|IRQF_SAMPLE_RANDOM
end_define

begin_define
define|#
directive|define
name|AGT_SHIRQ
value|IRQF_SHARED
end_define

begin_define
define|#
directive|define
name|AGT_PROBEIRQ
value|IRQF_PROBE_SHARED
end_define

begin_define
define|#
directive|define
name|AGT_PERCPU
value|IRQF_PERCPU
end_define

begin_include
include|#
directive|include
file|"lxproto.h"
end_include

end_unit

