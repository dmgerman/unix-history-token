begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ed James.  *  * %sccs.include.redist.c%  *  *	@(#)def.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_define
define|#
directive|define
name|AUTHOR_STR
value|"ATC - by Ed James"
end_define

begin_define
define|#
directive|define
name|PI
value|3.14159654
end_define

begin_define
define|#
directive|define
name|LOWFUEL
value|15
end_define

begin_define
define|#
directive|define
name|REALLOC
value|10
end_define

begin_define
define|#
directive|define
name|SGN
parameter_list|(
name|x
parameter_list|)
value|((x< 0) ? -1 : ((x> 0) ? 1 : 0))
end_define

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|((x< 0) ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|DIR_FROM_DXDY
parameter_list|(
name|dx
parameter_list|,
name|dy
parameter_list|)
value|((int) (atan2((double)(dy), (double)(dx)) \ 				* MAXDIR / (2 * PI) + 2.5 + MAXDIR) % MAXDIR)
end_define

begin_define
define|#
directive|define
name|MAXDIR
value|8
end_define

begin_define
define|#
directive|define
name|D_LEFT
value|1
end_define

begin_define
define|#
directive|define
name|D_RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|D_UP
value|3
end_define

begin_define
define|#
directive|define
name|D_DOWN
value|4
end_define

begin_define
define|#
directive|define
name|T_NODEST
value|0
end_define

begin_define
define|#
directive|define
name|T_BEACON
value|1
end_define

begin_define
define|#
directive|define
name|T_EXIT
value|2
end_define

begin_define
define|#
directive|define
name|T_AIRPORT
value|3
end_define

begin_define
define|#
directive|define
name|S_NONE
value|0
end_define

begin_define
define|#
directive|define
name|S_GONE
value|1
end_define

begin_define
define|#
directive|define
name|S_MARKED
value|2
end_define

begin_define
define|#
directive|define
name|S_UNMARKED
value|3
end_define

begin_define
define|#
directive|define
name|S_IGNORED
value|4
end_define

begin_define
define|#
directive|define
name|INPUT_LINES
value|3
end_define

begin_define
define|#
directive|define
name|PLANE_COLS
value|20
end_define

end_unit

