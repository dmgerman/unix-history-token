begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ESIX, a variant of v.5.3 for the 386.  */
end_comment

begin_comment
comment|/* These are based on reports for ESIX 5.3.2 D.  */
end_comment

begin_include
include|#
directive|include
file|"s-usg5-3.h"
end_include

begin_define
define|#
directive|define
name|ESIX
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_define
define|#
directive|define
name|MISSING_UTIMES
end_define

begin_comment
comment|/* Some versions of V.3 have this, but not all. ESIX does. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_define
define|#
directive|define
name|SYSV_PTYS
end_define

begin_undef
undef|#
directive|undef
name|sigsetmask
end_undef

begin_comment
comment|/* ESIX has FIONREAD, but it doesn't work right on the ptys or pipes */
end_comment

begin_define
define|#
directive|define
name|BROKEN_FIONREAD
end_define

begin_define
define|#
directive|define
name|LIBS_SYSTEM
value|-lbsd
end_define

begin_define
define|#
directive|define
name|NO_SIOCTL_H
end_define

end_unit

