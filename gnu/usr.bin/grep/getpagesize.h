begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate getpagesize on systems that lack it.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPAGESIZE
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
name|getpagesize
operator|&&
name|defined
name|__BEOS__
end_if

begin_include
include|#
directive|include
file|<OS.h>
end_include

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|B_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|getpagesize
operator|&&
name|defined
name|_SC_PAGESIZE
end_if

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
name|VMS
operator|&&
name|__VMS_VER
operator|<
literal|70000000
operator|)
end_if

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf (_SC_PAGESIZE)
end_define

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
operator|!
name|defined
name|getpagesize
operator|&&
name|defined
name|VMS
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__ALPHA
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|8192
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|getpagesize
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|EXEC_PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NBPG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CLSIZE
end_ifndef

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|(NBPG * CLSIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NBPC
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|NBPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_GETPAGESIZE */
end_comment

end_unit

