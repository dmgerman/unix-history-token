begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Fri Mar  4 12:11:36 1983 by jkf]-  * 	ltypes.h			$Locker:  $  * lisp data type defs  *  * $Header: /na/franz/franz/h/RCS/ltypes.h,v 1.2 83/03/04 12:30:22 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/* type flags */
end_comment

begin_define
define|#
directive|define
name|UNBO
value|-1
end_define

begin_define
define|#
directive|define
name|STRNG
value|0
end_define

begin_define
define|#
directive|define
name|ATOM
value|1
end_define

begin_define
define|#
directive|define
name|INT
value|2
end_define

begin_define
define|#
directive|define
name|DTPR
value|3
end_define

begin_define
define|#
directive|define
name|DOUB
value|4
end_define

begin_define
define|#
directive|define
name|BCD
value|5
end_define

begin_define
define|#
directive|define
name|PORT
value|6
end_define

begin_define
define|#
directive|define
name|ARRAY
value|7
end_define

begin_define
define|#
directive|define
name|OTHER
value|8
end_define

begin_define
define|#
directive|define
name|SDOT
value|9
end_define

begin_define
define|#
directive|define
name|VALUE
value|10
end_define

begin_define
define|#
directive|define
name|HUNK2
value|11
end_define

begin_comment
comment|/* The hunks */
end_comment

begin_define
define|#
directive|define
name|HUNK4
value|12
end_define

begin_define
define|#
directive|define
name|HUNK8
value|13
end_define

begin_define
define|#
directive|define
name|HUNK16
value|14
end_define

begin_define
define|#
directive|define
name|HUNK32
value|15
end_define

begin_define
define|#
directive|define
name|HUNK64
value|16
end_define

begin_define
define|#
directive|define
name|HUNK128
value|17
end_define

begin_define
define|#
directive|define
name|VECTOR
value|18
end_define

begin_define
define|#
directive|define
name|VECTORI
value|19
end_define

end_unit

