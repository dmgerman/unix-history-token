begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/REPOSITORY/v3/include/sys/parsestreams.h,v 3.11 1994/01/25 19:04:30 kardel Exp  *  * parsestreams.h,v 3.11 1994/01/25 19:04:30 kardel Exp  *  * Copyright (c) 1989,1990,1991,1992,1993,1994  * Frank Kardel Friedrich-Alexander Universitaet Erlangen-Nuernberg  *                                     * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|lint
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|static
name|char
name|parse77hrcsid
index|[]
init|=
literal|"parsestreams.h,v 3.11 1994/01/25 19:04:30 kardel Exp"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|PARSEKERNEL
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PARSESTREAM
end_ifndef

begin_define
define|#
directive|define
name|PARSESTREAM
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
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
operator|&&
name|defined
argument_list|(
name|STREAM
argument_list|)
end_if

begin_define
define|#
directive|define
name|PARSEKERNEL
end_define

begin_include
include|#
directive|include
file|<sys/ppsclock.h>
end_include

begin_struct
struct|struct
name|parsestream
comment|/* parse module local data */
block|{
name|queue_t
modifier|*
name|parse_queue
decl_stmt|;
comment|/* read stream for this channel */
name|queue_t
modifier|*
name|parse_dqueue
decl_stmt|;
comment|/* driver queue entry (PPS support) */
name|unsigned
name|long
name|parse_status
decl_stmt|;
comment|/* operation flags */
name|void
modifier|*
name|parse_data
decl_stmt|;
comment|/* local data space (PPS support) */
name|parse_t
name|parse_io
decl_stmt|;
comment|/* io structure */
name|struct
name|ppsclockev
name|parse_ppsclockev
decl_stmt|;
comment|/* copy of last pps event */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|parsestream
name|parsestream_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PARSE_ENABLE
value|0x0001
end_define

begin_comment
comment|/*--------------- debugging support ---------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_DCF
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|parsedebug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DD_OPEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DD_CLOSE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DD_RPUT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DD_WPUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DD_RSVC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DD_PARSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DD_INSTALL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DD_ISR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DD_RAWDCF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|if ((X)& parsedebug) printf Y
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

