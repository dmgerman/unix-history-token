begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"m-mips.h"
end_include

begin_undef
undef|#
directive|undef
name|LIBS_MACHINE
end_undef

begin_undef
undef|#
directive|undef
name|BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|LIB_STANDARD
end_undef

begin_undef
undef|#
directive|undef
name|START_FILES
end_undef

begin_undef
undef|#
directive|undef
name|COFF
end_undef

begin_undef
undef|#
directive|undef
name|TERMINFO
end_undef

begin_define
define|#
directive|define
name|MAIL_USE_FLOCK
end_define

begin_define
define|#
directive|define
name|HAVE_UNION_WAIT
end_define

begin_comment
comment|/* This line starts being needed with ultrix 4.0.  */
end_comment

begin_comment
comment|/* You must delete it for version 3.1.  */
end_comment

begin_define
define|#
directive|define
name|START_FILES
value|pre-crt0.o /usr/lib/cmplrs/cc/crt0.o
end_define

begin_comment
comment|/* Supposedly the following will overcome a kernel bug.  */
end_comment

begin_undef
undef|#
directive|undef
name|LD_SWITCH_MACHINE
end_undef

begin_undef
undef|#
directive|undef
name|DATA_START
end_undef

begin_define
define|#
directive|define
name|DATA_START
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DATA_SEG_BITS
value|0x10000000
end_define

begin_comment
comment|/* In Ultrix 4.1, XvmsAlloc.o in libX11.a seems to insist    on defining malloc itself.  This should avoid conflicting with it.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_MALLOC
end_define

end_unit

