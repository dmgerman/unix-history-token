begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host environment for the tti "Unicom" PBB 68020 boards */
end_comment

begin_include
include|#
directive|include
file|"sparc/xm-sparc.h"
end_include

begin_define
define|#
directive|define
name|USG
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

