begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PHASE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PHASE_H_
end_define

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_define
define|#
directive|define
name|PHASE_DEAD
value|0
end_define

begin_comment
comment|/* Link is dead */
end_comment

begin_define
define|#
directive|define
name|PHASE_ESTABLISH
value|1
end_define

begin_comment
comment|/* Establishing link */
end_comment

begin_define
define|#
directive|define
name|PHASE_AUTHENTICATE
value|2
end_define

begin_comment
comment|/* Beeing authenticate */
end_comment

begin_define
define|#
directive|define
name|PHASE_NETWORK
value|3
end_define

begin_define
define|#
directive|define
name|PHASE_TERMINATE
value|4
end_define

begin_comment
comment|/* Terminating link */
end_comment

begin_decl_stmt
name|int
name|phase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Curent phase */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|NewPhase
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PhaseNames
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

