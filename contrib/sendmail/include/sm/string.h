begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: string.h,v 1.36 2001/06/17 21:31:11 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm string manipulation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|SM_STRING_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* strlc{py,at}, strerror */
end_comment

begin_comment
comment|/* return number of bytes left in a buffer */
end_comment

begin_define
define|#
directive|define
name|SPACELEFT
parameter_list|(
name|buf
parameter_list|,
name|ptr
parameter_list|)
value|(sizeof buf - ((ptr) - buf))
end_define

begin_decl_stmt
specifier|extern
name|int
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
name|sm_snprintf
name|__P
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
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sm_match
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_str
operator|,
specifier|const
name|char
operator|*
name|_pattern
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_strdup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_strndup_x
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_str
operator|,
name|size_t
name|_len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for "normal" data (free'd before end of process) */
end_comment

begin_define
define|#
directive|define
name|sm_strdup_x
parameter_list|(
name|str
parameter_list|)
value|strcpy(sm_malloc_x(strlen(str) + 1), str)
end_define

begin_comment
comment|/* for data that is supposed to be persistent. */
end_comment

begin_define
define|#
directive|define
name|sm_pstrdup_x
parameter_list|(
name|str
parameter_list|)
value|strcpy(sm_pmalloc_x(strlen(str) + 1), str)
end_define

begin_define
define|#
directive|define
name|sm_strdup_tagged_x
parameter_list|(
name|str
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|group
parameter_list|)
define|\
value|strcpy(sm_malloc_tagged_x(strlen(str) + 1, file, line, group), str)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sm_stringf_x
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_fmt
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
name|sm_vstringf_x
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_fmt
operator|,
name|va_list
name|_ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|sm_strlcpy
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_dst
operator|,
specifier|const
name|char
operator|*
name|_src
operator|,
name|ssize_t
name|_len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|sm_strlcat
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_dst
operator|,
specifier|const
name|char
operator|*
name|_src
operator|,
name|ssize_t
name|_len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|sm_strlcat2
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|ssize_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|size_t
ifdef|#
directive|ifdef
name|__STDC__
name|sm_strlcpyn
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|ssize_t
name|len
parameter_list|,
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
name|sm_strlcpyn
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ssize_t
operator|,
name|int
operator|,
name|va_dcl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|HASSTRERROR
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|__P
argument_list|(
operator|(
name|int
name|_errno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HASSTRERROR */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sm_strrevcmp
name|__P
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
name|sm_strrevcasecmp
name|__P
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
name|sm_strcasecmp
name|__P
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
name|sm_strncasecmp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LONGLONG_T
name|sm_strtoll
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ULONGLONG_T
name|sm_strtoull
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stripquotes
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_STRING_H */
end_comment

end_unit

