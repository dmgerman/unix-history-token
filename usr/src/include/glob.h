begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Guido van Rossum.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)glob.h	5.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|gl_pathc
decl_stmt|;
comment|/* count of paths matching pattern */
name|int
name|gl_offs
decl_stmt|;
comment|/* reserved at beginning of gl_pathv */
name|int
name|gl_flags
decl_stmt|;
comment|/* copy of flags parameter to glob() */
name|int
function_decl|(
modifier|*
name|gl_errfunc
function_decl|)
parameter_list|()
function_decl|;
comment|/* copy of errfunc parameter to glob() */
name|char
modifier|*
modifier|*
name|gl_pathv
decl_stmt|;
comment|/* list of paths matching pattern */
block|}
name|glob_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GLOB_ERR
value|0x01
end_define

begin_comment
comment|/* return on error */
end_comment

begin_define
define|#
directive|define
name|GLOB_MARK
value|0x02
end_define

begin_comment
comment|/* append / to matching directories */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSORT
value|0x04
end_define

begin_comment
comment|/* don't sort */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOCHECK
value|0x08
end_define

begin_comment
comment|/* return pattern itself if nothing matches */
end_comment

begin_define
define|#
directive|define
name|GLOB_DOOFFS
value|0x10
end_define

begin_comment
comment|/* use gl_offs */
end_comment

begin_define
define|#
directive|define
name|GLOB_APPEND
value|0x20
end_define

begin_comment
comment|/* append to output from previous call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|GLOB_QUOTE
value|0x40
end_define

begin_comment
comment|/* quote special chars with \ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLOB_NOSPACE
value|(-1)
end_define

begin_comment
comment|/* malloc call failed */
end_comment

begin_define
define|#
directive|define
name|GLOB_ABEND
value|(-2)
end_define

begin_comment
comment|/* unignored error */
end_comment

begin_function_decl
name|void
name|globfree
parameter_list|()
function_decl|;
end_function_decl

end_unit

