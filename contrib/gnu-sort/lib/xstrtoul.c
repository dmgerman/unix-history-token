begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|__strtol
value|strtoul
end_define

begin_define
define|#
directive|define
name|__strtol_t
value|unsigned long int
end_define

begin_define
define|#
directive|define
name|__xstrtol
value|xstrtoul
end_define

begin_define
define|#
directive|define
name|STRTOL_T_MINIMUM
value|0
end_define

begin_define
define|#
directive|define
name|STRTOL_T_MAXIMUM
value|ULONG_MAX
end_define

begin_include
include|#
directive|include
file|"xstrtol.c"
end_include

end_unit

