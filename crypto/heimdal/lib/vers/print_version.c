begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 - 2004 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
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

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: print_version.c,v 1.6.2.1 2004/02/12 18:31:33 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_include
include|#
directive|include
file|"print_version.h"
end_include

begin_function
name|void
name|print_version
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|package_list
init|=
name|VERSIONLIST
decl_stmt|;
if|if
condition|(
name|progname
operator|==
name|NULL
condition|)
name|progname
operator|=
name|getprogname
argument_list|()
expr_stmt|;
if|if
condition|(
operator|*
name|package_list
operator|==
literal|'\0'
condition|)
name|package_list
operator|=
literal|"no version information"
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s (%s)\n"
argument_list|,
name|progname
argument_list|,
name|package_list
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Copyright 1999-2004 Kungliga Tekniska Högskolan\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Send bug-reports to %s\n"
argument_list|,
name|PACKAGE_BUGREPORT
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

