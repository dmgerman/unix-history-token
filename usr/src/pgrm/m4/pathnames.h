begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)pathnames.h	5.3 (Berkeley) 6/1/90  */
end_comment

begin_comment
comment|/*  * definitions of diversion files. If the name of  * the file is changed, adjust UNIQUE to point to the  * wildcard (*) character in the filename.  */
end_comment

begin_define
define|#
directive|define
name|DIVNAM
value|"/tmp/m4*XXXXXX"
end_define

begin_comment
comment|/* unix diversion files */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|7
end_define

begin_comment
comment|/* unique char location */
end_comment

end_unit

