begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	This file contains the constants that must be reset on each system  *	when notefiles are first installed.  Other constants exist in  *	structs.h, but in general should not be modified unless needed.  */
end_comment

begin_define
define|#
directive|define
name|Sysname
value|"ucbmonet"
end_define

begin_comment
comment|/* this sytem name */
end_comment

begin_define
define|#
directive|define
name|BERKELEY
end_define

begin_comment
comment|/* use machine.user, LFLUSHO, router, mh */
end_comment

begin_define
define|#
directive|define
name|MSTDIR
value|"/usr/spool/notes"
end_define

begin_define
define|#
directive|define
name|BIN
value|"/usr/new"
end_define

begin_define
define|#
directive|define
name|NOTESUID
value|1558
end_define

begin_comment
comment|/* owner of system */
end_comment

begin_define
define|#
directive|define
name|ANONUID
value|1001
end_define

begin_comment
comment|/* uid of anon notes */
end_comment

begin_comment
comment|/*	make ANONUID an unused uid, because it is never allowed into the */
end_comment

begin_comment
comment|/*	notefile programs  */
end_comment

begin_define
define|#
directive|define
name|ARCHTIME
value|14
end_define

begin_comment
comment|/* default days to archive */
end_comment

begin_define
define|#
directive|define
name|ARCHDIR
value|"/usr/spool/oldnotes"
end_define

begin_define
define|#
directive|define
name|NOTESRC
value|".notesrc"
end_define

begin_comment
comment|/* default subscription file */
end_comment

begin_define
define|#
directive|define
name|AUTOSEQ
value|"autoseq"
end_define

begin_comment
comment|/* auto-sequencer link */
end_comment

begin_comment
comment|/*  *	These define defaults for various Unix functions that can  *	be overidden by environment variables   */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|"/usr/ucb/vi"
end_define

begin_comment
comment|/* default editor */
end_comment

begin_define
define|#
directive|define
name|MAILER
value|"/usr/ucb/Mail"
end_define

begin_comment
comment|/* mailer to use */
end_comment

begin_define
define|#
directive|define
name|ROUTER
value|"/usr/new/lib/notes/pcomp"
end_define

begin_define
define|#
directive|define
name|SUPERMAILER
end_define

begin_comment
comment|/* using smart mailer */
end_comment

begin_define
define|#
directive|define
name|PAGER
value|"/usr/ucb/more"
end_define

begin_comment
comment|/* pg/more default */
end_comment

begin_define
define|#
directive|define
name|WRITE
value|"/bin/write"
end_define

begin_comment
comment|/* user-user communication */
end_comment

begin_comment
comment|/*  *	Definitions dependent on the UNIX OS you are using  */
end_comment

begin_comment
comment|/*#define	V6				/* version 6 kernel */
end_comment

begin_comment
comment|/*#define	UNIX4.0				/* Unix 4.0 kernel */
end_comment

begin_define
define|#
directive|define
name|BSD4
value|.1c
end_define

begin_comment
comment|/* Berkeley 4.1cBSD kernel */
end_comment

begin_define
define|#
directive|define
name|VFORK
end_define

begin_comment
comment|/* vfork call available */
end_comment

begin_define
define|#
directive|define
name|UIDMASK
value|0177777
end_define

begin_comment
comment|/* mask out high UID bits */
end_comment

begin_define
define|#
directive|define
name|GIDMASK
value|0177777
end_define

begin_comment
comment|/* mask out high GID bits */
end_comment

begin_comment
comment|/*  *	Some other definitions.  */
end_comment

begin_define
define|#
directive|define
name|PROMPT
value|"? "
end_define

begin_comment
comment|/* command prompt */
end_comment

begin_define
define|#
directive|define
name|AUTOCREATE
end_define

begin_comment
comment|/* auto creation newsgroups */
end_comment

begin_define
define|#
directive|define
name|NOSUCHWARN
value|"nfmaint"
end_define

begin_comment
comment|/* "can't find" net nfs */
end_comment

begin_define
define|#
directive|define
name|OLDGROUP
value|30
end_define

begin_comment
comment|/* 30 day group expiration */
end_comment

begin_define
define|#
directive|define
name|NOTESUMASK
value|022
end_define

begin_define
define|#
directive|define
name|DUMPCORE
end_define

begin_comment
comment|/* trapped internal error dumps core */
end_comment

begin_comment
comment|/* #define		NEWS */
end_comment

begin_comment
comment|/* #define		DEMANDNEWS			/* news output on demand */
end_comment

begin_define
define|#
directive|define
name|BNEWS
end_define

begin_comment
comment|/* if running Bnews */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BNEWS
end_ifdef

begin_comment
comment|/* for B news systems */
end_comment

begin_define
define|#
directive|define
name|TONEWS
value|"inews -t %s -n %s -f %s"
end_define

begin_comment
comment|/* B news insertion */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TONEWS
value|"news -i %s -n %s"
end_define

begin_comment
comment|/* A news insertion */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

