begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|ALL
value|""
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|1000
end_define

begin_comment
comment|/* Max messages to exec                 */
end_comment

begin_define
define|#
directive|define
name|EXISTS
value|01
end_define

begin_comment
comment|/* Flag bits in msgstats-- Deleted is   */
end_comment

begin_define
define|#
directive|define
name|DELETED
value|02
end_define

begin_comment
comment|/*      undefined currently             */
end_comment

begin_define
define|#
directive|define
name|SELECTED
value|04
end_define

begin_comment
comment|/* Message selected by an arg           */
end_comment

begin_define
define|#
directive|define
name|READONLY
value|01
end_define

begin_comment
comment|/* No write access to folder            */
end_comment

begin_define
define|#
directive|define
name|DEFMOD
value|01
end_define

begin_comment
comment|/* In-core profile has been modified    */
end_comment

begin_comment
comment|/*#define NEWS     1    /* Define for news inclusion            */
end_comment

begin_struct
struct|struct
name|swit
block|{
name|char
modifier|*
name|sw
decl_stmt|;
name|int
name|minchars
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * m_gmsg() returns this structure.  It contains the per folder  * information which is obtained from reading the folder directory.  */
end_comment

begin_struct
struct|struct
name|msgs
block|{
name|int
name|hghmsg
decl_stmt|;
comment|/* Highest msg in directory     */
name|int
name|nummsg
decl_stmt|;
comment|/* Actual Number of msgs        */
name|int
name|lowmsg
decl_stmt|;
comment|/* Lowest msg number            */
name|int
name|curmsg
decl_stmt|;
comment|/* Number of current msg if any */
name|int
name|lowsel
decl_stmt|;
comment|/* Lowest selected msg number   */
name|int
name|hghsel
decl_stmt|;
comment|/* Highest selected msg number  */
name|int
name|numsel
decl_stmt|;
comment|/* Number of msgs selected      */
name|char
modifier|*
name|foldpath
decl_stmt|;
comment|/* Pathname of folder           */
name|char
name|selist
decl_stmt|,
comment|/* Folder has a "select" file   */
name|msgflags
decl_stmt|,
comment|/* Folder status bits           */
name|filler
decl_stmt|,
name|others
decl_stmt|;
comment|/* Folder has other file(s)     */
name|char
name|msgstats
index|[
literal|1
index|]
decl_stmt|;
comment|/* Stat bytes for each msg      */
block|}
struct|;
end_struct

begin_comment
comment|/* m_getfld definitions and return values       */
end_comment

begin_define
define|#
directive|define
name|NAMESZ
value|64
end_define

begin_comment
comment|/* Limit on component name size         */
end_comment

begin_define
define|#
directive|define
name|LENERR
value|-2
end_define

begin_comment
comment|/* Name too long error from getfld      */
end_comment

begin_define
define|#
directive|define
name|FMTERR
value|-3
end_define

begin_comment
comment|/* Message Format error                 */
end_comment

begin_comment
comment|/* m_getfld return codes                */
end_comment

begin_define
define|#
directive|define
name|FLD
value|0
end_define

begin_comment
comment|/* Field returned                       */
end_comment

begin_define
define|#
directive|define
name|FLDPLUS
value|1
end_define

begin_comment
comment|/* Field " with more to come            */
end_comment

begin_define
define|#
directive|define
name|FLDEOF
value|2
end_define

begin_comment
comment|/* Field " ending at eom                */
end_comment

begin_define
define|#
directive|define
name|BODY
value|3
end_define

begin_comment
comment|/* Body  " with more to come            */
end_comment

begin_define
define|#
directive|define
name|BODYEOF
value|4
end_define

begin_comment
comment|/* Body  " ending at eom                */
end_comment

begin_define
define|#
directive|define
name|FILEEOF
value|5
end_define

begin_comment
comment|/* Reached end of input file            */
end_comment

begin_comment
comment|/*  * These standard strings are defined in strings.a.  They are the  * only system-dependent parameters in MH, and thus by redefining  * their values and reloading the various modules, MH will run  * on any system.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|components
decl_stmt|,
comment|/* Name of user's component file (in mh dir) */
modifier|*
name|current
decl_stmt|,
comment|/* Name of current msg file in a folder */
modifier|*
name|defalt
decl_stmt|,
comment|/* Name of the std folder (inbox)       */
modifier|*
name|distcomps
decl_stmt|,
comment|/* Name of `dist' components file       */
modifier|*
name|draft
decl_stmt|,
comment|/* Name of the normal draft file        */
modifier|*
name|fileproc
decl_stmt|,
comment|/* Path of file program                 */
modifier|*
name|foldprot
decl_stmt|,
comment|/* Default folder protection            */
modifier|*
name|hostname
decl_stmt|,
comment|/* Local net host name                  */
modifier|*
name|installproc
decl_stmt|,
comment|/* Name of auto-install program path    */
modifier|*
name|listname
decl_stmt|,
comment|/* Default selection list folder name   */
modifier|*
name|lockdir
decl_stmt|,
comment|/* Dir for lock files (Same fs as mailboxes)*/
modifier|*
name|lsproc
decl_stmt|,
comment|/* Path of the Harvard ls program       */
modifier|*
name|mailboxes
decl_stmt|,
comment|/* Incoming mail directory              */
modifier|*
name|mh_prof
decl_stmt|,
comment|/* Name of users profile file           */
modifier|*
name|mh_deliver
decl_stmt|,
comment|/* Name of deliverer for mh             */
modifier|*
name|mhnews
decl_stmt|,
comment|/* Name of MH news file                 */
modifier|*
name|msgprot
decl_stmt|,
comment|/* Default message protection (s.a. 0664) */
modifier|*
name|pfolder
decl_stmt|,
comment|/* Name of current folder profile entry */
modifier|*
name|prproc
decl_stmt|,
comment|/* Path of the pr program               */
modifier|*
name|scanproc
decl_stmt|,
comment|/* Path of the scan program             */
modifier|*
name|showproc
decl_stmt|,
comment|/* Path of the type (l) program         */
modifier|*
name|sendproc
decl_stmt|,
comment|/* Path of the send message program     */
modifier|*
name|stdcomps
decl_stmt|,
comment|/* Std comp file if missing user's own  */
modifier|*
name|stddcomps
decl_stmt|,
comment|/* Std dist file if missing user's own  */
modifier|*
name|sysed
decl_stmt|,
comment|/* Path of the std (ned) editor         */
comment|/* Just about every program uses this also                      */
modifier|*
name|mypath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User's log-on path                   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXCOMP
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|unixtomh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Path of program to convert UNIX style 			   mailboxes to MH style mailboxes */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Mailprog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Path of program to do actual mailing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|localname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of local machine on local net */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * node structure used to hold a linked list of the users profile  * information taken from logpath/.mh_prof.  */
end_comment

begin_struct
struct|struct
name|node
block|{
name|struct
name|node
modifier|*
name|n_next
decl_stmt|;
name|char
modifier|*
name|n_name
decl_stmt|,
modifier|*
name|n_field
decl_stmt|;
block|}
modifier|*
name|m_defs
struct|;
end_struct

begin_decl_stmt
name|char
name|def_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The first char in the mhnews file indicates whether the program  * calling m_news() should continue running or halt.  */
end_comment

begin_define
define|#
directive|define
name|NEWSHALT
value|'!'
end_define

begin_comment
comment|/* Halt after showing the news  */
end_comment

begin_define
define|#
directive|define
name|NEWSCONT
value|' '
end_define

begin_comment
comment|/* Continue  (ditto)            */
end_comment

begin_define
define|#
directive|define
name|NEWSPAUSE
value|'\001'
end_define

begin_comment
comment|/* Pause during news output...  */
end_comment

begin_comment
comment|/*  * Miscellaneous Defines to speed things up  */
end_comment

begin_define
define|#
directive|define
name|error
parameter_list|(
name|str
parameter_list|)
value|{ fprintf(stderr, "%s\n", str); exit(-1); }
end_define

begin_comment
comment|/*  * Routine type declarations -- needed by version 7 compiler  */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|brkstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_maildir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|trimcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|invo_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|copyip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_getfolder
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|msgs
modifier|*
name|m_gmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|getans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cdate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|makename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|r1bindex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Routine type declarations -- SHOULD BE GLOBAL  */
end_comment

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

end_unit

