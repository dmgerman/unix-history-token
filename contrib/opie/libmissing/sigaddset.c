begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sigaddset.c: A replacement for the sigaddset function  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.          History:  	Created by cmetz for OPIE 2.2. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_NSIG
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NSIG
end_ifdef

begin_define
define|#
directive|define
name|_NSIG
value|NSIG
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NSIG */
end_comment

begin_define
define|#
directive|define
name|_NSIG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSIG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NSIG */
end_comment

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_decl_stmt
name|int
name|sigaddset
name|FUNCTION
argument_list|(
operator|(
name|set
operator|,
name|signum
operator|)
argument_list|,
name|sigset_t
operator|*
name|set
name|AND
name|int
name|signum
argument_list|)
block|{
if|#
directive|if
sizeof|sizeof
argument_list|(
name|sigset_t
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
name|Sorry
operator|,
name|we
name|don
literal|'
end_decl_stmt

unit|t currently support your system. #else /* sizeof(sigset_t) != sizeof(int) */ 	if (set&& (signum> 0)&& (signum< _NSIG)) 		*set |= 1<< (signum - 1); #endif /* sizeof(sigset_t) != sizeof(int) */  	return 0; }
end_unit

