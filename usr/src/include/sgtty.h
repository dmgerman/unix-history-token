begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	sgtty.h	4.1	83/05/03	*/
end_comment

begin_comment
comment|/*  * Structure for stty and gtty system calls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SGTTYB_
end_ifndef

begin_define
define|#
directive|define
name|_SGTTYB_
end_define

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|short
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

