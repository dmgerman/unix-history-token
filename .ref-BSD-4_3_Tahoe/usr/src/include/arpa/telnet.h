begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)telnet.h	5.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Definitions for the TELNET protocol.  */
end_comment

begin_define
define|#
directive|define
name|IAC
value|255
end_define

begin_comment
comment|/* interpret as command: */
end_comment

begin_define
define|#
directive|define
name|DONT
value|254
end_define

begin_comment
comment|/* you are not to use option */
end_comment

begin_define
define|#
directive|define
name|DO
value|253
end_define

begin_comment
comment|/* please, you use option */
end_comment

begin_define
define|#
directive|define
name|WONT
value|252
end_define

begin_comment
comment|/* I won't use option */
end_comment

begin_define
define|#
directive|define
name|WILL
value|251
end_define

begin_comment
comment|/* I will use option */
end_comment

begin_define
define|#
directive|define
name|SB
value|250
end_define

begin_comment
comment|/* interpret as subnegotiation */
end_comment

begin_define
define|#
directive|define
name|GA
value|249
end_define

begin_comment
comment|/* you may reverse the line */
end_comment

begin_define
define|#
directive|define
name|EL
value|248
end_define

begin_comment
comment|/* erase the current line */
end_comment

begin_define
define|#
directive|define
name|EC
value|247
end_define

begin_comment
comment|/* erase the current character */
end_comment

begin_define
define|#
directive|define
name|AYT
value|246
end_define

begin_comment
comment|/* are you there */
end_comment

begin_define
define|#
directive|define
name|AO
value|245
end_define

begin_comment
comment|/* abort output--but let prog finish */
end_comment

begin_define
define|#
directive|define
name|IP
value|244
end_define

begin_comment
comment|/* interrupt process--permanently */
end_comment

begin_define
define|#
directive|define
name|BREAK
value|243
end_define

begin_comment
comment|/* break */
end_comment

begin_define
define|#
directive|define
name|DM
value|242
end_define

begin_comment
comment|/* data mark--for connect. cleaning */
end_comment

begin_define
define|#
directive|define
name|NOP
value|241
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|SE
value|240
end_define

begin_comment
comment|/* end sub negotiation */
end_comment

begin_define
define|#
directive|define
name|EOR
value|239
end_define

begin_comment
comment|/* end of record (transparent mode) */
end_comment

begin_define
define|#
directive|define
name|SYNCH
value|242
end_define

begin_comment
comment|/* for telfunc calls */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TELCMDS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|telcmds
index|[]
init|=
block|{
literal|"SE"
block|,
literal|"NOP"
block|,
literal|"DMARK"
block|,
literal|"BRK"
block|,
literal|"IP"
block|,
literal|"AO"
block|,
literal|"AYT"
block|,
literal|"EC"
block|,
literal|"EL"
block|,
literal|"GA"
block|,
literal|"SB"
block|,
literal|"WILL"
block|,
literal|"WONT"
block|,
literal|"DO"
block|,
literal|"DONT"
block|,
literal|"IAC"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* telnet options */
end_comment

begin_define
define|#
directive|define
name|TELOPT_BINARY
value|0
end_define

begin_comment
comment|/* 8-bit data path */
end_comment

begin_define
define|#
directive|define
name|TELOPT_ECHO
value|1
end_define

begin_comment
comment|/* echo */
end_comment

begin_define
define|#
directive|define
name|TELOPT_RCP
value|2
end_define

begin_comment
comment|/* prepare to reconnect */
end_comment

begin_define
define|#
directive|define
name|TELOPT_SGA
value|3
end_define

begin_comment
comment|/* suppress go ahead */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAMS
value|4
end_define

begin_comment
comment|/* approximate message size */
end_comment

begin_define
define|#
directive|define
name|TELOPT_STATUS
value|5
end_define

begin_comment
comment|/* give status */
end_comment

begin_define
define|#
directive|define
name|TELOPT_TM
value|6
end_define

begin_comment
comment|/* timing mark */
end_comment

begin_define
define|#
directive|define
name|TELOPT_RCTE
value|7
end_define

begin_comment
comment|/* remote controlled transmission and echo */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOL
value|8
end_define

begin_comment
comment|/* negotiate about output line width */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOP
value|9
end_define

begin_comment
comment|/* negotiate about output page size */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOCRD
value|10
end_define

begin_comment
comment|/* negotiate about CR disposition */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOHTS
value|11
end_define

begin_comment
comment|/* negotiate about horizontal tabstops */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOHTD
value|12
end_define

begin_comment
comment|/* negotiate about horizontal tab disposition */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOFFD
value|13
end_define

begin_comment
comment|/* negotiate about formfeed disposition */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOVTS
value|14
end_define

begin_comment
comment|/* negotiate about vertical tab stops */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOVTD
value|15
end_define

begin_comment
comment|/* negotiate about vertical tab disposition */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAOLFD
value|16
end_define

begin_comment
comment|/* negotiate about output LF disposition */
end_comment

begin_define
define|#
directive|define
name|TELOPT_XASCII
value|17
end_define

begin_comment
comment|/* extended ascic character set */
end_comment

begin_define
define|#
directive|define
name|TELOPT_LOGOUT
value|18
end_define

begin_comment
comment|/* force logout */
end_comment

begin_define
define|#
directive|define
name|TELOPT_BM
value|19
end_define

begin_comment
comment|/* byte macro */
end_comment

begin_define
define|#
directive|define
name|TELOPT_DET
value|20
end_define

begin_comment
comment|/* data entry terminal */
end_comment

begin_define
define|#
directive|define
name|TELOPT_SUPDUP
value|21
end_define

begin_comment
comment|/* supdup protocol */
end_comment

begin_define
define|#
directive|define
name|TELOPT_SUPDUPOUTPUT
value|22
end_define

begin_comment
comment|/* supdup output */
end_comment

begin_define
define|#
directive|define
name|TELOPT_SNDLOC
value|23
end_define

begin_comment
comment|/* send location */
end_comment

begin_define
define|#
directive|define
name|TELOPT_TTYPE
value|24
end_define

begin_comment
comment|/* terminal type */
end_comment

begin_define
define|#
directive|define
name|TELOPT_EOR
value|25
end_define

begin_comment
comment|/* end or record */
end_comment

begin_define
define|#
directive|define
name|TELOPT_EXOPL
value|255
end_define

begin_comment
comment|/* extended-options-list */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TELOPTS
end_ifdef

begin_define
define|#
directive|define
name|NTELOPTS
value|(1+TELOPT_EOR)
end_define

begin_decl_stmt
name|char
modifier|*
name|telopts
index|[
name|NTELOPTS
index|]
init|=
block|{
literal|"BINARY"
block|,
literal|"ECHO"
block|,
literal|"RCP"
block|,
literal|"SUPPRESS GO AHEAD"
block|,
literal|"NAME"
block|,
literal|"STATUS"
block|,
literal|"TIMING MARK"
block|,
literal|"RCTE"
block|,
literal|"NAOL"
block|,
literal|"NAOP"
block|,
literal|"NAOCRD"
block|,
literal|"NAOHTS"
block|,
literal|"NAOHTD"
block|,
literal|"NAOFFD"
block|,
literal|"NAOVTS"
block|,
literal|"NAOVTD"
block|,
literal|"NAOLFD"
block|,
literal|"EXTEND ASCII"
block|,
literal|"LOGOUT"
block|,
literal|"BYTE MACRO"
block|,
literal|"DATA ENTRY TERMINAL"
block|,
literal|"SUPDUP"
block|,
literal|"SUPDUP OUTPUT"
block|,
literal|"SEND LOCATION"
block|,
literal|"TERMINAL TYPE"
block|,
literal|"END OF RECORD"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sub-option qualifiers */
end_comment

begin_define
define|#
directive|define
name|TELQUAL_IS
value|0
end_define

begin_comment
comment|/* option is... */
end_comment

begin_define
define|#
directive|define
name|TELQUAL_SEND
value|1
end_define

begin_comment
comment|/* send option */
end_comment

end_unit

