begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /va/arnold/=lib/=curses/RCS/unctrl.h,v 1.1 85/02/06 12:03:20 arnold Exp $ */
end_comment

begin_comment
comment|/*  * unctrl.h  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_unctrl
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|ch
parameter_list|)
value|(_unctrl[ch& 0177])
end_define

end_unit

