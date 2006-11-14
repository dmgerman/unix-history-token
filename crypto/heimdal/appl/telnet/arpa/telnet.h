begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)telnet.h	8.2 (Berkeley) 12/15/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TELNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_TELNET_H_
end_define

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
name|ABORT
value|238
end_define

begin_comment
comment|/* Abort process */
end_comment

begin_define
define|#
directive|define
name|SUSP
value|237
end_define

begin_comment
comment|/* Suspend process */
end_comment

begin_define
define|#
directive|define
name|xEOF
value|236
end_define

begin_comment
comment|/* End of file: EOF is already used... */
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
literal|"EOF"
block|,
literal|"SUSP"
block|,
literal|"ABORT"
block|,
literal|"EOR"
block|,
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
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|telcmds
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TELCMD_FIRST
value|xEOF
end_define

begin_define
define|#
directive|define
name|TELCMD_LAST
value|IAC
end_define

begin_define
define|#
directive|define
name|TELCMD_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)<= TELCMD_LAST&& \ 			 (unsigned int)(x)>= TELCMD_FIRST)
end_define

begin_define
define|#
directive|define
name|TELCMD
parameter_list|(
name|x
parameter_list|)
value|telcmds[(x)-TELCMD_FIRST]
end_define

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
name|TELOPT_TUID
value|26
end_define

begin_comment
comment|/* TACACS user identification */
end_comment

begin_define
define|#
directive|define
name|TELOPT_OUTMRK
value|27
end_define

begin_comment
comment|/* output marking */
end_comment

begin_define
define|#
directive|define
name|TELOPT_TTYLOC
value|28
end_define

begin_comment
comment|/* terminal location number */
end_comment

begin_define
define|#
directive|define
name|TELOPT_3270REGIME
value|29
end_define

begin_comment
comment|/* 3270 regime */
end_comment

begin_define
define|#
directive|define
name|TELOPT_X3PAD
value|30
end_define

begin_comment
comment|/* X.3 PAD */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NAWS
value|31
end_define

begin_comment
comment|/* window size */
end_comment

begin_define
define|#
directive|define
name|TELOPT_TSPEED
value|32
end_define

begin_comment
comment|/* terminal speed */
end_comment

begin_define
define|#
directive|define
name|TELOPT_LFLOW
value|33
end_define

begin_comment
comment|/* remote flow control */
end_comment

begin_define
define|#
directive|define
name|TELOPT_LINEMODE
value|34
end_define

begin_comment
comment|/* Linemode option */
end_comment

begin_define
define|#
directive|define
name|TELOPT_XDISPLOC
value|35
end_define

begin_comment
comment|/* X Display Location */
end_comment

begin_define
define|#
directive|define
name|TELOPT_OLD_ENVIRON
value|36
end_define

begin_comment
comment|/* Old - Environment variables */
end_comment

begin_define
define|#
directive|define
name|TELOPT_AUTHENTICATION
value|37
end_define

begin_comment
comment|/* Authenticate */
end_comment

begin_define
define|#
directive|define
name|TELOPT_ENCRYPT
value|38
end_define

begin_comment
comment|/* Encryption option */
end_comment

begin_define
define|#
directive|define
name|TELOPT_NEW_ENVIRON
value|39
end_define

begin_comment
comment|/* New - Environment variables */
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

begin_define
define|#
directive|define
name|NTELOPTS
value|(1+TELOPT_NEW_ENVIRON)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TELOPTS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|telopts
index|[
name|NTELOPTS
operator|+
literal|1
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
block|,
literal|"TACACS UID"
block|,
literal|"OUTPUT MARKING"
block|,
literal|"TTYLOC"
block|,
literal|"3270 REGIME"
block|,
literal|"X.3 PAD"
block|,
literal|"NAWS"
block|,
literal|"TSPEED"
block|,
literal|"LFLOW"
block|,
literal|"LINEMODE"
block|,
literal|"XDISPLOC"
block|,
literal|"OLD-ENVIRON"
block|,
literal|"AUTHENTICATION"
block|,
literal|"ENCRYPT"
block|,
literal|"NEW-ENVIRON"
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TELOPT_FIRST
value|TELOPT_BINARY
end_define

begin_define
define|#
directive|define
name|TELOPT_LAST
value|TELOPT_NEW_ENVIRON
end_define

begin_define
define|#
directive|define
name|TELOPT_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)<= TELOPT_LAST)
end_define

begin_define
define|#
directive|define
name|TELOPT
parameter_list|(
name|x
parameter_list|)
value|telopts[(x)-TELOPT_FIRST]
end_define

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

begin_define
define|#
directive|define
name|TELQUAL_INFO
value|2
end_define

begin_comment
comment|/* ENVIRON: informational version of IS */
end_comment

begin_define
define|#
directive|define
name|TELQUAL_REPLY
value|2
end_define

begin_comment
comment|/* AUTHENTICATION: client version of IS */
end_comment

begin_define
define|#
directive|define
name|TELQUAL_NAME
value|3
end_define

begin_comment
comment|/* AUTHENTICATION: client version of IS */
end_comment

begin_define
define|#
directive|define
name|LFLOW_OFF
value|0
end_define

begin_comment
comment|/* Disable remote flow control */
end_comment

begin_define
define|#
directive|define
name|LFLOW_ON
value|1
end_define

begin_comment
comment|/* Enable remote flow control */
end_comment

begin_define
define|#
directive|define
name|LFLOW_RESTART_ANY
value|2
end_define

begin_comment
comment|/* Restart output on any char */
end_comment

begin_define
define|#
directive|define
name|LFLOW_RESTART_XON
value|3
end_define

begin_comment
comment|/* Restart output only on XON */
end_comment

begin_comment
comment|/*  * LINEMODE suboptions  */
end_comment

begin_define
define|#
directive|define
name|LM_MODE
value|1
end_define

begin_define
define|#
directive|define
name|LM_FORWARDMASK
value|2
end_define

begin_define
define|#
directive|define
name|LM_SLC
value|3
end_define

begin_define
define|#
directive|define
name|MODE_EDIT
value|0x01
end_define

begin_define
define|#
directive|define
name|MODE_TRAPSIG
value|0x02
end_define

begin_define
define|#
directive|define
name|MODE_ACK
value|0x04
end_define

begin_define
define|#
directive|define
name|MODE_SOFT_TAB
value|0x08
end_define

begin_define
define|#
directive|define
name|MODE_LIT_ECHO
value|0x10
end_define

begin_define
define|#
directive|define
name|MODE_MASK
value|0x1f
end_define

begin_comment
comment|/* Not part of protocol, but needed to simplify things... */
end_comment

begin_define
define|#
directive|define
name|MODE_FLOW
value|0x0100
end_define

begin_define
define|#
directive|define
name|MODE_ECHO
value|0x0200
end_define

begin_define
define|#
directive|define
name|MODE_INBIN
value|0x0400
end_define

begin_define
define|#
directive|define
name|MODE_OUTBIN
value|0x0800
end_define

begin_define
define|#
directive|define
name|MODE_FORCE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SLC_SYNCH
value|1
end_define

begin_define
define|#
directive|define
name|SLC_BRK
value|2
end_define

begin_define
define|#
directive|define
name|SLC_IP
value|3
end_define

begin_define
define|#
directive|define
name|SLC_AO
value|4
end_define

begin_define
define|#
directive|define
name|SLC_AYT
value|5
end_define

begin_define
define|#
directive|define
name|SLC_EOR
value|6
end_define

begin_define
define|#
directive|define
name|SLC_ABORT
value|7
end_define

begin_define
define|#
directive|define
name|SLC_EOF
value|8
end_define

begin_define
define|#
directive|define
name|SLC_SUSP
value|9
end_define

begin_define
define|#
directive|define
name|SLC_EC
value|10
end_define

begin_define
define|#
directive|define
name|SLC_EL
value|11
end_define

begin_define
define|#
directive|define
name|SLC_EW
value|12
end_define

begin_define
define|#
directive|define
name|SLC_RP
value|13
end_define

begin_define
define|#
directive|define
name|SLC_LNEXT
value|14
end_define

begin_define
define|#
directive|define
name|SLC_XON
value|15
end_define

begin_define
define|#
directive|define
name|SLC_XOFF
value|16
end_define

begin_define
define|#
directive|define
name|SLC_FORW1
value|17
end_define

begin_define
define|#
directive|define
name|SLC_FORW2
value|18
end_define

begin_define
define|#
directive|define
name|NSLC
value|18
end_define

begin_comment
comment|/*  * For backwards compatability, we define SLC_NAMES to be the  * list of names if SLC_NAMES is not defined.  */
end_comment

begin_define
define|#
directive|define
name|SLC_NAMELIST
value|"0", "SYNCH", "BRK", "IP", "AO", "AYT", "EOR", \ 			"ABORT", "EOF", "SUSP", "EC", "EL", "EW", "RP", \ 			"LNEXT", "XON", "XOFF", "FORW1", "FORW2", 0,
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SLC_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|slc_names
index|[]
init|=
block|{
name|SLC_NAMELIST
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|slc_names
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SLC_NAMES
value|SLC_NAMELIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SLC_NAME_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)<= NSLC)
end_define

begin_define
define|#
directive|define
name|SLC_NAME
parameter_list|(
name|x
parameter_list|)
value|slc_names[x]
end_define

begin_define
define|#
directive|define
name|SLC_NOSUPPORT
value|0
end_define

begin_define
define|#
directive|define
name|SLC_CANTCHANGE
value|1
end_define

begin_define
define|#
directive|define
name|SLC_VARIABLE
value|2
end_define

begin_define
define|#
directive|define
name|SLC_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|SLC_LEVELBITS
value|0x03
end_define

begin_define
define|#
directive|define
name|SLC_FUNC
value|0
end_define

begin_define
define|#
directive|define
name|SLC_FLAGS
value|1
end_define

begin_define
define|#
directive|define
name|SLC_VALUE
value|2
end_define

begin_define
define|#
directive|define
name|SLC_ACK
value|0x80
end_define

begin_define
define|#
directive|define
name|SLC_FLUSHIN
value|0x40
end_define

begin_define
define|#
directive|define
name|SLC_FLUSHOUT
value|0x20
end_define

begin_define
define|#
directive|define
name|OLD_ENV_VAR
value|1
end_define

begin_define
define|#
directive|define
name|OLD_ENV_VALUE
value|0
end_define

begin_define
define|#
directive|define
name|NEW_ENV_VAR
value|0
end_define

begin_define
define|#
directive|define
name|NEW_ENV_VALUE
value|1
end_define

begin_define
define|#
directive|define
name|ENV_ESC
value|2
end_define

begin_define
define|#
directive|define
name|ENV_USERVAR
value|3
end_define

begin_comment
comment|/*  * AUTHENTICATION suboptions  */
end_comment

begin_comment
comment|/*  * Who is authenticating who ...  */
end_comment

begin_define
define|#
directive|define
name|AUTH_WHO_CLIENT
value|0
end_define

begin_comment
comment|/* Client authenticating server */
end_comment

begin_define
define|#
directive|define
name|AUTH_WHO_SERVER
value|1
end_define

begin_comment
comment|/* Server authenticating client */
end_comment

begin_define
define|#
directive|define
name|AUTH_WHO_MASK
value|1
end_define

begin_comment
comment|/*  * amount of authentication done  */
end_comment

begin_define
define|#
directive|define
name|AUTH_HOW_ONE_WAY
value|0
end_define

begin_define
define|#
directive|define
name|AUTH_HOW_MUTUAL
value|2
end_define

begin_define
define|#
directive|define
name|AUTH_HOW_MASK
value|2
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_NULL
value|0
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_KERBEROS_V4
value|1
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_KERBEROS_V5
value|2
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_SPX
value|3
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_MINK
value|4
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_SRA
value|5
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_CNT
value|6
end_define

begin_comment
comment|/* #define	AUTHTYPE_UNSECURE 6 */
end_comment

begin_define
define|#
directive|define
name|AUTHTYPE_TEST
value|99
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|authtype_names
index|[]
init|=
block|{
literal|"NULL"
block|,
literal|"KERBEROS_V4"
block|,
literal|"KERBEROS_V5"
block|,
literal|"SPX"
block|,
literal|"MINK"
block|,
literal|"SRA"
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|authtype_names
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AUTHTYPE_NAME_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)< AUTHTYPE_CNT)
end_define

begin_define
define|#
directive|define
name|AUTHTYPE_NAME
parameter_list|(
name|x
parameter_list|)
value|authtype_names[x]
end_define

begin_comment
comment|/*  * ENCRYPTion suboptions  */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_IS
value|0
end_define

begin_comment
comment|/* I pick encryption type ... */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_SUPPORT
value|1
end_define

begin_comment
comment|/* I support encryption types ... */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_REPLY
value|2
end_define

begin_comment
comment|/* Initial setup response */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_START
value|3
end_define

begin_comment
comment|/* Am starting to send encrypted */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_END
value|4
end_define

begin_comment
comment|/* Am ending encrypted */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_REQSTART
value|5
end_define

begin_comment
comment|/* Request you start encrypting */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_REQEND
value|6
end_define

begin_comment
comment|/* Request you send encrypting */
end_comment

begin_define
define|#
directive|define
name|ENCRYPT_ENC_KEYID
value|7
end_define

begin_define
define|#
directive|define
name|ENCRYPT_DEC_KEYID
value|8
end_define

begin_define
define|#
directive|define
name|ENCRYPT_CNT
value|9
end_define

begin_define
define|#
directive|define
name|ENCTYPE_ANY
value|0
end_define

begin_define
define|#
directive|define
name|ENCTYPE_DES_CFB64
value|1
end_define

begin_define
define|#
directive|define
name|ENCTYPE_DES_OFB64
value|2
end_define

begin_define
define|#
directive|define
name|ENCTYPE_CNT
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPT_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|encrypt_names
index|[]
init|=
block|{
literal|"IS"
block|,
literal|"SUPPORT"
block|,
literal|"REPLY"
block|,
literal|"START"
block|,
literal|"END"
block|,
literal|"REQUEST-START"
block|,
literal|"REQUEST-END"
block|,
literal|"ENC-KEYID"
block|,
literal|"DEC-KEYID"
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|enctype_names
index|[]
init|=
block|{
literal|"ANY"
block|,
literal|"DES_CFB64"
block|,
literal|"DES_OFB64"
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|encrypt_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|enctype_names
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENCRYPT_NAME_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)< ENCRYPT_CNT)
end_define

begin_define
define|#
directive|define
name|ENCRYPT_NAME
parameter_list|(
name|x
parameter_list|)
value|encrypt_names[x]
end_define

begin_define
define|#
directive|define
name|ENCTYPE_NAME_OK
parameter_list|(
name|x
parameter_list|)
value|((unsigned int)(x)< ENCTYPE_CNT)
end_define

begin_define
define|#
directive|define
name|ENCTYPE_NAME
parameter_list|(
name|x
parameter_list|)
value|enctype_names[x]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TELNET_H_ */
end_comment

end_unit

