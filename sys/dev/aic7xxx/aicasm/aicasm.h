begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Assembler for the sequencer program downloaded to Aic7xxx SCSI host adapters  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: //depot/src/aic7xxx/aicasm/aicasm.h#5 $  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|"../queue.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

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

begin_typedef
typedef|typedef
struct|struct
name|path_entry
block|{
name|char
modifier|*
name|directory
decl_stmt|;
name|int
name|quoted_includes_only
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|path_entry
argument_list|)
name|links
expr_stmt|;
block|}
typedef|*
name|path_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|QUOTED_INCLUDE
block|,
name|BRACKETED_INCLUDE
block|,
name|SOURCE_FILE
block|}
name|include_type
typedef|;
end_typedef

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|path_list
argument_list|,
name|path_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|path_list
name|search_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cs_tailq
name|cs_tailq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|scope_list
name|scope_stack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symlist
name|patch_functions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|includes_search_curdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* False if we've seen -I- */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|appname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|yyfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|versions
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|stop
parameter_list|(
specifier|const
name|char
modifier|*
name|errstring
parameter_list|,
name|int
name|err_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|include_file
parameter_list|(
name|char
modifier|*
name|file_name
parameter_list|,
name|include_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|instruction
modifier|*
name|seq_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|critical_section
modifier|*
name|cs_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|scope
modifier|*
name|scope_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_scope
parameter_list|(
name|struct
name|scope
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

