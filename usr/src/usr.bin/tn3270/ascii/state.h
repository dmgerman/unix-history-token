begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)state.h	4.2 (Berkeley) %G%  */
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

