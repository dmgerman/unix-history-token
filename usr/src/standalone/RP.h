begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* *	*  RP06  Definitions  * */
end_comment

begin_comment
comment|/* *	RP06  Device  Register  Offsets */
end_comment

begin_define
define|#
directive|define
name|RP_cr
value|0
end_define

begin_comment
comment|/* control reg */
end_comment

begin_define
define|#
directive|define
name|RP_sr
value|1
end_define

begin_comment
comment|/* status reg */
end_comment

begin_define
define|#
directive|define
name|RP_er1
value|2
end_define

begin_comment
comment|/*  Err reg 1 */
end_comment

begin_define
define|#
directive|define
name|RP_mr
value|3
end_define

begin_comment
comment|/* Maintenance reg */
end_comment

begin_define
define|#
directive|define
name|RP_as
value|4
end_define

begin_comment
comment|/* attention summary */
end_comment

begin_define
define|#
directive|define
name|RP_stk
value|5
end_define

begin_comment
comment|/* desired track/sector */
end_comment

begin_define
define|#
directive|define
name|RP_dt
value|6
end_define

begin_comment
comment|/* drive type */
end_comment

begin_define
define|#
directive|define
name|RP_la
value|7
end_define

begin_comment
comment|/* look ahead */
end_comment

begin_define
define|#
directive|define
name|RP_sn
value|8
end_define

begin_comment
comment|/*  serial no. */
end_comment

begin_define
define|#
directive|define
name|RP_off
value|9
end_define

begin_comment
comment|/* offset reg */
end_comment

begin_define
define|#
directive|define
name|RP_cyl
value|10
end_define

begin_comment
comment|/* desired cyl */
end_comment

begin_define
define|#
directive|define
name|RP_cca
value|11
end_define

begin_comment
comment|/* current cyl addr */
end_comment

begin_define
define|#
directive|define
name|RP_er2
value|12
end_define

begin_comment
comment|/* err reg 2 */
end_comment

begin_define
define|#
directive|define
name|RP_er3
value|13
end_define

begin_comment
comment|/*  err reg 3 */
end_comment

begin_define
define|#
directive|define
name|RP_Epos
value|14
end_define

begin_comment
comment|/*  ECC position reg */
end_comment

begin_define
define|#
directive|define
name|RP_Epat
value|15
end_define

begin_comment
comment|/*  ECC pattern reg */
end_comment

begin_comment
comment|/* *	RP06  Function  Codes */
end_comment

begin_define
define|#
directive|define
name|RP_GO
value|1
end_define

begin_comment
comment|/*  go bit */
end_comment

begin_define
define|#
directive|define
name|RP_NOP
end_define

begin_comment
comment|/* no-op function code in control reg */
end_comment

begin_define
define|#
directive|define
name|RP_UNL
value|2
end_define

begin_comment
comment|/* Unload */
end_comment

begin_define
define|#
directive|define
name|RP_RCAL
value|6
end_define

begin_comment
comment|/* Recalibrate */
end_comment

begin_define
define|#
directive|define
name|RP_DC
value|010
end_define

begin_comment
comment|/*  Drive Clear */
end_comment

begin_define
define|#
directive|define
name|RP_REL
value|012
end_define

begin_comment
comment|/* Release */
end_comment

begin_define
define|#
directive|define
name|RP_SRCH
value|030
end_define

begin_comment
comment|/* Search */
end_comment

begin_define
define|#
directive|define
name|RP_WCD
value|050
end_define

begin_comment
comment|/* Write Check Data */
end_comment

begin_define
define|#
directive|define
name|RP_WCH
value|052
end_define

begin_comment
comment|/* Write Check Header& Data */
end_comment

begin_define
define|#
directive|define
name|RP_WR
value|060
end_define

begin_comment
comment|/* Write Data */
end_comment

begin_define
define|#
directive|define
name|RP_WHD
value|062
end_define

begin_comment
comment|/* Write Header& Data (Format) */
end_comment

begin_define
define|#
directive|define
name|RP_RED
value|070
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|RP_RHD
value|072
end_define

begin_comment
comment|/* Read Header& Data */
end_comment

begin_define
define|#
directive|define
name|RP_SEEK
value|4
end_define

begin_comment
comment|/* Seek */
end_comment

begin_define
define|#
directive|define
name|RP_OFF
value|014
end_define

begin_comment
comment|/* Centerline Offset */
end_comment

begin_define
define|#
directive|define
name|RP_RTC
value|016
end_define

begin_comment
comment|/* Return to Centerline */
end_comment

begin_define
define|#
directive|define
name|RP_PA
value|022
end_define

begin_comment
comment|/* Pack Acknowledge */
end_comment

begin_define
define|#
directive|define
name|RP_RIP
value|020
end_define

begin_comment
comment|/* Read-in Preset */
end_comment

begin_comment
comment|/* *	RP06 Offset Register */
end_comment

begin_define
define|#
directive|define
name|RP_HCI
value|0x400
end_define

begin_comment
comment|/*  Header Compare Inhibit */
end_comment

begin_define
define|#
directive|define
name|RP_ECI
value|0x800
end_define

begin_comment
comment|/*  ECC Inhibit */
end_comment

begin_comment
comment|/* *	RP06  Status Reg */
end_comment

begin_define
define|#
directive|define
name|RP_ATA
value|0x8000
end_define

begin_comment
comment|/* Attention Active */
end_comment

begin_define
define|#
directive|define
name|RP_ERR
value|0x4000
end_define

begin_comment
comment|/* Composite Error */
end_comment

begin_define
define|#
directive|define
name|RP_PIP
value|0x2000
end_define

begin_comment
comment|/* Positioning Operation in Progress */
end_comment

begin_define
define|#
directive|define
name|RP_MOL
value|0x1000
end_define

begin_comment
comment|/* Medium On-Line */
end_comment

begin_define
define|#
directive|define
name|RP_WRL
value|0x800
end_define

begin_comment
comment|/*  Write Lock */
end_comment

begin_define
define|#
directive|define
name|RP_LST
value|0x400
end_define

begin_comment
comment|/* Last Sector Transferred */
end_comment

begin_define
define|#
directive|define
name|RP_PGM
value|0x200
end_define

begin_comment
comment|/* Programmable (Dual Port) */
end_comment

begin_define
define|#
directive|define
name|RP_DRP
value|0x100
end_define

begin_comment
comment|/* Drive Preset (Dual Port) */
end_comment

begin_define
define|#
directive|define
name|RP_DRY
value|0x80
end_define

begin_comment
comment|/*  Drive Ready */
end_comment

begin_define
define|#
directive|define
name|RP_VV
value|0x40
end_define

begin_comment
comment|/* Volume Valid */
end_comment

begin_comment
comment|/* *  RP06  Error  Register */
end_comment

begin_define
define|#
directive|define
name|RP_DCK
value|0x8000
end_define

begin_comment
comment|/*  Data Check */
end_comment

begin_define
define|#
directive|define
name|RP_UNS
value|0x4000
end_define

begin_comment
comment|/* Drive Unsafe */
end_comment

begin_define
define|#
directive|define
name|RP_OPI
value|0x2000
end_define

begin_comment
comment|/* Operation Incomplete */
end_comment

begin_define
define|#
directive|define
name|RP_DTE
value|0x1000
end_define

begin_comment
comment|/* Drive Timing Error */
end_comment

begin_define
define|#
directive|define
name|RP_WLE
value|0x800
end_define

begin_comment
comment|/* Write LOck Error */
end_comment

begin_define
define|#
directive|define
name|RP_IAE
value|0x400
end_define

begin_comment
comment|/* Invalid Address */
end_comment

begin_define
define|#
directive|define
name|RP_ADE
value|0x200
end_define

begin_comment
comment|/* Address Overflow */
end_comment

begin_define
define|#
directive|define
name|RP_HCRC
value|0x100
end_define

begin_comment
comment|/* Header CRC Error */
end_comment

begin_define
define|#
directive|define
name|RP_HCE
value|0x80
end_define

begin_comment
comment|/* Header Compare Error */
end_comment

begin_define
define|#
directive|define
name|RP_ECH
value|0x40
end_define

begin_comment
comment|/* ECC Hard Error */
end_comment

begin_define
define|#
directive|define
name|RP_WCF
value|0x20
end_define

begin_comment
comment|/* Write Clock Fail */
end_comment

begin_define
define|#
directive|define
name|RP_FER
value|0x10
end_define

begin_comment
comment|/* Format Error */
end_comment

begin_define
define|#
directive|define
name|RP_PAR
value|8
end_define

begin_comment
comment|/* Parity Error */
end_comment

begin_define
define|#
directive|define
name|RP_RMR
value|4
end_define

begin_comment
comment|/* Register Modification Refused */
end_comment

begin_define
define|#
directive|define
name|RP_ILR
value|2
end_define

begin_comment
comment|/* Illegal Register */
end_comment

begin_define
define|#
directive|define
name|RP_ILF
value|1
end_define

begin_comment
comment|/* Illegal Function */
end_comment

begin_comment
comment|/* *  misc */
end_comment

begin_define
define|#
directive|define
name|RP_BASE
value|0x400
end_define

begin_comment
comment|/* start of external reg's on MBA */
end_comment

begin_define
define|#
directive|define
name|RP6CYL
value|815
end_define

begin_comment
comment|/* no. RP06 cylinders/pack */
end_comment

begin_define
define|#
directive|define
name|RP6TRK
value|19
end_define

begin_comment
comment|/* no. tracks/cyl */
end_comment

begin_define
define|#
directive|define
name|RP6SEC
value|22
end_define

begin_comment
comment|/* no. sectors/track */
end_comment

begin_define
define|#
directive|define
name|RP6ST
value|(rptrk*rpsec)
end_define

begin_comment
comment|/* no. sectors/cyl */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|(rpcyl*rptrk*rpsec)
end_define

begin_comment
comment|/* no. sectors/pack */
end_comment

begin_define
define|#
directive|define
name|RP_FMT
value|0x1000
end_define

begin_comment
comment|/* format bit in offset reg */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|RM3CYL
value|823
end_define

begin_comment
comment|/*  RM03 */
end_comment

begin_define
define|#
directive|define
name|RM3TRK
value|5
end_define

begin_define
define|#
directive|define
name|RM3SEC
value|32
end_define

begin_define
define|#
directive|define
name|RP6typ
value|022
end_define

begin_define
define|#
directive|define
name|RM3typ
value|024
end_define

begin_define
define|#
directive|define
name|RP6HD
value|8
end_define

begin_comment
comment|/* no. bytes RP06 sector header */
end_comment

begin_define
define|#
directive|define
name|RM3HD
value|4
end_define

begin_comment
comment|/*  no. bytes  RM03 sector header */
end_comment

begin_define
define|#
directive|define
name|RM_BSB
value|0xc000
end_define

begin_comment
comment|/*  bad sector bits for format */
end_comment

end_unit

