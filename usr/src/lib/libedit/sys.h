begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)sys.h	5.1 (Berkeley) %G%  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_sys */
end_comment

end_unit

