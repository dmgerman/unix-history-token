begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *       Copyright (c) 1997 by Simon Shapiro  *       All Rights Reserved  *  * This is a proprietary, unpublished source code.  No publishing, copying,  * distribution or use permission is granted to anyone.  *  * If you want to use this product in any way, please contact the author by  * sending email to shimon@i-connect.net  *  */
end_comment

begin_comment
comment|/*  *  *  dpt.h:	Definitions and constants used by the SCSI side of the DPT  *  *  credits:	Mike Neuffer;	DPT low level code and in other areas as well.  *		Mark Salyzyn; 	Many vital bits of info and diagnostics.  *		Justin Gibbs;	FreeBSD API, debugging and style  *		Ron McDaniels;	SCSI Software Interrupts  *		FreeBSD.ORG;	Great O/S to work on and for.  */
end_comment

begin_empty
empty|#ident "$Id: dpt.h,v 1.1.2.1 1998/03/06 23:44:05 julian Exp $"
end_empty

begin_ifndef
ifndef|#
directive|ifndef
name|_DPT_H
end_ifndef

begin_define
define|#
directive|define
name|_DPT_H
end_define

begin_comment
comment|/* till we have the CAM stuff, use our own */
end_comment

begin_undef
undef|#
directive|undef
name|DPT_USE_DPT_SWI
end_undef

begin_define
define|#
directive|define
name|DPT_USE_DPT_SWI
value|1
end_define

begin_decl_stmt
specifier|extern
name|u_long
name|dpt_unit
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DPT_RELEASE
value|1
end_define

begin_define
define|#
directive|define
name|DPT_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|DPT_PATCH
value|4
end_define

begin_define
define|#
directive|define
name|DPT_MONTH
value|8
end_define

begin_define
define|#
directive|define
name|DPT_DAY
value|23
end_define

begin_define
define|#
directive|define
name|DPT_YEAR
value|17
end_define

begin_comment
comment|/* 1997 - 1980 */
end_comment

begin_define
define|#
directive|define
name|DPT_CTL_RELEASE
value|1
end_define

begin_define
define|#
directive|define
name|DPT_CTL_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|DPT_CTL_PATCH
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PAGESIZ
end_ifndef

begin_define
define|#
directive|define
name|PAGESIZ
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|physaddr
end_ifndef

begin_typedef
typedef|typedef
name|void
modifier|*
name|physaddr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|DPT_INQUIRE_DEVICES
end_undef

begin_comment
comment|/* We have no buyers for this function       */
end_comment

begin_define
define|#
directive|define
name|DPT_SUPPORT_POLLING
end_define

begin_comment
comment|/* Use polled mode at boot (must be ON!)     */
end_comment

begin_define
define|#
directive|define
name|DPT_OPENNINGS
value|8
end_define

begin_comment
comment|/* Commands-in-progress per device */
end_comment

begin_define
define|#
directive|define
name|DPT_RETRIES
value|5
end_define

begin_comment
comment|/* Times to retry failed commands */
end_comment

begin_undef
undef|#
directive|undef
name|DPT_DISABLE_SG
end_undef

begin_define
define|#
directive|define
name|DPT_HAS_OPEN
end_define

begin_comment
comment|/* Arguments to dpt_run_queue() can be: */
end_comment

begin_define
define|#
directive|define
name|DPT_FREE_LIST_INCREMENT
value|64
end_define

begin_define
define|#
directive|define
name|DPT_CMD_LEN
value|12
end_define

begin_define
define|#
directive|define
name|DPT_MAX_SEGS
value|1024
end_define

begin_comment
comment|/* How many segments do we want in 					      * a Scatter/Gather list? 					      * Some HBA's can  do 16, 					      * Some 8192. Since we 					      * pre-allocate them in fixed 					      * increments, we need to put a 					      * practical limit on these. A 					      * passed parameter (from 					      * kernel boot or lkm) will help 					      */
end_comment

begin_comment
comment|/* Debug levels */
end_comment

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_PCI
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_INIT
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SETUP
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_STATES
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_CONFIG
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_QUEUES
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SCSI_CMD
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SOFTINTR
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_HARDINTR
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_HEX_DUMPS
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_POLLING
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_INQUIRE
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_COMPLETION
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_COMPLETION_ERRORS
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_MINPHYS
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SG
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SG_SHOW_DATA
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SCSI_CMD_NAME
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_CONTROL
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_TIMEOUTS
end_undef

begin_undef
undef|#
directive|undef
name|DPT_DEBUG_SHUTDOWN
end_undef

begin_define
define|#
directive|define
name|DPT_DEBUG_USER_CMD
end_define

begin_comment
comment|/*  * Misc. definitions  */
end_comment

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|MAX_CHANNELS
value|3
end_define

begin_comment
comment|/* Map minor numbers to device identity */
end_comment

begin_define
define|#
directive|define
name|TARGET_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|BUS_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|HBA_MASK
value|0x01c0
end_define

begin_define
define|#
directive|define
name|LUN_MASK
value|0x0e00
end_define

begin_define
define|#
directive|define
name|minor2target
parameter_list|(
name|minor
parameter_list|)
value|( minor& TARGET_MASK )
end_define

begin_define
define|#
directive|define
name|minor2bus
parameter_list|(
name|minor
parameter_list|)
value|( (minor& BUS_MASK)>> 4 )
end_define

begin_define
define|#
directive|define
name|minor2hba
parameter_list|(
name|minor
parameter_list|)
value|( (minor& HBA_MASK)>> 6 )
end_define

begin_define
define|#
directive|define
name|minor2lun
parameter_list|(
name|minor
parameter_list|)
value|( (minor& LUN_MASK)>> 9 )
end_define

begin_comment
comment|/*  * Valid values for cache_type  */
end_comment

begin_define
define|#
directive|define
name|DPT_NO_CACHE
value|0
end_define

begin_define
define|#
directive|define
name|DPT_CACHE_WRITETHROUGH
value|1
end_define

begin_define
define|#
directive|define
name|DPT_CACHE_WRITEBACK
value|2
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a<b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAXISA
value|4
end_define

begin_define
define|#
directive|define
name|MAXEISA
value|16
end_define

begin_define
define|#
directive|define
name|MAXPCI
value|16
end_define

begin_define
define|#
directive|define
name|MAXIRQ
value|16
end_define

begin_define
define|#
directive|define
name|MAXTARGET
value|16
end_define

begin_define
define|#
directive|define
name|IS_ISA
value|'I'
end_define

begin_define
define|#
directive|define
name|IS_EISA
value|'E'
end_define

begin_define
define|#
directive|define
name|IS_PCI
value|'P'
end_define

begin_define
define|#
directive|define
name|BROKEN_INQUIRY
value|1
end_define

begin_define
define|#
directive|define
name|BUSMASTER
value|0xff
end_define

begin_define
define|#
directive|define
name|PIO
value|0xfe
end_define

begin_define
define|#
directive|define
name|EATA_SIGNATURE
value|0x41544145
end_define

begin_comment
comment|/* little ENDIAN "EATA" */
end_comment

begin_define
define|#
directive|define
name|DPT_BLINK_INDICATOR
value|0x42445054
end_define

begin_define
define|#
directive|define
name|DPT_ID1
value|0x12
end_define

begin_define
define|#
directive|define
name|DPT_ID2
value|0x1
end_define

begin_define
define|#
directive|define
name|ATT_ID1
value|0x06
end_define

begin_define
define|#
directive|define
name|ATT_ID2
value|0x94
end_define

begin_define
define|#
directive|define
name|ATT_ID3
value|0x0
end_define

begin_define
define|#
directive|define
name|NEC_ID1
value|0x38
end_define

begin_define
define|#
directive|define
name|NEC_ID2
value|0xa3
end_define

begin_define
define|#
directive|define
name|NEC_ID3
value|0x82
end_define

begin_define
define|#
directive|define
name|DPT_MAX_ADAPTERS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_PCI_DEVICES
value|32
end_define

begin_comment
comment|/* Maximum # Of Devices Per Bus */
end_comment

begin_define
define|#
directive|define
name|MAX_METHOD_2
value|16
end_define

begin_comment
comment|/* Max Devices For Method 2 */
end_comment

begin_define
define|#
directive|define
name|MAX_PCI_BUS
value|16
end_define

begin_comment
comment|/* Maximum # Of Busses Allowed */
end_comment

begin_define
define|#
directive|define
name|SG_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|SG_SIZE_BIG
value|252
end_define

begin_comment
comment|/* max. 8096 elements, 64k */
end_comment

begin_define
define|#
directive|define
name|DPT_MAX_RETRIES
value|2
end_define

begin_define
define|#
directive|define
name|READ
value|0
end_define

begin_define
define|#
directive|define
name|WRITE
value|1
end_define

begin_define
define|#
directive|define
name|OTHER
value|2
end_define

begin_define
define|#
directive|define
name|HD
parameter_list|(
name|cmd
parameter_list|)
value|((hostdata *)&(cmd->host->hostdata))
end_define

begin_define
define|#
directive|define
name|CD
parameter_list|(
name|cmd
parameter_list|)
value|((struct eata_ccb *)(cmd->host_scribble))
end_define

begin_define
define|#
directive|define
name|SD
parameter_list|(
name|host
parameter_list|)
value|((hostdata *)&(host->hostdata))
end_define

begin_define
define|#
directive|define
name|BaseRegister
parameter_list|(
name|dpt
parameter_list|)
value|((dpt->v_membase == NULL)            \ 				? (u_int32_t)dpt->io_base                    \ 				: (u_int32_t)dpt->v_membase )
end_define

begin_comment
comment|/*  * EATA Command& Register definitions  */
end_comment

begin_define
define|#
directive|define
name|PCI_REG_DPTconfig
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_REG_PumpModeAddress
value|0x44
end_define

begin_define
define|#
directive|define
name|PCI_REG_PumpModeData
value|0x48
end_define

begin_define
define|#
directive|define
name|PCI_REG_ConfigParam1
value|0x50
end_define

begin_define
define|#
directive|define
name|PCI_REG_ConfigParam2
value|0x54
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_SETUPTEST
value|0xc6
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_READ_CONFIG
value|0xf0
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_SET_CONFIG
value|0xf1
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_SEND_CP
value|0xf2
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_RECEIVE_SP
value|0xf3
end_define

begin_define
define|#
directive|define
name|EATA_CMD_PIO_TRUNC
value|0xf4
end_define

begin_define
define|#
directive|define
name|EATA_CMD_RESET
value|0xf9
end_define

begin_define
define|#
directive|define
name|EATA_CMD_IMMEDIATE
value|0xfa
end_define

begin_define
define|#
directive|define
name|EATA_CMD_DMA_READ_CONFIG
value|0xfd
end_define

begin_define
define|#
directive|define
name|EATA_CMD_DMA_SET_CONFIG
value|0xfe
end_define

begin_define
define|#
directive|define
name|EATA_CMD_DMA_SEND_CP
value|0xff
end_define

begin_define
define|#
directive|define
name|ECS_EMULATE_SENSE
value|0xd4
end_define

begin_comment
comment|/*  * Immediate Commands  * Beware of this enumeration.	Not all commands are in sequence!  */
end_comment

begin_enum
enum|enum
block|{
name|EATA_GENERIC_ABORT
block|,
name|EATA_SPECIFIC_RESET
block|,
name|EATA_BUS_RESET
block|,
name|EATA_SPECIFIC_ABORT
block|,
name|EATA_QUIET_INTR
block|,
name|EATA_SMART_ROM_DL_EN
block|,
name|EATA_COLD_BOOT_HBA
block|,
comment|/* Only as a last resort	*/
name|EATA_FORCE_IO
block|,
name|EATA_SCSI_BUS_OFFLINE
block|,
name|EATA_RESET_MASKED_BUS
block|,
name|EATA_POWER_OFF_WARN
block|}
name|dpt_immediate_cmd
enum|;
end_enum

begin_define
define|#
directive|define
name|HA_CTRLREG
value|0x206
end_define

begin_comment
comment|/* control register for HBA */
end_comment

begin_define
define|#
directive|define
name|HA_CTRL_DISINT
value|0x02
end_define

begin_comment
comment|/* CTRLREG: disable interrupts */
end_comment

begin_define
define|#
directive|define
name|HA_CTRL_RESCPU
value|0x04
end_define

begin_comment
comment|/* CTRLREG: reset processo */
end_comment

begin_define
define|#
directive|define
name|HA_CTRL_8HEADS
value|0x08
end_define

begin_comment
comment|/* CTRLREG: set for drives with 				       *>=8 heads 				       * (WD1003 rudimentary :-) */
end_comment

begin_define
define|#
directive|define
name|HA_WCOMMAND
value|0x07
end_define

begin_comment
comment|/* command register offset	*/
end_comment

begin_define
define|#
directive|define
name|HA_WIFC
value|0x06
end_define

begin_comment
comment|/* immediate command offset	*/
end_comment

begin_define
define|#
directive|define
name|HA_WCODE
value|0x05
end_define

begin_define
define|#
directive|define
name|HA_WCODE2
value|0x04
end_define

begin_define
define|#
directive|define
name|HA_WDMAADDR
value|0x02
end_define

begin_comment
comment|/* DMA address LSB offset	*/
end_comment

begin_define
define|#
directive|define
name|HA_RERROR
value|0x01
end_define

begin_comment
comment|/* Error Register, offset 1 from base */
end_comment

begin_define
define|#
directive|define
name|HA_RAUXSTAT
value|0x08
end_define

begin_comment
comment|/* aux status register offset */
end_comment

begin_define
define|#
directive|define
name|HA_RSTATUS
value|0x07
end_define

begin_comment
comment|/* status register offset	*/
end_comment

begin_define
define|#
directive|define
name|HA_RDATA
value|0x00
end_define

begin_comment
comment|/* data register (16bit)	*/
end_comment

begin_define
define|#
directive|define
name|HA_WDATA
value|0x00
end_define

begin_comment
comment|/* data register (16bit)	*/
end_comment

begin_define
define|#
directive|define
name|HA_ABUSY
value|0x01
end_define

begin_comment
comment|/* aux busy bit		*/
end_comment

begin_define
define|#
directive|define
name|HA_AIRQ
value|0x02
end_define

begin_comment
comment|/* aux IRQ pending bit	*/
end_comment

begin_define
define|#
directive|define
name|HA_SERROR
value|0x01
end_define

begin_comment
comment|/* pr. command ended in error */
end_comment

begin_define
define|#
directive|define
name|HA_SMORE
value|0x02
end_define

begin_comment
comment|/* more data soon to come	*/
end_comment

begin_define
define|#
directive|define
name|HA_SCORR
value|0x04
end_define

begin_comment
comment|/* datio_addra corrected		*/
end_comment

begin_define
define|#
directive|define
name|HA_SDRQ
value|0x08
end_define

begin_comment
comment|/* data request active	*/
end_comment

begin_define
define|#
directive|define
name|HA_SSC
value|0x10
end_define

begin_comment
comment|/* seek complete		*/
end_comment

begin_define
define|#
directive|define
name|HA_SFAULT
value|0x20
end_define

begin_comment
comment|/* write fault		*/
end_comment

begin_define
define|#
directive|define
name|HA_SREADY
value|0x40
end_define

begin_comment
comment|/* drive ready		*/
end_comment

begin_define
define|#
directive|define
name|HA_SBUSY
value|0x80
end_define

begin_comment
comment|/* drive busy		*/
end_comment

begin_define
define|#
directive|define
name|HA_SDRDY
value|HA_SSC+HA_SREADY+HA_SDRQ
end_define

begin_comment
comment|/*  * Message definitions	  */
end_comment

begin_enum
enum|enum
block|{
name|HA_NO_ERROR
block|,
comment|/* No Error				*/
name|HA_ERR_SEL_TO
block|,
comment|/* Selection Timeout			*/
name|HA_ERR_CMD_TO
block|,
comment|/* Command Timeout			*/
name|HA_SCSIBUS_RESET
block|,
name|HA_HBA_POWER_UP
block|,
comment|/* Initial Controller Power-up		*/
name|HA_UNX_BUSPHASE
block|,
comment|/* Unexpected Bus Phase			*/
name|HA_UNX_BUS_FREE
block|,
comment|/* Unexpected Bus Free			*/
name|HA_BUS_PARITY
block|,
comment|/* Bus Parity Error			*/
name|HA_SCSI_HUNG
block|,
comment|/* SCSI Hung				*/
name|HA_UNX_MSGRJCT
block|,
comment|/* Unexpected Message Rejected		*/
name|HA_RESET_STUCK
block|,
comment|/* SCSI Bus Reset Stuck			*/
name|HA_RSENSE_FAIL
block|,
comment|/* Auto Request-Sense Failed		*/
name|HA_PARITY_ERR
block|,
comment|/* Controller Ram Parity Error		*/
name|HA_CP_ABORT_NA
block|,
comment|/* Abort Message sent to non-active cmd */
name|HA_CP_ABORTED
block|,
comment|/* Abort Message sent to active cmd	*/
name|HA_CP_RESET_NA
block|,
comment|/* Reset Message sent to non-active cmd */
name|HA_CP_RESET
block|,
comment|/* Reset Message sent to active cmd	*/
name|HA_ECC_ERR
block|,
comment|/* Controller Ram ECC Error		*/
name|HA_PCI_PARITY
block|,
comment|/* PCI Parity Error			*/
name|HA_PCI_MABORT
block|,
comment|/* PCI Master Abort			*/
name|HA_PCI_TABORT
block|,
comment|/* PCI Target Abort			*/
name|HA_PCI_STABORT
comment|/* PCI Signaled Target Abort		*/
block|}
name|dpt_message
enum|;
end_enum

begin_define
define|#
directive|define
name|HA_INTR_OFF
value|1
end_define

begin_define
define|#
directive|define
name|HA_INTR_ON
value|0
end_define

begin_comment
comment|/* IOCTL List */
end_comment

begin_define
define|#
directive|define
name|DPT_RW_CMD_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DPT_RW_CMD_DUMP_SOFTC
value|"dump softc"
end_define

begin_define
define|#
directive|define
name|DPT_RW_CMD_DUMP_SYSINFO
value|"dump sysinfo"
end_define

begin_define
define|#
directive|define
name|DPT_RW_CMD_DUMP_METRICS
value|"dump metrics"
end_define

begin_define
define|#
directive|define
name|DPT_RW_CMD_CLEAR_METRICS
value|"clear metrics"
end_define

begin_define
define|#
directive|define
name|DPT_RW_CMD_SHOW_LED
value|"show LED"
end_define

begin_define
define|#
directive|define
name|DPT_IOCTL_DRIVER
value|0X80000000
end_define

begin_define
define|#
directive|define
name|DPT_IOCTL_INTERNAL_METRICS
value|(DPT_IOCTL_DRIVER | 0x00000001)
end_define

begin_define
define|#
directive|define
name|DPT_IOCTL_SOFTC
value|(DPT_IOCTL_DRIVER | 0x00000002)
end_define

begin_define
define|#
directive|define
name|DPT_IOCTL_SEND
value|(DPT_IOCTL_DRIVER | 0x00000004)
end_define

begin_comment
comment|/*  *	Other	definitions  */
end_comment

begin_define
define|#
directive|define
name|DptChannel
parameter_list|(
name|unit
parameter_list|,
name|bus
parameter_list|)
value|((bus) % (((unit) + 1) * 4))
end_define

begin_define
define|#
directive|define
name|DPT_HCP_LENGTH
parameter_list|(
name|page
parameter_list|)
value|(ntohs(*(int16_t *)(void *)(&page[2]))+4)
end_define

begin_define
define|#
directive|define
name|DPT_HCP_FIRST
parameter_list|(
name|page
parameter_list|)
value|(&page[4])
end_define

begin_define
define|#
directive|define
name|DPT_HCP_NEXT
parameter_list|(
name|param
parameter_list|)
value|(&param[3 + param[3] + 1])
end_define

begin_define
define|#
directive|define
name|DPT_HCP_CODE
parameter_list|(
name|param
parameter_list|)
value|(ntohs(*(int16_t *)(void *)param))
end_define

begin_comment
comment|/* HBA's Status port (register) bitmap */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|reg_bit
block|{
comment|/* reading this one will clear the interrupt */
name|u_int8_t
name|error
range|:
literal|1
decl_stmt|,
comment|/* previous command ended in an error */
name|more
range|:
literal|1
decl_stmt|,
comment|/* More DATA coming soon 			 * Poll BSY& DRQ (PIO) 			 */
name|corr
range|:
literal|1
decl_stmt|,
comment|/* 			 * data read was successfully corrected with 			 * ECC 			 */
name|drq
range|:
literal|1
decl_stmt|,
comment|/* data request active */
name|sc
range|:
literal|1
decl_stmt|,
comment|/* seek complete */
name|fault
range|:
literal|1
decl_stmt|,
comment|/* write fault */
name|ready
range|:
literal|1
decl_stmt|,
comment|/* drive ready */
name|busy
range|:
literal|1
decl_stmt|;
comment|/* controller busy */
block|}
name|dpt_status_reg_t
typedef|;
end_typedef

begin_comment
comment|/* HBA's Auxiliary status port (register) bitmap */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|reg_abit
block|{
comment|/* reading this won't clear the interrupt */
name|u_int8_t
name|abusy
range|:
literal|1
decl_stmt|,
comment|/* auxiliary busy */
name|irq
range|:
literal|1
decl_stmt|,
comment|/* set when drive interrupt is asserted	*/
name|dummy
range|:
literal|6
decl_stmt|;
block|}
name|dpt_aux_status_t
typedef|;
end_typedef

begin_comment
comment|/* The whole Register Set as a structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|eata_register
block|{
comment|/* EATA register set */
name|u_int8_t
name|data_reg
index|[
literal|2
index|]
decl_stmt|;
comment|/* R, couldn't figure this one out */
name|u_int8_t
name|cp_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* W, CP address register */
union|union
block|{
name|u_int8_t
name|command
decl_stmt|;
comment|/*  					* W, command code: [read|set] conf, 					* send CP 					*/
name|struct
name|reg_bit
name|status
decl_stmt|;
comment|/* R, see register_bit1 */
name|u_int8_t
name|statusbyte
decl_stmt|;
block|}
name|ovr
union|;
name|struct
name|reg_abit
name|aux_stat
decl_stmt|;
comment|/* R, see register_bit2			*/
block|}
name|eata_reg_t
typedef|;
end_typedef

begin_comment
comment|/* Holds the results of a READ_CONFIGURATION command  * Beware of data items which are larger than 1 byte.  * these come from the DPT in network order.  * On an Intel ``CPU'' they will be upside down and backwards!  * The dpt_get_conf function is normally responsible for flipping  * Everything back.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|get_conf
block|{
comment|/* Read Configuration Array */
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|foo_DevType
decl_stmt|;
name|u_int8_t
name|foo_PageCode
decl_stmt|;
name|u_int8_t
name|foo_Reserved0
decl_stmt|;
name|u_int8_t
name|foo_len
decl_stmt|;
block|}
name|foo
struct|;
name|u_int32_t
name|foo_length
decl_stmt|;
comment|/* Should return 0x22, 0x24, etc */
block|}
name|bar
union|;
define|#
directive|define
name|gcs_length
value|bar.foo_length
define|#
directive|define
name|gcs_PageCode
value|bar.foo.foo_DevType
define|#
directive|define
name|gcs_reserved0
value|bar.foo.foo_Reserved0
define|#
directive|define
name|gcs_len
value|bar.foo.foo_len
name|u_int32_t
name|signature
decl_stmt|;
comment|/* Signature MUST be "EATA".	ntohl()`ed */
name|u_int8_t
name|version2
range|:
literal|4
decl_stmt|,
name|version
range|:
literal|4
decl_stmt|;
comment|/* EATA Version level */
name|u_int8_t
name|OCS_enabled
range|:
literal|1
decl_stmt|,
comment|/* Overlap Command Support enabled */
name|TAR_support
range|:
literal|1
decl_stmt|,
comment|/* SCSI Target Mode supported */
name|TRNXFR
range|:
literal|1
decl_stmt|,
comment|/*  			 * Truncate Transfer Cmd not necessary Only 			 * used in PIO Mode 			 */
name|MORE_support
range|:
literal|1
decl_stmt|,
comment|/* MORE supported (only PIO Mode) */
name|DMA_support
range|:
literal|1
decl_stmt|,
comment|/* DMA supported Driver uses only this mode */
name|DMA_valid
range|:
literal|1
decl_stmt|,
comment|/* DRQ value in Byte 30 is valid */
name|ATA
range|:
literal|1
decl_stmt|,
comment|/* ATA device connected (not supported)	*/
name|HAA_valid
range|:
literal|1
decl_stmt|;
comment|/* Hostadapter Address is valid */
name|u_int16_t
name|cppadlen
decl_stmt|;
comment|/* 			 * Number of pad bytes send after CD data set 			 * to zero for DMA commands. Ntohl()`ed 			 */
name|u_int8_t
name|scsi_idS
decl_stmt|;
comment|/* SCSI ID of controller 2-0 Byte 0 res. */
name|u_int8_t
name|scsi_id2
decl_stmt|;
comment|/* If not, zero is returned */
name|u_int8_t
name|scsi_id1
decl_stmt|;
name|u_int8_t
name|scsi_id0
decl_stmt|;
name|u_int32_t
name|cplen
decl_stmt|;
comment|/* CP length: number of valid cp bytes	*/
name|u_int32_t
name|splen
decl_stmt|;
comment|/* 			 * Number of bytes returned after we receive 			 * SP command 			 */
name|u_int16_t
name|queuesiz
decl_stmt|;
comment|/* max number of queueable CPs */
name|u_int16_t
name|dummy
decl_stmt|;
name|u_int16_t
name|SGsiz
decl_stmt|;
comment|/* max number of SG table entrie */
name|u_int8_t
name|IRQ
range|:
literal|4
decl_stmt|,
comment|/* IRQ used this HBA */
name|IRQ_TR
range|:
literal|1
decl_stmt|,
comment|/* IRQ Trigger: 0=edge, 1=level	 */
name|SECOND
range|:
literal|1
decl_stmt|,
comment|/* This is a secondary controller */
name|DMA_channel
range|:
literal|2
decl_stmt|;
comment|/* DRQ index, DRQ is 2comp of DRQX */
name|u_int8_t
name|sync
decl_stmt|;
comment|/* 				 * device at ID 7 tru 0 is running in 				 * synchronous mode, this will disappear 				 */
name|u_int8_t
name|DSBLE
range|:
literal|1
decl_stmt|,
comment|/* ISA i/o addressing is disabled */
name|FORCADR
range|:
literal|1
decl_stmt|,
comment|/* i/o address has been forced */
name|SG_64K
range|:
literal|1
decl_stmt|,
name|SG_UAE
range|:
literal|1
decl_stmt|,
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|MAX_ID
range|:
literal|5
decl_stmt|,
comment|/* Max number of SCSI target IDs */
name|MAX_CHAN
range|:
literal|3
decl_stmt|;
comment|/* Number of SCSI busses on HBA	 */
name|u_int8_t
name|MAX_LUN
decl_stmt|;
comment|/* Max number of LUNs */
name|u_int8_t
label|:
literal|3
operator|,
name|AUTOTRM
operator|:
literal|1
operator|,
name|M1_inst
operator|:
literal|1
operator|,
name|ID_qest
operator|:
literal|1
operator|,
comment|/* Raidnum ID is questionable */
name|is_PCI
operator|:
literal|1
operator|,
comment|/* HBA is PCI */
name|is_EISA
operator|:
literal|1
expr_stmt|;
comment|/* HBA is EISA */
name|u_int8_t
name|RAIDNUM
decl_stmt|;
comment|/* unique HBA identifier */
name|u_int8_t
name|unused
index|[
literal|4
index|]
decl_stmt|;
comment|/* When doing PIO, you	GET 512 bytes */
comment|/*>>------>>	End of The DPT structure<<------<< */
name|u_int32_t
name|length
decl_stmt|;
comment|/* True length, after ntohl conversion	*/
block|}
name|dpt_conf_t
typedef|;
end_typedef

begin_comment
comment|/* Scatter-Gather list entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpt_sg_segment
block|{
name|u_int32_t
name|seg_addr
decl_stmt|;
comment|/* Network order physaddr Comes BEFORE length! */
name|u_int32_t
name|seg_len
decl_stmt|;
block|}
name|dpt_sg_t
typedef|;
end_typedef

begin_comment
comment|/* Status Packet */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|eata_sp
block|{
name|u_int8_t
name|hba_stat
range|:
literal|7
decl_stmt|,
comment|/* HBA status */
name|EOC
range|:
literal|1
decl_stmt|;
comment|/* True if command finished */
name|u_int8_t
name|scsi_stat
decl_stmt|;
comment|/* Target SCSI status */
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|residue_len
decl_stmt|;
comment|/* Number of bytes not transferred */
name|void
modifier|*
name|ccb
decl_stmt|;
comment|/* ``Just a signature''	*/
name|u_int8_t
name|sp_ID_Message
decl_stmt|;
name|u_int8_t
name|sp_Que_Message
decl_stmt|;
name|u_int8_t
name|sp_Tag_Message
decl_stmt|;
name|u_int8_t
name|msg
index|[
literal|9
index|]
decl_stmt|;
block|}
name|dpt_sp_t
typedef|;
end_typedef

begin_comment
comment|/*  * A strange collection of O/S-Hardware releated bits and pieces.  * Used by the dpt_ioctl() entry point to return DPT_SYSINFO command.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpt_drive_parameters
block|{
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* U pto 1024 */
name|u_int8_t
name|heads
decl_stmt|;
comment|/* U pto 255  */
name|u_int8_t
name|sectors
decl_stmt|;
comment|/* Up to 63   */
block|}
name|dpt_drive_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|driveParam_S
name|driveParam_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SI_CMOS_Valid
value|0x0001
end_define

begin_define
define|#
directive|define
name|SI_NumDrivesValid
value|0x0002
end_define

begin_define
define|#
directive|define
name|SI_ProcessorValid
value|0x0004
end_define

begin_define
define|#
directive|define
name|SI_MemorySizeValid
value|0x0008
end_define

begin_define
define|#
directive|define
name|SI_DriveParamsValid
value|0x0010
end_define

begin_define
define|#
directive|define
name|SI_SmartROMverValid
value|0x0020
end_define

begin_define
define|#
directive|define
name|SI_OSversionValid
value|0x0040
end_define

begin_define
define|#
directive|define
name|SI_OSspecificValid
value|0x0080
end_define

begin_define
define|#
directive|define
name|SI_BusTypeValid
value|0x0100
end_define

begin_define
define|#
directive|define
name|SI_ALL_VALID
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|SI_NO_SmartROM
value|0x8000
end_define

begin_define
define|#
directive|define
name|SI_ISA_BUS
value|0x00
end_define

begin_define
define|#
directive|define
name|SI_MCA_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|SI_EISA_BUS
value|0x02
end_define

begin_define
define|#
directive|define
name|SI_PCI_BUS
value|0x04
end_define

begin_define
define|#
directive|define
name|HBA_BUS_ISA
value|0x00
end_define

begin_define
define|#
directive|define
name|HBA_BUS_EISA
value|0x01
end_define

begin_define
define|#
directive|define
name|HBA_BUS_PCI
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|dpt_sysinfo
block|{
name|u_int8_t
name|drive0CMOS
decl_stmt|;
comment|/* CMOS Drive 0 Type */
name|u_int8_t
name|drive1CMOS
decl_stmt|;
comment|/* CMOS Drive 1 Type */
name|u_int8_t
name|numDrives
decl_stmt|;
comment|/* 0040:0075 contents */
name|u_int8_t
name|processorFamily
decl_stmt|;
comment|/* Same as DPTSIG definition */
name|u_int8_t
name|processorType
decl_stmt|;
comment|/* Same as DPTSIG definition */
name|u_int8_t
name|smartROMMajorVersion
decl_stmt|;
name|u_int8_t
name|smartROMMinorVersion
decl_stmt|;
comment|/* SmartROM version */
name|u_int8_t
name|smartROMRevision
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
comment|/* See bit definitions above */
name|u_int16_t
name|conventionalMemSize
decl_stmt|;
comment|/* in KB */
name|u_int32_t
name|extendedMemSize
decl_stmt|;
comment|/* in KB */
name|u_int32_t
name|osType
decl_stmt|;
comment|/* Same as DPTSIG definition */
name|u_int8_t
name|osMajorVersion
decl_stmt|;
name|u_int8_t
name|osMinorVersion
decl_stmt|;
comment|/* The OS version */
name|u_int8_t
name|osRevision
decl_stmt|;
name|u_int8_t
name|osSubRevision
decl_stmt|;
name|u_int8_t
name|busType
decl_stmt|;
comment|/* See defininitions above */
name|u_int8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* For alignment */
name|dpt_drive_t
name|drives
index|[
literal|16
index|]
decl_stmt|;
comment|/* SmartROM Logical Drives */
block|}
name|dpt_sysinfo_t
typedef|;
end_typedef

begin_comment
comment|/* SEND_COMMAND packet structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|eata_ccb
block|{
comment|/* Send Command Packet structure */
name|u_int8_t
name|SCSI_Reset
range|:
literal|1
decl_stmt|,
comment|/* Cause a SCSI Bus reset on the cmd */
name|HBA_Init
range|:
literal|1
decl_stmt|,
comment|/* Cause Controller to reinitialize */
name|Auto_Req_Sen
range|:
literal|1
decl_stmt|,
comment|/* Do Auto Request Sense on errors */
name|scatter
range|:
literal|1
decl_stmt|,
comment|/* Data Ptr points to a SG Packet */
name|Quick
range|:
literal|1
decl_stmt|,
comment|/* Set this one for NO Status PAcket */
name|Interpret
range|:
literal|1
decl_stmt|,
comment|/* Interpret the SCSI cdb of own use */
name|DataOut
range|:
literal|1
decl_stmt|,
comment|/* Data Out phase with command */
name|DataIn
range|:
literal|1
decl_stmt|;
comment|/* Data In phase with command */
name|u_int8_t
name|reqlen
decl_stmt|;
comment|/* Request Sense Length Valid if Auto_Req_Sen=1 */
name|u_int8_t
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|FWNEST
range|:
literal|1
decl_stmt|,
comment|/* send cmd to phys RAID component */
name|unused2
range|:
literal|7
decl_stmt|;
name|u_int8_t
name|Phsunit
range|:
literal|1
decl_stmt|,
comment|/* physical unit on mirrored pair */
name|I_AT
range|:
literal|1
decl_stmt|,
comment|/* inhibit address translation  */
name|Disable_Cache
range|:
literal|1
decl_stmt|,
comment|/* HBA inhibit caching */
name|unused3
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|cp_id
range|:
literal|5
decl_stmt|,
comment|/* SCSI Device ID of target */
name|cp_channel
range|:
literal|3
decl_stmt|;
comment|/* SCSI Channel # of HBA */
name|u_int8_t
name|cp_LUN
range|:
literal|3
decl_stmt|,
range|:
literal|2
decl_stmt|,
name|cp_luntar
range|:
literal|1
decl_stmt|,
comment|/* CP is for target ROUTINE */
name|cp_dispri
range|:
literal|1
decl_stmt|,
comment|/* Grant disconnect privilege */
name|cp_identify
range|:
literal|1
decl_stmt|;
comment|/* Always TRUE */
name|u_int8_t
name|cp_msg
index|[
literal|3
index|]
decl_stmt|;
comment|/* Message bytes 0-3 */
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|x_scsi_cmd
decl_stmt|;
comment|/* Partial SCSI CDB def */
name|u_int8_t
name|x_extent
range|:
literal|1
decl_stmt|,
name|x_bytchk
range|:
literal|1
decl_stmt|,
name|x_reladr
range|:
literal|1
decl_stmt|,
name|x_cmplst
range|:
literal|1
decl_stmt|,
name|x_fmtdata
range|:
literal|1
decl_stmt|,
name|x_lun
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|x_page
decl_stmt|;
name|u_int8_t
name|reserved4
decl_stmt|;
name|u_int8_t
name|x_len
decl_stmt|;
name|u_int8_t
name|x_link
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|x_flag
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|reserved5
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|x_vendor
range|:
literal|2
decl_stmt|;
block|}
name|x
struct|;
name|u_int8_t
name|z
index|[
literal|12
index|]
decl_stmt|;
comment|/* Command Descriptor Block (= 12) */
block|}
name|cp_w
union|;
define|#
directive|define
name|cp_cdb
value|cp_w.z
define|#
directive|define
name|cp_scsi_cmd
value|cp_w.x.x_scsi_cmd
define|#
directive|define
name|cp_extent
value|cp_w.x.x_extent
define|#
directive|define
name|cp_lun
value|cp_w.x.x_lun
define|#
directive|define
name|cp_page
value|cp_w.x.x_page
define|#
directive|define
name|cp_len
value|cp_w.x.x_len
define|#
directive|define
name|MULTIFUNCTION_CMD
value|0x0e
comment|/* SCSI Multi Function Cmd    */
define|#
directive|define
name|BUS_QUIET
value|0x04
comment|/* Quite Scsi Bus Code        */
define|#
directive|define
name|BUS_UNQUIET
value|0x05
comment|/* Un Quiet Scsi Bus Code     */
name|u_int32_t
name|cp_datalen
decl_stmt|;
comment|/* Data Transfer Length. If scatter=1 len (IN 				 * BYTES!) of the S/G array */
name|u_int32_t
name|cp_viraddr
decl_stmt|;
comment|/* address of this ccb (unique tag)	*/
name|u_int32_t
name|cp_dataDMA
decl_stmt|;
comment|/* Data Address, if scatter=1 then it is the 				* address of scatter packet */
name|u_int32_t
name|cp_statDMA
decl_stmt|;
comment|/* address for Status Packet */
name|u_int32_t
name|cp_reqDMA
decl_stmt|;
comment|/* 				 * Request Sense Address, used if CP command 				 * ends with error 				 */
block|}
name|eata_ccb_t
typedef|;
end_typedef

begin_comment
comment|/*   * DPT Signature Structure.  * Used by /dev/dpt to directly pass commands to the HBA  * We hae more information here than we care for...  */
end_comment

begin_comment
comment|/* Current Signature Version - sigBYTE dsSigVersion; */
end_comment

begin_define
define|#
directive|define
name|SIG_VERSION
value|1
end_define

begin_comment
comment|/*   * Processor Family - sigBYTE dsProcessorFamily;	DISTINCT VALUE   *  * What type of processor the file is meant to run on.  * This will let us know whether to read sigWORDs as high/low or low/high.  */
end_comment

begin_define
define|#
directive|define
name|PROC_INTEL
value|0x00
end_define

begin_comment
comment|/* Intel 80x86 */
end_comment

begin_define
define|#
directive|define
name|PROC_MOTOROLA
value|0x01
end_define

begin_comment
comment|/* Motorola 68K */
end_comment

begin_define
define|#
directive|define
name|PROC_MIPS4000
value|0x02
end_define

begin_comment
comment|/* MIPS RISC 4000 */
end_comment

begin_define
define|#
directive|define
name|PROC_ALPHA
value|0x03
end_define

begin_comment
comment|/* DEC Alpha */
end_comment

begin_comment
comment|/*   * Specific Minimim Processor - sigBYTE dsProcessor; FLAG BITS   *  * Different bit definitions dependent on processor_family  */
end_comment

begin_comment
comment|/* PROC_INTEL: */
end_comment

begin_define
define|#
directive|define
name|PROC_8086
value|0x01
end_define

begin_comment
comment|/* Intel 8086 */
end_comment

begin_define
define|#
directive|define
name|PROC_286
value|0x02
end_define

begin_comment
comment|/* Intel 80286 */
end_comment

begin_define
define|#
directive|define
name|PROC_386
value|0x04
end_define

begin_comment
comment|/* Intel 80386 */
end_comment

begin_define
define|#
directive|define
name|PROC_486
value|0x08
end_define

begin_comment
comment|/* Intel 80486 */
end_comment

begin_define
define|#
directive|define
name|PROC_PENTIUM
value|0x10
end_define

begin_comment
comment|/* Intel 586 aka P5 aka Pentium */
end_comment

begin_define
define|#
directive|define
name|PROC_P6
value|0x20
end_define

begin_comment
comment|/* Intel 686 aka P6 */
end_comment

begin_comment
comment|/* PROC_MOTOROLA: */
end_comment

begin_define
define|#
directive|define
name|PROC_68000
value|0x01
end_define

begin_comment
comment|/* Motorola 68000 */
end_comment

begin_define
define|#
directive|define
name|PROC_68020
value|0x02
end_define

begin_comment
comment|/* Motorola 68020 */
end_comment

begin_define
define|#
directive|define
name|PROC_68030
value|0x04
end_define

begin_comment
comment|/* Motorola 68030 */
end_comment

begin_define
define|#
directive|define
name|PROC_68040
value|0x08
end_define

begin_comment
comment|/* Motorola 68040 */
end_comment

begin_comment
comment|/* Filetype - sigBYTE dsFiletype; DISTINCT VALUES */
end_comment

begin_define
define|#
directive|define
name|FT_EXECUTABLE
value|0
end_define

begin_comment
comment|/* Executable Program */
end_comment

begin_define
define|#
directive|define
name|FT_SCRIPT
value|1
end_define

begin_comment
comment|/* Script/Batch File??? */
end_comment

begin_define
define|#
directive|define
name|FT_HBADRVR
value|2
end_define

begin_comment
comment|/* HBA Driver */
end_comment

begin_define
define|#
directive|define
name|FT_OTHERDRVR
value|3
end_define

begin_comment
comment|/* Other Driver */
end_comment

begin_define
define|#
directive|define
name|FT_IFS
value|4
end_define

begin_comment
comment|/* Installable Filesystem Driver */
end_comment

begin_define
define|#
directive|define
name|FT_ENGINE
value|5
end_define

begin_comment
comment|/* DPT Engine */
end_comment

begin_define
define|#
directive|define
name|FT_COMPDRVR
value|6
end_define

begin_comment
comment|/* Compressed Driver Disk */
end_comment

begin_define
define|#
directive|define
name|FT_LANGUAGE
value|7
end_define

begin_comment
comment|/* Foreign Language file */
end_comment

begin_define
define|#
directive|define
name|FT_FIRMWARE
value|8
end_define

begin_comment
comment|/* Downloadable or actual Firmware */
end_comment

begin_define
define|#
directive|define
name|FT_COMMMODL
value|9
end_define

begin_comment
comment|/* Communications Module */
end_comment

begin_define
define|#
directive|define
name|FT_INT13
value|10
end_define

begin_comment
comment|/* INT 13 style HBA Driver */
end_comment

begin_define
define|#
directive|define
name|FT_HELPFILE
value|11
end_define

begin_comment
comment|/* Help file */
end_comment

begin_define
define|#
directive|define
name|FT_LOGGER
value|12
end_define

begin_comment
comment|/* Event Logger */
end_comment

begin_define
define|#
directive|define
name|FT_INSTALL
value|13
end_define

begin_comment
comment|/* An Install Program */
end_comment

begin_define
define|#
directive|define
name|FT_LIBRARY
value|14
end_define

begin_comment
comment|/* Storage Manager Real-Mode Calls */
end_comment

begin_define
define|#
directive|define
name|FT_RESOURCE
value|15
end_define

begin_comment
comment|/* Storage Manager Resource File */
end_comment

begin_define
define|#
directive|define
name|FT_MODEM_DB
value|16
end_define

begin_comment
comment|/* Storage Manager Modem Database */
end_comment

begin_comment
comment|/* Filetype flags - sigBYTE dsFiletypeFlags;		FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|FTF_DLL
value|0x01
end_define

begin_comment
comment|/* Dynamic Link Library */
end_comment

begin_define
define|#
directive|define
name|FTF_NLM
value|0x02
end_define

begin_comment
comment|/* Netware Loadable Module */
end_comment

begin_define
define|#
directive|define
name|FTF_OVERLAYS
value|0x04
end_define

begin_comment
comment|/* Uses overlays */
end_comment

begin_define
define|#
directive|define
name|FTF_DEBUG
value|0x08
end_define

begin_comment
comment|/* Debug version */
end_comment

begin_define
define|#
directive|define
name|FTF_TSR
value|0x10
end_define

begin_comment
comment|/* TSR */
end_comment

begin_define
define|#
directive|define
name|FTF_SYS
value|0x20
end_define

begin_comment
comment|/* DOS Lodable driver */
end_comment

begin_define
define|#
directive|define
name|FTF_PROTECTED
value|0x40
end_define

begin_comment
comment|/* Runs in protected mode */
end_comment

begin_define
define|#
directive|define
name|FTF_APP_SPEC
value|0x80
end_define

begin_comment
comment|/* Application Specific */
end_comment

begin_comment
comment|/* OEM - sigBYTE dsOEM;		DISTINCT VALUES */
end_comment

begin_define
define|#
directive|define
name|OEM_DPT
value|0
end_define

begin_comment
comment|/* DPT */
end_comment

begin_define
define|#
directive|define
name|OEM_ATT
value|1
end_define

begin_comment
comment|/* ATT */
end_comment

begin_define
define|#
directive|define
name|OEM_NEC
value|2
end_define

begin_comment
comment|/* NEC */
end_comment

begin_define
define|#
directive|define
name|OEM_ALPHA
value|3
end_define

begin_comment
comment|/* Alphatronix */
end_comment

begin_define
define|#
directive|define
name|OEM_AST
value|4
end_define

begin_comment
comment|/* AST */
end_comment

begin_define
define|#
directive|define
name|OEM_OLIVETTI
value|5
end_define

begin_comment
comment|/* Olivetti */
end_comment

begin_define
define|#
directive|define
name|OEM_SNI
value|6
end_define

begin_comment
comment|/* Siemens/Nixdorf */
end_comment

begin_comment
comment|/* Operating System	- sigLONG dsOS;		FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|OS_DOS
value|0x00000001
end_define

begin_comment
comment|/* PC/MS-DOS */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS
value|0x00000002
end_define

begin_comment
comment|/* Microsoft Windows 3.x */
end_comment

begin_define
define|#
directive|define
name|OS_WINDOWS_NT
value|0x00000004
end_define

begin_comment
comment|/* Microsoft Windows NT */
end_comment

begin_define
define|#
directive|define
name|OS_OS2M
value|0x00000008
end_define

begin_comment
comment|/* OS/2 1.2.x,MS 1.3.0,IBM 1.3.x */
end_comment

begin_define
define|#
directive|define
name|OS_OS2L
value|0x00000010
end_define

begin_comment
comment|/* Microsoft OS/2 1.301 - LADDR */
end_comment

begin_define
define|#
directive|define
name|OS_OS22x
value|0x00000020
end_define

begin_comment
comment|/* IBM OS/2 2.x */
end_comment

begin_define
define|#
directive|define
name|OS_NW286
value|0x00000040
end_define

begin_comment
comment|/* Novell NetWare 286 */
end_comment

begin_define
define|#
directive|define
name|OS_NW386
value|0x00000080
end_define

begin_comment
comment|/* Novell NetWare 386 */
end_comment

begin_define
define|#
directive|define
name|OS_GEN_UNIX
value|0x00000100
end_define

begin_comment
comment|/* Generic Unix */
end_comment

begin_define
define|#
directive|define
name|OS_SCO_UNIX
value|0x00000200
end_define

begin_comment
comment|/* SCO Unix */
end_comment

begin_define
define|#
directive|define
name|OS_ATT_UNIX
value|0x00000400
end_define

begin_comment
comment|/* ATT Unix */
end_comment

begin_define
define|#
directive|define
name|OS_UNIXWARE
value|0x00000800
end_define

begin_comment
comment|/* UnixWare Unix */
end_comment

begin_define
define|#
directive|define
name|OS_INT_UNIX
value|0x00001000
end_define

begin_comment
comment|/* Interactive Unix */
end_comment

begin_define
define|#
directive|define
name|OS_SOLARIS
value|0x00002000
end_define

begin_comment
comment|/* SunSoft Solaris */
end_comment

begin_define
define|#
directive|define
name|OS_QNX
value|0x00004000
end_define

begin_comment
comment|/* QNX for Tom Moch */
end_comment

begin_define
define|#
directive|define
name|OS_NEXTSTEP
value|0x00008000
end_define

begin_comment
comment|/* NeXTSTEP */
end_comment

begin_define
define|#
directive|define
name|OS_BANYAN
value|0x00010000
end_define

begin_comment
comment|/* Banyan Vines */
end_comment

begin_define
define|#
directive|define
name|OS_OLIVETTI_UNIX
value|0x00020000
end_define

begin_comment
comment|/* Olivetti Unix */
end_comment

begin_define
define|#
directive|define
name|OS_FREEBSD
value|0x00040000
end_define

begin_comment
comment|/* FreeBSD 2.2 and later */
end_comment

begin_define
define|#
directive|define
name|OS_OTHER
value|0x80000000
end_define

begin_comment
comment|/* Other */
end_comment

begin_comment
comment|/* Capabilities - sigWORD dsCapabilities; FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID0
value|0x0001
end_define

begin_comment
comment|/* RAID-0 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID1
value|0x0002
end_define

begin_comment
comment|/* RAID-1 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID3
value|0x0004
end_define

begin_comment
comment|/* RAID-3 */
end_comment

begin_define
define|#
directive|define
name|CAP_RAID5
value|0x0008
end_define

begin_comment
comment|/* RAID-5 */
end_comment

begin_define
define|#
directive|define
name|CAP_SPAN
value|0x0010
end_define

begin_comment
comment|/* Spanning */
end_comment

begin_define
define|#
directive|define
name|CAP_PASS
value|0x0020
end_define

begin_comment
comment|/* Provides passthrough */
end_comment

begin_define
define|#
directive|define
name|CAP_OVERLAP
value|0x0040
end_define

begin_comment
comment|/* Passthrough supports overlapped commands */
end_comment

begin_define
define|#
directive|define
name|CAP_ASPI
value|0x0080
end_define

begin_comment
comment|/* Supports ASPI Command Requests */
end_comment

begin_define
define|#
directive|define
name|CAP_ABOVE16MB
value|0x0100
end_define

begin_comment
comment|/* ISA Driver supports greater than 16MB */
end_comment

begin_define
define|#
directive|define
name|CAP_EXTEND
value|0x8000
end_define

begin_comment
comment|/* Extended info appears after description */
end_comment

begin_comment
comment|/* Devices Supported - sigWORD dsDeviceSupp;		FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|DEV_DASD
value|0x0001
end_define

begin_comment
comment|/* DASD (hard drives) */
end_comment

begin_define
define|#
directive|define
name|DEV_TAPE
value|0x0002
end_define

begin_comment
comment|/* Tape drives */
end_comment

begin_define
define|#
directive|define
name|DEV_PRINTER
value|0x0004
end_define

begin_comment
comment|/* Printers */
end_comment

begin_define
define|#
directive|define
name|DEV_PROC
value|0x0008
end_define

begin_comment
comment|/* Processors */
end_comment

begin_define
define|#
directive|define
name|DEV_WORM
value|0x0010
end_define

begin_comment
comment|/* WORM drives */
end_comment

begin_define
define|#
directive|define
name|DEV_CDROM
value|0x0020
end_define

begin_comment
comment|/* CD-ROM drives */
end_comment

begin_define
define|#
directive|define
name|DEV_SCANNER
value|0x0040
end_define

begin_comment
comment|/* Scanners */
end_comment

begin_define
define|#
directive|define
name|DEV_OPTICAL
value|0x0080
end_define

begin_comment
comment|/* Optical Drives */
end_comment

begin_define
define|#
directive|define
name|DEV_JUKEBOX
value|0x0100
end_define

begin_comment
comment|/* Jukebox */
end_comment

begin_define
define|#
directive|define
name|DEV_COMM
value|0x0200
end_define

begin_comment
comment|/* Communications Devices */
end_comment

begin_define
define|#
directive|define
name|DEV_OTHER
value|0x0400
end_define

begin_comment
comment|/* Other Devices */
end_comment

begin_define
define|#
directive|define
name|DEV_ALL
value|0xFFFF
end_define

begin_comment
comment|/* All SCSI Devices */
end_comment

begin_comment
comment|/* Adapters Families Supported - sigWORD dsAdapterSupp; FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|ADF_2001
value|0x0001
end_define

begin_comment
comment|/* PM2001 */
end_comment

begin_define
define|#
directive|define
name|ADF_2012A
value|0x0002
end_define

begin_comment
comment|/* PM2012A */
end_comment

begin_define
define|#
directive|define
name|ADF_PLUS_ISA
value|0x0004
end_define

begin_comment
comment|/* PM2011,PM2021 */
end_comment

begin_define
define|#
directive|define
name|ADF_PLUS_EISA
value|0x0008
end_define

begin_comment
comment|/* PM2012B,PM2022 */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_ISA
value|0x0010
end_define

begin_comment
comment|/* PM2021 */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_EISA
value|0x0020
end_define

begin_comment
comment|/* PM2022,PM2122, etc */
end_comment

begin_define
define|#
directive|define
name|ADF_SC3_PCI
value|0x0040
end_define

begin_comment
comment|/* SmartCache III PCI */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_ISA
value|0x0080
end_define

begin_comment
comment|/* SmartCache IV ISA */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_EISA
value|0x0100
end_define

begin_comment
comment|/* SmartCache IV EISA */
end_comment

begin_define
define|#
directive|define
name|ADF_SC4_PCI
value|0x0200
end_define

begin_comment
comment|/* SmartCache IV PCI */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_MASTER
value|0xFFFE
end_define

begin_comment
comment|/* All bus mastering */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL_CACHE
value|0xFFFC
end_define

begin_comment
comment|/* All caching */
end_comment

begin_define
define|#
directive|define
name|ADF_ALL
value|0xFFFF
end_define

begin_comment
comment|/* ALL DPT adapters */
end_comment

begin_comment
comment|/* Application - sigWORD dsApplication;				FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|APP_DPTMGR
value|0x0001
end_define

begin_comment
comment|/* DPT Storage Manager */
end_comment

begin_define
define|#
directive|define
name|APP_ENGINE
value|0x0002
end_define

begin_comment
comment|/* DPT Engine */
end_comment

begin_define
define|#
directive|define
name|APP_SYTOS
value|0x0004
end_define

begin_comment
comment|/* Sytron Sytos Plus */
end_comment

begin_define
define|#
directive|define
name|APP_CHEYENNE
value|0x0008
end_define

begin_comment
comment|/* Cheyenne ARCServe + ARCSolo */
end_comment

begin_define
define|#
directive|define
name|APP_MSCDEX
value|0x0010
end_define

begin_comment
comment|/* Microsoft CD-ROM extensions */
end_comment

begin_define
define|#
directive|define
name|APP_NOVABACK
value|0x0020
end_define

begin_comment
comment|/* NovaStor Novaback */
end_comment

begin_define
define|#
directive|define
name|APP_AIM
value|0x0040
end_define

begin_comment
comment|/* Archive Information Manager */
end_comment

begin_comment
comment|/* Requirements - sigBYTE dsRequirements;	FLAG BITS */
end_comment

begin_define
define|#
directive|define
name|REQ_SMARTROM
value|0x01
end_define

begin_comment
comment|/* Requires SmartROM to be present */
end_comment

begin_define
define|#
directive|define
name|REQ_DPTDDL
value|0x02
end_define

begin_comment
comment|/* Requires DPTDDL.SYS to be loaded */
end_comment

begin_define
define|#
directive|define
name|REQ_HBA_DRIVER
value|0x04
end_define

begin_comment
comment|/* Requires an HBA driver to be loaded	*/
end_comment

begin_define
define|#
directive|define
name|REQ_ASPI_TRAN
value|0x08
end_define

begin_comment
comment|/* Requires an ASPI Transport Modules	*/
end_comment

begin_define
define|#
directive|define
name|REQ_ENGINE
value|0x10
end_define

begin_comment
comment|/* Requires a DPT Engine to be loaded	*/
end_comment

begin_define
define|#
directive|define
name|REQ_COMM_ENG
value|0x20
end_define

begin_comment
comment|/* Requires a DPT Communications Engine */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpt_sig
block|{
name|char
name|dsSignature
index|[
literal|6
index|]
decl_stmt|;
comment|/* ALWAYS "dPtSiG" */
name|u_int8_t
name|SigVersion
decl_stmt|;
comment|/* signature version (currently 1) */
name|u_int8_t
name|ProcessorFamily
decl_stmt|;
comment|/* what type of processor */
name|u_int8_t
name|Processor
decl_stmt|;
comment|/* precise processor */
name|u_int8_t
name|Filetype
decl_stmt|;
comment|/* type of file */
name|u_int8_t
name|FiletypeFlags
decl_stmt|;
comment|/* flags to specify load type, etc. */
name|u_int8_t
name|OEM
decl_stmt|;
comment|/* OEM file was created for */
name|u_int32_t
name|OS
decl_stmt|;
comment|/* which Operating systems */
name|u_int16_t
name|Capabilities
decl_stmt|;
comment|/* RAID levels, etc. */
name|u_int16_t
name|DeviceSupp
decl_stmt|;
comment|/* Types of SCSI devices supported */
name|u_int16_t
name|AdapterSupp
decl_stmt|;
comment|/* DPT adapter families supported */
name|u_int16_t
name|Application
decl_stmt|;
comment|/* applications file is for */
name|u_int8_t
name|Requirements
decl_stmt|;
comment|/* Other driver dependencies */
name|u_int8_t
name|Version
decl_stmt|;
comment|/* 1 */
name|u_int8_t
name|Revision
decl_stmt|;
comment|/* 'J' */
name|u_int8_t
name|SubRevision
decl_stmt|;
comment|/* '9'	' ' if N/A */
name|u_int8_t
name|Month
decl_stmt|;
comment|/* creation month */
name|u_int8_t
name|Day
decl_stmt|;
comment|/* creation day */
name|u_int8_t
name|Year
decl_stmt|;
comment|/* creation year since 1980  */
name|char
modifier|*
name|Description
decl_stmt|;
comment|/* description (NULL terminated) */
block|}
name|dpt_sig_t
typedef|;
end_typedef

begin_comment
comment|/* 32 bytes minimum - with no description.	Put NULL at description[0] */
end_comment

begin_comment
comment|/* 81 bytes maximum - with 49 character description plus NULL. */
end_comment

begin_comment
comment|/* This line added at Roycroft's request */
end_comment

begin_comment
comment|/* Microsoft's NT compiler gets confused if you do a pack and don't */
end_comment

begin_comment
comment|/* restore it. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|eata_pass_through
block|{
name|u_int8_t
name|eataID
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|command
decl_stmt|;
define|#
directive|define
name|EATAUSRCMD
value|(('D'<<8)|65)
comment|/* EATA PassThrough Command	*/
define|#
directive|define
name|DPT_SIGNATURE
value|(('D'<<8)|67)
comment|/* Get Signature Structure */
define|#
directive|define
name|DPT_NUMCTRLS
value|(('D'<<8)|68)
comment|/* Get Number Of DPT Adapters */
define|#
directive|define
name|DPT_CTRLINFO
value|(('D'<<8)|69)
comment|/* Get Adapter Info Structure */
define|#
directive|define
name|DPT_SYSINFO
value|(('D'<<8)|72)
comment|/* Get System Info Structure	*/
define|#
directive|define
name|DPT_BLINKLED
value|(('D'<<8)|75)
comment|/* Get The BlinkLED Status */
name|u_int8_t
modifier|*
name|command_buffer
decl_stmt|;
name|eata_ccb_t
name|command_packet
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
name|u_int8_t
name|host_status
decl_stmt|;
name|u_int8_t
name|target_status
decl_stmt|;
name|u_int8_t
name|retries
decl_stmt|;
block|}
name|eata_pt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dpt_ccb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|dpt_ccb
argument_list|)
name|links
expr_stmt|;
name|struct
name|scsi_xfer
modifier|*
name|xs
decl_stmt|;
comment|/* the scsi_xfer for this cmd */
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|state
decl_stmt|;
comment|/* we need this one for user commands */
define|#
directive|define
name|DPT_CCB_STATE_COMPLETED
value|0x00000040
ifdef|#
directive|ifdef
name|DPT_TRACK_CCB_STATES
define|#
directive|define
name|DPT_CCB_STATE_FREE
value|0x00000001
define|#
directive|define
name|DPT_CCB_STATE_FREE2WAITING
value|0x00000002
define|#
directive|define
name|DPT_CCB_STATE_WAITING
value|0x00000004
define|#
directive|define
name|DPT_CCB_STATE_WAITING2SUBMITTED
value|0x00000008
define|#
directive|define
name|DPT_CCB_STATE_SUBMITTED
value|0x00000010
define|#
directive|define
name|DPT_CCB_STATE_SUBMITTED2COMPLETED
value|0x00000020
define|#
directive|define
name|DPT_CCB_STATE_COMPLETED
value|0x00000040
define|#
directive|define
name|DPT_CCB_STATE_COMPLETED2DONE
value|0x00000080
define|#
directive|define
name|DPT_CCB_STATE_COMPLETED2FREE
value|0x00000100
define|#
directive|define
name|DPT_CCB_STATE_DONE
value|0x00000200
define|#
directive|define
name|DPT_CCB_STATE_MARKED_LOST
value|0x00000400
define|#
directive|define
name|DPT_CCB_STATE_MARKED_SALVAGED
value|0x00000800
define|#
directive|define
name|DPT_CCB_STATE_ABORTED
value|0x00001000
endif|#
directive|endif
comment|/* DPT_TRACK_CCB_STATES */
ifdef|#
directive|ifdef
name|DPT_ABORT_LOSERS
define|#
directive|define
name|DPT_CCB_STATE_MARKED_LOST
value|0x00000400
endif|#
directive|endif
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
name|eata_ccb_t
name|eata_ccb
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
name|u_int8_t
name|retries
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
comment|/* status of this queueslot */
name|u_int8_t
modifier|*
name|cmd
decl_stmt|;
comment|/* address of cmd */
name|dpt_sg_t
modifier|*
name|sg_list
decl_stmt|;
specifier|volatile
name|dpt_sp_t
name|status_packet
decl_stmt|;
name|u_int8_t
name|status_reg
decl_stmt|;
name|u_int8_t
name|aux_status_reg
decl_stmt|;
name|u_int32_t
name|transaction_id
decl_stmt|;
ifdef|#
directive|ifdef
name|DPT_MEASURE_PERFORMANCE
name|u_int32_t
name|submitted_time
decl_stmt|;
name|struct
name|timeval
name|command_started
decl_stmt|,
name|command_ended
decl_stmt|;
endif|#
directive|endif
block|}
name|dpt_ccb_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is provided for compatability with UnixWare only.  * Some of the fields may be bogus.  * Others may have a totally different meaning.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpt_scsi_ha
block|{
name|u_int32_t
name|ha_state
decl_stmt|;
comment|/* Operational state */
name|u_int8_t
name|ha_id
index|[
literal|4
index|]
decl_stmt|;
comment|/* Host adapter SCSI ids */
name|int
name|ha_vect
decl_stmt|;
comment|/* Interrupt vector number */
name|int32_t
name|ha_base
decl_stmt|;
comment|/* Base I/O address */
name|int
name|ha_max_jobs
decl_stmt|;
comment|/* Max number of Active Jobs */
name|int
name|ha_cache
range|:
literal|2
decl_stmt|;
comment|/* Cache parameters */
name|int
name|ha_cachesize
range|:
literal|30
decl_stmt|;
comment|/* In meg, only if cache present*/
name|int
name|ha_nbus
decl_stmt|;
comment|/* Number Of Busses on HBA */
name|int
name|ha_ntargets
decl_stmt|;
comment|/* Number Of Targets Supported */
name|int
name|ha_nluns
decl_stmt|;
comment|/* Number Of LUNs Supported */
name|int
name|ha_tshift
decl_stmt|;
comment|/* Shift value for target */
name|int
name|ha_bshift
decl_stmt|;
comment|/* Shift value for bus */
name|int
name|ha_npend
decl_stmt|;
comment|/* # of jobs sent to HBA */
name|int
name|ha_active_jobs
decl_stmt|;
comment|/* Number Of Active Jobs	 */
name|char
name|ha_fw_version
index|[
literal|4
index|]
decl_stmt|;
comment|/* Firmware Revision Level */
name|void
modifier|*
name|ha_ccb
decl_stmt|;
comment|/* Controller command blocks */
name|void
modifier|*
name|ha_cblist
decl_stmt|;
comment|/* Command block free list */
name|void
modifier|*
name|ha_dev
decl_stmt|;
comment|/* Logical unit queues */
name|void
modifier|*
name|ha_StPkt_lock
decl_stmt|;
comment|/* Status Packet Lock */
name|void
modifier|*
name|ha_ccb_lock
decl_stmt|;
comment|/* CCB Lock */
name|void
modifier|*
name|ha_LuQWaiting
decl_stmt|;
comment|/* Lu Queue Waiting List */
name|void
modifier|*
name|ha_QWait_lock
decl_stmt|;
comment|/* Device Que Waiting Lock */
name|int
name|ha_QWait_opri
decl_stmt|;
comment|/* Saved Priority Level */
ifdef|#
directive|ifdef
name|DPT_TARGET_MODE
name|dpt_ccb_t
modifier|*
name|target_ccb
index|[
literal|4
index|]
decl_stmt|;
comment|/* Command block always waiting writebuf */
endif|#
directive|endif
block|}
name|dpt_compat_ha_t
typedef|;
end_typedef

begin_comment
comment|/*  * Describe the Inquiry Data returned on Page 0 from the Adapter. The  * Page C1 Inquiry Data is described in the DptConfig_t structure above.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|deviceType
decl_stmt|;
name|u_int8_t
name|rm_dtq
decl_stmt|;
name|u_int8_t
name|otherData
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|vendor
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|modelNum
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|firmware
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|protocol
index|[
literal|4
index|]
decl_stmt|;
block|}
name|dpt_inq_t
typedef|;
end_typedef

begin_comment
comment|/*  *			sp_EOC is not `safe', so I will check sp_Messages[0] instead!  */
end_comment

begin_define
define|#
directive|define
name|DptStat_BUSY
parameter_list|(
name|x
parameter_list|)
value|((x)->sp_ID_Message)
end_define

begin_define
define|#
directive|define
name|DptStat_Reset_BUSY
parameter_list|(
name|x
parameter_list|)
define|\
value|( (x)->msg[0] = 0xA5, (x)->EOC = 0,		\   (x)->ccb = (struct eata_ccb *)NULL )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DPT_MEASURE_PERFORMANCE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|dpt_metrics
block|{
name|u_int32_t
name|command_count
index|[
literal|256
index|]
decl_stmt|;
comment|/* We assume MAX 256 SCSI commands */
name|u_int32_t
name|max_command_time
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|min_command_time
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|min_intr_time
decl_stmt|;
name|u_int32_t
name|max_intr_time
decl_stmt|;
name|u_int32_t
name|aborted_interrupts
decl_stmt|;
name|u_int32_t
name|spurious_interrupts
decl_stmt|;
name|u_int32_t
name|max_waiting_count
decl_stmt|;
name|u_int32_t
name|max_submit_count
decl_stmt|;
name|u_int32_t
name|max_complete_count
decl_stmt|;
name|u_int32_t
name|min_waiting_time
decl_stmt|;
name|u_int32_t
name|min_submit_time
decl_stmt|;
name|u_int32_t
name|min_complete_time
decl_stmt|;
name|u_int32_t
name|max_waiting_time
decl_stmt|;
name|u_int32_t
name|max_submit_time
decl_stmt|;
name|u_int32_t
name|max_complete_time
decl_stmt|;
name|u_int32_t
name|command_collisions
decl_stmt|;
name|u_int32_t
name|command_too_busy
decl_stmt|;
name|u_int32_t
name|max_eata_tries
decl_stmt|;
name|u_int32_t
name|min_eata_tries
decl_stmt|;
name|u_int32_t
name|read_by_size_count
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_count
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|read_by_size_min_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|read_by_size_max_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_min_time
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|write_by_size_max_time
index|[
literal|10
index|]
decl_stmt|;
define|#
directive|define
name|SIZE_512
value|0
define|#
directive|define
name|SIZE_1K
value|1
define|#
directive|define
name|SIZE_2K
value|2
define|#
directive|define
name|SIZE_4K
value|3
define|#
directive|define
name|SIZE_8K
value|4
define|#
directive|define
name|SIZE_16K
value|5
define|#
directive|define
name|SIZE_32K
value|6
define|#
directive|define
name|SIZE_64K
value|7
define|#
directive|define
name|SIZE_BIGGER
value|8
define|#
directive|define
name|SIZE_OTHER
value|9
name|struct
name|timeval
name|intr_started
decl_stmt|;
block|}
name|dpt_perf_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|dpt_softc
block|{
name|int
name|unit
decl_stmt|;
comment|/*  			 * Are we /dev/dpt0. /dev/dpt1, etc? 			 * (Controller number)  			 */
name|u_int32_t
name|handle_interrupts
range|:
literal|1
decl_stmt|,
comment|/* Are we rready to do real work? */
name|spare
range|:
literal|31
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|dpt_softc
argument_list|)
name|links
expr_stmt|;
name|int
name|total_ccbs_count
decl_stmt|;
name|int
name|free_ccbs_count
decl_stmt|;
name|int
name|waiting_ccbs_count
decl_stmt|;
name|int
name|submitted_ccbs_count
decl_stmt|;
name|int
name|completed_ccbs_count
decl_stmt|;
name|u_int32_t
name|queue_status
decl_stmt|;
name|u_int32_t
name|free_lock
decl_stmt|;
name|u_int32_t
name|waiting_lock
decl_stmt|;
name|u_int32_t
name|submitted_lock
decl_stmt|;
name|u_int32_t
name|completed_lock
decl_stmt|;
define|#
directive|define
name|DPT_QUEUES_NONE_ACTIVE
value|0x00000000
define|#
directive|define
name|DPT_FREE_QUEUE_ACTIVE
value|0x00000001
define|#
directive|define
name|DPT_WAITING_QUEUE_ACTIVE
value|0x00000002
define|#
directive|define
name|DPT_SUBMITTED_QUEUE_ACTIVE
value|0x00000004
define|#
directive|define
name|DPT_COMPLETED_QUEUE_ACTIVE
value|0x00000008
define|#
directive|define
name|DPT_SINTR_ACTIVE
value|0x00000010
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dpt_ccb
argument_list|)
name|free_ccbs
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dpt_ccb
argument_list|)
name|waiting_ccbs
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dpt_ccb
argument_list|)
name|submitted_ccbs
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dpt_ccb
argument_list|)
name|completed_ccbs
expr_stmt|;
name|u_int32_t
name|commands_processed
decl_stmt|;
ifdef|#
directive|ifdef
name|DPT_MEASURE_PERFORMANCE
name|dpt_perf_t
name|performance
decl_stmt|;
endif|#
directive|endif
comment|/*      * These three parameters can be used to allow for wide scsi, and      * for host adapters that support multiple busses The first two      * should be set to 1 more than the actual max id or lun (i.e. 8 for      * normal systems).      */
name|u_int32_t
name|max_id
decl_stmt|;
name|u_int32_t
name|max_lun
decl_stmt|;
name|u_int16_t
name|io_base
decl_stmt|;
specifier|volatile
name|u_int8_t
modifier|*
name|v_membase
decl_stmt|;
specifier|volatile
name|u_int8_t
modifier|*
name|p_membase
decl_stmt|;
name|u_int8_t
name|irq
decl_stmt|;
name|u_int8_t
name|dma_channel
decl_stmt|;
comment|/* Up to 4 (3 really) busses per controller. */
name|struct
name|scsi_link
name|sc_scsi_link
index|[
literal|4
index|]
decl_stmt|;
name|dpt_inq_t
name|board_data
decl_stmt|;
name|u_int8_t
name|EATA_revision
decl_stmt|;
name|u_int8_t
name|bustype
decl_stmt|;
comment|/* bustype of HBA		*/
name|u_int8_t
name|channels
decl_stmt|;
comment|/* # of avail scsi chan.	*/
name|u_int32_t
name|state
decl_stmt|;
comment|/* state of HBA			*/
define|#
directive|define
name|DPT_HA_FREE
value|0x00000000
define|#
directive|define
name|DPT_HA_OK
value|0x00000000
define|#
directive|define
name|DPT_HA_NO_TIMEOUT
value|0x00000000
define|#
directive|define
name|DPT_HA_BUSY
value|0x00000001
define|#
directive|define
name|DPT_HA_TIMEOUT
value|0x00000002
define|#
directive|define
name|DPT_HA_RESET
value|0x00000004
define|#
directive|define
name|DPT_HA_LOCKED
value|0x00000008
define|#
directive|define
name|DPT_HA_ABORTED
value|0x00000010
define|#
directive|define
name|DPT_HA_CONTROL_ACTIVE
value|0x00000020
define|#
directive|define
name|DPT_HA_SHUTDOWN_ACTIVE
value|0x00000040
define|#
directive|define
name|DPT_HA_COMMAND_ACTIVE
value|0x00000080
define|#
directive|define
name|DPT_HA_QUIET
value|0x00000100
ifdef|#
directive|ifdef
name|DPT_HANDLE_TIMEOUTS
define|#
directive|define
name|DPT_HA_TIMEOUTS_SET
value|0x40000000
define|#
directive|define
name|DPT_HA_TIMEOUTS_ACTIVE
value|0x80000000
endif|#
directive|endif
name|u_int8_t
name|primary
decl_stmt|;
comment|/* true if primary */
name|u_int8_t
name|more_support
range|:
literal|1
decl_stmt|,
comment|/* HBA supports MORE flag */
name|immediate_support
range|:
literal|1
decl_stmt|,
comment|/* HBA supports IMMEDIATE */
name|broken_INQUIRY
range|:
literal|1
decl_stmt|;
comment|/* EISA HBA with broken INQUIRY */
name|u_int8_t
name|resetlevel
index|[
name|MAX_CHANNELS
index|]
decl_stmt|;
name|u_int32_t
name|last_ccb
decl_stmt|;
comment|/* Last used ccb */
name|u_int32_t
name|cplen
decl_stmt|;
comment|/* size of CP in words */
name|u_int16_t
name|cppadlen
decl_stmt|;
comment|/* pad length of cp */
name|u_int16_t
name|queuesize
decl_stmt|;
name|u_int16_t
name|sgsize
decl_stmt|;
comment|/* Entries in the SG list */
name|u_int8_t
name|hostid
index|[
literal|4
index|]
decl_stmt|;
comment|/* SCSI ID of HBA */
name|u_int32_t
name|cache_type
range|:
literal|2
decl_stmt|,
name|cache_size
range|:
literal|30
decl_stmt|;
specifier|volatile
name|dpt_sp_t
name|sp
decl_stmt|;
comment|/* status packet */
block|}
name|dpt_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Externals:  * These all come from dpt_scsi.c  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DPT_C_
end_ifndef

begin_extern
extern|extern TAILQ_HEAD(
operator|,
extern|dpt_softc
end_extern

begin_expr_stmt
unit|)
name|dpt_softc_list
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|dpt_controllers_present
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|hex_dump
parameter_list|(
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|i2bin
parameter_list|(
name|unsigned
name|int
name|no
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|scsi_cmd_name
parameter_list|(
name|u_int8_t
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|dpt_conf_t
modifier|*
name|dpt_get_conf
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|,
name|u_int8_t
name|page
parameter_list|,
name|u_int8_t
name|target
parameter_list|,
name|u_int8_t
name|size
parameter_list|,
name|int
name|extent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dpt_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dpt_setup
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|,
name|dpt_conf_t
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dpt_attach
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dpt_shutdown
parameter_list|(
name|int
name|howto
parameter_list|,
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dpt_detect_cache
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dpt_user_cmd
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|,
name|eata_pt_t
modifier|*
name|user_cmd
parameter_list|,
name|caddr_t
name|cmdarg
parameter_list|,
name|int
name|minor_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
name|dpt_blinking_led
parameter_list|(
name|dpt_softc_t
modifier|*
name|dpt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DPT_C_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DPT_H */
end_comment

end_unit

