begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software_Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * supmsg.h - global definitions/variables used in msg routines.  *  **********************************************************************  * HISTORY  *  * 7-July-93  Nate Williams at Montana State University  *	Modified SUP to use gzip based compression when sending files  *	across the network to save BandWidth  *  * $Log: supmsg.h,v $  * Revision 1.1.1.1  1993/08/21  00:46:35  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:19  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.7  92/08/11  12:08:20  mrt  * 	Added copyright.  * 	[92/08/10            mrt]  *   * Revision 1.6  89/08/23  14:56:42  gm0w  * 	Changed MSGF to MSG constants.  * 	[89/08/23            gm0w]  *   * 27-Dec-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added crosspatch support.  Removed nameserver support.  *  * 29-Jun-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added "release" support.  *  * 27-May-87  Doug Philips (dwp) at Carnegie-Mellon University  *	Added MSGFDONE and subvalues, added doneack and donereason.  *  * 20-May-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added changes to make lint happy.  *  * 04-Jan-86  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Changed hostname to hostT to support multiple repositories per  *	collection.  Added FSETUPBUSY to tell clients that server is  *	currently busy.  *  * 19-Dec-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Created.  *  **********************************************************************  */
end_comment

begin_comment
comment|/* Special messages reserved for SCM */
end_comment

begin_define
define|#
directive|define
name|MSGGOAWAY
value|(-1)
end_define

begin_comment
comment|/* see scm.c */
end_comment

begin_comment
comment|/* Message types -- see supmsg.c */
end_comment

begin_define
define|#
directive|define
name|MSGSIGNON
value|(101)
end_define

begin_define
define|#
directive|define
name|MSGSIGNONACK
value|(102)
end_define

begin_define
define|#
directive|define
name|MSGSETUP
value|(103)
end_define

begin_define
define|#
directive|define
name|MSGSETUPACK
value|(104)
end_define

begin_define
define|#
directive|define
name|MSGLOGIN
value|(105)
end_define

begin_define
define|#
directive|define
name|MSGLOGACK
value|(106)
end_define

begin_define
define|#
directive|define
name|MSGCRYPT
value|(107)
end_define

begin_define
define|#
directive|define
name|MSGCRYPTOK
value|(108)
end_define

begin_define
define|#
directive|define
name|MSGREFUSE
value|(109)
end_define

begin_define
define|#
directive|define
name|MSGLIST
value|(110)
end_define

begin_define
define|#
directive|define
name|MSGNEED
value|(111)
end_define

begin_define
define|#
directive|define
name|MSGDENY
value|(112)
end_define

begin_define
define|#
directive|define
name|MSGSEND
value|(113)
end_define

begin_define
define|#
directive|define
name|MSGRECV
value|(114)
end_define

begin_define
define|#
directive|define
name|MSGDONE
value|(115)
end_define

begin_define
define|#
directive|define
name|MSGXPATCH
value|(117)
end_define

begin_define
define|#
directive|define
name|MSGCOMPRESS
value|(118)
end_define

begin_comment
comment|/* MSGSETUPACK data codes - setupack */
end_comment

begin_define
define|#
directive|define
name|FSETUPOK
value|(999)
end_define

begin_define
define|#
directive|define
name|FSETUPHOST
value|(998)
end_define

begin_define
define|#
directive|define
name|FSETUPSAME
value|(997)
end_define

begin_define
define|#
directive|define
name|FSETUPOLD
value|(996)
end_define

begin_define
define|#
directive|define
name|FSETUPBUSY
value|(995)
end_define

begin_define
define|#
directive|define
name|FSETUPRELEASE
value|(994)
end_define

begin_comment
comment|/* MSGLOGACK data codes - loginack */
end_comment

begin_define
define|#
directive|define
name|FLOGOK
value|(989)
end_define

begin_define
define|#
directive|define
name|FLOGNG
value|(988)
end_define

begin_comment
comment|/* MSGDONE data codes - doneack */
end_comment

begin_define
define|#
directive|define
name|FDONESUCCESS
value|(979)
end_define

begin_define
define|#
directive|define
name|FDONEDONTLOG
value|(978)
end_define

begin_define
define|#
directive|define
name|FDONESRVERROR
value|(977)
end_define

begin_define
define|#
directive|define
name|FDONEUSRERROR
value|(976)
end_define

begin_define
define|#
directive|define
name|FDONEGOAWAY
value|(975)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MSGSUBR
end_ifdef

begin_comment
comment|/* used in all msg routines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we are the server */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|protver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protocol version of partner */
end_comment

begin_else
else|#
directive|else
else|MSGSUBR
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MSGFILE
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_else
else|#
directive|else
else|MSGFILE
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
endif|MSGFILE
end_endif

begin_comment
comment|/* used in all msg routines */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we are the server */
end_comment

begin_comment
comment|/* msggoaway */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|goawayreason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reason for goaway */
end_comment

begin_comment
comment|/* msgsignon */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|pgmversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* version of this program */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|protver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protocol version of partner */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|pgmver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program version of partner */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|scmver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scm version of partner */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|fspid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process id of fileserver */
end_comment

begin_comment
comment|/* msgsetup */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|xpatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setup crosspatch to a new client */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|xuser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user for crosspatch */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|collname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* collection name */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|basedir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base directory */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|basedev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base directory device */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|baseino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base directory inode */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|lasttime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of last upgrade */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|listonly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only listing files, no data xfer */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|newonly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only send new files */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|release
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* release name */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|setupack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ack return value for setup */
end_comment

begin_comment
comment|/* msgcrypt */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|crypttest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* encryption test string */
end_comment

begin_comment
comment|/* msglogin */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|logcrypt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* login encryption test */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|loguser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* login username */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|logpswd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* password for login */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|logack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* login ack status */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|logerror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error string from oklogin */
end_comment

begin_comment
comment|/* msgxpatch */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arg count for crosspatch */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arg array for crosspatch */
end_comment

begin_comment
comment|/* msgrefuse */
end_comment

begin_decl_stmt
name|EXTERN
name|TREE
modifier|*
name|refuseT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tree of files to refuse */
end_comment

begin_comment
comment|/* msglist */
end_comment

begin_decl_stmt
name|EXTERN
name|TREE
modifier|*
name|listT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tree of files to list */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|scantime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time that collection was scanned */
end_comment

begin_comment
comment|/* msgneed */
end_comment

begin_decl_stmt
name|EXTERN
name|TREE
modifier|*
name|needT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tree of files to need */
end_comment

begin_comment
comment|/* msgdeny */
end_comment

begin_decl_stmt
name|EXTERN
name|TREE
modifier|*
name|denyT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tree of files to deny */
end_comment

begin_comment
comment|/* msgrecv */
end_comment

begin_comment
comment|/* msgsend */
end_comment

begin_decl_stmt
name|EXTERN
name|TREE
modifier|*
name|upgradeT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to file being upgraded */
end_comment

begin_comment
comment|/* msgdone */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|doneack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* done ack status */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|donereason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if indicated by doneack */
end_comment

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_endif
endif|#
directive|endif
endif|MSGSUBR
end_endif

end_unit

