begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h  * This file was produced by running the Configure script.  * Feel free to modify any of this as the need arises.  */
end_comment

begin_comment
comment|/* name of the site.  May be overridden by gethostname, uname, etc. */
end_comment

begin_define
define|#
directive|define
name|SITENAME
value|"ucbvax"
end_define

begin_comment
comment|/* name of the organization, may be a file name */
end_comment

begin_define
define|#
directive|define
name|ORGNAME
value|"University of California, Berkeley"
end_define

begin_comment
comment|/* login name of news administrator, if any. */
end_comment

begin_undef
undef|#
directive|undef
name|NEWSADMIN
name|"
name|root"
end_undef

begin_comment
comment|/* news library, may use only ~ and %l expansion */
end_comment

begin_define
define|#
directive|define
name|LIB
value|"/usr/spool/news/lib"
end_define

begin_comment
comment|/* rn private library, may use ~ expansion, %x and %l */
end_comment

begin_define
define|#
directive|define
name|RNLIB
value|"/usr/local/lib/rn"
end_define

begin_comment
comment|/* location of the news spool directory, may use ~ expansion, %x and %l */
end_comment

begin_define
define|#
directive|define
name|SPOOL
value|"/tmp"
end_define

begin_comment
comment|/* location of the active file, may use ~ expansion, %x and %l */
end_comment

begin_define
define|#
directive|define
name|ACTIVE
value|"/usr/spool/news/lib/active"
end_define

begin_comment
comment|/* location of spooled mail */
end_comment

begin_define
define|#
directive|define
name|MAILFILE
value|"/usr/spool/mail/%L"
end_define

begin_comment
comment|/* default shell--ok to be a slow shell like csh */
end_comment

begin_define
define|#
directive|define
name|PREFSHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* default editor */
end_comment

begin_define
define|#
directive|define
name|DEFEDITOR
value|"/usr/ucb/vi"
end_define

begin_comment
comment|/* root uid */
end_comment

begin_define
define|#
directive|define
name|ROOTID
value|0
end_define

begin_comment
comment|/* what is the first character of a mailbox? */
end_comment

begin_define
define|#
directive|define
name|MBOXCHAR
value|'F'
end_define

begin_comment
comment|/* how to cancel an article */
end_comment

begin_define
define|#
directive|define
name|CANCEL
value|"/usr/spool/news/lib/inews -h<%h"
end_define

begin_comment
comment|/* distribution groups */
end_comment

begin_define
define|#
directive|define
name|LOCDIST
value|"local"
end_define

begin_define
define|#
directive|define
name|ORGDIST
value|"ucb"
end_define

begin_define
define|#
directive|define
name|CITYDIST
value|"ba"
end_define

begin_define
define|#
directive|define
name|STATEDIST
value|"ca"
end_define

begin_define
define|#
directive|define
name|CNTRYDIST
value|"usa"
end_define

begin_define
define|#
directive|define
name|CONTDIST
value|"na"
end_define

begin_undef
undef|#
directive|undef
name|index
name|strchr
end_undef

begin_comment
comment|/* cultural */
end_comment

begin_undef
undef|#
directive|undef
name|rindex
name|strrchr
end_undef

begin_comment
comment|/*  differences? */
end_comment

begin_undef
undef|#
directive|undef
name|void
name|int
end_undef

begin_comment
comment|/* is void to be avoided? */
end_comment

begin_undef
undef|#
directive|undef
name|vfork
name|fork
end_undef

begin_comment
comment|/* is vfork too virtual? */
end_comment

begin_undef
undef|#
directive|undef
name|EUNICE
end_undef

begin_comment
comment|/* no linking? */
end_comment

begin_undef
undef|#
directive|undef
name|VMS
end_undef

begin_comment
comment|/* not currently used, here just in case */
end_comment

begin_undef
undef|#
directive|undef
name|USENDIR
end_undef

begin_comment
comment|/* include ndir.c? */
end_comment

begin_undef
undef|#
directive|undef
name|LIBNDIR
end_undef

begin_comment
comment|/* include /usr/include/ndir.h? */
end_comment

begin_define
define|#
directive|define
name|MININACT
end_define

begin_comment
comment|/* include 2.10.2 optimization? */
end_comment

begin_define
define|#
directive|define
name|PORTABLE
end_define

begin_comment
comment|/* do we do extra lookups to start up? */
end_comment

begin_define
define|#
directive|define
name|PASSNAMES
end_define

begin_comment
comment|/* do names come from the passwd file? */
end_comment

begin_comment
comment|/*  (undef to take name from ~/.fullname) */
end_comment

begin_define
define|#
directive|define
name|BERKNAMES
end_define

begin_comment
comment|/* if so, are they Berkeley format? */
end_comment

begin_comment
comment|/* (that is, ":name,stuff:") */
end_comment

begin_undef
undef|#
directive|undef
name|USGNAMES
end_undef

begin_comment
comment|/* or are they USG format? */
end_comment

begin_comment
comment|/* (that is, ":stuff-name(stuff):") */
end_comment

begin_undef
undef|#
directive|undef
name|WHOAMI
end_undef

begin_comment
comment|/* should we include whoami.h? */
end_comment

begin_undef
undef|#
directive|undef
name|TERMIO
end_undef

begin_comment
comment|/* is this a termio system? */
end_comment

begin_define
define|#
directive|define
name|FCNTL
end_define

begin_comment
comment|/* should we include fcntl.h? */
end_comment

begin_define
define|#
directive|define
name|IOCTL
end_define

begin_comment
comment|/* are ioctl args all defined in one place? */
end_comment

begin_define
define|#
directive|define
name|NORMSIG
end_define

begin_comment
comment|/* use signal rather than sigset? */
end_comment

begin_define
define|#
directive|define
name|HAVETERMLIB
end_define

begin_comment
comment|/* do we have termlib-style routines? */
end_comment

begin_undef
undef|#
directive|undef
name|GETPWENT
end_undef

begin_comment
comment|/* need we include slow getpwent? */
end_comment

begin_undef
undef|#
directive|undef
name|INTERNET
end_undef

begin_comment
comment|/* does our mailer do INTERNET addressing? */
end_comment

begin_define
define|#
directive|define
name|GETHOSTNAME
end_define

begin_comment
comment|/* do we have a gethostname function? */
end_comment

begin_undef
undef|#
directive|undef
name|DOUNAME
end_undef

begin_comment
comment|/* do we have a uname function? */
end_comment

begin_undef
undef|#
directive|undef
name|PHOSTNAME
name|"
name|hostname"
end_undef

begin_comment
comment|/* how to get host name with popen */
end_comment

begin_define
define|#
directive|define
name|SERVER
end_define

begin_define
define|#
directive|define
name|SERVER_HOST
value|"ucbvax"
end_define

end_unit

