begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * awk.h -- Definitions for gawk.   */
end_comment

begin_comment
comment|/*   * Copyright (C) 1986, 1988, 1989, 1991, 1992, 1993 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Progamming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with GAWK; see the file COPYING.  If not, write to  * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* ------------------------------ Includes ------------------------------ */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LIMITS_H_MISSING
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|errno
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_include
include|#
directive|include
file|<signum.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ----------------- System dependencies (with more includes) -----------*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<floatingpoint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|VAXC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DECC
argument_list|)
operator|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VMS w/ VAXC or DECC */
end_comment

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_include
include|#
directive|include
file|<stat.h>
end_include

begin_include
include|#
directive|include
file|<file.h>
end_include

begin_comment
comment|/* avoid<fcntl.h> in io.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_define
define|#
directive|define
name|MALLOC_ARG_T
value|size_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|MALLOC_ARG_T
value|unsigned
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIZE_T_MISSING
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SZTC
end_ifndef

begin_define
define|#
directive|define
name|SZTC
end_define

begin_define
define|#
directive|define
name|INTC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_undef
undef|#
directive|undef
name|atof
end_undef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|atarist
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unixlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* atarist || VMS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atarist || VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Next */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STDC_HEADERS */
end_comment

begin_include
include|#
directive|include
file|"protos.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDC_HEADERS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Ultrix41
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|atof
name|P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_comment
comment|/* nasty nasty SunOS-ism */
end_comment

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sparc */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|alloca
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ALLOCA_PROTO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNDERSCORE_SETJMP
end_ifdef

begin_comment
comment|/* nasty nasty berkelixm */
end_comment

begin_define
define|#
directive|define
name|setjmp
value|_setjmp
end_define

begin_define
define|#
directive|define
name|longjmp
value|_longjmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * if you don't have vprintf, try this and cross your fingers.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VPRINTF_MISSING
argument_list|)
end_if

begin_define
define|#
directive|define
name|vfprintf
parameter_list|(
name|fp
parameter_list|,
name|fmt
parameter_list|,
name|arg
parameter_list|)
value|_doprnt((fmt), (arg), (fp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* some macros to redirect to code in vms/vms_misc.c */
end_comment

begin_define
define|#
directive|define
name|exit
value|vms_exit
end_define

begin_define
define|#
directive|define
name|open
value|vms_open
end_define

begin_define
define|#
directive|define
name|strerror
value|vms_strerror
end_define

begin_define
define|#
directive|define
name|strdup
value|vms_strdup
end_define

begin_decl_stmt
specifier|extern
name|void
name|exit
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|open
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vms_devopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TTY_FWRITE
end_ifndef

begin_define
define|#
directive|define
name|fwrite
value|tty_fwrite
end_define

begin_define
define|#
directive|define
name|fclose
value|tty_fclose
end_define

begin_decl_stmt
specifier|extern
name|size_t
name|fwrite
name|P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fclose
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|popen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pclose
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vms_arg_fixup
name|P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* some things not in STDC_HEADERS */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|gnu_strftime
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|tm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|unlink
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getopt
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isatty
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|fileno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|fileno
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|close
argument_list|()
decl_stmt|,
name|dup
argument_list|()
decl_stmt|,
name|dup2
argument_list|()
decl_stmt|,
name|fstat
argument_list|()
decl_stmt|,
name|read
argument_list|()
decl_stmt|,
name|stat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getpgrp
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*VMS*/
end_comment

begin_define
define|#
directive|define
name|GNU_REGEX
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GNU_REGEX
end_ifdef

begin_include
include|#
directive|include
file|"regex.h"
end_include

begin_include
include|#
directive|include
file|"dfa.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|Regexp
block|{
name|struct
name|re_pattern_buffer
name|pat
decl_stmt|;
name|struct
name|re_registers
name|regs
decl_stmt|;
name|struct
name|dfa
name|dfareg
decl_stmt|;
name|int
name|dfa
decl_stmt|;
block|}
name|Regexp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RESTART
parameter_list|(
name|rp
parameter_list|,
name|s
parameter_list|)
value|(rp)->regs.start[0]
end_define

begin_define
define|#
directive|define
name|REEND
parameter_list|(
name|rp
parameter_list|,
name|s
parameter_list|)
value|(rp)->regs.end[0]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GNU_REGEX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU_REGEX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|atarist
end_ifdef

begin_define
define|#
directive|define
name|read
value|_text_read
end_define

begin_comment
comment|/* we do not want all these CR's to mess our input */
end_comment

begin_function_decl
specifier|extern
name|int
name|_text_read
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__MINT__
end_ifndef

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINT__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEFPATH
end_ifndef

begin_define
define|#
directive|define
name|DEFPATH
value|".:/usr/local/lib/awk:/usr/lib/awk"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENVSEP
end_ifndef

begin_define
define|#
directive|define
name|ENVSEP
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|double
name|double_to_int
name|P
argument_list|(
operator|(
name|double
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------ Constants, Structures, Typedefs  ------------------ */
end_comment

begin_define
define|#
directive|define
name|AWKNUM
value|double
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* illegal entry == 0 */
name|Node_illegal
block|,
comment|/* binary operators  lnode and rnode are the expressions to work on */
name|Node_times
block|,
name|Node_quotient
block|,
name|Node_mod
block|,
name|Node_plus
block|,
name|Node_minus
block|,
name|Node_cond_pair
block|,
comment|/* conditional pair (see Node_line_range) */
name|Node_subscript
block|,
name|Node_concat
block|,
name|Node_exp
block|,
comment|/* unary operators   subnode is the expression to work on */
comment|/*10*/
name|Node_preincrement
block|,
name|Node_predecrement
block|,
name|Node_postincrement
block|,
name|Node_postdecrement
block|,
name|Node_unary_minus
block|,
name|Node_field_spec
block|,
comment|/* assignments   lnode is the var to assign to, rnode is the exp */
name|Node_assign
block|,
name|Node_assign_times
block|,
name|Node_assign_quotient
block|,
name|Node_assign_mod
block|,
comment|/*20*/
name|Node_assign_plus
block|,
name|Node_assign_minus
block|,
name|Node_assign_exp
block|,
comment|/* boolean binaries   lnode and rnode are expressions */
name|Node_and
block|,
name|Node_or
block|,
comment|/* binary relationals   compares lnode and rnode */
name|Node_equal
block|,
name|Node_notequal
block|,
name|Node_less
block|,
name|Node_greater
block|,
name|Node_leq
block|,
comment|/*30*/
name|Node_geq
block|,
name|Node_match
block|,
name|Node_nomatch
block|,
comment|/* unary relationals   works on subnode */
name|Node_not
block|,
comment|/* program structures */
name|Node_rule_list
block|,
comment|/* lnode is a rule, rnode is rest of list */
name|Node_rule_node
block|,
comment|/* lnode is pattern, rnode is statement */
name|Node_statement_list
block|,
comment|/* lnode is statement, rnode is more list */
name|Node_if_branches
block|,
comment|/* lnode is to run on true, rnode on false */
name|Node_expression_list
block|,
comment|/* lnode is an exp, rnode is more list */
name|Node_param_list
block|,
comment|/* lnode is a variable, rnode is more list */
comment|/* keywords */
comment|/*40*/
name|Node_K_if
block|,
comment|/* lnode is conditonal, rnode is if_branches */
name|Node_K_while
block|,
comment|/* lnode is condtional, rnode is stuff to run */
name|Node_K_for
block|,
comment|/* lnode is for_struct, rnode is stuff to run */
name|Node_K_arrayfor
block|,
comment|/* lnode is for_struct, rnode is stuff to run */
name|Node_K_break
block|,
comment|/* no subs */
name|Node_K_continue
block|,
comment|/* no stuff */
name|Node_K_print
block|,
comment|/* lnode is exp_list, rnode is redirect */
name|Node_K_printf
block|,
comment|/* lnode is exp_list, rnode is redirect */
name|Node_K_next
block|,
comment|/* no subs */
name|Node_K_exit
block|,
comment|/* subnode is return value, or NULL */
comment|/*50*/
name|Node_K_do
block|,
comment|/* lnode is conditional, rnode stuff to run */
name|Node_K_return
block|,
name|Node_K_delete
block|,
name|Node_K_getline
block|,
name|Node_K_function
block|,
comment|/* lnode is statement list, rnode is params */
comment|/* I/O redirection for print statements */
name|Node_redirect_output
block|,
comment|/* subnode is where to redirect */
name|Node_redirect_append
block|,
comment|/* subnode is where to redirect */
name|Node_redirect_pipe
block|,
comment|/* subnode is where to redirect */
name|Node_redirect_pipein
block|,
comment|/* subnode is where to redirect */
name|Node_redirect_input
block|,
comment|/* subnode is where to redirect */
comment|/* Variables */
comment|/*60*/
name|Node_var
block|,
comment|/* rnode is value, lnode is array stuff */
name|Node_var_array
block|,
comment|/* array is ptr to elements, asize num of 				 * eles */
name|Node_val
block|,
comment|/* node is a value - type in flags */
comment|/* Builtins   subnode is explist to work on, proc is func to call */
name|Node_builtin
block|,
comment|/* 	 * pattern: conditional ',' conditional ;  lnode of Node_line_range 	 * is the two conditionals (Node_cond_pair), other word (rnode place) 	 * is a flag indicating whether or not this range has been entered. 	 */
name|Node_line_range
block|,
comment|/* 	 * boolean test of membership in array lnode is string-valued 	 * expression rnode is array name  	 */
name|Node_in_array
block|,
name|Node_func
block|,
comment|/* lnode is param. list, rnode is body */
name|Node_func_call
block|,
comment|/* lnode is name, rnode is argument list */
name|Node_cond_exp
block|,
comment|/* lnode is conditonal, rnode is if_branches */
name|Node_regex
block|,
comment|/*70*/
name|Node_hashnode
block|,
name|Node_ahash
block|,
name|Node_NF
block|,
name|Node_NR
block|,
name|Node_FNR
block|,
name|Node_FS
block|,
name|Node_RS
block|,
name|Node_FIELDWIDTHS
block|,
name|Node_IGNORECASE
block|,
name|Node_OFS
block|,
name|Node_ORS
block|,
name|Node_OFMT
block|,
name|Node_CONVFMT
block|,
name|Node_K_nextfile
block|}
name|NODETYPE
typedef|;
end_typedef

begin_comment
comment|/*  * NOTE - this struct is a rather kludgey -- it is packed to minimize  * space usage, at the expense of cleanliness.  Alter at own risk.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|exp_node
block|{
union|union
block|{
struct|struct
block|{
union|union
block|{
name|struct
name|exp_node
modifier|*
name|lptr
decl_stmt|;
name|char
modifier|*
name|param_name
decl_stmt|;
name|long
name|ll
decl_stmt|;
block|}
name|l
union|;
union|union
block|{
name|struct
name|exp_node
modifier|*
name|rptr
decl_stmt|;
name|struct
name|exp_node
modifier|*
function_decl|(
modifier|*
name|pptr
function_decl|)
parameter_list|()
function_decl|;
name|Regexp
modifier|*
name|preg
decl_stmt|;
name|struct
name|for_loop_header
modifier|*
name|hd
decl_stmt|;
name|struct
name|exp_node
modifier|*
modifier|*
name|av
decl_stmt|;
name|int
name|r_ent
decl_stmt|;
comment|/* range entered */
block|}
name|r
union|;
union|union
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|exp_node
modifier|*
name|extra
decl_stmt|;
name|long
name|xl
decl_stmt|;
block|}
name|x
union|;
name|short
name|number
decl_stmt|;
name|unsigned
name|char
name|reflags
decl_stmt|;
define|#
directive|define
name|CASE
value|1
define|#
directive|define
name|CONST
value|2
define|#
directive|define
name|FS_DFLT
value|4
block|}
name|nodep
struct|;
struct|struct
block|{
name|AWKNUM
name|fltnum
decl_stmt|;
comment|/* this is here for optimal packing of 					 * the structure on many machines 					 */
name|char
modifier|*
name|sp
decl_stmt|;
name|size_t
name|slen
decl_stmt|;
name|unsigned
name|char
name|sref
decl_stmt|;
name|char
name|idx
decl_stmt|;
block|}
name|val
struct|;
struct|struct
block|{
name|struct
name|exp_node
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|length
decl_stmt|;
name|struct
name|exp_node
modifier|*
name|value
decl_stmt|;
block|}
name|hash
struct|;
define|#
directive|define
name|hnext
value|sub.hash.next
define|#
directive|define
name|hname
value|sub.hash.name
define|#
directive|define
name|hlength
value|sub.hash.length
define|#
directive|define
name|hvalue
value|sub.hash.value
struct|struct
block|{
name|struct
name|exp_node
modifier|*
name|next
decl_stmt|;
name|struct
name|exp_node
modifier|*
name|name
decl_stmt|;
name|struct
name|exp_node
modifier|*
name|value
decl_stmt|;
block|}
name|ahash
struct|;
define|#
directive|define
name|ahnext
value|sub.ahash.next
define|#
directive|define
name|ahname
value|sub.ahash.name
define|#
directive|define
name|ahvalue
value|sub.ahash.value
block|}
name|sub
union|;
name|NODETYPE
name|type
decl_stmt|;
name|unsigned
name|short
name|flags
decl_stmt|;
define|#
directive|define
name|MALLOC
value|1
comment|/* can be free'd */
define|#
directive|define
name|TEMP
value|2
comment|/* should be free'd */
define|#
directive|define
name|PERM
value|4
comment|/* can't be free'd */
define|#
directive|define
name|STRING
value|8
comment|/* assigned as string */
define|#
directive|define
name|STR
value|16
comment|/* string value is current */
define|#
directive|define
name|NUM
value|32
comment|/* numeric value is current */
define|#
directive|define
name|NUMBER
value|64
comment|/* assigned as number */
define|#
directive|define
name|MAYBE_NUM
value|128
comment|/* user input:  if NUMERIC then 						 * a NUMBER */
define|#
directive|define
name|ARRAYMAXED
value|256
comment|/* array is at max size */
name|char
modifier|*
name|vname
decl_stmt|;
comment|/* variable's name */
block|}
name|NODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lnode
value|sub.nodep.l.lptr
end_define

begin_define
define|#
directive|define
name|nextp
value|sub.nodep.l.lptr
end_define

begin_define
define|#
directive|define
name|rnode
value|sub.nodep.r.rptr
end_define

begin_define
define|#
directive|define
name|source_file
value|sub.nodep.x.name
end_define

begin_define
define|#
directive|define
name|source_line
value|sub.nodep.number
end_define

begin_define
define|#
directive|define
name|param_cnt
value|sub.nodep.number
end_define

begin_define
define|#
directive|define
name|param
value|sub.nodep.l.param_name
end_define

begin_define
define|#
directive|define
name|subnode
value|lnode
end_define

begin_define
define|#
directive|define
name|proc
value|sub.nodep.r.pptr
end_define

begin_define
define|#
directive|define
name|re_reg
value|sub.nodep.r.preg
end_define

begin_define
define|#
directive|define
name|re_flags
value|sub.nodep.reflags
end_define

begin_define
define|#
directive|define
name|re_text
value|lnode
end_define

begin_define
define|#
directive|define
name|re_exp
value|sub.nodep.x.extra
end_define

begin_define
define|#
directive|define
name|re_cnt
value|sub.nodep.number
end_define

begin_define
define|#
directive|define
name|forsub
value|lnode
end_define

begin_define
define|#
directive|define
name|forloop
value|rnode->sub.nodep.r.hd
end_define

begin_define
define|#
directive|define
name|stptr
value|sub.val.sp
end_define

begin_define
define|#
directive|define
name|stlen
value|sub.val.slen
end_define

begin_define
define|#
directive|define
name|stref
value|sub.val.sref
end_define

begin_define
define|#
directive|define
name|stfmt
value|sub.val.idx
end_define

begin_define
define|#
directive|define
name|numbr
value|sub.val.fltnum
end_define

begin_define
define|#
directive|define
name|var_value
value|lnode
end_define

begin_define
define|#
directive|define
name|var_array
value|sub.nodep.r.av
end_define

begin_define
define|#
directive|define
name|array_size
value|sub.nodep.l.ll
end_define

begin_define
define|#
directive|define
name|table_size
value|sub.nodep.x.xl
end_define

begin_define
define|#
directive|define
name|condpair
value|lnode
end_define

begin_define
define|#
directive|define
name|triggered
value|sub.nodep.r.r_ent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_decl_stmt
name|int
name|primes
index|[]
init|=
block|{
literal|31
block|,
literal|61
block|,
literal|127
block|,
literal|257
block|,
literal|509
block|,
literal|1021
block|,
literal|2053
block|,
literal|4099
block|,
literal|8191
block|,
literal|16381
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|for_loop_header
block|{
name|NODE
modifier|*
name|init
decl_stmt|;
name|NODE
modifier|*
name|cond
decl_stmt|;
name|NODE
modifier|*
name|incr
decl_stmt|;
block|}
name|FOR_LOOP_HEADER
typedef|;
end_typedef

begin_comment
comment|/* for "for(iggy in foo) {" */
end_comment

begin_struct
struct|struct
name|search
block|{
name|NODE
modifier|*
name|sym
decl_stmt|;
name|size_t
name|idx
decl_stmt|;
name|NODE
modifier|*
name|bucket
decl_stmt|;
name|NODE
modifier|*
name|retval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for faster input, bypass stdio */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|iobuf
block|{
name|int
name|fd
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|char
modifier|*
name|off
decl_stmt|;
name|char
modifier|*
name|end
decl_stmt|;
name|size_t
name|size
decl_stmt|;
comment|/* this will be determined by an fstat() call */
name|int
name|cnt
decl_stmt|;
name|long
name|secsiz
decl_stmt|;
name|int
name|flag
decl_stmt|;
define|#
directive|define
name|IOP_IS_TTY
value|1
define|#
directive|define
name|IOP_IS_INTERNAL
value|2
define|#
directive|define
name|IOP_NO_FREE
value|4
block|}
name|IOBUF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Func_ptr
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/*  * structure used to dynamically maintain a linked-list of open files/pipes  */
end_comment

begin_struct
struct|struct
name|redirect
block|{
name|unsigned
name|int
name|flag
decl_stmt|;
define|#
directive|define
name|RED_FILE
value|1
define|#
directive|define
name|RED_PIPE
value|2
define|#
directive|define
name|RED_READ
value|4
define|#
directive|define
name|RED_WRITE
value|8
define|#
directive|define
name|RED_APPEND
value|16
define|#
directive|define
name|RED_NOBUF
value|32
define|#
directive|define
name|RED_USED
value|64
define|#
directive|define
name|RED_EOF
value|128
name|char
modifier|*
name|value
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|IOBUF
modifier|*
name|iop
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
name|status
decl_stmt|;
name|struct
name|redirect
modifier|*
name|prev
decl_stmt|;
name|struct
name|redirect
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure for our source, either a command line string or a source file */
end_comment

begin_struct
struct|struct
name|src
block|{
enum|enum
name|srctype
block|{
name|CMDLINE
init|=
literal|1
block|,
name|SOURCEFILE
block|}
name|stype
enum|;
name|char
modifier|*
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* longjmp return codes, must be nonzero */
end_comment

begin_comment
comment|/* Continue means either for loop/while continue, or next input record */
end_comment

begin_define
define|#
directive|define
name|TAG_CONTINUE
value|1
end_define

begin_comment
comment|/* Break means either for/while break, or stop reading input */
end_comment

begin_define
define|#
directive|define
name|TAG_BREAK
value|2
end_define

begin_comment
comment|/* Return means return from a function call; leave value in ret_node */
end_comment

begin_define
define|#
directive|define
name|TAG_RETURN
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|(~(1<< (sizeof (int) * 8 - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|(~(1<< (sizeof (long) * 8 - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|(~(unsigned long)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MIN
end_ifndef

begin_define
define|#
directive|define
name|LONG_MIN
value|(-LONG_MAX - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HUGE
value|INT_MAX
end_define

begin_comment
comment|/* -------------------------- External variables -------------------------- */
end_comment

begin_comment
comment|/* gawk builtin variables */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|NF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|NR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|FNR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|IGNORECASE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|OFS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|OFSlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ORS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ORSlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|OFMT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CONVFMT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|CONVFMTidx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|OFMTidx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|FS_node
decl_stmt|,
modifier|*
name|NF_node
decl_stmt|,
modifier|*
name|RS_node
decl_stmt|,
modifier|*
name|NR_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|FILENAME_node
decl_stmt|,
modifier|*
name|OFS_node
decl_stmt|,
modifier|*
name|ORS_node
decl_stmt|,
modifier|*
name|OFMT_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|CONVFMT_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|FNR_node
decl_stmt|,
modifier|*
name|RLENGTH_node
decl_stmt|,
modifier|*
name|RSTART_node
decl_stmt|,
modifier|*
name|SUBSEP_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|IGNORECASE_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|FIELDWIDTHS_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
modifier|*
name|stack_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|Nnull_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
modifier|*
name|fields_arr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sourceline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|source
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|expression_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|_t
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used as temporary in tree_eval */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|nextfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|field0_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_unix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_posix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_lint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_begin_rule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_end_rule
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------- Pseudo-functions ------------------------- */
end_comment

begin_define
define|#
directive|define
name|is_identchar
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c) || (c) == '_')
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MPROF
end_ifndef

begin_define
define|#
directive|define
name|getnode
parameter_list|(
name|n
parameter_list|)
value|if (nextfree) n = nextfree, nextfree = nextfree->nextp;\ 			else n = more_nodes()
end_define

begin_define
define|#
directive|define
name|freenode
parameter_list|(
name|n
parameter_list|)
value|((n)->nextp = nextfree, nextfree = (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|getnode
parameter_list|(
name|n
parameter_list|)
value|emalloc(n, NODE *, sizeof(NODE), "getnode")
end_define

begin_define
define|#
directive|define
name|freenode
parameter_list|(
name|n
parameter_list|)
value|free(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|tree_eval
parameter_list|(
name|t
parameter_list|)
value|r_tree_eval(t)
end_define

begin_define
define|#
directive|define
name|get_lhs
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|r_get_lhs((p), (a))
end_define

begin_undef
undef|#
directive|undef
name|freenode
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|get_lhs
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|((p)->type == Node_var ? (&(p)->var_value) : \ 			r_get_lhs((p), (a)))
end_define

begin_define
define|#
directive|define
name|tree_eval
parameter_list|(
name|t
parameter_list|)
value|(_t = (t),_t == NULL ? Nnull_string : \ 			(_t->type == Node_param_list ? r_tree_eval(_t) : \ 			(_t->type == Node_val ? _t : \ 			(_t->type == Node_var ? _t->var_value : \ 			r_tree_eval(_t)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|make_number
parameter_list|(
name|x
parameter_list|)
value|mk_number((x), (unsigned int)(MALLOC|NUM|NUMBER))
end_define

begin_define
define|#
directive|define
name|tmp_number
parameter_list|(
name|x
parameter_list|)
value|mk_number((x), (unsigned int)(MALLOC|TEMP|NUM|NUMBER))
end_define

begin_define
define|#
directive|define
name|free_temp
parameter_list|(
name|n
parameter_list|)
value|do {if ((n)->flags&TEMP) { unref(n); }} while (0)
end_define

begin_define
define|#
directive|define
name|make_string
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|make_str_node((s), SZTC (l),0)
end_define

begin_define
define|#
directive|define
name|SCAN
value|1
end_define

begin_define
define|#
directive|define
name|ALREADY_MALLOCED
value|2
end_define

begin_define
define|#
directive|define
name|cant_happen
parameter_list|()
value|fatal("internal error line %d, file: %s", \ 				__LINE__, __FILE__);
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_TOKEN_PASTING
argument_list|)
end_if

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|var
parameter_list|,
name|ty
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|(void)((var=(ty)malloc((MALLOC_ARG_T)(x))) ||\ 				 (fatal("%s: %s: can't allocate memory (%s)",\ 					(str), #var, strerror(errno)),0))
end_define

begin_define
define|#
directive|define
name|erealloc
parameter_list|(
name|var
parameter_list|,
name|ty
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|(void)((var=(ty)realloc((char *)var,\ 						  (MALLOC_ARG_T)(x))) ||\ 				 (fatal("%s: %s: can't allocate memory (%s)",\ 					(str), #var, strerror(errno)),0))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|var
parameter_list|,
name|ty
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|(void)((var=(ty)malloc((MALLOC_ARG_T)(x))) ||\ 				 (fatal("%s: %s: can't allocate memory (%s)",\ 					(str), "var", strerror(errno)),0))
end_define

begin_define
define|#
directive|define
name|erealloc
parameter_list|(
name|var
parameter_list|,
name|ty
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|(void)((var=(ty)realloc((char *)var,\ 						  (MALLOC_ARG_T)(x))) ||\ 				 (fatal("%s: %s: can't allocate memory (%s)",\ 					(str), "var", strerror(errno)),0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|force_number
value|r_force_number
end_define

begin_define
define|#
directive|define
name|force_string
value|r_force_string
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_function_decl
specifier|extern
name|AWKNUM
name|force_number
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_decl_stmt
specifier|extern
name|double
name|_msc51bug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|force_number
parameter_list|(
name|n
parameter_list|)
value|(_msc51bug=(_t = (n),(_t->flags& NUM) ? _t->numbr : r_force_number(_t)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MSDOS */
end_comment

begin_define
define|#
directive|define
name|force_number
parameter_list|(
name|n
parameter_list|)
value|(_t = (n),(_t->flags& NUM) ? _t->numbr : r_force_number(_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|force_string
parameter_list|(
name|s
parameter_list|)
value|(_t = (s),(_t->flags& STR) ? _t : r_force_string(_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG */
end_comment

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(a) == *(b)&& strcmp((a), (b)) == 0)
end_define

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|((n)&& *(a)== *(b)&& strncmp((a), (b), SZTC (n)) == 0)
end_define

begin_comment
comment|/* ------------- Function prototypes or defs (as appropriate) ------------- */
end_comment

begin_comment
comment|/* array.c */
end_comment

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|concat_exp
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assoc_clear
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|symbol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|hash
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s
operator|,
name|size_t
name|len
operator|,
name|unsigned
name|long
name|hsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_array
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|symbol
operator|,
name|NODE
operator|*
name|subs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
modifier|*
name|assoc_lookup
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|symbol
operator|,
name|NODE
operator|*
name|subs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_delete
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|symbol
operator|,
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assoc_scan
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|symbol
operator|,
expr|struct
name|search
operator|*
name|lookat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assoc_next
name|P
argument_list|(
operator|(
expr|struct
name|search
operator|*
name|lookat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* awk.tab.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tokexpand
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|nextc
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|node
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|left
operator|,
name|NODETYPE
name|op
operator|,
name|NODE
operator|*
name|right
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|install
name|P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|NODE
operator|*
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|lookup
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|variable
name|P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|can_free
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyparse
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* builtin.c */
end_comment

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_exp
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_index
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_int
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_length
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_log
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_sprintf
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_printf
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_simple
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|,
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_sqrt
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_substr
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_strftime
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_systime
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_system
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_print
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_tolower
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_toupper
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_atan2
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_sin
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_cos
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_rand
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_srand
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_match
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_gsub
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_sub
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eval.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interpret
name|P
argument_list|(
operator|(
name|NODE
operator|*
specifier|volatile
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|r_tree_eval
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cmp_nodes
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|t1
operator|,
name|NODE
operator|*
name|t2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
modifier|*
name|r_get_lhs
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|ptr
operator|,
name|Func_ptr
operator|*
name|assign
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_IGNORECASE
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_OFS
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_ORS
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_OFMT
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_CONVFMT
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* field.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_fields
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_record
name|P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|cnt
operator|,
name|int
name|freeold
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reset_record
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_NF
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
modifier|*
name|get_field
name|P
argument_list|(
operator|(
name|int
name|num
operator|,
name|Func_ptr
operator|*
name|assign
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_split
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_FS
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_RS
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_FIELDWIDTHS
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* io.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_FNR
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_NR
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_input
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|redirect
modifier|*
name|redirect
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|,
name|int
operator|*
name|errflg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_close
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flush_io
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|close_io
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|devopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pathopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|do_getline
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|do_nextfile
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* iop.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optimal_bufsize
name|P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|IOBUF
modifier|*
name|iop_alloc
name|P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_a_record
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|out
operator|,
name|IOBUF
operator|*
name|iop
operator|,
name|int
name|rs
operator|,
name|int
operator|*
name|errcode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
decl|main
name|P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Regexp
modifier|*
name|mk_re_parse
name|P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|int
name|ignorecase
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|load_environ
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|arg_assign
name|P
argument_list|(
operator|(
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SIGTYPE
name|catchsig
name|P
argument_list|(
operator|(
name|int
name|sig
operator|,
name|int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* msg.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|err
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s
operator|,
specifier|const
name|char
operator|*
name|emsg
operator|,
name|va_list
name|argp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|_MSC_VER
operator|==
literal|510
end_if

begin_decl_stmt
specifier|extern
name|void
name|msg
name|P
argument_list|(
operator|(
name|va_list
name|va_alist
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warning
name|P
argument_list|(
operator|(
name|va_list
name|va_alist
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fatal
name|P
argument_list|(
operator|(
name|va_list
name|va_alist
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|msg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warning
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* node.c */
end_comment

begin_decl_stmt
specifier|extern
name|AWKNUM
name|r_force_number
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|r_force_string
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|dupnode
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|mk_number
name|P
argument_list|(
operator|(
name|AWKNUM
name|x
operator|,
name|unsigned
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|make_str_node
name|P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|size_t
name|len
operator|,
name|int
name|scan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|tmp_string
name|P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|more_nodes
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|freenode
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|it
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|unref
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|tmp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_escape
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|string_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* re.c */
end_comment

begin_decl_stmt
specifier|extern
name|Regexp
modifier|*
name|make_regexp
name|P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|size_t
name|len
operator|,
name|int
name|ignorecase
operator|,
name|int
name|dfa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|research
name|P
argument_list|(
operator|(
name|Regexp
operator|*
name|rp
operator|,
name|char
operator|*
name|str
operator|,
name|int
name|start
operator|,
name|size_t
name|len
operator|,
name|int
name|need_start
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refree
name|P
argument_list|(
operator|(
name|Regexp
operator|*
name|rp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reg_error
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Regexp
modifier|*
name|re_update
name|P
argument_list|(
operator|(
name|NODE
operator|*
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resyntax
name|P
argument_list|(
operator|(
name|int
name|syntax
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resetup
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strcase.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strcasecmp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s1
operator|,
specifier|const
name|char
operator|*
name|s2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strncasecmp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|s1
operator|,
specifier|const
name|char
operator|*
name|s2
operator|,
specifier|register
name|size_t
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|atarist
end_ifdef

begin_comment
comment|/* atari/tmpnam.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpnam
name|P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempnam
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|path
operator|,
specifier|const
name|char
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Figure out what '\a' really is. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|BELL
value|'\a'
end_define

begin_comment
comment|/* sure makes life easy, don't it? */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
literal|'z'
operator|-
literal|'a'
operator|==
literal|25
end_if

begin_comment
comment|/* ascii */
end_comment

begin_if
if|#
directive|if
literal|'a'
operator|!=
literal|97
end_if

begin_comment
comment|/* machine is dumb enough to use mark parity */
end_comment

begin_define
define|#
directive|define
name|BELL
value|'\207'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BELL
value|'\07'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BELL
value|'\057'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|casetable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for case-independent regexp matching */
end_comment

end_unit

