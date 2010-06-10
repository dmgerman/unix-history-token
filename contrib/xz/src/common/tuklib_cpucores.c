begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_cpucores.c
end_comment

begin_comment
comment|/// \brief      Get the number of CPU cores online
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
file|"tuklib_cpucores.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TUKLIB_CPUCORES_SYSCTL
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TUKLIB_CPUCORES_SYSCONF
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|extern
name|uint32_t
name|tuklib_cpucores
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|ret
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|TUKLIB_CPUCORES_SYSCTL
argument_list|)
name|int
name|name
index|[
literal|2
index|]
init|=
block|{
name|CTL_HW
block|,
name|HW_NCPU
block|}
decl_stmt|;
name|int
name|cpus
decl_stmt|;
name|size_t
name|cpus_size
init|=
sizeof|sizeof
argument_list|(
name|cpus
argument_list|)
decl_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|name
argument_list|,
literal|2
argument_list|,
operator|&
name|cpus
argument_list|,
operator|&
name|cpus_size
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
operator|&&
name|cpus_size
operator|==
sizeof|sizeof
argument_list|(
name|cpus
argument_list|)
operator|&&
name|cpus
operator|>
literal|0
condition|)
name|ret
operator|=
operator|(
name|uint32_t
operator|)
name|cpus
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|TUKLIB_CPUCORES_SYSCONF
argument_list|)
ifdef|#
directive|ifdef
name|_SC_NPROCESSORS_ONLN
comment|// Most systems
specifier|const
name|long
name|cpus
init|=
name|sysconf
argument_list|(
name|_SC_NPROCESSORS_ONLN
argument_list|)
decl_stmt|;
else|#
directive|else
comment|// IRIX
specifier|const
name|long
name|cpus
init|=
name|sysconf
argument_list|(
name|_SC_NPROC_ONLN
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|cpus
operator|>
literal|0
condition|)
name|ret
operator|=
operator|(
name|uint32_t
operator|)
name|cpus
expr_stmt|;
endif|#
directive|endif
return|return
name|ret
return|;
block|}
end_function

end_unit

