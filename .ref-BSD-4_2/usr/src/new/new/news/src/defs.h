begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * defs.h - defines for news-related programs.  *  * If you remove any lines here or in your Makefile, make the change  * to localize.sh so you won't have to redo it for each news release.  *  * If TMAIL is undefined, the -M option will be disabled.  *  * By convention, the version of the software you are running is taken  * to be news_version below.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|news_version
init|=
literal|"B 2.10.1 6/24/83"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCCS ID @(#)defs.dist	2.23 (hand edited)	5/3/83 */
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
value|1
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
value|000
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
name|DFLTSUB
value|"general,all.general"
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
comment|/* Mandatory subscription list		*/
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
name|INEWS
value|"/usr/new/inews"
end_define

begin_comment
comment|/* inews for recnews to fork	*/
end_comment

begin_define
define|#
directive|define
name|FOLLOWUP
value|INEWS
end_define

begin_define
define|#
directive|define
name|RNEWS
value|"/usr/new/rnews"
end_define

begin_comment
comment|/* rnews for uurec to fork	*/
end_comment

begin_comment
comment|/* If you change rnews, see Makefile too*/
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
value|"uux - -r -z %s!rnews< %s"
end_define

begin_comment
comment|/* your uux can't do it	*/
end_comment

begin_define
define|#
directive|define
name|UXMIT
value|"uux -r -z -c %s!rnews '<' %s"
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

begin_define
define|#
directive|define
name|BATCH
value|"/usr/new/lib/news/unbatch"
end_define

begin_comment
comment|/* name of unbatcher 		*/
end_comment

begin_define
define|#
directive|define
name|BATCHDIR
value|"/usr/spool/batch"
end_define

begin_comment
comment|/* dir all batching files are in*/
end_comment

begin_comment
comment|/* #define BERKNAME "ARPAVAX"	/* name of local host on Berknet	*/
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
value|".UUCP"
end_define

begin_comment
comment|/* Local domain				*/
end_comment

begin_comment
comment|/* #define AUTONEWNG		/* Believe new unrecognized newsgroups	*/
end_comment

begin_comment
comment|/* #define CHEAP		/* don't chown files to news		*/
end_comment

begin_define
define|#
directive|define
name|OLD
end_define

begin_comment
comment|/* Add extra headers for old neighbors	*/
end_comment

begin_comment
comment|/* #define UNAME		/* If uname call is available.		*/
end_comment

begin_comment
comment|/* #define GHNAME		/* If gethostname call is available.	*/
end_comment

begin_comment
comment|/* #define NOCOLON		/* Don't do :.  Will go away in 2.11.	*/
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
name|MYORG
value|"U.C. Berkeley"
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

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

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
name|SYSPATH
value|"PATH=/usr/new:/usr/ucb:/bin:/usr/bin"
end_define

begin_comment
comment|/* default, secure, vanilla path */
end_comment

begin_define
define|#
directive|define
name|LNCNT
value|16
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
value|64
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
value|"!:.@^%"
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
name|NGFSIZ
value|5000
end_define

begin_comment
comment|/* legal newsgroup file size			*/
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

end_unit

