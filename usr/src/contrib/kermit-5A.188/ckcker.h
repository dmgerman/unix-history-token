begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ckcker.h -- Symbol and macro definitions for C-Kermit */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCKER_H
end_ifndef

begin_define
define|#
directive|define
name|CKCKER_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOICP
end_ifdef

begin_comment
comment|/* No Interactive Command Parser */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_comment
comment|/* implies... */
end_comment

begin_define
define|#
directive|define
name|NOSPL
end_define

begin_comment
comment|/* No Script Programming Language */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

begin_comment
comment|/* Codes for what we are doing now */
end_comment

begin_define
define|#
directive|define
name|W_NOTHING
value|0
end_define

begin_comment
comment|/* Nothing */
end_comment

begin_define
define|#
directive|define
name|W_SEND
value|2
end_define

begin_comment
comment|/* SENDing or MAILing */
end_comment

begin_define
define|#
directive|define
name|W_RECV
value|4
end_define

begin_comment
comment|/* RECEIVEing or GETting */
end_comment

begin_define
define|#
directive|define
name|W_REMO
value|8
end_define

begin_comment
comment|/* Doing a REMOTE command */
end_comment

begin_define
define|#
directive|define
name|W_CONNECT
value|16
end_define

begin_comment
comment|/* CONNECT mode */
end_comment

begin_define
define|#
directive|define
name|W_COMMAND
value|32
end_define

begin_comment
comment|/* Command mode */
end_comment

begin_comment
comment|/* Terminal types */
end_comment

begin_define
define|#
directive|define
name|VT100
value|0
end_define

begin_comment
comment|/* Also for VT52 mode */
end_comment

begin_define
define|#
directive|define
name|TEKTRONIX
value|1
end_define

begin_comment
comment|/* Normal packet and window size */
end_comment

begin_define
define|#
directive|define
name|MAXPACK
value|94
end_define

begin_comment
comment|/* Maximum unextended packet size */
end_comment

begin_comment
comment|/* Can't be more than 94! */
end_comment

begin_define
define|#
directive|define
name|MAXWS
value|31
end_define

begin_comment
comment|/* Maximum window size */
end_comment

begin_comment
comment|/* Can't be more than 31! */
end_comment

begin_comment
comment|/* Maximum long packet size for sending packets */
end_comment

begin_comment
comment|/* Override these from cc command line via -DMAXSP=nnn */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSP
end_ifndef

begin_define
define|#
directive|define
name|MAXSP
value|9024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXSP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DYNAMIC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSP
end_ifndef

begin_define
define|#
directive|define
name|MAXSP
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXSP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_comment
comment|/* Maximum long packet size for receiving packets */
end_comment

begin_comment
comment|/* Override these from cc command line via -DMAXRP=nnn */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRP
end_ifndef

begin_define
define|#
directive|define
name|MAXRP
value|9024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXRP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DYNAMIC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRP
end_ifndef

begin_define
define|#
directive|define
name|MAXRP
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXRP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* Restriction removed in edit 185 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* Dynamic or not, */
end_comment

begin_undef
undef|#
directive|undef
name|MAXSP
end_undef

begin_comment
comment|/* VMS seems to have an intrinsic */
end_comment

begin_define
define|#
directive|define
name|MAXSP
value|1920
end_define

begin_comment
comment|/* limit of about 1920. */
end_comment

begin_undef
undef|#
directive|undef
name|MAXRP
end_undef

begin_define
define|#
directive|define
name|MAXRP
value|1920
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Default sizes for windowed packet buffers */
end_comment

begin_comment
comment|/* Override these from cc command line via -DSBSIZ=nnn, -DRBSIZ=nnn */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SBSIZ
end_ifndef

begin_define
define|#
directive|define
name|SBSIZ
value|9050
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SBSIZ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RBSIZ
end_ifndef

begin_define
define|#
directive|define
name|RBSIZ
value|9050
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RBSIZ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DYNAMIC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SBSIZ
end_ifndef

begin_define
define|#
directive|define
name|SBSIZ
value|(MAXPACK * (MAXWS + 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SBSIZ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RBSIZ
end_ifndef

begin_define
define|#
directive|define
name|RBSIZ
value|(MAXPACK * (MAXWS + 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RBSIZ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* Restriction removed in edit 185 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* VMS again... */
end_comment

begin_undef
undef|#
directive|undef
name|SBSIZ
end_undef

begin_define
define|#
directive|define
name|SBSIZ
value|1930
end_define

begin_undef
undef|#
directive|undef
name|RBSIZ
end_undef

begin_define
define|#
directive|define
name|RBSIZ
value|1930
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Kermit parameters and defaults */
end_comment

begin_define
define|#
directive|define
name|CTLQ
value|'#'
end_define

begin_comment
comment|/* Control char prefix I will use */
end_comment

begin_define
define|#
directive|define
name|MYEBQ
value|'&'
end_define

begin_comment
comment|/* 8th-Bit prefix char I will use */
end_comment

begin_define
define|#
directive|define
name|MYRPTQ
value|'~'
end_define

begin_comment
comment|/* Repeat count prefix I will use */
end_comment

begin_define
define|#
directive|define
name|MAXTRY
value|10
end_define

begin_comment
comment|/* Times to retry a packet */
end_comment

begin_define
define|#
directive|define
name|MYPADN
value|0
end_define

begin_comment
comment|/* How many padding chars I need */
end_comment

begin_define
define|#
directive|define
name|MYPADC
value|'\0'
end_define

begin_comment
comment|/* Which padding character I need */
end_comment

begin_define
define|#
directive|define
name|DMYTIM
value|7
end_define

begin_comment
comment|/* Default timeout interval to use. */
end_comment

begin_define
define|#
directive|define
name|URTIME
value|10
end_define

begin_comment
comment|/* Timeout interval to use on me. */
end_comment

begin_define
define|#
directive|define
name|DSRVTIM
value|0
end_define

begin_comment
comment|/* Default server cmd wait timeout. */
end_comment

begin_define
define|#
directive|define
name|DEFTRN
value|0
end_define

begin_comment
comment|/* Default line turnaround handshake */
end_comment

begin_define
define|#
directive|define
name|DEFPAR
value|0
end_define

begin_comment
comment|/* Default parity */
end_comment

begin_define
define|#
directive|define
name|MYEOL
value|CR
end_define

begin_comment
comment|/* Incoming packet terminator. */
end_comment

begin_define
define|#
directive|define
name|DRPSIZ
value|90
end_define

begin_comment
comment|/* Default incoming packet size. */
end_comment

begin_define
define|#
directive|define
name|DSPSIZ
value|90
end_define

begin_comment
comment|/* Default outbound packet size. */
end_comment

begin_define
define|#
directive|define
name|DDELAY
value|5
end_define

begin_comment
comment|/* Default delay. */
end_comment

begin_define
define|#
directive|define
name|DSPEED
value|9600
end_define

begin_comment
comment|/* Default line speed. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* Default CONNECT-mode */
end_comment

begin_define
define|#
directive|define
name|DFESC
value|29
end_define

begin_comment
comment|/* escape character */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_comment
comment|/* Ctrl-] for PC and NeXT */
end_comment

begin_define
define|#
directive|define
name|DFESC
value|29
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_comment
comment|/* And Atari ST */
end_comment

begin_define
define|#
directive|define
name|DFESC
value|29
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DFESC
value|28
end_define

begin_comment
comment|/* Ctrl-backslash for others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOPUSH
end_ifdef

begin_comment
comment|/* NOPUSH implies NOJC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOJC
end_ifndef

begin_comment
comment|/* (no job control) */
end_comment

begin_define
define|#
directive|define
name|NOJC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOJC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPUSH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/* Default for SET SUSPEND */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOJC
end_ifdef

begin_comment
comment|/* UNIX but job control disabled */
end_comment

begin_define
define|#
directive|define
name|DFSUSP
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UNIX, job control enabled. */
end_comment

begin_define
define|#
directive|define
name|DFSUSP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOJC */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DFSUSP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_comment
comment|/* Files */
end_comment

begin_define
define|#
directive|define
name|ZCTERM
value|0
end_define

begin_comment
comment|/* Console terminal */
end_comment

begin_define
define|#
directive|define
name|ZSTDIO
value|1
end_define

begin_comment
comment|/* Standard input/output */
end_comment

begin_define
define|#
directive|define
name|ZIFILE
value|2
end_define

begin_comment
comment|/* Current input file (SEND, etc) (in) */
end_comment

begin_define
define|#
directive|define
name|ZOFILE
value|3
end_define

begin_comment
comment|/* Current output file (RECEIVE, GET) (out) */
end_comment

begin_define
define|#
directive|define
name|ZDFILE
value|4
end_define

begin_comment
comment|/* Current debugging log file (out) */
end_comment

begin_define
define|#
directive|define
name|ZTFILE
value|5
end_define

begin_comment
comment|/* Current transaction log file (out) */
end_comment

begin_define
define|#
directive|define
name|ZPFILE
value|6
end_define

begin_comment
comment|/* Current packet log file (out) */
end_comment

begin_define
define|#
directive|define
name|ZSFILE
value|7
end_define

begin_comment
comment|/* Current session log file (out) */
end_comment

begin_define
define|#
directive|define
name|ZSYSFN
value|8
end_define

begin_comment
comment|/* Input/Output from a system function */
end_comment

begin_define
define|#
directive|define
name|ZRFILE
value|9
end_define

begin_comment
comment|/* Local file for READ (in) */
end_comment

begin_define
define|#
directive|define
name|ZWFILE
value|10
end_define

begin_comment
comment|/* Local file for WRITE (out) */
end_comment

begin_define
define|#
directive|define
name|ZNFILS
value|11
end_define

begin_comment
comment|/* How many defined file numbers */
end_comment

begin_comment
comment|/*  Buffered file i/o is used to avoid gratuitous function calls while encoding a  packet.  The previous way involved 2 nested function calls for EACH character  of the file.  This way, we only do 2 calls per K of data.  This reduces  packet encoding time to 1% of its former cost.  Originally added by Paul  Placeway. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* In VMS, allow for longest possible RMS record */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_define
define|#
directive|define
name|INBUFSIZE
value|32768
end_define

begin_comment
comment|/* File input buffer size */
end_comment

begin_define
define|#
directive|define
name|OBUFSIZE
value|32768
end_define

begin_comment
comment|/* File output buffer size */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INBUFSIZE
value|4096
end_define

begin_comment
comment|/* File input buffer size */
end_comment

begin_define
define|#
directive|define
name|OBUFSIZE
value|4096
end_define

begin_comment
comment|/* File output buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not VMS */
end_comment

begin_comment
comment|/* For all others, just use a 1K buffer */
end_comment

begin_define
define|#
directive|define
name|INBUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|OBUFSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* get the next char; sorta like a getc() macro */
end_comment

begin_define
define|#
directive|define
name|zminchar
parameter_list|()
value|(((--zincnt)>=0) ? ((int)(*zinptr++)& 0377) : zinfill())
end_define

begin_comment
comment|/* stuff a character into the input buffer */
end_comment

begin_define
define|#
directive|define
name|zmstuff
parameter_list|(
name|c
parameter_list|)
value|zinptr--, *zinptr = c, zincnt++
end_define

begin_comment
comment|/* put a character to a file, like putchar() macro */
end_comment

begin_define
define|#
directive|define
name|zmchout
parameter_list|(
name|c
parameter_list|)
define|\
value|((*zoutptr++=(char)(c)),(((++zoutcnt)>=OBUFSIZE)?zoutdump():0))
end_define

begin_comment
comment|/* Screen functions */
end_comment

begin_define
define|#
directive|define
name|SCR_FN
value|1
end_define

begin_comment
comment|/* filename */
end_comment

begin_define
define|#
directive|define
name|SCR_AN
value|2
end_define

begin_comment
comment|/* as-name */
end_comment

begin_define
define|#
directive|define
name|SCR_FS
value|3
end_define

begin_comment
comment|/* file-size */
end_comment

begin_define
define|#
directive|define
name|SCR_XD
value|4
end_define

begin_comment
comment|/* x-packet data */
end_comment

begin_define
define|#
directive|define
name|SCR_ST
value|5
end_define

begin_comment
comment|/* File status: */
end_comment

begin_define
define|#
directive|define
name|ST_OK
value|0
end_define

begin_comment
comment|/*  Transferred OK */
end_comment

begin_define
define|#
directive|define
name|ST_DISC
value|1
end_define

begin_comment
comment|/*  Discarded */
end_comment

begin_define
define|#
directive|define
name|ST_INT
value|2
end_define

begin_comment
comment|/*  Interrupted */
end_comment

begin_define
define|#
directive|define
name|ST_SKIP
value|3
end_define

begin_comment
comment|/*  Skipped */
end_comment

begin_define
define|#
directive|define
name|ST_ERR
value|4
end_define

begin_comment
comment|/*  Fatal Error */
end_comment

begin_define
define|#
directive|define
name|ST_REFU
value|5
end_define

begin_comment
comment|/*  Refused (use Attribute codes for reason) */
end_comment

begin_define
define|#
directive|define
name|ST_INC
value|6
end_define

begin_comment
comment|/* Incompletely received */
end_comment

begin_define
define|#
directive|define
name|SCR_PN
value|6
end_define

begin_comment
comment|/* packet number */
end_comment

begin_define
define|#
directive|define
name|SCR_PT
value|7
end_define

begin_comment
comment|/* packet type or pseudotype */
end_comment

begin_define
define|#
directive|define
name|SCR_TC
value|8
end_define

begin_comment
comment|/* transaction complete */
end_comment

begin_define
define|#
directive|define
name|SCR_EM
value|9
end_define

begin_comment
comment|/* error message */
end_comment

begin_define
define|#
directive|define
name|SCR_WM
value|10
end_define

begin_comment
comment|/* warning message */
end_comment

begin_define
define|#
directive|define
name|SCR_TU
value|11
end_define

begin_comment
comment|/* arbitrary undelimited text */
end_comment

begin_define
define|#
directive|define
name|SCR_TN
value|12
end_define

begin_comment
comment|/* arbitrary new text, delimited at beginning */
end_comment

begin_define
define|#
directive|define
name|SCR_TZ
value|13
end_define

begin_comment
comment|/* arbitrary text, delimited at end */
end_comment

begin_define
define|#
directive|define
name|SCR_QE
value|14
end_define

begin_comment
comment|/* quantity equals (e.g. "foo: 7") */
end_comment

begin_define
define|#
directive|define
name|SCR_CW
value|15
end_define

begin_comment
comment|/* close screen window */
end_comment

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|tochar
parameter_list|(
name|ch
parameter_list|)
value|(((ch) + SP )& 0xFF )
end_define

begin_comment
comment|/* Number to character */
end_comment

begin_define
define|#
directive|define
name|xunchar
parameter_list|(
name|ch
parameter_list|)
value|(((ch) - SP )& 0xFF )
end_define

begin_comment
comment|/* Character to number */
end_comment

begin_define
define|#
directive|define
name|ctl
parameter_list|(
name|ch
parameter_list|)
value|(((ch) ^ 64 )& 0xFF )
end_define

begin_comment
comment|/* Controllify/Uncontrollify */
end_comment

begin_define
define|#
directive|define
name|unpar
parameter_list|(
name|ch
parameter_list|)
value|(((ch)& 127)& 0xFF )
end_define

begin_comment
comment|/* Clear parity bit */
end_comment

begin_comment
comment|/* Symbols for File Attributes */
end_comment

begin_define
define|#
directive|define
name|AT_XALL
value|0
end_define

begin_comment
comment|/* All of them */
end_comment

begin_define
define|#
directive|define
name|AT_ALLY
value|1
end_define

begin_comment
comment|/* All of them on (Yes) */
end_comment

begin_define
define|#
directive|define
name|AT_ALLN
value|2
end_define

begin_comment
comment|/* All of them off (no) */
end_comment

begin_define
define|#
directive|define
name|AT_LENK
value|3
end_define

begin_comment
comment|/* Length in K */
end_comment

begin_define
define|#
directive|define
name|AT_FTYP
value|4
end_define

begin_comment
comment|/* File Type */
end_comment

begin_define
define|#
directive|define
name|AT_DATE
value|5
end_define

begin_comment
comment|/* Creation date */
end_comment

begin_define
define|#
directive|define
name|AT_CREA
value|6
end_define

begin_comment
comment|/* Creator */
end_comment

begin_define
define|#
directive|define
name|AT_ACCT
value|7
end_define

begin_comment
comment|/* Account */
end_comment

begin_define
define|#
directive|define
name|AT_AREA
value|8
end_define

begin_comment
comment|/* Area */
end_comment

begin_define
define|#
directive|define
name|AT_PSWD
value|9
end_define

begin_comment
comment|/* Password for area */
end_comment

begin_define
define|#
directive|define
name|AT_BLKS
value|10
end_define

begin_comment
comment|/* Blocksize */
end_comment

begin_define
define|#
directive|define
name|AT_ACCE
value|11
end_define

begin_comment
comment|/* Access */
end_comment

begin_define
define|#
directive|define
name|AT_ENCO
value|12
end_define

begin_comment
comment|/* Encoding */
end_comment

begin_define
define|#
directive|define
name|AT_DISP
value|13
end_define

begin_comment
comment|/* Disposition */
end_comment

begin_define
define|#
directive|define
name|AT_LPRO
value|14
end_define

begin_comment
comment|/* Local Protection */
end_comment

begin_define
define|#
directive|define
name|AT_GPRO
value|15
end_define

begin_comment
comment|/* Generic Protection */
end_comment

begin_define
define|#
directive|define
name|AT_SYSI
value|16
end_define

begin_comment
comment|/* System ID */
end_comment

begin_define
define|#
directive|define
name|AT_RECF
value|17
end_define

begin_comment
comment|/* Record Format */
end_comment

begin_define
define|#
directive|define
name|AT_SYSP
value|18
end_define

begin_comment
comment|/* System-Dependent Parameters */
end_comment

begin_define
define|#
directive|define
name|AT_LENB
value|19
end_define

begin_comment
comment|/* Length in Bytes */
end_comment

begin_comment
comment|/* Kermit packet information structure */
end_comment

begin_struct
struct|struct
name|pktinfo
block|{
comment|/* Packet information structure */
name|CHAR
modifier|*
name|bf_adr
decl_stmt|;
comment|/*  buffer address */
name|int
name|bf_len
decl_stmt|;
comment|/*  buffer length */
name|CHAR
modifier|*
name|pk_adr
decl_stmt|;
comment|/* Packet address within buffer */
name|int
name|pk_len
decl_stmt|;
comment|/*  length of data within buffer */
name|int
name|pk_typ
decl_stmt|;
comment|/*  packet type */
name|int
name|pk_seq
decl_stmt|;
comment|/*  packet sequence number */
name|int
name|pk_flg
decl_stmt|;
comment|/*  ack'd bit */
name|int
name|pk_rtr
decl_stmt|;
comment|/*  retransmission count */
block|}
struct|;
end_struct

begin_comment
comment|/* File-related symbols and structures */
end_comment

begin_define
define|#
directive|define
name|XYFILN
value|0
end_define

begin_comment
comment|/*  Naming  */
end_comment

begin_define
define|#
directive|define
name|XYFILT
value|1
end_define

begin_comment
comment|/*  Type    */
end_comment

begin_define
define|#
directive|define
name|XYFT_T
value|0
end_define

begin_comment
comment|/*    Text  */
end_comment

begin_define
define|#
directive|define
name|XYFT_B
value|1
end_define

begin_comment
comment|/*    Binary */
end_comment

begin_define
define|#
directive|define
name|XYFT_I
value|2
end_define

begin_comment
comment|/*    Image or Block (VMS) */
end_comment

begin_define
define|#
directive|define
name|XYFT_L
value|3
end_define

begin_comment
comment|/*    Labeled (tagged binary) (VMS) */
end_comment

begin_define
define|#
directive|define
name|XYFT_U
value|4
end_define

begin_comment
comment|/*    Binary Undefined (VMS) */
end_comment

begin_define
define|#
directive|define
name|XYFILW
value|2
end_define

begin_comment
comment|/*  Warning */
end_comment

begin_define
define|#
directive|define
name|XYFILD
value|3
end_define

begin_comment
comment|/*  Display */
end_comment

begin_define
define|#
directive|define
name|XYFD_N
value|0
end_define

begin_comment
comment|/*    None, Off */
end_comment

begin_define
define|#
directive|define
name|XYFD_R
value|1
end_define

begin_comment
comment|/*    Regular, Dots */
end_comment

begin_define
define|#
directive|define
name|XYFD_C
value|2
end_define

begin_comment
comment|/*    Cursor-positioning (e.g. with curses) */
end_comment

begin_define
define|#
directive|define
name|XYFD_S
value|3
end_define

begin_comment
comment|/*    Simple counter */
end_comment

begin_define
define|#
directive|define
name|XYFILC
value|4
end_define

begin_comment
comment|/*  Character set */
end_comment

begin_define
define|#
directive|define
name|XYFILF
value|5
end_define

begin_comment
comment|/*  Record Format */
end_comment

begin_define
define|#
directive|define
name|XYFF_S
value|0
end_define

begin_comment
comment|/*    Stream */
end_comment

begin_define
define|#
directive|define
name|XYFF_V
value|1
end_define

begin_comment
comment|/*    Variable */
end_comment

begin_define
define|#
directive|define
name|XYFF_VB
value|2
end_define

begin_comment
comment|/*    Variable with RCW's */
end_comment

begin_define
define|#
directive|define
name|XYFF_F
value|3
end_define

begin_comment
comment|/*    Fixed length */
end_comment

begin_define
define|#
directive|define
name|XYFF_U
value|4
end_define

begin_comment
comment|/*    Undefined */
end_comment

begin_define
define|#
directive|define
name|XYFILR
value|6
end_define

begin_comment
comment|/*  Record length */
end_comment

begin_define
define|#
directive|define
name|XYFILO
value|7
end_define

begin_comment
comment|/*  Organization */
end_comment

begin_define
define|#
directive|define
name|XYFO_S
value|0
end_define

begin_comment
comment|/*    Sequential */
end_comment

begin_define
define|#
directive|define
name|XYFO_I
value|1
end_define

begin_comment
comment|/*    Indexed */
end_comment

begin_define
define|#
directive|define
name|XYFO_R
value|2
end_define

begin_comment
comment|/*    Relative */
end_comment

begin_define
define|#
directive|define
name|XYFILP
value|8
end_define

begin_comment
comment|/*  Printer carriage control */
end_comment

begin_define
define|#
directive|define
name|XYFP_N
value|0
end_define

begin_comment
comment|/*    Newline (imbedded control characters) */
end_comment

begin_define
define|#
directive|define
name|XYFP_F
value|1
end_define

begin_comment
comment|/*    FORTRAN (space, 1, +, etc, in column 1 */
end_comment

begin_define
define|#
directive|define
name|XYFP_P
value|2
end_define

begin_comment
comment|/*    Special printer carriage controls */
end_comment

begin_define
define|#
directive|define
name|XYFP_X
value|4
end_define

begin_comment
comment|/*    None */
end_comment

begin_define
define|#
directive|define
name|XYFILX
value|9
end_define

begin_comment
comment|/*  Collision Action */
end_comment

begin_define
define|#
directive|define
name|XYFX_A
value|3
end_define

begin_comment
comment|/*    Append */
end_comment

begin_define
define|#
directive|define
name|XYFX_Q
value|5
end_define

begin_comment
comment|/*    Ask */
end_comment

begin_define
define|#
directive|define
name|XYFX_B
value|2
end_define

begin_comment
comment|/*    Backup */
end_comment

begin_define
define|#
directive|define
name|XYFX_D
value|4
end_define

begin_comment
comment|/*    Discard */
end_comment

begin_define
define|#
directive|define
name|XYFX_R
value|0
end_define

begin_comment
comment|/*    Rename */
end_comment

begin_define
define|#
directive|define
name|XYFX_X
value|1
end_define

begin_comment
comment|/*    Replace */
end_comment

begin_define
define|#
directive|define
name|XYFX_U
value|6
end_define

begin_comment
comment|/*    Update */
end_comment

begin_define
define|#
directive|define
name|XYFILB
value|10
end_define

begin_comment
comment|/*  Blocksize */
end_comment

begin_define
define|#
directive|define
name|XYFILZ
value|11
end_define

begin_comment
comment|/*  Disposition */
end_comment

begin_define
define|#
directive|define
name|XYFZ_N
value|0
end_define

begin_comment
comment|/*    New, Create */
end_comment

begin_define
define|#
directive|define
name|XYFZ_A
value|1
end_define

begin_comment
comment|/*    New, append if file exists, else create */
end_comment

begin_define
define|#
directive|define
name|XYFZ_O
value|2
end_define

begin_comment
comment|/*    Old, file must exist */
end_comment

begin_define
define|#
directive|define
name|XYFZ_X
value|3
end_define

begin_comment
comment|/*    Output to pipe/process */
end_comment

begin_define
define|#
directive|define
name|XYFZ_Y
value|4
end_define

begin_comment
comment|/*    Input from pipe/process */
end_comment

begin_define
define|#
directive|define
name|XYFILS
value|12
end_define

begin_comment
comment|/*  File Byte Size */
end_comment

begin_define
define|#
directive|define
name|XYFILL
value|13
end_define

begin_comment
comment|/*  File Label (VMS) */
end_comment

begin_define
define|#
directive|define
name|XYFILI
value|14
end_define

begin_comment
comment|/*  File Incomplete */
end_comment

begin_comment
comment|/* ANSI-style forward declarations for protocol-related functions. */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int input
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int inibufs
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int makebuf
argument_list|,
argument|(int, int, CHAR [], struct pktinfo *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mksbuf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mkrbuf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int spack
argument_list|,
argument|(char, int, int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID proto
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int rpack
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ack1
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ackn
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ackns
argument_list|,
argument|(int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nack
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int resend
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int errpkt
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID logpkt
argument_list|,
argument|(char, int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|CHAR dopar
argument_list|,
argument|(CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chk1
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|unsigned int chk2
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|unsigned int chk3
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sipkt
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rinit
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int spar
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int rcvfil
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|CHAR
operator|*
name|rpar
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|CHAR
operator|*
name|rpar
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int gnfile
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int getsbuf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int getrbuf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int freesbuf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int freerbuf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dumpsbuf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dumprbuf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID freerpkt
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chkwin
argument_list|,
argument|(int, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int rsattr
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|getreason
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int scmd
argument_list|,
argument|(char, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int encstr
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int decode
argument_list|,
argument|(CHAR *, int (*)(char), int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int fnparse
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int syscmd
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cwd
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID screen
argument_list|,
argument|(int, char, long, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int remset
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int initattr
argument_list|,
argument|(struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int gattr
argument_list|,
argument|(CHAR *, struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int adebu
argument_list|,
argument|(char *, struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int canned
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int opent
argument_list|,
argument|(struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int opena
argument_list|,
argument|(char *, struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int openi
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int openo
argument_list|,
argument|(char *, struct zattr *, struct filinfo *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int reof
argument_list|,
argument|(char *, struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID reot
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sfile
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sattr
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sdata
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int seof
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sxeof
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int seot
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int window
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int errmsg
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int clsif
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int clsof
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|CHAR setgen
argument_list|,
argument|(char, char *, char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int getpkt
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int putsrv
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int puttrm
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int putfil
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID zdstuff
argument_list|,
argument|(CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID pktinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rinit
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID resetc
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID xsinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int adjpkl
argument_list|,
argument|(int,int,int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chktimo
argument_list|,
argument|(int,int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nxtpkt
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ack
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ackns
argument_list|,
argument|(int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ackn
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ack1
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nack
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rcalcpsz
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int resend
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int errpkt
argument_list|,
argument|(CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID srinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID tstats
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID fstats
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID intmsg
argument_list|,
argument|(long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID ermsg
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chkint
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID sdebu
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rdebu
argument_list|,
argument|(CHAR *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|dbchr
argument_list|,
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP stptrap
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP trap
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP stptrap
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|SIGTYP trap
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* User interface functions needed by main program, etc. */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID prescan
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID setint
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID cmdini
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dotake
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmdlin
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conect
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ckcgetc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ckcputc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mdmhup
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID herald
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID fixcmd
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int doarg
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID usage
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID doclean
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sndhlp
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID ckhost
argument_list|,
argument|(char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int gettcs
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zkanji
argument_list|,
argument|(int (*)(void))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Kanji function prototypes */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zkanjf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zkanjz
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xkanjz
argument_list|,
argument|(int (*)(char) )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xkanji
argument_list|,
argument|(int, int (*)(char) )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCKER_H */
end_comment

begin_comment
comment|/* End of ckcker.h */
end_comment

end_unit

