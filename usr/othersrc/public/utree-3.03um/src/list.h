begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      LIST.H  *      UTREE tree and file list definitions.  *      3.03-um klin, Sat Jan 11 19:53:57 1992, Splitted from defs.h  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_list
index|[]
init|=
literal|"@(#) utree 3.03-um (klin) Feb 11 1992 list.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/*  *      Files in a directory are hold in dynamically allocated array  *      of a record type flist which is linked into directory type dlist.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_flist
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/*  File name                           */
name|time_t
name|modtime
decl_stmt|;
comment|/*  Modification time                   */
name|off_t
name|filesize
decl_stmt|;
comment|/*  File size                           */
name|char
name|istagged
decl_stmt|;
comment|/*  File is tagged                      */
name|char
name|filemode
decl_stmt|;
comment|/*  File modes                          */
block|}
name|flist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FNULL
value|((flist *) 0)
end_define

begin_comment
comment|/* The flist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Directories are hold in a double linked list of a record type  *      dlist which is built up at startup time or later at runtime.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dlist
block|{
name|glist
name|list
decl_stmt|;
comment|/*  Containing pathname and pointers    */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/*  Directory basename                  */
name|flist
modifier|*
name|filevec
decl_stmt|;
comment|/*  Pointer to flist entries            */
name|char
modifier|*
name|zoompattern
decl_stmt|;
comment|/*  File zooming pattern                */
name|char
modifier|*
name|filebuf
decl_stmt|;
comment|/*  Buffer of filenames                 */
name|unsigned
name|bufsize
decl_stmt|;
comment|/*  Size of filename buffer             */
name|int
name|number
decl_stmt|;
comment|/*  Directory number                    */
name|int
name|level
decl_stmt|;
comment|/*  Subdirectory level                  */
name|unsigned
name|long
name|treeinfo
decl_stmt|;
comment|/*  Tree information flag               */
name|int
name|nfils
decl_stmt|;
comment|/*  Number of files                     */
name|int
name|ndirs
decl_stmt|;
comment|/*  Number of subdirectories            */
name|int
name|ntags
decl_stmt|;
comment|/*  Number of tagged files              */
name|int
name|curfile
decl_stmt|;
comment|/*  Current file in file list           */
name|int
name|topfile
decl_stmt|;
comment|/*  First file on screen in file list   */
name|char
name|cancd
decl_stmt|;
comment|/*  Can change to this directory        */
name|char
name|flag
decl_stmt|;
comment|/*  Filelist flag                       */
name|char
name|sort
decl_stmt|;
comment|/*  Sort criteria flag                  */
name|time_t
name|modtime
decl_stmt|;
comment|/*  Modification time of directory      */
name|time_t
name|chgtime
decl_stmt|;
comment|/*  Status change time of directory     */
block|}
name|dlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNULL
value|((dlist *) 0)
end_define

begin_comment
comment|/* The dlist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to items of dlist record is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|DLIST
parameter_list|(
name|p
parameter_list|)
value|(&(p)->list)
end_define

begin_define
define|#
directive|define
name|DPNAM
parameter_list|(
name|p
parameter_list|)
value|((p)->list.string)
end_define

begin_define
define|#
directive|define
name|DPREV
parameter_list|(
name|p
parameter_list|)
value|((p)->list.prev)
end_define

begin_define
define|#
directive|define
name|DNEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->list.next)
end_define

begin_define
define|#
directive|define
name|DFNAM
parameter_list|(
name|p
parameter_list|)
value|((p)->filename)
end_define

begin_define
define|#
directive|define
name|DFVEC
parameter_list|(
name|p
parameter_list|)
value|((p)->filevec)
end_define

begin_define
define|#
directive|define
name|DZOOM
parameter_list|(
name|p
parameter_list|)
value|((p)->zoompattern)
end_define

begin_define
define|#
directive|define
name|DFBUF
parameter_list|(
name|p
parameter_list|)
value|((p)->filebuf)
end_define

begin_define
define|#
directive|define
name|DBSIZ
parameter_list|(
name|p
parameter_list|)
value|((p)->bufsize)
end_define

begin_define
define|#
directive|define
name|DDNUM
parameter_list|(
name|p
parameter_list|)
value|((p)->number)
end_define

begin_define
define|#
directive|define
name|DLEVL
parameter_list|(
name|p
parameter_list|)
value|((p)->level)
end_define

begin_define
define|#
directive|define
name|DINFO
parameter_list|(
name|p
parameter_list|)
value|((p)->treeinfo)
end_define

begin_define
define|#
directive|define
name|DNFIL
parameter_list|(
name|p
parameter_list|)
value|((p)->nfils)
end_define

begin_define
define|#
directive|define
name|DNDIR
parameter_list|(
name|p
parameter_list|)
value|((p)->ndirs)
end_define

begin_define
define|#
directive|define
name|DNTAG
parameter_list|(
name|p
parameter_list|)
value|((p)->ntags)
end_define

begin_define
define|#
directive|define
name|DFCUR
parameter_list|(
name|p
parameter_list|)
value|((p)->curfile)
end_define

begin_define
define|#
directive|define
name|DFTOP
parameter_list|(
name|p
parameter_list|)
value|((p)->topfile)
end_define

begin_define
define|#
directive|define
name|DCANC
parameter_list|(
name|p
parameter_list|)
value|((p)->cancd)
end_define

begin_define
define|#
directive|define
name|DFLAG
parameter_list|(
name|p
parameter_list|)
value|((p)->flag)
end_define

begin_define
define|#
directive|define
name|DSORT
parameter_list|(
name|p
parameter_list|)
value|((p)->sort)
end_define

begin_define
define|#
directive|define
name|DMTIM
parameter_list|(
name|p
parameter_list|)
value|((p)->modtime)
end_define

begin_define
define|#
directive|define
name|DCTIM
parameter_list|(
name|p
parameter_list|)
value|((p)->chgtime)
end_define

begin_comment
comment|/*  *      The same access macros as above for current directory entry.  */
end_comment

begin_define
define|#
directive|define
name|CLIST
value|(&cdlist->list)
end_define

begin_define
define|#
directive|define
name|CPNAM
value|(cdlist->list.string)
end_define

begin_define
define|#
directive|define
name|CPREV
value|(cdlist->list.prev)
end_define

begin_define
define|#
directive|define
name|CNEXT
value|(cdlist->list.next)
end_define

begin_define
define|#
directive|define
name|CFNAM
value|(cdlist->filename)
end_define

begin_define
define|#
directive|define
name|CFVEC
value|(cdlist->filevec)
end_define

begin_define
define|#
directive|define
name|CZOOM
value|(cdlist->zoompattern)
end_define

begin_define
define|#
directive|define
name|CFBUF
value|(cdlist->filebuf)
end_define

begin_define
define|#
directive|define
name|CBSIZ
value|(cdlist->bufsize)
end_define

begin_define
define|#
directive|define
name|CDNUM
value|(cdlist->number)
end_define

begin_define
define|#
directive|define
name|CLEVL
value|(cdlist->level)
end_define

begin_define
define|#
directive|define
name|CINFO
value|(cdlist->treeinfo)
end_define

begin_define
define|#
directive|define
name|CNFIL
value|(cdlist->nfils)
end_define

begin_define
define|#
directive|define
name|CNDIR
value|(cdlist->ndirs)
end_define

begin_define
define|#
directive|define
name|CNTAG
value|(cdlist->ntags)
end_define

begin_define
define|#
directive|define
name|CFCUR
value|(cdlist->curfile)
end_define

begin_define
define|#
directive|define
name|CFTOP
value|(cdlist->topfile)
end_define

begin_define
define|#
directive|define
name|CCANC
value|(cdlist->cancd)
end_define

begin_define
define|#
directive|define
name|CFLAG
value|(cdlist->flag)
end_define

begin_define
define|#
directive|define
name|CSORT
value|(cdlist->sort)
end_define

begin_define
define|#
directive|define
name|CMTIM
value|(cdlist->modtime)
end_define

begin_define
define|#
directive|define
name|CCTIM
value|(cdlist->chgtime)
end_define

begin_comment
comment|/* Compare modification and change time from dlist p with status s      */
end_comment

begin_define
define|#
directive|define
name|CHKTIM
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|((p)->modtime<st.st_mtime||(p)->chgtime<st.st_ctime)
end_define

begin_comment
comment|/* Column and row of directory p on directory tree screen               */
end_comment

begin_define
define|#
directive|define
name|DTCOL
parameter_list|(
name|p
parameter_list|)
value|((p)->level*indent)
end_define

begin_define
define|#
directive|define
name|DTROW
parameter_list|(
name|p
parameter_list|)
value|((p)->number-tdlist->number+firstdline)
end_define

begin_comment
comment|/*  *      Access to items of flist record is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_comment
comment|/* Access macros to flist items pointed to by flist ptr f               */
end_comment

begin_define
define|#
directive|define
name|FPFIL
parameter_list|(
name|f
parameter_list|)
value|(f->filename)
end_define

begin_define
define|#
directive|define
name|FPTIM
parameter_list|(
name|f
parameter_list|)
value|(f->modtime)
end_define

begin_define
define|#
directive|define
name|FPSIZ
parameter_list|(
name|f
parameter_list|)
value|(f->filesize)
end_define

begin_define
define|#
directive|define
name|FPTAG
parameter_list|(
name|f
parameter_list|)
value|(f->istagged)
end_define

begin_define
define|#
directive|define
name|FPMOD
parameter_list|(
name|f
parameter_list|)
value|(f->filemode)
end_define

begin_comment
comment|/* Access macros to flist items in flist vector v with index n          */
end_comment

begin_define
define|#
directive|define
name|FVFIL
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(v[n].filename)
end_define

begin_define
define|#
directive|define
name|FVTIM
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(v[n].modtime)
end_define

begin_define
define|#
directive|define
name|FVSIZ
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(v[n].filesize)
end_define

begin_define
define|#
directive|define
name|FVTAG
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(v[n].istagged)
end_define

begin_define
define|#
directive|define
name|FVMOD
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(v[n].filemode)
end_define

begin_comment
comment|/* Access macros to flist with index n from directory pointed to by p   */
end_comment

begin_define
define|#
directive|define
name|FLIST
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n])
end_define

begin_define
define|#
directive|define
name|FFNAM
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n].filename)
end_define

begin_define
define|#
directive|define
name|FMTIM
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n].modtime)
end_define

begin_define
define|#
directive|define
name|FSIZE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n].filesize)
end_define

begin_define
define|#
directive|define
name|FITAG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n].istagged)
end_define

begin_define
define|#
directive|define
name|FMODE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(p->filevec[n].filemode)
end_define

begin_comment
comment|/* Column and row of file n from directory p                            */
end_comment

begin_define
define|#
directive|define
name|FFCOL
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(((n-p->topfile)%fperline)*FWINSZ)
end_define

begin_define
define|#
directive|define
name|FFROW
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|((n-p->topfile)/fperline+firstline)
end_define

begin_comment
comment|/* Column and row of file n in file window on tree screen               */
end_comment

begin_define
define|#
directive|define
name|FTCOL
parameter_list|(
name|n
parameter_list|)
value|((n%fperline)*FWINSZ)
end_define

begin_define
define|#
directive|define
name|FTROW
parameter_list|(
name|n
parameter_list|)
value|(n/fperline+firstfline)
end_define

begin_comment
comment|/* Values for directory list file list flag                             */
end_comment

begin_define
define|#
directive|define
name|FL_NUL
value|0x00
end_define

begin_comment
comment|/* File list not read in                */
end_comment

begin_define
define|#
directive|define
name|FL_CHG
value|0x01
end_define

begin_comment
comment|/* File list changed                    */
end_comment

begin_define
define|#
directive|define
name|FL_FIL
value|0x02
end_define

begin_comment
comment|/* File list read in                    */
end_comment

begin_comment
comment|/* Values for file mode and flags                                       */
end_comment

begin_define
define|#
directive|define
name|FF_NONE
value|' '
end_define

begin_comment
comment|/* Ordinary file                        */
end_comment

begin_define
define|#
directive|define
name|FF_ERR
value|'?'
end_define

begin_comment
comment|/* Can't stat file                      */
end_comment

begin_define
define|#
directive|define
name|FF_EXEC
value|'*'
end_define

begin_comment
comment|/* Executable                           */
end_comment

begin_define
define|#
directive|define
name|FF_DIR
value|'/'
end_define

begin_comment
comment|/* Directory                            */
end_comment

begin_define
define|#
directive|define
name|FF_SLNK
value|'@'
end_define

begin_comment
comment|/* Symbolic link                        */
end_comment

begin_define
define|#
directive|define
name|FF_SOCK
value|'='
end_define

begin_comment
comment|/* Socket AF_UNIX                       */
end_comment

begin_define
define|#
directive|define
name|FF_TAG
value|'+'
end_define

begin_comment
comment|/* File is tagged                       */
end_comment

begin_define
define|#
directive|define
name|FF_MARK
value|'>'
end_define

begin_comment
comment|/* Mark on file                         */
end_comment

begin_define
define|#
directive|define
name|ISTAG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|(FITAG(p, n)  == FF_TAG)
end_define

end_unit

