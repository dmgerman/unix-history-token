begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pathnames.h	5.1 (Berkeley) 5/11/89  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"PATH=%s/bin:"
end_define

begin_define
define|#
directive|define
name|_PATH_LEARN
value|"/usr/libdata/learn"
end_define

begin_define
define|#
directive|define
name|_PATH_RM
value|"/bin/rm"
end_define

begin_define
define|#
directive|define
name|_PATH_STTY
value|"/bin/stty"
end_define

end_unit

