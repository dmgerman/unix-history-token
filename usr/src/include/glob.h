begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Guido van Rossum.  *  * %sccs.include.redist.c%  *  *	@(#)glob.h	5.5 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|gl_pathc
decl_stmt|;
comment|/* count of total paths so far */
name|int
name|gl_matchc
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
name|GLOB_APPEND
value|0x01
end_define

begin_comment
comment|/* append to output from previous call */
end_comment

begin_define
define|#
directive|define
name|GLOB_DOOFFS
value|0x02
end_define

begin_comment
comment|/* use gl_offs */
end_comment

begin_define
define|#
directive|define
name|GLOB_ERR
value|0x04
end_define

begin_comment
comment|/* return on error */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|GLOB_MAGCHAR
value|0x08
end_define

begin_comment
comment|/* pattern had globbing characters */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLOB_MARK
value|0x10
end_define

begin_comment
comment|/* append / to matching directories */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOCHECK
value|0x20
end_define

begin_comment
comment|/* return pattern itself if nothing matches */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSORT
value|0x40
end_define

begin_comment
comment|/* don't sort */
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
value|0x80
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|glob
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|glob_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|globfree
name|__P
argument_list|(
operator|(
name|glob_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

