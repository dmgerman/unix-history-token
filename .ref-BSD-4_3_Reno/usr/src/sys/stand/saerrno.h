begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)saerrno.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just like unix */
end_comment

begin_comment
comment|/* error codes */
end_comment

begin_define
define|#
directive|define
name|EADAPT
value|1
end_define

begin_comment
comment|/* bad adaptor */
end_comment

begin_define
define|#
directive|define
name|ECTLR
value|2
end_define

begin_comment
comment|/* bad controller */
end_comment

begin_define
define|#
directive|define
name|EUNIT
value|3
end_define

begin_comment
comment|/* bad drive */
end_comment

begin_define
define|#
directive|define
name|EPART
value|4
end_define

begin_comment
comment|/* bad partition */
end_comment

begin_define
define|#
directive|define
name|ERDLAB
value|5
end_define

begin_comment
comment|/* can't read disk label */
end_comment

begin_define
define|#
directive|define
name|EUNLAB
value|6
end_define

begin_comment
comment|/* unlabeled disk */
end_comment

begin_define
define|#
directive|define
name|ENXIO
value|7
end_define

begin_comment
comment|/* bad device specification */
end_comment

begin_define
define|#
directive|define
name|EBADF
value|8
end_define

begin_comment
comment|/* bad file descriptor */
end_comment

begin_define
define|#
directive|define
name|EOFFSET
value|9
end_define

begin_comment
comment|/* relative seek not supported */
end_comment

begin_define
define|#
directive|define
name|ESRCH
value|10
end_define

begin_comment
comment|/* directory search for file failed */
end_comment

begin_define
define|#
directive|define
name|EIO
value|11
end_define

begin_comment
comment|/* generic error */
end_comment

begin_define
define|#
directive|define
name|ECMD
value|12
end_define

begin_comment
comment|/* undefined driver command */
end_comment

begin_define
define|#
directive|define
name|EBSE
value|13
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|EWCK
value|14
end_define

begin_comment
comment|/* write check error */
end_comment

begin_define
define|#
directive|define
name|EECC
value|15
end_define

begin_comment
comment|/* uncorrectable ecc error */
end_comment

begin_define
define|#
directive|define
name|EHER
value|16
end_define

begin_comment
comment|/* hard error */
end_comment

end_unit

