begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/tw.h,v 3.25 2006/01/12 18:15:25 christos Exp $ */
end_comment

begin_comment
comment|/*  * tw.h: TwENEX functions headers  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_tw
end_ifndef

begin_define
define|#
directive|define
name|_h_tw
end_define

begin_define
define|#
directive|define
name|TW_PATH
value|0x1000
end_define

begin_define
define|#
directive|define
name|TW_ZERO
value|0x0fff
end_define

begin_define
define|#
directive|define
name|TW_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|TW_COMMAND
value|0x0001
end_define

begin_define
define|#
directive|define
name|TW_VARIABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|TW_LOGNAME
value|0x0003
end_define

begin_define
define|#
directive|define
name|TW_FILE
value|0x0004
end_define

begin_define
define|#
directive|define
name|TW_DIRECTORY
value|0x0005
end_define

begin_define
define|#
directive|define
name|TW_VARLIST
value|0x0006
end_define

begin_define
define|#
directive|define
name|TW_USER
value|0x0007
end_define

begin_define
define|#
directive|define
name|TW_COMPLETION
value|0x0008
end_define

begin_define
define|#
directive|define
name|TW_ALIAS
value|0x0009
end_define

begin_define
define|#
directive|define
name|TW_SHELLVAR
value|0x000a
end_define

begin_define
define|#
directive|define
name|TW_ENVVAR
value|0x000b
end_define

begin_define
define|#
directive|define
name|TW_BINDING
value|0x000c
end_define

begin_define
define|#
directive|define
name|TW_WORDLIST
value|0x000d
end_define

begin_define
define|#
directive|define
name|TW_LIMIT
value|0x000e
end_define

begin_define
define|#
directive|define
name|TW_SIGNAL
value|0x000f
end_define

begin_define
define|#
directive|define
name|TW_JOB
value|0x0010
end_define

begin_define
define|#
directive|define
name|TW_EXPLAIN
value|0x0011
end_define

begin_define
define|#
directive|define
name|TW_TEXT
value|0x0012
end_define

begin_define
define|#
directive|define
name|TW_GRPNAME
value|0x0013
end_define

begin_define
define|#
directive|define
name|TW_EXEC_CHK
value|0x01
end_define

begin_define
define|#
directive|define
name|TW_DIR_CHK
value|0x02
end_define

begin_define
define|#
directive|define
name|TW_TEXT_CHK
value|0x04
end_define

begin_define
define|#
directive|define
name|TW_DIR_OK
value|0x10
end_define

begin_define
define|#
directive|define
name|TW_PAT_OK
value|0x20
end_define

begin_define
define|#
directive|define
name|TW_IGN_OK
value|0x40
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ESC
value|CTL_ESC('\033')
end_define

begin_define
define|#
directive|define
name|is_set
parameter_list|(
name|var
parameter_list|)
value|adrof(var)
end_define

begin_define
define|#
directive|define
name|ismetahash
parameter_list|(
name|a
parameter_list|)
value|(ismeta(a)&& (a) != '#')
end_define

begin_define
define|#
directive|define
name|SEARCHLIST
value|"HPATH"
end_define

begin_comment
comment|/* Env. param for helpfile searchlist */
end_comment

begin_define
define|#
directive|define
name|DEFAULTLIST
value|":/usr/man/cat1:/usr/man/cat8:/usr/man/cat6:/usr/local/man/cat1:/usr/local/man/cat8:/usr/local/man/cat6"
end_define

begin_comment
comment|/* if no HPATH */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LIST
block|,
name|LIST_ALL
block|,
name|RECOGNIZE
block|,
name|RECOGNIZE_ALL
block|,
name|RECOGNIZE_SCROLL
block|,
name|PRINT_HELP
block|,
name|SPELL
block|,
name|GLOB
block|,
name|GLOB_EXPAND
block|,
name|VARS_EXPAND
block|,
name|PATH_NORMALIZE
block|,
name|COMMAND_NORMALIZE
block|}
name|COMMAND
typedef|;
end_typedef

begin_struct
struct|struct
name|scroll_tab_list
block|{
name|Char
modifier|*
name|element
decl_stmt|;
name|struct
name|scroll_tab_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|scroll_tab_list
modifier|*
name|scroll_tab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curchoice
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|non_unique_match
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|match_unique_match
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|InsideCompletion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|varent
name|completions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|color_context_ls
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"tw.decls.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_tw */
end_comment

end_unit

