begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  *  Most of codes are derived from chat.c by Karl Fox (karl@MorningStar.Com).  *  *	Chat -- a program for automatic session establishment (i.e. dial  *		the phone and log in).  *  *	This software is in the public domain.  *  *	Please send all bug reports, requests for information, etc. to:  *  *		Karl Fox<karl@MorningStar.Com>  *		Morning Star Technologies, Inc.  *		1760 Zollinger Road  *		Columbus, OH  43221  *		(614)451-1883  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_CHAT_H_
end_define

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ExpandString
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|MakeArgs
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

