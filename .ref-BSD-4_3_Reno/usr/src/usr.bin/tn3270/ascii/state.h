begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)state.h	4.1 (Berkeley) 12/4/88  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_STATE
end_define

begin_comment
comment|/* this defines the state structure used by the key mapping routines */
end_comment

begin_define
define|#
directive|define
name|STATE_NULL
value|-1
end_define

begin_comment
comment|/* Falls off edge */
end_comment

begin_define
define|#
directive|define
name|STATE_GOTO
value|-2
end_define

begin_comment
comment|/* GOTO internal state */
end_comment

begin_define
define|#
directive|define
name|state
value|struct State
end_define

begin_struct
struct|struct
name|State
block|{
name|int
name|match
decl_stmt|;
comment|/* character to match */
name|int
name|result
decl_stmt|;
comment|/* 3270 control code */
name|state
modifier|*
name|next
decl_stmt|;
comment|/* next entry in this same state */
name|state
modifier|*
name|address
decl_stmt|;
comment|/* if goto, where is next state */
block|}
struct|;
end_struct

end_unit

