begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)send.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_define
define|#
directive|define
name|RINIT
value|1
end_define

begin_define
define|#
directive|define
name|RENQ
value|2
end_define

begin_define
define|#
directive|define
name|RTREE
value|3
end_define

begin_define
define|#
directive|define
name|RTRFREE
value|4
end_define

begin_define
define|#
directive|define
name|RTRCHK
value|5
end_define

begin_define
define|#
directive|define
name|REVENIT
value|6
end_define

begin_define
define|#
directive|define
name|RSTRING
value|7
end_define

begin_define
define|#
directive|define
name|REVLAB
value|8
end_define

begin_define
define|#
directive|define
name|REVCNST
value|9
end_define

begin_define
define|#
directive|define
name|REVTBEG
value|10
end_define

begin_define
define|#
directive|define
name|REVTYPE
value|11
end_define

begin_define
define|#
directive|define
name|REVTEND
value|12
end_define

begin_define
define|#
directive|define
name|REVVBEG
value|13
end_define

begin_define
define|#
directive|define
name|REVVAR
value|14
end_define

begin_define
define|#
directive|define
name|REVVEND
value|15
end_define

begin_define
define|#
directive|define
name|REVFHDR
value|16
end_define

begin_define
define|#
directive|define
name|REVFFWD
value|17
end_define

begin_define
define|#
directive|define
name|REVFBDY
value|18
end_define

begin_define
define|#
directive|define
name|REVFEND
value|19
end_define

begin_define
define|#
directive|define
name|ROPUSH
value|20
end_define

begin_define
define|#
directive|define
name|ROPOP
value|21
end_define

begin_define
define|#
directive|define
name|ROSET
value|22
end_define

begin_define
define|#
directive|define
name|RKILL
value|23
end_define

begin_define
define|#
directive|define
name|RFINISH
value|24
end_define

begin_define
define|#
directive|define
name|RLAST
value|24
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|trdesc
index|[]
decl_stmt|;
end_decl_stmt

end_unit

