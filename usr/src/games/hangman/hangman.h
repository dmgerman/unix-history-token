begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)hangman.h	5.4 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_define
define|#
directive|define
name|MINLEN
value|6
end_define

begin_define
define|#
directive|define
name|MAXERRS
value|7
end_define

begin_define
define|#
directive|define
name|MESGY
value|12
end_define

begin_define
define|#
directive|define
name|MESGX
value|0
end_define

begin_define
define|#
directive|define
name|PROMPTY
value|11
end_define

begin_define
define|#
directive|define
name|PROMPTX
value|0
end_define

begin_define
define|#
directive|define
name|KNOWNY
value|10
end_define

begin_define
define|#
directive|define
name|KNOWNX
value|1
end_define

begin_define
define|#
directive|define
name|NUMBERY
value|4
end_define

begin_define
define|#
directive|define
name|NUMBERX
value|(COLS - 1 - 26)
end_define

begin_define
define|#
directive|define
name|AVGY
value|5
end_define

begin_define
define|#
directive|define
name|AVGX
value|(COLS - 1 - 26)
end_define

begin_define
define|#
directive|define
name|GUESSY
value|2
end_define

begin_define
define|#
directive|define
name|GUESSX
value|(COLS - 1 - 26)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|y
decl_stmt|,
name|x
decl_stmt|;
name|char
name|ch
decl_stmt|;
block|}
name|ERR_POS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bool
name|Guessed
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Word
index|[]
decl_stmt|,
name|Known
index|[]
decl_stmt|,
modifier|*
name|Noose_pict
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Errors
decl_stmt|,
name|Wordnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|Average
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ERR_POS
name|Err_pos
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Dict
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|Dict_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|die
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|abs
parameter_list|()
function_decl|;
end_function_decl

end_unit

