begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pathnames.h	2.6	83/08/11	*/
end_comment

begin_comment
comment|/*  * Declarations and constants specific to an installation.  *  * Vax/Unix version 7.  */
end_comment

begin_define
define|#
directive|define
name|GETHOST
end_define

begin_comment
comment|/* System has gethostname syscall */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GETHOST
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|EMPTYID
end_define

begin_comment
comment|/* Dynamically determined local host */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCAL
value|'j'
end_define

begin_comment
comment|/* Local host id */
end_comment

begin_endif
endif|#
directive|endif
endif|GETHOST
end_endif

begin_define
define|#
directive|define
name|MAIL
value|"/bin/mail"
end_define

begin_comment
comment|/* Name of mail sender */
end_comment

begin_define
define|#
directive|define
name|SENDMAIL
value|"/usr/lib/sendmail"
end_define

begin_comment
comment|/* Name of classy mail deliverer */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|"/usr/ucb/ex"
end_define

begin_comment
comment|/* Name of text editor */
end_comment

begin_define
define|#
directive|define
name|VISUAL
value|"/usr/ucb/vi"
end_define

begin_comment
comment|/* Name of display editor */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* Standard shell */
end_comment

begin_define
define|#
directive|define
name|MORE
value|"/usr/ucb/more"
end_define

begin_comment
comment|/* Standard output pager */
end_comment

begin_define
define|#
directive|define
name|HELPFILE
value|"/usr/lib/Mail.help"
end_define

begin_comment
comment|/* Name of casual help file */
end_comment

begin_define
define|#
directive|define
name|THELPFILE
value|"/usr/lib/Mail.help.~"
end_define

begin_define
define|#
directive|define
name|POSTAGE
value|"/usr/adm/maillog"
end_define

begin_comment
comment|/* Where to audit mail sending */
end_comment

begin_comment
comment|/* Name of casual tilde help */
end_comment

begin_define
define|#
directive|define
name|UIDMASK
value|0177777
end_define

begin_comment
comment|/* Significant uid bits */
end_comment

begin_define
define|#
directive|define
name|MASTER
value|"/usr/lib/Mail.rc"
end_define

begin_define
define|#
directive|define
name|APPEND
end_define

begin_comment
comment|/* New mail goes to end of mailbox */
end_comment

begin_define
define|#
directive|define
name|CANLOCK
end_define

begin_comment
comment|/* Locking protocol actually works */
end_comment

begin_define
define|#
directive|define
name|UTIME
end_define

begin_comment
comment|/* System implements utime(2) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_include
include|#
directive|include
file|"sigretro.h"
end_include

begin_comment
comment|/* Retrofit signal defs */
end_comment

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

end_unit

