begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is te-generic.h and is intended to be a template for  * target environment specific header files.  *  * It is my intent that this file will evolve into a file suitable for config,  * compile, and copying as an aid for testing and porting.  xoxorich.  */
end_comment

begin_comment
comment|/* Added these, because if we don't know what we're targetting we may    need an assembler version of libgcc, and that will use local    labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* these define interfaces */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_HEADER
end_ifdef

begin_include
include|#
directive|include
include|OBJ_HEADER
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of te-generic.h */
end_comment

end_unit

