begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Integrated Solutions 386 machine.  */
end_comment

begin_include
include|#
directive|include
file|"m-intel386.h"
end_include

begin_define
define|#
directive|define
name|LIBX10_MACHINE
value|-lnsl_s
end_define

begin_define
define|#
directive|define
name|LIBX11_MACHINE
value|-lnsl_s
end_define

begin_undef
undef|#
directive|undef
name|HAVE_PTYS
end_undef

begin_undef
undef|#
directive|undef
name|SYSV_PTYS
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_SOCKETS
end_undef

begin_define
define|#
directive|define
name|LIBS_DEBUG
value|-lg
end_define

end_unit

