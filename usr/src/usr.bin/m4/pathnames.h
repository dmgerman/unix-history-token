begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * %sccs.include.redist.c%  *  *	@(#)pathnames.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions of diversion files.  If the name of the file is changed,  * adjust UNIQUE to point to the wildcard (*) character in the filename.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|msdos
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DIVNAME
value|"\\M4*XXXXXX"
end_define

begin_comment
comment|/* msdos diversion files */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|3
end_define

begin_comment
comment|/* unique char location */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DIVNAME
value|"/tmp/m4.0XXXXXX"
end_define

begin_comment
comment|/* unix diversion files */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|8
end_define

begin_comment
comment|/* unique char location */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DIVNAME
value|"sys$login:m4*XXXXXX"
end_define

begin_comment
comment|/* vms diversion files */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|12
end_define

begin_comment
comment|/* unique char location */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

