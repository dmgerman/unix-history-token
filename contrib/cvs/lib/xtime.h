begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_comment
comment|/* This file simply performs the include magic necessary for using time  * functions  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* vms */
end_comment

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

begin_comment
comment|/* TIME_WITH_SYS_TIME */
end_comment

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

begin_comment
comment|/* HAVE_SYS_TIME_H */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SYS_TIME_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !TIME_WITH_SYS_TIME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMEB_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_SYS_TIMEB_H */
end_comment

begin_comment
comment|/*  * We use the obsolete `struct timeb' as part of our interface!  * Since the system doesn't have it, we define it here;  * our callers must do likewise.  *  * At the least we were using this in lib/getdate.y, but lib/system.h used to  * define it too, so maybe CVS is using it elsewhere.  */
end_comment

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
comment|/* Seconds since the epoch	*/
name|unsigned
name|short
name|millitm
decl_stmt|;
comment|/* Field not used		*/
name|short
name|timezone
decl_stmt|;
comment|/* Minutes west of GMT		*/
name|short
name|dstflag
decl_stmt|;
comment|/* Field not used		*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SYS_TIMEB_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|timezone
end_ifdef

begin_undef
undef|#
directive|undef
name|timezone
end_undef

begin_comment
comment|/* needed for sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* timezone */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_FTIME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TIMEZONE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|long
name|timezone
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_FTIME)&& !defined(HAVE_TIMEZONE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !vms */
end_comment

end_unit

