begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** mawk.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*   $Log: mawk.h,v $  * Revision 1.2  1992/06/02  05:07:35  rich  * Ported to 386bsd.  Changes from vax BSD4.3 include usage of  * fmod in libm.a, usage of void pointers, and usage of vfprintf  * in libc.a.  Floating point exceptions are not raised when  * they should be, which causes the last fpe test to fail.  *  * Revision 5.4  92/03/03  16:34:41  brennan  * conditional around open() proto  *   * Revision 5.3  92/01/09  08:46:58  brennan  * cell destroy macro  *   * Revision 5.2  92/01/06  08:08:56  brennan  * binmode() proto for MSDOS  *   * Revision 5.1  91/12/05  07:59:26  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  mawk.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAWK_H
end_ifndef

begin_define
define|#
directive|define
name|MAWK_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print parse if on */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dump_RE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|dump_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|posix_space_flag
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_comment
comment|/*----------------  *  GLOBAL VARIABLES  *----------------*/
end_comment

begin_comment
comment|/* a well known string */
end_comment

begin_decl_stmt
specifier|extern
name|STRING
name|null_str
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TEMPBUFF_GOES_HERE
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* a useful scratch area */
end_comment

begin_macro
name|EXTERN
end_macro

begin_union
union|union
block|{
name|STRING
modifier|*
name|_split_buff
index|[
name|MAX_SPLIT
index|]
decl_stmt|;
name|char
name|_string_buff
index|[
name|MIN_SPRINTF
index|]
decl_stmt|;
block|}
name|tempbuff
union|;
end_union

begin_comment
comment|/* anonymous union */
end_comment

begin_define
define|#
directive|define
name|string_buff
value|tempbuff._string_buff
end_define

begin_define
define|#
directive|define
name|split_buff
value|tempbuff._split_buff
end_define

begin_define
define|#
directive|define
name|SPRINTF_SZ
value|sizeof(tempbuff)
end_define

begin_comment
comment|/* help with casts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pow2
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these are used by the parser, scanner and error messages     from the compile  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pfile_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program input file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_token
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|token_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lineno of current token */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|compile_error_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paren_cnt
decl_stmt|,
name|brace_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_flag
decl_stmt|,
name|getline_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|mawk_state
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EXECUTION
value|1
end_define

begin_comment
comment|/* other state is 0 compiling */
end_comment

begin_comment
comment|/*---------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS_MSC
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for error messages */
end_comment

begin_comment
comment|/* macro to test the type of two adjacent cells */
end_comment

begin_define
define|#
directive|define
name|TEST2
parameter_list|(
name|cp
parameter_list|)
value|(pow2[(cp)->type]+pow2[((cp)+1)->type])
end_define

begin_comment
comment|/* macro to get at the string part of a CELL */
end_comment

begin_define
define|#
directive|define
name|string
parameter_list|(
name|cp
parameter_list|)
value|((STRING *)(cp)->ptr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|cell_destroy
parameter_list|(
name|cp
parameter_list|)
value|DB_cell_destroy(cp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cell_destroy
parameter_list|(
name|cp
parameter_list|)
value|if ( (cp)->type>= C_STRING&&\                            -- string(cp)->ref_cnt == 0 )\                         zfree(string(cp),string(cp)->len+STRING_OH);else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  prototypes  */
end_comment

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast1_to_s
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast1_to_d
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast2_to_s
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast2_to_d
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast_to_RE
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast_for_split
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|check_strnum
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|cast_to_REPL
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|test
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* test for null non-null */
end_comment

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|cellcpy
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|repl_cpy
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|DB_cell_destroy
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|overflow
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|rt_overflow
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|rt_error
argument_list|,
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|mawk_exit
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|da
argument_list|,
operator|(
name|INST
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|str_str
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|rm_escape
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|re_split
argument_list|,
operator|(
name|char
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|re_pos_match
argument_list|,
operator|(
name|char
operator|*
operator|,
name|PTR
operator|,
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|binmode
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|exit
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|THINK_C
end_ifdef

begin_include
include|#
directive|include
file|<unix.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|close
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ANSI compilers won't like open() if they've ever seen open as    int open(char *,int, ...).  If so remove it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBMR2
end_ifndef

begin_comment
comment|/* AIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__386BSD__
end_ifndef

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|open
argument_list|,
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|read
argument_list|,
operator|(
name|int
operator|,
name|PTR
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|parse
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|yylex
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|yyparse
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|yyerror
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|bozo
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|errmsg
argument_list|,
operator|(
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|compile_error
argument_list|,
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|execute
argument_list|,
operator|(
name|INST
operator|*
operator|,
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|find_kw_str
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|HAVE_STDLIB_H
end_if

begin_function_decl
name|double
name|strtod
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|double
name|fmod
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAWK_H */
end_comment

end_unit

