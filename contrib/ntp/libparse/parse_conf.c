begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/libparse/parse_conf.c,v 4.5 1999/11/28 09:13:53 kardel RELEASE_19991128_A  *    * parse_conf.c,v 4.5 1999/11/28 09:13:53 kardel RELEASE_19991128_A  *  * Parser configuration module for reference clocks  *  * STREAM define switches between two personalities of the module  * if STREAM is defined this module can be used with dcf77sync.c as  * a STREAMS kernel module. In this case the time stamps will be  * a struct timeval.  * when STREAM is not defined NTP time stamps will be used.  *  * Copyright (C) 1995-1998 by Frank Kardel  * Copyright (C) 1992-1994 by Frank Kardel, Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_PARSE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
name|CLOCK_TRIMTAIP
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_trimtaip
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_TRIMTSIP
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_trimtsip
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_RCC8000
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_rcc8000
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_HOPF6021
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_hopf6021
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_COMPUTIME
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_computime
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_WHARTON_400A
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_wharton_400a
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_VARITEXT
end_ifdef

begin_decl_stmt
specifier|extern
name|clockformat_t
name|clock_varitext
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
name|CLOCK_TRIMTAIP
operator|&
name|clock_trimtaip
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_TRIMTSIP
operator|&
name|clock_trimtsip
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_RCC8000
operator|&
name|clock_rcc8000
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_HOPF6021
operator|&
name|clock_hopf6021
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_COMPUTIME
operator|&
name|clock_computime
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_WHARTON_400A
operator|&
name|clock_wharton_400a
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CLOCK_VARITEXT
operator|&
name|clock_varitext
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE) */
end_comment

begin_decl_stmt
name|int
name|parse_conf_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (REFCLOCK&& CLOCK_PARSE) */
end_comment

begin_comment
comment|/*  * History:  *  * parse_conf.c,v  * Revision 4.5  1999/11/28 09:13:53  kardel  * RECON_4_0_98F  *  * Revision 4.4  1999/02/28 15:27:25  kardel  * wharton clock integration  *  * Revision 4.3  1998/08/16 18:52:15  kardel  * (clockformats): Trimble TSIP driver now also  * available for kernel operation  *  * Revision 4.2  1998/06/12 09:13:48  kardel  * conditional compile macros fixed  *  * Revision 4.1  1998/05/24 09:40:49  kardel  * adjustments of log messages  *  *  * from V3 3.24 log info deleted 1998/04/11 kardel  */
end_comment

end_unit

