begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U U S R . H  --  Symbol definitions for C-Kermit ckuus*.c modules  */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|vax11c
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Values associated with top-level commands, must be 0 or greater. */
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
comment|/* DISCONNECT */
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
comment|/*  ...     */
end_comment

begin_comment
comment|/* empty space to add something */
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
comment|/* Mail */
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

end_unit

