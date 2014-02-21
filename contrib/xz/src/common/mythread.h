begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       mythread.h
end_comment

begin_comment
comment|/// \brief      Wrappers for threads
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"sysdefs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTHREAD
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_define
define|#
directive|define
name|mythread_once
parameter_list|(
name|func
parameter_list|)
define|\
value|do { \ 		static pthread_once_t once_ = PTHREAD_ONCE_INIT; \ 		pthread_once(&once_,&func); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|mythread_sigmask
parameter_list|(
name|how
parameter_list|,
name|set
parameter_list|,
name|oset
parameter_list|)
define|\
value|pthread_sigmask(how, set, oset)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mythread_once
parameter_list|(
name|func
parameter_list|)
define|\
value|do { \ 		static bool once_ = false; \ 		if (!once_) { \ 			func(); \ 			once_ = true; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|mythread_sigmask
parameter_list|(
name|how
parameter_list|,
name|set
parameter_list|,
name|oset
parameter_list|)
define|\
value|sigprocmask(how, set, oset)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

