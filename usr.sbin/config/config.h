begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Config.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_struct
struct|struct
name|file_list
block|{
name|struct
name|file_list
modifier|*
name|f_next
decl_stmt|;
name|char
modifier|*
name|f_fn
decl_stmt|;
comment|/* the name */
name|int
name|f_type
decl_stmt|;
comment|/* type or count */
name|u_char
name|f_flags
decl_stmt|;
comment|/* see below */
name|char
modifier|*
name|f_compilewith
decl_stmt|;
comment|/* special make rule if present */
name|char
modifier|*
name|f_depends
decl_stmt|;
comment|/* additional dependancies */
name|char
modifier|*
name|f_clean
decl_stmt|;
comment|/* File list to add to clean rule */
name|char
modifier|*
name|f_needs
decl_stmt|;
name|char
modifier|*
name|f_warn
decl_stmt|;
comment|/* warning message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types.  */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|INVISIBLE
value|2
end_define

begin_define
define|#
directive|define
name|PROFILING
value|3
end_define

begin_define
define|#
directive|define
name|NODEPEND
value|4
end_define

begin_define
define|#
directive|define
name|LOCAL
value|5
end_define

begin_define
define|#
directive|define
name|DEVDONE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TYPEMASK
value|0x7fffffff
end_define

begin_comment
comment|/*  * Attributes (flags).  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLCT_RULE
value|1
end_define

begin_define
define|#
directive|define
name|NO_OBJ
value|2
end_define

begin_define
define|#
directive|define
name|BEFORE_DEPEND
value|4
end_define

begin_define
define|#
directive|define
name|NEED_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|ISDUP
value|16
end_define

begin_define
define|#
directive|define
name|NOWERROR
value|32
end_define

begin_struct
struct|struct
name|device
block|{
name|int
name|d_done
decl_stmt|;
comment|/* processed */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* name of device (e.g. rk11) */
name|int
name|d_count
decl_stmt|;
comment|/* device count */
define|#
directive|define
name|UNKNOWN
value|-2
comment|/* -2 means not set yet */
name|struct
name|device
modifier|*
name|d_next
decl_stmt|;
comment|/* Next one in list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config
block|{
name|char
modifier|*
name|s_sysname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Config has a global notion of which machine type is  * being used.  It uses the name of the machine in choosing  * files and directories.  Thus if the name of the machine is ``i386'',  * it will build from ``Makefile.i386'' and use ``../i386/inline''  * in the makerules, etc.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|machinename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * For each machine, a set of CPU's may be specified as supported.  * These and the options (below) are put in the C flags in the makefile.  */
end_comment

begin_struct
struct|struct
name|cputype
block|{
name|char
modifier|*
name|cpu_name
decl_stmt|;
name|struct
name|cputype
modifier|*
name|cpu_next
decl_stmt|;
block|}
modifier|*
name|cputype
struct|;
end_struct

begin_comment
comment|/*  * A set of options may also be specified which are like CPU types,  * but which may also specify values for the options.  * A separate set of options may be defined for make-style options.  */
end_comment

begin_struct
struct|struct
name|opt
block|{
name|char
modifier|*
name|op_name
decl_stmt|;
name|char
modifier|*
name|op_value
decl_stmt|;
name|int
name|op_ownfile
decl_stmt|;
comment|/* true = own file, false = makefile */
name|struct
name|opt
modifier|*
name|op_next
decl_stmt|;
block|}
modifier|*
name|opt
struct|,
modifier|*
name|mkopt
struct|;
end_struct

begin_struct
struct|struct
name|opt_list
block|{
name|char
modifier|*
name|o_name
decl_stmt|;
name|char
modifier|*
name|o_file
decl_stmt|;
name|struct
name|opt_list
modifier|*
name|o_next
decl_stmt|;
block|}
modifier|*
name|otab
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hints
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_trace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|envmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hintmode
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|get_word
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_quoted_word
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|raisestr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remember
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|moveifchanged
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makefile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|headers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|device
modifier|*
name|dtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|errbuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|yyfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|file_list
modifier|*
name|ftab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PREFIX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Config file name - for error messages */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|srcdir
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root of the kernel source tree */
end_comment

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!strcmp(a,b))
end_define

begin_define
define|#
directive|define
name|ns
parameter_list|(
name|s
parameter_list|)
value|strdup(s)
end_define

end_unit

