begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: pap.h,v 1.3 1997/02/22 16:10:41 peter Exp $  *  *	TODO:  */
end_comment

begin_define
define|#
directive|define
name|PAP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|PAP_ACK
value|2
end_define

begin_define
define|#
directive|define
name|PAP_NAK
value|3
end_define

begin_decl_stmt
specifier|extern
name|struct
name|authinfo
name|AuthPapInfo
decl_stmt|;
end_decl_stmt

end_unit

