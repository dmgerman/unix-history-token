begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)tmscp.h	7.2 (Berkeley) 5/27/88 */
end_comment

begin_comment
comment|/*  *	@(#)tmscp.h	1.3	10/21/85  * Definitions for the Tape Mass Storage Control Protocol  */
end_comment

begin_comment
comment|/****************************************************************  *                                                              *  *        Licensed from Digital Equipment Corporation           *  *                       Copyright (c)                          *  *               Digital Equipment Corporation                  *  *                   Maynard, Massachusetts                     *  *                         1985, 1986                           *  *                    All rights reserved.                      *  *                                                              *  *        The Information in this software is subject to change *  *   without notice and should not be construed as a commitment *  *   by  Digital  Equipment  Corporation.   Digital   makes  no *  *   representations about the suitability of this software for *  *   any purpose.  It is supplied "As Is" without expressed  or *  *   implied  warranty. 					*  *								*  *        If the Regents of the University of California or its *  *   licensees modify the software in a manner creating  	*  *   diriviative copyright rights, appropriate copyright  	*  *   legends may be placed on  the drivative work in addition   *  *   to that set forth above. 					*  *								*  ****************************************************************  *  * Modification history: /sys/vax/tmscp.h  *  * 18-Oct-85 - afd  *	Added: defines for tape format (density) flag values.  *  * 18-Jul-85 - afd  *	Added: #define	M_UF_WBKNV	0000100  *		for write back (which enables cache).  ************************************************************************/
end_comment

begin_comment
comment|/*  * Control message opcodes  */
end_comment

begin_define
define|#
directive|define
name|M_OP_ABORT
value|0001
end_define

begin_comment
comment|/* Abort command */
end_comment

begin_define
define|#
directive|define
name|M_OP_GTCMD
value|0002
end_define

begin_comment
comment|/* Get command status command */
end_comment

begin_define
define|#
directive|define
name|M_OP_GTUNT
value|0003
end_define

begin_comment
comment|/* Get unit status command */
end_comment

begin_define
define|#
directive|define
name|M_OP_STCON
value|0004
end_define

begin_comment
comment|/* Set controller characteristics command */
end_comment

begin_define
define|#
directive|define
name|M_OP_AVAIL
value|0010
end_define

begin_comment
comment|/* Available command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ONLIN
value|0011
end_define

begin_comment
comment|/* Online command */
end_comment

begin_define
define|#
directive|define
name|M_OP_STUNT
value|0012
end_define

begin_comment
comment|/* Set unit characteristics command */
end_comment

begin_define
define|#
directive|define
name|M_OP_DTACP
value|0013
end_define

begin_comment
comment|/* Determine access paths command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ACCES
value|0020
end_define

begin_comment
comment|/* Access command */
end_comment

begin_define
define|#
directive|define
name|M_OP_CMPCD
value|0021
end_define

begin_comment
comment|/* Compare controller data command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ERASE
value|0022
end_define

begin_comment
comment|/* Erase command */
end_comment

begin_define
define|#
directive|define
name|M_OP_FLUSH
value|0023
end_define

begin_comment
comment|/* Flush command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ERGAP
value|0026
end_define

begin_comment
comment|/* Erase gap command */
end_comment

begin_define
define|#
directive|define
name|M_OP_COMP
value|0040
end_define

begin_comment
comment|/* Compare host data command */
end_comment

begin_define
define|#
directive|define
name|M_OP_READ
value|0041
end_define

begin_comment
comment|/* Read command */
end_comment

begin_define
define|#
directive|define
name|M_OP_WRITE
value|0042
end_define

begin_comment
comment|/* Write command */
end_comment

begin_define
define|#
directive|define
name|M_OP_WRITM
value|0044
end_define

begin_comment
comment|/* Write tape mark command */
end_comment

begin_define
define|#
directive|define
name|M_OP_REPOS
value|0045
end_define

begin_comment
comment|/* Reposition command */
end_comment

begin_define
define|#
directive|define
name|M_OP_AVATN
value|0100
end_define

begin_comment
comment|/* Available attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_DUPUN
value|0101
end_define

begin_comment
comment|/* Duplicate unit number attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_ACPTH
value|0102
end_define

begin_comment
comment|/* Access path attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_END
value|0200
end_define

begin_comment
comment|/* End message flag */
end_comment

begin_comment
comment|/*  * Generic command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_COMP
value|0040000
end_define

begin_comment
comment|/* Compare */
end_comment

begin_define
define|#
directive|define
name|M_MD_CLSEX
value|0020000
end_define

begin_comment
comment|/* Clear serious exception */
end_comment

begin_define
define|#
directive|define
name|M_MD_SECOR
value|0001000
end_define

begin_comment
comment|/* Suppress error correction */
end_comment

begin_define
define|#
directive|define
name|M_MD_SEREC
value|0000400
end_define

begin_comment
comment|/* Suppress error recovery */
end_comment

begin_define
define|#
directive|define
name|M_MD_STWRP
value|0000004
end_define

begin_comment
comment|/* Set write protect */
end_comment

begin_define
define|#
directive|define
name|M_MD_ALLCD
value|0000002
end_define

begin_comment
comment|/* All class drivers */
end_comment

begin_define
define|#
directive|define
name|M_MD_NXUNT
value|0000001
end_define

begin_comment
comment|/* Next unit */
end_comment

begin_comment
comment|/*  * TMSCP command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_DLEOT
value|0000200
end_define

begin_comment
comment|/* Delete LEOT */
end_comment

begin_define
define|#
directive|define
name|M_MD_IMMED
value|0000100
end_define

begin_comment
comment|/* Immediate completion */
end_comment

begin_define
define|#
directive|define
name|M_MD_EXCAC
value|0000040
end_define

begin_comment
comment|/* Exclusive access */
end_comment

begin_define
define|#
directive|define
name|M_MD_UNLOD
value|0000020
end_define

begin_comment
comment|/* Unload */
end_comment

begin_define
define|#
directive|define
name|M_MD_REVRS
value|0000010
end_define

begin_comment
comment|/* reverse */
end_comment

begin_define
define|#
directive|define
name|M_MD_OBJCT
value|0000004
end_define

begin_comment
comment|/* object count */
end_comment

begin_define
define|#
directive|define
name|M_MD_REWND
value|0000002
end_define

begin_comment
comment|/* rewind */
end_comment

begin_comment
comment|/*  * End message flags  */
end_comment

begin_define
define|#
directive|define
name|M_EF_ERLOG
value|0040
end_define

begin_comment
comment|/* Error log generated */
end_comment

begin_define
define|#
directive|define
name|M_EF_SEREX
value|0020
end_define

begin_comment
comment|/* Serious exception */
end_comment

begin_define
define|#
directive|define
name|M_EF_EOT
value|0010
end_define

begin_comment
comment|/* End of tape encountered */
end_comment

begin_define
define|#
directive|define
name|M_EF_PLS
value|0004
end_define

begin_comment
comment|/* Position lost */
end_comment

begin_comment
comment|/*  * Controller flags  */
end_comment

begin_define
define|#
directive|define
name|M_CF_ATTN
value|0200
end_define

begin_comment
comment|/* Enable attention messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_MISC
value|0100
end_define

begin_comment
comment|/* Enable miscellaneous error log messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_OTHER
value|0040
end_define

begin_comment
comment|/* Enable other host's error log messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_THIS
value|0020
end_define

begin_comment
comment|/* Enable this host's error log messages */
end_comment

begin_comment
comment|/*  * Unit flags  */
end_comment

begin_define
define|#
directive|define
name|M_UF_WRTPH
value|0020000
end_define

begin_comment
comment|/* Write protect (hardware) */
end_comment

begin_define
define|#
directive|define
name|M_UF_WRTPS
value|0010000
end_define

begin_comment
comment|/* Write protect (software or volume) */
end_comment

begin_define
define|#
directive|define
name|M_UF_WBKNV
value|0000100
end_define

begin_comment
comment|/* Write back (enables cache) */
end_comment

begin_define
define|#
directive|define
name|M_UF_VSMSU
value|0000040
end_define

begin_comment
comment|/* Variable speed mode suppression */
end_comment

begin_define
define|#
directive|define
name|M_UF_VARSP
value|0000020
end_define

begin_comment
comment|/* Variable speed unit */
end_comment

begin_define
define|#
directive|define
name|M_UF_CMPWR
value|0000002
end_define

begin_comment
comment|/* Compare writes */
end_comment

begin_define
define|#
directive|define
name|M_UF_CMPRD
value|0000001
end_define

begin_comment
comment|/* Compare reads */
end_comment

begin_comment
comment|/*  * Status codes  */
end_comment

begin_define
define|#
directive|define
name|M_ST_MASK
value|037
end_define

begin_comment
comment|/* Status code mask */
end_comment

begin_define
define|#
directive|define
name|M_ST_SUCC
value|000
end_define

begin_comment
comment|/* Success */
end_comment

begin_define
define|#
directive|define
name|M_ST_ICMD
value|001
end_define

begin_comment
comment|/* Invalid command */
end_comment

begin_define
define|#
directive|define
name|M_ST_ABRTD
value|002
end_define

begin_comment
comment|/* Command aborted */
end_comment

begin_define
define|#
directive|define
name|M_ST_OFFLN
value|003
end_define

begin_comment
comment|/* Unit offline */
end_comment

begin_define
define|#
directive|define
name|M_ST_AVLBL
value|004
end_define

begin_comment
comment|/* Unit available */
end_comment

begin_define
define|#
directive|define
name|M_ST_WRTPR
value|006
end_define

begin_comment
comment|/* Write protected */
end_comment

begin_define
define|#
directive|define
name|M_ST_COMP
value|007
end_define

begin_comment
comment|/* Compare error */
end_comment

begin_define
define|#
directive|define
name|M_ST_DATA
value|010
end_define

begin_comment
comment|/* Data error */
end_comment

begin_define
define|#
directive|define
name|M_ST_HSTBF
value|011
end_define

begin_comment
comment|/* Host buffer access error */
end_comment

begin_define
define|#
directive|define
name|M_ST_CNTLR
value|012
end_define

begin_comment
comment|/* Controller error */
end_comment

begin_define
define|#
directive|define
name|M_ST_DRIVE
value|013
end_define

begin_comment
comment|/* Drive error */
end_comment

begin_define
define|#
directive|define
name|M_ST_FMTER
value|014
end_define

begin_comment
comment|/* Formatter error */
end_comment

begin_define
define|#
directive|define
name|M_ST_BOT
value|015
end_define

begin_comment
comment|/* BOT encountered */
end_comment

begin_define
define|#
directive|define
name|M_ST_TAPEM
value|016
end_define

begin_comment
comment|/* Tape mark encountered */
end_comment

begin_define
define|#
directive|define
name|M_ST_RDTRN
value|020
end_define

begin_comment
comment|/* Record data truncated */
end_comment

begin_define
define|#
directive|define
name|M_ST_PLOST
value|021
end_define

begin_comment
comment|/* Position lost */
end_comment

begin_define
define|#
directive|define
name|M_ST_SEX
value|022
end_define

begin_comment
comment|/* Serious exception */
end_comment

begin_define
define|#
directive|define
name|M_ST_LED
value|023
end_define

begin_comment
comment|/* LEOT detected */
end_comment

begin_define
define|#
directive|define
name|M_ST_DIAG
value|037
end_define

begin_comment
comment|/* Message from an internal diagnostic */
end_comment

begin_comment
comment|/*  * An MSCP packet  */
end_comment

begin_struct
struct|struct
name|mscp
block|{
name|struct
name|mscp_header
name|mscp_header
decl_stmt|;
comment|/* device specific header */
name|long
name|mscp_cmdref
decl_stmt|;
comment|/* command reference number */
name|short
name|mscp_unit
decl_stmt|;
comment|/* unit number */
name|short
name|mscp_xxx1
decl_stmt|;
comment|/* unused */
name|u_char
name|mscp_opcode
decl_stmt|;
comment|/* opcode */
name|u_char
name|mscp_flags
decl_stmt|;
comment|/* end message flags */
name|short
name|mscp_modifier
decl_stmt|;
comment|/* modifiers */
union|union
block|{
struct|struct
block|{
name|long
name|Mscp_bytecnt
decl_stmt|;
comment|/* byte count */
name|long
name|Mscp_buffer
decl_stmt|;
comment|/* buffer descriptor */
name|long
name|Mscp_mapbase
decl_stmt|;
comment|/* physical addr of map registers */
name|long
name|Mscp_xxx2
decl_stmt|;
comment|/* unused */
name|long
name|Mscp_lbn
decl_stmt|;
comment|/* logical block number */
name|long
name|Mscp_xxx4
decl_stmt|;
comment|/* unused */
name|long
modifier|*
name|Mscp_dscptr
decl_stmt|;
comment|/* pointer to descriptor (software) */
name|long
name|Mscp_sftwds
index|[
literal|17
index|]
decl_stmt|;
comment|/* software words, padding */
block|}
name|mscp_generic
struct|;
struct|struct
block|{
name|short
name|Mscp_version
decl_stmt|;
comment|/* MSCP version */
name|short
name|Mscp_cntflgs
decl_stmt|;
comment|/* controller flags */
name|short
name|Mscp_hsttmo
decl_stmt|;
comment|/* host timeout */
name|short
name|Mscp_usefrac
decl_stmt|;
comment|/* use fraction */
name|quad
name|Mscp_time
decl_stmt|;
comment|/* time and date */
name|long
name|Mscp_cntdep
decl_stmt|;
comment|/* controller dependent parameters */
block|}
name|mscp_setcntchar
struct|;
struct|struct
block|{
name|short
name|Mscp_multunt
decl_stmt|;
comment|/* multi-unit code */
name|short
name|Mscp_unitflgs
decl_stmt|;
comment|/* unit flags */
name|long
name|Mscp_hostid
decl_stmt|;
comment|/* host identifier */
name|quad
name|Mscp_unitid
decl_stmt|;
comment|/* unit identifier */
name|long
name|Mscp_mediaid
decl_stmt|;
comment|/* media type identifier */
name|short
name|Mscp_format
decl_stmt|;
comment|/* format (tape density) */
name|short
name|Mscp_speed
decl_stmt|;
comment|/* tape speed = (ips * bpi) /1000 */
name|short
name|Mscp_fmtmenu
decl_stmt|;
comment|/* format menu */
name|short
name|Mscp_group
decl_stmt|;
comment|/* group size */
name|short
name|Mscp_cylinder
decl_stmt|;
comment|/* cylinder size */
name|short
name|Mscp_xxx3
decl_stmt|;
comment|/* reserved */
name|short
name|Mscp_rctsize
decl_stmt|;
comment|/* RCT table size */
name|char
name|Mscp_rbns
decl_stmt|;
comment|/* RBNs / track */
name|char
name|Mscp_rctcpys
decl_stmt|;
comment|/* RCT copies */
block|}
name|mscp_getunitsts
struct|;
block|}
name|mscp_un
union|;
name|short
name|mscp_fil1
decl_stmt|;
name|short
name|mscp_fil2
decl_stmt|;
name|short
name|mscp_fil3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mscp_msglen
value|(sizeof (struct mscp) - sizeof(struct mscp_header))
end_define

begin_comment
comment|/*  * generic packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_bytecnt
value|mscp_un.mscp_generic.Mscp_bytecnt
end_define

begin_define
define|#
directive|define
name|mscp_buffer
value|mscp_un.mscp_generic.Mscp_buffer
end_define

begin_define
define|#
directive|define
name|mscp_mapbase
value|mscp_un.mscp_generic.Mscp_mapbase
end_define

begin_define
define|#
directive|define
name|mscp_lbn
value|mscp_un.mscp_generic.Mscp_lbn
end_define

begin_define
define|#
directive|define
name|mscp_dscptr
value|mscp_un.mscp_generic.Mscp_dscptr
end_define

begin_define
define|#
directive|define
name|mscp_sftwds
value|mscp_un.mscp_generic.Mscp_sftwds
end_define

begin_define
define|#
directive|define
name|mscp_status
value|mscp_modifier
end_define

begin_comment
comment|/*  * Abort / Get Command Status packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_outref
value|mscp_bytecnt
end_define

begin_comment
comment|/*  * Set Controller Characteristics packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_version
value|mscp_un.mscp_setcntchar.Mscp_version
end_define

begin_define
define|#
directive|define
name|mscp_cntflgs
value|mscp_un.mscp_setcntchar.Mscp_cntflgs
end_define

begin_define
define|#
directive|define
name|mscp_hsttmo
value|mscp_un.mscp_setcntchar.Mscp_hsttmo
end_define

begin_define
define|#
directive|define
name|mscp_usefrac
value|mscp_un.mscp_setcntchar.Mscp_usefrac
end_define

begin_define
define|#
directive|define
name|mscp_time
value|mscp_un.mscp_setcntchar.Mscp_time
end_define

begin_define
define|#
directive|define
name|mscp_cntdep
value|mscp_un.mscp_setcntchar.Mscp_cntdep
end_define

begin_comment
comment|/*  * Reposition command packet fields  */
end_comment

begin_define
define|#
directive|define
name|mscp_reccnt
value|mscp_bytecnt
end_define

begin_comment
comment|/* record/object count */
end_comment

begin_define
define|#
directive|define
name|mscp_tmkcnt
value|mscp_buffer
end_define

begin_comment
comment|/* tape mark count */
end_comment

begin_comment
comment|/*  * Get Unit Status end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_multunt
value|mscp_un.mscp_getunitsts.Mscp_multunt
end_define

begin_define
define|#
directive|define
name|mscp_unitflgs
value|mscp_un.mscp_getunitsts.Mscp_unitflgs
end_define

begin_define
define|#
directive|define
name|mscp_hostid
value|mscp_un.mscp_getunitsts.Mscp_hostid
end_define

begin_define
define|#
directive|define
name|mscp_unitid
value|mscp_un.mscp_getunitsts.Mscp_unitid
end_define

begin_define
define|#
directive|define
name|mscp_mediaid
value|mscp_un.mscp_getunitsts.Mscp_mediaid
end_define

begin_define
define|#
directive|define
name|mscp_format
value|mscp_un.mscp_getunitsts.Mscp_format
end_define

begin_comment
comment|/* density:0=high */
end_comment

begin_define
define|#
directive|define
name|mscp_speed
value|mscp_un.mscp_getunitsts.Mscp_speed
end_define

begin_comment
comment|/* (ips*bpi)/1000 */
end_comment

begin_define
define|#
directive|define
name|mscp_fmtmenu
value|mscp_un.mscp_getunitsts.Mscp_fmtmenu
end_define

begin_comment
comment|/*  * Online / Set Unit Characteristics end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_maxwrt
value|mscp_dscptr
end_define

begin_comment
comment|/* max write byte count */
end_comment

begin_define
define|#
directive|define
name|mscp_noiserec
value|mscp_cylinder
end_define

begin_comment
comment|/* noise record */
end_comment

begin_comment
comment|/*  * Set Controller Characteristics end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_cnttmo
value|mscp_hsttmo
end_define

begin_comment
comment|/* controller timeout */
end_comment

begin_define
define|#
directive|define
name|mscp_cntcmdl
value|mscp_usefrac
end_define

begin_comment
comment|/* controller soft& hardware version */
end_comment

begin_define
define|#
directive|define
name|mscp_cntid
value|mscp_unitid
end_define

begin_comment
comment|/* controller id */
end_comment

begin_comment
comment|/*  * Error Log message format codes  */
end_comment

begin_define
define|#
directive|define
name|M_FM_CNTERR
value|0
end_define

begin_comment
comment|/* Controller error */
end_comment

begin_define
define|#
directive|define
name|M_FM_BUSADDR
value|1
end_define

begin_comment
comment|/* Host memory access error */
end_comment

begin_define
define|#
directive|define
name|M_FM_TAPETRN
value|5
end_define

begin_comment
comment|/* Tape transfer error */
end_comment

begin_define
define|#
directive|define
name|M_FM_STIERR
value|6
end_define

begin_comment
comment|/* STI communication or command failure */
end_comment

begin_define
define|#
directive|define
name|M_FM_STIDEL
value|7
end_define

begin_comment
comment|/* STI drive error log */
end_comment

begin_define
define|#
directive|define
name|M_FM_STIFEL
value|010
end_define

begin_comment
comment|/* STI formatter error log */
end_comment

begin_comment
comment|/*  * Error Log message flags  */
end_comment

begin_define
define|#
directive|define
name|M_LF_SUCC
value|0200
end_define

begin_comment
comment|/* Operation successful */
end_comment

begin_define
define|#
directive|define
name|M_LF_CONT
value|0100
end_define

begin_comment
comment|/* Operation continuing */
end_comment

begin_define
define|#
directive|define
name|M_LF_SQNRS
value|0001
end_define

begin_comment
comment|/* Sequence number reset */
end_comment

begin_comment
comment|/*  * Tape Format Flag Values  */
end_comment

begin_define
define|#
directive|define
name|M_TF_800
value|001
end_define

begin_comment
comment|/* NRZI 800 bpi */
end_comment

begin_define
define|#
directive|define
name|M_TF_PE
value|002
end_define

begin_comment
comment|/* Phase Encoded 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|M_TF_GCR
value|004
end_define

begin_comment
comment|/* Group Code Recording 6250 bpi */
end_comment

begin_define
define|#
directive|define
name|M_TF_BLK
value|010
end_define

begin_comment
comment|/* Cartridge Block Mode */
end_comment

begin_comment
comment|/*  * MSCP Error Log packet  *  *	NOTE: MSCP packet must be padded to this size.  */
end_comment

begin_struct
struct|struct
name|mslg
block|{
name|struct
name|mscp_header
name|mslg_header
decl_stmt|;
comment|/* device specific header */
name|long
name|mslg_cmdref
decl_stmt|;
comment|/* command reference number */
name|short
name|mslg_unit
decl_stmt|;
comment|/* unit number */
name|short
name|mslg_seqnum
decl_stmt|;
comment|/* sequence number */
name|u_char
name|mslg_format
decl_stmt|;
comment|/* format */
name|u_char
name|mslg_flags
decl_stmt|;
comment|/* error log message flags */
name|short
name|mslg_event
decl_stmt|;
comment|/* event code */
name|quad
name|mslg_cntid
decl_stmt|;
comment|/* controller id */
name|u_char
name|mslg_cntsvr
decl_stmt|;
comment|/* controller software version */
name|u_char
name|mslg_cnthvr
decl_stmt|;
comment|/* controller hardware version */
name|short
name|mslg_multunt
decl_stmt|;
comment|/* multi-unit code */
name|quad
name|mslg_unitid
decl_stmt|;
comment|/* unit id */
name|u_char
name|mslg_unitsvr
decl_stmt|;
comment|/* unit software version */
name|u_char
name|mslg_unithvr
decl_stmt|;
comment|/* unit hardware version */
name|short
name|mslg_group
decl_stmt|;
comment|/* group; retry + level */
name|long
name|mslg_position
decl_stmt|;
comment|/* position (object count) */
name|u_char
name|mslg_fmtsvr
decl_stmt|;
comment|/* formatter software version */
name|u_char
name|mslg_fmthvr
decl_stmt|;
comment|/* formatter hardware version */
name|short
name|mslg_xxx2
decl_stmt|;
comment|/* unused */
name|char
name|mslg_stiunsucc
index|[
literal|62
index|]
decl_stmt|;
comment|/* STI status information */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mslg_busaddr
value|mslg_unitid.val[0]
end_define

begin_define
define|#
directive|define
name|mslg_sdecyl
value|mslg_group
end_define

end_unit

