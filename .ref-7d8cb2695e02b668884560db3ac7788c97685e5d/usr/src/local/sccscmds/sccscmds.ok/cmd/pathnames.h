begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)pathnames.h	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_BDIFF
value|"/usr/local/bin/bdiff"
end_define

begin_define
define|#
directive|define
name|_PATH_DIFF
value|"/usr/bin/diff"
end_define

begin_define
define|#
directive|define
name|_PATH_GET
value|"/usr/local/bin/get"
end_define

begin_define
define|#
directive|define
name|_PATH_HELPDIR
value|"/usr/local/lib/help/"
end_define

begin_define
define|#
directive|define
name|_PATH_OLDHELP
value|"/usr/local/lib/sccs.hf"
end_define

begin_define
define|#
directive|define
name|_PATH_SCCSINCLUDE
value|"/a/staff/admin/copyright"
end_define

begin_define
define|#
directive|define
name|_PATH_SCCSLOG
value|"/var/log/sccs-log"
end_define

begin_define
define|#
directive|define
name|_PATH_VAL
value|"/usr/local/bin/val"
end_define

end_unit

