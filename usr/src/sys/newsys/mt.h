begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<sys/mt.h>	9/8/80 */
end_comment

begin_comment
comment|/*  *	IOCTRL codes for mag tape drivers  */
end_comment

begin_define
define|#
directive|define
name|SKIPF
value|0
end_define

begin_comment
comment|/* Skip forward */
end_comment

begin_define
define|#
directive|define
name|SKIPR
value|1
end_define

begin_comment
comment|/* Skip reverse */
end_comment

begin_define
define|#
directive|define
name|WEOF
value|2
end_define

begin_comment
comment|/* Write EOF */
end_comment

begin_define
define|#
directive|define
name|REW
value|3
end_define

begin_comment
comment|/* Rewind */
end_comment

begin_define
define|#
directive|define
name|SKIPFF
value|4
end_define

begin_comment
comment|/* Skip forward file */
end_comment

begin_define
define|#
directive|define
name|SKIPRF
value|5
end_define

begin_comment
comment|/* Skip rerverse file */
end_comment

end_unit

