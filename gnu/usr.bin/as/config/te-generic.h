begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is te-generic.h and is intended to be a template for  * target environment specific header files.  *  * It is my intent that this file will evolve into a file suitable for config,  * compile, and copying as an aid for testing and porting.  xoxorich.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TE_GENERIC
value|1
end_define

begin_comment
comment|/* these define interfaces */
end_comment

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of te-generic.h */
end_comment

end_unit

