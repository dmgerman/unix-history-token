begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	This software is Copyright (c) 1986 by Rick Adams.  *  *	Permission is hereby granted to copy, reproduce, redistribute or  *	otherwise use this software as long as: there is no monetary  *	profit gained specifically from the use or reproduction or this  *	software, it is not sold, rented, traded or otherwise marketed, and  *	this copyright notice is included prominently in any copy  *	made.  *  *	The author make no claims as to the fitness or correctness of  *	this software for any use whatsoever, and it is provided as is.   *	Any use of this software is at the user's own risk.  *  */
end_comment

begin_comment
comment|/*	@(#)defs.dist	2.59	10/15/87	*/
end_comment

begin_comment
comment|/*  * defs.h - defines for news-related programs.  *  * If you remove any lines here or in your Makefile, make the change  * to localize.sh so you won't have to redo it for each news release.  *  * If TMAIL is undefined, the -M option will be disabled.  *  * By convention, the version of the software you are running is taken  * to be news_version below.  */
end_comment

begin_define
define|#
directive|define
name|DAYS
value|(60L*60L*24L)
end_define

begin_define
define|#
directive|define
name|WEEKS
value|(7*DAYS)
end_define

begin_comment
comment|/* Things that very well may require local configuration */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOME
end_ifndef

begin_define
define|#
directive|define
name|ROOTID
value|0
end_define

begin_comment
comment|/* uid of person allowed to cancel anything	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_UMASK
value|002
end_define

begin_comment
comment|/* mask for umask call, 022 for secure system	*/
end_comment

begin_define
define|#
directive|define
name|DFLTEXP
value|2*WEEKS
end_define

begin_comment
comment|/* default no. of seconds to expire in		*/
end_comment

begin_define
define|#
directive|define
name|HISTEXP
value|4*WEEKS
end_define

begin_comment
comment|/* default no. of seconds to forget in		*/
end_comment

begin_define
define|#
directive|define
name|DFLTSUB
value|"general,all.announce"
end_define

begin_comment
comment|/* default subscription list	*/
end_comment

begin_define
define|#
directive|define
name|TMAIL
value|"/usr/ucb/Mail"
end_define

begin_comment
comment|/* Mail program that understands -T	*/
end_comment

begin_define
define|#
directive|define
name|ADMSUB
value|"general,all.announce"
end_define

begin_comment
comment|/* Mandatory subscription list	*/
end_comment

begin_define
define|#
directive|define
name|PAGE
value|"/usr/ucb/more"
end_define

begin_comment
comment|/* Default pager			*/
end_comment

begin_define
define|#
directive|define
name|NOTIFY
value|"usenet"
end_define

begin_comment
comment|/* Tell him about certain ctl messages	*/
end_comment

begin_comment
comment|/* Default xmit command - remove -z if	*/
end_comment

begin_define
define|#
directive|define
name|DFTXMIT
value|"uux - -r -z -gd %s!rnews< %s"
end_define

begin_comment
comment|/* your uux can't do it	*/
end_comment

begin_define
define|#
directive|define
name|UXMIT
value|"uux -r -z -gd -c %s!rnews '<' %s"
end_define

begin_comment
comment|/* If uux -c is ok	*/
end_comment

begin_define
define|#
directive|define
name|DFTEDITOR
value|"vi"
end_define

begin_comment
comment|/* Default editor, see also postnews.	*/
end_comment

begin_comment
comment|/* #define UUPROG "euuname"	/* omit for uuname, put in LIBDIR	*/
end_comment

begin_define
define|#
directive|define
name|MANUALLY
end_define

begin_comment
comment|/* Don't execute rmgroups, just notify.	*/
end_comment

begin_comment
comment|/* #define NONEWGROUPS		/* Don't create new groups, just notify.*/
end_comment

begin_comment
comment|/* #define SPOOLNEWS		/* Spool incoming rnews, don't process	*/
end_comment

begin_comment
comment|/* #define SPOOLINEWS		/* Spool local inews, don't process	*/
end_comment

begin_comment
comment|/* #define LOCALNAME 		/* There is no full name database. 	*/
end_comment

begin_define
define|#
directive|define
name|INTERNET
end_define

begin_comment
comment|/* Internet mail works locally		*/
end_comment

begin_define
define|#
directive|define
name|MYDOMAIN
value|".Berkeley.EDU"
end_define

begin_comment
comment|/* Local domain				*/
end_comment

begin_comment
comment|/* #define CHEAP		/* don't chown files to news		*/
end_comment

begin_comment
comment|/* #define OLD			/* Add extra headers for old neighbors	*/
end_comment

begin_comment
comment|/* #define UNAME		/* If uname call returns your nodename  */
end_comment

begin_define
define|#
directive|define
name|GHNAME
end_define

begin_comment
comment|/* If gethostname call is available.	*/
end_comment

begin_comment
comment|/* #define UUNAME "/etc/uucpname" /* If your nodename is stored in a file */
end_comment

begin_define
define|#
directive|define
name|V7MAIL
end_define

begin_comment
comment|/* Local mail format is V7 ("From ")	*/
end_comment

begin_define
define|#
directive|define
name|SORTACTIVE
end_define

begin_comment
comment|/* if you want news presented in the order of the .newsrc */
end_comment

begin_define
define|#
directive|define
name|ZAPNOTES
end_define

begin_comment
comment|/* if you want old style notes headers moved into the headers */
end_comment

begin_define
define|#
directive|define
name|DIGPAGE
end_define

begin_comment
comment|/* allow digestifying in vnews */
end_comment

begin_define
define|#
directive|define
name|DOXREFS
end_define

begin_comment
comment|/* Generate xref line for rn to use */
end_comment

begin_comment
comment|/* #define MULTICAST		/* If you want to be able to multicast news */
end_comment

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_comment
comment|/* If you are running 4.2  or 4.3 BSD	*/
end_comment

begin_comment
comment|/* #define BSD2_10		/* If you are running 2.10 BSD */
end_comment

begin_comment
comment|/* #define LOCKF		/* If you have the lockf() sys call */
end_comment

begin_comment
comment|/* #define DOGETUSER		/* Always do 'getuser' so can't fake name */
end_comment

begin_comment
comment|/* #define LOGDIR		/* use the 'logdir' call on path lookups */
end_comment

begin_define
define|#
directive|define
name|MKDIRSUB
end_define

begin_comment
comment|/* your system has mkdir as a syscall */
end_comment

begin_comment
comment|/* #define READDIR		/* your system has readdir() in libc */
end_comment

begin_comment
comment|/* #define ALWAYSALIAS		/* temporary kludge for conversion */
end_comment

begin_define
define|#
directive|define
name|SENDMAIL
value|"/usr/lib/sendmail"
end_define

begin_comment
comment|/* command line to run "sendmail" if you have it	*/
end_comment

begin_comment
comment|/* #define MMDF	"/usr/mmdf/submit"	/* command line to run mmdf if you have it */
end_comment

begin_define
define|#
directive|define
name|MYORG
value|"CSRG, UC Berkeley"
end_define

begin_comment
comment|/* My organization.  Please	*/
end_comment

begin_comment
comment|/* include your city (and state, and	*/
end_comment

begin_comment
comment|/* country, if not obvious) in MYORG,	*/
end_comment

begin_comment
comment|/* and please keep it short.		*/
end_comment

begin_comment
comment|/* #define HIDDENNET "frooz"	/* if you have a local network and want */
end_comment

begin_comment
comment|/* The mail address to look like it came */
end_comment

begin_comment
comment|/* from one machine */
end_comment

begin_comment
comment|/* NOTE: The following two macros replace the use of HIDDENNET */
end_comment

begin_comment
comment|/* #define GENERICPATH "frooz"	/* If you are using a shared USENET/UUCP node */
end_comment

begin_comment
comment|/* #define GENERICFROM "Frobozz.COM"	/* If you want generic From:-addresses */
end_comment

begin_comment
comment|/* #define NICENESS	4	/* does a nice(NICENESS) in rnews */
end_comment

begin_comment
comment|/* #define FASCIST	"all,!all.all"	/* only permit posting to certain groups */
end_comment

begin_comment
comment|/* see installation guide for details */
end_comment

begin_comment
comment|/* #define SMALL_ADDRESS_SPACE	/* If your machine can't address> 32767 */
end_comment

begin_comment
comment|/* #define ORGDISTRIB	"froozum"	/* For organization wide control message handling */
end_comment

begin_comment
comment|/* Things you might want to change */
end_comment

begin_define
define|#
directive|define
name|NEWSRC
value|".newsrc"
end_define

begin_comment
comment|/* name of .newsrc file (in home dir)	*/
end_comment

begin_define
define|#
directive|define
name|LINES
value|512
end_define

begin_comment
comment|/* maximum no. of lines in .newsrc		*/
end_comment

begin_define
define|#
directive|define
name|NEGCHAR
value|'!'
end_define

begin_comment
comment|/* newsgroup negation character			*/
end_comment

begin_define
define|#
directive|define
name|DEADTIME
value|45
end_define

begin_comment
comment|/* no. of seconds to wait on deadlock		*/
end_comment

begin_define
define|#
directive|define
name|FMETA
value|'%'
end_define

begin_comment
comment|/* file meta-character for c option		*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pdp11
argument_list|)
operator|||
name|defined
argument_list|(
name|SMALL_ADDRESS_SPACE
argument_list|)
end_if

begin_define
define|#
directive|define
name|BUFLEN
value|128
end_define

begin_comment
comment|/* standard buffer size				*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFLEN
value|256
end_define

begin_comment
comment|/* standard buffer size				*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LBUFLEN
value|1024
end_define

begin_comment
comment|/* big buffer size				*/
end_comment

begin_define
define|#
directive|define
name|SBUFLEN
value|32
end_define

begin_comment
comment|/* small buffer size (for system names, etc)	*/
end_comment

begin_define
define|#
directive|define
name|LNCNT
value|14
end_define

begin_comment
comment|/* Articles with> LNCNT lines go through pager */
end_comment

begin_comment
comment|/* Things you probably won't want to change */
end_comment

begin_define
define|#
directive|define
name|PATHLEN
value|512
end_define

begin_comment
comment|/* length of longest source string		*/
end_comment

begin_define
define|#
directive|define
name|DATELEN
value|64
end_define

begin_comment
comment|/* length of longest allowed date string	*/
end_comment

begin_define
define|#
directive|define
name|NAMELEN
value|128
end_define

begin_comment
comment|/* length of longest possible message ID	*/
end_comment

begin_define
define|#
directive|define
name|SNLN
value|8
end_define

begin_comment
comment|/* max significant characters in sysname	*/
end_comment

begin_define
define|#
directive|define
name|PROTO
value|'A'
end_define

begin_comment
comment|/* old protocol name				*/
end_comment

begin_define
define|#
directive|define
name|NETCHRS
value|"!:@^%,"
end_define

begin_comment
comment|/* Punct. chars used for various networks	*/
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* boolean true					*/
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/* boolean false				*/
end_comment

begin_define
define|#
directive|define
name|PERHAPS
value|2
end_define

begin_comment
comment|/* indeterminate boolean value			*/
end_comment

begin_define
define|#
directive|define
name|NGDELIM
value|','
end_define

begin_comment
comment|/* delimit character in news group line		*/
end_comment

begin_comment
comment|/* for NNTP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER
end_ifdef

begin_include
include|#
directive|include
file|"/usr/src/new/nntp/common/response_codes.h"
end_include

begin_define
define|#
directive|define
name|SERVER_FILE
value|"/usr/new/lib/news/server"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_XENIX
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_XENIX */
end_comment

end_unit

