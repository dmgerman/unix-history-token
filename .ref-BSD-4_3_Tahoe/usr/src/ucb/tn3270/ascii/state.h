begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)state.h	3.2 (Berkeley) 3/28/88  */
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

