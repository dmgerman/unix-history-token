begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ps.h	5.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|UNLIMITED
value|0
end_define

begin_comment
comment|/* unlimited terminal width */
end_comment

begin_enum
enum|enum
name|type
block|{
name|CHAR
block|,
name|UCHAR
block|,
name|SHORT
block|,
name|USHORT
block|,
name|LONG
block|,
name|ULONG
block|,
name|KPTR
block|}
enum|;
end_enum

begin_struct
struct|struct
name|usave
block|{
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
name|struct
name|timeval
name|u_start
decl_stmt|;
name|struct
name|rusage
name|u_ru
decl_stmt|;
name|struct
name|rusage
name|u_cru
decl_stmt|;
name|char
name|u_acflag
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_kinfo
block|{
name|struct
name|proc
modifier|*
name|ki_p
decl_stmt|;
comment|/* proc structure */
name|struct
name|eproc
modifier|*
name|ki_e
decl_stmt|;
comment|/* extra stuff */
name|struct
name|usave
modifier|*
name|ki_u
decl_stmt|;
comment|/* interesting parts of user */
name|char
modifier|*
name|ki_args
decl_stmt|;
comment|/* exec args (should be char **) */
name|char
modifier|*
name|ki_env
decl_stmt|;
comment|/* environment (should be char **) */
block|}
name|KINFO
typedef|;
end_typedef

begin_comment
comment|/* Variables. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_var
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name(s) of variable */
name|char
modifier|*
name|header
decl_stmt|;
comment|/* default header */
name|char
modifier|*
name|alias
decl_stmt|;
comment|/* aliases */
define|#
directive|define
name|COMM
value|0x01
comment|/* needs exec arguments and environment (XXX) */
define|#
directive|define
name|LJUST
value|0x02
comment|/* left adjust on output (trailing blanks) */
define|#
directive|define
name|USER
value|0x04
comment|/* needs user structure */
name|u_int
name|flag
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* output routine */
name|short
name|width
decl_stmt|;
comment|/* printing width */
comment|/* 	 * The following (optional) elements are hooks for passing information 	 * to the generic output routines: pvar, evar, uvar (those which print 	 * simple elements from well known structures: proc, eproc, usave) 	 */
name|int
name|off
decl_stmt|;
comment|/* offset in structure */
name|enum
name|type
name|type
decl_stmt|;
comment|/* type of element */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* printf format */
name|char
modifier|*
name|time
decl_stmt|;
comment|/* time format */
comment|/* 	 * glue to link selected fields together 	 */
block|}
name|VAR
typedef|;
end_typedef

begin_struct
struct|struct
name|varent
block|{
name|VAR
modifier|*
name|var
decl_stmt|;
name|struct
name|varent
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

