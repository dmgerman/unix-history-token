begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2006 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                        2006                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: hashed_db.h,v 1.5 2006/08/19 15:58:34 tom Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASHED_DB_H
end_ifndef

begin_define
define|#
directive|define
name|HASHED_DB_H
value|1
end_define

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_if
if|#
directive|if
name|USE_HASHED_DB
end_if

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DBN_SUFFIX
end_ifndef

begin_define
define|#
directive|define
name|DBM_SUFFIX
value|".db"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DB_VERSION_MAJOR
end_ifdef

begin_define
define|#
directive|define
name|HASHED_DB_API
value|DB_VERSION_MAJOR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HASHED_DB_API
value|1
end_define

begin_comment
comment|/* e.g., db 1.8.5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern NCURSES_EXPORT(DB *
end_extern

begin_expr_stmt
unit|)
name|_nc_db_open
argument_list|(
specifier|const
name|char
operator|*
comment|/* path */
argument_list|,
name|bool
comment|/* modify */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_db_have_data
argument_list|(
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|,
name|char
operator|*
operator|*
comment|/* buffer */
argument_list|,
name|int
operator|*
comment|/* size */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_db_have_index
argument_list|(
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|,
name|char
operator|*
operator|*
comment|/* buffer */
argument_list|,
name|int
operator|*
comment|/* size */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_db_close
argument_list|(
name|DB
operator|*
comment|/* db */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_db_first
argument_list|(
name|DB
operator|*
comment|/* db */
argument_list|,
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_db_next
argument_list|(
name|DB
operator|*
comment|/* db */
argument_list|,
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_db_get
argument_list|(
name|DB
operator|*
comment|/* db */
argument_list|,
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_db_put
argument_list|(
name|DB
operator|*
comment|/* db */
argument_list|,
name|DBT
operator|*
comment|/* key */
argument_list|,
name|DBT
operator|*
comment|/* data */
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASHED_DB_H */
end_comment

end_unit

