begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pause.c    Pause for half a second.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_comment
comment|/* Pick a timing routine to use.  I somewhat arbitrarily picked usleep    above napms above poll above select above nap.  The nap function is    last because on different systems the argument has different    meanings.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_USLEEP
operator|||
name|HAVE_NAPMS
operator|||
name|HAVE_POLL
operator|||
name|HAVE_SELECT
end_if

begin_undef
undef|#
directive|undef
name|HAVE_NAP
end_undef

begin_define
define|#
directive|define
name|HAVE_NAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_USLEEP
operator|||
name|HAVE_NAPMS
operator|||
name|HAVE_POLL
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SELECT
end_undef

begin_define
define|#
directive|define
name|HAVE_SELECT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_USLEEP
operator|||
name|HAVE_NAPMS
end_if

begin_undef
undef|#
directive|undef
name|HAVE_POLL
end_undef

begin_define
define|#
directive|define
name|HAVE_POLL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_USLEEP
end_if

begin_undef
undef|#
directive|undef
name|HAVE_NAPMS
end_undef

begin_define
define|#
directive|define
name|HAVE_NAPMS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SELECT
end_if

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SELECT_H
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_POLL
end_if

begin_if
if|#
directive|if
name|HAVE_STROPTS_H
end_if

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_POLL_H
end_if

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STROPTS_H
operator|&&
operator|!
name|HAVE_POLL_H
end_if

begin_comment
comment|/* We need a definition for struct pollfd, although it doesn't matter    what it contains.  */
end_comment

begin_struct
struct|struct
name|pollfd
block|{
name|int
name|idummy
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STROPTS_H&& ! HAVE_POLL_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_POLL */
end_comment

begin_if
if|#
directive|if
name|HAVE_TIME_H
end_if

begin_if
if|#
directive|if
operator|!
name|HAVE_SYS_TIME_H
operator|||
operator|!
name|HAVE_SELECT
operator|||
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|usysdep_pause
parameter_list|()
block|{
if|#
directive|if
name|HAVE_NAPMS
name|napms
argument_list|(
literal|500
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_NAPMS */
if|#
directive|if
name|HAVE_NAP
if|#
directive|if
name|HAVE_HUNDREDTHS_NAP
name|nap
argument_list|(
literal|50L
argument_list|)
expr_stmt|;
else|#
directive|else
name|nap
argument_list|(
literal|500L
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ! HAVE_HUNDREDTHS_NAP */
endif|#
directive|endif
comment|/* HAVE_NAP */
if|#
directive|if
name|HAVE_USLEEP
name|usleep
argument_list|(
literal|500
operator|*
operator|(
name|long
operator|)
literal|1000
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_USLEEP */
if|#
directive|if
name|HAVE_POLL
name|struct
name|pollfd
name|sdummy
decl_stmt|;
comment|/* We need to pass an unused pollfd structure because poll checks      the address before checking the number of elements.  */
name|memset
argument_list|(
operator|&
name|sdummy
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|sdummy
argument_list|)
expr_stmt|;
name|poll
argument_list|(
operator|&
name|sdummy
argument_list|,
literal|0
argument_list|,
literal|500
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_POLL */
if|#
directive|if
name|HAVE_SELECT
name|struct
name|timeval
name|s
decl_stmt|;
name|s
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|s
operator|.
name|tv_usec
operator|=
literal|500
operator|*
operator|(
name|long
operator|)
literal|1000
expr_stmt|;
name|select
argument_list|(
literal|0
argument_list|,
operator|(
name|pointer
operator|)
name|NULL
argument_list|,
operator|(
name|pointer
operator|)
name|NULL
argument_list|,
operator|(
name|pointer
operator|)
name|NULL
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SELECT */
if|#
directive|if
operator|!
name|HAVE_NAPMS
operator|&&
operator|!
name|HAVE_NAP
operator|&&
operator|!
name|HAVE_USLEEP
if|#
directive|if
operator|!
name|HAVE_SELECT
operator|&&
operator|!
name|HAVE_POLL
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ! HAVE_SELECT&& ! HAVE_POLL */
endif|#
directive|endif
comment|/* ! HAVE_NAPMS&& ! HAVE_NAP&& ! HAVE_USLEEP */
block|}
end_function

end_unit

