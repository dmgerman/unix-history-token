begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Work around the bug in some systems whereby gettimeofday clobbers the    static buffer that localtime uses for it's return value.  The gettimeofday    function from Mac OS X 10.0.4, i.e. Darwin 1.3.7 has this problem.    The tzset replacement is necessary for at least Solaris 2.5, 2.5.1, and 2.6.    Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* written by Jim Meyering */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_comment
comment|/* Disable the definitions of these functions (from config.h)    so we can use the library versions here.  */
end_comment

begin_undef
undef|#
directive|undef
name|gettimeofday
end_undef

begin_undef
undef|#
directive|undef
name|gmtime
end_undef

begin_undef
undef|#
directive|undef
name|localtime
end_undef

begin_undef
undef|#
directive|undef
name|tzset
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|tm
modifier|*
name|localtime_buffer_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is a wrapper for localtime.  It is used only on systems for which    gettimeofday clobbers the static buffer used for localtime's result.     On the first call, record the address of the static buffer that    localtime uses for its result.  */
end_comment

begin_function
name|struct
name|tm
modifier|*
name|rpl_localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|)
block|{
name|struct
name|tm
modifier|*
name|tm
init|=
name|localtime
argument_list|(
name|timep
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|localtime_buffer_addr
condition|)
name|localtime_buffer_addr
operator|=
name|tm
expr_stmt|;
return|return
name|tm
return|;
block|}
end_function

begin_comment
comment|/* Same as above, since gmtime and localtime use the same buffer.  */
end_comment

begin_function
name|struct
name|tm
modifier|*
name|rpl_gmtime
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|)
block|{
name|struct
name|tm
modifier|*
name|tm
init|=
name|gmtime
argument_list|(
name|timep
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|localtime_buffer_addr
condition|)
name|localtime_buffer_addr
operator|=
name|tm
expr_stmt|;
return|return
name|tm
return|;
block|}
end_function

begin_comment
comment|/* This is a wrapper for gettimeofday.  It is used only on systems for which    gettimeofday clobbers the static buffer used for localtime's result.     Save and restore the contents of the buffer used for localtime's result    around the call to gettimeofday.  */
end_comment

begin_function
name|int
name|rpl_gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|timezone
modifier|*
name|tz
parameter_list|)
block|{
name|struct
name|tm
name|save
decl_stmt|;
name|int
name|result
decl_stmt|;
if|if
condition|(
operator|!
name|localtime_buffer_addr
condition|)
block|{
name|time_t
name|t
init|=
literal|0
decl_stmt|;
name|localtime_buffer_addr
operator|=
name|localtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
block|}
name|save
operator|=
operator|*
name|localtime_buffer_addr
expr_stmt|;
name|result
operator|=
name|gettimeofday
argument_list|(
name|tv
argument_list|,
name|tz
argument_list|)
expr_stmt|;
operator|*
name|localtime_buffer_addr
operator|=
name|save
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/* This is a wrapper for tzset. It is used only on systems for which    tzset may clobber the static buffer used for localtime's result.    Save and restore the contents of the buffer used for localtime's    result around the call to tzset.  */
end_comment

begin_function
name|void
name|rpl_tzset
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|tm
name|save
decl_stmt|;
if|if
condition|(
operator|!
name|localtime_buffer_addr
condition|)
block|{
name|time_t
name|t
init|=
literal|0
decl_stmt|;
name|localtime_buffer_addr
operator|=
name|localtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
block|}
name|save
operator|=
operator|*
name|localtime_buffer_addr
expr_stmt|;
name|tzset
argument_list|()
expr_stmt|;
operator|*
name|localtime_buffer_addr
operator|=
name|save
expr_stmt|;
block|}
end_function

end_unit

