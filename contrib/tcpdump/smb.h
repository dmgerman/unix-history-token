begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/smb.h,v 1.3 2000/12/17 23:07:50 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*     Copyright (C) Andrew Tridgell 1995-1999     This software may be distributed either under the terms of the    BSD-style license that accompanies tcpdump or the GNU GPL version 2    or later */
end_comment

begin_define
define|#
directive|define
name|CVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|(((unsigned char *)(buf))[pos])
end_define

begin_define
define|#
directive|define
name|PVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|((unsigned)CVAL(buf,pos))
end_define

begin_define
define|#
directive|define
name|SCVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|(CVAL(buf,pos) = (val))
end_define

begin_define
define|#
directive|define
name|SVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|(PVAL(buf,pos)|PVAL(buf,(pos)+1)<<8)
end_define

begin_define
define|#
directive|define
name|IVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|(SVAL(buf,pos)|SVAL(buf,(pos)+2)<<16)
end_define

begin_define
define|#
directive|define
name|SSVALX
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|(CVAL(buf,pos)=(val)&0xFF,CVAL(buf,pos+1)=(val)>>8)
end_define

begin_define
define|#
directive|define
name|SIVALX
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|(SSVALX(buf,pos,val&0xFFFF),SSVALX(buf,pos+2,val>>16))
end_define

begin_define
define|#
directive|define
name|SVALS
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|((int16)SVAL(buf,pos))
end_define

begin_define
define|#
directive|define
name|IVALS
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|((int32)IVAL(buf,pos))
end_define

begin_define
define|#
directive|define
name|SSVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SSVALX((buf),(pos),((uint16)(val)))
end_define

begin_define
define|#
directive|define
name|SIVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SIVALX((buf),(pos),((uint32)(val)))
end_define

begin_define
define|#
directive|define
name|SSVALS
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SSVALX((buf),(pos),((int16)(val)))
end_define

begin_define
define|#
directive|define
name|SIVALS
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SIVALX((buf),(pos),((int32)(val)))
end_define

begin_comment
comment|/* now the reverse routines - these are used in nmb packets (mostly) */
end_comment

begin_define
define|#
directive|define
name|SREV
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<8) | (((x)>>8)&0xFF))
end_define

begin_define
define|#
directive|define
name|IREV
parameter_list|(
name|x
parameter_list|)
value|((SREV(x)<<16) | (SREV((x)>>16)))
end_define

begin_define
define|#
directive|define
name|RSVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|SREV(SVAL(buf,pos))
end_define

begin_define
define|#
directive|define
name|RIVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
value|IREV(IVAL(buf,pos))
end_define

begin_define
define|#
directive|define
name|RSSVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SSVAL(buf,pos,SREV(val))
end_define

begin_define
define|#
directive|define
name|RSIVAL
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|,
name|val
parameter_list|)
value|SIVAL(buf,pos,IREV(val))
end_define

begin_define
define|#
directive|define
name|uint16
value|unsigned short
end_define

begin_define
define|#
directive|define
name|uint32
value|unsigned int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|uchar
end_ifndef

begin_define
define|#
directive|define
name|uchar
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the complete */
end_comment

begin_define
define|#
directive|define
name|SMBmkdir
value|0x00
end_define

begin_comment
comment|/* create directory */
end_comment

begin_define
define|#
directive|define
name|SMBrmdir
value|0x01
end_define

begin_comment
comment|/* delete directory */
end_comment

begin_define
define|#
directive|define
name|SMBopen
value|0x02
end_define

begin_comment
comment|/* open file */
end_comment

begin_define
define|#
directive|define
name|SMBcreate
value|0x03
end_define

begin_comment
comment|/* create file */
end_comment

begin_define
define|#
directive|define
name|SMBclose
value|0x04
end_define

begin_comment
comment|/* close file */
end_comment

begin_define
define|#
directive|define
name|SMBflush
value|0x05
end_define

begin_comment
comment|/* flush file */
end_comment

begin_define
define|#
directive|define
name|SMBunlink
value|0x06
end_define

begin_comment
comment|/* delete file */
end_comment

begin_define
define|#
directive|define
name|SMBmv
value|0x07
end_define

begin_comment
comment|/* rename file */
end_comment

begin_define
define|#
directive|define
name|SMBgetatr
value|0x08
end_define

begin_comment
comment|/* get file attributes */
end_comment

begin_define
define|#
directive|define
name|SMBsetatr
value|0x09
end_define

begin_comment
comment|/* set file attributes */
end_comment

begin_define
define|#
directive|define
name|SMBread
value|0x0A
end_define

begin_comment
comment|/* read from file */
end_comment

begin_define
define|#
directive|define
name|SMBwrite
value|0x0B
end_define

begin_comment
comment|/* write to file */
end_comment

begin_define
define|#
directive|define
name|SMBlock
value|0x0C
end_define

begin_comment
comment|/* lock byte range */
end_comment

begin_define
define|#
directive|define
name|SMBunlock
value|0x0D
end_define

begin_comment
comment|/* unlock byte range */
end_comment

begin_define
define|#
directive|define
name|SMBctemp
value|0x0E
end_define

begin_comment
comment|/* create temporary file */
end_comment

begin_define
define|#
directive|define
name|SMBmknew
value|0x0F
end_define

begin_comment
comment|/* make new file */
end_comment

begin_define
define|#
directive|define
name|SMBchkpth
value|0x10
end_define

begin_comment
comment|/* check directory path */
end_comment

begin_define
define|#
directive|define
name|SMBexit
value|0x11
end_define

begin_comment
comment|/* process exit */
end_comment

begin_define
define|#
directive|define
name|SMBlseek
value|0x12
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|SMBtcon
value|0x70
end_define

begin_comment
comment|/* tree connect */
end_comment

begin_define
define|#
directive|define
name|SMBtconX
value|0x75
end_define

begin_comment
comment|/* tree connect and X*/
end_comment

begin_define
define|#
directive|define
name|SMBtdis
value|0x71
end_define

begin_comment
comment|/* tree disconnect */
end_comment

begin_define
define|#
directive|define
name|SMBnegprot
value|0x72
end_define

begin_comment
comment|/* negotiate protocol */
end_comment

begin_define
define|#
directive|define
name|SMBdskattr
value|0x80
end_define

begin_comment
comment|/* get disk attributes */
end_comment

begin_define
define|#
directive|define
name|SMBsearch
value|0x81
end_define

begin_comment
comment|/* search directory */
end_comment

begin_define
define|#
directive|define
name|SMBsplopen
value|0xC0
end_define

begin_comment
comment|/* open print spool file */
end_comment

begin_define
define|#
directive|define
name|SMBsplwr
value|0xC1
end_define

begin_comment
comment|/* write to print spool file */
end_comment

begin_define
define|#
directive|define
name|SMBsplclose
value|0xC2
end_define

begin_comment
comment|/* close print spool file */
end_comment

begin_define
define|#
directive|define
name|SMBsplretq
value|0xC3
end_define

begin_comment
comment|/* return print queue */
end_comment

begin_define
define|#
directive|define
name|SMBsends
value|0xD0
end_define

begin_comment
comment|/* send single block message */
end_comment

begin_define
define|#
directive|define
name|SMBsendb
value|0xD1
end_define

begin_comment
comment|/* send broadcast message */
end_comment

begin_define
define|#
directive|define
name|SMBfwdname
value|0xD2
end_define

begin_comment
comment|/* forward user name */
end_comment

begin_define
define|#
directive|define
name|SMBcancelf
value|0xD3
end_define

begin_comment
comment|/* cancel forward */
end_comment

begin_define
define|#
directive|define
name|SMBgetmac
value|0xD4
end_define

begin_comment
comment|/* get machine name */
end_comment

begin_define
define|#
directive|define
name|SMBsendstrt
value|0xD5
end_define

begin_comment
comment|/* send start of multi-block message */
end_comment

begin_define
define|#
directive|define
name|SMBsendend
value|0xD6
end_define

begin_comment
comment|/* send end of multi-block message */
end_comment

begin_define
define|#
directive|define
name|SMBsendtxt
value|0xD7
end_define

begin_comment
comment|/* send text of multi-block message */
end_comment

begin_comment
comment|/* Core+ protocol */
end_comment

begin_define
define|#
directive|define
name|SMBlockread
value|0x13
end_define

begin_comment
comment|/* Lock a range and read */
end_comment

begin_define
define|#
directive|define
name|SMBwriteunlock
value|0x14
end_define

begin_comment
comment|/* Unlock a range then write */
end_comment

begin_define
define|#
directive|define
name|SMBreadbraw
value|0x1a
end_define

begin_comment
comment|/* read a block of data with no smb header */
end_comment

begin_define
define|#
directive|define
name|SMBwritebraw
value|0x1d
end_define

begin_comment
comment|/* write a block of data with no smb header */
end_comment

begin_define
define|#
directive|define
name|SMBwritec
value|0x20
end_define

begin_comment
comment|/* secondary write request */
end_comment

begin_define
define|#
directive|define
name|SMBwriteclose
value|0x2c
end_define

begin_comment
comment|/* write a file then close it */
end_comment

begin_comment
comment|/* dos extended protocol */
end_comment

begin_define
define|#
directive|define
name|SMBreadBraw
value|0x1A
end_define

begin_comment
comment|/* read block raw */
end_comment

begin_define
define|#
directive|define
name|SMBreadBmpx
value|0x1B
end_define

begin_comment
comment|/* read block multiplexed */
end_comment

begin_define
define|#
directive|define
name|SMBreadBs
value|0x1C
end_define

begin_comment
comment|/* read block (secondary response) */
end_comment

begin_define
define|#
directive|define
name|SMBwriteBraw
value|0x1D
end_define

begin_comment
comment|/* write block raw */
end_comment

begin_define
define|#
directive|define
name|SMBwriteBmpx
value|0x1E
end_define

begin_comment
comment|/* write block multiplexed */
end_comment

begin_define
define|#
directive|define
name|SMBwriteBs
value|0x1F
end_define

begin_comment
comment|/* write block (secondary request) */
end_comment

begin_define
define|#
directive|define
name|SMBwriteC
value|0x20
end_define

begin_comment
comment|/* write complete response */
end_comment

begin_define
define|#
directive|define
name|SMBsetattrE
value|0x22
end_define

begin_comment
comment|/* set file attributes expanded */
end_comment

begin_define
define|#
directive|define
name|SMBgetattrE
value|0x23
end_define

begin_comment
comment|/* get file attributes expanded */
end_comment

begin_define
define|#
directive|define
name|SMBlockingX
value|0x24
end_define

begin_comment
comment|/* lock/unlock byte ranges and X */
end_comment

begin_define
define|#
directive|define
name|SMBtrans
value|0x25
end_define

begin_comment
comment|/* transaction - name, bytes in/out */
end_comment

begin_define
define|#
directive|define
name|SMBtranss
value|0x26
end_define

begin_comment
comment|/* transaction (secondary request/response) */
end_comment

begin_define
define|#
directive|define
name|SMBioctl
value|0x27
end_define

begin_comment
comment|/* IOCTL */
end_comment

begin_define
define|#
directive|define
name|SMBioctls
value|0x28
end_define

begin_comment
comment|/* IOCTL  (secondary request/response) */
end_comment

begin_define
define|#
directive|define
name|SMBcopy
value|0x29
end_define

begin_comment
comment|/* copy */
end_comment

begin_define
define|#
directive|define
name|SMBmove
value|0x2A
end_define

begin_comment
comment|/* move */
end_comment

begin_define
define|#
directive|define
name|SMBecho
value|0x2B
end_define

begin_comment
comment|/* echo */
end_comment

begin_define
define|#
directive|define
name|SMBopenX
value|0x2D
end_define

begin_comment
comment|/* open and X */
end_comment

begin_define
define|#
directive|define
name|SMBreadX
value|0x2E
end_define

begin_comment
comment|/* read and X */
end_comment

begin_define
define|#
directive|define
name|SMBwriteX
value|0x2F
end_define

begin_comment
comment|/* write and X */
end_comment

begin_define
define|#
directive|define
name|SMBsesssetupX
value|0x73
end_define

begin_comment
comment|/* Session Set Up& X (including User Logon) */
end_comment

begin_define
define|#
directive|define
name|SMBffirst
value|0x82
end_define

begin_comment
comment|/* find first */
end_comment

begin_define
define|#
directive|define
name|SMBfunique
value|0x83
end_define

begin_comment
comment|/* find unique */
end_comment

begin_define
define|#
directive|define
name|SMBfclose
value|0x84
end_define

begin_comment
comment|/* find close */
end_comment

begin_define
define|#
directive|define
name|SMBinvalid
value|0xFE
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_comment
comment|/* Extended 2.0 protocol */
end_comment

begin_define
define|#
directive|define
name|SMBtrans2
value|0x32
end_define

begin_comment
comment|/* TRANS2 protocol set */
end_comment

begin_define
define|#
directive|define
name|SMBtranss2
value|0x33
end_define

begin_comment
comment|/* TRANS2 protocol set, secondary command */
end_comment

begin_define
define|#
directive|define
name|SMBfindclose
value|0x34
end_define

begin_comment
comment|/* Terminate a TRANSACT2_FINDFIRST */
end_comment

begin_define
define|#
directive|define
name|SMBfindnclose
value|0x35
end_define

begin_comment
comment|/* Terminate a TRANSACT2_FINDNOTIFYFIRST */
end_comment

begin_define
define|#
directive|define
name|SMBulogoffX
value|0x74
end_define

begin_comment
comment|/* user logoff */
end_comment

begin_comment
comment|/* NT SMB extensions. */
end_comment

begin_define
define|#
directive|define
name|SMBnttrans
value|0xA0
end_define

begin_comment
comment|/* NT transact */
end_comment

begin_define
define|#
directive|define
name|SMBnttranss
value|0xA1
end_define

begin_comment
comment|/* NT transact secondary */
end_comment

begin_define
define|#
directive|define
name|SMBntcreateX
value|0xA2
end_define

begin_comment
comment|/* NT create and X */
end_comment

begin_define
define|#
directive|define
name|SMBntcancel
value|0xA4
end_define

begin_comment
comment|/* NT cancel */
end_comment

begin_comment
comment|/* pathworks special */
end_comment

begin_define
define|#
directive|define
name|pSETDIR
value|'\377'
end_define

begin_comment
comment|/* these are the TRANS2 sub commands */
end_comment

begin_define
define|#
directive|define
name|TRANSACT2_OPEN
value|0
end_define

begin_define
define|#
directive|define
name|TRANSACT2_FINDFIRST
value|1
end_define

begin_define
define|#
directive|define
name|TRANSACT2_FINDNEXT
value|2
end_define

begin_define
define|#
directive|define
name|TRANSACT2_QFSINFO
value|3
end_define

begin_define
define|#
directive|define
name|TRANSACT2_SETFSINFO
value|4
end_define

begin_define
define|#
directive|define
name|TRANSACT2_QPATHINFO
value|5
end_define

begin_define
define|#
directive|define
name|TRANSACT2_SETPATHINFO
value|6
end_define

begin_define
define|#
directive|define
name|TRANSACT2_QFILEINFO
value|7
end_define

begin_define
define|#
directive|define
name|TRANSACT2_SETFILEINFO
value|8
end_define

begin_define
define|#
directive|define
name|TRANSACT2_FSCTL
value|9
end_define

begin_define
define|#
directive|define
name|TRANSACT2_IOCTL
value|10
end_define

begin_define
define|#
directive|define
name|TRANSACT2_FINDNOTIFYFIRST
value|11
end_define

begin_define
define|#
directive|define
name|TRANSACT2_FINDNOTIFYNEXT
value|12
end_define

begin_define
define|#
directive|define
name|TRANSACT2_MKDIR
value|13
end_define

begin_define
define|#
directive|define
name|PTR_DIFF
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|((unsigned long)(((char *)(p1)) - (char *)(p2)))
end_define

begin_comment
comment|/* some protos */
end_comment

begin_function_decl
specifier|const
name|uchar
modifier|*
name|fdata
parameter_list|(
specifier|const
name|uchar
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
specifier|const
name|uchar
modifier|*
name|maxbuf
parameter_list|)
function_decl|;
end_function_decl

end_unit

