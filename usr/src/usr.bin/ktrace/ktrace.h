begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktrace.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|DEF_FACS
value|(KTRFAC_SYSCALL | KTRFAC_SYSRET | KTRFAC_NAMEI)
end_define

begin_define
define|#
directive|define
name|DEF_TRACEFILE
value|"ktrace.data"
end_define

end_unit

