begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ckcker.h -- Symbol and macro definitions for C-Kermit */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/* Mnemonics for ASCII characters */
end_comment

begin_define
define|#
directive|define
name|NUL
value|000
end_define

begin_comment
comment|/* ASCII Null */
end_comment

begin_define
define|#
directive|define
name|SOH
value|001
end_define

begin_comment
comment|/* ASCII Start of header */
end_comment

begin_define
define|#
directive|define
name|BEL
value|007
end_define

begin_comment
comment|/* ASCII Bell (Beep) */
end_comment

begin_define
define|#
directive|define
name|BS
value|010
end_define

begin_comment
comment|/* ASCII Backspace */
end_comment

begin_define
define|#
directive|define
name|LF
value|012
end_define

begin_comment
comment|/* ASCII Linefeed */
end_comment

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_comment
comment|/* ASCII Carriage Return */
end_comment

begin_define
define|#
directive|define
name|XON
value|021
end_define

begin_comment
comment|/* ASCII XON */
end_comment

begin_define
define|#
directive|define
name|SP
value|040
end_define

begin_comment
comment|/* ASCII Space */
end_comment

begin_define
define|#
directive|define
name|DEL
value|0177
end_define

begin_comment
comment|/* ASCII Delete (Rubout) */
end_comment

begin_comment
comment|/* Kermit parameters and defaults */
end_comment

begin_define
define|#
directive|define
name|MAXPACK
value|94
end_define

begin_comment
comment|/* Maximum packet size */
end_comment

begin_define
define|#
directive|define
name|RBUFL
value|200
end_define

begin_comment
comment|/* Receive buffer length */
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
comment|/* Timeout interval to be used on me. */
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
comment|/* End-Of-Line character I need on packets. */
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
comment|/* Current input file */
end_comment

begin_define
define|#
directive|define
name|ZOFILE
value|3
end_define

begin_comment
comment|/* Current output file */
end_comment

begin_define
define|#
directive|define
name|ZDFILE
value|4
end_define

begin_comment
comment|/* Current debugging log file */
end_comment

begin_define
define|#
directive|define
name|ZTFILE
value|5
end_define

begin_comment
comment|/* Current transaction log file */
end_comment

begin_define
define|#
directive|define
name|ZPFILE
value|6
end_define

begin_comment
comment|/* Current packet log file */
end_comment

begin_define
define|#
directive|define
name|ZSFILE
value|7
end_define

begin_comment
comment|/* Current session log file */
end_comment

begin_define
define|#
directive|define
name|ZSYSFN
value|8
end_define

begin_comment
comment|/* Input from a system function */
end_comment

begin_define
define|#
directive|define
name|ZNFILS
value|9
end_define

begin_comment
comment|/* How many defined file numbers */
end_comment

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
value|((ch) + SP )
end_define

begin_comment
comment|/* Number to character */
end_comment

begin_define
define|#
directive|define
name|unchar
parameter_list|(
name|ch
parameter_list|)
value|((ch) - SP )
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
value|((ch) ^ 64 )
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
value|((ch)& 127)
end_define

begin_comment
comment|/* Clear parity bit */
end_comment

end_unit

