begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * spkr.h -- interface definitions for speaker ioctl()  *  * v1.1 by Eric S. Raymond (esr@snark.thyrsus.com) Feb 1990  *      modified for 386bsd by Andrew A. Chernov<ache@astral.msk.su>  *      386bsd only clean version, all SYSV stuff removed  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPKR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPKR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPKRTONE
value|_IOW('S', 1, tone_t)
end_define

begin_comment
comment|/* emit tone */
end_comment

begin_define
define|#
directive|define
name|SPKRTUNE
value|_IO('S', 2)
end_define

begin_comment
comment|/* emit tone sequence*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|frequency
decl_stmt|;
comment|/* in hertz */
name|int
name|duration
decl_stmt|;
comment|/* in 1/100ths of a second */
block|}
name|tone_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPKR_H_ */
end_comment

begin_comment
comment|/* spkr.h ends here */
end_comment

end_unit

