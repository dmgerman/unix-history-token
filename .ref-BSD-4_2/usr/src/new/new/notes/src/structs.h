begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	structure definitions for the notefile program */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
name|.1c
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_define
define|#
directive|define
name|setuid
parameter_list|(
name|x
parameter_list|)
value|setreuid(-1,x)
end_define

begin_endif
endif|#
directive|endif
endif|BSD4.1c
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VFORK
end_ifdef

begin_define
define|#
directive|define
name|fork
value|vfork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NETLOG
value|"net.log"
end_define

begin_comment
comment|/* log file for network */
end_comment

begin_define
define|#
directive|define
name|GRIPES
value|"nfgripes"
end_define

begin_comment
comment|/* name of gripe notefile */
end_comment

begin_define
define|#
directive|define
name|UTILITY
value|".utilities"
end_define

begin_comment
comment|/* subdirectory containing utilities */
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
comment|/* where sequencer files live */
end_comment

begin_define
define|#
directive|define
name|SEQ
value|".SEQ"
end_define

begin_comment
comment|/* next d_nfnum available */
end_comment

begin_define
define|#
directive|define
name|INDXHLP
value|"index.help"
end_define

begin_comment
comment|/* name of index page help */
end_comment

begin_define
define|#
directive|define
name|RDMHLP
value|"read.help"
end_define

begin_comment
comment|/* name of readem page help file */
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
comment|/* nf comment routine */
end_comment

begin_define
define|#
directive|define
name|SEQLOCK
value|'s'
end_define

begin_comment
comment|/* lock flags */
end_comment

begin_define
define|#
directive|define
name|LOGLOCK
value|'l'
end_define

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
comment|/* access lists in here */
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
value|25
end_define

begin_comment
comment|/* max number of characters in name */
end_comment

begin_define
define|#
directive|define
name|SYSSZ
value|10
end_define

begin_comment
comment|/* max system name length */
end_comment

begin_comment
comment|/* must hold null terminator also */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|512
end_define

begin_comment
comment|/* chars in core */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
name|.1c
end_ifdef

begin_define
define|#
directive|define
name|MAXMSG
value|4000000000
end_define

begin_comment
comment|/* longest allowed note */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXMSG
value|65535
end_define

begin_comment
comment|/* longest allowed note */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD4.1c
end_endif

begin_define
define|#
directive|define
name|PAGESAV
value|10
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

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
name|.1c
end_ifdef

begin_define
define|#
directive|define
name|NNLEN
value|255
end_define

begin_comment
comment|/* Notesfile Name length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NNLEN
value|40
end_define

begin_comment
comment|/* Notesfile Name length */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD4.1c
end_endif

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
name|NINDEX
value|10
end_define

begin_comment
comment|/* how many notes on directory page */
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
value|255
end_define

begin_comment
comment|/* longest file name length */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
name|.1c
end_ifdef

begin_define
define|#
directive|define
name|CMDLEN
value|1024
end_define

begin_comment
comment|/* command length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CMDLEN
value|512
end_define

begin_comment
comment|/* command length */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD4.1c
end_endif

begin_define
define|#
directive|define
name|MAXGROUPS
value|300
end_define

begin_comment
comment|/* maximum "globbed" notesfiles */
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
comment|/* max access list size */
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
name|PUSER
value|00
end_define

begin_comment
comment|/* for perm_f - entry type */
end_comment

begin_define
define|#
directive|define
name|PGROUP
value|01
end_define

begin_comment
comment|/* ORDER IS IMPORTANT */
end_comment

begin_define
define|#
directive|define
name|PSYSTEM
value|02
end_define

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
name|NORMSEQ
value|1
end_define

begin_comment
comment|/* normal sequencer */
end_comment

begin_define
define|#
directive|define
name|EXTSEQ
value|2
end_define

begin_comment
comment|/* enter anyway sequencer */
end_comment

begin_define
define|#
directive|define
name|INDXSEQ
value|3
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
comment|/* update seq and exit, RLS */
end_comment

begin_define
define|#
directive|define
name|QUITNEX
value|-6
end_define

begin_comment
comment|/* no such notesfile */
end_comment

begin_define
define|#
directive|define
name|QUITBAD
value|-7
end_define

begin_comment
comment|/* error opening notesfile */
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
comment|/*  *	These defines are for the archiver. They are used for determining  *	eligibility for archival along with the age of the note.  */
end_comment

begin_define
define|#
directive|define
name|DIRNOCARE
value|0
end_define

begin_comment
comment|/* don't care about dir msgs */
end_comment

begin_define
define|#
directive|define
name|DIRON
value|1
end_define

begin_comment
comment|/* archive only if on */
end_comment

begin_define
define|#
directive|define
name|DIROFF
value|2
end_define

begin_comment
comment|/* only if off */
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
comment|/* author name */
name|int
name|aid
decl_stmt|;
comment|/* author's uid */
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
block|{
comment|/* permission tables */
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
name|txthead_f
comment|/* way note text stored */
block|{
name|short
name|note_no
decl_stmt|;
comment|/* to which note this text belongs (0=policy) */
name|short
name|resp_no
decl_stmt|;
comment|/* to which response this text belongs (0=main note) */
comment|/* both for debugging */
ifdef|#
directive|ifdef
name|BSD4
name|.1c
name|unsigned
name|long
name|textlen
decl_stmt|;
comment|/* how long the text is */
else|#
directive|else
name|unsigned
name|short
name|textlen
decl_stmt|;
comment|/* how long the text is */
endif|#
directive|endif
endif|BSD4.1c
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
name|txthead_f
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
name|daddr_f
comment|/* save a disk address */
block|{
name|long
name|addr
decl_stmt|;
comment|/* for lseeks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|resp_f
comment|/* for each response: */
block|{
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
name|char
name|d_title
index|[
name|NNLEN
index|]
decl_stmt|;
comment|/* name of the notesfile */
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
name|char
name|d_filler
index|[
literal|38
index|]
decl_stmt|;
comment|/* bytes for future use ... */
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
comment|/* this notefile's descriptor, updated by critical sections */
name|struct
name|descr_f
name|descr
decl_stmt|;
name|char
name|nf
index|[
name|NNLEN
index|]
decl_stmt|;
comment|/* which notefile he is in */
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
name|xasys
index|[
name|SYSSZ
index|]
decl_stmt|;
comment|/* author search sys */
name|char
name|xaname
index|[
name|NAMESZ
index|]
decl_stmt|;
comment|/* author search name */
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
comment|/* orphaned responses */
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
name|fbuf_f
comment|/* buffered character input */
block|{
name|int
name|fid
decl_stmt|,
comment|/* file desriptor */
name|iptr
decl_stmt|,
comment|/* current pointer */
name|ilim
decl_stmt|;
comment|/* end of buffer */
name|char
name|buff
index|[
literal|512
index|]
decl_stmt|;
comment|/* the buffer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|grp
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|lookat
decl_stmt|;
name|char
name|seqtyp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SYSTEM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points at system name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag DEL's */
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

begin_comment
comment|/* remove ugly warnings */
end_comment

begin_function_decl
name|char
modifier|*
name|strsave
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
comment|/* clean up lint and other stuff */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|globuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point at the true uid */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nrows
decl_stmt|,
name|ncols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screen size */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|notesrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* notesrc file name, RLS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of index lines, RLS */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|grp
name|group
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|last_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ignsigs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|replot
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|notesenv
block|{
name|jmp_buf
name|n_env
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|notesenv
name|curenv
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|jenv
value|curenv.n_env
end_define

begin_decl_stmt
specifier|extern
name|int
name|msk
decl_stmt|;
end_decl_stmt

end_unit

