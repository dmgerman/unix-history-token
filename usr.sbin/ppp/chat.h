begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  *  Most of codes are derived from chat.c by Karl Fox (karl@MorningStar.Com).  *  *	Chat -- a program for automatic session establishment (i.e. dial  *		the phone and log in).  *  *	This software is in the public domain.  *  *	Please send all bug reports, requests for information, etc. to:  *  *		Karl Fox<karl@MorningStar.Com>  *		Morning Star Technologies, Inc.  *		1760 Zollinger Road  *		Columbus, OH  43221  *		(614)451-1883  *  * $Id: chat.h,v 1.8 1997/10/26 01:02:23 brian Exp $  *  */
end_comment

begin_define
define|#
directive|define
name|VECSIZE
parameter_list|(
name|v
parameter_list|)
value|(sizeof(v) / sizeof(v[0]))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|ExpandString
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MakeArgs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mangles the first arg ! */
end_comment

begin_function_decl
specifier|extern
name|int
name|DoChat
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* passes arg to MakeArgs() */
end_comment

end_unit

