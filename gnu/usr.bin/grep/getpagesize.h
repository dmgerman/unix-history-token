begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate getpagesize on systems that lack it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPAGESIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGESIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no _SC_PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

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

begin_comment
comment|/* no EXEC_PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NBPG
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|NBPG * CLSIZE
end_define

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

begin_comment
comment|/* no CLSIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPG */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|PAGESIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no NBPC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no NBPG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no EXEC_PAGESIZE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no HAVE_SYS_PARAM_H */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|8192
end_define

begin_comment
comment|/* punt totally */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no HAVE_SYS_PARAM_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no _SC_PAGESIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no HAVE_GETPAGESIZE */
end_comment

end_unit

