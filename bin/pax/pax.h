begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pax.h	8.2 (Berkeley) 4/18/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * BSD PAX global data structures and constants.  */
end_comment

begin_define
define|#
directive|define
name|MAXBLK
value|64512
end_define

begin_comment
comment|/* MAX blocksize supported (posix SPEC) */
end_comment

begin_comment
comment|/* WARNING: increasing MAXBLK past 32256 */
end_comment

begin_comment
comment|/* will violate posix spec. */
end_comment

begin_define
define|#
directive|define
name|MAXBLK_POSIX
value|32256
end_define

begin_comment
comment|/* MAX blocksize supported as per POSIX */
end_comment

begin_define
define|#
directive|define
name|BLKMULT
value|512
end_define

begin_comment
comment|/* blocksize must be even mult of 512 bytes */
end_comment

begin_comment
comment|/* Don't even think of changing this */
end_comment

begin_define
define|#
directive|define
name|DEVBLK
value|8192
end_define

begin_comment
comment|/* default read blksize for devices */
end_comment

begin_define
define|#
directive|define
name|FILEBLK
value|10240
end_define

begin_comment
comment|/* default read blksize for files */
end_comment

begin_define
define|#
directive|define
name|PAXPATHLEN
value|3072
end_define

begin_comment
comment|/* maximum path length for pax. MUST be */
end_comment

begin_comment
comment|/* longer than the system PATH_MAX */
end_comment

begin_comment
comment|/*  * Pax modes of operation  */
end_comment

begin_define
define|#
directive|define
name|LIST
value|0
end_define

begin_comment
comment|/* List the file in an archive */
end_comment

begin_define
define|#
directive|define
name|EXTRACT
value|1
end_define

begin_comment
comment|/* extract the files in an archive */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE
value|2
end_define

begin_comment
comment|/* write a new archive */
end_comment

begin_define
define|#
directive|define
name|APPND
value|3
end_define

begin_comment
comment|/* append to the end of an archive */
end_comment

begin_define
define|#
directive|define
name|COPY
value|4
end_define

begin_comment
comment|/* copy files to destination dir */
end_comment

begin_define
define|#
directive|define
name|DEFOP
value|LIST
end_define

begin_comment
comment|/* if no flags default is to LIST */
end_comment

begin_comment
comment|/*  * Device type of the current archive volume  */
end_comment

begin_define
define|#
directive|define
name|ISREG
value|0
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|ISCHR
value|1
end_define

begin_comment
comment|/* character device */
end_comment

begin_define
define|#
directive|define
name|ISBLK
value|2
end_define

begin_comment
comment|/* block device */
end_comment

begin_define
define|#
directive|define
name|ISTAPE
value|3
end_define

begin_comment
comment|/* tape drive */
end_comment

begin_define
define|#
directive|define
name|ISPIPE
value|4
end_define

begin_comment
comment|/* pipe/socket */
end_comment

begin_comment
comment|/*  * Format Specific Routine Table  *  * The format specific routine table allows new archive formats to be quickly  * added. Overall pax operation is independent of the actual format used to  * form the archive. Only those routines which deal directly with the archive  * are tailored to the oddities of the specific format. All other routines are  * independent of the archive format. Data flow in and out of the format  * dependent routines pass pointers to ARCHD structure (described below).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of format, this is the name the user */
comment|/* gives to -x option to select it. */
name|int
name|bsz
decl_stmt|;
comment|/* default block size. used when the user */
comment|/* does not specify a blocksize for writing */
comment|/* Appends continue to with the blocksize */
comment|/* the archive is currently using. */
name|int
name|hsz
decl_stmt|;
comment|/* Header size in bytes. this is the size of */
comment|/* the smallest header this format supports. */
comment|/* Headers are assumed to fit in a BLKMULT. */
comment|/* If they are bigger, get_head() and */
comment|/* get_arc() must be adjusted */
name|int
name|udev
decl_stmt|;
comment|/* does append require unique dev/ino? some */
comment|/* formats use the device and inode fields */
comment|/* to specify hard links. when members in */
comment|/* the archive have the same inode/dev they */
comment|/* are assumed to be hard links. During */
comment|/* append we may have to generate unique ids */
comment|/* to avoid creating incorrect hard links */
name|int
name|hlk
decl_stmt|;
comment|/* does archive store hard links info? if */
comment|/* not, we do not bother to look for them */
comment|/* during archive write operations */
name|int
name|blkalgn
decl_stmt|;
comment|/* writes must be aligned to blkalgn boundary */
name|int
name|inhead
decl_stmt|;
comment|/* is the trailer encoded in a valid header? */
comment|/* if not, trailers are assumed to be found */
comment|/* in invalid headers (i.e like tar) */
name|int
function_decl|(
modifier|*
name|id
function_decl|)
parameter_list|()
function_decl|;
comment|/* checks if a buffer is a valid header */
comment|/* returns 1 if it is, o.w. returns a 0 */
name|int
function_decl|(
modifier|*
name|st_rd
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialize routine for read. so format */
comment|/* can set up tables etc before it starts */
comment|/* reading an archive */
name|int
function_decl|(
modifier|*
name|rd
function_decl|)
parameter_list|()
function_decl|;
comment|/* read header routine. passed a pointer to */
comment|/* ARCHD. It must extract the info from the */
comment|/* format and store it in the ARCHD struct. */
comment|/* This routine is expected to fill all the */
comment|/* fields in the ARCHD (including stat buf) */
comment|/* 0 is returned when a valid header is */
comment|/* found. -1 when not valid. This routine */
comment|/* set the skip and pad fields so the format */
comment|/* independent routines know the amount of */
comment|/* padding and the number of bytes of data */
comment|/* which follow the header. This info is */
comment|/* used skip to the next file header */
name|off_t
function_decl|(
modifier|*
name|end_rd
function_decl|)
parameter_list|()
function_decl|;
comment|/* read cleanup. Allows format to clean up */
comment|/* and MUST RETURN THE LENGTH OF THE TRAILER */
comment|/* RECORD (so append knows how many bytes */
comment|/* to move back to rewrite the trailer) */
name|int
function_decl|(
modifier|*
name|st_wr
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialize routine for write operations */
name|int
function_decl|(
modifier|*
name|wr
function_decl|)
parameter_list|()
function_decl|;
comment|/* write archive header. Passed an ARCHD */
comment|/* filled with the specs on the next file to */
comment|/* archived. Returns a 1 if no file data is */
comment|/* is to be stored; 0 if file data is to be */
comment|/* added. A -1 is returned if a write */
comment|/* operation to the archive failed. this */
comment|/* function sets the skip and pad fields so */
comment|/* the proper padding can be added after */
comment|/* file data. This routine must NEVER write */
comment|/* a flawed archive header. */
name|int
function_decl|(
modifier|*
name|end_wr
function_decl|)
parameter_list|()
function_decl|;
comment|/* end write. write the trailer and do any */
comment|/* other format specific functions needed */
comment|/* at the end of a archive write */
name|int
function_decl|(
modifier|*
name|trail
function_decl|)
parameter_list|()
function_decl|;
comment|/* returns 0 if a valid trailer, -1 if not */
comment|/* For formats which encode the trailer */
comment|/* outside of a valid header, a return value */
comment|/* of 1 indicates that the block passed to */
comment|/* it can never contain a valid header (skip */
comment|/* this block, no point in looking at it)  */
comment|/* CAUTION: parameters to this function are */
comment|/* different for trailers inside or outside */
comment|/* of headers. See get_head() for details */
name|int
function_decl|(
modifier|*
name|rd_data
function_decl|)
parameter_list|()
function_decl|;
comment|/* read/process file data from the archive */
name|int
function_decl|(
modifier|*
name|wr_data
function_decl|)
parameter_list|()
function_decl|;
comment|/* write/process file data to the archive */
name|int
function_decl|(
modifier|*
name|options
function_decl|)
parameter_list|()
function_decl|;
comment|/* process format specific options (-o) */
block|}
name|FSUB
typedef|;
end_typedef

begin_comment
comment|/*  * Pattern matching structure  *  * Used to store command line patterns  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pattern
block|{
name|char
modifier|*
name|pstr
decl_stmt|;
comment|/* pattern to match, user supplied */
name|char
modifier|*
name|pend
decl_stmt|;
comment|/* end of a prefix match */
name|char
modifier|*
name|chdname
decl_stmt|;
comment|/* the dir to change to if not NULL.  */
name|int
name|plen
decl_stmt|;
comment|/* length of pstr */
name|int
name|flgs
decl_stmt|;
comment|/* processing/state flags */
define|#
directive|define
name|MTCH
value|0x1
comment|/* pattern has been matched */
define|#
directive|define
name|DIR_MTCH
value|0x2
comment|/* pattern matched a directory */
name|struct
name|pattern
modifier|*
name|fow
decl_stmt|;
comment|/* next pattern */
block|}
name|PATTERN
typedef|;
end_typedef

begin_comment
comment|/*  * General Archive Structure (used internal to pax)  *  * This structure is used to pass information about archive members between  * the format independent routines and the format specific routines. When  * new archive formats are added, they must accept requests and supply info  * encoded in a structure of this type. The name fields are declared statically  * here, as there is only ONE of these floating around, size is not a major  * consideration. Eventually converting the name fields to a dynamic length  * may be required if and when the supporting operating system removes all  * restrictions on the length of pathnames it will resolve.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|nlen
decl_stmt|;
comment|/* file name length */
name|char
name|name
index|[
name|PAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* file name */
name|int
name|ln_nlen
decl_stmt|;
comment|/* link name length */
name|char
name|ln_name
index|[
name|PAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name to link to (if any) */
name|char
modifier|*
name|org_name
decl_stmt|;
comment|/* orig name in file system */
name|PATTERN
modifier|*
name|pat
decl_stmt|;
comment|/* ptr to pattern match (if any) */
name|struct
name|stat
name|sb
decl_stmt|;
comment|/* stat buffer see stat(2) */
name|off_t
name|pad
decl_stmt|;
comment|/* bytes of padding after file xfer */
name|off_t
name|skip
decl_stmt|;
comment|/* bytes of real data after header */
comment|/* IMPORTANT. The st_size field does */
comment|/* not always indicate the amount of */
comment|/* data following the header. */
name|u_long
name|crc
decl_stmt|;
comment|/* file crc */
name|int
name|type
decl_stmt|;
comment|/* type of file node */
define|#
directive|define
name|PAX_DIR
value|1
comment|/* directory */
define|#
directive|define
name|PAX_CHR
value|2
comment|/* character device */
define|#
directive|define
name|PAX_BLK
value|3
comment|/* block device */
define|#
directive|define
name|PAX_REG
value|4
comment|/* regular file */
define|#
directive|define
name|PAX_SLK
value|5
comment|/* symbolic link */
define|#
directive|define
name|PAX_SCK
value|6
comment|/* socket */
define|#
directive|define
name|PAX_FIF
value|7
comment|/* fifo */
define|#
directive|define
name|PAX_HLK
value|8
comment|/* hard link */
define|#
directive|define
name|PAX_HRG
value|9
comment|/* hard link to a regular file */
define|#
directive|define
name|PAX_CTG
value|10
comment|/* high performance file */
block|}
name|ARCHD
typedef|;
end_typedef

begin_comment
comment|/*  * Format Specific Options List  *  * Used to pass format options to the format options handler  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|oplist
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* option variable name e.g. name= */
name|char
modifier|*
name|value
decl_stmt|;
comment|/* value for option variable */
name|struct
name|oplist
modifier|*
name|fow
decl_stmt|;
comment|/* next option */
block|}
name|OPLIST
typedef|;
end_typedef

begin_comment
comment|/*  * General Macros  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAJOR
parameter_list|(
name|x
parameter_list|)
value|major(x)
end_define

begin_define
define|#
directive|define
name|MINOR
parameter_list|(
name|x
parameter_list|)
value|minor(x)
end_define

begin_define
define|#
directive|define
name|TODEV
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|makedev((x), (y))
end_define

begin_comment
comment|/*  * General Defines  */
end_comment

begin_define
define|#
directive|define
name|HEX
value|16
end_define

begin_define
define|#
directive|define
name|OCT
value|8
end_define

begin_define
define|#
directive|define
name|_PAX_
value|1
end_define

begin_define
define|#
directive|define
name|_TFILE_BASE
value|"paxXXXXXXXXXX"
end_define

end_unit

