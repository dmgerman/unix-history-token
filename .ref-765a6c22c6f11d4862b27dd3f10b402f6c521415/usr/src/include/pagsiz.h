begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pagsiz.h	4.1	83/05/03	*/
end_comment

begin_define
define|#
directive|define
name|NBPG
value|512
end_define

begin_define
define|#
directive|define
name|PGOFSET
value|511
end_define

begin_define
define|#
directive|define
name|CLSIZE
value|2
end_define

begin_define
define|#
directive|define
name|CLOFSET
value|1023
end_define

begin_define
define|#
directive|define
name|PAGSIZ
value|(NBPG*CLSIZE)
end_define

begin_define
define|#
directive|define
name|PAGRND
value|((PAGSIZ)-1)
end_define

end_unit

