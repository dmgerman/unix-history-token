begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: phase.h,v 1.2.6.3 1997/08/25 00:34:36 brian Exp $  *  *	TODO:  */
end_comment

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
comment|/* Being authenticated */
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
specifier|extern
name|int
name|phase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Curent phase */
end_comment

begin_function_decl
specifier|extern
name|void
name|NewPhase
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

