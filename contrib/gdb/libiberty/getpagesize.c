begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulation of getpagesize() for systems that need it. */
end_comment

begin_comment
comment|/*  NAME  	getpagesize -- return the number of bytes in page of memory  SYNOPSIS  	int getpagesize (void)  DESCRIPTION  	Returns the number of bytes in a page of memory.  This is the 	granularity of many of the system memory management routines. 	No guarantee is made as to whether or not it is the same as the 	basic memory management hardware page size.  BUGS  	Is intended as a reasonable replacement for systems where this 	is not provided as a system call.  The value of 4096 may or may 	not be correct for the systems where it is returned as the default 	value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_PARAM_H
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSCONF
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|sysconf(_SC_PAGESIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|PAGESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no PAGESIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_PAGESIZE
end_ifdef

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
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
name|GNU_OUR_PAGESIZE
value|(NBPG * CLSIZE)
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
comment|/* CLSIZE */
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
name|GNU_OUR_PAGESIZE
value|NBPC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no NBPC */
end_comment

begin_define
define|#
directive|define
name|GNU_OUR_PAGESIZE
value|4096
end_define

begin_comment
comment|/* Just punt and use reasonable value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NBPC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NBPG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_PAGESIZE */
end_comment

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
comment|/* HAVE_SYSCONF */
end_comment

begin_function
name|int
name|getpagesize
parameter_list|()
block|{
return|return
operator|(
name|GNU_OUR_PAGESIZE
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VMS */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* older distributions of gcc-vms are missing<syidef.h> */
end_comment

begin_include
include|#
directive|include
file|<syidef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYI$_PAGE_SIZE
end_ifndef

begin_comment
comment|/* VMS V5.4 and earlier didn't have this yet */
end_comment

begin_define
define|#
directive|define
name|SYI$_PAGE_SIZE
value|4452
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|unsigned
name|long
name|lib$getsyi
parameter_list|(
specifier|const
name|unsigned
name|short
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|getpagesize
parameter_list|()
block|{
name|long
name|pagsiz
init|=
literal|0L
decl_stmt|;
name|unsigned
name|short
name|itmcod
init|=
name|SYI$_PAGE_SIZE
decl_stmt|;
operator|(
name|void
operator|)
name|lib$getsyi
argument_list|(
operator|&
name|itmcod
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|pagsiz
argument_list|)
expr_stmt|;
if|if
condition|(
name|pagsiz
operator|==
literal|0L
condition|)
name|pagsiz
operator|=
literal|512L
expr_stmt|;
comment|/* VAX default */
return|return
operator|(
name|int
operator|)
name|pagsiz
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

end_unit

