begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Peter McIlroy.  *  * %sccs.include.redist.c%  *  *	@(#)sort.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|NBINS
value|256
end_define

begin_define
define|#
directive|define
name|MAXMERGE
value|16
end_define

begin_comment
comment|/* values for masks, weights, and other flags. */
end_comment

begin_define
define|#
directive|define
name|I
value|1
end_define

begin_comment
comment|/* mask out non-printable characters */
end_comment

begin_define
define|#
directive|define
name|D
value|2
end_define

begin_comment
comment|/* sort alphanumeric characters only */
end_comment

begin_define
define|#
directive|define
name|N
value|4
end_define

begin_comment
comment|/* Field is a number */
end_comment

begin_define
define|#
directive|define
name|F
value|8
end_define

begin_comment
comment|/* weight lower and upper case the same */
end_comment

begin_define
define|#
directive|define
name|R
value|16
end_define

begin_comment
comment|/* Field is reversed with respect to the global weight */
end_comment

begin_define
define|#
directive|define
name|BI
value|32
end_define

begin_comment
comment|/* ignore blanks in icol */
end_comment

begin_define
define|#
directive|define
name|BT
value|64
end_define

begin_comment
comment|/* ignore blanks in tcol */
end_comment

begin_comment
comment|/* masks for delimiters: blanks, fields, and termination. */
end_comment

begin_define
define|#
directive|define
name|BLANK
value|1
end_define

begin_comment
comment|/* ' ', '\t'; '\n' if -T is invoked */
end_comment

begin_define
define|#
directive|define
name|FLD_D
value|2
end_define

begin_comment
comment|/* ' ', '\t' default; from -t otherwise */
end_comment

begin_define
define|#
directive|define
name|REC_D_F
value|4
end_define

begin_comment
comment|/* '\n' default; from -T otherwise */
end_comment

begin_define
define|#
directive|define
name|ND
value|10
end_define

begin_comment
comment|/* limit on number of -k options. */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|FCLOSE
parameter_list|(
name|file
parameter_list|)
value|{							\ 	if (EOF == fclose(file))					\ 		err(2, "%s", file);					\ }
end_define

begin_define
define|#
directive|define
name|EWRITE
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|{					\ 	if (!fwrite(ptr, size, n, f))					\ 		 err(2, NULL);						\ }
end_define

begin_comment
comment|/* length of record is currently limited to 2^16 - 1 */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|length_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SALIGN
parameter_list|(
name|n
parameter_list|)
value|((n+1)& ~1)
end_define

begin_comment
comment|/* a record is a key/line pair starting at rec.data. It has a total length  * and an offset to the start of the line half of the pair.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|recheader
block|{
name|length_t
name|length
decl_stmt|;
name|length_t
name|offset
decl_stmt|;
name|u_char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|RECHEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|trecheader
block|{
name|length_t
name|length
decl_stmt|;
name|length_t
name|offset
decl_stmt|;
block|}
name|TRECHEADER
typedef|;
end_typedef

begin_comment
comment|/* This is the column as seen by struct field.  It is used by enterfield.  * They are matched with corresponding coldescs during initialization.  */
end_comment

begin_struct
struct|struct
name|column
block|{
name|struct
name|coldesc
modifier|*
name|p
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|indent
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* a coldesc has a number and pointers to the beginning and end of the  * corresponding column in the current line.  This is determined in enterkey.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coldesc
block|{
name|u_char
modifier|*
name|start
decl_stmt|;
name|u_char
modifier|*
name|end
decl_stmt|;
name|int
name|num
decl_stmt|;
block|}
name|COLDESC
typedef|;
end_typedef

begin_comment
comment|/* A field has an initial and final column; an omitted final column  * implies the end of the line.  Flags regulate omission of blanks and  * numerical sorts; mask determines which characters are ignored (from -i, -d);  * weights determines the sort weights of a character (from -f, -r).  */
end_comment

begin_struct
struct|struct
name|field
block|{
name|struct
name|column
name|icol
decl_stmt|;
name|struct
name|column
name|tcol
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_char
modifier|*
name|mask
decl_stmt|;
name|u_char
modifier|*
name|weights
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|f_handle
block|{
name|int
name|top
decl_stmt|;
name|char
modifier|*
modifier|*
name|names
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|int
name|PANIC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum depth of fsort before fmerge is called */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|ascii
index|[
name|NBINS
index|]
decl_stmt|,
name|Rascii
index|[
name|NBINS
index|]
decl_stmt|,
name|Ftable
index|[
name|NBINS
index|]
decl_stmt|,
name|RFtable
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|alltable
index|[
name|NBINS
index|]
decl_stmt|,
name|dtable
index|[
name|NBINS
index|]
decl_stmt|,
name|itable
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|d_mask
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SINGL_FLD
decl_stmt|,
name|SEP_FLAG
decl_stmt|,
name|UNIQUE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|REC_D
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

