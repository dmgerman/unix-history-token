begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)optab.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/*  * px opcode information structure  */
end_comment

begin_define
define|#
directive|define
name|MAXNARGS
value|10
end_define

begin_comment
comment|/*  * argument types  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ARGTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ADDR2
value|1
end_define

begin_define
define|#
directive|define
name|ADDR4
value|2
end_define

begin_define
define|#
directive|define
name|DISP
value|3
end_define

begin_define
define|#
directive|define
name|PSUBOP
value|5
end_define

begin_define
define|#
directive|define
name|SUBOP
value|6
end_define

begin_define
define|#
directive|define
name|VLEN
value|7
end_define

begin_define
define|#
directive|define
name|HWORD
value|8
end_define

begin_define
define|#
directive|define
name|LWORD
value|9
end_define

begin_define
define|#
directive|define
name|STRING
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|opname
decl_stmt|;
name|ARGTYPE
name|argtype
index|[
name|MAXNARGS
index|]
decl_stmt|;
block|}
name|OPTAB
typedef|;
end_typedef

begin_decl_stmt
name|OPTAB
name|optab
index|[]
decl_stmt|;
end_decl_stmt

end_unit

