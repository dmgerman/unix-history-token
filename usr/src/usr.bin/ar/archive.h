begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  *	@(#)archive.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Ar(1) options. */
end_comment

begin_define
define|#
directive|define
name|AR_A
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_B
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_C
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_D
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_M
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_O
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_P
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_Q
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_R
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_T
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_U
value|0x0400
end_define

begin_define
define|#
directive|define
name|AR_V
value|0x0800
end_define

begin_define
define|#
directive|define
name|AR_X
value|0x1000
end_define

begin_decl_stmt
specifier|extern
name|u_int
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up file copy. */
end_comment

begin_define
define|#
directive|define
name|SETCF
parameter_list|(
name|from
parameter_list|,
name|fromname
parameter_list|,
name|to
parameter_list|,
name|toname
parameter_list|,
name|pad
parameter_list|)
value|{ \ 	cf.rfd = from; \ 	cf.rname = fromname; \ 	cf.wfd = to; \ 	cf.wname = toname; \ 	cf.flags = pad; \ }
end_define

begin_comment
comment|/* File copy structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rfd
decl_stmt|;
comment|/* read file descriptor */
name|char
modifier|*
name|rname
decl_stmt|;
comment|/* read name */
name|int
name|wfd
decl_stmt|;
comment|/* write file descriptor */
name|char
modifier|*
name|wname
decl_stmt|;
comment|/* write name */
define|#
directive|define
name|RPAD
value|0x01
comment|/* pad on reads */
define|#
directive|define
name|WPAD
value|0x02
comment|/* pad on writes */
name|u_int
name|flags
decl_stmt|;
comment|/* pad flags */
block|}
name|CF
typedef|;
end_typedef

begin_comment
comment|/* Header structure internal format. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|date
decl_stmt|;
comment|/* date */
name|long
name|size
decl_stmt|;
comment|/* size in bytes */
name|int
name|gid
decl_stmt|;
comment|/* group */
name|int
name|lname
decl_stmt|;
comment|/* if long name */
name|int
name|uid
decl_stmt|;
comment|/* owner */
name|u_short
name|mode
decl_stmt|;
comment|/* permissions */
name|char
name|name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name */
block|}
name|CHDR
typedef|;
end_typedef

begin_comment
comment|/* Seek over the module contents; always rounds. */
end_comment

begin_define
define|#
directive|define
name|SKIP
parameter_list|(
name|fd
parameter_list|,
name|size
parameter_list|,
name|name
parameter_list|)
value|{ \ 	if (lseek((fd), ((size) + ((size)& 1)), SEEK_CUR) == (off_t)-1) \ 		error(name); \ }
end_define

begin_comment
comment|/* Print out any files that weren't in the archive. */
end_comment

begin_define
define|#
directive|define
name|ORPHANS
value|{ \ 	if (*argv) { \ 		eval = 1; \ 		do { \ 			(void)fprintf(stderr, \ 			    "ar: %s: not found in archive.\n", *argv); \ 		} while (*++argv); \ 	} \ }
end_define

begin_comment
comment|/* Header format strings. */
end_comment

begin_define
define|#
directive|define
name|HDR1
value|"%s%-13d%-12ld%-6u%-6u%-8o%-10ld%2s"
end_define

begin_define
define|#
directive|define
name|HDR2
value|"%-16s%-12ld%-6u%-6u%-8o%-10ld%2s"
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

end_unit

