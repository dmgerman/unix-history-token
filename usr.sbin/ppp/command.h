begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: command.h,v 1.2.6.2 1997/08/25 00:34:24 brian Exp $  *  *	TODO:  */
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

begin_define
define|#
directive|define
name|VAR_AUTHKEY
value|0
end_define

begin_define
define|#
directive|define
name|VAR_DIAL
value|1
end_define

begin_define
define|#
directive|define
name|VAR_LOGIN
value|2
end_define

begin_define
define|#
directive|define
name|VAR_AUTHNAME
value|3
end_define

begin_define
define|#
directive|define
name|VAR_DEVICE
value|4
end_define

begin_define
define|#
directive|define
name|VAR_ACCMAP
value|5
end_define

begin_define
define|#
directive|define
name|VAR_PHONE
value|6
end_define

begin_define
define|#
directive|define
name|VAR_HANGUP
value|7
end_define

begin_function_decl
specifier|extern
name|int
name|SetVariable
parameter_list|(
name|struct
name|cmdtab
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
name|var_param
parameter_list|)
function_decl|;
end_function_decl

end_unit

