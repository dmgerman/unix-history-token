begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vis.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * cencode flags  */
end_comment

begin_define
define|#
directive|define
name|CENC_CSTYLE
value|1
end_define

begin_comment
comment|/* use C-style backslash sequences */
end_comment

begin_define
define|#
directive|define
name|CENC_GRAPH
value|2
end_define

begin_comment
comment|/* encode as ^? and M- sequences */
end_comment

begin_define
define|#
directive|define
name|CENC_OCTAL
value|4
end_define

begin_comment
comment|/* encode as octal sequences */
end_comment

begin_define
define|#
directive|define
name|CENC_ALL
value|(CENC_CSTYLE|CENC_GRAPH|CENC_OCTAL)
end_define

begin_define
define|#
directive|define
name|CENC_WHITE
value|8
end_define

begin_comment
comment|/* encode white-space chars (sp-tb-nl) */
end_comment

begin_define
define|#
directive|define
name|CENC_RACHAR
value|0x10
end_define

begin_comment
comment|/* look at read-ahead char */
end_comment

begin_comment
comment|/*  * cdecode flags  */
end_comment

begin_define
define|#
directive|define
name|CDEC_HAT
value|1
end_define

begin_comment
comment|/* treat ^ as special */
end_comment

begin_define
define|#
directive|define
name|CDEC_END
value|2
end_define

begin_comment
comment|/* reset decode machine */
end_comment

begin_comment
comment|/*  * cdecode return codes  */
end_comment

begin_define
define|#
directive|define
name|CDEC_NEEDMORE
value|0
end_define

begin_comment
comment|/* not done, feed another char */
end_comment

begin_define
define|#
directive|define
name|CDEC_OK
value|1
end_define

begin_comment
comment|/* done, character ready */
end_comment

begin_define
define|#
directive|define
name|CDEC_OKPUSH
value|2
end_define

begin_comment
comment|/* done, push back passed char */
end_comment

begin_define
define|#
directive|define
name|CDEC_NOCHAR
value|3
end_define

begin_comment
comment|/* done, no character ready (hidden newline) */
end_comment

begin_define
define|#
directive|define
name|CDEC_SYNBAD
value|-1
end_define

begin_comment
comment|/* unrecognized escape sequence */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|cencode
parameter_list|()
function_decl|;
end_function_decl

end_unit

