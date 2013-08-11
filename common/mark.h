begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)mark.h	10.3 (Berkeley) 3/6/96  */
end_comment

begin_comment
comment|/*  * The MARK and LMARK structures define positions in the file.  There are  * two structures because the mark subroutines are the only places where  * anything cares about something other than line and column.  *  * Because of the different interfaces used by the db(3) package, curses,  * and users, the line number is 1 based and the column number is 0 based.  * Additionally, it is known that the out-of-band line number is less than  * any legal line number.  The line number is of type recno_t, as that's  * the underlying type of the database.  The column number is of type size_t,  * guaranteeing that we can malloc a line.  */
end_comment

begin_struct
struct|struct
name|_mark
block|{
define|#
directive|define
name|OOBLNO
value|0
comment|/* Out-of-band line number. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Column number. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_lmark
block|{
name|LIST_ENTRY
argument_list|(
argument|_lmark
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of marks. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Column number. */
name|CHAR_T
name|name
decl_stmt|;
comment|/* Mark name. */
define|#
directive|define
name|MARK_DELETED
value|0x01
comment|/* Mark was deleted. */
define|#
directive|define
name|MARK_USERSET
value|0x02
comment|/* User set this mark. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ABSMARK1
value|'\''
end_define

begin_comment
comment|/* Absolute mark name. */
end_comment

begin_define
define|#
directive|define
name|ABSMARK2
value|'`'
end_define

begin_comment
comment|/* Absolute mark name. */
end_comment

end_unit

