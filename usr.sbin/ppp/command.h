begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_struct
struct|struct
name|cmdtab
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|alias
decl_stmt|;
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
name|u_char
name|lauth
decl_stmt|;
name|char
modifier|*
name|helpmes
decl_stmt|;
name|char
modifier|*
name|syntax
decl_stmt|;
name|void
modifier|*
name|args
decl_stmt|;
block|}
struct|;
end_struct

end_unit

