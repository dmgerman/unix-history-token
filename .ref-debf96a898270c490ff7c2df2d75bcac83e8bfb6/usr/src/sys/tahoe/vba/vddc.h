begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vddc.h	1.1	85/07/21	*/
end_comment

begin_comment
comment|/* **	Header file for the VDDC (Versabus Direct Disk Controller) Driver */
end_comment

begin_define
define|#
directive|define
name|NSECPTRK
value|32
end_define

begin_comment
comment|/* #sectors/track - fixed by VDDC */
end_comment

begin_define
define|#
directive|define
name|SECTSIZ
value|512
end_define

begin_comment
comment|/* sector size fixed by VDDC */
end_comment

begin_define
define|#
directive|define
name|L2SIZ
value|9
end_define

begin_comment
comment|/* log2 of sector size */
end_comment

begin_define
define|#
directive|define
name|L2BSIZ
value|10
end_define

begin_comment
comment|/* log2 of block size */
end_comment

begin_define
define|#
directive|define
name|NVDDRV
value|3
end_define

begin_comment
comment|/* number of drive types supported */
end_comment

begin_comment
comment|/* **	DCB Command Codes */
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
name|C
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
comment|/* To be written to VDDC Cntrl Register */
end_comment

begin_comment
comment|/*  * Error/Status Symbolic Constants  */
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
name|SZTIMEOUT
value|0x8
end_define

begin_comment
comment|/* Seize timeout Error */
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
name|ERRBITS
value|"\20\30\27SOFT\26HARD\25CPDCRT\24TOMNUS\23TOPLUS\22DSLATE\ \21DSERLY\20OPABRT\17DDIRDY\16DCOMPERR\15PARERR\14DNEMEM\13INVADR\12SEEKSTRT\ \11ALTACC\10\DRVNRDY\7NOTCYLERR\6UCDATERR\5DSEEKERR\4SZTIMEOUT\3WPTERR\2HCMPERR\ \1HCRCERR"
end_define

begin_comment
comment|/*  * DCB Status Symbolic Constants  */
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

begin_define
define|#
directive|define
name|DCBBITS
value|"\20\40DCBSTR\37DCBCMP\36DCBUSC\35DCBABT"
end_define

begin_comment
comment|/*  * MDCB Status Symbolic Constants  */
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

begin_define
define|#
directive|define
name|MDCBBITS
value|"\20\40DCBINT\37INTCCDE\36CTRLBSY"
end_define

begin_comment
comment|/* **	Hard Error Types */
end_comment

begin_define
define|#
directive|define
name|HTYPES
value|(HCRCERR|HCMPERR|WPTERR|SZTIMEOUT|DSEEKERR|UCDATERR|NOTCYLERR| \ 		 DRVNRDY|INVDADR|DNEMEM|PARERR|DCOMPERR)
end_define

begin_comment
comment|/* **	Errors */
end_comment

begin_define
define|#
directive|define
name|ERRS
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|CANRETRY
value|(SZTIMEOUT|DSEEKERR|NOTCYLERR|DCOMPERR|UCDATERR| \ 			 PARERR|DNEMEM|HCRCERR|HCMPERR)
end_define

begin_comment
comment|/* **	VDDC Interrupt Modes */
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
name|INTDUN
value|0x3
end_define

begin_comment
comment|/* Interrupt on Error or Success */
end_comment

begin_define
define|#
directive|define
name|CMD_MASK
value|0xFF0
end_define

begin_comment
comment|/* Command code mask */
end_comment

begin_comment
comment|/* When a tabular approach can be used */
end_comment

begin_comment
comment|/* again change this back to 0x1F0 */
end_comment

begin_define
define|#
directive|define
name|vdaddr
value|( (char *)(0xff0000+IOBASE) )
end_define

begin_struct
struct|struct
name|size
block|{
name|daddr_t
name|nblocks
decl_stmt|;
name|int
name|block0
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* **	Addr of Memory-Mapped I/O port for VDDC Control Register */
end_comment

begin_define
define|#
directive|define
name|VDDC_ADR
value|(char *)(0xFF2000 + IOBASE)
end_define

begin_comment
comment|/* device address register */
end_comment

begin_comment
comment|/* this is the logical value */
end_comment

begin_comment
comment|/* physically @ 0xFF2000 */
end_comment

begin_comment
comment|/* location was extracted */
end_comment

begin_comment
comment|/* from the VDDC diagnostic */
end_comment

begin_comment
comment|/* package */
end_comment

begin_comment
comment|/* **	Address of Memory-Mapped I/O Port for VDDC H/W Reset */
end_comment

begin_define
define|#
directive|define
name|VDDC_RESET
parameter_list|(
name|addr
parameter_list|)
value|*(addr + 4) = 0;
end_define

begin_comment
comment|/* reset controller */
end_comment

begin_comment
comment|/* **	Start i/o to/from controller. */
end_comment

begin_define
define|#
directive|define
name|VDDC_ATTENTION
parameter_list|(
name|ctrl
parameter_list|,
name|mdcbadr
parameter_list|)
define|\
value|{ movow(((int)mdcbadr& 0xffff0000)>>16,ctrl) ;\ 			  movow( (int)mdcbadr& 0xffff, ctrl+2);\ 			}
end_define

end_unit

