begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mh.h - main header file for all of MH */
end_comment

begin_comment
comment|/* Well-used constants */
end_comment

begin_define
define|#
directive|define
name|NOTOK
value|(-1)
end_define

begin_comment
comment|/* syscall()s return this on error */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_comment
comment|/*  ditto on success */
end_comment

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_comment
comment|/* trinary logic */
end_comment

begin_define
define|#
directive|define
name|ALL
value|""
end_define

begin_define
define|#
directive|define
name|NULLCP
value|((char *) 0)
end_define

begin_define
define|#
directive|define
name|NULLVP
value|((char **) 0)
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|1000
end_define

begin_comment
comment|/* max arguments to exec */
end_comment

begin_define
define|#
directive|define
name|NFOLDERS
value|200
end_define

begin_comment
comment|/* max folder arguments on command line */
end_comment

begin_define
define|#
directive|define
name|MAXFOLDER
value|1000
end_define

begin_comment
comment|/* message increment */
end_comment

begin_define
define|#
directive|define
name|DMAXFOLDER
value|4
end_define

begin_comment
comment|/* typical number of digits */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
name|||
name|BSD41A
name|||
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_endif
endif|#
directive|endif
endif|not BSD
end_endif

begin_comment
comment|/* how sad... */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* profile structure */
end_comment

begin_struct
struct|struct
name|node
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* key */
name|char
modifier|*
name|n_field
decl_stmt|;
comment|/* value */
name|char
name|n_context
decl_stmt|;
comment|/* context, not profile */
name|struct
name|node
modifier|*
name|n_next
decl_stmt|;
comment|/* next entry */
block|}
struct|;
end_struct

begin_comment
comment|/* switches structure */
end_comment

begin_define
define|#
directive|define
name|AMBIGSW
value|(-2)
end_define

begin_comment
comment|/* from smatch() on ambiguous switch */
end_comment

begin_define
define|#
directive|define
name|UNKWNSW
value|(-1)
end_define

begin_comment
comment|/*  ditto on unknown switch */
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

begin_decl_stmt
specifier|extern
name|struct
name|swit
name|anoyes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* standard yes/no switches */
end_comment

begin_comment
comment|/* messages structure */
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
name|msgflags
decl_stmt|;
comment|/* Folder status bits           */
ifndef|#
directive|ifndef
name|MTR
name|char
name|pad1
index|[
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|char
argument_list|)
index|]
decl_stmt|;
endif|#
directive|endif
endif|not MTR
define|#
directive|define
name|READONLY
value|0x01
comment|/*     No write access to folder */
define|#
directive|define
name|SEQMOD
value|0x02
comment|/*     folder's sequences modifed */
define|#
directive|define
name|MHPATH
value|0x04
comment|/*     mhpath-style folder handling */
define|#
directive|define
name|OTHERS
value|0x08
comment|/*     folder has other files	*/
define|#
directive|define
name|MODIFIED
value|0x10
comment|/*     msh in-core folder modified */
define|#
directive|define
name|FBITS
value|"\020\01READONLY\02SEQMOD\03MHPATH\04OTHERS\05MODIFIED"
comment|/* Note well: msgstats[] is a short, so we have 16 bits to work 	with.  The first 5 are for standard MH message flags, 	this leaves us 11 for user-defined attributes.  Of these, 	1 is reserved for future internal use, so this leaves 	users 10.						*/
define|#
directive|define
name|NATTRS
value|10
comment|/* could be 11, see above	*/
name|char
modifier|*
name|msgattrs
index|[
name|NATTRS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* folder attributes		*/
name|short
name|attrstats
decl_stmt|;
comment|/* public=0/private=1		*/
ifndef|#
directive|ifndef
name|MTR
name|char
name|pad2
index|[
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|short
argument_list|)
index|]
decl_stmt|;
endif|#
directive|endif
endif|not MTR
name|int
name|lowoff
decl_stmt|;
comment|/* low element in msgstats[] */
name|int
name|hghoff
decl_stmt|;
comment|/* hgh element in msgstats[] */
ifndef|#
directive|ifndef
name|MTR
name|short
name|msgstats
index|[
literal|1
index|]
decl_stmt|;
comment|/* msg status			*/
else|#
directive|else
else|MTR
name|short
modifier|*
name|msgbase
decl_stmt|;
comment|/* msg base			*/
name|short
modifier|*
name|msgstats
decl_stmt|;
comment|/* msg status			*/
endif|#
directive|endif
endif|MTR
define|#
directive|define
name|EXISTS
value|0x0001
comment|/*     exists			*/
define|#
directive|define
name|DELETED
value|0x0002
comment|/*     deleted			*/
define|#
directive|define
name|SELECTED
value|0x0004
comment|/*     selected for use		*/
define|#
directive|define
name|SELECT_EMPTY
value|0x0008
comment|/*     mhpath "new"		*/
define|#
directive|define
name|UNSEEN
value|0x0010
comment|/*     inc/show "unseen"	*/
define|#
directive|define
name|FFATTRSLOT
value|5
comment|/*     user-defined attributes	*/
comment|/*	first free slot is	*/
comment|/*	(1<< 5) or 0x20	*/
define|#
directive|define
name|MBITS
value|"\020\01EXISTS\02DELETED\03SELECTED\04NEW\05UNSEEN"
ifndef|#
directive|ifndef
name|MTR
define|#
directive|define
name|MSIZE
parameter_list|(
name|mp
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
define|\
value|((unsigned) (sizeof *mp + ((hi) + 2) * sizeof *mp -> msgstats))
else|#
directive|else
else|MTR
define|#
directive|define
name|MSIZE
parameter_list|(
name|mp
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
value|((unsigned) sizeof *mp)
define|#
directive|define
name|MSIZEX
parameter_list|(
name|mp
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
define|\
value|((unsigned) (((hi) - (lo) + 1) * sizeof *mp -> msgstats))
endif|#
directive|endif
endif|MTR
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLMP
value|((struct msgs *) 0)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* m_getfld() message parsing */
end_comment

begin_define
define|#
directive|define
name|NAMESZ
value|128
end_define

begin_comment
comment|/* Limit on component name size         */
end_comment

begin_define
define|#
directive|define
name|LENERR
value|(-2)
end_define

begin_comment
comment|/* Name too long error from getfld      */
end_comment

begin_define
define|#
directive|define
name|FMTERR
value|(-3)
end_define

begin_comment
comment|/* Message Format error                 */
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
comment|/* Maildrop styles */
end_comment

begin_define
define|#
directive|define
name|MS_DEFAULT
value|0
end_define

begin_comment
comment|/* default (one msg per file) */
end_comment

begin_define
define|#
directive|define
name|MS_UNKNOWN
value|1
end_define

begin_comment
comment|/* type not known yet */
end_comment

begin_define
define|#
directive|define
name|MS_UUCP
value|2
end_define

begin_comment
comment|/* Unix-style "from" lines */
end_comment

begin_define
define|#
directive|define
name|MS_MMDF
value|3
end_define

begin_comment
comment|/* string mmdlm2 */
end_comment

begin_define
define|#
directive|define
name|MS_MSH
value|4
end_define

begin_comment
comment|/* whacko msh */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|msg_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m_getfld() indicators */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|msg_style
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  .. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_delim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  .. */
end_comment

begin_define
define|#
directive|define
name|NOUSE
value|0
end_define

begin_comment
comment|/* draft being re-used */
end_comment

begin_define
define|#
directive|define
name|TFOLDER
value|0
end_define

begin_comment
comment|/* path() given a +folder */
end_comment

begin_define
define|#
directive|define
name|TFILE
value|1
end_define

begin_comment
comment|/* path() given a file */
end_comment

begin_define
define|#
directive|define
name|TSUBCWF
value|2
end_define

begin_comment
comment|/* path() given a @folder */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK
end_ifndef

begin_define
define|#
directive|define
name|LINK
value|"@"
end_define

begin_endif
endif|#
directive|endif
endif|not LINK
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SBACKUP
end_ifndef

begin_define
define|#
directive|define
name|SBACKUP
value|","
end_define

begin_endif
endif|#
directive|endif
endif|not SBACKUP
end_endif

begin_define
define|#
directive|define
name|OUTPUTLINELEN
value|72
end_define

begin_comment
comment|/* default line length for headers */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*  * These standard strings are defined in config.c.  They are the  * only system-dependent parameters in MH, and thus by redefining  * their values and reloading the various modules, MH will run  * on any system.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|components
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|defalt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|digestcomps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|distcomps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|draft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fileproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|foldprot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|forwcomps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|incproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|installproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mailproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mh_defaults
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mh_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mh_seq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mhlformat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mhlforward
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mhlproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|moreproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msgprot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mshproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nsequence
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|packproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|postproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pfolder
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|psequence
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rcvdistcomps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|replcomps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rmfproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rmmproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sendproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|showproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|slocalproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sysed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|usequence
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vmhproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|whatnowproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|whomproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* global variables -sigh- */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ctxflags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CTXMOD
value|0x01
end_define

begin_comment
comment|/* context information modified */
end_comment

begin_define
define|#
directive|define
name|DBITS
value|"\020\01CTXMOD"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OVERHEAD
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|fd_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fd_ctx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|OVERHEAD
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|invo_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pgm invocation name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mypath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's $HOME */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|defpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of user's profile */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ctxpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of user's context */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|node
modifier|*
name|m_defs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* from the MH subroutine library */
end_comment

begin_function_decl
name|char
modifier|*
name|add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adios
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|admonish
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|advise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|advertise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ambigsw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atooi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|brkstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closefds
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
name|copy
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
name|void
name|cpydata
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpydgst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|discard
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|done
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdcompare
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gans
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
name|int
name|getanswer
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
name|void
name|help
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|libpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_atoi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_backup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_convert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_draft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_eomsbr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_file
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
name|void
name|m_fmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_foil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_getdefs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_getfld
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
name|int
name|m_gmprot
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
name|m_maildir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_mailpath
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
name|void
name|m_readefs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|msgs
modifier|*
name|m_remsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_replace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_scratch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_seq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_seqadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_seqbits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_seqdel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_seqflag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_seqnew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_setcur
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_setseq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_setvis
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_sync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|m_tmpfil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_unknown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|m_update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|m_whatnow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makedir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|peekc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pidwait
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pidXwait
parameter_list|(
name|id
parameter_list|,
name|cp
parameter_list|)
value|pidstatus (pidwait (id, NOTOK), stdout, cp)
end_define

begin_function_decl
name|int
name|pidstatus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printsw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|push
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pwd
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

begin_function_decl
name|int
name|refile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|showfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sprintb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssequal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stringdex
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
name|int
name|type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uleq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unputenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uprf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfgets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_include
include|#
directive|include
file|"../h/strings.h"
end_include

begin_comment
comment|/* should be in<stdio.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|_iobuf
modifier|*
name|FP
typedef|;
end_typedef

begin_function_decl
name|FP
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
else|SYS5
end_else

begin_define
define|#
directive|define
name|FP
value|FILE*
end_define

begin_endif
endif|#
directive|endif
endif|SYS5
end_endif

begin_comment
comment|/* miscellaneous */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_define
define|#
directive|define
name|rename
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|(link (f1, f2) != NOTOK ? unlink (f1) : NOTOK)
end_define

begin_endif
endif|#
directive|endif
endif|BSD42
end_endif

begin_define
define|#
directive|define
name|setsig
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|if (signal (s, SIG_IGN) != SIG_IGN) \ 			    (void) signal (s, f)
end_define

begin_define
define|#
directive|define
name|setsigx
parameter_list|(
name|i
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|if ((i = signal (s, SIG_IGN)) != SIG_IGN) \ 			    (void) signal (s, f)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|ruserpass
value|_ruserpass
end_define

begin_endif
endif|#
directive|endif
endif|sun
end_endif

end_unit

