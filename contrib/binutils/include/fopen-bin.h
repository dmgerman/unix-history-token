begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macros for the 'type' part of an fopen, freopen or fdopen.<Read|Write>[Update]<Binary file|text file>     This version is for "binary" systems, where text and binary files are    different.  An example is Mess-Dose.  Many Unix systems could also    cope with a "b" in the string, indicating binary files, but some reject this    (and thereby don't conform to ANSI C, but what else is new?).     This file is designed for inclusion by host-dependent .h files.  No    user application should include it directly, since that would make    the application unable to be configured for both "same" and "binary"    variant systems.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_RB
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WB
value|"wb"
end_define

begin_define
define|#
directive|define
name|FOPEN_AB
value|"ab"
end_define

begin_define
define|#
directive|define
name|FOPEN_RUB
value|"r+b"
end_define

begin_define
define|#
directive|define
name|FOPEN_WUB
value|"w+b"
end_define

begin_define
define|#
directive|define
name|FOPEN_AUB
value|"a+b"
end_define

begin_define
define|#
directive|define
name|FOPEN_RT
value|"r"
end_define

begin_define
define|#
directive|define
name|FOPEN_WT
value|"w"
end_define

begin_define
define|#
directive|define
name|FOPEN_AT
value|"a"
end_define

begin_define
define|#
directive|define
name|FOPEN_RUT
value|"r+"
end_define

begin_define
define|#
directive|define
name|FOPEN_WUT
value|"w+"
end_define

begin_define
define|#
directive|define
name|FOPEN_AUT
value|"a+"
end_define

end_unit

