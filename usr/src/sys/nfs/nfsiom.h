begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsiom.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Size of the resource map and system page table pte's that are mapped  * by nfs for i/o much like a bus adapter  */
end_comment

begin_define
define|#
directive|define
name|NFS_MAPREG
value|512
end_define

begin_comment
comment|/* Num. of kernel pte's for i/o mapping */
end_comment

begin_comment
comment|/* Must be>= MAXPHYS/NBPG */
end_comment

begin_define
define|#
directive|define
name|NFS_MSIZ
value|100
end_define

begin_comment
comment|/* Size of alloc. map for pte's */
end_comment

end_unit

