begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|GPROF4
value|1
end_define

begin_comment
comment|/* XXX can't get at kernel options */
end_comment

begin_define
define|#
directive|define
name|GUPROF
value|1
end_define

begin_comment
comment|/* XXX can't get at kernel options */
end_comment

begin_include
include|#
directive|include
file|"../lib/libc/gmon/mcount.c"
end_include

begin_comment
comment|/* XXX */
end_comment

end_unit

