begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mscp.h	4.3	82/11/13	*/
end_comment

begin_comment
comment|/*  * Definitions for the Mass Storage Control Protocol  */
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
name|M_OP_SEREX
value|0007
end_define

begin_comment
comment|/* Serious exception end message */
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
name|M_OP_REPLC
value|0024
end_define

begin_comment
comment|/* Replace command */
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
name|M_MD_EXPRS
value|0100000
end_define

begin_comment
comment|/* Express request */
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
name|M_MD_ERROR
value|0010000
end_define

begin_comment
comment|/* Force error */
end_comment

begin_define
define|#
directive|define
name|M_MD_SCCHH
value|0004000
end_define

begin_comment
comment|/* Suppress caching (high speed) */
end_comment

begin_define
define|#
directive|define
name|M_MD_SCCHL
value|0002000
end_define

begin_comment
comment|/* Suppress caching (low speed) */
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
name|M_MD_SSHDW
value|0000200
end_define

begin_comment
comment|/* Suppress shadowing */
end_comment

begin_define
define|#
directive|define
name|M_MD_WBKNV
value|0000100
end_define

begin_comment
comment|/* Write back (non-volatile) */
end_comment

begin_define
define|#
directive|define
name|M_MD_WBKVL
value|0000040
end_define

begin_comment
comment|/* Write back (volatile) */
end_comment

begin_define
define|#
directive|define
name|M_MD_WRSEQ
value|0000020
end_define

begin_comment
comment|/* Write shadow set one unit at a time */
end_comment

begin_comment
comment|/*  * AVAILABLE command modifiers  */
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
name|M_MD_SPNDW
value|0000001
end_define

begin_comment
comment|/* Spin down */
end_comment

begin_comment
comment|/*  * FLUSH command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_FLENU
value|0000001
end_define

begin_comment
comment|/* Flush entire unit */
end_comment

begin_define
define|#
directive|define
name|M_MD_VOLTL
value|0000002
end_define

begin_comment
comment|/* Volatile only */
end_comment

begin_comment
comment|/*  * GET UNIT STATUS command modifiers  */
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
comment|/*  * ONLINE command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_RIP
value|0000001
end_define

begin_comment
comment|/* Allow self destruction */
end_comment

begin_define
define|#
directive|define
name|M_MD_IGNMF
value|0000002
end_define

begin_comment
comment|/* Ignore media format error */
end_comment

begin_comment
comment|/*  * ONLINE and SET UNIT CHARACTERISTICS command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_ALTHI
value|0000040
end_define

begin_comment
comment|/* Alter host identifier */
end_comment

begin_define
define|#
directive|define
name|M_MD_SHDSP
value|0000020
end_define

begin_comment
comment|/* Shadow unit specified */
end_comment

begin_define
define|#
directive|define
name|M_MD_CLWBL
value|0000010
end_define

begin_comment
comment|/* Clear write-back data lost */
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

begin_comment
comment|/*  * REPLACE command modifiers  */
end_comment

begin_define
define|#
directive|define
name|M_MD_PRIMR
value|0000001
end_define

begin_comment
comment|/* Primary replacement block */
end_comment

begin_comment
comment|/*  * End message flags  */
end_comment

begin_define
define|#
directive|define
name|M_EF_BBLKR
value|0200
end_define

begin_comment
comment|/* Bad block reported */
end_comment

begin_define
define|#
directive|define
name|M_EF_BBLKU
value|0100
end_define

begin_comment
comment|/* Bad block unreported */
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

begin_define
define|#
directive|define
name|M_CF_MLTHS
value|0004
end_define

begin_comment
comment|/* Multi-host */
end_comment

begin_define
define|#
directive|define
name|M_CF_SHADW
value|0002
end_define

begin_comment
comment|/* Shadowing */
end_comment

begin_define
define|#
directive|define
name|M_CF_576
value|0001
end_define

begin_comment
comment|/* 576 byte sectors */
end_comment

begin_comment
comment|/*  * Unit flags  */
end_comment

begin_define
define|#
directive|define
name|M_UF_REPLC
value|0100000
end_define

begin_comment
comment|/* Controller initiated bad block replacement */
end_comment

begin_define
define|#
directive|define
name|M_UF_INACT
value|0040000
end_define

begin_comment
comment|/* Inactive shadow set unit */
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
name|M_UF_SCCHH
value|0004000
end_define

begin_comment
comment|/* Suppress caching (high speed) */
end_comment

begin_define
define|#
directive|define
name|M_UF_SCCHL
value|0002000
end_define

begin_comment
comment|/* Suppress caching (low speed) */
end_comment

begin_define
define|#
directive|define
name|M_UF_RMVBL
value|0000200
end_define

begin_comment
comment|/* Removable media */
end_comment

begin_define
define|#
directive|define
name|M_UF_WBKNV
value|0000100
end_define

begin_comment
comment|/* Write back (non-volatile) */
end_comment

begin_define
define|#
directive|define
name|M_UF_576
value|0000004
end_define

begin_comment
comment|/* 576 byte sectors */
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
name|M_ST_MFMTE
value|005
end_define

begin_comment
comment|/* Media format error */
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
name|Mscp_xxx2
index|[
literal|2
index|]
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
literal|4
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
name|long
name|Mscp_time
decl_stmt|;
comment|/* time and date */
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
name|Mscp_shdwunt
decl_stmt|;
comment|/* shadow unit */
name|short
name|Mscp_shdwsts
decl_stmt|;
comment|/* shadow status */
name|short
name|Mscp_track
decl_stmt|;
comment|/* track size */
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
block|}
struct|;
end_struct

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
comment|/*  * Online / Set Unit Characteristics packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_errlgfl
value|mscp_lbn
end_define

begin_define
define|#
directive|define
name|mscp_copyspd
value|mscp_shdwsts
end_define

begin_comment
comment|/*  * Replace packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_rbn
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
name|mscp_shdwunt
value|mscp_un.mscp_getunitsts.Mscp_shdwunt
end_define

begin_define
define|#
directive|define
name|mscp_shdwsts
value|mscp_un.mscp_getunitsts.Mscp_shdwsts
end_define

begin_define
define|#
directive|define
name|mscp_track
value|mscp_un.mscp_getunitsts.Mscp_track
end_define

begin_define
define|#
directive|define
name|mscp_group
value|mscp_un.mscp_getunitsts.Mscp_group
end_define

begin_define
define|#
directive|define
name|mscp_cylinder
value|mscp_un.mscp_getunitsts.Mscp_cylinder
end_define

begin_define
define|#
directive|define
name|mscp_rctsize
value|mscp_un.mscp_getunitsts.Mscp_rctsize
end_define

begin_define
define|#
directive|define
name|mscp_rbns
value|mscp_un.mscp_getunitsts.Mscp_rbns
end_define

begin_define
define|#
directive|define
name|mscp_rctcpys
value|mscp_un.mscp_getunitsts.Mscp_rctcpys
end_define

begin_comment
comment|/*  * Online / Set Unit Characteristics end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_untsize
value|mscp_dscptr
end_define

begin_define
define|#
directive|define
name|mscp_volser
value|mscp_sftwds[0]
end_define

begin_comment
comment|/*  * Set Controller Characteristics end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_cnttmo
value|mscp_hsttmo
end_define

begin_define
define|#
directive|define
name|mscp_cntcmdl
value|mscp_usefrac
end_define

begin_define
define|#
directive|define
name|mscp_cntid
value|mscp_unitid
end_define

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
name|M_FM_DISKTRN
value|2
end_define

begin_comment
comment|/* Disk transfer error */
end_comment

begin_define
define|#
directive|define
name|M_FM_SDI
value|3
end_define

begin_comment
comment|/* SDI error */
end_comment

begin_define
define|#
directive|define
name|M_FM_SMLDSK
value|4
end_define

begin_comment
comment|/* Small disk error */
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
name|mslg_volser
decl_stmt|;
comment|/* volume serial number */
name|long
name|mslg_hdr
decl_stmt|;
comment|/* header */
name|char
name|mslg_sdistat
index|[
literal|12
index|]
decl_stmt|;
comment|/* SDI status information */
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

