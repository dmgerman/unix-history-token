begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mscp.h	7.4 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * Definitions for the Mass Storage Control Protocol  * I WISH I KNEW WHAT MORE OF THESE WERE.  IT SURE WOULD BE NICE  * IF DEC SOLD DOCUMENTATION FOR THEIR OWN CONTROLLERS.  */
end_comment

begin_comment
comment|/*  * Control message opcodes  */
end_comment

begin_define
define|#
directive|define
name|M_OP_ABORT
value|0x01
end_define

begin_comment
comment|/* Abort command */
end_comment

begin_define
define|#
directive|define
name|M_OP_GETCMDST
value|0x02
end_define

begin_comment
comment|/* Get command status command */
end_comment

begin_define
define|#
directive|define
name|M_OP_GETUNITST
value|0x03
end_define

begin_comment
comment|/* Get unit status command */
end_comment

begin_define
define|#
directive|define
name|M_OP_SETCTLRC
value|0x04
end_define

begin_comment
comment|/* Set controller characteristics command */
end_comment

begin_define
define|#
directive|define
name|M_OP_SEREX
value|0x07
end_define

begin_comment
comment|/* Serious exception end message */
end_comment

begin_define
define|#
directive|define
name|M_OP_AVAILABLE
value|0x08
end_define

begin_comment
comment|/* Available command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ONLINE
value|0x09
end_define

begin_comment
comment|/* Online command */
end_comment

begin_define
define|#
directive|define
name|M_OP_SETUNITC
value|0x0a
end_define

begin_comment
comment|/* Set unit characteristics command */
end_comment

begin_define
define|#
directive|define
name|M_OP_DTACCPATH
value|0x0b
end_define

begin_comment
comment|/* Determine access paths command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ACCESS
value|0x10
end_define

begin_comment
comment|/* Access command */
end_comment

begin_define
define|#
directive|define
name|M_OP_COMPCD
value|0x11
end_define

begin_comment
comment|/* Compare controller data command */
end_comment

begin_define
define|#
directive|define
name|M_OP_ERASE
value|0x12
end_define

begin_comment
comment|/* Erase command */
end_comment

begin_define
define|#
directive|define
name|M_OP_FLUSH
value|0x13
end_define

begin_comment
comment|/* Flush command */
end_comment

begin_define
define|#
directive|define
name|M_OP_REPLACE
value|0x14
end_define

begin_comment
comment|/* Replace command */
end_comment

begin_define
define|#
directive|define
name|M_OP_COMPHD
value|0x20
end_define

begin_comment
comment|/* Compare host data command */
end_comment

begin_define
define|#
directive|define
name|M_OP_READ
value|0x21
end_define

begin_comment
comment|/* Read command */
end_comment

begin_define
define|#
directive|define
name|M_OP_WRITE
value|0x22
end_define

begin_comment
comment|/* Write command */
end_comment

begin_define
define|#
directive|define
name|M_OP_AVAILATTN
value|0x40
end_define

begin_comment
comment|/* Available attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_DUPUNIT
value|0x41
end_define

begin_comment
comment|/* Duplicate unit number attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_ACCPATH
value|0x42
end_define

begin_comment
comment|/* Access path attention message */
end_comment

begin_define
define|#
directive|define
name|M_OP_END
value|0x80
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
value|0x8000
end_define

begin_comment
comment|/* Express request */
end_comment

begin_define
define|#
directive|define
name|M_MD_COMP
value|0x4000
end_define

begin_comment
comment|/* Compare */
end_comment

begin_define
define|#
directive|define
name|M_MD_CLSEX
value|0x2000
end_define

begin_comment
comment|/* Clear serious exception */
end_comment

begin_define
define|#
directive|define
name|M_MD_ERROR
value|0x1000
end_define

begin_comment
comment|/* Force error */
end_comment

begin_define
define|#
directive|define
name|M_MD_SCCHH
value|0x0800
end_define

begin_comment
comment|/* Suppress caching (high speed) */
end_comment

begin_define
define|#
directive|define
name|M_MD_SCCHL
value|0x0400
end_define

begin_comment
comment|/* Suppress caching (low speed) */
end_comment

begin_define
define|#
directive|define
name|M_MD_SECOR
value|0x0200
end_define

begin_comment
comment|/* Suppress error correction */
end_comment

begin_define
define|#
directive|define
name|M_MD_SEREC
value|0x0100
end_define

begin_comment
comment|/* Suppress error recovery */
end_comment

begin_define
define|#
directive|define
name|M_MD_SSHDW
value|0x0080
end_define

begin_comment
comment|/* Suppress shadowing */
end_comment

begin_define
define|#
directive|define
name|M_MD_WBKNV
value|0x0040
end_define

begin_comment
comment|/* Write back (non-volatile) */
end_comment

begin_define
define|#
directive|define
name|M_MD_WBKVL
value|0x0020
end_define

begin_comment
comment|/* Write back (volatile) */
end_comment

begin_define
define|#
directive|define
name|M_MD_WRSEQ
value|0x0010
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
name|M_AVM_ALLCD
value|0x0002
end_define

begin_comment
comment|/* All class drivers */
end_comment

begin_define
define|#
directive|define
name|M_AVM_SPINDOWN
value|0x0001
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
name|M_FLM_FLUSHENU
value|0x0001
end_define

begin_comment
comment|/* Flush entire unit */
end_comment

begin_define
define|#
directive|define
name|M_FLM_VOLATILE
value|0x0002
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
name|M_GUM_NEXTUNIT
value|0x0001
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
name|M_OLM_RIP
value|0x0001
end_define

begin_comment
comment|/* Allow self destruction */
end_comment

begin_define
define|#
directive|define
name|M_OLM_IGNMF
value|0x0002
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
name|M_OSM_ALTERHI
value|0x0020
end_define

begin_comment
comment|/* Alter host identifier */
end_comment

begin_define
define|#
directive|define
name|M_OSM_SHADOWSP
value|0x0010
end_define

begin_comment
comment|/* Shadow unit specified */
end_comment

begin_define
define|#
directive|define
name|M_OSM_CLEARWBL
value|0x0008
end_define

begin_comment
comment|/* Clear write-back data lost */
end_comment

begin_define
define|#
directive|define
name|M_OSM_SETWRPROT
value|0x0004
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
name|M_RPM_PRIMARY
value|0x0001
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
value|0x80
end_define

begin_comment
comment|/* Bad block reported */
end_comment

begin_define
define|#
directive|define
name|M_EF_BBLKU
value|0x40
end_define

begin_comment
comment|/* Bad block unreported */
end_comment

begin_define
define|#
directive|define
name|M_EF_ERLOG
value|0x20
end_define

begin_comment
comment|/* Error log generated */
end_comment

begin_define
define|#
directive|define
name|M_EF_SEREX
value|0x10
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
value|0x80
end_define

begin_comment
comment|/* Enable attention messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_MISC
value|0x40
end_define

begin_comment
comment|/* Enable miscellaneous error log messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_OTHER
value|0x20
end_define

begin_comment
comment|/* Enable other host's error log messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_THIS
value|0x10
end_define

begin_comment
comment|/* Enable this host's error log messages */
end_comment

begin_define
define|#
directive|define
name|M_CF_MLTHS
value|0x04
end_define

begin_comment
comment|/* Multi-host */
end_comment

begin_define
define|#
directive|define
name|M_CF_SHADW
value|0x02
end_define

begin_comment
comment|/* Shadowing */
end_comment

begin_define
define|#
directive|define
name|M_CF_576
value|0x01
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
value|0x8000
end_define

begin_comment
comment|/* Controller initiated bad block replacement */
end_comment

begin_define
define|#
directive|define
name|M_UF_INACT
value|0x4000
end_define

begin_comment
comment|/* Inactive shadow set unit */
end_comment

begin_define
define|#
directive|define
name|M_UF_WRTPH
value|0x2000
end_define

begin_comment
comment|/* Write protect (hardware) */
end_comment

begin_define
define|#
directive|define
name|M_UF_WRTPS
value|0x1000
end_define

begin_comment
comment|/* Write protect (software or volume) */
end_comment

begin_define
define|#
directive|define
name|M_UF_SCCHH
value|0x8000
end_define

begin_comment
comment|/* Suppress caching (high speed) */
end_comment

begin_define
define|#
directive|define
name|M_UF_SCCHL
value|0x4000
end_define

begin_comment
comment|/* Suppress caching (low speed) */
end_comment

begin_define
define|#
directive|define
name|M_UF_RMVBL
value|0x0080
end_define

begin_comment
comment|/* Removable media */
end_comment

begin_define
define|#
directive|define
name|M_UF_WBKNV
value|0x0040
end_define

begin_comment
comment|/* Write back (non-volatile) */
end_comment

begin_define
define|#
directive|define
name|M_UF_576
value|0x0004
end_define

begin_comment
comment|/* 576 byte sectors */
end_comment

begin_define
define|#
directive|define
name|M_UF_CMPWR
value|0x0002
end_define

begin_comment
comment|/* Compare writes */
end_comment

begin_define
define|#
directive|define
name|M_UF_CMPRD
value|0x0001
end_define

begin_comment
comment|/* Compare reads */
end_comment

begin_comment
comment|/*  * Error Log message format codes  */
end_comment

begin_define
define|#
directive|define
name|M_FM_CTLRERR
value|0x00
end_define

begin_comment
comment|/* Controller error */
end_comment

begin_define
define|#
directive|define
name|M_FM_BUSADDR
value|0x01
end_define

begin_comment
comment|/* Host memory access error */
end_comment

begin_define
define|#
directive|define
name|M_FM_DISKTRN
value|0x02
end_define

begin_comment
comment|/* Disk transfer error */
end_comment

begin_define
define|#
directive|define
name|M_FM_SDI
value|0x03
end_define

begin_comment
comment|/* SDI error */
end_comment

begin_define
define|#
directive|define
name|M_FM_SMLDSK
value|0x04
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
value|0x80
end_define

begin_comment
comment|/* Operation successful */
end_comment

begin_define
define|#
directive|define
name|M_LF_CONT
value|0x40
end_define

begin_comment
comment|/* Operation continuing */
end_comment

begin_define
define|#
directive|define
name|M_LF_SQNRS
value|0x01
end_define

begin_comment
comment|/* Sequence number reset */
end_comment

begin_comment
comment|/*  * Status codes  */
end_comment

begin_define
define|#
directive|define
name|M_ST_MASK
value|0x1f
end_define

begin_comment
comment|/* Status code mask */
end_comment

begin_define
define|#
directive|define
name|M_ST_SUCCESS
value|0x00
end_define

begin_comment
comment|/* Success */
end_comment

begin_define
define|#
directive|define
name|M_ST_INVALCMD
value|0x01
end_define

begin_comment
comment|/* Invalid command */
end_comment

begin_define
define|#
directive|define
name|M_ST_ABORTED
value|0x02
end_define

begin_comment
comment|/* Command aborted */
end_comment

begin_define
define|#
directive|define
name|M_ST_OFFLINE
value|0x03
end_define

begin_comment
comment|/* Unit offline */
end_comment

begin_define
define|#
directive|define
name|M_ST_AVAILABLE
value|0x04
end_define

begin_comment
comment|/* Unit available */
end_comment

begin_define
define|#
directive|define
name|M_ST_MFMTERR
value|0x05
end_define

begin_comment
comment|/* Media format error */
end_comment

begin_define
define|#
directive|define
name|M_ST_WRPROT
value|0x06
end_define

begin_comment
comment|/* Write protected */
end_comment

begin_define
define|#
directive|define
name|M_ST_COMPERR
value|0x07
end_define

begin_comment
comment|/* Compare error */
end_comment

begin_define
define|#
directive|define
name|M_ST_DATAERR
value|0x08
end_define

begin_comment
comment|/* Data error */
end_comment

begin_define
define|#
directive|define
name|M_ST_HOSTBUFERR
value|0x09
end_define

begin_comment
comment|/* Host buffer access error */
end_comment

begin_define
define|#
directive|define
name|M_ST_CTLRERR
value|0x0a
end_define

begin_comment
comment|/* Controller error */
end_comment

begin_define
define|#
directive|define
name|M_ST_DRIVEERR
value|0x0b
end_define

begin_comment
comment|/* Drive error */
end_comment

begin_define
define|#
directive|define
name|M_ST_DIAG
value|0x1f
end_define

begin_comment
comment|/* Message from an internal diagnostic */
end_comment

begin_comment
comment|/*  * Subcodes of M_ST_OFFLINE  */
end_comment

begin_define
define|#
directive|define
name|M_OFFLINE_UNKNOWN
value|(0<< 5)
end_define

begin_comment
comment|/* unknown or on other ctlr */
end_comment

begin_define
define|#
directive|define
name|M_OFFLINE_UNMOUNTED
value|(1<< 5)
end_define

begin_comment
comment|/* unmounted or RUN/STOP at STOP */
end_comment

begin_define
define|#
directive|define
name|M_OFFLINE_INOPERATIVE
value|(2<< 5)
end_define

begin_comment
comment|/* inoperative? */
end_comment

begin_define
define|#
directive|define
name|M_OFFLINE_DUPLICATE
value|(4<< 5)
end_define

begin_comment
comment|/* duplicate unit number */
end_comment

begin_define
define|#
directive|define
name|M_OFFLINE_INDIAGNOSTIC
value|(8<< 5)
end_define

begin_comment
comment|/* disabled by FS or diagnostic */
end_comment

begin_comment
comment|/*  * An MSCP packet begins with a header giving the length of  * the entire packet (including the header itself)(?), two bytes  * of device specific data, and the a whole bunch of variants  * depending on message type.  *  * N.B.:  In most cases we distinguish between a `command' and  * an `end' variant as well.  The command variant is that which  * is given to the controller; the `end' variant is its response.  */
end_comment

begin_comment
comment|/*  * Generic sequential message variant (command and response).  */
end_comment

begin_struct
struct|struct
name|mscpv_seq
block|{
name|long
name|seq_bytecount
decl_stmt|;
comment|/* byte count */
define|#
directive|define
name|seq_rbn
value|seq_bytecount
comment|/* aka RBN (replace) */
define|#
directive|define
name|seq_outref
value|seq_bytecount
comment|/* aka outref (abort/get cmd status) */
name|long
name|seq_buffer
decl_stmt|;
comment|/* buffer descriptor */
name|long
name|seq_mapbase
decl_stmt|;
comment|/* page map (first PTE) phys address */
name|long
name|seq_xxx1
decl_stmt|;
comment|/* ? */
comment|/* unused */
name|long
name|seq_lbn
decl_stmt|;
comment|/* logical block number */
name|long
name|seq_xxx2
decl_stmt|;
comment|/* ? */
comment|/* unused */
name|long
modifier|*
name|seq_addr
decl_stmt|;
comment|/* pointer to cmd descriptor */
name|long
name|seq_software
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved to software; unused */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set Controller Characteristics command variant  */
end_comment

begin_struct
struct|struct
name|mscpv_sccc
block|{
name|u_short
name|sccc_version
decl_stmt|;
comment|/* MSCP version number */
name|u_short
name|sccc_ctlrflags
decl_stmt|;
comment|/* controller flags */
name|u_short
name|sccc_hosttimo
decl_stmt|;
comment|/* host timeout */
name|u_short
name|sccc_usefrac
decl_stmt|;
comment|/* use fraction */
name|long
name|sccc_time
decl_stmt|;
comment|/* time and date */
name|long
name|sccc_xxx1
decl_stmt|;
comment|/* ? */
name|long
name|sccc_errlgfl
decl_stmt|;
comment|/* ? */
name|short
name|sccc_xxx2
decl_stmt|;
comment|/* ? */
name|short
name|sccc_copyspd
decl_stmt|;
comment|/* ? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set Controller Characteristics end variant  */
end_comment

begin_struct
struct|struct
name|mscpv_scce
block|{
name|u_short
name|scce_version
decl_stmt|;
comment|/* MSCP version number */
name|u_short
name|scce_ctlrflags
decl_stmt|;
comment|/* controller flags */
name|u_short
name|scce_ctlrtimo
decl_stmt|;
comment|/* controller timeout */
name|u_short
name|scce_ctlrcmdl
decl_stmt|;
comment|/* ??? */
name|quad
name|scce_ctlrid
decl_stmt|;
comment|/* controller ID */
name|long
name|scce_xxx
index|[
literal|3
index|]
decl_stmt|;
comment|/* ? */
name|long
name|scce_volser
decl_stmt|;
comment|/* volume serial number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * On Line command variant  */
end_comment

begin_struct
struct|struct
name|mscpv_onlc
block|{
name|long
name|onlc_xxx1
index|[
literal|4
index|]
decl_stmt|;
comment|/* ? */
name|long
name|onlc_errlgfl
decl_stmt|;
comment|/* error log flag? */
name|short
name|onlc_xxx2
decl_stmt|;
comment|/* ? */
name|short
name|onlc_copyspd
decl_stmt|;
comment|/* copy speed? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * On Line end variant  */
end_comment

begin_struct
struct|struct
name|mscpv_onle
block|{
name|long
name|onle_xxx1
index|[
literal|3
index|]
decl_stmt|;
comment|/* ? */
comment|/*???*/
name|short
name|onle_xxx2
decl_stmt|;
comment|/* ? */
name|u_char
name|onle_drivetype
decl_stmt|;
comment|/* drive type index (same in guse) */
name|char
name|onle_xxx3
decl_stmt|;
comment|/* ? */
name|long
name|onle_mediaid
decl_stmt|;
comment|/* media type id (same in guse) */
name|long
name|onle_xxx4
decl_stmt|;
comment|/* ? */
name|long
name|onle_unitsize
decl_stmt|;
comment|/* unit size in sectors */
name|long
name|onle_volser
decl_stmt|;
comment|/* volume serial number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get Unit Status end variant (and Avail Attn?)  */
end_comment

begin_struct
struct|struct
name|mscpv_guse
block|{
name|u_short
name|guse_multunit
decl_stmt|;
comment|/* multi-unit code */
name|u_short
name|guse_unitflags
decl_stmt|;
comment|/* unit flags */
name|long
name|guse_hostid
decl_stmt|;
comment|/* host id */
name|long
name|guse_unitid0
decl_stmt|;
comment|/*???*/
name|short
name|guse_unitid1
decl_stmt|;
comment|/*???*/
name|u_char
name|guse_drivetype
decl_stmt|;
comment|/* drive type index */
name|u_char
name|guse_unitid2
decl_stmt|;
comment|/*???*/
name|long
name|guse_mediaid
decl_stmt|;
comment|/* media type id (encoded) */
name|short
name|guse_shadowunit
decl_stmt|;
comment|/* shadow unit */
name|short
name|guse_shadowstat
decl_stmt|;
comment|/* shadow status */
name|u_short
name|guse_nspt
decl_stmt|;
comment|/* sectors per track */
name|u_short
name|guse_group
decl_stmt|;
comment|/* track group size */
name|u_short
name|guse_ngpc
decl_stmt|;
comment|/* groups per cylinder */
name|u_short
name|guse_xxx
decl_stmt|;
comment|/* reserved */
name|u_short
name|guse_rctsize
decl_stmt|;
comment|/* RCT size (sectors) */
name|u_char
name|guse_nrpt
decl_stmt|;
comment|/* RBNs per track */
name|u_char
name|guse_nrct
decl_stmt|;
comment|/* number of RCTs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros to break up and build media IDs.  An ID encodes the port  * type in the top 10 bits, and the drive type in the remaining 22.  * The 10 bits, and 15 of the 22, are in groups of 5, with the value  * 0 representing space and values 1..26 representing A..Z.  The low  * 7 bits represent a number in 0..127.  Hence an RA81 on a UDA50  * is<D><U><R><A><>81, or 0x25641051.  This encoding scheme is known  * in part in uda.c.  *  * The casts below are just to make pcc generate better code.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_MEDIA_PORT
parameter_list|(
name|id
parameter_list|)
value|(((long)(id)>> 22)& 0x3ff)
end_define

begin_comment
comment|/* port */
end_comment

begin_define
define|#
directive|define
name|MSCP_MEDIA_DRIVE
parameter_list|(
name|id
parameter_list|)
value|((long)(id)& 0x003fffff)
end_define

begin_comment
comment|/* drive */
end_comment

begin_define
define|#
directive|define
name|MSCP_MID_ECH
parameter_list|(
name|n
parameter_list|,
name|id
parameter_list|)
value|(((long)(id)>> ((n) * 5 + 7))& 0x1f)
end_define

begin_define
define|#
directive|define
name|MSCP_MID_CHAR
parameter_list|(
name|n
parameter_list|,
name|id
parameter_list|)
define|\
value|(MSCP_MID_ECH(n, id) ? MSCP_MID_ECH(n, id) + '@' : ' ')
end_define

begin_define
define|#
directive|define
name|MSCP_MID_NUM
parameter_list|(
name|id
parameter_list|)
value|((id)& 0x7f)
end_define

begin_comment
comment|/* for, e.g., RA81 */
end_comment

begin_define
define|#
directive|define
name|MSCP_MKDRIVE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
define|\
value|(((a) - '@')<< 17 | ((b) - '@')<< 12 | (n))
end_define

begin_comment
comment|/* for, e.g., RRD50 */
end_comment

begin_define
define|#
directive|define
name|MSCP_MKDRIVE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
define|\
value|(((a) - '@')<< 17 | ((b) - '@')<< 12 | ((c) - '@')<< 7 | (n))
end_define

begin_comment
comment|/*  * Error datagram variant.  */
end_comment

begin_struct
struct|struct
name|mscpv_erd
block|{
name|quad
name|erd_ctlrid
decl_stmt|;
comment|/* controller ID */
name|u_char
name|erd_ctlrsoftware
decl_stmt|;
comment|/* controller software version */
name|u_char
name|erd_ctlrhardware
decl_stmt|;
comment|/* controller hardware version */
name|u_short
name|erd_multiunit
decl_stmt|;
comment|/* multi-unit code (?) */
union|union
block|{
name|u_long
name|un_busaddr
decl_stmt|;
comment|/* bus address, if mem access err */
name|quad
name|un_unitid
decl_stmt|;
comment|/* unit id, otherwise */
block|}
name|erd_un1
union|;
define|#
directive|define
name|erd_busaddr
value|erd_un1.un_busaddr
define|#
directive|define
name|erd_unitid
value|erd_un1.un_unitid
name|u_char
name|erd_unitsoftware
decl_stmt|;
comment|/* unit software version */
name|u_char
name|erd_unithardware
decl_stmt|;
comment|/* unit hardware version */
union|union
block|{
name|u_char
name|un_b
index|[
literal|2
index|]
decl_stmt|;
comment|/* level, retry (if disk xfer err) */
name|u_short
name|un_s
decl_stmt|;
comment|/* cylinder (if small disk error) */
block|}
name|erd_un2
union|;
define|#
directive|define
name|erd_level
value|erd_un2.un_b[0]
define|#
directive|define
name|erd_retry
value|erd_un2.un_b[1]
define|#
directive|define
name|erd_sdecyl
value|erd_un2.un_s
name|long
name|erd_volser
decl_stmt|;
comment|/* volume serial number */
name|u_long
name|erd_hdr
decl_stmt|;
comment|/* `header' (block number) */
name|u_char
name|erd_sdistat
index|[
literal|12
index|]
decl_stmt|;
comment|/* SDI status information (?) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * I am making brash assumptions about the first four bytes of all  * MSCP packets.  These appear to be true for both UDA50s and TMSCP  * devices (TU81, TA81, TK50).  DEC claim that these four bytes are  * not part of MSCP itself, yet at least the length is necessary  * for, e.g., error checking.  */
end_comment

begin_struct
struct|struct
name|mscp
block|{
name|u_short
name|mscp_msglen
decl_stmt|;
comment|/* length in bytes */
name|u_char
name|mscp_msgtc
decl_stmt|;
comment|/* type (high 4 bits) and credits */
name|u_char
name|mscp_vcid
decl_stmt|;
comment|/* virtual circuit ID */
name|long
name|mscp_cmdref
decl_stmt|;
comment|/* command reference number */
name|u_short
name|mscp_unit
decl_stmt|;
comment|/* unit number */
name|u_short
name|mscp_seqnum
decl_stmt|;
comment|/* sequence number */
name|u_char
name|mscp_opcode
decl_stmt|;
comment|/* opcode */
define|#
directive|define
name|mscp_format
value|mscp_opcode
comment|/* aka format (datagrams) */
name|u_char
name|mscp_flags
decl_stmt|;
comment|/* flags */
name|u_short
name|mscp_modifier
decl_stmt|;
comment|/* modifier (commands) */
define|#
directive|define
name|mscp_status
value|mscp_modifier
comment|/* aka status (ends) */
define|#
directive|define
name|mscp_event
value|mscp_modifier
comment|/* aka event (datagrams) */
union|union
block|{
name|struct
name|mscpv_seq
name|un_seq
decl_stmt|;
comment|/* generic sequential msg */
name|struct
name|mscpv_sccc
name|un_sccc
decl_stmt|;
comment|/* SCC command */
name|struct
name|mscpv_scce
name|un_scce
decl_stmt|;
comment|/* SCC end */
name|struct
name|mscpv_onlc
name|un_onlc
decl_stmt|;
comment|/* on line command */
name|struct
name|mscpv_onle
name|un_onle
decl_stmt|;
comment|/* on line end */
name|struct
name|mscpv_guse
name|un_guse
decl_stmt|;
comment|/* get unit status */
name|struct
name|mscpv_erd
name|un_erd
decl_stmt|;
comment|/* error datagram */
block|}
name|mscp_un
union|;
comment|/*???*/
name|long
name|mscp_xxx
decl_stmt|;
comment|/* pad to 64 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Define message length according to the DEC specifications by dropping  * the four byte header.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_MSGLEN
value|(sizeof (struct mscp) - 4)
end_define

begin_comment
comment|/*  * Shorthand  */
end_comment

begin_comment
comment|/*  * Generic packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_seq
value|mscp_un.un_seq
end_define

begin_comment
comment|/*  * Set Controller Characteristics packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_sccc
value|mscp_un.un_sccc
end_define

begin_comment
comment|/*  * Set Controller Characteristics end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_scce
value|mscp_un.un_scce
end_define

begin_comment
comment|/*  * Online / Set Unit Characteristics command packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_onlc
value|mscp_un.un_onlc
end_define

begin_comment
comment|/*  * Online end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_onle
value|mscp_un.un_onle
end_define

begin_comment
comment|/*  * Get Unit Status end packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_guse
value|mscp_un.un_guse
end_define

begin_comment
comment|/*  * MSCP Error Log packet  */
end_comment

begin_define
define|#
directive|define
name|mscp_erd
value|mscp_un.un_erd
end_define

begin_comment
comment|/*  * MSCP seq_addr field actually belongs to overall packet.  */
end_comment

begin_define
define|#
directive|define
name|mscp_addr
value|mscp_seq.seq_addr
end_define

begin_comment
comment|/*  * Macros to break up mscp_msgtc, and types.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_MSGTYPE
parameter_list|(
name|m
parameter_list|)
value|((m)& 0xf0)
end_define

begin_define
define|#
directive|define
name|MSCP_CREDITS
parameter_list|(
name|m
parameter_list|)
value|((m)& 0x0f)
end_define

begin_define
define|#
directive|define
name|MSCPT_SEQ
value|0x00
end_define

begin_comment
comment|/* sequential message */
end_comment

begin_define
define|#
directive|define
name|MSCPT_DATAGRAM
value|0x10
end_define

begin_comment
comment|/* error datagram */
end_comment

begin_define
define|#
directive|define
name|MSCPT_CREDITS
value|0x20
end_define

begin_comment
comment|/* credit notification */
end_comment

begin_define
define|#
directive|define
name|MSCPT_MAINTENANCE
value|0xf0
end_define

begin_comment
comment|/* who knows */
end_comment

begin_comment
comment|/*  * Here begin more perhaps brash assumptions about MSCP devices...  */
end_comment

begin_comment
comment|/*  * MSCP controllers have `command rings' and `response rings'.  A  * command ring is a pool of MSCP packets that the host uses to give  * commands to the controller; a response ring is a pool of MSCP  * packets that the controller uses to give back responses.  Entries  * in the command and response rings are `owned' by either the host  * or the controller; only the owner is allowed to alter any of the  * fields in the MSCP packet.  Thus, free command packets are owned  * by the host, and free response packets by the controller.  When  * the host gives a packet to the controller, it tells the controller  * by touching a device register; when the controller gives a response  * to the host, it generates an interrupt if enabled, and sets  * a device register as well.  *  * The pool is `described' by a set of pointers to the packets, along  * with the two flags below.  */
end_comment

begin_define
define|#
directive|define
name|MSCP_OWN
value|0x80000000
end_define

begin_comment
comment|/* controller owns this packet */
end_comment

begin_define
define|#
directive|define
name|MSCP_INT
value|0x40000000
end_define

begin_comment
comment|/* controller should interrupt */
end_comment

end_unit

