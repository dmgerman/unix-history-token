begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright Massachusetts Institute of Technology 1985 */
end_comment

begin_comment
comment|/* $Header: lncmd.h,v 10.4 86/02/01 16:03:32 tony Rel $ */
end_comment

begin_comment
comment|/* lncmd.h - Command sequences DEC printers, in particular LN0x laser    printers */
end_comment

begin_define
define|#
directive|define
name|LN_RIS
value|"\033c"
end_define

begin_define
define|#
directive|define
name|LN_SSU
value|"\033[%d I"
end_define

begin_define
define|#
directive|define
name|LN_PUM_SET
value|"\033[11h"
end_define

begin_define
define|#
directive|define
name|LN_PFS
value|"\033[%s J"
end_define

begin_define
define|#
directive|define
name|LN_DECSLRM
value|"\033[%d;%ds"
end_define

begin_define
define|#
directive|define
name|LN_HPA
value|"\033[%d`"
end_define

begin_define
define|#
directive|define
name|LN_VPA
value|"\033[%dd"
end_define

begin_define
define|#
directive|define
name|LN_SIXEL_GRAPHICS
value|"\033P%d;%d;%dq"
end_define

begin_define
define|#
directive|define
name|LN_ST
value|"\033\\"
end_define

begin_define
define|#
directive|define
name|LN_DECOPM_SET
value|"\033[?52h"
end_define

begin_define
define|#
directive|define
name|LN_SGR
value|"\033[1%dm"
end_define

end_unit

