begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Defaults.h: default values for ftp's common variables */
end_comment

begin_comment
comment|/* These are all surrounded by #ifndef blocks so you can just use  * the -D flag with your compiler (i.e. -DZCAT=\"/usr/local/bin/zcat\").  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEFAULTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEFAULTS_H_
end_define

begin_comment
comment|/*  $RCSfile: defaults.h,v $  *  $Revision: 14020.13 $  *  $Date: 93/07/09 10:58:27 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEWMAILMESSAGE
end_ifndef

begin_comment
comment|/* For english speakers, "You have new mail." */
end_comment

begin_define
define|#
directive|define
name|NEWMAILMESSAGE
value|"You have new mail."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZCAT
end_ifndef

begin_comment
comment|/* Usually "zcat," but use the full pathname */
end_comment

begin_comment
comment|/* if possible. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GZCAT
end_ifdef

begin_comment
comment|/* If you said you had gnu's zcat, use it 								 * since it can do .Z files too. 								 */
end_comment

begin_define
define|#
directive|define
name|ZCAT
value|GZCAT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !GZCAT */
end_comment

begin_define
define|#
directive|define
name|ZCAT
value|"zcat"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef GZCAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef ZCAT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_XFER_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|MAX_XFER_BUFSIZE
value|32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dANONOPEN
end_ifndef

begin_comment
comment|/* 1 or 0, usually 1 */
end_comment

begin_define
define|#
directive|define
name|dANONOPEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dDEBUG
end_ifndef

begin_comment
comment|/* 1 or 0, usually 0 */
end_comment

begin_define
define|#
directive|define
name|dDEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dMPROMPT
end_ifndef

begin_comment
comment|/* Usually 1, I prefer 0... */
end_comment

begin_define
define|#
directive|define
name|dMPROMPT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PASSIVEMODE
end_ifndef

begin_define
define|#
directive|define
name|PASSIVEMODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If passive FTP can be used, this specifies whether it is turned on  * by default.  If not, we have passive mode available, but are using  * Port ftp by default.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|dPASSIVE
end_ifndef

begin_define
define|#
directive|define
name|dPASSIVE
value|1
end_define

begin_comment
comment|/* Works for most folks... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dVERBOSE
end_ifndef

begin_comment
comment|/* V_QUIET, V_ERRS, V_TERSE, V_VERBOSE */
end_comment

begin_define
define|#
directive|define
name|dVERBOSE
value|V_TERSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dPROMPT
end_ifndef

begin_comment
comment|/* short: "@Bftp@P>" */
end_comment

begin_comment
comment|/* long: "@B@E @UNcFTP@P @B@M@D@P ->" */
end_comment

begin_define
define|#
directive|define
name|dPROMPT
value|"@B@c@Mncftp@P>"
end_define

begin_comment
comment|/* new two line prompt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dPAGER
end_ifndef

begin_comment
comment|/* if set to empty string, act like 'cat' */
end_comment

begin_define
define|#
directive|define
name|dPAGER
value|"more"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dLOGNAME
end_ifndef

begin_comment
comment|/* usu. put in the user's home directory. */
end_comment

begin_define
define|#
directive|define
name|dLOGNAME
value|"~/.ftplog"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dRECENTF
end_ifndef

begin_comment
comment|/* usu. put in the user's home directory. */
end_comment

begin_define
define|#
directive|define
name|dRECENTF
value|"~/.ncrecent"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dMAXRECENTS
end_ifndef

begin_comment
comment|/* limit to how many recent sites to save. */
end_comment

begin_define
define|#
directive|define
name|dMAXRECENTS
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dRECENT_ON
end_ifndef

begin_comment
comment|/* Do you want the recent log on? */
end_comment

begin_comment
comment|/* usually 1. */
end_comment

begin_define
define|#
directive|define
name|dRECENT_ON
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do you want logging on by default? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|dLOGGING
end_ifndef

begin_comment
comment|/* usually 0 */
end_comment

begin_define
define|#
directive|define
name|dLOGGING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dTYPE
end_ifndef

begin_comment
comment|/* usually TYPE_A */
end_comment

begin_define
define|#
directive|define
name|dTYPE
value|TYPE_A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dTYPESTR
end_ifndef

begin_comment
comment|/* usually "ascii" */
end_comment

begin_define
define|#
directive|define
name|dTYPESTR
value|"ascii"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dREDIALDELAY
end_ifndef

begin_comment
comment|/* usu. 60 (seconds). */
end_comment

begin_define
define|#
directive|define
name|dREDIALDELAY
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CMDLINELEN
end_ifndef

begin_define
define|#
directive|define
name|CMDLINELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RECEIVEDLINELEN
end_ifndef

begin_define
define|#
directive|define
name|RECEIVEDLINELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXMACROS
end_ifndef

begin_define
define|#
directive|define
name|MAXMACROS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACBUFLEN
end_ifndef

begin_comment
comment|/* usually 4096. */
end_comment

begin_define
define|#
directive|define
name|MACBUFLEN
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do you want binary transfers by default? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|dAUTOBINARY
end_ifndef

begin_comment
comment|/* usually 1 */
end_comment

begin_define
define|#
directive|define
name|dAUTOBINARY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dPROGRESS
end_ifndef

begin_define
define|#
directive|define
name|dPROGRESS
value|pr_philbar
end_define

begin_comment
comment|/* can be: pr_none, pr_percent, pr_philbar, 								 * or pr_kbytes 								 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default login name at gateway */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|dGATEWAY_LOGIN
end_ifndef

begin_define
define|#
directive|define
name|dGATEWAY_LOGIN
value|"ftp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFAULTS_H_ */
end_comment

begin_comment
comment|/* eof */
end_comment

end_unit

