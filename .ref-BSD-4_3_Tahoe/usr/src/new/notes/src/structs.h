begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RCSIDENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|zzstructs
index|[]
init|=
literal|"$Header: structs.h,v 1.7.0.1 85/03/17 20:57:42 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(RCSIDENT)&& defined(MAINLINE)
end_endif

begin_comment
comment|/*  *	structure definitions for the notesfile program.  *  *	Constants/definitions likely to change with different  *	kernels are included in the file "parms.h".  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* pretty euphemisms */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|NEVER
value|(-1)
end_define

begin_comment
comment|/* expiration stuff */
end_comment

begin_define
define|#
directive|define
name|EDIT
value|TRUE
end_define

begin_comment
comment|/* whether to edit or */
end_comment

begin_define
define|#
directive|define
name|NOEDIT
value|FALSE
end_define

begin_comment
comment|/* not to edit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UID8
end_ifdef

begin_comment
comment|/* 8 bit uids */
end_comment

begin_define
define|#
directive|define
name|UIDMASK
value|0377
end_define

begin_comment
comment|/* mask 8 bit uids */
end_comment

begin_define
define|#
directive|define
name|GIDMASK
value|0377
end_define

begin_comment
comment|/* mask 8 bit gids */
end_comment

begin_else
else|#
directive|else
else|! defined(UID8)
end_else

begin_comment
comment|/* 16 bit uids */
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

begin_endif
endif|#
directive|endif
endif|! defined(UID8)
end_endif

begin_define
define|#
directive|define
name|NETLOG
value|"net.log"
end_define

begin_comment
comment|/* network logfile */
end_comment

begin_define
define|#
directive|define
name|GRIPES
value|"nfgripes"
end_define

begin_comment
comment|/* gripe notesfile */
end_comment

begin_define
define|#
directive|define
name|UTILITY
value|".utilities"
end_define

begin_comment
comment|/* utility directory */
end_comment

begin_define
define|#
directive|define
name|LOCKS
value|".locks"
end_define

begin_comment
comment|/* lock directory */
end_comment

begin_define
define|#
directive|define
name|SEQUENCER
value|".sequencer"
end_define

begin_comment
comment|/* sequencer files */
end_comment

begin_define
define|#
directive|define
name|SEQ
value|".SEQ"
end_define

begin_comment
comment|/* next d_nfnum */
end_comment

begin_define
define|#
directive|define
name|INDXHLP
value|"index.help"
end_define

begin_comment
comment|/* index page help */
end_comment

begin_define
define|#
directive|define
name|RDMHLP
value|"read.help"
end_define

begin_comment
comment|/* readem page help file */
end_comment

begin_define
define|#
directive|define
name|LIMHLP
value|"lim.help"
end_define

begin_comment
comment|/* help for limited index */
end_comment

begin_define
define|#
directive|define
name|ACCHLP
value|"access.help"
end_define

begin_comment
comment|/* for access editor */
end_comment

begin_define
define|#
directive|define
name|DIRHLP
value|"dir.help"
end_define

begin_comment
comment|/* for director options */
end_comment

begin_define
define|#
directive|define
name|AVAILHLP
value|"avail.notes"
end_define

begin_comment
comment|/* list of public notefiles */
end_comment

begin_define
define|#
directive|define
name|NFCOMMENT
value|"nfcomment"
end_define

begin_comment
comment|/* nfcomment routine */
end_comment

begin_define
define|#
directive|define
name|ARCHALIAS
value|"Archive-into"
end_define

begin_comment
comment|/* archive mapping */
end_comment

begin_define
define|#
directive|define
name|TEXT
value|"text"
end_define

begin_comment
comment|/* name of text file */
end_comment

begin_define
define|#
directive|define
name|INDEXN
value|"note.indx"
end_define

begin_comment
comment|/* master index */
end_comment

begin_define
define|#
directive|define
name|INDEXR
value|"resp.indx"
end_define

begin_comment
comment|/* response chains */
end_comment

begin_define
define|#
directive|define
name|ACCESS
value|"access"
end_define

begin_comment
comment|/* access lists here */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE
value|"archive"
end_define

begin_comment
comment|/* archive sub-dir */
end_comment

begin_define
define|#
directive|define
name|COMPRESS
value|"comp."
end_define

begin_comment
comment|/* compress names */
end_comment

begin_define
define|#
directive|define
name|SEQLOCK
value|'s'
end_define

begin_comment
comment|/* .SEQ lock */
end_comment

begin_define
define|#
directive|define
name|LOGLOCK
value|'l'
end_define

begin_comment
comment|/* log file locking */
end_comment

begin_define
define|#
directive|define
name|ARCHLOCK
value|'a'
end_define

begin_comment
comment|/* archiving */
end_comment

begin_define
define|#
directive|define
name|TXTLOCK
value|'t'
end_define

begin_comment
comment|/* text file */
end_comment

begin_define
define|#
directive|define
name|DSCRLOCK
value|'n'
end_define

begin_comment
comment|/* index file */
end_comment

begin_define
define|#
directive|define
name|RESPSZ
value|5
end_define

begin_comment
comment|/* number responses/response record */
end_comment

begin_define
define|#
directive|define
name|NAMESZ
value|17
end_define

begin_comment
comment|/* longest user name */
end_comment

begin_define
define|#
directive|define
name|HOMESYSSZ
value|33
end_define

begin_comment
comment|/* user home system */
end_comment

begin_define
define|#
directive|define
name|SYSSZ
value|33
end_define

begin_comment
comment|/* system name length */
end_comment

begin_comment
comment|/* above hold null byte also */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|1024
end_define

begin_comment
comment|/* chars in core */
end_comment

begin_comment
comment|/*  *	pick an appropriate default for the maximum message length  *	(MAXMSG). Also pick an appropriate hard limit. (HARDMAX)  *	HARDMAX must leave room for a one line message of up to 50  *	bytes of the form "ignoring %ld excess bytes"  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIGTEXT
end_ifdef

begin_define
define|#
directive|define
name|MAXMSG
value|100000
end_define

begin_comment
comment|/* can be larger */
end_comment

begin_define
define|#
directive|define
name|HARDMAX
value|3000000
end_define

begin_comment
comment|/* 3 Mbytes */
end_comment

begin_else
else|#
directive|else
else|NOT BIGTEXT
end_else

begin_define
define|#
directive|define
name|MAXMSG
value|65000
end_define

begin_comment
comment|/* not much larger */
end_comment

begin_define
define|#
directive|define
name|HARDMAX
value|65000
end_define

begin_comment
comment|/* room for mesage */
end_comment

begin_endif
endif|#
directive|endif
endif|NOT BIGTEXT
end_endif

begin_define
define|#
directive|define
name|PAGESAV
value|50
end_define

begin_comment
comment|/* display stack */
end_comment

begin_comment
comment|/* using unsigned short */
end_comment

begin_define
define|#
directive|define
name|UNIQPLEX
value|100000
end_define

begin_comment
comment|/* multiplex nfid into noteid */
end_comment

begin_comment
comment|/* see putnote and putresp */
end_comment

begin_define
define|#
directive|define
name|TITLEN
value|36
end_define

begin_comment
comment|/* note title length */
end_comment

begin_define
define|#
directive|define
name|NNLEN
value|40
end_define

begin_comment
comment|/* Notesfile Name length */
end_comment

begin_define
define|#
directive|define
name|DMLEN
value|40
end_define

begin_comment
comment|/* director message length */
end_comment

begin_define
define|#
directive|define
name|NOT
value|~
end_define

begin_comment
comment|/* tilde, prints wrong on hazeltines */
end_comment

begin_define
define|#
directive|define
name|WDLEN
value|128
end_define

begin_comment
comment|/* longest file name */
end_comment

begin_define
define|#
directive|define
name|CMDLEN
value|512
end_define

begin_comment
comment|/* build-a-command */
end_comment

begin_define
define|#
directive|define
name|PASSWDLEN
value|128
end_define

begin_comment
comment|/* longest line in /etc/passwd */
end_comment

begin_define
define|#
directive|define
name|DATELEN
value|24
end_define

begin_comment
comment|/* length of formatted date */
end_comment

begin_define
define|#
directive|define
name|NPERMS
value|35
end_define

begin_comment
comment|/* max access list */
end_comment

begin_comment
comment|/*  *	NPERMS can be increased as desired. However, a static array is  *	allocated based on this constant. Watch it if you are running in  *	a memory starved environment (like an 11/60).  */
end_comment

begin_define
define|#
directive|define
name|PAGELEN
value|56
end_define

begin_comment
comment|/* pagelength for 'S' */
end_comment

begin_define
define|#
directive|define
name|ANONOK
value|01
end_define

begin_comment
comment|/* permit anon notes */
end_comment

begin_define
define|#
directive|define
name|FRMNEWS
value|01
end_define

begin_comment
comment|/* non-nf article */
end_comment

begin_define
define|#
directive|define
name|OPEN
value|02
end_define

begin_comment
comment|/* open for public */
end_comment

begin_define
define|#
directive|define
name|DIRMES
value|04
end_define

begin_comment
comment|/* director msg on */
end_comment

begin_define
define|#
directive|define
name|DELETED
value|010
end_define

begin_comment
comment|/* is deleted */
end_comment

begin_define
define|#
directive|define
name|NFINVALID
value|010
end_define

begin_comment
comment|/* got bad copy */
end_comment

begin_define
define|#
directive|define
name|NETWRKD
value|020
end_define

begin_comment
comment|/* networking OK */
end_comment

begin_define
define|#
directive|define
name|CONTINUED
value|040
end_define

begin_comment
comment|/* was auto-split */
end_comment

begin_define
define|#
directive|define
name|WRITONLY
value|0100
end_define

begin_comment
comment|/* writeonly access when written */
end_comment

begin_define
define|#
directive|define
name|ORPHND
value|0200
end_define

begin_comment
comment|/* foster parent */
end_comment

begin_define
define|#
directive|define
name|ISARCH
value|0400
end_define

begin_comment
comment|/* is an archive */
end_comment

begin_comment
comment|/*	change these only after modifying the table in access.c		*/
end_comment

begin_define
define|#
directive|define
name|READOK
value|01
end_define

begin_comment
comment|/* allow user to read */
end_comment

begin_define
define|#
directive|define
name|WRITOK
value|02
end_define

begin_comment
comment|/* allow user to write */
end_comment

begin_define
define|#
directive|define
name|DRCTOK
value|04
end_define

begin_comment
comment|/* allow user to be director */
end_comment

begin_define
define|#
directive|define
name|RESPOK
value|010
end_define

begin_comment
comment|/* ok to respond */
end_comment

begin_comment
comment|/*  *	archive writing keyed on director status for now...  */
end_comment

begin_define
define|#
directive|define
name|ARCHWRITOK
value|020
end_define

begin_comment
comment|/* archive write */
end_comment

begin_define
define|#
directive|define
name|ARCHRESPOK
value|040
end_define

begin_comment
comment|/* archive response */
end_comment

begin_define
define|#
directive|define
name|DFLTPERMS
value|(READOK+WRITOK+RESPOK)
end_define

begin_comment
comment|/* default permissions */
end_comment

begin_define
define|#
directive|define
name|PERMUSER
value|00
end_define

begin_comment
comment|/* perm_f entry type */
end_comment

begin_define
define|#
directive|define
name|PERMGROUP
value|01
end_define

begin_comment
comment|/* ORDER IS IMPORTANT */
end_comment

begin_define
define|#
directive|define
name|PERMSYSTEM
value|02
end_define

begin_comment
comment|/*  *	Sequencer modes.  *	modes< NOREADSEQ cause the time to be taken from "Basetime"  *	modes< NOWRITESEQ cause no update when leaving the notesfile.  *	There is currently no way to read from the sequencer file  *		and not update -- it's a wierd case anyway.  */
end_comment

begin_define
define|#
directive|define
name|NOSEQ
value|0
end_define

begin_comment
comment|/* no sequencer */
end_comment

begin_define
define|#
directive|define
name|USERSEQ
value|1
end_define

begin_comment
comment|/* usertime noupdate */
end_comment

begin_define
define|#
directive|define
name|NOWRITESEQ
value|10
end_define

begin_comment
comment|/*< this no write */
end_comment

begin_define
define|#
directive|define
name|BASESEQ
value|11
end_define

begin_comment
comment|/* usertime& update */
end_comment

begin_define
define|#
directive|define
name|NOREADSEQ
value|100
end_define

begin_comment
comment|/* use Basetime if< */
end_comment

begin_define
define|#
directive|define
name|NORMSEQ
value|101
end_define

begin_comment
comment|/* normal sequencer */
end_comment

begin_define
define|#
directive|define
name|EXTSEQ
value|102
end_define

begin_comment
comment|/* enter anyway */
end_comment

begin_define
define|#
directive|define
name|INDXSEQ
value|103
end_define

begin_comment
comment|/* index sequencer */
end_comment

begin_comment
comment|/*  from harpo!mmp */
end_comment

begin_define
define|#
directive|define
name|QUITSEQ
value|-2
end_define

begin_comment
comment|/* quit, update sequencer */
end_comment

begin_define
define|#
directive|define
name|QUITNOSEQ
value|-3
end_define

begin_comment
comment|/* quit, no seq update */
end_comment

begin_define
define|#
directive|define
name|QUITFAST
value|-4
end_define

begin_comment
comment|/* quit almost abort */
end_comment

begin_define
define|#
directive|define
name|QUITUPD
value|-5
end_define

begin_comment
comment|/* like quitfast */
end_comment

begin_define
define|#
directive|define
name|QUITNEX
value|-6
end_define

begin_comment
comment|/* no notesfile */
end_comment

begin_define
define|#
directive|define
name|QUITBAD
value|-7
end_define

begin_comment
comment|/* bad notesfile */
end_comment

begin_define
define|#
directive|define
name|GOOD
value|0
end_define

begin_comment
comment|/* good exit status */
end_comment

begin_define
define|#
directive|define
name|BAD
value|1
end_define

begin_comment
comment|/* bad exit status */
end_comment

begin_define
define|#
directive|define
name|NONF
value|2
end_define

begin_comment
comment|/* no notefile */
end_comment

begin_define
define|#
directive|define
name|POLICY
value|1
end_define

begin_comment
comment|/* mnemonics */
end_comment

begin_define
define|#
directive|define
name|NOPOLICY
value|0
end_define

begin_comment
comment|/* used in calls */
end_comment

begin_define
define|#
directive|define
name|LOCKIT
value|1
end_define

begin_comment
comment|/* Do not change */
end_comment

begin_define
define|#
directive|define
name|NOLOCKIT
value|0
end_define

begin_define
define|#
directive|define
name|COPYID
value|1
end_define

begin_define
define|#
directive|define
name|NOCOPYID
value|0
end_define

begin_define
define|#
directive|define
name|ADDID
value|1
end_define

begin_define
define|#
directive|define
name|NOADDID
value|0
end_define

begin_define
define|#
directive|define
name|ADDTIME
value|1
end_define

begin_define
define|#
directive|define
name|NOADDTIME
value|0
end_define

begin_define
define|#
directive|define
name|DETAIL
value|1
end_define

begin_comment
comment|/* dump extra info */
end_comment

begin_define
define|#
directive|define
name|NODETAIL
value|0
end_define

begin_comment
comment|/* used for generic form */
end_comment

begin_comment
comment|/*  *	These defines are for the archiver. They are used for determining  *	eligibility for archival along with the age of the note.  *	DFLT means to use whatever value was supplied on the archive  *	command line.  The others mean the notesfile is configured  *	for a specific archival setup.  */
end_comment

begin_define
define|#
directive|define
name|DIRDFLT
value|0
end_define

begin_comment
comment|/* use cmd line */
end_comment

begin_define
define|#
directive|define
name|DIRNOCARE
value|1
end_define

begin_comment
comment|/* don't check dir */
end_comment

begin_define
define|#
directive|define
name|DIRON
value|2
end_define

begin_comment
comment|/* only if dir on */
end_comment

begin_define
define|#
directive|define
name|DIROFF
value|3
end_define

begin_comment
comment|/* only if dir off */
end_comment

begin_define
define|#
directive|define
name|KEEPDFLT
value|0
end_define

begin_comment
comment|/* use cmd line */
end_comment

begin_define
define|#
directive|define
name|KEEPNO
value|1
end_define

begin_comment
comment|/* delete 'em */
end_comment

begin_define
define|#
directive|define
name|KEEPYES
value|2
end_define

begin_comment
comment|/* archive 'em */
end_comment

begin_struct
struct|struct
name|auth_f
comment|/* how we id author */
block|{
name|char
name|aname
index|[
name|NAMESZ
index|]
decl_stmt|;
comment|/* his name */
name|char
name|asystem
index|[
name|HOMESYSSZ
index|]
decl_stmt|;
comment|/* his system */
name|int
name|aid
decl_stmt|;
comment|/* uid (if local) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|when_f
comment|/* standard date structure */
block|{
name|short
name|w_year
decl_stmt|;
name|short
name|w_month
decl_stmt|;
name|short
name|w_day
decl_stmt|;
name|short
name|w_hours
decl_stmt|;
name|short
name|w_mins
decl_stmt|;
name|long
name|w_gmttime
decl_stmt|;
comment|/* stock unix time */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|id_f
comment|/* unique id for notes */
block|{
name|char
name|sys
index|[
name|SYSSZ
index|]
decl_stmt|;
name|long
name|uniqid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|perm_f
comment|/* permission tables */
block|{
name|short
name|ptype
decl_stmt|;
comment|/* user, group, system */
name|char
name|name
index|[
name|NAMESZ
index|]
decl_stmt|;
comment|/* name of such */
name|short
name|perms
decl_stmt|;
comment|/* what he is allowed */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|daddr_f
comment|/* save a disk address */
block|{
name|long
name|addr
decl_stmt|;
comment|/* for lseeks */
ifdef|#
directive|ifdef
name|BIGTEXT
name|unsigned
name|long
name|textlen
decl_stmt|;
comment|/* how long is text */
else|#
directive|else
else|NOT BIGTEXT
name|unsigned
name|short
name|textlen
decl_stmt|;
comment|/* how long the text is */
endif|#
directive|endif
endif|NOT BIGTEXT
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txtbuf_f
block|{
name|char
name|txtbuf
index|[
name|BUFSIZE
index|]
decl_stmt|;
comment|/* hold a bunch of characters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dsply_f
block|{
name|struct
name|daddr_f
name|d_head
decl_stmt|;
comment|/* text start */
name|struct
name|txtbuf_f
name|d_buf
decl_stmt|;
name|int
name|optr
decl_stmt|,
name|olim
decl_stmt|;
comment|/* output index and end of buffer */
name|long
name|outcount
decl_stmt|;
comment|/* number of characters dumped */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|resp_f
comment|/* for each response: */
block|{
name|short
name|r_first
decl_stmt|,
comment|/* bounds of this */
name|r_last
decl_stmt|;
comment|/* resp_f block */
name|struct
name|id_f
name|r_id
index|[
name|RESPSZ
index|]
decl_stmt|;
comment|/* system/id for each response */
name|struct
name|daddr_f
name|r_addr
index|[
name|RESPSZ
index|]
decl_stmt|;
comment|/* where the response is */
name|struct
name|when_f
name|r_when
index|[
name|RESPSZ
index|]
decl_stmt|;
comment|/* date/time of response */
name|char
name|r_from
index|[
name|RESPSZ
index|]
index|[
name|SYSSZ
index|]
decl_stmt|;
comment|/* system that sent this to us */
name|struct
name|when_f
name|r_rcvd
index|[
name|RESPSZ
index|]
decl_stmt|;
comment|/* date/time for sequencer */
name|struct
name|auth_f
name|r_auth
index|[
name|RESPSZ
index|]
decl_stmt|;
name|char
name|r_stat
index|[
name|RESPSZ
index|]
decl_stmt|;
comment|/* director/status flag */
name|int
name|r_next
decl_stmt|;
comment|/* index of next response_ind */
name|int
name|r_previous
decl_stmt|;
comment|/* backlinks */
comment|/* [currently unused */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|note_f
comment|/* standard note structure: */
block|{
name|struct
name|id_f
name|n_id
decl_stmt|;
comment|/* unique id for this note */
name|short
name|n_nresp
decl_stmt|;
comment|/* number of responses */
name|char
name|ntitle
index|[
name|TITLEN
index|]
decl_stmt|;
comment|/* title of note */
name|struct
name|auth_f
name|n_auth
decl_stmt|;
comment|/* note's author */
name|struct
name|when_f
name|n_date
decl_stmt|;
comment|/* note's date */
name|struct
name|when_f
name|n_rcvd
decl_stmt|;
comment|/* date we got it */
name|struct
name|when_f
name|n_lmod
decl_stmt|;
comment|/* date of last mod */
name|char
name|n_from
index|[
name|SYSSZ
index|]
decl_stmt|;
comment|/* system that handed us the note */
name|int
name|n_rindx
decl_stmt|;
comment|/* where the first set of responses lies */
name|struct
name|daddr_f
name|n_addr
decl_stmt|;
comment|/* address of note's text on disk */
name|char
name|n_stat
decl_stmt|;
comment|/* director/status flag */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|descr_f
comment|/* for the notesfile: */
block|{
name|long
name|d_format
decl_stmt|;
comment|/* nf's format */
name|char
name|d_title
index|[
name|NNLEN
index|]
decl_stmt|;
comment|/* nf's name */
name|char
name|d_drmes
index|[
name|DMLEN
index|]
decl_stmt|;
comment|/* director message */
name|short
name|d_plcy
decl_stmt|;
comment|/* ==0 if no message */
name|struct
name|when_f
name|d_lastm
decl_stmt|;
comment|/* last modified time */
name|short
name|d_stat
decl_stmt|;
comment|/* open/closed/etc */
name|short
name|d_nnote
decl_stmt|;
comment|/* how many notes in file */
name|struct
name|id_f
name|d_id
decl_stmt|;
comment|/* sys name& unique id counter */
name|struct
name|when_f
name|d_lstxmit
decl_stmt|;
comment|/* last network transmit */
name|struct
name|when_f
name|d_created
decl_stmt|;
comment|/* creation date */
name|struct
name|when_f
name|d_lastuse
decl_stmt|;
comment|/* last day used */
name|long
name|d_daysused
decl_stmt|;
comment|/* count those days */
name|long
name|d_rspwrit
decl_stmt|;
comment|/* number of responses ever written */
name|long
name|d_notwrit
decl_stmt|;
comment|/* number of notes ever written */
name|long
name|entries
decl_stmt|;
comment|/* number of entries into the notefile */
name|long
name|walltime
decl_stmt|;
comment|/* man-seconds (?) spent in notefile */
name|long
name|d_rspread
decl_stmt|;
comment|/* number of responses read */
name|long
name|d_notread
decl_stmt|;
comment|/* and number of notes */
name|long
name|d_rsprcvd
decl_stmt|;
comment|/* network in stats */
name|long
name|d_notrcvd
decl_stmt|;
name|long
name|d_rspxmit
decl_stmt|;
comment|/* network out stats */
name|long
name|d_notxmit
decl_stmt|;
name|long
name|d_notdrop
decl_stmt|;
comment|/* duplicate notes recieved */
name|long
name|d_rspdrop
decl_stmt|;
comment|/* and dropped on ground */
name|long
name|d_orphans
decl_stmt|;
comment|/* orphaned responses */
name|long
name|netwrkouts
decl_stmt|;
comment|/* number of times networked out */
name|long
name|netwrkins
decl_stmt|;
comment|/* and number of networked in */
name|short
name|d_nfnum
decl_stmt|;
comment|/* unique to this notesfile */
name|long
name|d_archtime
decl_stmt|;
comment|/* archive after X days */
name|long
name|d_workset
decl_stmt|;
comment|/* working set size */
name|long
name|d_delnote
decl_stmt|;
comment|/* count deletes */
name|long
name|d_delresp
decl_stmt|;
comment|/* count resp dels */
name|long
name|d_dmesgstat
decl_stmt|;
comment|/* use dirmsg for archive */
name|long
name|d_archkeep
decl_stmt|;
comment|/* keep/delete */
name|long
name|d_adopted
decl_stmt|;
comment|/* orphans adopted */
name|long
name|d_longnote
decl_stmt|;
comment|/* max per article */
name|char
name|d_filler
index|[
literal|20
index|]
decl_stmt|;
comment|/* future use ... */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|io_f
comment|/* master i/o form */
block|{
name|int
name|fidtxt
decl_stmt|;
comment|/* text */
name|int
name|fidndx
decl_stmt|;
comment|/* note.indx */
name|int
name|fidrdx
decl_stmt|;
comment|/* resp.indx */
name|struct
name|descr_f
name|descr
decl_stmt|;
comment|/* current descr */
comment|/* updated by critical sections */
name|char
name|nf
index|[
name|NNLEN
index|]
decl_stmt|;
comment|/* last part of name */
name|char
name|basedir
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* its directory */
name|char
name|fullname
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* full pathname */
name|char
name|xstring
index|[
name|TITLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* search string */
name|char
name|xauthor
index|[
name|NAMESZ
operator|+
name|SYSSZ
operator|+
literal|2
index|]
decl_stmt|;
comment|/* author search */
comment|/* site!user\0 */
name|struct
name|when_f
name|stime
decl_stmt|;
comment|/* read notes/responses more recent than this */
name|short
name|access
decl_stmt|;
comment|/* what sort of access user has */
name|int
name|nrspwrit
decl_stmt|;
comment|/* number of responses written this entry */
name|int
name|nnotwrit
decl_stmt|;
comment|/* num of notes written */
name|long
name|entered
decl_stmt|;
comment|/* when started so can figure time in */
name|int
name|nrspread
decl_stmt|;
comment|/* how many responses he read */
name|int
name|nnotread
decl_stmt|;
comment|/* how many notes he read */
comment|/* num read may be tough */
name|int
name|nnotxmit
decl_stmt|;
comment|/* network out stats */
name|int
name|nrspxmit
decl_stmt|;
name|int
name|nnotrcvd
decl_stmt|;
comment|/* network in stats */
name|int
name|nrsprcvd
decl_stmt|;
name|int
name|nnotdrop
decl_stmt|;
comment|/* duplicates rom the network */
name|int
name|nrspdrop
decl_stmt|;
name|int
name|norphans
decl_stmt|;
comment|/* orphans rcvd */
name|int
name|adopted
decl_stmt|;
comment|/* adoptions handled */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|seq_f
comment|/* sequencer entry list form */
block|{
name|char
name|nfname
index|[
name|NNLEN
index|]
decl_stmt|;
comment|/* name of notefile */
name|struct
name|when_f
name|lastin
decl_stmt|;
comment|/* last entry time */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nflist_f
comment|/* nf's to scan */
block|{
name|char
modifier|*
name|nf_name
decl_stmt|;
name|short
name|nf_active
decl_stmt|;
comment|/* !'ed or not */
name|short
name|nf_seqmode
decl_stmt|;
comment|/* sequencer mode */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Declare global variables. The actual instantiation of these   *	variables is in the file startup.c  *  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hised
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preferred editor */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hisshell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preferred shell */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hispager
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* paging program */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hismailer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nrows
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rows on screen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ncols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screen width */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|histty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty on command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DEL hit recently */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|globuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* his true user id */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Notesuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* who's god */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Anonuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* who's not allowed */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Nindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index page rows */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ignoresigs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* critical section */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Mstdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default nf place */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|System
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point to it */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Authsystem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* author's system */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Invokedas
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[0] */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Seqname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequencing name */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|when_f
name|Basetime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero time */
end_comment

begin_comment
comment|/*  *	Various definitions that help keep things portable.  *	Types that various functions return, etc.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* UNIX4.0 index() */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* UNIX4.0 rindex() */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for lint */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|defined(USG)
end_endif

begin_comment
comment|/*  *	Standard library routines that return other than "int".  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* syscall errors */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* errno messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and how many */
end_comment

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* satisfy lint */
end_comment

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for lint */
end_comment

begin_comment
comment|/*  *	routines in the notesfile system that return other than  *	"int".  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in misc.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|nflist_f
modifier|*
name|nextgroup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in expand.c */
end_comment

begin_function_decl
specifier|extern
name|long
name|pagein
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in pagein.c */
end_comment

begin_function_decl
specifier|extern
name|long
name|gettext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in gtext.c */
end_comment

begin_function_decl
specifier|extern
name|long
name|puttrec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in recsio.c */
end_comment

end_unit

