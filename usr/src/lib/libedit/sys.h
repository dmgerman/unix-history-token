begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)sys.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * sys.h: Put all the stupid compiler and system dependencies here...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_sys
end_ifndef

begin_define
define|#
directive|define
name|_h_sys
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|public
end_ifndef

begin_define
define|#
directive|define
name|public
end_define

begin_comment
comment|/* Externally visible functions/variables */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|private
end_ifndef

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_comment
comment|/* Always hidden internals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|protected
end_ifndef

begin_define
define|#
directive|define
name|protected
end_define

begin_comment
comment|/* Redefined from elsewhere to "static" */
end_comment

begin_comment
comment|/* When we want to hide everything	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PTR_T
end_ifndef

begin_define
define|#
directive|define
name|_PTR_T
end_define

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|ptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|ptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_T
end_ifndef

begin_define
define|#
directive|define
name|_IOCTL_T
end_define

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|ioctl_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|ioctl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|REGEXP
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS
end_ifdef

begin_undef
undef|#
directive|undef
name|REGEXP
end_undef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*sig_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/*  * Broken hdrs.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|__P
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
name|fprintf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
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
name|int
name|sigsetmask
name|__P
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
name|sigblock
name|__P
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
name|ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fputc
name|__P
argument_list|(
operator|(
name|int
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
name|fgetc
name|__P
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
name|int
name|fflush
name|__P
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
name|int
name|tolower
name|__P
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
name|toupper
name|__P
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
name|errno
decl_stmt|,
name|sys_nerr
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

begin_decl_stmt
specifier|extern
name|void
name|perror
name|__P
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
name|read
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|e
parameter_list|)
value|sys_errlist[e]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SABER
end_ifdef

begin_decl_stmt
specifier|extern
name|ptr_t
name|memcpy
name|__P
argument_list|(
operator|(
name|ptr_t
operator|,
specifier|const
name|ptr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ptr_t
name|memset
name|__P
argument_list|(
operator|(
name|ptr_t
operator|,
name|int
operator|,
name|size_t
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
name|char
modifier|*
name|fgetline
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|*
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

begin_comment
comment|/* _h_sys */
end_comment

end_unit

