begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running DG/ux */
end_comment

begin_comment
comment|/* looks just like sysv4 for now */
end_comment

begin_include
include|#
directive|include
file|"i386/xm-i386.h"
end_include

begin_include
include|#
directive|include
file|"xm-svr4.h"
end_include

begin_comment
comment|/* If not compiled with GNU C, use the portable alloca.  */
end_comment

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

