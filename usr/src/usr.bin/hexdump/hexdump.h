begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)hexdump.h	5.4 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pr
block|{
name|struct
name|_pr
modifier|*
name|nextpr
decl_stmt|;
comment|/* next print unit */
define|#
directive|define
name|F_ADDRESS
value|0x001
comment|/* print offset */
define|#
directive|define
name|F_BPAD
value|0x002
comment|/* blank pad */
define|#
directive|define
name|F_C
value|0x004
comment|/* %_c */
define|#
directive|define
name|F_CHAR
value|0x008
comment|/* %c */
define|#
directive|define
name|F_DBL
value|0x010
comment|/* %[EefGf] */
define|#
directive|define
name|F_INT
value|0x020
comment|/* %[di] */
define|#
directive|define
name|F_P
value|0x040
comment|/* %_p */
define|#
directive|define
name|F_STR
value|0x080
comment|/* %s */
define|#
directive|define
name|F_U
value|0x100
comment|/* %_u */
define|#
directive|define
name|F_UINT
value|0x200
comment|/* %[ouXx] */
define|#
directive|define
name|F_TEXT
value|0x400
comment|/* no conversions */
name|u_int
name|flags
decl_stmt|;
comment|/* flag values */
name|int
name|bcnt
decl_stmt|;
comment|/* byte count */
name|char
modifier|*
name|cchar
decl_stmt|;
comment|/* conversion character */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* printf format */
name|char
modifier|*
name|nospace
decl_stmt|;
comment|/* no whitespace version */
block|}
name|PR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_fu
block|{
name|struct
name|_fu
modifier|*
name|nextfu
decl_stmt|;
comment|/* next format unit */
name|struct
name|_pr
modifier|*
name|nextpr
decl_stmt|;
comment|/* next print unit */
define|#
directive|define
name|F_IGNORE
value|0x01
comment|/* %_A */
define|#
directive|define
name|F_SETREP
value|0x02
comment|/* rep count set, not default */
name|u_int
name|flags
decl_stmt|;
comment|/* flag values */
name|int
name|reps
decl_stmt|;
comment|/* repetition count */
name|int
name|bcnt
decl_stmt|;
comment|/* byte count */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* format string */
block|}
name|FU
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_fs
block|{
comment|/* format strings */
name|struct
name|_fs
modifier|*
name|nextfs
decl_stmt|;
comment|/* linked list of format strings */
name|struct
name|_fu
modifier|*
name|nextfu
decl_stmt|;
comment|/* linked list of format units */
name|int
name|bcnt
decl_stmt|;
block|}
name|FS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FS
modifier|*
name|fshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of format strings list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data block size */
end_comment

begin_enum
enum|enum
name|_vflag
block|{
name|ALL
block|,
name|DUP
block|,
name|FIRST
block|,
name|WAIT
block|}
enum|;
end_enum

begin_comment
comment|/* -v values */
end_comment

begin_function_decl
name|char
modifier|*
name|emalloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

