begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *      The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gprof_h
end_ifndef

begin_define
define|#
directive|define
name|gprof_h
end_define

begin_comment
comment|/* Include the BFD sysdep.h file.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* Undefine the BFD PACKAGE and VERSION macros before including the    gprof config.h file.  */
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE
end_undef

begin_undef
undef|#
directive|undef
name|VERSION
end_undef

begin_include
include|#
directive|include
file|"gconfig.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX defines hz as a macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|hz
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|A_OUTNAME
value|"a.out"
end_define

begin_comment
comment|/* default core filename */
end_comment

begin_define
define|#
directive|define
name|GMONNAME
value|"gmon.out"
end_define

begin_comment
comment|/* default profile filename */
end_comment

begin_define
define|#
directive|define
name|GMONSUM
value|"gmon.sum"
end_define

begin_comment
comment|/* profile summary filename */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_comment
comment|/* Undefine BFD's `_' macro - it uses dgetext() and we want to use gettext().  */
end_comment

begin_undef
undef|#
directive|undef
name|_
end_undef

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STYLE_FLAT_PROFILE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|STYLE_CALL_GRAPH
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|STYLE_SUMMARY_FILE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|STYLE_EXEC_COUNTS
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|STYLE_ANNOTATED_SOURCE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|STYLE_GMON_INFO
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|STYLE_FUNCTION_ORDER
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|STYLE_FILE_ORDER
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|ANYDEBUG
value|(1<<0)
end_define

begin_comment
comment|/*    1 */
end_comment

begin_define
define|#
directive|define
name|DFNDEBUG
value|(1<<1)
end_define

begin_comment
comment|/*    2 */
end_comment

begin_define
define|#
directive|define
name|CYCLEDEBUG
value|(1<<2)
end_define

begin_comment
comment|/*    4 */
end_comment

begin_define
define|#
directive|define
name|ARCDEBUG
value|(1<<3)
end_define

begin_comment
comment|/*    8 */
end_comment

begin_define
define|#
directive|define
name|TALLYDEBUG
value|(1<<4)
end_define

begin_comment
comment|/*   16 */
end_comment

begin_define
define|#
directive|define
name|TIMEDEBUG
value|(1<<5)
end_define

begin_comment
comment|/*   32 */
end_comment

begin_define
define|#
directive|define
name|SAMPLEDEBUG
value|(1<<6)
end_define

begin_comment
comment|/*   64 */
end_comment

begin_define
define|#
directive|define
name|AOUTDEBUG
value|(1<<7)
end_define

begin_comment
comment|/*  128 */
end_comment

begin_define
define|#
directive|define
name|CALLDEBUG
value|(1<<8)
end_define

begin_comment
comment|/*  256 */
end_comment

begin_define
define|#
directive|define
name|LOOKUPDEBUG
value|(1<<9)
end_define

begin_comment
comment|/*  512 */
end_comment

begin_define
define|#
directive|define
name|PROPDEBUG
value|(1<<10)
end_define

begin_comment
comment|/* 1024 */
end_comment

begin_define
define|#
directive|define
name|BBDEBUG
value|(1<<11)
end_define

begin_comment
comment|/* 2048 */
end_comment

begin_define
define|#
directive|define
name|IDDEBUG
value|(1<<12)
end_define

begin_comment
comment|/* 4096 */
end_comment

begin_define
define|#
directive|define
name|SRCDEBUG
value|(1<<13)
end_define

begin_comment
comment|/* 8192 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|l
parameter_list|,
name|s
parameter_list|)
value|if (debug_level& (l)) {s;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|l
parameter_list|,
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|FF_AUTO
init|=
literal|0
block|,
name|FF_MAGIC
block|,
name|FF_BSD
block|,
name|FF_BSD44
block|,
name|FF_PROF
block|}
name|File_Format
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UNIT
index|[
literal|2
index|]
typedef|;
end_typedef

begin_comment
comment|/* unit of profiling */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|whoami
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command-name, for error messages */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|function_mapping_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file mapping functions to files */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|a_out_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* core filename */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ticks per second */
end_comment

begin_comment
comment|/*  * Command-line options:  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|output_style
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|output_width
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controls column width in index */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|bsd_style_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as opposed to FSF style output */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|demangle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* demangle symbol names? */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|ignore_direct_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't count direct calls */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|ignore_static_funcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress static functions */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|ignore_zeros
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore unused symbols/files */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|line_granularity
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function or line granularity? */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|print_descriptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output profile description */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|print_path
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print path or just filename? */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|ignore_non_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ignore non-function symbols.  */
end_comment

begin_decl_stmt
specifier|extern
name|File_Format
name|file_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* requested file format */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|first_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no output so far? */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|done
argument_list|(
name|int
name|status
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gprof_h */
end_comment

end_unit

