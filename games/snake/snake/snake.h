begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)snake.h	8.1 (Berkeley) 5/31/93  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_struct
struct|struct
name|tbuffer
block|{
name|long
name|t
index|[
literal|4
index|]
decl_stmt|;
block|}
name|tbuffer
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|CL
decl_stmt|,
modifier|*
name|UP
decl_stmt|,
modifier|*
name|DO
decl_stmt|,
modifier|*
name|ND
decl_stmt|,
modifier|*
name|BS
decl_stmt|,
modifier|*
name|HO
decl_stmt|,
modifier|*
name|CM
decl_stmt|,
modifier|*
name|TA
decl_stmt|,
modifier|*
name|LL
decl_stmt|,
modifier|*
name|KL
decl_stmt|,
modifier|*
name|KR
decl_stmt|,
modifier|*
name|KU
decl_stmt|,
modifier|*
name|KD
decl_stmt|,
modifier|*
name|TI
decl_stmt|,
modifier|*
name|TE
decl_stmt|,
modifier|*
name|KS
decl_stmt|,
modifier|*
name|KE
decl_stmt|,
modifier|*
name|VI
decl_stmt|,
modifier|*
name|VE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LINES
decl_stmt|,
name|COLUMNS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical screen size. */
end_comment

begin_decl_stmt
name|int
name|lcnt
decl_stmt|,
name|ccnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's idea of screen size */
end_comment

begin_decl_stmt
name|char
name|xBC
decl_stmt|,
name|PC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AM
decl_stmt|,
name|BW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tbuf
index|[
literal|1024
index|]
decl_stmt|,
name|tcapbuf
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tgetstr
argument_list|()
decl_stmt|,
modifier|*
name|tgoto
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Klength
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of KX strings */
end_comment

begin_decl_stmt
name|int
name|chunk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount of money given at a time */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|debug
end_ifdef

begin_define
define|#
directive|define
name|cashvalue
value|(loot-penalty)/25
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cashvalue
value|chunk*(loot-penalty)/25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|point
block|{
name|int
name|col
decl_stmt|,
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|point
name|cursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|orig
decl_stmt|,
name|new
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCLGET
end_ifdef

begin_decl_stmt
name|struct
name|ltchars
name|olttyc
decl_stmt|,
name|nlttyc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|point
modifier|*
name|point
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|void
name|apr
parameter_list|(
name|struct
name|point
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pr
parameter_list|(
specifier|const
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
name|apr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|same
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((s1)->line == (s2)->line&& (s1)->col == (s2)->col)
end_define

end_unit

