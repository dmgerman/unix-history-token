begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|PARSE
argument_list|)
operator|||
name|defined
argument_list|(
name|PARSEPPS
argument_list|)
operator|)
end_if

begin_comment
comment|/*  * /src/NTP/REPOSITORY/v3/parse/parse_conf.c,v 3.15 1994/02/02 17:45:32 kardel Exp  *    * parse_conf.c,v 3.15 1994/02/02 17:45:32 kardel Exp  *  * Parser configuration module for reference clocks  *  * STREAM define switches between two personalities of the module  * if STREAM is defined this module can be used with dcf77sync.c as  * a STREAMS kernel module. In this case the time stamps will be  * a struct timeval.  * when STREAM is not defined NTP time stamps will be used.  *  * Copyright (c) 1992,1993,1994  * Frank Kardel Friedrich-Alexander Universitaet Erlangen-Nuernberg  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_include
include|#
directive|include
file|"sys/time.h"
end_include

begin_include
include|#
directive|include
file|"sys/errno.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"parse.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_SCHMID
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_schmid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_DCF7000
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_dcf7000
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_MEINBERG
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_meinberg
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_RAWDCF
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_rawdcf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_TRIMSV6
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_trimsv6
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * format definitions  */
end_comment

begin_decl_stmt
name|clockformat_t
modifier|*
name|clockformats
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|CLOCK_MEINBERG
operator|&
name|clock_meinberg
index|[
literal|0
index|]
block|,
operator|&
name|clock_meinberg
index|[
literal|1
index|]
block|,
operator|&
name|clock_meinberg
index|[
literal|2
index|]
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_DCF7000
operator|&
name|clock_dcf7000
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_SCHMID
operator|&
name|clock_schmid
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_RAWDCF
operator|&
name|clock_rawdcf
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_TRIMSV6
operator|&
name|clock_trimsv6
block|,
endif|#
directive|endif
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|nformats
init|=
sizeof|sizeof
argument_list|(
name|clockformats
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|clockformats
index|[
literal|0
index|]
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK PARSE */
end_comment

begin_comment
comment|/*  * History:  *  * parse_conf.c,v  * Revision 3.15  1994/02/02  17:45:32  kardel  * rcs ids fixed  *  * Revision 3.13  1994/01/25  19:05:23  kardel  * 94/01/23 reconcilation  *  * Revision 3.12  1994/01/23  17:22:02  kardel  * 1994 reconcilation  *  * Revision 3.11  1993/11/01  20:00:24  kardel  * parse Solaris support (initial version)  *  * Revision 3.10  1993/10/09  15:01:37  kardel  * file structure unified  *  * Revision 3.9  1993/09/26  23:40:19  kardel  * new parse driver logic  *  * Revision 3.8  1993/09/02  23:20:57  kardel  * dragon extiction  *  * Revision 3.7  1993/09/01  21:44:52  kardel  * conditional cleanup  *  * Revision 3.6  1993/09/01  11:25:09  kardel  * patch accident 8-(  *  * Revision 3.5  1993/08/31  22:31:14  kardel  * SINIX-M SysVR4 integration  *  * Revision 3.4  1993/08/27  00:29:42  kardel  * compilation cleanup  *  * Revision 3.3  1993/07/14  09:04:45  kardel  * only when REFCLOCK&& PARSE is defined  *  * Revision 3.2  1993/07/09  11:37:13  kardel  * Initial restructured version + GPS support  *  * Revision 3.1  1993/07/06  10:00:11  kardel  * DCF77 driver goes generic...  *  */
end_comment

end_unit

