begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * speaker.h -- interface definitions for speaker ioctl()  *  * v1.4 by Eric S. Raymond (esr@snark.thyrsus.com) Aug 1993  *      modified for FreeBSD by Andrew A. Chernov<ache@astral.msk.su>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SPEAKER_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SPEAKER_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

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

begin_comment
comment|/*  * Strings written to the speaker device are interpreted as tunes and played;  * see the spkr(4) man page for details.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SPEAKER_H_ */
end_comment

end_unit

