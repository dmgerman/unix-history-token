begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for tar archives.    Copyright (C) 1988, 1992, 1993 Free Software Foundation  This file is part of GNU Tar.  GNU Tar is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Tar is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Tar; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* major() and minor() macros (among other things) defined here for hpux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_include
include|#
directive|include
file|<sys/mknod.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * We need to include<sys/types.h> for the u_quad_t definition  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_define
define|#
directive|define
name|SPARSE_EXT_HDR
value|21
end_define

begin_define
define|#
directive|define
name|SPARSE_IN_HDR
value|4
end_define

begin_struct
struct|struct
name|sparse
block|{
name|char
name|offset
index|[
literal|12
index|]
decl_stmt|;
name|char
name|numbytes
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sp_array
block|{
name|int
name|offset
decl_stmt|;
name|int
name|numbytes
decl_stmt|;
block|}
struct|;
end_struct

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
name|arch_name
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
name|arch_linkname
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
comment|/* these following fields were added by JF for gnu */
comment|/* and are NOT standard */
name|char
name|atime
index|[
literal|12
index|]
decl_stmt|;
name|char
name|ctime
index|[
literal|12
index|]
decl_stmt|;
name|char
name|offset
index|[
literal|12
index|]
decl_stmt|;
name|char
name|longnames
index|[
literal|4
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|NEEDPAD
name|char
name|pad
decl_stmt|;
endif|#
directive|endif
name|struct
name|sparse
name|sp
index|[
name|SPARSE_IN_HDR
index|]
decl_stmt|;
name|char
name|isextended
decl_stmt|;
name|char
name|realsize
index|[
literal|12
index|]
decl_stmt|;
comment|/* true size of the sparse file */
comment|/* char	ending_blanks[12];*/
comment|/* number of nulls at the 	   end of the file, if any */
block|}
name|header
struct|;
struct|struct
name|extended_header
block|{
name|struct
name|sparse
name|sp
index|[
literal|21
index|]
decl_stmt|;
name|char
name|isextended
decl_stmt|;
block|}
name|ext_hdr
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
comment|/* Note that the standards committee allows only capital A through    capital Z for user-defined expansion.  This means that defining something    as, say '8' is a *bad* idea. */
end_comment

begin_define
define|#
directive|define
name|LF_DUMPDIR
value|'D'
end_define

begin_comment
comment|/* This is a dir entry that contains 					   the names of files that were in 					   the dir at the time the dump 					   was made */
end_comment

begin_define
define|#
directive|define
name|LF_LONGLINK
value|'K'
end_define

begin_comment
comment|/* Identifies the NEXT file on the tape 					   as having a long linkname */
end_comment

begin_define
define|#
directive|define
name|LF_LONGNAME
value|'L'
end_define

begin_comment
comment|/* Identifies the NEXT file on the tape 					   as having a long name. */
end_comment

begin_define
define|#
directive|define
name|LF_MULTIVOL
value|'M'
end_define

begin_comment
comment|/* This is the continuation 					   of a file that began on another 					   volume */
end_comment

begin_define
define|#
directive|define
name|LF_NAMES
value|'N'
end_define

begin_comment
comment|/* For storing filenames that didn't 					   fit in 100 characters */
end_comment

begin_define
define|#
directive|define
name|LF_SPARSE
value|'S'
end_define

begin_comment
comment|/* This is for sparse files */
end_comment

begin_define
define|#
directive|define
name|LF_VOLHDR
value|'V'
end_define

begin_comment
comment|/* This file is a tape/volume header */
end_comment

begin_comment
comment|/* Ignore it on extraction */
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

begin_define
define|#
directive|define
name|EX_BADVOL
value|5
end_define

begin_comment
comment|/* Special error code means 				   Tape volume doesn't match the one 				   specified on the command line */
end_comment

begin_define
define|#
directive|define
name|EX_BADDIR
value|6
end_define

begin_comment
comment|/* bad directory name */
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
name|info_script
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Script to run at end of each tape change */
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
name|filename_terminator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* \n or \0. */
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

begin_decl_stmt
name|TAR_EXTERN
name|struct
name|sp_array
modifier|*
name|sparsearray
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the start of the scratch space */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|sp_array_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial size of the sparsearray */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|u_quad_t
name|tot_written
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Total written to output */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|struct
name|re_pattern_buffer
modifier|*
name|label_pattern
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compiled regex for extract label */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
modifier|*
name|ar_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of tape drive names */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|n_ar_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of tape drive names */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|cur_ar_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape drive currently being used */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|ar_files_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* malloced size of ar_files */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|current_file_name
decl_stmt|,
modifier|*
name|current_link_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Flags from the command line  */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|cmd_mode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CMD_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CMD_CAT
value|1
end_define

begin_comment
comment|/* -A */
end_comment

begin_define
define|#
directive|define
name|CMD_CREATE
value|2
end_define

begin_comment
comment|/* -c */
end_comment

begin_define
define|#
directive|define
name|CMD_DIFF
value|3
end_define

begin_comment
comment|/* -d */
end_comment

begin_define
define|#
directive|define
name|CMD_APPEND
value|4
end_define

begin_comment
comment|/* -r */
end_comment

begin_define
define|#
directive|define
name|CMD_LIST
value|5
end_define

begin_comment
comment|/* -t */
end_comment

begin_define
define|#
directive|define
name|CMD_UPDATE
value|6
end_define

begin_comment
comment|/* -u */
end_comment

begin_define
define|#
directive|define
name|CMD_EXTRACT
value|7
end_define

begin_comment
comment|/* -x */
end_comment

begin_define
define|#
directive|define
name|CMD_DELETE
value|8
end_define

begin_comment
comment|/* -D */
end_comment

begin_define
define|#
directive|define
name|CMD_VERSION
value|9
end_define

begin_comment
comment|/* --version */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_reblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -B */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_dironly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -n */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_run_script_at_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -F */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_gnudump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -G */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_follow_links
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -h */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_ignorez
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -i */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_keep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -k */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_startfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -K */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_local_filesys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -l */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|tape_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -L */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -m */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_multivol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -M */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_new_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -N */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_oldarch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -o */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_exstdout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -O */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_use_protection
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -p */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_absolute_paths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -P */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_sayblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -R */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_sorted_names
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -s */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_sparse_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -S  ... JK */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_namefile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -T */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -v */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|f_volhdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -V */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_confirm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_verify
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -W */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_exclude
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -X */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|f_compressprog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -z and -Z */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_do_chown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --do-chown */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_totals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --totals */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_remove_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --remove-files */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_ignore_failed_read
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --ignore-failed-read */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_checkpoint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --checkpoint */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_show_omitted_dirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --show-omitted-dirs */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|f_volno_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --volno-file */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_force_local
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --force-local */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_atime_preserve
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --atime-preserve */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_compress_block
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --compress-block */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_unlink
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --unlink */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|int
name|f_fast_read
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --fast-read */
end_comment

begin_comment
comment|/*  * We default to Unix Standard format rather than 4.2BSD tar format.  * The code can actually produce all three:  *	f_standard	ANSI standard  *	f_oldarch	V7  *	neither		4.2BSD  * but we don't bother, since 4.2BSD can read ANSI standard format anyway.  * The only advantage to the "neither" option is that we can cmp our  * output to the output of 4.2BSD tar, for debugging.  */
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
comment|/* cached strlen(name) */
name|char
name|found
decl_stmt|;
comment|/* A matching file has been found */
name|char
name|firstch
decl_stmt|;
comment|/* First char is literally matched */
name|char
name|regexp
decl_stmt|;
comment|/* This name is a regexp, not literal */
name|char
modifier|*
name|change_dir
decl_stmt|;
comment|/* JF set with the -C option */
name|char
modifier|*
name|dir_contents
decl_stmt|;
comment|/* JF for f_gnudump */
name|char
name|fake
decl_stmt|;
comment|/* dummy entry */
name|char
name|name
index|[
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

begin_decl_stmt
name|TAR_EXTERN
name|char
modifier|*
name|gnu_dumpfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Error recovery stuff  */
end_comment

begin_decl_stmt
name|TAR_EXTERN
name|char
name|read_error_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * global boolean, see name_match in tar.c  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nlpsfreed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Declarations of functions available to the world.  */
end_comment

begin_function_decl
name|union
name|record
modifier|*
name|findrec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|userec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|union
name|record
modifier|*
name|endofrecs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|anno
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VPRINTF
argument_list|)
operator|&&
name|__STDC__
end_if

begin_function_decl
name|void
name|msg
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_perror
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|msg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_perror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

