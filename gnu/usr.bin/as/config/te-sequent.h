begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is te-sequent.h and is intended to set up emulation with  * sequent's development tools.  *  */
end_comment

begin_define
define|#
directive|define
name|TE_SEQUENT
value|1
end_define

begin_comment
comment|/* sequent has a "special" header. */
end_comment

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(128)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TC_I386
end_ifdef

begin_comment
comment|/* zmagic is 0x22eb */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(0x12eb)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I386 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TC_NS32K
end_ifdef

begin_comment
comment|/* zmagic is 0x10ea */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(0x00ea)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_NS32K */
end_comment

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
comment|/* end of te-sequent.h */
end_comment

end_unit

