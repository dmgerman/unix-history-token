begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mfsiom.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|MFS_MAPREG
value|(MAXPHYS/NBPG + 2)
end_define

begin_comment
comment|/* Kernel mapping pte's */
end_comment

begin_define
define|#
directive|define
name|MFS_MAPSIZE
value|10
end_define

begin_comment
comment|/* Size of alloc map for pte's */
end_comment

end_unit

