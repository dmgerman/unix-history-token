begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hangman.h	8.1 (Berkeley) 5/31/93  *	$FreeBSD$  */
end_comment

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
file|<unistd.h>
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
name|void
name|die
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endgame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getguess
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getword
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|playgame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prdata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prman
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prword
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|readch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

