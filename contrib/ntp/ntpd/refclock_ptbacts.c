begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * crude hack to avoid hard links in distribution  * and keep only one ACTS type source for different  * ACTS refclocks  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_PTBACTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|KEEPPTBACTS
end_define

begin_include
include|#
directive|include
file|"refclock_acts.c"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PTBACTS) */
end_comment

begin_decl_stmt
name|int
name|refclock_ptbacts_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PTBACTS) */
end_comment

end_unit

