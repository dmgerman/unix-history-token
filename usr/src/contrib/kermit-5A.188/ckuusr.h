begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U U S R . H  --  Symbol definitions for C-Kermit ckuus*.c modules  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKUUSR_H
end_ifndef

begin_define
define|#
directive|define
name|CKUUSR_H
end_define

begin_include
include|#
directive|include
file|"ckucmd.h"
end_include

begin_comment
comment|/* Get symbols from command package */
end_comment

begin_comment
comment|/* Sizes of things */
end_comment

begin_define
define|#
directive|define
name|FSPECL
value|300
end_define

begin_comment
comment|/* Max length for MSEND/GET string */
end_comment

begin_define
define|#
directive|define
name|VNAML
value|20
end_define

begin_comment
comment|/* Max length for variable name */
end_comment

begin_define
define|#
directive|define
name|FORDEPTH
value|10
end_define

begin_comment
comment|/* Maximum depth of nested FOR loops */
end_comment

begin_define
define|#
directive|define
name|GVARS
value|126
end_define

begin_comment
comment|/* Highest global var allowed */
end_comment

begin_define
define|#
directive|define
name|MAXTAKE
value|30
end_define

begin_comment
comment|/* Maximum nesting of TAKE files */
end_comment

begin_define
define|#
directive|define
name|MACLEVEL
value|50
end_define

begin_comment
comment|/* Maximum nesting for macros */
end_comment

begin_define
define|#
directive|define
name|NARGS
value|10
end_define

begin_comment
comment|/* Max number of macro arguments */
end_comment

begin_define
define|#
directive|define
name|LINBUFSIZ
value|CMDBL+10
end_define

begin_comment
comment|/* Size of line[] buffer */
end_comment

begin_define
define|#
directive|define
name|INPBUFSIZ
value|257
end_define

begin_comment
comment|/* Size of INPUT buffer */
end_comment

begin_define
define|#
directive|define
name|CMDSTKL
value|( MACLEVEL + MAXTAKE + 2)
end_define

begin_comment
comment|/* Command stack depth */
end_comment

begin_define
define|#
directive|define
name|MAC_MAX
value|256
end_define

begin_comment
comment|/* Maximum number of macros */
end_comment

begin_define
define|#
directive|define
name|MSENDMAX
value|100
end_define

begin_comment
comment|/* Number of filespecs for MSEND */
end_comment

begin_struct
struct|struct
name|cmdptr
block|{
comment|/* Command stack structure */
name|int
name|src
decl_stmt|;
comment|/* Command Source */
name|int
name|lvl
decl_stmt|;
comment|/* Current TAKE or DO level */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mtab
block|{
comment|/* Macro table, like keyword table */
name|char
modifier|*
name|kwd
decl_stmt|;
comment|/* But with pointers for vals */
name|char
modifier|*
name|mval
decl_stmt|;
comment|/* instead of ints. */
name|short
name|flgs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Name of C-Kermit program initialization file. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_define
define|#
directive|define
name|KERMRC
value|"CKERMIT.INI"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|KERMRC
value|"ckermit.ini"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_define
define|#
directive|define
name|KERMRC
value|".kermrc"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_define
define|#
directive|define
name|KERMRC
value|".kermrc"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERMRC
value|"CKERMIT.INI"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vms */
end_comment

begin_comment
comment|/* Includes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_comment
comment|/* why? */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_comment
comment|/* Symbols for command source */
end_comment

begin_define
define|#
directive|define
name|CMD_KB
value|0
end_define

begin_comment
comment|/* KeyBoard or standard input */
end_comment

begin_define
define|#
directive|define
name|CMD_TF
value|1
end_define

begin_comment
comment|/* TAKE command File */
end_comment

begin_define
define|#
directive|define
name|CMD_MD
value|2
end_define

begin_comment
comment|/* Macro Definition */
end_comment

begin_comment
comment|/* Top Level Commands */
end_comment

begin_comment
comment|/* Values associated with top-level commands must be 0 or greater. */
end_comment

begin_define
define|#
directive|define
name|XXBYE
value|0
end_define

begin_comment
comment|/* BYE */
end_comment

begin_define
define|#
directive|define
name|XXCLE
value|1
end_define

begin_comment
comment|/* CLEAR */
end_comment

begin_define
define|#
directive|define
name|XXCLO
value|2
end_define

begin_comment
comment|/* CLOSE */
end_comment

begin_define
define|#
directive|define
name|XXCON
value|3
end_define

begin_comment
comment|/* CONNECT */
end_comment

begin_define
define|#
directive|define
name|XXCPY
value|4
end_define

begin_comment
comment|/* COPY */
end_comment

begin_define
define|#
directive|define
name|XXCWD
value|5
end_define

begin_comment
comment|/* CWD (Change Working Directory) */
end_comment

begin_define
define|#
directive|define
name|XXDEF
value|6
end_define

begin_comment
comment|/* DEFINE (a command macro) */
end_comment

begin_define
define|#
directive|define
name|XXDEL
value|7
end_define

begin_comment
comment|/* (Local) DELETE */
end_comment

begin_define
define|#
directive|define
name|XXDIR
value|8
end_define

begin_comment
comment|/* (Local) DIRECTORY */
end_comment

begin_define
define|#
directive|define
name|XXDIS
value|9
end_define

begin_comment
comment|/* DISABLE<-- changed from DISCONNECT! */
end_comment

begin_define
define|#
directive|define
name|XXECH
value|10
end_define

begin_comment
comment|/* ECHO */
end_comment

begin_define
define|#
directive|define
name|XXEXI
value|11
end_define

begin_comment
comment|/* EXIT */
end_comment

begin_define
define|#
directive|define
name|XXFIN
value|12
end_define

begin_comment
comment|/* FINISH */
end_comment

begin_define
define|#
directive|define
name|XXGET
value|13
end_define

begin_comment
comment|/* GET */
end_comment

begin_define
define|#
directive|define
name|XXHLP
value|14
end_define

begin_comment
comment|/* HELP */
end_comment

begin_define
define|#
directive|define
name|XXINP
value|15
end_define

begin_comment
comment|/* INPUT */
end_comment

begin_define
define|#
directive|define
name|XXLOC
value|16
end_define

begin_comment
comment|/* LOCAL */
end_comment

begin_define
define|#
directive|define
name|XXLOG
value|17
end_define

begin_comment
comment|/* LOG */
end_comment

begin_define
define|#
directive|define
name|XXMAI
value|18
end_define

begin_comment
comment|/* MAIL */
end_comment

begin_define
define|#
directive|define
name|XXMOU
value|19
end_define

begin_comment
comment|/* (Local) MOUNT */
end_comment

begin_define
define|#
directive|define
name|XXMSG
value|20
end_define

begin_comment
comment|/* (Local) MESSAGE */
end_comment

begin_define
define|#
directive|define
name|XXOUT
value|21
end_define

begin_comment
comment|/* OUTPUT */
end_comment

begin_define
define|#
directive|define
name|XXPAU
value|22
end_define

begin_comment
comment|/* PAUSE */
end_comment

begin_define
define|#
directive|define
name|XXPRI
value|23
end_define

begin_comment
comment|/* (Local) PRINT */
end_comment

begin_define
define|#
directive|define
name|XXQUI
value|24
end_define

begin_comment
comment|/* QUIT */
end_comment

begin_define
define|#
directive|define
name|XXREC
value|25
end_define

begin_comment
comment|/* RECEIVE */
end_comment

begin_define
define|#
directive|define
name|XXREM
value|26
end_define

begin_comment
comment|/* REMOTE */
end_comment

begin_define
define|#
directive|define
name|XXREN
value|27
end_define

begin_comment
comment|/* (Local) RENAME */
end_comment

begin_define
define|#
directive|define
name|XXSEN
value|28
end_define

begin_comment
comment|/* SEND */
end_comment

begin_define
define|#
directive|define
name|XXSER
value|29
end_define

begin_comment
comment|/* SERVER */
end_comment

begin_define
define|#
directive|define
name|XXSET
value|30
end_define

begin_comment
comment|/* SET */
end_comment

begin_define
define|#
directive|define
name|XXSHE
value|31
end_define

begin_comment
comment|/* Command for SHELL */
end_comment

begin_define
define|#
directive|define
name|XXSHO
value|32
end_define

begin_comment
comment|/* SHOW */
end_comment

begin_define
define|#
directive|define
name|XXSPA
value|33
end_define

begin_comment
comment|/* (Local) SPACE */
end_comment

begin_define
define|#
directive|define
name|XXSTA
value|34
end_define

begin_comment
comment|/* STATISTICS */
end_comment

begin_define
define|#
directive|define
name|XXSUB
value|35
end_define

begin_comment
comment|/* (Local) SUBMIT */
end_comment

begin_define
define|#
directive|define
name|XXTAK
value|36
end_define

begin_comment
comment|/* TAKE */
end_comment

begin_define
define|#
directive|define
name|XXTRA
value|37
end_define

begin_comment
comment|/* TRANSMIT */
end_comment

begin_define
define|#
directive|define
name|XXTYP
value|38
end_define

begin_comment
comment|/* (Local) TYPE */
end_comment

begin_define
define|#
directive|define
name|XXWHO
value|39
end_define

begin_comment
comment|/* (Local) WHO */
end_comment

begin_define
define|#
directive|define
name|XXDIAL
value|40
end_define

begin_comment
comment|/* (Local) DIAL */
end_comment

begin_define
define|#
directive|define
name|XXLOGI
value|41
end_define

begin_comment
comment|/* (Local) SCRIPT */
end_comment

begin_define
define|#
directive|define
name|XXCOM
value|42
end_define

begin_comment
comment|/* Comment */
end_comment

begin_define
define|#
directive|define
name|XXHAN
value|43
end_define

begin_comment
comment|/* HANGUP */
end_comment

begin_define
define|#
directive|define
name|XXXLA
value|44
end_define

begin_comment
comment|/* TRANSLATE */
end_comment

begin_define
define|#
directive|define
name|XXIF
value|45
end_define

begin_comment
comment|/* IF */
end_comment

begin_define
define|#
directive|define
name|XXLBL
value|46
end_define

begin_comment
comment|/* label */
end_comment

begin_define
define|#
directive|define
name|XXGOTO
value|47
end_define

begin_comment
comment|/* GOTO */
end_comment

begin_define
define|#
directive|define
name|XXEND
value|48
end_define

begin_comment
comment|/* END */
end_comment

begin_define
define|#
directive|define
name|XXSTO
value|49
end_define

begin_comment
comment|/* STOP */
end_comment

begin_define
define|#
directive|define
name|XXDO
value|50
end_define

begin_comment
comment|/* DO */
end_comment

begin_define
define|#
directive|define
name|XXPWD
value|51
end_define

begin_comment
comment|/* PWD */
end_comment

begin_define
define|#
directive|define
name|XXTES
value|52
end_define

begin_comment
comment|/* TEST */
end_comment

begin_define
define|#
directive|define
name|XXASK
value|53
end_define

begin_comment
comment|/* ASK */
end_comment

begin_define
define|#
directive|define
name|XXASKQ
value|54
end_define

begin_comment
comment|/* ASKQ */
end_comment

begin_define
define|#
directive|define
name|XXASS
value|55
end_define

begin_comment
comment|/* ASSIGN */
end_comment

begin_define
define|#
directive|define
name|XXREI
value|56
end_define

begin_comment
comment|/* REINPUT */
end_comment

begin_define
define|#
directive|define
name|XXINC
value|57
end_define

begin_comment
comment|/* INCREMENT */
end_comment

begin_define
define|#
directive|define
name|XXDEC
value|59
end_define

begin_comment
comment|/* DECREMENT */
end_comment

begin_define
define|#
directive|define
name|XXELS
value|60
end_define

begin_comment
comment|/* ELSE */
end_comment

begin_define
define|#
directive|define
name|XXEXE
value|61
end_define

begin_comment
comment|/* EXECUTE */
end_comment

begin_define
define|#
directive|define
name|XXWAI
value|62
end_define

begin_comment
comment|/* WAIT */
end_comment

begin_define
define|#
directive|define
name|XXVER
value|63
end_define

begin_comment
comment|/* VERSION */
end_comment

begin_define
define|#
directive|define
name|XXENA
value|64
end_define

begin_comment
comment|/* ENABLE */
end_comment

begin_define
define|#
directive|define
name|XXWRI
value|65
end_define

begin_comment
comment|/* WRITE */
end_comment

begin_define
define|#
directive|define
name|XXCLS
value|66
end_define

begin_comment
comment|/* CLS (clear screen) */
end_comment

begin_define
define|#
directive|define
name|XXRET
value|67
end_define

begin_comment
comment|/* RETURN */
end_comment

begin_define
define|#
directive|define
name|XXOPE
value|68
end_define

begin_comment
comment|/* OPEN */
end_comment

begin_define
define|#
directive|define
name|XXREA
value|69
end_define

begin_comment
comment|/* READ */
end_comment

begin_define
define|#
directive|define
name|XXON
value|70
end_define

begin_comment
comment|/* ON */
end_comment

begin_define
define|#
directive|define
name|XXDCL
value|71
end_define

begin_comment
comment|/* DECLARE */
end_comment

begin_define
define|#
directive|define
name|XXBEG
value|72
end_define

begin_comment
comment|/* BEGIN (not used) */
end_comment

begin_define
define|#
directive|define
name|XXFOR
value|72
end_define

begin_comment
comment|/* FOR */
end_comment

begin_define
define|#
directive|define
name|XXWHI
value|73
end_define

begin_comment
comment|/* WHILE */
end_comment

begin_define
define|#
directive|define
name|XXIFX
value|74
end_define

begin_comment
comment|/* Extended IF */
end_comment

begin_define
define|#
directive|define
name|XXCMS
value|75
end_define

begin_comment
comment|/* SEND from command output (not yet) */
end_comment

begin_define
define|#
directive|define
name|XXCMR
value|76
end_define

begin_comment
comment|/* RECEIVE to a command's input (not yet) */
end_comment

begin_define
define|#
directive|define
name|XXCMG
value|77
end_define

begin_comment
comment|/* GET to a command's input (not yet) */
end_comment

begin_define
define|#
directive|define
name|XXSUS
value|78
end_define

begin_comment
comment|/* SUSPEND */
end_comment

begin_define
define|#
directive|define
name|XXERR
value|79
end_define

begin_comment
comment|/* ERROR */
end_comment

begin_define
define|#
directive|define
name|XXMSE
value|80
end_define

begin_comment
comment|/* MSEND */
end_comment

begin_define
define|#
directive|define
name|XXBUG
value|81
end_define

begin_comment
comment|/* BUG */
end_comment

begin_define
define|#
directive|define
name|XXPAD
value|82
end_define

begin_comment
comment|/* PAD (as in X.25 PAD) SUNX25 */
end_comment

begin_define
define|#
directive|define
name|XXRED
value|83
end_define

begin_comment
comment|/* REDIAL */
end_comment

begin_define
define|#
directive|define
name|XXGTA
value|84
end_define

begin_comment
comment|/* _getargs (invisible internal) */
end_comment

begin_define
define|#
directive|define
name|XXPTA
value|85
end_define

begin_comment
comment|/* _putargs (invisible internal) */
end_comment

begin_define
define|#
directive|define
name|XXGOK
value|86
end_define

begin_comment
comment|/* GETOK - Ask for YES/NO */
end_comment

begin_define
define|#
directive|define
name|XXTEL
value|87
end_define

begin_comment
comment|/* TELNET */
end_comment

begin_define
define|#
directive|define
name|XXASX
value|88
end_define

begin_comment
comment|/* _ASSIGN (evaluates var name) */
end_comment

begin_define
define|#
directive|define
name|XXDFX
value|89
end_define

begin_comment
comment|/* _DEFINE (evaluates var name) */
end_comment

begin_define
define|#
directive|define
name|XXPNG
value|90
end_define

begin_comment
comment|/* PING (for TCP/IP) */
end_comment

begin_define
define|#
directive|define
name|XXINT
value|91
end_define

begin_comment
comment|/* INTRODUCTION */
end_comment

begin_define
define|#
directive|define
name|XXCHK
value|92
end_define

begin_comment
comment|/* CHECK (a feature) */
end_comment

begin_define
define|#
directive|define
name|XXMSL
value|93
end_define

begin_comment
comment|/* MSLEEP, MPAUSE (millisecond sleep) */
end_comment

begin_comment
comment|/* IF conditions */
end_comment

begin_define
define|#
directive|define
name|XXIFCO
value|0
end_define

begin_comment
comment|/* IF COUNT */
end_comment

begin_define
define|#
directive|define
name|XXIFER
value|1
end_define

begin_comment
comment|/* IF ERRORLEVEL */
end_comment

begin_define
define|#
directive|define
name|XXIFEX
value|2
end_define

begin_comment
comment|/* IF EXIST */
end_comment

begin_define
define|#
directive|define
name|XXIFFA
value|3
end_define

begin_comment
comment|/* IF FAILURE */
end_comment

begin_define
define|#
directive|define
name|XXIFSU
value|4
end_define

begin_comment
comment|/* IF SUCCESS */
end_comment

begin_define
define|#
directive|define
name|XXIFNO
value|5
end_define

begin_comment
comment|/* IF NOT */
end_comment

begin_define
define|#
directive|define
name|XXIFDE
value|6
end_define

begin_comment
comment|/* IF DEFINED */
end_comment

begin_define
define|#
directive|define
name|XXIFEQ
value|7
end_define

begin_comment
comment|/* IF EQUAL (strings) */
end_comment

begin_define
define|#
directive|define
name|XXIFAE
value|8
end_define

begin_comment
comment|/* IF = (numbers) */
end_comment

begin_define
define|#
directive|define
name|XXIFLT
value|9
end_define

begin_comment
comment|/* IF< (numbers) */
end_comment

begin_define
define|#
directive|define
name|XXIFGT
value|10
end_define

begin_comment
comment|/* IF> (numbers) */
end_comment

begin_define
define|#
directive|define
name|XXIFLL
value|11
end_define

begin_comment
comment|/* IF Lexically Less Than (strings) */
end_comment

begin_define
define|#
directive|define
name|XXIFLG
value|12
end_define

begin_comment
comment|/* IF Lexically Greater Than (strings) */
end_comment

begin_define
define|#
directive|define
name|XXIFEO
value|13
end_define

begin_comment
comment|/* IF EOF (READ file) */
end_comment

begin_define
define|#
directive|define
name|XXIFBG
value|14
end_define

begin_comment
comment|/* IF BACKGROUND */
end_comment

begin_define
define|#
directive|define
name|XXIFNU
value|15
end_define

begin_comment
comment|/* IF NUMERIC */
end_comment

begin_define
define|#
directive|define
name|XXIFFG
value|16
end_define

begin_comment
comment|/* IF FOREGROUND */
end_comment

begin_comment
comment|/* SET parameters */
end_comment

begin_define
define|#
directive|define
name|XYBREA
value|0
end_define

begin_comment
comment|/* BREAK simulation */
end_comment

begin_define
define|#
directive|define
name|XYCHKT
value|1
end_define

begin_comment
comment|/* Block check type */
end_comment

begin_define
define|#
directive|define
name|XYDEBU
value|2
end_define

begin_comment
comment|/* Debugging */
end_comment

begin_define
define|#
directive|define
name|XYDELA
value|3
end_define

begin_comment
comment|/* Delay */
end_comment

begin_define
define|#
directive|define
name|XYDUPL
value|4
end_define

begin_comment
comment|/* Duplex */
end_comment

begin_define
define|#
directive|define
name|XYEOL
value|5
end_define

begin_comment
comment|/* End-Of-Line (packet terminator) */
end_comment

begin_define
define|#
directive|define
name|XYESC
value|6
end_define

begin_comment
comment|/* Escape character */
end_comment

begin_define
define|#
directive|define
name|XYFILE
value|7
end_define

begin_comment
comment|/* File Parameters */
end_comment

begin_comment
comment|/* (this space available) */
end_comment

begin_define
define|#
directive|define
name|XYFLOW
value|9
end_define

begin_comment
comment|/* Flow Control */
end_comment

begin_define
define|#
directive|define
name|XYHAND
value|10
end_define

begin_comment
comment|/* Handshake */
end_comment

begin_define
define|#
directive|define
name|XYIFD
value|11
end_define

begin_comment
comment|/* Incomplete File Disposition */
end_comment

begin_define
define|#
directive|define
name|XYIMAG
value|12
end_define

begin_comment
comment|/* "Image Mode" */
end_comment

begin_define
define|#
directive|define
name|XYINPU
value|13
end_define

begin_comment
comment|/* INPUT command parameters */
end_comment

begin_define
define|#
directive|define
name|XYLEN
value|14
end_define

begin_comment
comment|/* Maximum packet length to send */
end_comment

begin_define
define|#
directive|define
name|XYLINE
value|15
end_define

begin_comment
comment|/* Communication line to use */
end_comment

begin_define
define|#
directive|define
name|XYLOG
value|16
end_define

begin_comment
comment|/* Log file */
end_comment

begin_define
define|#
directive|define
name|XYMARK
value|17
end_define

begin_comment
comment|/* Start of Packet mark */
end_comment

begin_define
define|#
directive|define
name|XYNPAD
value|18
end_define

begin_comment
comment|/* Amount of padding */
end_comment

begin_define
define|#
directive|define
name|XYPADC
value|19
end_define

begin_comment
comment|/* Pad character */
end_comment

begin_define
define|#
directive|define
name|XYPARI
value|20
end_define

begin_comment
comment|/* Parity */
end_comment

begin_define
define|#
directive|define
name|XYPAUS
value|21
end_define

begin_comment
comment|/* Interpacket pause */
end_comment

begin_define
define|#
directive|define
name|XYPROM
value|22
end_define

begin_comment
comment|/* Program prompt string */
end_comment

begin_define
define|#
directive|define
name|XYQBIN
value|23
end_define

begin_comment
comment|/* 8th-bit prefix */
end_comment

begin_define
define|#
directive|define
name|XYQCTL
value|24
end_define

begin_comment
comment|/* Control character prefix */
end_comment

begin_define
define|#
directive|define
name|XYREPT
value|25
end_define

begin_comment
comment|/* Repeat count prefix */
end_comment

begin_define
define|#
directive|define
name|XYRETR
value|26
end_define

begin_comment
comment|/* Retry limit */
end_comment

begin_define
define|#
directive|define
name|XYSPEE
value|27
end_define

begin_comment
comment|/* Line speed (baud rate) */
end_comment

begin_define
define|#
directive|define
name|XYTACH
value|28
end_define

begin_comment
comment|/* Character to be doubled */
end_comment

begin_define
define|#
directive|define
name|XYTIMO
value|29
end_define

begin_comment
comment|/* Timeout interval */
end_comment

begin_define
define|#
directive|define
name|XYMODM
value|30
end_define

begin_comment
comment|/* Modem type */
end_comment

begin_define
define|#
directive|define
name|XYSEND
value|31
end_define

begin_comment
comment|/* SEND parameters, used with some of the above */
end_comment

begin_define
define|#
directive|define
name|XYRECV
value|32
end_define

begin_comment
comment|/* RECEIVE parameters, ditto */
end_comment

begin_define
define|#
directive|define
name|XYTERM
value|33
end_define

begin_comment
comment|/* Terminal parameters */
end_comment

begin_define
define|#
directive|define
name|XYTBYT
value|0
end_define

begin_comment
comment|/*  Terminal Bytesize (7 or 8) */
end_comment

begin_define
define|#
directive|define
name|XYTTYP
value|1
end_define

begin_comment
comment|/*  Terminal Type */
end_comment

begin_define
define|#
directive|define
name|TT_NONE
value|0
end_define

begin_comment
comment|/*    NONE */
end_comment

begin_define
define|#
directive|define
name|TT_VT52
value|1
end_define

begin_comment
comment|/*    DEC VT-52  */
end_comment

begin_define
define|#
directive|define
name|TT_VT100
value|2
end_define

begin_comment
comment|/*    DEC VT-100 */
end_comment

begin_define
define|#
directive|define
name|TT_VT102
value|3
end_define

begin_comment
comment|/*    DEC VT-102 */
end_comment

begin_define
define|#
directive|define
name|TT_VT220
value|4
end_define

begin_comment
comment|/*    DEC VT-220 */
end_comment

begin_define
define|#
directive|define
name|TT_VT320
value|5
end_define

begin_comment
comment|/*    DEC VT-320 */
end_comment

begin_define
define|#
directive|define
name|TT_TEK40
value|6
end_define

begin_comment
comment|/*    Tektronix 401x */
end_comment

begin_define
define|#
directive|define
name|XYTCS
value|2
end_define

begin_comment
comment|/*  Terminal Character Set */
end_comment

begin_define
define|#
directive|define
name|XYTSO
value|3
end_define

begin_comment
comment|/*  Terminal Shift-In/Shift-Out */
end_comment

begin_define
define|#
directive|define
name|XYTNL
value|4
end_define

begin_comment
comment|/*  Terminal newline mode */
end_comment

begin_define
define|#
directive|define
name|XYTCOL
value|5
end_define

begin_comment
comment|/*  Terminal colors */
end_comment

begin_define
define|#
directive|define
name|XYTEC
value|6
end_define

begin_comment
comment|/*  Terminal echo = duplex = local-echo */
end_comment

begin_define
define|#
directive|define
name|XYTCUR
value|7
end_define

begin_comment
comment|/*  Terminal cursor */
end_comment

begin_define
define|#
directive|define
name|XYTARR
value|8
end_define

begin_comment
comment|/*  Terminal arrow-key mode */
end_comment

begin_define
define|#
directive|define
name|XYTKPD
value|9
end_define

begin_comment
comment|/*  Terminal keypad mode */
end_comment

begin_define
define|#
directive|define
name|XYTWRP
value|10
end_define

begin_comment
comment|/*  Terminal wrap */
end_comment

begin_define
define|#
directive|define
name|XYTCRD
value|11
end_define

begin_comment
comment|/*  Terminal CR-display */
end_comment

begin_define
define|#
directive|define
name|XYATTR
value|34
end_define

begin_comment
comment|/* Attribute packets */
end_comment

begin_define
define|#
directive|define
name|XYSERV
value|35
end_define

begin_comment
comment|/* Server parameters */
end_comment

begin_define
define|#
directive|define
name|XYSERT
value|0
end_define

begin_comment
comment|/*  Server timeout   */
end_comment

begin_define
define|#
directive|define
name|XYSERD
value|1
end_define

begin_comment
comment|/*  Server display   */
end_comment

begin_define
define|#
directive|define
name|XYWIND
value|36
end_define

begin_comment
comment|/* Window size */
end_comment

begin_define
define|#
directive|define
name|XYXFER
value|37
end_define

begin_comment
comment|/* Transfer */
end_comment

begin_define
define|#
directive|define
name|XYLANG
value|38
end_define

begin_comment
comment|/* Language */
end_comment

begin_define
define|#
directive|define
name|XYCOUN
value|39
end_define

begin_comment
comment|/* Count */
end_comment

begin_define
define|#
directive|define
name|XYTAKE
value|40
end_define

begin_comment
comment|/* Take */
end_comment

begin_define
define|#
directive|define
name|XYUNCS
value|41
end_define

begin_comment
comment|/* Unknown-character-set */
end_comment

begin_define
define|#
directive|define
name|XYKEY
value|42
end_define

begin_comment
comment|/* Key */
end_comment

begin_define
define|#
directive|define
name|XYMACR
value|43
end_define

begin_comment
comment|/* Macro */
end_comment

begin_define
define|#
directive|define
name|XYHOST
value|44
end_define

begin_comment
comment|/* Hostname on network */
end_comment

begin_define
define|#
directive|define
name|XYNET
value|45
end_define

begin_comment
comment|/* Type of Network */
end_comment

begin_define
define|#
directive|define
name|XYCARR
value|46
end_define

begin_comment
comment|/* Carrier */
end_comment

begin_define
define|#
directive|define
name|XYXMIT
value|47
end_define

begin_comment
comment|/* Transmit */
end_comment

begin_define
define|#
directive|define
name|XYDIAL
value|48
end_define

begin_comment
comment|/* Dial options */
end_comment

begin_define
define|#
directive|define
name|XYDHUP
value|0
end_define

begin_comment
comment|/*   Dial Hangup */
end_comment

begin_define
define|#
directive|define
name|XYDINI
value|1
end_define

begin_comment
comment|/*   Dial Initialization string */
end_comment

begin_define
define|#
directive|define
name|XYDKSP
value|2
end_define

begin_comment
comment|/*   Dial Kermit-Spoof */
end_comment

begin_define
define|#
directive|define
name|XYDTMO
value|3
end_define

begin_comment
comment|/*   Dial Timeout */
end_comment

begin_define
define|#
directive|define
name|XYDDPY
value|4
end_define

begin_comment
comment|/*   Dial Display */
end_comment

begin_define
define|#
directive|define
name|XYDSPD
value|5
end_define

begin_comment
comment|/*   Dial Speed matching */
end_comment

begin_define
define|#
directive|define
name|XYDMNP
value|6
end_define

begin_comment
comment|/*   Dial MNP negotiation enabled */
end_comment

begin_define
define|#
directive|define
name|XYDV32
value|7
end_define

begin_comment
comment|/*   Dial V.32 mode enabled */
end_comment

begin_define
define|#
directive|define
name|XYDV42
value|8
end_define

begin_comment
comment|/*   Dial V.42 mode enabled */
end_comment

begin_define
define|#
directive|define
name|XYDV42B
value|9
end_define

begin_comment
comment|/*   Dial V.42bis mode enabled */
end_comment

begin_define
define|#
directive|define
name|XYDDIR
value|10
end_define

begin_comment
comment|/*   Dial directory */
end_comment

begin_define
define|#
directive|define
name|XYDDIA
value|11
end_define

begin_comment
comment|/*   Dial dial-command */
end_comment

begin_define
define|#
directive|define
name|XYDMHU
value|12
end_define

begin_comment
comment|/*   Dial modem-hangup */
end_comment

begin_define
define|#
directive|define
name|XYDNPR
value|13
end_define

begin_comment
comment|/*   Dial number-prefix */
end_comment

begin_define
define|#
directive|define
name|XYSESS
value|49
end_define

begin_comment
comment|/* SET SESSION options */
end_comment

begin_define
define|#
directive|define
name|XYBUF
value|50
end_define

begin_comment
comment|/* Buffer length */
end_comment

begin_define
define|#
directive|define
name|XYBACK
value|51
end_define

begin_comment
comment|/* Background */
end_comment

begin_define
define|#
directive|define
name|XYDFLT
value|52
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|XYDOUB
value|53
end_define

begin_comment
comment|/* Double */
end_comment

begin_define
define|#
directive|define
name|XYCMD
value|54
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|XYCASE
value|55
end_define

begin_comment
comment|/* Case */
end_comment

begin_define
define|#
directive|define
name|XYCOMP
value|56
end_define

begin_comment
comment|/* Compression */
end_comment

begin_define
define|#
directive|define
name|XYX25
value|57
end_define

begin_comment
comment|/* X.25 parameter (SUNX25) */
end_comment

begin_define
define|#
directive|define
name|XYPAD
value|58
end_define

begin_comment
comment|/* X.3 PAD parameter (SUNX25) */
end_comment

begin_define
define|#
directive|define
name|XYWILD
value|59
end_define

begin_comment
comment|/* Wildcard expansion method */
end_comment

begin_define
define|#
directive|define
name|XYSUSP
value|60
end_define

begin_comment
comment|/* Suspend */
end_comment

begin_define
define|#
directive|define
name|XYMAIL
value|61
end_define

begin_comment
comment|/* Mail-Command */
end_comment

begin_define
define|#
directive|define
name|XYPRIN
value|62
end_define

begin_comment
comment|/* Print-Command */
end_comment

begin_define
define|#
directive|define
name|XYQUIE
value|63
end_define

begin_comment
comment|/* Quiet */
end_comment

begin_define
define|#
directive|define
name|XYLCLE
value|64
end_define

begin_comment
comment|/* Local-echo */
end_comment

begin_define
define|#
directive|define
name|XYSCRI
value|65
end_define

begin_comment
comment|/* SCRIPT command paramaters */
end_comment

begin_define
define|#
directive|define
name|XYMSGS
value|66
end_define

begin_comment
comment|/* MESSAGEs ON/OFF */
end_comment

begin_define
define|#
directive|define
name|XYTEL
value|67
end_define

begin_comment
comment|/* TELNET parameters */
end_comment

begin_define
define|#
directive|define
name|CK_TN_EC
value|0
end_define

begin_comment
comment|/*  TELNET ECHO */
end_comment

begin_define
define|#
directive|define
name|CK_TN_TT
value|1
end_define

begin_comment
comment|/*  TELNET TERMINAL-TYPE */
end_comment

begin_define
define|#
directive|define
name|CK_TN_NL
value|2
end_define

begin_comment
comment|/*  TELNET NEWLINE-MODE */
end_comment

begin_comment
comment|/* #ifdef SUNX25 */
end_comment

begin_comment
comment|/* PAD command parameters */
end_comment

begin_define
define|#
directive|define
name|XYPADL
value|0
end_define

begin_comment
comment|/* clear virtual call */
end_comment

begin_define
define|#
directive|define
name|XYPADS
value|1
end_define

begin_comment
comment|/* status of virtual call */
end_comment

begin_define
define|#
directive|define
name|XYPADR
value|2
end_define

begin_comment
comment|/* reset of virtual call */
end_comment

begin_define
define|#
directive|define
name|XYPADI
value|3
end_define

begin_comment
comment|/* send an interrupt packet */
end_comment

begin_comment
comment|/* Used with XYX25... */
end_comment

begin_define
define|#
directive|define
name|XYUDAT
value|0
end_define

begin_comment
comment|/* X.25 call user data */
end_comment

begin_define
define|#
directive|define
name|XYCLOS
value|1
end_define

begin_comment
comment|/* X.25 closed user group call */
end_comment

begin_define
define|#
directive|define
name|XYREVC
value|2
end_define

begin_comment
comment|/* X.25 reverse charge call */
end_comment

begin_comment
comment|/* #endif */
end_comment

begin_comment
comment|/* SUNX25 */
end_comment

begin_comment
comment|/* SHOW command symbols */
end_comment

begin_define
define|#
directive|define
name|SHPAR
value|0
end_define

begin_comment
comment|/* Parameters */
end_comment

begin_define
define|#
directive|define
name|SHVER
value|1
end_define

begin_comment
comment|/* Versions */
end_comment

begin_define
define|#
directive|define
name|SHCOM
value|2
end_define

begin_comment
comment|/* Communications */
end_comment

begin_define
define|#
directive|define
name|SHPRO
value|3
end_define

begin_comment
comment|/* Protocol */
end_comment

begin_define
define|#
directive|define
name|SHFIL
value|4
end_define

begin_comment
comment|/* File */
end_comment

begin_define
define|#
directive|define
name|SHLNG
value|5
end_define

begin_comment
comment|/* Language */
end_comment

begin_define
define|#
directive|define
name|SHCOU
value|6
end_define

begin_comment
comment|/* Count */
end_comment

begin_define
define|#
directive|define
name|SHMAC
value|7
end_define

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|SHKEY
value|8
end_define

begin_comment
comment|/* Key */
end_comment

begin_define
define|#
directive|define
name|SHSCR
value|9
end_define

begin_comment
comment|/* Scripts */
end_comment

begin_define
define|#
directive|define
name|SHSPD
value|10
end_define

begin_comment
comment|/* Speed */
end_comment

begin_define
define|#
directive|define
name|SHSTA
value|11
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|SHSER
value|12
end_define

begin_comment
comment|/* Server */
end_comment

begin_define
define|#
directive|define
name|SHXMI
value|13
end_define

begin_comment
comment|/* Transmit */
end_comment

begin_define
define|#
directive|define
name|SHATT
value|14
end_define

begin_comment
comment|/* Attributes */
end_comment

begin_define
define|#
directive|define
name|SHMOD
value|15
end_define

begin_comment
comment|/* Modem */
end_comment

begin_define
define|#
directive|define
name|SHDFLT
value|16
end_define

begin_comment
comment|/* Default (as in VMS) */
end_comment

begin_define
define|#
directive|define
name|SHVAR
value|17
end_define

begin_comment
comment|/* Show global variables */
end_comment

begin_define
define|#
directive|define
name|SHARG
value|18
end_define

begin_comment
comment|/* Show macro arguments */
end_comment

begin_define
define|#
directive|define
name|SHARR
value|19
end_define

begin_comment
comment|/* Show arrays */
end_comment

begin_define
define|#
directive|define
name|SHBUI
value|20
end_define

begin_comment
comment|/* Show builtin variables */
end_comment

begin_define
define|#
directive|define
name|SHFUN
value|21
end_define

begin_comment
comment|/* Show functions */
end_comment

begin_define
define|#
directive|define
name|SHPAD
value|22
end_define

begin_comment
comment|/* Show (X.25) PAD */
end_comment

begin_define
define|#
directive|define
name|SHTER
value|23
end_define

begin_comment
comment|/* Show terminal settings */
end_comment

begin_define
define|#
directive|define
name|SHESC
value|24
end_define

begin_comment
comment|/* Show escape character */
end_comment

begin_define
define|#
directive|define
name|SHDIA
value|25
end_define

begin_comment
comment|/* Show DIAL parameters */
end_comment

begin_define
define|#
directive|define
name|SHNET
value|26
end_define

begin_comment
comment|/* Show network parameters */
end_comment

begin_define
define|#
directive|define
name|SHLBL
value|27
end_define

begin_comment
comment|/* Show VMS labeled file parameters */
end_comment

begin_define
define|#
directive|define
name|SHSTK
value|28
end_define

begin_comment
comment|/* Show stack, MAC debugging */
end_comment

begin_define
define|#
directive|define
name|SHCSE
value|29
end_define

begin_comment
comment|/* Show character sets */
end_comment

begin_define
define|#
directive|define
name|SHFEA
value|30
end_define

begin_comment
comment|/* Show features */
end_comment

begin_comment
comment|/* REMOTE command symbols */
end_comment

begin_define
define|#
directive|define
name|XZCPY
value|0
end_define

begin_comment
comment|/* Copy */
end_comment

begin_define
define|#
directive|define
name|XZCWD
value|1
end_define

begin_comment
comment|/* Change Working Directory */
end_comment

begin_define
define|#
directive|define
name|XZDEL
value|2
end_define

begin_comment
comment|/* Delete */
end_comment

begin_define
define|#
directive|define
name|XZDIR
value|3
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|XZHLP
value|4
end_define

begin_comment
comment|/* Help */
end_comment

begin_define
define|#
directive|define
name|XZHOS
value|5
end_define

begin_comment
comment|/* Host */
end_comment

begin_define
define|#
directive|define
name|XZKER
value|6
end_define

begin_comment
comment|/* Kermit */
end_comment

begin_define
define|#
directive|define
name|XZLGI
value|7
end_define

begin_comment
comment|/* Login */
end_comment

begin_define
define|#
directive|define
name|XZLGO
value|8
end_define

begin_comment
comment|/* Logout */
end_comment

begin_define
define|#
directive|define
name|XZMAI
value|9
end_define

begin_comment
comment|/* Mail<-- wrong, this should be top-level */
end_comment

begin_define
define|#
directive|define
name|XZMOU
value|10
end_define

begin_comment
comment|/* Mount */
end_comment

begin_define
define|#
directive|define
name|XZMSG
value|11
end_define

begin_comment
comment|/* Message */
end_comment

begin_define
define|#
directive|define
name|XZPRI
value|12
end_define

begin_comment
comment|/* Print */
end_comment

begin_define
define|#
directive|define
name|XZREN
value|13
end_define

begin_comment
comment|/* Rename */
end_comment

begin_define
define|#
directive|define
name|XZSET
value|14
end_define

begin_comment
comment|/* Set */
end_comment

begin_define
define|#
directive|define
name|XZSPA
value|15
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|XZSUB
value|16
end_define

begin_comment
comment|/* Submit */
end_comment

begin_define
define|#
directive|define
name|XZTYP
value|17
end_define

begin_comment
comment|/* Type */
end_comment

begin_define
define|#
directive|define
name|XZWHO
value|18
end_define

begin_comment
comment|/* Who */
end_comment

begin_comment
comment|/* SET INPUT command parameters */
end_comment

begin_define
define|#
directive|define
name|IN_DEF
value|0
end_define

begin_comment
comment|/* Default timeout */
end_comment

begin_define
define|#
directive|define
name|IN_TIM
value|1
end_define

begin_comment
comment|/* Timeout action */
end_comment

begin_define
define|#
directive|define
name|IN_CAS
value|2
end_define

begin_comment
comment|/* Case (matching) */
end_comment

begin_define
define|#
directive|define
name|IN_ECH
value|3
end_define

begin_comment
comment|/* Echo */
end_comment

begin_define
define|#
directive|define
name|IN_SIL
value|4
end_define

begin_comment
comment|/* Silence */
end_comment

begin_comment
comment|/* ENABLE/DISABLE command parameters */
end_comment

begin_define
define|#
directive|define
name|EN_ALL
value|0
end_define

begin_comment
comment|/* All */
end_comment

begin_define
define|#
directive|define
name|EN_CWD
value|1
end_define

begin_comment
comment|/* CD/CWD */
end_comment

begin_define
define|#
directive|define
name|EN_DIR
value|2
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|EN_FIN
value|3
end_define

begin_comment
comment|/* FINISH */
end_comment

begin_define
define|#
directive|define
name|EN_GET
value|4
end_define

begin_comment
comment|/* Get */
end_comment

begin_define
define|#
directive|define
name|EN_HOS
value|5
end_define

begin_comment
comment|/* Host command */
end_comment

begin_define
define|#
directive|define
name|EN_KER
value|6
end_define

begin_comment
comment|/* Kermit command */
end_comment

begin_define
define|#
directive|define
name|EN_LOG
value|7
end_define

begin_comment
comment|/* Login */
end_comment

begin_define
define|#
directive|define
name|EN_SEN
value|8
end_define

begin_comment
comment|/* Send */
end_comment

begin_define
define|#
directive|define
name|EN_SET
value|9
end_define

begin_comment
comment|/* Set */
end_comment

begin_define
define|#
directive|define
name|EN_SPA
value|10
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|EN_TYP
value|11
end_define

begin_comment
comment|/* Type */
end_comment

begin_define
define|#
directive|define
name|EN_WHO
value|12
end_define

begin_comment
comment|/* Who/Finger */
end_comment

begin_define
define|#
directive|define
name|EN_DEL
value|13
end_define

begin_comment
comment|/* Delete */
end_comment

begin_define
define|#
directive|define
name|EN_BYE
value|14
end_define

begin_comment
comment|/* BYE (as opposed to FINISH) */
end_comment

begin_comment
comment|/* Symbols for logs */
end_comment

begin_define
define|#
directive|define
name|LOGD
value|0
end_define

begin_comment
comment|/* Debugging */
end_comment

begin_define
define|#
directive|define
name|LOGP
value|1
end_define

begin_comment
comment|/* Packets */
end_comment

begin_define
define|#
directive|define
name|LOGS
value|2
end_define

begin_comment
comment|/* Session */
end_comment

begin_define
define|#
directive|define
name|LOGT
value|3
end_define

begin_comment
comment|/* Transaction */
end_comment

begin_define
define|#
directive|define
name|LOGX
value|4
end_define

begin_comment
comment|/* Screen */
end_comment

begin_define
define|#
directive|define
name|LOGR
value|5
end_define

begin_comment
comment|/* The "OPEN read file */
end_comment

begin_define
define|#
directive|define
name|LOGW
value|6
end_define

begin_comment
comment|/* The "OPEN" write/append file */
end_comment

begin_define
define|#
directive|define
name|LOGE
value|7
end_define

begin_comment
comment|/* Error (e.g. stderr) */
end_comment

begin_comment
comment|/* Symbols for builtin variables */
end_comment

begin_define
define|#
directive|define
name|VN_ARGC
value|0
end_define

begin_comment
comment|/* ARGC */
end_comment

begin_define
define|#
directive|define
name|VN_COUN
value|1
end_define

begin_comment
comment|/* COUNT */
end_comment

begin_define
define|#
directive|define
name|VN_DATE
value|2
end_define

begin_comment
comment|/* DATE */
end_comment

begin_define
define|#
directive|define
name|VN_DIRE
value|3
end_define

begin_comment
comment|/* DIRECTORY */
end_comment

begin_define
define|#
directive|define
name|VN_ERRO
value|4
end_define

begin_comment
comment|/* ERRORLEVEL */
end_comment

begin_define
define|#
directive|define
name|VN_TIME
value|5
end_define

begin_comment
comment|/* TIME */
end_comment

begin_define
define|#
directive|define
name|VN_VERS
value|6
end_define

begin_comment
comment|/* VERSION */
end_comment

begin_define
define|#
directive|define
name|VN_IBUF
value|7
end_define

begin_comment
comment|/* INPUT buffer */
end_comment

begin_define
define|#
directive|define
name|VN_SUCC
value|8
end_define

begin_comment
comment|/* SUCCESS flag */
end_comment

begin_define
define|#
directive|define
name|VN_LINE
value|9
end_define

begin_comment
comment|/* LINE */
end_comment

begin_define
define|#
directive|define
name|VN_ARGS
value|10
end_define

begin_comment
comment|/* Program command-line arg count */
end_comment

begin_define
define|#
directive|define
name|VN_SYST
value|11
end_define

begin_comment
comment|/* System type */
end_comment

begin_define
define|#
directive|define
name|VN_SYSV
value|12
end_define

begin_comment
comment|/* System version */
end_comment

begin_define
define|#
directive|define
name|VN_RET
value|13
end_define

begin_comment
comment|/* RETURN value */
end_comment

begin_define
define|#
directive|define
name|VN_FILE
value|14
end_define

begin_comment
comment|/* Most recent filespec */
end_comment

begin_define
define|#
directive|define
name|VN_NDAT
value|15
end_define

begin_comment
comment|/* Numeric date yyyy/mm/dd */
end_comment

begin_define
define|#
directive|define
name|VN_HOME
value|16
end_define

begin_comment
comment|/* Home directory */
end_comment

begin_define
define|#
directive|define
name|VN_SPEE
value|17
end_define

begin_comment
comment|/* Transmission speed */
end_comment

begin_define
define|#
directive|define
name|VN_HOST
value|18
end_define

begin_comment
comment|/* Host name */
end_comment

begin_define
define|#
directive|define
name|VN_TTYF
value|19
end_define

begin_comment
comment|/* TTY file descriptor (UNIX only) */
end_comment

begin_define
define|#
directive|define
name|VN_PROG
value|20
end_define

begin_comment
comment|/* Program name */
end_comment

begin_define
define|#
directive|define
name|VN_NTIM
value|21
end_define

begin_comment
comment|/* NTIME */
end_comment

begin_define
define|#
directive|define
name|VN_FFC
value|22
end_define

begin_comment
comment|/* Characters in last file xferred */
end_comment

begin_define
define|#
directive|define
name|VN_TFC
value|23
end_define

begin_comment
comment|/* Chars in last file group xferred */
end_comment

begin_define
define|#
directive|define
name|VN_CPU
value|24
end_define

begin_comment
comment|/* CPU type */
end_comment

begin_define
define|#
directive|define
name|VN_CMDL
value|25
end_define

begin_comment
comment|/* Command level */
end_comment

begin_define
define|#
directive|define
name|VN_DAY
value|26
end_define

begin_comment
comment|/* Day of week, string */
end_comment

begin_define
define|#
directive|define
name|VN_NDAY
value|27
end_define

begin_comment
comment|/* Day of week, numeric */
end_comment

begin_define
define|#
directive|define
name|VN_LCL
value|28
end_define

begin_comment
comment|/* Local (vs) remote mode */
end_comment

begin_define
define|#
directive|define
name|VN_CMDS
value|29
end_define

begin_comment
comment|/* Command source */
end_comment

begin_define
define|#
directive|define
name|VN_CMDF
value|30
end_define

begin_comment
comment|/* Command file name */
end_comment

begin_define
define|#
directive|define
name|VN_MAC
value|31
end_define

begin_comment
comment|/* Macro name */
end_comment

begin_define
define|#
directive|define
name|VN_EXIT
value|32
end_define

begin_comment
comment|/* Exit status */
end_comment

begin_define
define|#
directive|define
name|VN_ICHR
value|33
end_define

begin_comment
comment|/* INPUT character */
end_comment

begin_define
define|#
directive|define
name|VN_ICNT
value|34
end_define

begin_comment
comment|/* INPUT count */
end_comment

begin_comment
comment|/* Symbols for builtin functions */
end_comment

begin_define
define|#
directive|define
name|FNARGS
value|6
end_define

begin_comment
comment|/* Maximum number of function args */
end_comment

begin_define
define|#
directive|define
name|FN_IND
value|0
end_define

begin_comment
comment|/* Index (of string 1 in string 2) */
end_comment

begin_define
define|#
directive|define
name|FN_LEN
value|1
end_define

begin_comment
comment|/* Length (of string) */
end_comment

begin_define
define|#
directive|define
name|FN_LIT
value|2
end_define

begin_comment
comment|/* Literal (don't expand the string) */
end_comment

begin_define
define|#
directive|define
name|FN_LOW
value|3
end_define

begin_comment
comment|/* Lower (convert to lowercase) */
end_comment

begin_define
define|#
directive|define
name|FN_MAX
value|4
end_define

begin_comment
comment|/* Max (maximum) */
end_comment

begin_define
define|#
directive|define
name|FN_MIN
value|5
end_define

begin_comment
comment|/* Min (minimum) */
end_comment

begin_define
define|#
directive|define
name|FN_MOD
value|6
end_define

begin_comment
comment|/* Mod (modulus) */
end_comment

begin_define
define|#
directive|define
name|FN_EVA
value|7
end_define

begin_comment
comment|/* Eval (evaluate arith expression) */
end_comment

begin_define
define|#
directive|define
name|FN_SUB
value|8
end_define

begin_comment
comment|/* Substr (substring) */
end_comment

begin_define
define|#
directive|define
name|FN_UPP
value|9
end_define

begin_comment
comment|/* Upper (convert to uppercase) */
end_comment

begin_define
define|#
directive|define
name|FN_REV
value|10
end_define

begin_comment
comment|/* Reverse (a string) */
end_comment

begin_define
define|#
directive|define
name|FN_REP
value|11
end_define

begin_comment
comment|/* Repeat (a string) */
end_comment

begin_define
define|#
directive|define
name|FN_EXE
value|12
end_define

begin_comment
comment|/* Execute (a macro) */
end_comment

begin_define
define|#
directive|define
name|FN_VAL
value|13
end_define

begin_comment
comment|/* Return value (of a macro) */
end_comment

begin_define
define|#
directive|define
name|FN_LPA
value|14
end_define

begin_comment
comment|/* LPAD (left pad) */
end_comment

begin_define
define|#
directive|define
name|FN_RPA
value|15
end_define

begin_comment
comment|/* RPAD (right pad) */
end_comment

begin_define
define|#
directive|define
name|FN_DEF
value|16
end_define

begin_comment
comment|/* Definition of a macro, unexpanded */
end_comment

begin_define
define|#
directive|define
name|FN_CON
value|17
end_define

begin_comment
comment|/* Contents of a variable, ditto */
end_comment

begin_define
define|#
directive|define
name|FN_FIL
value|18
end_define

begin_comment
comment|/* File list */
end_comment

begin_define
define|#
directive|define
name|FN_FC
value|19
end_define

begin_comment
comment|/* File count */
end_comment

begin_define
define|#
directive|define
name|FN_CHR
value|20
end_define

begin_comment
comment|/* Character (like BASIC CHR$()) */
end_comment

begin_define
define|#
directive|define
name|FN_RIG
value|21
end_define

begin_comment
comment|/* Right (like BASIC RIGHT$()) */
end_comment

begin_define
define|#
directive|define
name|FN_COD
value|22
end_define

begin_comment
comment|/* Code value of character */
end_comment

begin_comment
comment|/* ANSI-style prototypes for user interface functions */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int parser
argument_list|,
argument|( int )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xxstring
argument_list|,
argument|(char *, char **, int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int yystring
argument_list|,
argument|(char *, char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xxstrcmp
argument_list|,
argument|(char *, char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xxout
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
argument|int getncm
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
argument|int getnct
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
argument|VOID bgchk
argument_list|,
argument|(void)
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
name|fneval
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
index|[]
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|nvlook
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|arrayval
argument_list|,
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int arraynam
argument_list|,
argument|(char *, int *, int *)
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
name|bldlen
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chkarray
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
argument|int dclarray
argument_list|,
argument|(char, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int parsevar
argument_list|,
argument|(char *, int *, int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int macini
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
argument|VOID initmac
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
argument|int delmac
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
argument|int addmac
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
argument|int addmmac
argument_list|,
argument|(char *, char *[])
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dobug
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
argument|int docd
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
argument|int doclslog
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
argument|int docmd
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
argument|int doconect
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
argument|int dodo
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int doenable
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
argument|int doget
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
argument|int dogoto
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
argument|int dohlp
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
argument|int dohrmt
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
argument|int doif
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
argument|int doinput
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int doreinp
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dolog
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
argument|int dologin
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
argument|int doopen
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
argument|int dooutput
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
argument|int doprm
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
argument|int doreturn
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
argument|int dormt
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
argument|int doshow
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
argument|int doshodial
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
argument|int dostat
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
argument|int dostop
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
argument|int dotype
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
argument|int transmit
argument_list|,
argument|(char *, char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xlate
argument_list|,
argument|(char *, char *, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int litcmd
argument_list|,
argument|(char **, char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int incvar
argument_list|,
argument|(char *, int, int, int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ckdial
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
name|char
operator|*
name|getdws
argument_list|,
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|getdcs
argument_list|,
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int hmsg
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
argument|int hmsga
argument_list|,
argument|(char * [])
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mlook
argument_list|,
argument|(struct mtab [], char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int mxlook
argument_list|,
argument|(struct mtab [], char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID prtopt
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
argument|CHAR rfilop
argument_list|,
argument|(char *, char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int setcc
argument_list|,
argument|(int *, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int setnum
argument_list|,
argument|(int *, int, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int seton
argument_list|,
argument|(int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID shmdmlin
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
argument|int shoatt
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
argument|VOID shocharset
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
argument|int shomac
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
argument|VOID shopar
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
argument|VOID shoparc
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
argument|VOID shoparc
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
argument|VOID shoparf
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
argument|VOID shoparp
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID shoparl
argument_list|,
argument|(void)
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
comment|/* NOCSETS */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID shodial
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
argument|VOID shomdm
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
argument|VOID shonet
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
argument|VOID shover
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
argument|int pktopn
argument_list|,
argument|(char *,int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int traopn
argument_list|,
argument|(char *,int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sesopn
argument_list|,
argument|(char *,int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int debopn
argument_list|,
argument|(char *,int)
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
name|parnam
argument_list|,
operator|(
name|char
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int popclvl
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
argument|int varval
argument_list|,
argument|(char *, int *)
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
name|evala
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
argument|int setat
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
argument|int setinp
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
argument|int setlin
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
argument|int setdial
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
argument|int setfil
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
argument|int settrm
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
argument|int setsr
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
argument|int setxmit
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
argument|int set_key
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
argument|int dochk
argument_list|,
argument|(void)
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
name|ludial
argument_list|,
operator|(
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID xwords
argument_list|,
argument|(char *, int, char *[])
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID shotcs
argument_list|,
argument|(int, int)
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
name|hhmmss
argument_list|,
operator|(
name|long
name|x
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKUUSR_H */
end_comment

begin_comment
comment|/* End of ckuusr.h */
end_comment

end_unit

