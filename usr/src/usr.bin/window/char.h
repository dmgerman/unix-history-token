begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)char.h	3.8 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Macros and things to deal with control characters.  *  * Unctrl() is just like the standard function, except we don't want  * to include curses.  * Isctrl() returns true for all characters less than space and  * greater than or equal to delete.  * Isprt() is tab and all characters not isctrl().  It's used  * by wwwrite().  * Isunctrl() includes all characters that should be expanded  * using unctrl() by wwwrite() if ww_unctrl is set.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_unctrl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|_cmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ctrl
parameter_list|(
name|c
parameter_list|)
value|(c& 0x1f)
end_define

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|c
parameter_list|)
value|(_unctrl[(unsigned char) (c)])
end_define

begin_define
define|#
directive|define
name|_C
value|0x01
end_define

begin_define
define|#
directive|define
name|_P
value|0x02
end_define

begin_define
define|#
directive|define
name|_U
value|0x04
end_define

begin_define
define|#
directive|define
name|isctrl
parameter_list|(
name|c
parameter_list|)
value|(_cmap[(unsigned char) (c)]& _C)
end_define

begin_define
define|#
directive|define
name|isprt
parameter_list|(
name|c
parameter_list|)
value|(_cmap[(unsigned char) (c)]& _P)
end_define

begin_define
define|#
directive|define
name|isunctrl
parameter_list|(
name|c
parameter_list|)
value|(_cmap[(unsigned char) (c)]& _U)
end_define

end_unit

