begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/hyperion/mu/christos/src/sys/tcsh-6.01/RCS/tw.h,v 3.2 1991/12/14 20:45:46 christos Exp $ */
end_comment

begin_comment
comment|/*  * tw.h: TwENEX functions headers  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|BSDSIGS
end_ifdef

begin_define
define|#
directive|define
name|FREE_ITEMS
parameter_list|(
name|items
parameter_list|,
name|num
parameter_list|)
define|\
value|{\     sigmask_t omask;\     omask = sighold (SIGINT);\     free_items (items,num);\     items = NULL;\     (void) sigsetmask(omask);\ }
end_define

begin_define
define|#
directive|define
name|FREE_DIR
parameter_list|(
name|fd
parameter_list|)
define|\
value|{\     sigmask_t omask;\     omask = sighold (SIGINT);\     (void) closedir (fd);\     fd = NULL;\     (void) sigsetmask(omask);\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE_ITEMS
parameter_list|(
name|items
parameter_list|,
name|num
parameter_list|)
define|\
value|{\     sighold (SIGINT);\     free_items (items,num);\     items = NULL;\     (void) sigrelse (SIGINT);\ }
end_define

begin_define
define|#
directive|define
name|FREE_DIR
parameter_list|(
name|fd
parameter_list|)
define|\
value|{\     sighold (SIGINT);\     (void) closedir (fd);\     fd = NULL;\     (void) sigrelse (SIGINT);\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|FILSIZ
value|512
end_define

begin_comment
comment|/* Max reasonable file name length */
end_comment

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a, b) == 0)
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
name|BUILTINS
value|"/usr/local/lib/builtins/"
end_define

begin_comment
comment|/* fake builtin bin */
end_comment

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

begin_decl_stmt
specifier|extern
name|Char
name|PromptBuf
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|LIST
block|,
name|RECOGNIZE
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
block|}
name|COMMAND
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUMCMDS_START
value|512
end_define

begin_comment
comment|/* was 800 */
end_comment

begin_define
define|#
directive|define
name|NUMCMDS_INCR
value|256
end_define

begin_define
define|#
directive|define
name|ITEMS_START
value|512
end_define

begin_define
define|#
directive|define
name|ITEMS_INCR
value|256
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_EXTERN
end_ifndef

begin_decl_stmt
specifier|extern
name|Char
modifier|*
modifier|*
name|command_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the pre-digested list of commands for speed 				 * and general usefullness */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numcommands
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|have_sorted
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
name|Char
name|dirflag
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ' nn\0' - dir #s -  . 1 2 ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

