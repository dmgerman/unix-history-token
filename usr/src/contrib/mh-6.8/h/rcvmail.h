begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rcvmail.h - rcvmail hook definitions */
end_comment

begin_comment
comment|/* @(#)$Id: rcvmail.h,v 1.3 1992/12/15 00:20:22 jromine Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MMDFMTS
end_ifndef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"../mts/sendmail/smail.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MMDFMTS */
end_comment

begin_include
include|#
directive|include
file|"../mts/mmdf/util.h"
end_include

begin_include
include|#
directive|include
file|"../mts/mmdf/mmdf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMDFMTS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MMDFI
end_ifndef

begin_define
define|#
directive|define
name|RCV_MOK
value|0
end_define

begin_define
define|#
directive|define
name|RCV_MBX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MMDFI */
end_comment

begin_define
define|#
directive|define
name|RCV_MOK
value|RP_MOK
end_define

begin_define
define|#
directive|define
name|RCV_MBX
value|RP_MECH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMDFI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NRTC
end_ifdef

begin_comment
comment|/* sigh */
end_comment

begin_undef
undef|#
directive|undef
name|RCV_MOK
end_undef

begin_undef
undef|#
directive|undef
name|RCV_MBX
end_undef

begin_define
define|#
directive|define
name|RCV_MOK
value|RP_MOK
end_define

begin_define
define|#
directive|define
name|RCV_MBX
value|RP_MECH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NRTC */
end_comment

end_unit

