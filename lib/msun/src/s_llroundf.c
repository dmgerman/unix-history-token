begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|type
value|float
end_define

begin_define
define|#
directive|define
name|roundit
value|roundf
end_define

begin_define
define|#
directive|define
name|dtype
value|long long
end_define

begin_define
define|#
directive|define
name|DTYPE_MIN
value|LLONG_MIN
end_define

begin_define
define|#
directive|define
name|DTYPE_MAX
value|LLONG_MAX
end_define

begin_define
define|#
directive|define
name|fn
value|llroundf
end_define

begin_include
include|#
directive|include
file|"s_lround.c"
end_include

end_unit

