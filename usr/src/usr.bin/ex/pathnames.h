begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_MAKEKEY
value|"/usr/libexec/makekey"
end_define

begin_define
define|#
directive|define
name|_PATH_BINMAIL
value|"/usr/libexec/mail.local"
end_define

begin_define
define|#
directive|define
name|_PATH_EXRECOVER
value|"/usr/libexec/ex3.7recover"
end_define

begin_define
define|#
directive|define
name|_PATH_EXPRESERVE
value|"/usr/libexec/ex3.7preserve"
end_define

begin_define
define|#
directive|define
name|_PATH_PRESERVE
value|"/var/preserve"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|vms
end_ifndef

begin_define
define|#
directive|define
name|EXSTRINGS
value|"/usr/libexec/ex3.7strings"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

