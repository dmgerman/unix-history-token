begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* local.h - fine the -lndir include file */
end_comment

begin_comment
comment|/* @(#)$Id: local.h,v 1.3 1992/02/06 17:37:44 jromine Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD42 */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NDIR
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5DIR
end_ifndef

begin_include
include|#
directive|include
file|<dir.h>
end_include

begin_comment
comment|/* last choice */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS5DIR */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NDIR */
end_comment

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD42 */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

end_unit

