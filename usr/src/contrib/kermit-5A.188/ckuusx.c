begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U U S X --  "User Interface" common functions. */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/*   This module contains user interface functions needed by both the interactive   user interface and the command-line-only user interface. */
end_comment

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckuusr.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINTCP
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINTCP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WINTCP
end_ifdef

begin_include
include|#
directive|include
file|<descrip.h>
end_include

begin_include
include|#
directive|include
file|<ssdef.h>
end_include

begin_include
include|#
directive|include
file|<stsdef.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<descrip.h>
end_include

begin_include
include|#
directive|include
file|<ssdef.h>
end_include

begin_include
include|#
directive|include
file|<stsdef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINTCP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* Used internally */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID screenc
argument_list|,
argument|(int, char, long, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|int
name|ft_win
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fullscreen file transfer display window is active */
end_comment

begin_comment
comment|/* Variables declared here */
end_comment

begin_decl_stmt
name|int
name|fdispla
init|=
name|XYFD_R
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File transfer display type */
end_comment

begin_decl_stmt
name|int
name|tt_crd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Carriage return display */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|char
name|debfil
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging log file name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TLOG
end_ifdef

begin_decl_stmt
name|char
name|trafil
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transaction log file name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLOG */
end_comment

begin_decl_stmt
name|char
name|pktfil
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Packet log file name */
end_comment

begin_decl_stmt
name|char
name|sesfil
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Session log file name */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOFRILLS
end_ifndef

begin_decl_stmt
name|char
name|optbuf
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Options for MAIL or REMOTE PRINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFRILLS */
end_comment

begin_decl_stmt
name|char
name|cmdstr
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Place to build generic command */
end_comment

begin_decl_stmt
name|char
name|fspec
index|[
name|FSPECL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Filename string for \v(filespec) */
end_comment

begin_comment
comment|/*  C C N T A B  --  Names of ASCII control characters 0-31 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ccntab
index|[]
init|=
block|{
literal|"NUL"
block|,
literal|"SOH"
block|,
literal|"STX"
block|,
literal|"ETX"
block|,
literal|"EOT"
block|,
literal|"ENQ"
block|,
literal|"ACK"
block|,
literal|"BEL"
block|,
literal|"BS"
block|,
literal|"HT"
block|,
literal|"LF"
block|,
literal|"VT"
block|,
literal|"FF"
block|,
literal|"CR"
block|,
literal|"SO"
block|,
literal|"SI"
block|,
literal|"DLE"
block|,
literal|"DC1/XON"
block|,
literal|"DC2"
block|,
literal|"DC3/XOFF"
block|,
literal|"DC4"
block|,
literal|"NAK"
block|,
literal|"SYN"
block|,
literal|"ETB"
block|,
literal|"CAN"
block|,
literal|"EM"
block|,
literal|"SUB"
block|,
literal|"ESC"
block|,
literal|"FS"
block|,
literal|"GS"
block|,
literal|"RS"
block|,
literal|"US"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|success
init|=
literal|1
decl_stmt|,
comment|/* Command success/failure flag */
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
init|=
literal|0
decl_stmt|,
comment|/* Command level */
endif|#
directive|endif
comment|/* NOSPL */
name|action
decl_stmt|,
comment|/* Action selected on command line*/
name|sessft
init|=
literal|0
decl_stmt|,
comment|/* Session log file type, 0 = text */
name|pflag
init|=
literal|1
decl_stmt|,
comment|/* Print prompt */
name|msgflg
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print informational messages */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOMSEND
end_ifndef

begin_comment
comment|/* Multiple SEND */
end_comment

begin_decl_stmt
name|char
modifier|*
name|msfiles
index|[
name|MSENDMAX
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMSEND */
end_comment

begin_comment
comment|/* External variables */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|dialfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dialing directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|local
decl_stmt|,
name|quiet
decl_stmt|,
name|binary
decl_stmt|,
name|bctu
decl_stmt|,
name|rptflg
decl_stmt|,
name|ebqflg
decl_stmt|,
name|network
decl_stmt|,
name|server
decl_stmt|,
name|what
decl_stmt|,
name|spsiz
decl_stmt|,
name|urpsiz
decl_stmt|,
name|wmax
decl_stmt|,
name|czseen
decl_stmt|,
name|cxseen
decl_stmt|,
name|winlo
decl_stmt|,
name|displa
decl_stmt|,
name|timint
decl_stmt|,
name|parity
decl_stmt|,
name|npad
decl_stmt|,
name|ebq
decl_stmt|,
name|ebqflg
decl_stmt|,
name|bctr
decl_stmt|,
name|rptq
decl_stmt|,
name|atcapu
decl_stmt|,
name|lpcapu
decl_stmt|,
name|swcapu
decl_stmt|,
name|wslotn
decl_stmt|,
name|wslotr
decl_stmt|,
name|rtimo
decl_stmt|,
name|mypadn
decl_stmt|,
name|sq
decl_stmt|,
name|capas
decl_stmt|,
name|rpsiz
decl_stmt|,
name|tsecs
decl_stmt|,
name|dfloc
decl_stmt|,
name|tralog
decl_stmt|,
name|pktlog
decl_stmt|,
name|seslog
decl_stmt|,
name|lscapu
decl_stmt|,
name|xitsta
decl_stmt|,
name|escape
decl_stmt|,
name|tlevel
decl_stmt|,
name|bgset
decl_stmt|,
name|backgrd
decl_stmt|,
name|wslots
decl_stmt|,
name|suspend
decl_stmt|,
name|srvdis
decl_stmt|,
name|spackets
decl_stmt|,
name|spktl
decl_stmt|,
name|rpktl
decl_stmt|,
name|retrans
decl_stmt|,
name|wcur
decl_stmt|,
name|numerrs
decl_stmt|,
name|fsecs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_comment
comment|/* 2/12/92 ENH */
end_comment

begin_include
include|#
directive|include
file|<sysid.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|con_reads_mt
decl_stmt|,
name|conint_ch
decl_stmt|,
name|conint_avl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|speed
decl_stmt|,
name|filcnt
decl_stmt|,
name|ffc
decl_stmt|,
name|tfc
decl_stmt|,
name|rptn
decl_stmt|,
name|fsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
modifier|*
name|rdatap
decl_stmt|,
name|padch
decl_stmt|,
name|seol
decl_stmt|,
name|ctlq
decl_stmt|,
name|mypadc
decl_stmt|,
name|eol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ttname
index|[]
decl_stmt|,
modifier|*
name|dftty
decl_stmt|,
modifier|*
name|cmarg
decl_stmt|,
modifier|*
modifier|*
name|cmlist
decl_stmt|,
modifier|*
name|versio
decl_stmt|,
name|myhost
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOICP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffer */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|cmdbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCCTRAP
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* Control-C trap */
end_comment

begin_decl_stmt
name|jmp_buf
name|cmjbuf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCCTRAP */
end_comment

begin_comment
comment|/*  P A R N A M  --  Return parity name */
end_comment

begin_function
name|char
modifier|*
ifdef|#
directive|ifdef
name|CK_ANSIC
name|parnam
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|parnam
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* parnam */
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'e'
case|:
return|return
operator|(
literal|"even"
operator|)
return|;
case|case
literal|'o'
case|:
return|return
operator|(
literal|"odd"
operator|)
return|;
case|case
literal|'m'
case|:
return|return
operator|(
literal|"mark"
operator|)
return|;
case|case
literal|'s'
case|:
return|return
operator|(
literal|"space"
operator|)
return|;
case|case
literal|0
case|:
return|return
operator|(
literal|"none"
operator|)
return|;
default|default:
return|return
operator|(
literal|"invalid"
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  S H O M D M  --  Show modem signals  */
end_comment

begin_function
name|VOID
name|shomdm
parameter_list|()
block|{
comment|/*   Note use of "\r\n" to make sure this report prints right, even when   called during CONNECT mode. */
name|int
name|y
decl_stmt|;
name|y
operator|=
name|ttgmdm
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|y
condition|)
block|{
case|case
operator|-
literal|3
case|:
name|printf
argument_list|(
literal|"Modem signals unavailable in this version of Kermit\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
operator|-
literal|2
case|:
name|printf
argument_list|(
literal|"No modem control for this device\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
operator|-
literal|1
case|:
name|printf
argument_list|(
literal|"Modem signals unavailable\r\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
ifndef|#
directive|ifndef
name|MAC
name|printf
argument_list|(
literal|" Carrier Detect      (CD):  %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_DCD
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Dataset Ready       (DSR): %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_DSR
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
name|printf
argument_list|(
literal|" Clear To Send       (CTS): %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_CTS
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MAC
name|printf
argument_list|(
literal|" Ring Indicator      (RI):  %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_RNG
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
name|printf
argument_list|(
literal|" Data Terminal Ready (DTR): %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_DTR
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MAC
name|printf
argument_list|(
literal|" Request to Send     (RTS): %s\r\n"
argument_list|,
operator|(
name|y
operator|&
name|BM_RTS
operator|)
condition|?
literal|"On"
else|:
literal|"Off"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
block|}
block|}
end_function

begin_comment
comment|/*  S D E B U  -- Record spar results in debugging log  */
end_comment

begin_function
name|VOID
name|sdebu
parameter_list|(
name|len
parameter_list|)
name|int
name|len
decl_stmt|;
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"spar: data"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|rdatap
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" spsiz "
argument_list|,
literal|""
argument_list|,
name|spsiz
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" timint"
argument_list|,
literal|""
argument_list|,
name|timint
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" npad  "
argument_list|,
literal|""
argument_list|,
name|npad
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" padch "
argument_list|,
literal|""
argument_list|,
name|padch
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" seol  "
argument_list|,
literal|""
argument_list|,
name|seol
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ctlq  "
argument_list|,
literal|""
argument_list|,
name|ctlq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebq   "
argument_list|,
literal|""
argument_list|,
name|ebq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebqflg"
argument_list|,
literal|""
argument_list|,
name|ebqflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" bctr  "
argument_list|,
literal|""
argument_list|,
name|bctr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptq  "
argument_list|,
literal|""
argument_list|,
name|rptq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptflg"
argument_list|,
literal|""
argument_list|,
name|rptflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lscapu"
argument_list|,
literal|""
argument_list|,
name|lscapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" atcapu"
argument_list|,
literal|""
argument_list|,
name|atcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lpcapu"
argument_list|,
literal|""
argument_list|,
name|lpcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" swcapu"
argument_list|,
literal|""
argument_list|,
name|swcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" wslotn"
argument_list|,
literal|""
argument_list|,
name|wslotn
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  R D E B U -- Debugging display of rpar() values  */
end_comment

begin_function
name|VOID
name|rdebu
parameter_list|(
name|d
parameter_list|,
name|len
parameter_list|)
name|CHAR
modifier|*
name|d
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"rpar: data"
argument_list|,
name|d
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rpsiz "
argument_list|,
literal|""
argument_list|,
name|xunchar
argument_list|(
name|d
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rtimo "
argument_list|,
literal|""
argument_list|,
name|rtimo
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" mypadn"
argument_list|,
literal|""
argument_list|,
name|mypadn
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" mypadc"
argument_list|,
literal|""
argument_list|,
name|mypadc
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" eol   "
argument_list|,
literal|""
argument_list|,
name|eol
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ctlq  "
argument_list|,
literal|""
argument_list|,
name|ctlq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" sq    "
argument_list|,
literal|""
argument_list|,
name|sq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebq   "
argument_list|,
literal|""
argument_list|,
name|ebq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebqflg"
argument_list|,
literal|""
argument_list|,
name|ebqflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" bctr  "
argument_list|,
literal|""
argument_list|,
name|bctr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptq  "
argument_list|,
literal|""
argument_list|,
name|d
index|[
literal|8
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptflg"
argument_list|,
literal|""
argument_list|,
name|rptflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" capas "
argument_list|,
literal|""
argument_list|,
name|capas
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" bits  "
argument_list|,
literal|""
argument_list|,
name|d
index|[
name|capas
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lscapu"
argument_list|,
literal|""
argument_list|,
name|lscapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" atcapu"
argument_list|,
literal|""
argument_list|,
name|atcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" lpcapu"
argument_list|,
literal|""
argument_list|,
name|lpcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" swcapu"
argument_list|,
literal|""
argument_list|,
name|swcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" wslotr"
argument_list|,
literal|""
argument_list|,
name|wslotr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rpsiz(extended)"
argument_list|,
literal|""
argument_list|,
name|rpsiz
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*  C H K E R R  --  Decide whether to exit upon a protocol error  */
end_comment

begin_function
name|VOID
name|chkerr
parameter_list|()
block|{
if|if
condition|(
name|backgrd
operator|&&
operator|!
name|server
condition|)
name|fatal
argument_list|(
literal|"Protocol error"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/*  F A T A L  --  Fatal error message */
end_comment

begin_function
name|VOID
name|fatal
parameter_list|(
name|msg
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|VMS
ifndef|#
directive|ifndef
name|NOICP
if|if
condition|(
name|strncmp
argument_list|(
name|msg
argument_list|,
literal|"%CKERMIT"
argument_list|,
literal|8
argument_list|)
condition|)
block|{
name|sprintf
argument_list|(
name|cmdbuf
argument_list|,
literal|"%%CKERMIT-E-FATAL, %s"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|msg
operator|=
name|cmdbuf
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* NOICP */
name|conoll
argument_list|(
name|msg
argument_list|)
expr_stmt|;
else|#
directive|else
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
name|msg
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"fatal"
argument_list|,
name|msg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Fatal:"
argument_list|,
name|msg
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
name|xitsta
operator||
literal|1
argument_list|)
expr_stmt|;
comment|/* Exit indicating failure */
block|}
end_function

begin_comment
comment|/*  B L D L E N  --  Make length-encoded copy of string  */
end_comment

begin_function
name|char
modifier|*
name|bldlen
parameter_list|(
name|str
parameter_list|,
name|dest
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|,
decl|*
name|dest
decl_stmt|;
end_function

begin_block
block|{
name|int
name|len
decl_stmt|;
name|len
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|str
argument_list|)
expr_stmt|;
operator|*
name|dest
operator|=
name|tochar
argument_list|(
name|len
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|dest
operator|+
literal|1
argument_list|,
name|str
argument_list|)
expr_stmt|;
return|return
operator|(
name|dest
operator|+
name|len
operator|+
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  S E T G E N  --  Construct a generic command  */
end_comment

begin_function
name|CHAR
ifdef|#
directive|ifdef
name|CK_ANSIC
name|setgen
parameter_list|(
name|char
name|type
parameter_list|,
name|char
modifier|*
name|arg1
parameter_list|,
name|char
modifier|*
name|arg2
parameter_list|,
name|char
modifier|*
name|arg3
parameter_list|)
else|#
directive|else
function|setgen
parameter_list|(
name|type
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
name|char
name|type
decl_stmt|,
decl|*
name|arg1
decl_stmt|,
modifier|*
name|arg2
decl_stmt|,
modifier|*
name|arg3
decl_stmt|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_comment
comment|/* setgen */
end_comment

begin_block
block|{
name|char
modifier|*
name|upstr
decl_stmt|,
modifier|*
name|cp
decl_stmt|;
name|cp
operator|=
name|cmdstr
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
name|type
expr_stmt|;
operator|*
name|cp
operator|=
name|NUL
expr_stmt|;
if|if
condition|(
operator|*
name|arg1
operator|!=
name|NUL
condition|)
block|{
name|upstr
operator|=
name|bldlen
argument_list|(
name|arg1
argument_list|,
name|cp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|arg2
operator|!=
name|NUL
condition|)
block|{
name|upstr
operator|=
name|bldlen
argument_list|(
name|arg2
argument_list|,
name|upstr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|arg3
operator|!=
name|NUL
condition|)
name|bldlen
argument_list|(
name|arg3
argument_list|,
name|upstr
argument_list|)
expr_stmt|;
block|}
block|}
name|cmarg
operator|=
name|cmdstr
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"setgen"
argument_list|,
name|cmarg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|'g'
operator|)
return|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|NOMSEND
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mgbufp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  F N P A R S E  --  */
end_comment

begin_comment
comment|/*   Argument is a character string containing one or more filespecs.   This function breaks the string apart into an array of pointers, one   to each filespec, and returns the number of filespecs.  Used by server   when it receives a GET command to allow it to process multiple file   specifications in one transaction.  Sets cmlist to point to a list of   file pointers, exactly as if they were command line arguments.    This version of fnparse treats spaces as filename separators.  If your   operating system allows spaces in filenames, you'll need a different   separator.    This version of fnparse mallocs a string buffer to contain the names.  It   cannot assume that the string that is pointed to by the argument is safe. */
end_comment

begin_function
name|int
name|fnparse
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|s
decl_stmt|,
modifier|*
name|q
decl_stmt|;
name|int
name|r
init|=
literal|0
decl_stmt|,
name|x
decl_stmt|;
comment|/* Return code */
if|if
condition|(
name|mgbufp
condition|)
name|free
argument_list|(
name|mgbufp
argument_list|)
expr_stmt|;
comment|/* Free this from last time. */
name|mgbufp
operator|=
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|string
argument_list|)
operator|+
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mgbufp
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"fnparse malloc error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifndef|#
directive|ifndef
name|NOICP
ifndef|#
directive|ifndef
name|NOSPL
name|strncpy
argument_list|(
name|fspec
argument_list|,
name|string
argument_list|,
name|FSPECL
argument_list|)
expr_stmt|;
comment|/* Make copy for \v(filespec) */
endif|#
directive|endif
comment|/* NOSPL */
endif|#
directive|endif
comment|/* NOICP */
name|s
operator|=
name|string
expr_stmt|;
comment|/* Input string */
name|p
operator|=
name|q
operator|=
name|mgbufp
expr_stmt|;
comment|/* Point to the copy */
name|r
operator|=
literal|0
expr_stmt|;
comment|/* Initialize our return code */
while|while
condition|(
operator|*
name|s
operator|==
name|SP
operator|||
operator|*
name|s
operator|==
name|HT
condition|)
comment|/* Skip leading spaces and tabs */
name|s
operator|++
expr_stmt|;
for|for
control|(
name|x
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
init|;
comment|/* Strip trailing spaces */
operator|(
name|x
operator|>
literal|1
operator|)
operator|&&
operator|(
name|s
index|[
name|x
operator|-
literal|1
index|]
operator|==
name|SP
operator|||
name|s
index|[
name|x
operator|-
literal|1
index|]
operator|==
name|HT
operator|)
condition|;
name|x
operator|--
control|)
name|s
index|[
name|x
operator|-
literal|1
index|]
operator|=
name|NUL
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Loop through rest of string */
if|if
condition|(
operator|*
name|s
operator|==
name|CMDQ
condition|)
block|{
comment|/* Backslash (quote character)? */
if|if
condition|(
operator|(
name|x
operator|=
name|xxesc
argument_list|(
operator|&
name|s
argument_list|)
operator|)
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Go interpret it. */
operator|*
name|q
operator|++
operator|=
operator|(
name|char
operator|)
name|x
expr_stmt|;
comment|/* Numeric backslash code, ok */
block|}
else|else
block|{
comment|/* Just let it quote next char */
name|s
operator|++
expr_stmt|;
comment|/* get past the backslash */
operator|*
name|q
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
comment|/* deposit next char */
block|}
continue|continue;
block|}
elseif|else
if|if
condition|(
operator|*
name|s
operator|==
name|SP
operator|||
operator|*
name|s
operator|==
name|NUL
condition|)
block|{
comment|/* Unquoted space or NUL? */
operator|*
name|q
operator|++
operator|=
name|NUL
expr_stmt|;
comment|/* End of output filename. */
name|msfiles
index|[
name|r
index|]
operator|=
name|p
expr_stmt|;
comment|/* Add this filename to the list */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"fnparse"
argument_list|,
name|msfiles
index|[
name|r
index|]
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|r
operator|++
expr_stmt|;
comment|/* Count it */
if|if
condition|(
operator|*
name|s
operator|==
name|NUL
condition|)
break|break;
comment|/* End of string? */
while|while
condition|(
operator|*
name|s
operator|==
name|SP
condition|)
name|s
operator|++
expr_stmt|;
comment|/* Skip repeated spaces */
name|p
operator|=
name|q
expr_stmt|;
comment|/* Start of next name */
continue|continue;
block|}
else|else
operator|*
name|q
operator|++
operator|=
operator|*
name|s
expr_stmt|;
comment|/* Otherwise copy the character */
name|s
operator|++
expr_stmt|;
comment|/* Next input character */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"fnparse r"
argument_list|,
literal|""
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|msfiles
index|[
name|r
index|]
operator|=
literal|""
expr_stmt|;
comment|/* Put empty string at end of list */
name|cmlist
operator|=
name|msfiles
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMSEND */
end_comment

begin_function
name|char
modifier|*
comment|/* dbchr() for DEBUG SESSION */
name|dbchr
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|static
name|char
name|s
index|[
literal|8
index|]
decl_stmt|;
name|char
modifier|*
name|cp
init|=
name|s
decl_stmt|;
name|c
operator|&=
literal|0xff
expr_stmt|;
if|if
condition|(
name|c
operator|&
literal|0x80
condition|)
block|{
comment|/* 8th bit on */
operator|*
name|cp
operator|++
operator|=
literal|'~'
expr_stmt|;
name|c
operator|&=
literal|0x7f
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|<
name|SP
condition|)
block|{
comment|/* Control character */
operator|*
name|cp
operator|++
operator|=
literal|'^'
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
name|ctl
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|DEL
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
literal|'^'
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
literal|'?'
expr_stmt|;
block|}
else|else
block|{
comment|/* Printing character */
operator|*
name|cp
operator|++
operator|=
name|c
expr_stmt|;
block|}
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate string */
name|cp
operator|=
name|s
expr_stmt|;
comment|/* Return pointer to it */
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  C K H O S T  --  Get name of local host (where C-Kermit is running)  */
end_comment

begin_comment
comment|/*   Call with pointer to buffer to put hostname in, and length of buffer.   Copies hostname into buffer on success, puts null string in buffer on   failure. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_undef
undef|#
directive|undef
name|ATTSV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_function
name|VOID
name|ckhost
parameter_list|(
name|vvbuf
parameter_list|,
name|vvlen
parameter_list|)
name|char
modifier|*
name|vvbuf
decl_stmt|;
name|int
name|vvlen
decl_stmt|;
block|{
name|char
modifier|*
name|g
decl_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|int
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* VMS */
ifdef|#
directive|ifdef
name|ATTSV
name|struct
name|utsname
name|hname
decl_stmt|;
endif|#
directive|endif
comment|/* ATTSV */
ifdef|#
directive|ifdef
name|datageneral
name|int
name|ac0
init|=
operator|(
name|char
operator|*
operator|)
name|vvbuf
decl_stmt|,
name|ac1
init|=
operator|-
literal|1
decl_stmt|,
name|ac2
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
comment|/* datageneral */
operator|*
name|vvbuf
operator|=
name|NUL
expr_stmt|;
ifdef|#
directive|ifdef
name|ATTSV
if|if
condition|(
name|uname
argument_list|(
operator|&
name|hname
argument_list|)
operator|>
operator|-
literal|1
condition|)
name|strncpy
argument_list|(
name|vvbuf
argument_list|,
name|hname
operator|.
name|nodename
argument_list|,
name|vvlen
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|BSD4
if|if
condition|(
name|gethostname
argument_list|(
name|vvbuf
argument_list|,
name|vvlen
argument_list|)
operator|<
literal|0
condition|)
operator|*
name|vvbuf
operator|=
name|NUL
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMS
name|g
operator|=
name|getenv
argument_list|(
literal|"SYS$NODE"
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
condition|)
name|strncpy
argument_list|(
name|vvbuf
argument_list|,
name|g
argument_list|,
name|vvlen
argument_list|)
expr_stmt|;
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|vvbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|1
operator|&&
name|vvbuf
index|[
name|x
operator|-
literal|1
index|]
operator|==
literal|':'
operator|&&
name|vvbuf
index|[
name|x
operator|-
literal|2
index|]
operator|==
literal|':'
condition|)
name|vvbuf
index|[
name|x
operator|-
literal|2
index|]
operator|=
name|NUL
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|datageneral
if|if
condition|(
name|sys
argument_list|(
name|$HNAME
argument_list|,
operator|&
name|ac0
argument_list|,
operator|&
name|ac1
argument_list|,
operator|&
name|ac2
argument_list|)
operator|==
literal|0
condition|)
comment|/* successful */
name|vvlen
operator|=
name|ac2
operator|+
literal|1
expr_stmt|;
comment|/* enh - have to add one */
else|#
directive|else
ifdef|#
directive|ifdef
name|OS2
comment|/* OS/2 */
name|g
operator|=
name|getenv
argument_list|(
literal|"SYSTEMNAME"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|g
condition|)
name|g
operator|=
name|getenv
argument_list|(
literal|"HOSTNAME"
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
condition|)
name|strncpy
argument_list|(
name|vvbuf
argument_list|,
name|g
argument_list|,
name|vvlen
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
endif|#
directive|endif
comment|/* datageneral */
endif|#
directive|endif
comment|/* VMS */
endif|#
directive|endif
comment|/* BSD4 */
endif|#
directive|endif
comment|/* ATTSV */
if|if
condition|(
operator|*
name|vvbuf
operator|==
name|NUL
condition|)
block|{
comment|/* If it's still empty */
name|g
operator|=
name|getenv
argument_list|(
literal|"HOST"
argument_list|)
expr_stmt|;
comment|/* try this */
if|if
condition|(
name|g
condition|)
name|strncpy
argument_list|(
name|vvbuf
argument_list|,
name|g
argument_list|,
name|vvlen
argument_list|)
expr_stmt|;
block|}
name|vvbuf
index|[
name|vvlen
operator|-
literal|1
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* Make sure result is terminated. */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_undef
undef|#
directive|undef
name|BSD4
end_undef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_define
define|#
directive|define
name|ASKMORE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOHELP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ASKMORE
end_ifndef

begin_define
define|#
directive|define
name|ASKMORE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASKMORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOHELP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASKMORE
end_ifdef

begin_comment
comment|/*   A S K M O R E  --  Poor person's "more".   Returns 0 if no more, 1 if more wanted.   Presently used by SHO MAC, SHO GLOB, SHO VAR, and HELP, so compiled out if   those options are also compiled out. */
end_comment

begin_function
name|int
name|askmore
parameter_list|()
block|{
name|char
name|c
decl_stmt|;
name|int
name|rv
decl_stmt|;
name|rv
operator|=
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|rv
operator|<
literal|0
condition|)
block|{
ifndef|#
directive|ifndef
name|OS2
name|printf
argument_list|(
literal|"more? "
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|NOSETBUF
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOSETBUF */
endif|#
directive|endif
comment|/* UNIX */
else|#
directive|else
name|printf
argument_list|(
literal|"more? (Y or space-bar for yes, N for no) "
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|c
operator|=
name|coninc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
comment|/* Yes */
case|case
name|SP
case|:
case|case
literal|'y'
case|:
case|case
literal|'Y'
case|:
case|case
literal|012
case|:
case|case
literal|015
case|:
name|printf
argument_list|(
literal|"\015      \015"
argument_list|)
expr_stmt|;
name|rv
operator|=
literal|1
expr_stmt|;
break|break;
comment|/* No */
case|case
literal|'n'
case|:
case|case
literal|'N'
case|:
case|case
literal|'q'
case|:
case|case
literal|'Q'
case|:
name|printf
argument_list|(
literal|"\015\012"
argument_list|)
expr_stmt|;
name|rv
operator|=
literal|0
expr_stmt|;
break|break;
comment|/* Invalid answer */
default|default:
name|printf
argument_list|(
literal|"Y or space-bar for yes, N for no\n"
argument_list|)
expr_stmt|;
continue|continue;
block|}
ifdef|#
directive|ifdef
name|OS2
name|printf
argument_list|(
literal|"\r                                         \r"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
block|}
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASKMORE */
end_comment

begin_comment
comment|/*  T R A P  --  Terminal interrupt handler */
end_comment

begin_function
name|SIGTYP
name|trap
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|VMS
name|int
name|i
decl_stmt|;
name|FILE
modifier|*
name|f
decl_stmt|;
endif|#
directive|endif
comment|/* VMS */
ifdef|#
directive|ifdef
name|__EMX__
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_ACK
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GEMDOS
comment|/* GEM is not reentrant, no i/o from interrupt level */
name|longjmp
argument_list|(
name|cmjbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Jump back to parser now! */
endif|#
directive|endif
comment|/* GEMDOS */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"^C trap() caught signal"
argument_list|,
literal|""
argument_list|,
name|sig
argument_list|)
expr_stmt|;
name|zclose
argument_list|(
name|ZIFILE
argument_list|)
expr_stmt|;
comment|/* If we were transferring a file, */
name|zclose
argument_list|(
name|ZOFILE
argument_list|)
expr_stmt|;
comment|/* close it. */
ifdef|#
directive|ifdef
name|VMS
comment|/*   Fix terminal. */
if|if
condition|(
name|ft_win
condition|)
block|{
comment|/* If curses window open */
name|screen
argument_list|(
name|SCR_CW
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* Close it */
name|conres
argument_list|()
expr_stmt|;
comment|/* Restore terminal */
name|i
operator|=
name|printf
argument_list|(
literal|"^C..."
argument_list|)
expr_stmt|;
comment|/* Echo ^C to standard output */
block|}
else|else
block|{
name|conres
argument_list|()
expr_stmt|;
name|i
operator|=
name|printf
argument_list|(
literal|"^C...\n"
argument_list|)
expr_stmt|;
comment|/* Echo ^C to standard output */
block|}
if|if
condition|(
name|i
operator|<
literal|1
operator|&&
name|ferror
argument_list|(
name|stdout
argument_list|)
condition|)
block|{
comment|/* If there was an error */
name|fclose
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* close standard output */
name|f
operator|=
name|fopen
argument_list|(
name|dftty
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* open the controlling terminal */
if|if
condition|(
name|f
condition|)
name|stdout
operator|=
name|f
expr_stmt|;
comment|/* and make it standard output */
name|printf
argument_list|(
literal|"^C...\n"
argument_list|)
expr_stmt|;
comment|/* and echo the ^C again. */
block|}
else|#
directive|else
comment|/* Not VMS */
if|if
condition|(
name|ft_win
condition|)
block|{
comment|/* If curses window open, */
name|screen
argument_list|(
name|SCR_CW
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* close it. */
name|printf
argument_list|(
literal|"^C..."
argument_list|)
expr_stmt|;
comment|/* Echo ^C to standard output */
block|}
else|else
block|{
name|printf
argument_list|(
literal|"^C...\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* VMS */
ifdef|#
directive|ifdef
name|datageneral
name|connoi_mt
argument_list|()
expr_stmt|;
comment|/* Kill asynch task that listens to */
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* the keyboard */
name|conres
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* datageneral */
ifndef|#
directive|ifndef
name|NOCCTRAP
ifdef|#
directive|ifdef
name|UNIX
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off any timer interrupts */
endif|#
directive|endif
comment|/* UNIX */
ifdef|#
directive|ifdef
name|OSK
name|ttimoff
argument_list|()
expr_stmt|;
comment|/* Turn off any timer interrupts */
name|sigmask
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/*   We are in an intercept routine but do not perform a F$RTE (done implicitly   but rts).  We have to decrement the sigmask as F$RTE does.  Warning:   longjump only restores the cpu registers, NOT the fpu registers.  So don't   use fpu at all or at least don't use common fpu (double or float) register   variables. */
endif|#
directive|endif
comment|/* OSK */
name|longjmp
argument_list|(
name|cmjbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Jump back to parser */
else|#
directive|else
comment|/* No Ctrl-C trap, just exit. */
ifdef|#
directive|ifdef
name|CK_CURSES
comment|/* Curses support? */
name|screen
argument_list|(
name|SCR_CW
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* Close curses window */
endif|#
directive|endif
comment|/* CK_CURSES */
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
name|what
argument_list|)
expr_stmt|;
comment|/* Exit poorly */
endif|#
directive|endif
comment|/* NOCCTRAP */
name|SIGRETURN
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  C C _ C L E A N  --  Cleanup after terminal interrupt handler */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_function
name|int
name|cc_clean
parameter_list|()
block|{
name|zclose
argument_list|(
name|ZIFILE
argument_list|)
expr_stmt|;
comment|/* If we were transferring a file, */
name|zclose
argument_list|(
name|ZOFILE
argument_list|)
expr_stmt|;
comment|/* close it. */
name|printf
argument_list|(
literal|"^C...\n"
argument_list|)
expr_stmt|;
comment|/* Not VMS, no problem... */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_comment
comment|/*  S T P T R A P -- Handle SIGTSTP (suspend) signals */
end_comment

begin_function
name|SIGTYP
name|stptrap
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|NOJC
name|int
name|x
decl_stmt|;
specifier|extern
name|int
name|cmflgs
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"stptrap() caught signal"
argument_list|,
literal|""
argument_list|,
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|suspend
condition|)
block|{
name|printf
argument_list|(
literal|"\r\nsuspend disabled\r\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOICP
if|if
condition|(
name|what
operator|==
name|W_COMMAND
condition|)
block|{
comment|/* If we were parsing commands */
name|prompt
argument_list|(
name|xxstring
argument_list|)
expr_stmt|;
comment|/* reissue the prompt and partial */
if|if
condition|(
operator|!
name|cmflgs
condition|)
comment|/* command (if any) */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* NOICP */
block|}
else|else
block|{
name|conres
argument_list|()
expr_stmt|;
comment|/* Reset the console */
ifndef|#
directive|ifndef
name|OS2
comment|/* Flush pending output first, in case we are continued */
comment|/* in the background, which could make us block */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|x
operator|=
name|psuspend
argument_list|(
name|suspend
argument_list|)
expr_stmt|;
comment|/* Try to suspend. */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
endif|#
directive|endif
comment|/* OS2 */
name|printf
argument_list|(
literal|"Job control not supported\r\n"
argument_list|)
expr_stmt|;
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* Rearm the trap. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"stptrap back from suspend"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|W_CONNECT
case|:
comment|/* If suspended during CONNECT? */
name|conbin
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* put console back in binary mode */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"stptrap W_CONNECT"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|NOICP
case|case
name|W_COMMAND
case|:
comment|/* Suspended in command mode */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"stptrap W_COMMAND pflag"
argument_list|,
literal|""
argument_list|,
name|pflag
argument_list|)
expr_stmt|;
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Put back CBREAK tty mode */
if|if
condition|(
name|pflag
condition|)
block|{
comment|/* If command parsing was */
name|prompt
argument_list|(
name|xxstring
argument_list|)
expr_stmt|;
comment|/* reissue the prompt and partial */
if|if
condition|(
operator|!
name|cmflgs
condition|)
comment|/* command (if any) */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
block|}
break|break;
endif|#
directive|endif
comment|/* NOICP */
default|default:
comment|/* All other cases... */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"stptrap default"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Put it back in CBREAK mode */
break|break;
block|}
block|}
endif|#
directive|endif
comment|/* NOJC */
name|SIGRETURN
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_comment
comment|/*   The rest of this file is for all implementations but the Macintosh. */
end_comment

begin_comment
comment|/*  C H K I N T  --  Check for console interrupts  */
end_comment

begin_function
name|int
name|chkint
parameter_list|()
block|{
name|int
name|ch
decl_stmt|,
name|cn
decl_stmt|;
name|long
name|zz
decl_stmt|;
if|if
condition|(
operator|(
operator|!
name|local
operator|)
operator|||
operator|(
name|quiet
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Only do this if local& not quiet */
ifdef|#
directive|ifdef
name|datageneral
if|if
condition|(
name|con_reads_mt
condition|)
comment|/* if conint_mt task is active */
if|if
condition|(
name|conint_avl
condition|)
block|{
comment|/* and there's an interrupt pending */
name|cn
operator|=
literal|1
expr_stmt|;
comment|/* process it */
name|ch
operator|=
name|conint_ch
expr_stmt|;
name|conint_avl
operator|=
literal|0
expr_stmt|;
comment|/* turn off flag so conint_mt can */
block|}
else|else
comment|/* proceed */
return|return
operator|(
literal|0
operator|)
return|;
elseif|else
comment|/* if conint_mt not active */
if|if
condition|(
operator|(
name|ch
operator|=
name|coninc
argument_list|(
literal|2
argument_list|)
operator|)
operator|<
literal|0
condition|)
comment|/* try to get char manually */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* I/O error, or no data */
else|else
comment|/* if successful, set cn so we */
name|cn
operator|=
literal|1
expr_stmt|;
comment|/* know we got one */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"chkint got keyboard character"
argument_list|,
name|ch
argument_list|,
name|cn
argument_list|)
expr_stmt|;
else|#
directive|else
name|cn
operator|=
name|conchk
argument_list|()
expr_stmt|;
comment|/* Any input waiting? */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"conchk"
argument_list|,
literal|""
argument_list|,
name|cn
argument_list|)
expr_stmt|;
if|if
condition|(
name|cn
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
name|ch
operator|=
name|coninc
argument_list|(
literal|5
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* datageneral */
switch|switch
condition|(
name|ch
operator|&
literal|0177
condition|)
block|{
case|case
literal|'A'
case|:
case|case
literal|'a'
case|:
case|case
literal|0001
case|:
comment|/* Status report */
if|if
condition|(
name|fdispla
operator|!=
name|XYFD_R
operator|&&
name|fdispla
operator|!=
name|XYFD_S
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Only for serial or simple */
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Status report:"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|" file type: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|binary
condition|)
block|{
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
name|binary
operator|==
name|XYFT_I
condition|)
comment|/* VMS-only file types */
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"image"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|binary
operator|==
name|XYFT_L
condition|)
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"labeled"
argument_list|)
expr_stmt|;
else|else
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"binary"
argument_list|)
expr_stmt|;
else|#
directive|else
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"binary"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
block|}
else|else
block|{
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"text"
argument_list|)
expr_stmt|;
block|}
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
name|filcnt
argument_list|,
literal|" file number"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fsize
condition|)
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
name|fsize
argument_list|,
literal|" size"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
name|ffc
argument_list|,
literal|" characters so far"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fsize
operator|>
literal|0L
condition|)
block|{
name|zz
operator|=
operator|(
name|ffc
operator|*
literal|100L
operator|)
operator|/
name|fsize
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
name|zz
argument_list|,
literal|" percent done"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bctu
operator|==
literal|4
condition|)
block|{
comment|/* Block check */
name|screen
argument_list|(
name|SCR_TU
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
literal|" block check: "
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_TZ
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
literal|"blank-free-2"
argument_list|)
expr_stmt|;
block|}
else|else
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|bctu
argument_list|,
literal|" block check"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|rptflg
argument_list|,
literal|" compression"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|ebqflg
argument_list|,
literal|" 8th-bit prefixing"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|lscapu
argument_list|,
literal|" locking shifts"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|network
condition|)
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
name|speed
argument_list|,
literal|" speed"
argument_list|)
expr_stmt|;
if|if
condition|(
name|what
operator|==
name|W_SEND
condition|)
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|spsiz
argument_list|,
literal|" packet length"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|what
operator|==
name|W_RECV
operator|||
name|what
operator|==
name|W_REMO
condition|)
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|urpsiz
argument_list|,
literal|" packet length"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_QE
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|wslots
argument_list|,
literal|" window slots"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'B'
case|:
case|case
literal|'b'
case|:
case|case
literal|0002
case|:
comment|/* Cancel batch */
case|case
literal|'Z'
case|:
case|case
literal|'z'
case|:
case|case
literal|0032
case|:
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Cancelling Batch "
argument_list|)
expr_stmt|;
name|czseen
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'F'
case|:
case|case
literal|'f'
case|:
case|case
literal|0006
case|:
comment|/* Cancel file */
case|case
literal|'X'
case|:
case|case
literal|'x'
case|:
case|case
literal|0030
case|:
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Cancelling File "
argument_list|)
expr_stmt|;
name|cxseen
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'R'
case|:
case|case
literal|'r'
case|:
case|case
literal|0022
case|:
comment|/* Resend */
case|case
literal|0015
case|:
case|case
literal|0012
case|:
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Resending packet "
argument_list|)
expr_stmt|;
name|numerrs
operator|++
expr_stmt|;
name|resend
argument_list|(
name|winlo
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|'E'
case|:
case|case
literal|'e'
case|:
comment|/* Send error packet */
case|case
literal|0005
case|:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
ifdef|#
directive|ifdef
name|datageneral
case|case
literal|'\03'
case|:
comment|/* We're not trapping ^C's with */
name|trap
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* signals, so we check here    */
endif|#
directive|endif
comment|/* datageneral */
default|default:
comment|/* Anything else, print message */
name|intmsg
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  I N T M S G  --  Issue message about terminal interrupts  */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|intmsg
parameter_list|(
name|long
name|n
parameter_list|)
else|#
directive|else
function|intmsg
parameter_list|(
name|n
parameter_list|)
name|long
name|n
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* intmsg */
block|{
name|char
name|buf
index|[
literal|80
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|displa
operator|||
name|quiet
condition|)
comment|/* Not if we're being quiet */
return|return;
if|if
condition|(
name|server
operator|&&
operator|(
operator|!
name|srvdis
operator|||
name|n
operator|>
operator|-
literal|1L
operator|)
condition|)
comment|/* Special for server */
return|return;
name|buf
index|[
literal|0
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* Keep compilers happy */
ifdef|#
directive|ifdef
name|SVORPOSIX
name|conchk
argument_list|()
expr_stmt|;
comment|/* Clear out pending escape-signals */
endif|#
directive|endif
comment|/* SVORPOSIX */
ifdef|#
directive|ifdef
name|VMS
name|conres
argument_list|()
expr_stmt|;
comment|/* So Ctrl-C will work */
endif|#
directive|endif
comment|/* VMS */
if|if
condition|(
operator|(
operator|!
name|server
operator|&&
name|n
operator|==
literal|1L
operator|)
operator|||
operator|(
name|server
operator|&&
name|n
operator|<
literal|0L
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|SVORPOSIX
comment|/* We need to signal before kb input */
ifndef|#
directive|ifndef
name|aegis
ifndef|#
directive|ifndef
name|datageneral
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Type escape character (%s) followed by:"
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
name|buf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* datageneral */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* SVORPOSIX */
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"X to cancel file,  CR to resend current packet"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Z to cancel group, A for status report"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"E to send Error packet, Ctrl-C to quit immediately: "
argument_list|)
expr_stmt|;
comment|/* if (server) */
name|screen
argument_list|(
name|SCR_TN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
else|else
name|screen
argument_list|(
name|SCR_TU
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|newdpy
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New display flag */
end_comment

begin_decl_stmt
specifier|static
name|char
name|fbuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Filename buffer */
end_comment

begin_decl_stmt
specifier|static
name|char
name|abuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* As-name buffer */
end_comment

begin_decl_stmt
specifier|static
name|long
name|oldffc
init|=
literal|0L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|dots
init|=
literal|0L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|hpos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|VOID
comment|/* Initialize Serial or CTR display */
name|dpyinit
parameter_list|()
block|{
name|newdpy
operator|=
literal|0
expr_stmt|;
comment|/*  Don't do this again */
name|oldffc
operator|=
literal|0L
expr_stmt|;
comment|/*  Reset this */
name|dots
operator|=
literal|0L
expr_stmt|;
comment|/*  and this.. */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* New line */
if|if
condition|(
name|what
operator|==
name|W_SEND
condition|)
name|conol
argument_list|(
literal|"Sending: "
argument_list|)
expr_stmt|;
comment|/* Action */
elseif|else
if|if
condition|(
name|what
operator|==
name|W_RECV
condition|)
name|conol
argument_list|(
literal|"Receiving: "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|fbuf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|abuf
condition|)
name|conol
argument_list|(
literal|" => "
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|abuf
argument_list|)
expr_stmt|;
comment|/* Names */
operator|*
name|fbuf
operator|=
name|NUL
expr_stmt|;
operator|*
name|abuf
operator|=
name|NUL
expr_stmt|;
if|if
condition|(
name|fsize
operator|>
operator|-
literal|1L
condition|)
block|{
comment|/* Size */
name|sprintf
argument_list|(
name|fbuf
argument_list|,
literal|"Size: %ld, Type: "
argument_list|,
name|fsize
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|fbuf
argument_list|)
expr_stmt|;
operator|*
name|fbuf
operator|=
name|NUL
expr_stmt|;
block|}
else|else
name|conol
argument_list|(
literal|"Size: unknown, Type: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|binary
condition|)
block|{
comment|/* Type */
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
name|binary
operator|==
name|XYFT_I
condition|)
comment|/* VMS-only file types */
name|conoll
argument_list|(
literal|"image"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|binary
operator|==
name|XYFT_L
condition|)
name|conoll
argument_list|(
literal|"labeled"
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* VMS */
name|conoll
argument_list|(
literal|"binary"
argument_list|)
expr_stmt|;
block|}
else|else
name|conoll
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fdispla
operator|==
name|XYFD_S
condition|)
block|{
comment|/* CRT field headings */
comment|/*   Define CK_CPS to show current transfer rate.   Leave it undefined to show estimated time remaining.   Estimated-time-remaining code from Andy Fyfe, not tested on   pathological cases. */
define|#
directive|define
name|CK_CPS
ifdef|#
directive|ifdef
name|CK_CPS
name|conoll
argument_list|(
literal|"    File   Percent       Packet"
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|"    Bytes  Done     CPS  Length"
argument_list|)
expr_stmt|;
else|#
directive|else
name|conoll
argument_list|(
literal|"    File   Percent  Secs Packet"
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|"    Bytes  Done     Left Length"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_CPS */
name|newdpy
operator|=
literal|0
expr_stmt|;
block|}
name|hpos
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   showpkt(c)   c = completion code: 0 means transfer in progress, nonzero means it's done.   show the file transfer progress counter and perhaps verbose packet type.   Original by: Kai Uwe Rommel. */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|showpkt
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|showpkt
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* showpkt */
block|{
if|if
condition|(
name|newdpy
condition|)
comment|/* Put up filenames, etc, */
name|dpyinit
argument_list|()
expr_stmt|;
comment|/* if they're not there already. */
if|if
condition|(
name|fdispla
operator|==
name|XYFD_S
condition|)
block|{
comment|/* CRT display */
name|char
name|buffer
index|[
literal|40
index|]
decl_stmt|;
name|long
name|et
decl_stmt|;
comment|/* Elapsed time, entire batch  */
name|long
name|pd
decl_stmt|;
comment|/* Percent done, this file     */
name|long
name|tp
decl_stmt|;
comment|/* Transfer rate, entire batch */
name|long
name|ps
decl_stmt|;
comment|/* Packet size, current packet */
name|long
name|myffc
decl_stmt|,
name|mytfc
decl_stmt|;
comment|/* Local copies of byte counters */
name|et
operator|=
name|gtimer
argument_list|()
expr_stmt|;
comment|/* Elapsed time  */
name|ps
operator|=
operator|(
name|what
operator|==
name|W_RECV
operator|)
condition|?
name|rpktl
operator|+
literal|1
else|:
name|spktl
operator|+
literal|1
expr_stmt|;
comment|/* Packet length */
name|pd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Percent done. */
if|if
condition|(
name|c
operator|==
name|NUL
condition|)
block|{
comment|/* Still going, figure % done */
if|if
condition|(
name|fsize
operator|==
literal|0L
condition|)
return|return;
comment|/* Empty file, don't bother */
name|pd
operator|=
operator|(
name|fsize
operator|>
literal|99L
operator|)
condition|?
operator|(
name|ffc
operator|/
operator|(
name|fsize
operator|/
literal|100L
operator|)
operator|)
else|:
literal|0L
expr_stmt|;
if|if
condition|(
name|pd
operator|>
literal|100
condition|)
name|pd
operator|=
literal|100
expr_stmt|;
comment|/* Expansion */
block|}
else|else
name|pd
operator|=
literal|100
expr_stmt|;
comment|/* File complete, so 100%. */
ifndef|#
directive|ifndef
name|CK_CPS
comment|/*   fsecs = time (from gtimer) that this file started (set in sfile()).   Rate so far is ffc / (et - fsecs),  estimated time for remaining bytes   is (fsize - ffc) / ( ffc / (et - fsecs )). */
name|tp
operator|=
operator|(
name|ffc
operator|>
literal|0L
operator|)
condition|?
operator|(
name|fsize
operator|-
name|ffc
operator|)
operator|*
operator|(
name|et
operator|-
name|fsecs
operator|)
operator|/
name|ffc
else|:
literal|0L
expr_stmt|;
endif|#
directive|endif
comment|/* CK_CPS */
name|myffc
operator|=
operator|(
name|ffc
operator|>
literal|0
operator|)
condition|?
name|ffc
operator|-
literal|1L
else|:
name|ffc
expr_stmt|;
comment|/* No, I don't know why... */
if|if
condition|(
name|myffc
operator|<
literal|0L
condition|)
name|myffc
operator|=
literal|0L
expr_stmt|;
ifdef|#
directive|ifdef
name|CK_CPS
name|mytfc
operator|=
operator|(
name|pd
operator|<
literal|100
operator|)
condition|?
name|tfc
operator|+
name|myffc
else|:
name|tfc
expr_stmt|;
name|tp
operator|=
operator|(
name|et
operator|>
literal|0
operator|)
condition|?
name|mytfc
operator|/
name|et
else|:
literal|0
expr_stmt|;
comment|/* Transfer rate */
if|if
condition|(
name|c
operator|&&
operator|(
name|tp
operator|==
literal|0
operator|)
condition|)
comment|/* Watch out for subsecond times */
name|tp
operator|=
name|myffc
expr_stmt|;
endif|#
directive|endif
comment|/* CK_CPS */
if|if
condition|(
name|pd
operator|>
operator|-
literal|1L
condition|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"%c%9ld%5ld%%%8ld%8ld "
argument_list|,
name|CR
argument_list|,
name|myffc
argument_list|,
name|pd
argument_list|,
name|tp
argument_list|,
name|ps
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"%c%9ld      %8ld%8ld "
argument_list|,
name|CR
argument_list|,
name|myffc
argument_list|,
name|tp
argument_list|,
name|ps
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|31
expr_stmt|;
block|}
else|else
block|{
comment|/* SERIAL display */
name|long
name|i
decl_stmt|,
name|k
decl_stmt|;
if|if
condition|(
name|ffc
operator|-
name|oldffc
operator|<
literal|1024
condition|)
comment|/* Update display every 1K */
return|return;
name|oldffc
operator|=
name|ffc
expr_stmt|;
comment|/* Time for new display */
name|k
operator|=
operator|(
name|ffc
operator|/
literal|1024L
operator|)
operator|-
name|dots
expr_stmt|;
comment|/* How many K so far */
for|for
control|(
name|i
operator|=
literal|0L
init|;
name|i
operator|<
name|k
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|hpos
operator|++
operator|>
literal|77
condition|)
block|{
comment|/* Time to wrap? */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
block|}
name|conoc
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
comment|/* Print a dot for this K */
name|dots
operator|++
expr_stmt|;
comment|/* Count it */
block|}
block|}
block|}
end_function

begin_comment
comment|/*  S C R E E N  --  Screen display function  */
end_comment

begin_comment
comment|/*   screen(f,c,n,s)     f - argument descriptor     c - a character or small integer     n - a long integer     s - a string.   Fill in this routine with the appropriate display update for the system.     FILE DISPLAY SERIAL:     Default, works on any terminal, even hardcopy.     FILE DISPLAY CRT:        Works on any CRT, writes over current line.     FILE DISPLAY FULLSCREEN: Requires terminal-dependent screen control. */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|screen
parameter_list|(
name|int
name|f
parameter_list|,
name|char
name|c
parameter_list|,
name|long
name|n
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
else|#
directive|else
function|screen
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
name|int
name|f
decl_stmt|;
name|char
name|c
decl_stmt|;
name|long
name|n
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* screen */
block|{
name|char
name|buf
index|[
literal|80
index|]
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* Length of string */
ifdef|#
directive|ifdef
name|UNIX
ifndef|#
directive|ifndef
name|NOJC
name|int
name|obg
decl_stmt|;
name|_PROTOTYP
argument_list|(
argument|VOID conbgt
argument_list|,
argument|(int)
argument_list|)
empty_stmt|;
if|if
condition|(
name|local
condition|)
block|{
name|obg
operator|=
name|backgrd
expr_stmt|;
comment|/* Previous background status */
name|conbgt
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* See if running in background */
if|if
condition|(
operator|!
name|backgrd
operator|&&
name|obg
condition|)
block|{
comment|/* Just came into foreground? */
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* Put console back in CBREAK mode */
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* Turn interrupts back on. */
block|}
block|}
endif|#
directive|endif
comment|/* NOJC */
endif|#
directive|endif
comment|/* UNIX */
if|if
condition|(
operator|(
name|f
operator|!=
name|SCR_WM
operator|)
operator|&&
operator|(
name|f
operator|!=
name|SCR_EM
operator|)
condition|)
comment|/* Always update warnings& errors */
if|if
condition|(
operator|!
name|displa
operator|||
name|quiet
operator|||
name|backgrd
operator|||
name|fdispla
operator|==
name|XYFD_N
operator|||
operator|(
name|server
operator|&&
operator|!
name|srvdis
operator|)
condition|)
return|return;
ifdef|#
directive|ifdef
name|CK_CURSES
if|if
condition|(
name|fdispla
operator|==
name|XYFD_C
condition|)
block|{
comment|/* If fullscreen display selected */
name|screenc
argument_list|(
name|f
argument_list|,
name|c
argument_list|,
name|n
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* call the fullscreen version */
return|return;
block|}
endif|#
directive|endif
comment|/* CK_CURSES */
name|len
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Length of string */
switch|switch
condition|(
name|f
condition|)
block|{
comment|/* Handle our function code */
case|case
name|SCR_FN
case|:
comment|/* Filename */
ifdef|#
directive|ifdef
name|MAC
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|conoc
argument_list|(
name|SP
argument_list|)
expr_stmt|;
name|hpos
operator|=
name|len
operator|+
literal|1
expr_stmt|;
else|#
directive|else
name|strncpy
argument_list|(
name|fbuf
argument_list|,
name|s
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|newdpy
operator|=
literal|1
expr_stmt|;
comment|/* New file so refresh display */
endif|#
directive|endif
comment|/* MAC */
return|return;
case|case
name|SCR_AN
case|:
comment|/* As-name */
ifdef|#
directive|ifdef
name|MAC
if|if
condition|(
name|hpos
operator|+
name|len
operator|>
literal|75
condition|)
block|{
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
block|}
name|conol
argument_list|(
literal|"=> "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|hpos
operator|+=
operator|(
name|len
operator|+
literal|3
operator|)
operator|)
operator|>
literal|78
condition|)
block|{
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
block|}
else|#
directive|else
name|strncpy
argument_list|(
name|abuf
argument_list|,
name|s
argument_list|,
literal|80
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
return|return;
case|case
name|SCR_FS
case|:
comment|/* File-size */
ifdef|#
directive|ifdef
name|MAC
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|", Size: %ld"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
return|return;
case|case
name|SCR_XD
case|:
comment|/* X-packet data */
ifdef|#
directive|ifdef
name|MAC
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|strncpy
argument_list|(
name|fbuf
argument_list|,
name|s
argument_list|,
literal|80
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
return|return;
case|case
name|SCR_ST
case|:
comment|/* File status */
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|ST_OK
case|:
comment|/* Transferred OK */
name|showpkt
argument_list|(
literal|'Z'
argument_list|)
expr_stmt|;
comment|/* Update numbers one last time */
if|if
condition|(
operator|(
name|hpos
operator|+=
literal|5
operator|)
operator|>
literal|78
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* Wrap screen line if necessary. */
name|conoll
argument_list|(
literal|" [OK]"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
comment|/* Print OK message. */
if|if
condition|(
name|fdispla
operator|==
name|XYFD_S
condition|)
block|{
comment|/* We didn't show Z packet when */
name|conoc
argument_list|(
literal|'Z'
argument_list|)
expr_stmt|;
comment|/* it came, so show it now. */
name|hpos
operator|=
literal|1
expr_stmt|;
block|}
return|return;
case|case
name|ST_DISC
case|:
comment|/*  Discarded */
if|if
condition|(
operator|(
name|hpos
operator|+=
literal|12
operator|)
operator|>
literal|78
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|" [discarded]"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|ST_INT
case|:
comment|/*  Interrupted */
if|if
condition|(
operator|(
name|hpos
operator|+=
literal|14
operator|)
operator|>
literal|78
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|" [interrupted]"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|ST_SKIP
case|:
comment|/*  Skipped */
if|if
condition|(
operator|(
name|hpos
operator|+=
literal|10
operator|)
operator|>
literal|78
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|" [skipped]"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|ST_ERR
case|:
comment|/* Error */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|"Error: "
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|ST_REFU
case|:
comment|/* Refused */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|"Refused: "
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|ST_INC
case|:
comment|/* Incomplete */
if|if
condition|(
operator|(
name|hpos
operator|+=
literal|12
operator|)
operator|>
literal|78
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|" [incomplete]"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
default|default:
name|conoll
argument_list|(
literal|"*** screen() called with bad status ***"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|MAC
case|case
name|SCR_PN
case|:
comment|/* Packet number */
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s: %ld"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|hpos
operator|+=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
comment|/* MAC */
case|case
name|SCR_PT
case|:
comment|/* Packet type or pseudotype */
if|if
condition|(
name|c
operator|==
literal|'Y'
condition|)
return|return;
comment|/* Don't bother with ACKs */
if|if
condition|(
name|c
operator|==
literal|'D'
condition|)
block|{
comment|/* In data transfer phase, */
name|showpkt
argument_list|(
name|NUL
argument_list|)
expr_stmt|;
comment|/* show progress. */
return|return;
block|}
ifndef|#
directive|ifndef
name|AMIGA
if|if
condition|(
name|hpos
operator|++
operator|>
literal|77
condition|)
block|{
comment|/* If near right margin, */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* Start new line */
name|hpos
operator|=
literal|0
expr_stmt|;
comment|/* and reset counter. */
block|}
endif|#
directive|endif
comment|/* AMIGA */
if|if
condition|(
name|c
operator|==
literal|'Z'
operator|&&
name|fdispla
operator|==
name|XYFD_S
condition|)
return|return;
else|else
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Display the packet type. */
ifdef|#
directive|ifdef
name|AMIGA
if|if
condition|(
name|c
operator|==
literal|'G'
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* New line after G packets */
endif|#
directive|endif
comment|/* AMIGA */
return|return;
case|case
name|SCR_TC
case|:
comment|/* Transaction complete */
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return;
case|case
name|SCR_EM
case|:
comment|/* Error message */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoc
argument_list|(
literal|'?'
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|SCR_WM
case|:
comment|/* Warning message */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|SCR_TU
case|:
comment|/* Undelimited text */
if|if
condition|(
operator|(
name|hpos
operator|+=
name|len
operator|)
operator|>
literal|77
condition|)
block|{
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|hpos
operator|=
name|len
expr_stmt|;
block|}
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
case|case
name|SCR_TN
case|:
comment|/* Text delimited at beginning */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hpos
operator|=
name|len
expr_stmt|;
return|return;
case|case
name|SCR_TZ
case|:
comment|/* Text delimited at end */
if|if
condition|(
operator|(
name|hpos
operator|+=
name|len
operator|)
operator|>
literal|77
condition|)
block|{
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|hpos
operator|=
name|len
expr_stmt|;
block|}
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
case|case
name|SCR_QE
case|:
comment|/* Quantity equals */
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s: %ld"
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
case|case
name|SCR_CW
case|:
comment|/* Close fullscreen window */
return|return;
comment|/* No window to close */
default|default:
name|conoll
argument_list|(
literal|"*** screen() called with bad object ***"
argument_list|)
expr_stmt|;
name|hpos
operator|=
literal|0
expr_stmt|;
return|return;
block|}
block|}
end_function

begin_comment
comment|/*  E R M S G  --  Nonfatal error message  */
end_comment

begin_comment
comment|/* Should be used only for printing the message text from an Error packet. */
end_comment

begin_function
name|VOID
name|ermsg
parameter_list|(
name|msg
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|;
block|{
comment|/* Print error message */
if|if
condition|(
name|local
condition|)
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0L
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Protocol Error:"
argument_list|,
name|msg
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|doclean
parameter_list|()
block|{
comment|/* General cleanup upon exit */
ifndef|#
directive|ifndef
name|NOICP
ifndef|#
directive|ifndef
name|NOSPL
specifier|extern
name|struct
name|mtab
modifier|*
name|mactab
decl_stmt|;
comment|/* For ON_EXIT macro. */
specifier|extern
name|int
name|nmac
decl_stmt|;
endif|#
directive|endif
comment|/* NOSPL */
endif|#
directive|endif
comment|/* NOICP */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|deblog
condition|)
block|{
comment|/* Close any open logs. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"Debug Log Closed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|*
name|debfil
operator|=
literal|'\0'
expr_stmt|;
name|deblog
operator|=
literal|0
expr_stmt|;
name|zclose
argument_list|(
name|ZDFILE
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|pktlog
condition|)
block|{
operator|*
name|pktfil
operator|=
literal|'\0'
expr_stmt|;
name|pktlog
operator|=
literal|0
expr_stmt|;
name|zclose
argument_list|(
name|ZPFILE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|seslog
condition|)
block|{
operator|*
name|sesfil
operator|=
literal|'\0'
expr_stmt|;
name|seslog
operator|=
literal|0
expr_stmt|;
name|zclose
argument_list|(
name|ZSFILE
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|TLOG
if|if
condition|(
name|tralog
condition|)
block|{
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Transaction Log Closed"
argument_list|,
literal|""
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
operator|*
name|trafil
operator|=
literal|'\0'
expr_stmt|;
name|tralog
operator|=
literal|0
expr_stmt|;
name|zclose
argument_list|(
name|ZTFILE
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TLOG */
ifndef|#
directive|ifndef
name|NOICP
ifndef|#
directive|ifndef
name|NOSPL
name|zclose
argument_list|(
name|ZRFILE
argument_list|)
expr_stmt|;
comment|/* READ and WRITE files, if any. */
name|zclose
argument_list|(
name|ZWFILE
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NODIAL
if|if
condition|(
name|dialfd
condition|)
name|fclose
argument_list|(
name|dialfd
argument_list|)
expr_stmt|;
comment|/* Dial directory, if any. */
endif|#
directive|endif
comment|/* NODIAL */
comment|/*   If a macro named "on_exit" is defined, execute it.  Also remove it from the   macro table, in case its definition includes an EXIT or QUIT command, which   would cause much recursion and would prevent the program from ever actually   EXITing. */
if|if
condition|(
name|nmac
condition|)
block|{
comment|/* Any macros defined? */
name|int
name|k
decl_stmt|;
comment|/* Yes */
name|k
operator|=
name|mlook
argument_list|(
name|mactab
argument_list|,
literal|"on_exit"
argument_list|,
name|nmac
argument_list|)
expr_stmt|;
comment|/* Look up "on_exit" */
if|if
condition|(
name|k
operator|>=
literal|0
condition|)
block|{
comment|/* If found, */
operator|*
operator|(
name|mactab
index|[
name|k
index|]
operator|.
name|kwd
operator|)
operator|=
name|NUL
expr_stmt|;
comment|/* poke its name from the table, */
if|if
condition|(
name|dodo
argument_list|(
name|k
argument_list|,
literal|""
argument_list|)
operator|>
operator|-
literal|1
condition|)
comment|/* set it up, */
name|parser
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* and execute it */
block|}
block|}
endif|#
directive|endif
comment|/* NOSPL */
endif|#
directive|endif
comment|/* NOICP */
comment|/*   Put console terminal back to normal.  This is done here because the   ON_EXIT macro calls the parser, which meddles with console terminal modes. */
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Close external line, if any */
if|if
condition|(
name|local
condition|)
block|{
name|strcpy
argument_list|(
name|ttname
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
comment|/* Restore default tty */
name|local
operator|=
name|dfloc
expr_stmt|;
comment|/* And default remote/local status */
block|}
name|conres
argument_list|()
expr_stmt|;
comment|/* Restore console terminal. */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Should be no need for this, and maybe it's screwing things up? */
name|connoi
argument_list|()
expr_stmt|;
comment|/* Turn off console interrupt traps */
endif|#
directive|endif
comment|/* COMMENT */
name|syscleanup
argument_list|()
expr_stmt|;
comment|/* System-dependent cleanup, last */
block|}
end_function

begin_comment
comment|/*  D O E X I T  --  Exit from the program.  */
end_comment

begin_comment
comment|/*   First arg is general, system-independent symbol: GOOD_EXIT or BAD_EXIT.   If second arg is -1, take 1st arg literally.   If second arg is not -1, work it into the exit code. */
end_comment

begin_function
name|VOID
name|doexit
parameter_list|(
name|exitstat
parameter_list|,
name|what
parameter_list|)
name|int
name|exitstat
decl_stmt|,
name|what
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|VMS
name|char
name|envstr
index|[
literal|64
index|]
decl_stmt|;
specifier|static
name|$DESCRIPTOR
argument_list|(
name|symnam
argument_list|,
literal|"CKERMIT_STATUS"
argument_list|)
expr_stmt|;
specifier|static
name|struct
name|dsc$descriptor_s
name|symval
decl_stmt|;
name|int
name|i
decl_stmt|;
endif|#
directive|endif
comment|/* VMS */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"doexit exitstat"
argument_list|,
literal|""
argument_list|,
name|exitstat
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"doexit what"
argument_list|,
literal|""
argument_list|,
name|what
argument_list|)
expr_stmt|;
name|doclean
argument_list|()
expr_stmt|;
comment|/* First, clean up everything */
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
name|what
operator|==
operator|-
literal|1
condition|)
name|what
operator|=
literal|0
expr_stmt|;
comment|/* Since we set two different items */
name|sprintf
argument_list|(
name|envstr
argument_list|,
literal|"%d"
argument_list|,
name|exitstat
operator||
name|what
argument_list|)
expr_stmt|;
name|symval
operator|.
name|dsc$w_length
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|envstr
argument_list|)
expr_stmt|;
name|symval
operator|.
name|dsc$a_pointer
operator|=
name|envstr
expr_stmt|;
name|symval
operator|.
name|dsc$b_class
operator|=
name|DSC$K_CLASS_S
expr_stmt|;
name|symval
operator|.
name|dsc$b_dtype
operator|=
name|DSC$K_DTYPE_T
expr_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
comment|/* Store in global table */
name|LIB$SET_SYMBOL
argument_list|(
operator|&
name|symnam
argument_list|,
operator|&
name|symval
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|exitstat
operator|==
name|BAD_EXIT
condition|)
name|exitstat
operator|=
name|SS$_ABORT
operator||
name|STS$M_INHIB_MSG
expr_stmt|;
if|if
condition|(
name|exitstat
operator|==
name|GOOD_EXIT
condition|)
name|exitstat
operator|=
name|SS$_NORMAL
operator||
name|STS$M_INHIB_MSG
expr_stmt|;
name|exit
argument_list|(
name|exitstat
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Not VMS */
if|if
condition|(
name|what
operator|==
operator|-
literal|1
condition|)
comment|/* Take 1st arg literally */
name|exit
argument_list|(
name|exitstat
argument_list|)
expr_stmt|;
comment|/* e.g. user-supplied exit code */
else|else
comment|/* otherwise */
name|exit
argument_list|(
name|exitstat
operator||
name|what
argument_list|)
expr_stmt|;
comment|/* OR in the bits */
endif|#
directive|endif
comment|/* VMS */
block|}
end_function

begin_comment
comment|/* Set up interrupts */
end_comment

begin_function
name|VOID
name|setint
parameter_list|()
block|{
name|conint
argument_list|(
name|trap
argument_list|,
name|stptrap
argument_list|)
expr_stmt|;
comment|/* Turn on console terminal interrupts. */
name|bgchk
argument_list|()
expr_stmt|;
comment|/* Check background status */
block|}
end_function

begin_function
name|VOID
name|bgchk
parameter_list|()
block|{
comment|/* Check background status */
if|if
condition|(
name|bgset
operator|<
literal|0
condition|)
name|pflag
operator|=
operator|!
name|backgrd
expr_stmt|;
comment|/* Set prompt flag */
else|else
comment|/* based on foreground/background */
name|pflag
operator|=
operator|(
name|bgset
operator|==
literal|0
condition|?
literal|1
else|:
literal|0
operator|)
expr_stmt|;
comment|/* Message flag on only if at top level, pflag is on, and QUIET is OFF */
if|if
condition|(
ifndef|#
directive|ifndef
name|NOSPL
name|cmdlvl
operator|==
literal|0
else|#
directive|else
name|tlevel
operator|<
literal|0
endif|#
directive|endif
comment|/* NOSPL */
condition|)
name|msgflg
operator|=
operator|(
name|pflag
operator|==
literal|0
operator|)
condition|?
literal|0
else|:
operator|!
name|quiet
expr_stmt|;
else|else
name|msgflg
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  D E B U G  --  Enter a record in the debugging log  */
end_comment

begin_comment
comment|/*  Call with a format, two strings, and a number:    f  - Format, a bit string in range 0-7.         If bit x is on, then argument number x is printed.    s1 - String, argument number 1.  If selected, printed as is.    s2 - String, argument number 2.  If selected, printed in brackets.    n  - Int, argument 3.  If selected, printed preceded by equals sign.     f=0 is special: print s1,s2, and interpret n as a char. */
end_comment

begin_define
define|#
directive|define
name|DBUFL
value|2300
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|dbptr
init|=
operator|(
name|char
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|dodebug
parameter_list|(
name|f
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
name|int
name|f
decl_stmt|;
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
name|long
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|sp
decl_stmt|;
if|if
condition|(
operator|!
name|deblog
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* If no debug log, don't. */
if|if
condition|(
operator|!
name|dbptr
condition|)
block|{
name|dbptr
operator|=
name|malloc
argument_list|(
name|DBUFL
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dbptr
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|sp
operator|=
name|dbptr
expr_stmt|;
if|if
condition|(
operator|!
name|s1
condition|)
name|s1
operator|=
literal|"(NULL)"
expr_stmt|;
if|if
condition|(
operator|!
name|s2
condition|)
name|s2
operator|=
literal|"(NULL)"
expr_stmt|;
switch|switch
condition|(
name|f
condition|)
block|{
case|case
name|F000
case|:
comment|/* 0, print both strings, and n as a char */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|5
operator|>
name|DBUFL
condition|)
block|{
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|n
operator|>
literal|31
operator|&&
name|n
operator|<
literal|127
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s%s:%c\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|<
literal|32
operator|||
name|n
operator|==
literal|127
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s%s:^%c\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
operator|(
name|n
operator|+
literal|64
operator|)
operator|&
literal|0x7F
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|127
operator|&&
name|n
operator|<
literal|160
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s%s:~^%c\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
operator|(
name|n
operator|-
literal|64
operator|)
operator|&
literal|0x7F
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|n
operator|>
literal|159
operator|&&
name|n
operator|<
literal|256
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s%s:~%c\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|n
operator|&
literal|0x7F
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s%s:%ld\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F001
case|:
comment|/* 1, "=n" */
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"=%ld\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F010
case|:
comment|/* 2, "[s2]" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|4
operator|>
name|DBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"[%s]\n"
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
literal|""
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F011
case|:
comment|/* 3, "[s2]=n" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|15
operator|>
name|DBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"[%s]=%ld\n"
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F100
case|:
comment|/* 4, "s1" */
if|if
condition|(
name|zsoutl
argument_list|(
name|ZDFILE
argument_list|,
name|s1
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F101
case|:
comment|/* 5, "s1=n" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
literal|15
operator|>
name|DBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s=%ld\n"
argument_list|,
name|s1
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F110
case|:
comment|/* 6, "s1[s2]" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|4
operator|>
name|DBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s[%s]\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F111
case|:
comment|/* 7, "s1[s2]=n" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|15
operator|>
name|DBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"DEBUG string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s[%s]=%ld\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"\n?Invalid format for debug() - %d\n"
argument_list|,
name|f
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZDFILE
argument_list|,
name|dbptr
argument_list|)
operator|<
literal|0
condition|)
name|deblog
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TLOG
end_ifdef

begin_define
define|#
directive|define
name|TBUFL
value|300
end_define

begin_comment
comment|/*  T L O G  --  Log a record in the transaction file  */
end_comment

begin_comment
comment|/*  Call with a format and 3 arguments: two strings and a number:    f  - Format, a bit string in range 0-7, bit x is on, arg #x is printed.    s1,s2 - String arguments 1 and 2.    n  - Int, argument 3. */
end_comment

begin_function
name|VOID
name|tlog
parameter_list|(
name|f
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
name|int
name|f
decl_stmt|;
name|long
name|n
decl_stmt|;
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
specifier|static
name|char
name|s
index|[
name|TBUFL
index|]
decl_stmt|;
name|char
modifier|*
name|sp
init|=
name|s
decl_stmt|;
name|int
name|x
decl_stmt|;
if|if
condition|(
operator|!
name|tralog
condition|)
return|return;
comment|/* If no transaction log, don't */
switch|switch
condition|(
name|f
condition|)
block|{
case|case
name|F000
case|:
comment|/* 0 (special) "s1 n s2"  */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
operator|+
literal|15
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s %ld %s\n"
argument_list|,
name|s1
argument_list|,
name|n
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F001
case|:
comment|/* 1, " n" */
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|" %ld\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F010
case|:
comment|/* 2, "[s2]" */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|s2
index|[
name|x
index|]
operator|==
literal|'\n'
condition|)
name|s2
index|[
name|x
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|x
operator|+
literal|6
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"[%s]\n"
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
literal|""
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F011
case|:
comment|/* 3, "[s2] n" */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|s2
index|[
name|x
index|]
operator|==
literal|'\n'
condition|)
name|s2
index|[
name|x
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|x
operator|+
literal|6
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"[%s] %ld\n"
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F100
case|:
comment|/* 4, "s1" */
if|if
condition|(
name|zsoutl
argument_list|(
name|ZTFILE
argument_list|,
name|s1
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F101
case|:
comment|/* 5, "s1: n" */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
literal|15
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s: %ld\n"
argument_list|,
name|s1
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F110
case|:
comment|/* 6, "s1 s2" */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|s2
index|[
name|x
index|]
operator|==
literal|'\n'
condition|)
name|s2
index|[
name|x
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
name|x
operator|+
literal|4
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s %s\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|F111
case|:
comment|/* 7, "s1 s2: n" */
name|x
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s2
argument_list|)
expr_stmt|;
if|if
condition|(
name|s2
index|[
name|x
index|]
operator|==
literal|'\n'
condition|)
name|s2
index|[
name|x
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s1
argument_list|)
operator|+
name|x
operator|+
literal|15
operator|>
name|TBUFL
condition|)
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"?T-Log string too long\n"
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"%s %s: %ld\n"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|sprintf
argument_list|(
name|sp
argument_list|,
literal|"\n?Invalid format for tlog() - %ld\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|zsout
argument_list|(
name|ZTFILE
argument_list|,
name|s
argument_list|)
operator|<
literal|0
condition|)
name|tralog
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLOG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_CURSES
end_ifdef

begin_comment
comment|/*   There are three different ways to do fullscreen on VMS.   1. Use the real curses library, VAXCCURSE.   2. Use do-it-yourself code.   3. Use the Screen Manager, SMG$.    Method 1 doesn't work quite right; you can't call endwin(), so once you've   started curses mode, you can never leave.    Method 2 doesn't optimize the screen, and so much more time is spent in   screen writes.  This actually causes file transfers to fail because the   tty device input buffer can be overrun while the screen is being updated,   especially on a slow MicroVAX that has small typeahead buffers.    In the following #ifdef block, #define one of them and #undef the other 2.    So now let's try method 3... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|CK_SMG
end_define

begin_comment
comment|/* Screen Manager */
end_comment

begin_undef
undef|#
directive|undef
name|MYCURSES
end_undef

begin_comment
comment|/* Do-it-yourself */
end_comment

begin_undef
undef|#
directive|undef
name|VMSCURSE
end_undef

begin_comment
comment|/* VAXCCURSE library */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/*  S C R E E N C  --  Screen display function, uses curses  */
end_comment

begin_comment
comment|/* Idea for curses display contributed by Chris Pratt of APV Baker, UK */
end_comment

begin_comment
comment|/* Avoid conficts with curses.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MYCURSES
end_ifndef

begin_undef
undef|#
directive|undef
name|VOID
end_undef

begin_comment
comment|/* This was defined in ckcdeb.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYCURSES */
end_comment

begin_undef
undef|#
directive|undef
name|BS
end_undef

begin_comment
comment|/* These were defined in ckcasc.h */
end_comment

begin_undef
undef|#
directive|undef
name|CR
end_undef

begin_undef
undef|#
directive|undef
name|NL
end_undef

begin_undef
undef|#
directive|undef
name|SO
end_undef

begin_undef
undef|#
directive|undef
name|US
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* VMS fullscreen display */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYCURSES
end_ifdef

begin_comment
comment|/* Do-it-yourself method */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isvt52
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From CKVTIO.C */
end_comment

begin_define
define|#
directive|define
name|printw
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMSCURSE
end_ifdef

begin_comment
comment|/* VMS curses library VAXCCURSE */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_comment
comment|/* Note: Screen manager doesn't need a header file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMSCURSE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYCURSES */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYCURSES
end_ifdef

begin_comment
comment|/* Do-it-yourself method */
end_comment

begin_define
define|#
directive|define
name|isvt52
value|0
end_define

begin_comment
comment|/* Used by OS/2, VT-100/ANSI always */
end_comment

begin_define
define|#
directive|define
name|printw
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_comment
comment|/* So use real curses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYCURSES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_SMG
end_ifdef

begin_comment
comment|/*   Long section for Screen Manager starts here...   By William Bader. */
end_comment

begin_include
include|#
directive|include
file|"ckvvms.h"
end_include

begin_comment
comment|/* #include<smgdef.h> */
end_comment

begin_comment
comment|/* #include<smgmsg.h> */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|vms_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used for system service return status */
end_comment

begin_decl_stmt
specifier|static
name|long
name|smg_pasteboard_id
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pasteboard identifier */
end_comment

begin_decl_stmt
specifier|static
name|long
name|smg_display_id
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display identifier */
end_comment

begin_decl_stmt
specifier|static
name|int
name|smg_open
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag if smg current open */
end_comment

begin_define
define|#
directive|define
name|clrtoeol
parameter_list|()
value|SMG$ERASE_LINE(&smg_display_id, 0, 0)
end_define

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|SMG$ERASE_DISPLAY(&smg_display_id, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|touchwin
parameter_list|(
name|scr
parameter_list|)
value|SMG$REPAINT_SCREEN(&smg_pasteboard_id)
end_define

begin_function
specifier|static
name|void
name|move
parameter_list|(
name|row
parameter_list|,
name|col
parameter_list|)
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
block|{
comment|/* Change from 0-based for curses to 1-based for SMG */
operator|++
name|row
expr_stmt|;
operator|++
name|col
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"move: smg$set_cursor_abs"
argument_list|,
name|SMG$SET_CURSOR_ABS
argument_list|(
operator|&
name|smg_display_id
argument_list|,
operator|&
name|row
argument_list|,
operator|&
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|refresh
parameter_list|()
block|{
name|CHECK_ERR
argument_list|(
literal|"refresh: smg$end_pasteboard_update"
argument_list|,
name|SMG$END_PASTEBOARD_UPDATE
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|)
argument_list|)
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"refresh: smg$begin_pasteboard_update"
argument_list|,
name|SMG$BEGIN_PASTEBOARD_UPDATE
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|VMS_V40
end_ifdef

begin_define
define|#
directive|define
name|OLD_VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS_V40 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS_V42
end_ifdef

begin_define
define|#
directive|define
name|OLD_VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS_V42 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS_V44
end_ifdef

begin_define
define|#
directive|define
name|OLD_VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS_V44 */
end_comment

begin_function
specifier|static
name|int
name|initscr
parameter_list|()
block|{
name|int
name|rows
init|=
literal|24
decl_stmt|,
name|cols
init|=
literal|80
decl_stmt|;
name|int
name|row
init|=
literal|1
decl_stmt|,
name|col
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|smg_pasteboard_id
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Open the screen */
ifdef|#
directive|ifdef
name|OLD_VMS
name|CHECK_ERR
argument_list|(
literal|"initscr: smg$create_pasteboard"
argument_list|,
name|SMG$CREATE_PASTEBOARD
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* For VMS V5, not tested */
name|CHECK_ERR
argument_list|(
literal|"initscr: smg$create_pasteboard"
argument_list|,
name|SMG$CREATE_PASTEBOARD
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OLD_VMS */
block|}
if|if
condition|(
name|smg_display_id
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Create a display window */
name|CHECK_ERR
argument_list|(
literal|"initscr: smg$create_virtual_display"
argument_list|,
name|SMG$CREATE_VIRTUAL_DISPLAY
argument_list|(
operator|&
name|rows
argument_list|,
operator|&
name|cols
argument_list|,
operator|&
name|smg_display_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Connect the display window to the screen */
name|CHECK_ERR
argument_list|(
literal|"initscr: smg$paste_virtual_display"
argument_list|,
name|SMG$PASTE_VIRTUAL_DISPLAY
argument_list|(
operator|&
name|smg_display_id
argument_list|,
operator|&
name|smg_pasteboard_id
argument_list|,
operator|&
name|row
argument_list|,
operator|&
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|smg_open
condition|)
block|{
comment|/* Start a batch update */
name|smg_open
operator|=
literal|1
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"initscr: smg$begin_pasteboard_update"
argument_list|,
name|SMG$BEGIN_PASTEBOARD_UPDATE
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|endwin
parameter_list|()
block|{
if|if
condition|(
operator|!
name|smg_open
condition|)
return|return;
name|smg_open
operator|=
literal|0
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"endwin: smg$end_pasteboard_update"
argument_list|,
name|SMG$END_PASTEBOARD_UPDATE
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|)
argument_list|)
expr_stmt|;
name|move
argument_list|(
literal|22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   These calls clear the screen. */
name|CHECK_ERR
argument_list|(
literal|"endwin: smg$delete_virtual_display"
argument_list|,
name|SMG$DELETE_VIRTUAL_DISPLAY
argument_list|(
operator|&
name|smg_display_id
argument_list|)
argument_list|)
expr_stmt|;
name|smg_display_id
operator|=
operator|-
literal|1
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"endwin: smg$delete_pasteboard"
argument_list|,
name|SMG$DELETE_PASTEBOARD
argument_list|(
operator|&
name|smg_pasteboard_id
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|smg_pasteboard_id
operator|=
operator|-
literal|1
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
block|}
end_function

begin_function
specifier|static
name|void
name|printw
parameter_list|(
name|str
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
name|long
name|a1
decl_stmt|,
name|a2
decl_stmt|,
name|a3
decl_stmt|,
name|a4
decl_stmt|,
name|a5
decl_stmt|,
name|a6
decl_stmt|,
name|a7
decl_stmt|,
name|a8
decl_stmt|;
comment|/* printw */
block|{
name|char
name|buf
index|[
literal|255
index|]
decl_stmt|;
name|$DESCRIPTOR
argument_list|(
name|text_dsc
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|text_dsc
operator|.
name|dsc$w_length
operator|=
name|sprintf
argument_list|(
name|buf
argument_list|,
name|str
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|)
expr_stmt|;
name|CHECK_ERR
argument_list|(
literal|"printw: smg$put_chars"
argument_list|,
name|SMG$PUT_CHARS
argument_list|(
operator|&
name|smg_display_id
argument_list|,
operator|&
name|text_dsc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_SMG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYCURSES
end_ifdef

begin_comment
comment|/*   Do-it-yourself curses implementation for VMS, OS/2 and other ANSI/VT-100's.   Supports only the VT52 and VT1xx (and later VT2xx/3xx/4xx) terminals.   By Terry Kennedy, St Peters College.     First, some stuff we can just ignore: */
end_comment

begin_function
name|int
name|touchwin
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{ }
end_function

begin_function
name|int
name|initscr
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|refresh
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|endwin
parameter_list|()
block|{ }
end_function

begin_comment
comment|/*  * Now, some stuff we need to do:  */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int move
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|move
parameter_list|(
name|row
parameter_list|,
name|col
parameter_list|)
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
block|{
if|if
condition|(
name|isvt52
condition|)
name|printf
argument_list|(
literal|"\033Y%c%c"
argument_list|,
name|row
operator|+
literal|037
argument_list|,
name|col
operator|+
literal|037
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\033[%d;%dH"
argument_list|,
name|row
operator|+
literal|1
argument_list|,
name|col
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|clear
parameter_list|()
block|{
name|move
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|isvt52
condition|)
name|printf
argument_list|(
literal|"\033J"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\033[J"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|clrtoeol
parameter_list|()
block|{
if|if
condition|(
name|isvt52
condition|)
name|printf
argument_list|(
literal|"\033K"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\033[K"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYCURSES */
end_comment

begin_comment
comment|/* Screen line numbers */
end_comment

begin_define
define|#
directive|define
name|CW_BAN
value|0
end_define

begin_comment
comment|/* Curses Window Banner */
end_comment

begin_define
define|#
directive|define
name|CW_DIR
value|2
end_define

begin_comment
comment|/* Current directory */
end_comment

begin_define
define|#
directive|define
name|CW_LIN
value|3
end_define

begin_comment
comment|/* Communication device */
end_comment

begin_define
define|#
directive|define
name|CW_SPD
value|4
end_define

begin_comment
comment|/* Communication speed */
end_comment

begin_define
define|#
directive|define
name|CW_PAR
value|5
end_define

begin_comment
comment|/* Parity */
end_comment

begin_define
define|#
directive|define
name|CW_NAM
value|7
end_define

begin_comment
comment|/* Filename */
end_comment

begin_define
define|#
directive|define
name|CW_TYP
value|8
end_define

begin_comment
comment|/* File type */
end_comment

begin_define
define|#
directive|define
name|CW_SIZ
value|9
end_define

begin_comment
comment|/* File size */
end_comment

begin_define
define|#
directive|define
name|CW_PCD
value|10
end_define

begin_comment
comment|/* Percent done */
end_comment

begin_define
define|#
directive|define
name|CW_TR
value|11
end_define

begin_comment
comment|/* Time remaining */
end_comment

begin_define
define|#
directive|define
name|CW_WS
value|12
end_define

begin_comment
comment|/* Window slots */
end_comment

begin_define
define|#
directive|define
name|CW_PT
value|13
end_define

begin_comment
comment|/* Packet type */
end_comment

begin_define
define|#
directive|define
name|CW_PC
value|14
end_define

begin_comment
comment|/* Packet count */
end_comment

begin_define
define|#
directive|define
name|CW_PL
value|15
end_define

begin_comment
comment|/* Packet length */
end_comment

begin_define
define|#
directive|define
name|CW_PR
value|16
end_define

begin_comment
comment|/* Packet retry */
end_comment

begin_define
define|#
directive|define
name|CW_PB
value|17
end_define

begin_comment
comment|/* Packet block check */
end_comment

begin_define
define|#
directive|define
name|CW_ERR
value|19
end_define

begin_comment
comment|/* Error message */
end_comment

begin_define
define|#
directive|define
name|CW_MSG
value|20
end_define

begin_comment
comment|/* Info message */
end_comment

begin_define
define|#
directive|define
name|CW_INT
value|22
end_define

begin_comment
comment|/* Instructions */
end_comment

begin_decl_stmt
specifier|static
name|int
name|cinit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for curses init'd */
end_comment

begin_decl_stmt
specifier|static
name|int
name|cendw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* endwin() was called */
end_comment

begin_function
specifier|static
ifdef|#
directive|ifdef
name|CK_ANSIC
comment|/* Because VOID used by curses.h */
name|void
else|#
directive|else
ifdef|#
directive|ifdef
name|MYCURSES
name|VOID
else|#
directive|else
name|int
endif|#
directive|endif
comment|/* MYCURSES */
endif|#
directive|endif
comment|/* CK_ANSIC */
name|scrft
parameter_list|()
block|{
comment|/* Display file type */
name|move
argument_list|(
name|CW_TYP
argument_list|,
literal|22
argument_list|)
expr_stmt|;
if|if
condition|(
name|binary
condition|)
block|{
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
name|binary
operator|==
name|XYFT_I
condition|)
name|printw
argument_list|(
literal|"image"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|binary
operator|==
name|XYFT_L
condition|)
name|printw
argument_list|(
literal|"labeled"
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"binary"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Not VMS */
name|printw
argument_list|(
literal|"binary"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
block|}
else|else
block|{
name|printw
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
block|}
name|clrtoeol
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|char
modifier|*
comment|/* Convert seconds to hh:mm:ss */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|hhmmss
parameter_list|(
name|long
name|x
parameter_list|)
else|#
directive|else
function|hhmmss
parameter_list|(
name|x
parameter_list|)
name|long
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* hhmmss(x) */
block|{
specifier|static
name|char
name|buf
index|[
literal|10
index|]
decl_stmt|;
name|long
name|s
decl_stmt|,
name|h
decl_stmt|,
name|m
decl_stmt|;
name|h
operator|=
name|x
operator|/
literal|3600L
expr_stmt|;
comment|/* Hours */
name|x
operator|=
name|x
operator|%
literal|3600L
expr_stmt|;
name|m
operator|=
name|x
operator|/
literal|60L
expr_stmt|;
comment|/* Minutes */
name|s
operator|=
name|x
operator|%
literal|60L
expr_stmt|;
comment|/* Seconds */
if|if
condition|(
name|x
operator|>
operator|-
literal|1L
condition|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%02ld:%02ld:%02ld"
argument_list|,
name|h
argument_list|,
name|m
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|buf
index|[
literal|0
index|]
operator|=
name|NUL
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|buf
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|CK_NEWTERM
end_ifdef

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|ck_stdout
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ck_fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_NEWTERM */
end_comment

begin_decl_stmt
specifier|static
name|long
name|pct
init|=
literal|100
decl_stmt|,
name|oldpct
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Percent done */
end_comment

begin_decl_stmt
specifier|static
name|int
name|oldtyp
init|=
literal|0
decl_stmt|,
name|oldwin
init|=
operator|-
literal|1
decl_stmt|,
name|oldtry
init|=
operator|-
literal|1
decl_stmt|,
name|oldlen
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_decl_stmt
name|void
name|screenc
argument_list|(
name|int
name|f
argument_list|,
name|char
name|c
argument_list|,
name|long
name|n
argument_list|,
name|char
operator|*
name|s
argument_list|)
else|#
directive|else
ifdef|#
directive|ifdef
name|MYCURSES
name|VOID
else|#
directive|else
name|int
endif|#
directive|endif
comment|/* MYCURSES */
name|screenc
argument_list|(
name|f
argument_list|,
name|c
argument_list|,
name|n
argument_list|,
name|s
argument_list|)
name|int
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument descriptor */
end_comment

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a character or small integer */
end_comment

begin_decl_stmt
name|long
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a long integer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a string */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_comment
comment|/* screenc() */
end_comment

begin_block
block|{
specifier|static
name|int
name|q
init|=
literal|0
decl_stmt|;
specifier|static
name|long
name|fsiz
init|=
operator|-
literal|1L
decl_stmt|;
comment|/* Copy of file size */
specifier|static
name|long
name|fcnt
init|=
literal|0L
decl_stmt|;
comment|/* File count */
specifier|static
name|long
name|fbyt
init|=
literal|0L
decl_stmt|;
comment|/* Total file bytes */
name|int
name|len
decl_stmt|;
comment|/* Length of string */
name|int
name|x
decl_stmt|;
comment|/* Worker */
if|if
condition|(
name|cinit
operator|==
literal|0
operator|||
name|cendw
operator|>
literal|0
condition|)
block|{
comment|/* Handle borderline cases... */
if|if
condition|(
name|f
operator|==
name|SCR_CW
condition|)
block|{
comment|/* Close window, but it's not open */
name|ft_win
operator|=
literal|0
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|f
operator|==
name|SCR_EM
operator|||
operator|(
name|f
operator|==
name|SCR_PT
operator|&&
name|c
operator|==
literal|'E'
operator|)
condition|)
block|{
comment|/* Fatal error before window open */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoc
argument_list|(
literal|'?'
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
comment|/* Regular display */
block|}
block|}
if|if
condition|(
name|cinit
operator|==
literal|0
condition|)
block|{
comment|/* Only call initscr() once */
name|cendw
operator|=
literal|1
expr_stmt|;
comment|/* New window needs repainting */
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
operator|!
name|initscr
argument_list|()
condition|)
block|{
comment|/* Oops, can't initialize window? */
comment|/*   In fact, this doesn't happen.  "man curses" says initscr() halts the   entire program if it fails, which is true on the systems where I've   tested it.  It will fail if your terminal type is not known to it.   That's why SET FILE DISPLAY FULLSCREEN calls tgetent() to make sure the   terminal type is known before allowing a curses display. */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"CURSES INITSCR ERROR\r\n"
argument_list|)
expr_stmt|;
name|fdispla
operator|=
name|XYFD_R
expr_stmt|;
comment|/* Go back to regular display */
return|return;
block|}
else|else
block|{
name|cinit
operator|++
expr_stmt|;
comment|/* Window initialized ok */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"CURSES INITSCR OK"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|/* Save some memory. */
ifdef|#
directive|ifdef
name|CK_NEWTERM
comment|/* (From Andy Fyfe<andy@vlsi.cs.caltech.edu>) 	   System V curses seems to reserve the right to alter the buffering 	   on the output FILE* without restoring it.  Fortunately System V 	   curses provides newterm(), an alternative to initscr(), that 	   allows us to specify explicitly the terminal type and input and 	   output FILE pointers.  Thus we duplicate stdout, and let curses 	   have the copy.  The original remains unaltered.  Unfortunately, 	   newterm() seems to be particular to System V. 	*/
name|s
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ck_fd
operator|<
literal|0
condition|)
block|{
name|ck_fd
operator|=
name|dup
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|)
expr_stmt|;
name|ck_stdout
operator|=
operator|(
name|ck_fd
operator|>=
literal|0
operator|)
condition|?
name|fdopen
argument_list|(
name|ck_fd
argument_list|,
literal|"w"
argument_list|)
else|:
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|ck_stdout
operator|==
name|NULL
operator|||
name|newterm
argument_list|(
name|s
argument_list|,
name|ck_stdout
argument_list|,
name|stdin
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Fullscreen display not supported for terminal type: %s\r\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fdispla
operator|=
name|XYFD_R
expr_stmt|;
comment|/* Go back to regular display */
return|return;
block|}
else|#
directive|else
name|initscr
argument_list|()
expr_stmt|;
comment|/* Initialize curses. */
endif|#
directive|endif
comment|/* CK_NEWTERM */
name|cinit
operator|++
expr_stmt|;
comment|/* Remember curses was initialized. */
endif|#
directive|endif
comment|/* COMMENT */
block|}
name|ft_win
operator|=
literal|1
expr_stmt|;
comment|/* Window is open */
if|if
condition|(
name|cendw
condition|)
block|{
comment|/* endwin() was called previously */
ifdef|#
directive|ifdef
name|VMS
name|initscr
argument_list|()
expr_stmt|;
comment|/* (or should have been!) */
name|clear
argument_list|()
expr_stmt|;
name|touchwin
argument_list|(
name|stdscr
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* All others... */
name|clear
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
name|move
argument_list|(
name|CW_BAN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Display the banner */
if|if
condition|(
operator|*
name|myhost
condition|)
name|printw
argument_list|(
literal|"%s, %s"
argument_list|,
name|versio
argument_list|,
operator|(
name|char
operator|*
operator|)
name|myhost
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|versio
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_DIR
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Current Directory: %s"
argument_list|,
name|zgtdir
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|network
condition|)
block|{
name|move
argument_list|(
name|CW_LIN
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Remote Host: %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|move
argument_list|(
name|CW_LIN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Communication Device: %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
block|}
name|move
argument_list|(
name|CW_SPD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Communication Speed: "
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_SPD
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Speed */
if|if
condition|(
name|network
condition|)
block|{
name|printw
argument_list|(
literal|"(network)"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|speed
operator|<
literal|0L
condition|)
name|speed
operator|=
name|ttgspd
argument_list|()
expr_stmt|;
if|if
condition|(
name|speed
operator|>
literal|0L
condition|)
block|{
if|if
condition|(
name|speed
operator|==
literal|8880
condition|)
name|printw
argument_list|(
literal|"75/1200"
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"%ld"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
block|}
else|else
name|printw
argument_list|(
literal|"unknown"
argument_list|)
expr_stmt|;
block|}
name|move
argument_list|(
name|CW_PAR
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Parity: %s"
argument_list|,
name|parnam
argument_list|(
operator|(
name|char
operator|)
name|parity
argument_list|)
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_TYP
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"File Type:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_SIZ
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"File Size:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PCD
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Percent Done:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_TR
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Estimated Time Left:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_WS
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Window Slots:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PT
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Packet Type:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PC
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Packet Count:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PL
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Packet Length:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PR
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Packet Retry Count:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_PB
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Packet Block Check:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Last Error:"
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_MSG
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Last Message:"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ATTSV
ifndef|#
directive|ifndef
name|aegis
ifndef|#
directive|ifndef
name|datageneral
define|#
directive|define
name|CK_NEED_SIG
endif|#
directive|endif
comment|/* datageneral */
endif|#
directive|endif
comment|/* aegis */
endif|#
directive|endif
comment|/* ATTSV */
ifdef|#
directive|ifdef
name|POSIX
ifndef|#
directive|ifndef
name|CK_NEED_SIG
define|#
directive|define
name|CK_NEED_SIG
endif|#
directive|endif
comment|/* CK_NEED_SIG */
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|CK_NEED_SIG
name|move
argument_list|(
name|CW_INT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"<%s>X to cancel file,<%s>Z to cancel group,<%s><CR> to resend packet"
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|CW_INT
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"<%s>E to send Error packet, or Ctrl-C to quit immediately."
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|move
argument_list|(
name|CW_INT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
name|printw
argument_list|(
literal|"X to cancel file, Z to cancel group,<Enter> to resend packet,"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printw
argument_list|(
literal|"X to cancel file, Z to cancel group,<CR> to resend packet,"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|move
argument_list|(
name|CW_INT
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"E to send Error packet, or Ctrl-C to quit immediately."
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CK_NEED_SIG */
name|refresh
argument_list|()
expr_stmt|;
name|cendw
operator|=
literal|0
expr_stmt|;
block|}
name|len
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Length of argument string */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"SCREENC switch"
argument_list|,
literal|""
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|/* Handle our function code */
switch|switch
condition|(
name|f
condition|)
block|{
case|case
name|SCR_FN
case|:
comment|/* Filename */
name|fsiz
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* Invalidate previous file size */
name|move
argument_list|(
name|CW_PCD
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Erase percent done from last time */
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_SIZ
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Erase file size from last time */
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* And last error message */
name|clrtoeol
argument_list|()
expr_stmt|;
if|if
condition|(
name|what
operator|==
name|W_SEND
condition|)
block|{
comment|/* If we're sending... */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|13
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Sending:"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|what
operator|==
name|W_RECV
condition|)
block|{
comment|/* If we're receiving... */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Receiving:"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* If we don't know... */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|/* (should never see this) */
name|printw
argument_list|(
literal|"File Name:"
argument_list|)
expr_stmt|;
block|}
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Display the filename */
if|if
condition|(
name|len
operator|>
literal|57
condition|)
block|{
name|printw
argument_list|(
literal|"%.54s.."
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|len
operator|=
literal|57
expr_stmt|;
block|}
else|else
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|q
operator|=
name|len
expr_stmt|;
comment|/* Remember name length for later */
name|clrtoeol
argument_list|()
expr_stmt|;
name|scrft
argument_list|()
expr_stmt|;
comment|/* Display file type */
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_AN
case|:
comment|/* File as-name */
if|if
condition|(
name|q
operator|+
name|len
operator|<
literal|58
condition|)
block|{
comment|/* Will fit */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|22
operator|+
name|q
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|" => %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Too long */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Overwrite previous name */
name|q
operator|=
literal|0
expr_stmt|;
name|len
operator|=
literal|54
expr_stmt|;
name|printw
argument_list|(
literal|" => %.51s.."
argument_list|,
name|s
argument_list|)
expr_stmt|;
comment|/* Truncate */
block|}
name|q
operator|+=
name|len
operator|+
literal|4
expr_stmt|;
comment|/* Remember horizontal position */
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_FS
case|:
comment|/* File size */
name|fsiz
operator|=
name|n
expr_stmt|;
name|move
argument_list|(
name|CW_SIZ
argument_list|,
literal|22
argument_list|)
expr_stmt|;
if|if
condition|(
name|fsiz
operator|>
operator|-
literal|1L
condition|)
name|printw
argument_list|(
literal|"%ld"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|scrft
argument_list|()
expr_stmt|;
comment|/* File type */
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_PT
case|:
comment|/* Packet type or pseudotype */
if|if
condition|(
name|spackets
operator|<
literal|5
condition|)
block|{
comment|/* Things that won't change after the 4th packet */
name|move
argument_list|(
name|CW_PAR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|parnam
argument_list|(
operator|(
name|char
operator|)
name|parity
argument_list|)
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_PB
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Block check on this packet */
if|if
condition|(
name|bctu
operator|==
literal|4
condition|)
name|printw
argument_list|(
literal|"B"
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"%d"
argument_list|,
name|bctu
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
block|}
name|x
operator|=
operator|(
name|what
operator|==
name|W_RECV
operator|)
condition|?
comment|/* Packet length */
name|rpktl
operator|+
literal|1
else|:
name|spktl
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|x
operator|!=
name|oldlen
condition|)
block|{
comment|/* But only if it changed. */
name|move
argument_list|(
name|CW_PL
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%d"
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|oldlen
operator|=
name|x
expr_stmt|;
block|}
name|move
argument_list|(
name|CW_PC
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Packet count (always). */
name|printw
argument_list|(
literal|"%d"
argument_list|,
name|spackets
argument_list|)
expr_stmt|;
comment|/* WARNING: this can slow us way */
name|clrtoeol
argument_list|()
expr_stmt|;
comment|/* down with short packets. */
if|if
condition|(
name|wcur
operator|!=
name|oldwin
condition|)
block|{
comment|/* Window slots, if changed. */
name|move
argument_list|(
name|CW_WS
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%d of %d"
argument_list|,
name|wcur
argument_list|,
name|wslotr
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|oldwin
operator|=
name|wcur
expr_stmt|;
block|}
if|if
condition|(
name|retrans
operator|!=
name|oldtry
condition|)
block|{
comment|/* Retry count, if changed */
name|move
argument_list|(
name|CW_PR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%d"
argument_list|,
name|retrans
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|oldtry
operator|=
name|retrans
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|!=
name|oldtyp
operator|&&
name|c
operator|!=
literal|'Y'
operator|&&
name|c
operator|!=
literal|'N'
condition|)
block|{
comment|/* Sender's packet type */
name|move
argument_list|(
name|CW_PT
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%c"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|oldtyp
operator|=
name|c
expr_stmt|;
block|}
switch|switch
condition|(
name|c
condition|)
block|{
comment|/* Now handle specific packet types */
case|case
literal|'S'
case|:
comment|/* Beginning of transfer */
name|fcnt
operator|=
name|fbyt
operator|=
literal|0L
expr_stmt|;
comment|/* Clear counters */
break|break;
case|case
literal|'D'
case|:
comment|/* Data packet */
if|if
condition|(
name|fsiz
operator|>
literal|0L
condition|)
block|{
comment|/* Show percent done if known */
name|long
name|s
decl_stmt|,
name|x
decl_stmt|;
name|oldpct
operator|=
name|pct
expr_stmt|;
comment|/* Remember previous percent */
name|pct
operator|=
operator|(
name|fsiz
operator|>
literal|99L
operator|)
condition|?
operator|(
name|ffc
operator|/
operator|(
name|fsiz
operator|/
literal|100L
operator|)
operator|)
else|:
literal|0L
expr_stmt|;
comment|/* New one */
if|if
condition|(
name|pct
operator|>
literal|100L
operator|||
comment|/* Allow expansion */
name|oldpct
operator|==
literal|99L
operator|&&
name|pct
operator|<
literal|0L
condition|)
comment|/* other boundary conditions */
name|pct
operator|=
literal|100L
expr_stmt|;
if|if
condition|(
name|pct
operator|!=
name|oldpct
condition|)
block|{
comment|/* Only do this 100 times per file */
name|move
argument_list|(
name|CW_PCD
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%ld"
argument_list|,
name|pct
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
comment|/* Time remaining for this file */
name|s
operator|=
call|(
name|long
call|)
argument_list|(
operator|(
name|unsigned
operator|)
name|gtimer
argument_list|()
operator|-
name|fsecs
argument_list|)
expr_stmt|;
comment|/* Secs so far */
if|if
condition|(
name|s
operator|>
literal|0L
condition|)
block|{
comment|/* 			  Time remaining must be calculated using the smallest 			  possible quantities, to prevent overflow: 			    (seconds_so_far * percent_left) / percent_done. 			  And avoid divide_by_zero. 			*/
name|x
operator|=
operator|(
name|pct
operator|>
literal|0L
operator|)
condition|?
operator|(
operator|(
name|s
operator|*
operator|(
literal|100
operator|-
name|pct
operator|)
operator|)
operator|/
name|pct
operator|)
else|:
operator|-
literal|1L
expr_stmt|;
if|if
condition|(
name|x
operator|>
operator|-
literal|1L
condition|)
block|{
name|move
argument_list|(
name|CW_TR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|hhmmss
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
break|break;
case|case
literal|'E'
case|:
comment|/* Error packet */
ifdef|#
directive|ifdef
name|COMMENT
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Print its data field */
if|if
condition|(
operator|*
name|s
condition|)
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
name|fcnt
operator|=
name|fbyt
operator|=
literal|0
expr_stmt|;
comment|/* So no bytes for this file */
break|break;
case|case
literal|'Q'
case|:
comment|/* Crunched packet */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Damaged Packet"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'T'
case|:
comment|/* Timeout */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Timeout"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
break|break;
default|default:
comment|/* Others, do nothing */
break|break;
block|}
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_ST
case|:
comment|/* File transfer status */
name|move
argument_list|(
name|CW_PCD
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Update percent done */
if|if
condition|(
name|c
operator|==
name|ST_OK
condition|)
block|{
comment|/* OK, print 100 % */
name|pct
operator|=
literal|100
expr_stmt|;
name|printw
argument_list|(
literal|"100"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|fsiz
operator|>
literal|0L
condition|)
comment|/* Not OK, update final percent */
name|printw
argument_list|(
literal|"%ld"
argument_list|,
operator|(
name|ffc
operator|*
literal|100L
operator|)
operator|/
name|fsiz
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_MSG
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Remove any previous message */
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_TR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
comment|/* Print new status message */
case|case
name|ST_OK
case|:
comment|/* Transfer OK */
name|fcnt
operator|++
expr_stmt|;
comment|/* Count this file */
if|if
condition|(
name|ffc
operator|>
literal|0L
condition|)
comment|/* For some reason ffc is off by 1 */
name|fbyt
operator|+=
name|ffc
operator|-
literal|1L
expr_stmt|;
comment|/* Count its bytes */
name|move
argument_list|(
name|CW_MSG
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Transfer OK"
argument_list|)
expr_stmt|;
comment|/* Say Transfer was OK */
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_DISC
case|:
comment|/* Discarded */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"File discarded"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_INT
case|:
comment|/* Interrupted */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Transfer interrupted"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_SKIP
case|:
comment|/* Skipped */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"File skipped"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_ERR
case|:
comment|/* Error message */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_REFU
case|:
comment|/* Refused */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
name|printw
argument_list|(
literal|"Refused, %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"Refused"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|ST_INC
case|:
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"Incomplete"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
default|default:
comment|/* Bad call */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"*** screen() called with bad status ***"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
block|}
case|case
name|SCR_TC
case|:
comment|/* Transaction complete */
name|move
argument_list|(
name|CW_MSG
argument_list|,
literal|22
argument_list|)
expr_stmt|;
comment|/* Print statistics in message line */
if|if
condition|(
name|tsecs
operator|>
literal|0
condition|)
name|printw
argument_list|(
literal|"Files: %ld, Total Bytes: %ld, %ld cps"
argument_list|,
name|fcnt
argument_list|,
name|fbyt
argument_list|,
operator|(
operator|(
name|fbyt
operator|*
literal|10L
operator|)
operator|/
operator|(
name|long
operator|)
name|tsecs
operator|)
operator|/
literal|10L
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"Files: %ld, Total Bytes: %ld"
argument_list|,
name|fcnt
argument_list|,
name|fbyt
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|CW_TR
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"       Elapsed Time: %s"
argument_list|,
name|hhmmss
argument_list|(
operator|(
name|long
operator|)
name|tsecs
argument_list|)
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
literal|23
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
comment|/* Clear instructions lines */
name|move
argument_list|(
literal|22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
comment|/* to make room for prompt. */
name|refresh
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|VMSCURSE
name|endwin
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* VMSCURSE */
name|pct
operator|=
literal|100
expr_stmt|;
name|oldpct
operator|=
literal|0
expr_stmt|;
comment|/* Reset these for next time. */
name|oldtyp
operator|=
literal|0
expr_stmt|;
name|oldwin
operator|=
operator|-
literal|1
expr_stmt|;
name|oldtry
operator|=
operator|-
literal|1
expr_stmt|;
name|oldlen
operator|=
operator|-
literal|1
expr_stmt|;
name|cendw
operator|=
literal|1
expr_stmt|;
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* Close window, then beep. */
name|ft_win
operator|=
literal|0
expr_stmt|;
comment|/* Window closed. */
return|return;
case|case
name|SCR_EM
case|:
comment|/* Error packet (fatal) */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"? %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_QE
case|:
comment|/* Quantity equals */
case|case
name|SCR_TU
case|:
comment|/* Undelimited text */
case|case
name|SCR_TN
case|:
comment|/* Text delimited at start */
case|case
name|SCR_TZ
case|:
comment|/* Text delimited at end */
return|return;
comment|/* (ignored in fullscreen display) */
case|case
name|SCR_XD
case|:
comment|/* X-packet data */
name|move
argument_list|(
name|CW_NAM
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
case|case
name|SCR_CW
case|:
comment|/* Close Window */
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
literal|23
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
literal|22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
name|pct
operator|=
literal|100
expr_stmt|;
name|oldpct
operator|=
literal|0
expr_stmt|;
comment|/* Reset these for next time. */
name|oldtyp
operator|=
literal|0
expr_stmt|;
name|oldwin
operator|=
operator|-
literal|1
expr_stmt|;
name|oldtry
operator|=
operator|-
literal|1
expr_stmt|;
name|oldlen
operator|=
operator|-
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|VMSCURSE
name|endwin
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* VMSCURSE */
name|ft_win
operator|=
literal|0
expr_stmt|;
comment|/* Flag that window is closed. */
name|cendw
operator|=
literal|1
expr_stmt|;
return|return;
default|default:
comment|/* Bad call */
name|move
argument_list|(
name|CW_ERR
argument_list|,
literal|22
argument_list|)
expr_stmt|;
name|printw
argument_list|(
literal|"*** screen() called with bad function code ***"
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_CURSES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

end_unit

