begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file for public domain tar (tape archive) program.  *  * @(#)tar.h 1.20 86/10/29	Public Domain.  *  * Created 25 August 1985 by John Gilmore, ihnp4!hoptoad!gnu.  *  * $Id: tar.h,v 1.5 1999/01/13 15:44:10 christos Exp $ # checkin only  */
end_comment

begin_comment
comment|/*  * Kludge for handling systems that can't cope with multiple  * external definitions of a variable.  In ONE routine (tar.c),  * we #define TAR_EXTERN to null; here, we set it to "extern" if  * it is not already set.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TAR_EXTERN
end_ifndef

begin_define
define|#
directive|define
name|TAR_EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Header block on tape.  *  * I'm going to use traditional DP naming conventions here.  * A "block" is a big chunk of stuff that we do I/O on.  * A "record" is a piece of info that we care about.  * Typically many "record"s fit into a "block".  */
end_comment

begin_define
define|#
directive|define
name|RECORDSIZE
value|512
end_define

begin_define
define|#
directive|define
name|NAMSIZ
value|100
end_define

begin_define
define|#
directive|define
name|TUNMLEN
value|32
end_define

begin_define
define|#
directive|define
name|TGNMLEN
value|32
end_define

begin_union
union|union
name|record
block|{
name|char
name|charptr
index|[
name|RECORDSIZE
index|]
decl_stmt|;
struct|struct
name|header
block|{
name|char
name|name
index|[
name|NAMSIZ
index|]
decl_stmt|;
name|char
name|mode
index|[
literal|8
index|]
decl_stmt|;
name|char
name|uid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|gid
index|[
literal|8
index|]
decl_stmt|;
name|char
name|size
index|[
literal|12
index|]
decl_stmt|;
name|char
name|mtime
index|[
literal|12
index|]
decl_stmt|;
name|char
name|chksum
index|[
literal|8
index|]
decl_stmt|;
name|char
name|linkflag
decl_stmt|;
name|char
name|linkname
index|[
name|NAMSIZ
index|]
decl_stmt|;
name|char
name|magic
index|[
literal|8
index|]
decl_stmt|;
name|char
name|uname
index|[
name|TUNMLEN
index|]
decl_stmt|;
name|char
name|gname
index|[
name|TGNMLEN
index|]
decl_stmt|;
name|char
name|devmajor
index|[
literal|8
index|]
decl_stmt|;
name|char
name|devminor
index|[
literal|8
index|]
decl_stmt|;
block|}
name|header
struct|;
block|}
union|;
end_union

begin_comment
comment|/* The checksum field is filled with this while the checksum is computed. */
end_comment

begin_define
define|#
directive|define
name|CHKBLANKS
value|"        "
end_define

begin_comment
comment|/* 8 blanks, no null */
end_comment

begin_comment
comment|/* The magic field is filled with this if uname and gname are valid. */
end_comment

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar  "
end_define

begin_comment
comment|/* 7 chars and a null */
end_comment

begin_comment
comment|/* The linkflag defines the type of file */
end_comment

begin_define
define|#
directive|define
name|LF_OLDNORMAL
value|'\0'
end_define

begin_comment
comment|/* Normal disk file, Unix compat */
end_comment

begin_define
define|#
directive|define
name|LF_NORMAL
value|'0'
end_define

begin_comment
comment|/* Normal disk file */
end_comment

begin_define
define|#
directive|define
name|LF_LINK
value|'1'
end_define

begin_comment
comment|/* Link to previously dumped file */
end_comment

begin_define
define|#
directive|define
name|LF_SYMLINK
value|'2'
end_define

begin_comment
comment|/* Symbolic link */
end_comment

begin_define
define|#
directive|define
name|LF_CHR
value|'3'
end_define

begin_comment
comment|/* Character special file */
end_comment

begin_define
define|#
directive|define
name|LF_BLK
value|'4'
end_define

begin_comment
comment|/* Block special file */
end_comment

begin_define
define|#
directive|define
name|LF_DIR
value|'5'
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|LF_FIFO
value|'6'
end_define

begin_comment
comment|/* FIFO special file */
end_comment

begin_define
define|#
directive|define
name|LF_CONTIG
value|'7'
end_define

begin_comment
comment|/* Contiguous file */
end_comment

begin_comment
comment|/* Further link types may be defined later. */
end_comment

begin_comment
comment|/*  * Exit codes from the "tar" program  */
end_comment

begin_define
define|#
directive|define
name|EX_SUCCESS
value|0
end_define

begin_comment
comment|/* success! */
end_comment

begin_define
define|#
directive|define
name|EX_ARGSBAD
value|1
end_define

begin_comment
comment|/* invalid args */
end_comment

begin_define
define|#
directive|define
name|EX_BADFILE
value|2
end_define

begin_comment
comment|/* invalid filename */
end_comment

begin_define
define|#
directive|define
name|EX_BADARCH
value|3
end_define

begin_comment
comment|/* bad archive */
end_comment

begin_define
define|#
directive|define
name|EX_SYSTEM
value|4
end_define

begin_comment
comment|/* system gave unexpected error */
end_comment

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|union
name|record
modifier|*
name|ar_block
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start of block of archive */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|union
name|record
modifier|*
name|ar_record
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current record of archive */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|union
name|record
modifier|*
name|ar_last
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last+1 record of archive block */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|ar_reading
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 writing, !0 reading archive */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|blocking
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of each block, in records */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of each block, in bytes */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|ar_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File containing archive */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|name_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File containing names to work on */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|tar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of this program */
end_comment

begin_comment
comment|/*  * Flags from the command line  */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_reblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -B */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_create
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -c */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -d */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_sayblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -D */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_follow_links
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -h */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_ignorez
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -i */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_keep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -k */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -m */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_oldarch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -o */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_use_protection
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -p */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_sorted_names
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -s */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -t */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_namefile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -T */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -v */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_extract
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -x */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|f_compress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -z */
end_comment

begin_comment
comment|/*  * We now default to Unix Standard format rather than 4.2BSD tar format.  * The code can actually produce all three:  *	f_standard	ANSI standard  *	f_oldarch	V7  *	neither		4.2BSD  * but we don't bother, since 4.2BSD can read ANSI standard format anyway.  * The only advantage to the "neither" option is that we can cmp(1) our  * output to the output of 4.2BSD tar, for debugging.  */
end_comment

begin_define
define|#
directive|define
name|f_standard
value|(!f_oldarch)
end_define

begin_comment
comment|/*  * Structure for keeping track of filenames and lists thereof.  */
end_comment

begin_struct
struct|struct
name|name
block|{
name|struct
name|name
modifier|*
name|next
decl_stmt|;
name|short
name|length
decl_stmt|;
name|char
name|found
decl_stmt|;
name|char
name|name
index|[
name|NAMSIZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|TAR_EXTERN
name|struct
name|name
modifier|*
name|namelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to first name in list */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|struct
name|name
modifier|*
name|namelast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to last name in list */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor for archive file */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of files in error */
end_comment

begin_comment
comment|/*  *  * Due to the next struct declaration, each routine that includes  * "tar.h" must also include<sys/types.h>.  I tried to make it automatic,  * but System V has no defines in<sys/types.h>, so there is no way of  * knowing when it has been included.  In addition, it cannot be included  * twice, but must be included exactly once.  Argghh!  *  * Thanks, typedef.  Thanks, USG.  */
end_comment

begin_struct
struct|struct
name|link
block|{
name|struct
name|link
modifier|*
name|next
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|short
name|linkcount
decl_stmt|;
name|char
name|name
index|[
name|NAMSIZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|TAR_EXTERN
name|struct
name|link
modifier|*
name|linklist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to first link in list */
end_comment

begin_comment
comment|/*  * Error recovery stuff  */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|read_error_flag
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Declarations of functions available to the world.  */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_define
define|#
directive|define
name|annorec
parameter_list|(
name|stream
parameter_list|,
name|msg
parameter_list|)
value|anno(stream, msg, 0)
end_define

begin_comment
comment|/* Cur rec */
end_comment

begin_define
define|#
directive|define
name|annofile
parameter_list|(
name|stream
parameter_list|,
name|msg
parameter_list|)
value|anno(stream, msg, 1)
end_define

begin_comment
comment|/* Saved rec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

