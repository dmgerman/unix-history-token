begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: chap.h,v 1.6 1997/06/09 03:27:15 brian Exp $  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CHAP_H_
end_define

begin_include
include|#
directive|include
file|<md4.h>
end_include

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_define
define|#
directive|define
name|CHAP_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|CHAP_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|CHAP_SUCCESS
value|3
end_define

begin_define
define|#
directive|define
name|CHAP_FAILURE
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

