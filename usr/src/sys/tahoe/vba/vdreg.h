begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vdreg.h	1.5	86/08/12	*/
end_comment

begin_comment
comment|/*  * VDDC (Versabus Direct Disk Controller) definitions.  */
end_comment

begin_comment
comment|/*  * DCB Command Codes  */
end_comment

begin_define
define|#
directive|define
name|RD
value|0x80
end_define

begin_comment
comment|/* Read Data */
end_comment

begin_define
define|#
directive|define
name|FTR
value|0xc0
end_define

begin_comment
comment|/* Full Track Read */
end_comment

begin_define
define|#
directive|define
name|RAS
value|0x90
end_define

begin_comment
comment|/* Read and Scatter */
end_comment

begin_define
define|#
directive|define
name|RD_RAW
value|0x600
end_define

begin_comment
comment|/* Read unformatted disk sector */
end_comment

begin_define
define|#
directive|define
name|CMP
value|0xa0
end_define

begin_comment
comment|/* Compare */
end_comment

begin_define
define|#
directive|define
name|FTC
value|0xe0
end_define

begin_comment
comment|/* Full Track Compare */
end_comment

begin_define
define|#
directive|define
name|RHDE
value|0x180
end_define

begin_comment
comment|/* Read Header, Data& ECC (not used) */
end_comment

begin_define
define|#
directive|define
name|WD
value|0x00
end_define

begin_comment
comment|/* Write Data */
end_comment

begin_define
define|#
directive|define
name|FTW
value|0x40
end_define

begin_comment
comment|/* Full Track Write */
end_comment

begin_define
define|#
directive|define
name|WTC
value|0x20
end_define

begin_comment
comment|/* Write Then Compare */
end_comment

begin_define
define|#
directive|define
name|FTWTC
value|0x60
end_define

begin_comment
comment|/* Full Track Write Then Compare */
end_comment

begin_define
define|#
directive|define
name|GAW
value|0x10
end_define

begin_comment
comment|/* Gather and Write */
end_comment

begin_define
define|#
directive|define
name|WDE
value|0x100
end_define

begin_comment
comment|/* Write Data& ECC (not used) */
end_comment

begin_define
define|#
directive|define
name|FSECT
value|0x900
end_define

begin_comment
comment|/* Format Sector */
end_comment

begin_define
define|#
directive|define
name|GWC
value|0x30
end_define

begin_comment
comment|/* Gather Write& Compare */
end_comment

begin_define
define|#
directive|define
name|VDSTART
value|0x800
end_define

begin_comment
comment|/* Start drives */
end_comment

begin_define
define|#
directive|define
name|VDRELEASE
value|0xa00
end_define

begin_comment
comment|/* Stop drives */
end_comment

begin_define
define|#
directive|define
name|SEEK
value|0xb00
end_define

begin_comment
comment|/* Seek */
end_comment

begin_define
define|#
directive|define
name|INIT
value|0xc00
end_define

begin_comment
comment|/* Initialize VDDC */
end_comment

begin_define
define|#
directive|define
name|DIAG
value|0xd00
end_define

begin_comment
comment|/* Diagnose (self-test) VDDC */
end_comment

begin_define
define|#
directive|define
name|RSTCFG
value|0xe00
end_define

begin_comment
comment|/* Reset/Configure VDDC/DDI/Drive(s) */
end_comment

begin_define
define|#
directive|define
name|VDSTATUS
value|0xf00
end_define

begin_comment
comment|/* VDDC Status */
end_comment

begin_define
define|#
directive|define
name|ABORT
value|0x80000000
end_define

begin_comment
comment|/* ABORT active i/o */
end_comment

begin_comment
comment|/*  * Error/status codes.  */
end_comment

begin_define
define|#
directive|define
name|HCRCERR
value|0x1
end_define

begin_comment
comment|/* Header CRC Error */
end_comment

begin_define
define|#
directive|define
name|HCMPERR
value|0x2
end_define

begin_comment
comment|/* Header Compare Error */
end_comment

begin_define
define|#
directive|define
name|WPTERR
value|0x4
end_define

begin_comment
comment|/* Write Protect Error/Status */
end_comment

begin_define
define|#
directive|define
name|CTLRERR
value|0x8
end_define

begin_comment
comment|/* Controller Error */
end_comment

begin_define
define|#
directive|define
name|DSEEKERR
value|0x10
end_define

begin_comment
comment|/* Disk Seek Error */
end_comment

begin_define
define|#
directive|define
name|UCDATERR
value|0x20
end_define

begin_comment
comment|/* Uncorrectable Data Error */
end_comment

begin_define
define|#
directive|define
name|NOTCYLERR
value|0x40
end_define

begin_comment
comment|/* Not on Cylinder Error */
end_comment

begin_define
define|#
directive|define
name|DRVNRDY
value|0x80
end_define

begin_comment
comment|/* Drive Not Ready Error/Status */
end_comment

begin_define
define|#
directive|define
name|ALTACC
value|0x100
end_define

begin_comment
comment|/* Alternate (track) accessed Status */
end_comment

begin_define
define|#
directive|define
name|SEEKSTRT
value|0x200
end_define

begin_comment
comment|/* Seek Started Status */
end_comment

begin_define
define|#
directive|define
name|INVDADR
value|0x400
end_define

begin_comment
comment|/* Invalid Disk Address Error */
end_comment

begin_define
define|#
directive|define
name|DNEMEM
value|0x800
end_define

begin_comment
comment|/* Non-Existant Memory Error */
end_comment

begin_define
define|#
directive|define
name|PARERR
value|0x1000
end_define

begin_comment
comment|/* Memory Parity Error */
end_comment

begin_define
define|#
directive|define
name|DCOMPERR
value|0x2000
end_define

begin_comment
comment|/* Data Compare Error */
end_comment

begin_define
define|#
directive|define
name|DDIRDY
value|0x4000
end_define

begin_comment
comment|/* DDI Ready Error/Status */
end_comment

begin_define
define|#
directive|define
name|OPABRT
value|0x8000
end_define

begin_comment
comment|/* Operator Abort (Host) Error/Status */
end_comment

begin_define
define|#
directive|define
name|DSERLY
value|0x10000
end_define

begin_comment
comment|/* Data Strobe Early */
end_comment

begin_define
define|#
directive|define
name|DSLATE
value|0x20000
end_define

begin_comment
comment|/* Data Strobe Late */
end_comment

begin_define
define|#
directive|define
name|TOPLUS
value|0x40000
end_define

begin_comment
comment|/* Track Offset Plus */
end_comment

begin_define
define|#
directive|define
name|TOMNUS
value|0x80000
end_define

begin_comment
comment|/* Track Offset Minus */
end_comment

begin_define
define|#
directive|define
name|CPDCRT
value|0x100000
end_define

begin_comment
comment|/* Cntlr Performed Data Correction */
end_comment

begin_define
define|#
directive|define
name|HRDERR
value|0x200000
end_define

begin_comment
comment|/* Hard Error */
end_comment

begin_define
define|#
directive|define
name|SFTERR
value|0x400000
end_define

begin_comment
comment|/* Soft Error (retry succesful) */
end_comment

begin_define
define|#
directive|define
name|ANYERR
value|0x800000
end_define

begin_comment
comment|/* Any Error */
end_comment

begin_define
define|#
directive|define
name|INVCMD
value|0x1000000
end_define

begin_comment
comment|/* Programmer error */
end_comment

begin_comment
comment|/* hard error */
end_comment

begin_define
define|#
directive|define
name|HTYPES
define|\
value|(HCRCERR|HCMPERR|WPTERR|CTLRERR|DSEEKERR|UCDATERR|NOTCYLERR|DRVNRDY|\      INVDADR|DNEMEM|PARERR|DCOMPERR)
end_define

begin_define
define|#
directive|define
name|ERRS
value|0x3FFF
end_define

begin_comment
comment|/* retryable errors */
end_comment

begin_define
define|#
directive|define
name|CANRETRY
define|\
value|(CTLRERR|DSEEKERR|NOTCYLERR|DCOMPERR|UCDATERR|PARERR|DNEMEM|HCRCERR|HCMPERR)
end_define

begin_define
define|#
directive|define
name|ERRBITS
value|"\20\1HCRC\2HCMP\3WPT\4CTLR\5DSEEK\6UCDATA\7NOTCYL\10DRVNRDY\ \11ALTACC\12SEEKSTRT\13INVDADR\14DNEMEM\15PAR\16DCOMP\17DDIRDY\20OPABRT\ \21DSERLY\22DSLATE\23TOPLUS\24TOPMNUS\25CPDCRT\26HRDERR\27SFTERR\30ANYERR\ \31INVCMD"
end_define

begin_comment
comment|/*  * DCB status codes.  */
end_comment

begin_define
define|#
directive|define
name|DCBABT
value|0x10000000
end_define

begin_comment
comment|/* DCB Aborted */
end_comment

begin_define
define|#
directive|define
name|DCBUSC
value|0x20000000
end_define

begin_comment
comment|/* DCB Unsuccesfully Completed */
end_comment

begin_define
define|#
directive|define
name|DCBCMP
value|0x40000000
end_define

begin_comment
comment|/* DCB Complete */
end_comment

begin_define
define|#
directive|define
name|DCBSTR
value|0x80000000
end_define

begin_comment
comment|/* DCB Started */
end_comment

begin_comment
comment|/*  * MDCB status codes.  */
end_comment

begin_define
define|#
directive|define
name|CTLRBSY
value|0x10000000
end_define

begin_comment
comment|/* Cntlr Busy */
end_comment

begin_define
define|#
directive|define
name|INTCCDE
value|0x60000000
end_define

begin_comment
comment|/* Interrupt Cause Code */
end_comment

begin_define
define|#
directive|define
name|DCBINT
value|0x80000000
end_define

begin_comment
comment|/* DCB Interrupt Flag */
end_comment

begin_comment
comment|/*  * VDDC interrupt modes.  */
end_comment

begin_define
define|#
directive|define
name|NOINT
value|0x0
end_define

begin_comment
comment|/* No Interrupt */
end_comment

begin_define
define|#
directive|define
name|INTERR
value|0x2
end_define

begin_comment
comment|/* Interrupt on Error */
end_comment

begin_define
define|#
directive|define
name|INTSUC
value|0x1
end_define

begin_comment
comment|/* Interrupt on Success */
end_comment

begin_define
define|#
directive|define
name|INTDONE
value|0x3
end_define

begin_comment
comment|/* Interrupt on Error or Success */
end_comment

begin_comment
comment|/*  * Constrol status definitions.  */
end_comment

begin_define
define|#
directive|define
name|CS_SCS
value|0xf
end_define

begin_comment
comment|/* Status Change Source (drive number) */
end_comment

begin_define
define|#
directive|define
name|CS_ELC
value|0x10
end_define

begin_comment
comment|/* Error on Last Command */
end_comment

begin_define
define|#
directive|define
name|CS_ICC
value|0x60
end_define

begin_comment
comment|/* Interupt Cause Code */
end_comment

begin_define
define|#
directive|define
name|ICC_NOI
value|0x00
end_define

begin_comment
comment|/* No interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_DUN
value|0x20
end_define

begin_comment
comment|/* No interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_ERR
value|0x40
end_define

begin_comment
comment|/* No interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_SUC
value|0x60
end_define

begin_comment
comment|/* No interupt */
end_comment

begin_define
define|#
directive|define
name|CS_GO
value|0x80
end_define

begin_comment
comment|/* Go bit (controller working) */
end_comment

begin_define
define|#
directive|define
name|CS_BE
value|0x100
end_define

begin_comment
comment|/* Buss Error */
end_comment

begin_define
define|#
directive|define
name|CS_BOK
value|0x4000
end_define

begin_comment
comment|/* Board O.K. */
end_comment

begin_define
define|#
directive|define
name|CS_SFL
value|0x8000
end_define

begin_comment
comment|/* System fail */
end_comment

begin_define
define|#
directive|define
name|CS_LEC
value|0xff000000
end_define

begin_comment
comment|/* Last Error Code */
end_comment

begin_comment
comment|/* Status word bit assignments */
end_comment

begin_define
define|#
directive|define
name|STA_UR
value|0x1
end_define

begin_comment
comment|/* Unit Ready */
end_comment

begin_define
define|#
directive|define
name|STA_OC
value|0x2
end_define

begin_comment
comment|/* On Cylinder */
end_comment

begin_define
define|#
directive|define
name|STA_SE
value|0x4
end_define

begin_comment
comment|/* Seek Error */
end_comment

begin_define
define|#
directive|define
name|STA_DF
value|0x8
end_define

begin_comment
comment|/* Drive Fault */
end_comment

begin_define
define|#
directive|define
name|STA_WP
value|0x10
end_define

begin_comment
comment|/* Write Protected */
end_comment

begin_define
define|#
directive|define
name|STA_US
value|0x20
end_define

begin_comment
comment|/* Unit Selected */
end_comment

begin_comment
comment|/* Interupt Control Field bit assignments */
end_comment

begin_define
define|#
directive|define
name|ICF_IPL
value|0x7
end_define

begin_comment
comment|/* Interupt Priority Level */
end_comment

begin_define
define|#
directive|define
name|ICF_IEN
value|0x8
end_define

begin_comment
comment|/* Interupt ENable */
end_comment

begin_define
define|#
directive|define
name|ICF_IV
value|0xff00
end_define

begin_comment
comment|/* Interupt Vector */
end_comment

begin_comment
comment|/* Transfer Control Format bit assignments */
end_comment

begin_define
define|#
directive|define
name|TCF_AM
value|0xff
end_define

begin_comment
comment|/* Address Modifier */
end_comment

begin_define
define|#
directive|define
name|AM_SNPDA
value|0x01
end_define

begin_comment
comment|/* Standard Non-Privileged Data Access */
end_comment

begin_define
define|#
directive|define
name|AM_SASA
value|0x81
end_define

begin_comment
comment|/* Standard Ascending Sequential Access */
end_comment

begin_define
define|#
directive|define
name|AM_ENPDA
value|0xf1
end_define

begin_comment
comment|/* Extended Non-Privileged Data Access */
end_comment

begin_define
define|#
directive|define
name|AM_EASA
value|0xe1
end_define

begin_comment
comment|/* Extended Ascending Sequential Access */
end_comment

begin_define
define|#
directive|define
name|TCF_BTE
value|0x800
end_define

begin_comment
comment|/* Block Transfer Enable */
end_comment

begin_comment
comment|/* Controller Configuration Flags bit assignments */
end_comment

begin_define
define|#
directive|define
name|CCF_STS
value|0x1
end_define

begin_comment
comment|/* Sectors per Track Selectable */
end_comment

begin_define
define|#
directive|define
name|CCF_EAV
value|0x2
end_define

begin_comment
comment|/* Enable Auto Vector */
end_comment

begin_define
define|#
directive|define
name|CCF_ERR
value|0x4
end_define

begin_comment
comment|/* Enable Reset Register */
end_comment

begin_define
define|#
directive|define
name|CCF_DER
value|0x8
end_define

begin_comment
comment|/* Disable Error Recovery */
end_comment

begin_define
define|#
directive|define
name|CCF_XMD
value|0x60
end_define

begin_comment
comment|/* XMD transfer mode (buss size) */
end_comment

begin_define
define|#
directive|define
name|XMD_8BIT
value|0x20
end_define

begin_comment
comment|/*   Do only 8 bit transfers */
end_comment

begin_define
define|#
directive|define
name|XMD_16BIT
value|0x40
end_define

begin_comment
comment|/*   Do only 16 bit transfers */
end_comment

begin_define
define|#
directive|define
name|XMD_32BIT
value|0x60
end_define

begin_comment
comment|/*   Do only 32 bit transfers */
end_comment

begin_define
define|#
directive|define
name|CCF_BSZ
value|0x300
end_define

begin_comment
comment|/* Burst SiZe */
end_comment

begin_define
define|#
directive|define
name|BSZ_16WRD
value|0x000
end_define

begin_comment
comment|/*   16 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_12WRD
value|0x100
end_define

begin_comment
comment|/*   12 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_8WRD
value|0x200
end_define

begin_comment
comment|/*   8 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_4WRD
value|0x300
end_define

begin_comment
comment|/*   4 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|CCF_SEN
value|0x400
end_define

begin_comment
comment|/* Cylinder / track Skew ENable (for format) */
end_comment

begin_define
define|#
directive|define
name|CCF_ENP
value|0x1000
end_define

begin_comment
comment|/* ENable Parity */
end_comment

begin_define
define|#
directive|define
name|CCF_EPE
value|0x2000
end_define

begin_comment
comment|/* Enable Parity Errors */
end_comment

begin_define
define|#
directive|define
name|CCF_EDE
value|0x10000
end_define

begin_comment
comment|/* Error Detection Enable */
end_comment

begin_define
define|#
directive|define
name|CCF_ECE
value|0x20000
end_define

begin_comment
comment|/* Error Correction Enable */
end_comment

begin_comment
comment|/*  * Diagnostic register definitions.  */
end_comment

begin_define
define|#
directive|define
name|DIA_DC
value|0x7f
end_define

begin_comment
comment|/* Dump count mask */
end_comment

begin_define
define|#
directive|define
name|DIA_DWR
value|0x80
end_define

begin_comment
comment|/* Dump Write / Read flag */
end_comment

begin_define
define|#
directive|define
name|DIA_ARE
value|0x100
end_define

begin_comment
comment|/* Auto Rebuild Enable */
end_comment

begin_define
define|#
directive|define
name|DIA_CEN
value|0x200
end_define

begin_comment
comment|/* Call ENable flag */
end_comment

begin_define
define|#
directive|define
name|DIA_KEY
value|0xAA550000
end_define

begin_comment
comment|/* Reset KEY */
end_comment

begin_comment
comment|/* Sector Header bit assignments */
end_comment

begin_define
define|#
directive|define
name|VDMF
value|0x8000
end_define

begin_comment
comment|/* Manufacturer Fault 1=good sector */
end_comment

begin_define
define|#
directive|define
name|VDUF
value|0x4000
end_define

begin_comment
comment|/* User Fault 1=good sector */
end_comment

begin_define
define|#
directive|define
name|VDALT
value|0x2000
end_define

begin_comment
comment|/* Alternate Sector 1=alternate */
end_comment

begin_define
define|#
directive|define
name|VDWPT
value|0x1000
end_define

begin_comment
comment|/* Write Protect 1=Read Only Sector */
end_comment

begin_comment
comment|/* DCB Bit assignments */
end_comment

begin_define
define|#
directive|define
name|INT_IC
value|0x3
end_define

begin_comment
comment|/* Interupt Control */
end_comment

begin_define
define|#
directive|define
name|IC_NOI
value|0x0
end_define

begin_comment
comment|/*   NO Interupt */
end_comment

begin_define
define|#
directive|define
name|IC_IOD
value|0x1
end_define

begin_comment
comment|/*   Interupt On Done */
end_comment

begin_define
define|#
directive|define
name|IC_IOE
value|0x2
end_define

begin_comment
comment|/*   Interupt On Error */
end_comment

begin_define
define|#
directive|define
name|IC_IOS
value|0x3
end_define

begin_comment
comment|/*   Interupt On Success */
end_comment

begin_define
define|#
directive|define
name|INT_PBA
value|0x4
end_define

begin_comment
comment|/* Proceed before ACK */
end_comment

begin_comment
comment|/*  * Perform a reset on the controller.  */
end_comment

begin_define
define|#
directive|define
name|VDDC_RESET
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|)
value|{ \ 	if (type == SMD_ECTLR) { \ 		(addr)->diag_flags = DIA_KEY|DIA_CEN; \ 		(addr)->cdr_mdcb_ptr = (fmt_mdcb *)0xffffffff; \ 		DELAY(5000000); \ 	} else { \ 		(addr)->cdr_reset = 0x0; \ 		DELAY(1500000); \ 	} \ }
end_define

begin_comment
comment|/*  * Abort a controller operation.  */
end_comment

begin_define
define|#
directive|define
name|VDDC_ABORT
parameter_list|(
name|a
parameter_list|,
name|type
parameter_list|)
value|{ \ 	if ((type) == SMDCTLR) { \ 		movow(a, (ABORT& 0xffff0000)>> 16) ; \ 		movow((int)(a)+2, ABORT& 0xffff); \ 	} else \ 		(a)->cdr_mdcb_ptr = (fmt_mdcb *)ABORT; \ 	DELAY(1000000); \ }
end_define

begin_comment
comment|/*  * Start i/o on controller.  */
end_comment

begin_define
define|#
directive|define
name|VDDC_ATTENTION
parameter_list|(
name|ctlr
parameter_list|,
name|mdcbadr
parameter_list|,
name|type
parameter_list|)
value|{\ 	if (type == SMDCTLR) { \ 		movow(ctlr, ((int)mdcbadr& 0xffff0000)>> 16) ; \ 		movow((int)(ctlr)+2, (int)mdcbadr& 0xffff); \ 	} else \ 		(ctlr)->cdr_mdcb_ptr = mdcbadr; \ }
end_define

begin_comment
comment|/*  * A disk address.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|track
decl_stmt|;
comment|/* all 8 bits */
name|char
name|sector
decl_stmt|;
comment|/* all 8  bits */
name|short
name|cylinder
decl_stmt|;
comment|/* low order 12 bits */
block|}
name|dskadr
typedef|;
end_typedef

begin_comment
comment|/*  * Sector formats.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|dskadr
name|hdr_addr
decl_stmt|;
name|short
name|smd_crc
decl_stmt|;
block|}
name|smd
struct|;
struct|struct
block|{
name|dskadr
name|physical
decl_stmt|;
name|dskadr
name|logical
decl_stmt|;
name|long
name|smd_e_crc
decl_stmt|;
block|}
name|smd_e
struct|;
block|}
name|fmt_hdr
typedef|;
end_typedef

begin_comment
comment|/*  * DCB trailer formats.  */
end_comment

begin_comment
comment|/* read/write trailer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|memadr
decl_stmt|;
comment|/* memory address */
name|u_long
name|wcount
decl_stmt|;
comment|/* 16 bit word count */
name|dskadr
name|disk
decl_stmt|;
comment|/* disk address */
block|}
name|trrw
typedef|;
end_typedef

begin_comment
comment|/* scatter/gather trailer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|trrw
name|start_addr
decl_stmt|;
struct|struct
block|{
name|char
modifier|*
name|nxt_addr
decl_stmt|;
name|u_long
name|nxt_len
decl_stmt|;
block|}
name|addr_chain
index|[
literal|126
index|]
struct|;
block|}
name|trsg
typedef|;
end_typedef

begin_comment
comment|/* seek trailer format */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dskadr
name|skaddr
decl_stmt|;
block|}
name|trseek
typedef|;
end_typedef

begin_comment
comment|/* format trailer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* data buffer to be filled on sector*/
name|long
name|nsectors
decl_stmt|;
comment|/* # of sectors to be formatted */
name|dskadr
name|disk
decl_stmt|;
comment|/* disk physical address info */
name|dskadr
name|hdr
decl_stmt|;
comment|/* header address info */
block|}
name|trfmt
typedef|;
end_typedef

begin_comment
comment|/* reset/configure trailer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|ncyl
decl_stmt|;
comment|/* # cylinders */
name|long
name|nsurfaces
decl_stmt|;
comment|/* # surfaces */
name|long
name|nsectors
decl_stmt|;
comment|/* # sectors */
name|long
name|slip_sec
decl_stmt|;
comment|/* # of slip sectors */
name|long
name|recovery
decl_stmt|;
comment|/* recovery flags */
block|}
name|treset
typedef|;
end_typedef

begin_comment
comment|/*  * DCB layout.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fmtdcb
block|{
name|struct
name|fmtdcb
modifier|*
name|nxtdcb
decl_stmt|;
comment|/* next dcb */
name|short
name|intflg
decl_stmt|;
comment|/* interrupt settings and flags */
name|short
name|opcode
decl_stmt|;
comment|/* DCB command code etc... */
name|long
name|operrsta
decl_stmt|;
comment|/* error& status info */
name|short
name|fill
decl_stmt|;
comment|/* not used */
name|char
name|devselect
decl_stmt|;
comment|/* drive selection */
name|char
name|trailcnt
decl_stmt|;
comment|/* trailer Word Count */
name|long
name|err_memadr
decl_stmt|;
comment|/* error memory address */
name|char
name|err_code
decl_stmt|;
comment|/* error codes for SMD/E */
name|char
name|fill2
decl_stmt|;
comment|/* not used */
name|short
name|err_wcount
decl_stmt|;
comment|/* error word count */
name|char
name|err_trk
decl_stmt|;
comment|/* error track/sector */
name|char
name|err_sec
decl_stmt|;
comment|/* error track/sector */
name|short
name|err_cyl
decl_stmt|;
comment|/* error cylinder adr */
union|union
block|{
name|trseek
name|sktrail
decl_stmt|;
comment|/* seek command trailer */
ifdef|#
directive|ifdef
name|notdef
name|trsg
name|sgtrail
decl_stmt|;
comment|/* scatter/gather trailer */
endif|#
directive|endif
name|trrw
name|rwtrail
decl_stmt|;
comment|/* read/write trailer */
name|trfmt
name|fmtrail
decl_stmt|;
comment|/* format trailer */
name|treset
name|rstrail
decl_stmt|;
comment|/* reset/configure trailer */
block|}
name|trail
union|;
block|}
name|fmt_dcb
typedef|;
end_typedef

begin_comment
comment|/*  * MDCB layout.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|fmt_dcb
modifier|*
name|firstdcb
decl_stmt|;
comment|/* first dcb in chain */
name|fmt_dcb
modifier|*
name|procdcb
decl_stmt|;
comment|/* dcb being processed */
name|fmt_dcb
modifier|*
name|intdcb
decl_stmt|;
comment|/* dcb causing interrupt */
name|long
name|vddcstat
decl_stmt|;
comment|/* VDDC status */
block|}
name|fmt_mdcb
typedef|;
end_typedef

begin_comment
comment|/*  * Control-status communications block.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|fmt_mdcb
modifier|*
name|cdr_mdcb_ptr
decl_stmt|;
comment|/* controller's mdcb */
name|u_long
name|cdr_reset
decl_stmt|;
comment|/* controller reset register */
name|u_long
name|cdr_csr
decl_stmt|;
comment|/* control/status register */
name|long
name|cdr_reserved
decl_stmt|;
comment|/* reserved */
name|u_short
name|cdr_status
index|[
literal|16
index|]
decl_stmt|;
comment|/* per-drive status register */
name|u_short
name|stat_chng
decl_stmt|;
comment|/* status change interupt register */
name|u_short
name|done_icf
decl_stmt|;
comment|/* interupt-complete register */
name|u_short
name|error_icf
decl_stmt|;
comment|/* error-interupt register */
name|u_short
name|success_icf
decl_stmt|;
comment|/* success-interupt register */
name|u_short
name|mdcb_tcf
decl_stmt|;
comment|/* mdcb transfer control register */
name|u_short
name|dcb_tcf
decl_stmt|;
comment|/* dcb transfer control register */
name|u_short
name|trail_tcf
decl_stmt|;
comment|/* trail transfer control register */
name|u_short
name|data_tcf
decl_stmt|;
comment|/* data transfer control register */
name|u_long
name|cdr_ccf
decl_stmt|;
comment|/* controller configuration flags */
name|u_long
name|sec_size
decl_stmt|;
comment|/* drive sector size */
name|u_short
name|cdr_unused0
decl_stmt|;
name|u_char
name|cyl_skew
decl_stmt|;
comment|/* cylinder to cylinder skew factor */
name|u_char
name|trk_skew
decl_stmt|;
comment|/* track to track skew factor */
name|u_long
name|cdr_unused1
decl_stmt|;
name|u_long
name|diag_flags
decl_stmt|;
comment|/* diagnostic flag register */
name|u_long
name|diag_dump
decl_stmt|;
comment|/* pointer for diagnostic addresses */
block|}
name|cdr
typedef|;
end_typedef

begin_comment
comment|/* controller types */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|SMDCTLR
value|1
end_define

begin_comment
comment|/* smd interface */
end_comment

begin_define
define|#
directive|define
name|SMD_ECTLR
value|2
end_define

begin_comment
comment|/* extended-smd interface */
end_comment

begin_comment
comment|/* drive types */
end_comment

begin_define
define|#
directive|define
name|XSD
value|0
end_define

begin_define
define|#
directive|define
name|FUJ
value|1
end_define

begin_comment
comment|/* Fujitsu 160 */
end_comment

begin_define
define|#
directive|define
name|XFD
value|2
end_define

begin_comment
comment|/* CDC 340Mb Winchester */
end_comment

begin_define
define|#
directive|define
name|SMD
value|3
end_define

begin_comment
comment|/* CDC 9766 or equivalent */
end_comment

begin_define
define|#
directive|define
name|FSD
value|4
end_define

begin_define
define|#
directive|define
name|EGL
value|5
end_define

begin_comment
comment|/* Fujitsu Eagle */
end_comment

begin_comment
comment|/*  * Drive logical partitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|par_start
decl_stmt|;
comment|/* starting sector # */
name|long
name|par_len
decl_stmt|;
comment|/* size in sectors */
block|}
name|par_tab
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|secsize
decl_stmt|;
comment|/* bytes/sector */
name|int
name|nsec
decl_stmt|;
comment|/* sectors/track */
name|int
name|ntrak
decl_stmt|;
comment|/* tracks/cylinder */
name|int
name|ncyl
decl_stmt|;
comment|/* # cylinders */
name|int
name|nslip
decl_stmt|;
comment|/* # slip sectors */
name|int
name|rpm
decl_stmt|;
comment|/* revolutions/minute */
name|int
name|nbits
decl_stmt|;
comment|/* bits/track */
name|char
modifier|*
name|type_name
decl_stmt|;
comment|/* drive name */
name|char
modifier|*
name|type_descrip
decl_stmt|;
comment|/* drive description */
name|long
name|fmt_pat
index|[
literal|16
index|]
decl_stmt|;
comment|/* patterns to be used for formatting */
name|par_tab
name|partition
index|[
literal|8
index|]
decl_stmt|;
comment|/* partition tables */
block|}
name|fs_tab
typedef|;
end_typedef

begin_comment
comment|/* physical information for known disk drives.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VDGENDATA
end_ifdef

begin_decl_stmt
name|long
name|vddcaddr
index|[]
init|=
block|{
literal|0xf2000
block|,
literal|0xf2100
block|,
literal|0xf2200
block|,
literal|0xf2300
block|,
literal|0xf2400
block|,
literal|0xf2500
block|,
literal|0xf2600
block|,
literal|0xf2700
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|vdtimeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fs_tab
name|vdst
index|[]
init|=
block|{
block|{
literal|512
block|,
literal|48
block|,
literal|24
block|,
literal|711
block|,
literal|0
block|,
literal|3600
block|,
literal|30240
block|,
literal|"xsd"
block|,
literal|"515 Mb Control Data Winchester drive"
block|,
block|{
literal|0x0264c993
block|,
literal|0x04c99326
block|,
literal|0x0993264c
block|,
literal|0x13264c98
block|,
literal|0x264c9930
block|,
literal|0x4c993260
block|,
literal|0x993264c0
block|,
literal|0x3264c980
block|,
literal|0x64c99300
block|,
literal|0xc9932600
block|,
literal|0x93264c00
block|,
literal|0x264c9800
block|,
literal|0x4c993000
block|,
literal|0x99326000
block|,
literal|0x3264c000
block|,
literal|0x54c98000
block|}
block|,
block|{
block|{
literal|0
block|,
literal|30528
block|}
block|,
comment|/* xsd0a cyl   0 - 52 */
block|{
literal|30528
block|,
literal|30528
block|}
block|,
comment|/* xsd0b cyl  53 - 105 */
block|{
literal|61056
block|,
literal|345600
block|}
block|,
comment|/* xsd0c cyl 106 - 705 */
block|{
literal|118656
block|,
literal|288000
block|}
block|,
comment|/* xsd0d cyl 206 - 705 */
block|{
literal|176256
block|,
literal|230400
block|}
block|,
comment|/* xsd0e cyl 306 - 705 */
block|{
literal|233856
block|,
literal|172800
block|}
block|,
comment|/* xsd0f cyl 406 - 705 */
block|{
literal|291456
block|,
literal|115200
block|}
block|,
comment|/* xsd0g cyl 506 - 705 */
block|{
literal|349056
block|,
literal|57600
block|}
block|}
comment|/* xsd0h cyl 606 - 705 */
block|}
block|,
block|{
literal|512
block|,
literal|44
block|,
literal|20
block|,
literal|842
block|,
literal|0
block|,
literal|3961
block|,
literal|27720
block|,
literal|"egl"
block|,
literal|"474 Mb Fujitsu Eagle drive"
block|,
block|{
literal|0x0264c993
block|,
literal|0x04c99326
block|,
literal|0x0993264c
block|,
literal|0x13264c98
block|,
literal|0x264c9930
block|,
literal|0x4c993260
block|,
literal|0x993264c0
block|,
literal|0x3264c980
block|,
literal|0x64c99300
block|,
literal|0xc9932600
block|,
literal|0x93264c00
block|,
literal|0x264c9800
block|,
literal|0x4c993000
block|,
literal|0x99326000
block|,
literal|0x3264c000
block|,
literal|0x54c98000
block|}
block|,
block|{
block|{
literal|0
block|,
literal|26400
block|}
block|,
comment|/* egl0a cyl   0 - 59 */
block|{
literal|26400
block|,
literal|33000
block|}
block|,
comment|/* egl0b cyl  60 - 134 */
block|{
literal|59400
block|,
literal|308880
block|}
block|,
comment|/* egl0c cyl 135 - 836 */
block|{
literal|368280
block|,
literal|2640
block|}
block|,
comment|/* egl0d cyl 837 - 842 */
block|{
literal|0
block|,
literal|368280
block|}
block|,
comment|/* egl0e cyl 0 - 836 */
block|{
literal|0
block|,
literal|370920
block|}
block|,
comment|/* egl0f cyl 0 - 842 */
block|{
literal|59400
block|,
literal|155320
block|}
block|,
comment|/* egl0g cyl 135 - 487 */
block|{
literal|214720
block|,
literal|153560
block|}
block|}
comment|/* egl0h cyl 488 - 836 */
block|}
block|,
block|{
literal|512
block|,
literal|64
block|,
literal|10
block|,
literal|823
block|,
literal|0
block|,
literal|3600
block|,
literal|40960
block|,
literal|"fuj"
block|,
comment|/* 360 Mb Fujitsu */
literal|"360 Mb Fujitsu Winchester drive"
block|,
block|{
literal|0x0264c993
block|,
literal|0x04c99326
block|,
literal|0x0993264c
block|,
literal|0x13264c98
block|,
literal|0x264c9930
block|,
literal|0x4c993260
block|,
literal|0x993264c0
block|,
literal|0x3264c980
block|,
literal|0x64c99300
block|,
literal|0xc9932600
block|,
literal|0x93264c00
block|,
literal|0x264c9800
block|,
literal|0x4c993000
block|,
literal|0x99326000
block|,
literal|0x3264c000
block|,
literal|0x54c98000
block|}
block|,
block|{
block|{
literal|0
block|,
literal|19200
block|}
block|,
comment|/* fuj0a cyl   0 - 59 */
block|{
literal|19200
block|,
literal|24000
block|}
block|,
comment|/* fuj0b cyl  60 - 134 */
block|{
literal|43200
block|,
literal|218560
block|}
block|,
comment|/* fuj0c cyl 135 - 817 */
block|{
literal|79680
block|,
literal|182080
block|}
block|,
comment|/* fuj0d cyl 249 - 817 */
block|{
literal|116160
block|,
literal|145600
block|}
block|,
comment|/* fuj0e cyl 363 - 817 */
block|{
literal|152640
block|,
literal|109120
block|}
block|,
comment|/* fuj0f cyl 477 - 817 */
block|{
literal|189120
block|,
literal|72640
block|}
block|,
comment|/* fuj0g cyl 591 - 817 */
block|{
literal|225600
block|,
literal|36160
block|}
block|}
comment|/* fug0h cyl 705 - 817 */
block|}
block|,
block|{
literal|512
block|,
literal|32
block|,
literal|24
block|,
literal|711
block|,
literal|0
block|,
literal|3600
block|,
literal|20160
block|,
literal|"xfd"
block|,
comment|/* 340 Mb FSD */
literal|"340 Mb Control Data Winchester drive"
block|,
block|{
literal|0x0d9b366c
block|,
literal|0x1b366cd8
block|,
literal|0x366cd9b0
block|,
literal|0x6cd9b360
block|,
literal|0xd9b366c0
block|,
literal|0xb366cd80
block|,
literal|0x66cd9b00
block|,
literal|0xcd9b3600
block|,
literal|0x9b366300
block|,
literal|0x366cd800
block|,
literal|0x6cd9b000
block|,
literal|0xd9b36000
block|,
literal|0xb366c000
block|,
literal|0x66cd8000
block|,
literal|0xcd9b0000
block|,
literal|0x9b360000
block|}
block|,
ifdef|#
directive|ifdef
name|MICKEY
block|{
block|{
literal|0
block|,
literal|20352
block|}
block|,
comment|/* xfd0a cyl   0-52 */
block|{
literal|20352
block|,
literal|20352
block|}
block|,
comment|/* xfd0b cyl  53-105 */
block|{
literal|40704
block|,
literal|230400
block|}
block|,
comment|/* xfd0c cyl 106-705 */
block|{
literal|271104
block|,
literal|1920
block|}
block|,
comment|/* xfd0d cyl 706-710 */
block|{
literal|0
block|,
literal|271104
block|}
block|,
comment|/* xfd0e cyl   0-705 */
block|{
literal|0
block|,
literal|273024
block|}
block|}
block|,
comment|/* xfd0f cyl   0-710 */
else|#
directive|else
block|{
block|{
literal|0
block|,
literal|20352
block|}
block|,
comment|/* xfd0a cyl   0 - 52 */
block|{
literal|20352
block|,
literal|20352
block|}
block|,
comment|/* xfd0b cyl  53 - 105 */
block|{
literal|40704
block|,
literal|230400
block|}
block|,
comment|/* xfd0c cyl 106 - 705 */
block|{
literal|79104
block|,
literal|192000
block|}
block|,
comment|/* xfd0d cyl 206 - 705 */
block|{
literal|117504
block|,
literal|153600
block|}
block|,
comment|/* xfd0e cyl 306 - 705 */
block|{
literal|155904
block|,
literal|115200
block|}
block|,
comment|/* xfd0f cyl 406 - 705 */
block|{
literal|194304
block|,
literal|76800
block|}
block|,
comment|/* xfd0g cyl 506 - 705 */
block|{
literal|232704
block|,
literal|38400
block|}
block|}
comment|/* xfd0h cyl 606 - 705 */
endif|#
directive|endif
block|}
block|,
block|{
literal|512
block|,
literal|32
block|,
literal|19
block|,
literal|823
block|,
literal|0
block|,
literal|3600
block|,
literal|20160
block|,
literal|"smd"
block|,
comment|/* 300 Mb SMD */
literal|"300 Mb Control Data removable media drive"
block|,
block|{
literal|0x0d9b366c
block|,
literal|0x1b366cd8
block|,
literal|0x366cd9b0
block|,
literal|0x6cd9b360
block|,
literal|0xd9b366c0
block|,
literal|0xb366cd80
block|,
literal|0x66cd9b00
block|,
literal|0xcd9b3600
block|,
literal|0x9b366300
block|,
literal|0x366cd800
block|,
literal|0x6cd9b000
block|,
literal|0xd9b36000
block|,
literal|0xb366c000
block|,
literal|0x66cd8000
block|,
literal|0xcd9b0000
block|,
literal|0x9b360000
block|}
block|,
block|{
block|{
literal|0
block|,
literal|20064
block|}
block|,
comment|/* smd0a cyl   0-65 */
block|{
literal|20064
block|,
literal|13680
block|}
block|,
comment|/* smd0b cyl  66-110 */
block|{
literal|33744
block|,
literal|214928
block|}
block|,
comment|/* smd0c cyl 111-817 */
block|{
literal|69616
block|,
literal|179056
block|}
block|,
comment|/* smd0d cyl 229 - 817 */
block|{
literal|105488
block|,
literal|143184
block|}
block|,
comment|/* smd0e cyl 347 - 817 */
block|{
literal|141360
block|,
literal|107312
block|}
block|,
comment|/* smd0f cyl 465 - 817 */
block|{
literal|177232
block|,
literal|71440
block|}
block|,
comment|/* smd0g cyl 583 - 817 */
block|{
literal|213104
block|,
literal|35568
block|}
block|}
comment|/* smd0h cyl 701 - 817 */
block|}
block|,
block|{
literal|512
block|,
literal|32
block|,
literal|10
block|,
literal|823
block|,
literal|0
block|,
literal|3600
block|,
literal|20160
block|,
literal|"fsd"
block|,
comment|/* 160 Mb FSD */
literal|"160 Mb Control Data Winchester drive"
block|,
block|{
literal|0x0d9b366c
block|,
literal|0x1b366cd8
block|,
literal|0x366cd9b0
block|,
literal|0x6cd9b360
block|,
literal|0xd9b366c0
block|,
literal|0xb366cd80
block|,
literal|0x66cd9b00
block|,
literal|0xcd9b3600
block|,
literal|0x9b366300
block|,
literal|0x366cd800
block|,
literal|0x6cd9b000
block|,
literal|0xd9b36000
block|,
literal|0xb366c000
block|,
literal|0x66cd8000
block|,
literal|0xcd9b0000
block|,
literal|0x9b360000
block|}
block|,
block|{
block|{
literal|0
block|,
literal|9600
block|}
block|,
comment|/* fsd0a cyl   0 -  59 */
block|{
literal|9600
block|,
literal|12000
block|}
block|,
comment|/* fsd0b cyl  60 - 134 */
block|{
literal|21600
block|,
literal|109280
block|}
block|,
comment|/* fsd0c cyl 135 - 817 */
block|{
literal|39840
block|,
literal|91040
block|}
block|,
comment|/* fsd0d cyl 249 - 817 */
block|{
literal|58080
block|,
literal|72800
block|}
block|,
comment|/* fsd0e cyl 363 - 817 */
block|{
literal|76320
block|,
literal|54560
block|}
block|,
comment|/* fsd0f cyl 477 - 817 */
block|{
literal|94560
block|,
literal|36320
block|}
block|,
comment|/* fsd0g cyl 591 - 817 */
block|{
literal|112800
block|,
literal|18080
block|}
block|}
comment|/* fsd0h cyl 705 - 817 */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nvddrv
init|=
operator|(
sizeof|sizeof
argument_list|(
name|vdst
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|fs_tab
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|STANDALONE
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|vddcaddr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|vdtimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fs_tab
name|vdst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nvddrv
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

