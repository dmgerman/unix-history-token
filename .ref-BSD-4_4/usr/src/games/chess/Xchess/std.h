begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file contains code for X-CHESS.    Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of X-CHESS.  X-CHESS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the X-CHESS General Public License for full details.  Everyone is granted permission to copy, modify and redistribute X-CHESS, but only under the conditions described in the X-CHESS General Public License.   A copy of this license is supposed to have been given to you along with X-CHESS so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* RCS Info: $Revision: 1.2 $ on $Date: 86/11/23 17:18:32 $  *		   $Source: /users/faustus/xchess/RCS/std.h,v $  * Copyright (c) 1986 Wayne A. Christopher, U. C. Berkeley CAD Group  *  * Standard definitions.  */
end_comment

begin_define
define|#
directive|define
name|UNIX
end_define

begin_define
define|#
directive|define
name|BSD
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FILE
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isalpha
end_ifndef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE
end_ifndef

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_comment
comment|/* Externs defined in std.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|trealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|datestring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getusername
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gethome
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gettok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tildexpand
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

begin_function_decl
specifier|extern
name|void
name|setenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|appendc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scannum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|seconds
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|prefix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|ciprefix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cieq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|substring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Externs from libc */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should use BSIZE instead of BUFSIZ... */
end_comment

begin_define
define|#
directive|define
name|BSIZE
value|512
end_define

begin_comment
comment|/* Some standard macros. */
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
value|(!strcmp((a), (b)))
end_define

begin_define
define|#
directive|define
name|isalphanum
parameter_list|(
name|c
parameter_list|)
value|(isalpha(c) || isdigit(c))
end_define

begin_define
define|#
directive|define
name|alloc
parameter_list|(
name|strname
parameter_list|)
value|((struct strname *) tmalloc(sizeof(struct strname)))
end_define

begin_define
define|#
directive|define
name|tfree
parameter_list|(
name|ptr
parameter_list|)
value|{ if (ptr) free((char *) ptr); ptr = 0; }
end_define

begin_define
define|#
directive|define
name|hexnum
parameter_list|(
name|c
parameter_list|)
value|((((c)>= '0')&& ((c)<= '9')) ? ((c) - '0') : ((((c)>= \ 		'a')&& ((c)<= 'f')) ? ((c) - 'a' + 10) : ((((c)>= 'A')&& \ 		((c)<= 'F')) ? ((c) - 'A' + 10) : 0)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_define
define|#
directive|define
name|srandom
value|srand
end_define

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|EXIT_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_BAD
value|0
end_define

begin_else
else|#
directive|else
else|VMS
end_else

begin_define
define|#
directive|define
name|EXIT_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_BAD
value|1
end_define

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

end_unit

