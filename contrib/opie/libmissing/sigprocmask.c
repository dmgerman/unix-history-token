begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sigprocmask.c: A replacement for the sigprocmask() function  %%% portions-copyright-cmetz Portions of this software are Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.          History:  	Created by cmetz for OPIE 2.2 from popen.c. Use FUNCTION                declaration et al. Include opie.h. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGNAL_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SIGNAL_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIGBLOCK
operator|||
operator|!
name|HAVE_SIGSETMASK
end_if

begin_decl_stmt
name|Without
name|sigblock
name|and
name|sigsetmask
decl_stmt|,
name|we
name|can
decl|'
end_decl_stmt

unit|t build a replacement sigprocmask. #endif /* !HAVE_SIGBLOCK || !HAVE_SIGSETMASK */  #include "opie.h"  #ifndef sigset_t #define sigset_t int #endif /* sigset_t */  int sigprocmask FUNCTION((how, set, oset), int how AND sigset_t *set AND sigset_t *oset) { 	int old, new;  	if (set&& (set != (sigset_t *)SIG_IGN)&& (set != (sigset_t *)SIG_ERR)) 		new = *set; 	else 		new = 0;  	switch(how) { 		case SIG_BLOCK: 			old = sigblock(new); 			if (oset&& (oset != (sigset_t *)SIG_IGN)&& (oset != (sigset_t *)SIG_ERR)) 				*oset = old; 			return 0;  		case SIG_SETMASK:                 	old = sigsetmask(new); 			if (oset&& (oset != (sigset_t *)SIG_IGN)&& (oset != (sigset_t *)SIG_ERR)) 				*oset = old; 			return 0;  		case SIG_UNBLOCK: 		        /* not implemented */ 		default: 			return 0; 	} }
end_unit

