begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_comment
comment|/* this defines the state structure used by the key mapping routines */
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

