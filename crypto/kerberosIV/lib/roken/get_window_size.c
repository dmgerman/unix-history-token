begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"$Id: get_window_size.c,v 1.4 1997/04/01 08:18:59 joda Exp $"
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
file|<stdlib.h>
end_include

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
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Where were those needed? /confused */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PROC_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TTY_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_function
name|int
name|get_window_size
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|winsize
modifier|*
name|wp
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
return|return
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCGWINSZ
argument_list|,
name|wp
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|TIOCGSIZE
argument_list|)
name|struct
name|ttysize
name|ts
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGSIZE
argument_list|,
operator|&
name|ts
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|wp
operator|->
name|ws_row
operator|=
name|ts
operator|.
name|ts_lines
expr_stmt|;
name|wp
operator|->
name|ws_col
operator|=
name|ts
operator|.
name|ts_cols
expr_stmt|;
name|wp
operator|->
name|ws_xpixel
operator|=
literal|0
expr_stmt|;
name|wp
operator|->
name|ws_ypixel
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE__SCRSIZE
argument_list|)
name|int
name|dst
index|[
literal|2
index|]
decl_stmt|;
name|_scrsize
argument_list|(
name|dst
argument_list|)
expr_stmt|;
name|wp
operator|->
name|ws_row
operator|=
name|dst
index|[
literal|1
index|]
expr_stmt|;
name|wp
operator|->
name|ws_col
operator|=
name|dst
index|[
literal|0
index|]
expr_stmt|;
name|wp
operator|->
name|ws_xpixel
operator|=
literal|0
expr_stmt|;
name|wp
operator|->
name|ws_ypixel
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
block|}
end_function

end_unit

