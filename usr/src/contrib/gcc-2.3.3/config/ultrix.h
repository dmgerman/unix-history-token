begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"vax.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|" -Dvax -Dunix -Dultrix -Dbsd4_2 -D__vax -D__unix -D__ultrix -D__bsd4_2"
end_define

begin_comment
comment|/* By default, allow $ to be part of an identifier.  */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|1
end_define

begin_comment
comment|/* These are as defined in /usr/include/sys/stdtypes.h.    These values are for ultrix 4.2 on the vax.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

end_unit

