begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)hp2648.h	5.1 (Berkeley) 5/7/85  *  *  * Displays plot files on an hp2648a graphics terminals.  I have heard  * that all hp plotting devices use the same control sequences, so this  * might work for all hp devices capable of plotting.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|TERMINAL
value|"/dev/tty"
end_define

begin_define
define|#
directive|define
name|ENQ
value|05
end_define

begin_define
define|#
directive|define
name|ACK
value|06
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|GRAPHIC
value|'*'
end_define

begin_define
define|#
directive|define
name|MODE
value|'m'
end_define

begin_define
define|#
directive|define
name|PLOT
value|'p'
end_define

begin_define
define|#
directive|define
name|DISPLAY
value|'d'
end_define

begin_define
define|#
directive|define
name|PENUP
value|'a'
end_define

begin_define
define|#
directive|define
name|BINARY
value|'i'
end_define

begin_define
define|#
directive|define
name|ASCII
value|'f'
end_define

begin_define
define|#
directive|define
name|CR
value|'\n'
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|xsc
parameter_list|(
name|xi
parameter_list|)
value|((int) (xi - lowx) * scalex + 0.5)
end_define

begin_define
define|#
directive|define
name|ysc
parameter_list|(
name|yi
parameter_list|)
value|((int) (yi - lowy) * scaley + 0.5)
end_define

begin_decl_stmt
specifier|extern
name|int
name|shakehands
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|currentx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|currenty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|buffcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fildes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|lowx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|lowy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scaley
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|sarg
decl_stmt|;
end_decl_stmt

end_unit

