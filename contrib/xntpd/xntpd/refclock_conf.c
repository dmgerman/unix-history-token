begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_conf.c - reference clock configuration  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|refclock
name|refclock_none
init|=
block|{
name|noentry
block|,
name|noentry
block|,
name|noentry
block|,
name|noentry
block|,
name|noentry
block|,
name|noentry
block|,
name|NOFLAGS
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOCAL_CLOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_local
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_local
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TRAK
argument_list|)
operator|||
name|defined
argument_list|(
name|TRAKCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|TRAKPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_trak
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_trak
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PST
argument_list|)
operator|||
name|defined
argument_list|(
name|PSTCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|PSTPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_pst
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_pst
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CHU
argument_list|)
operator|||
name|defined
argument_list|(
name|CHUCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|CHUPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_chu
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_chu
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GOES
argument_list|)
operator|||
name|defined
argument_list|(
name|GOESCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|GOESPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_goes
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_goes
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WWVB
argument_list|)
operator|||
name|defined
argument_list|(
name|WWVBCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|WWVBPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_wwvb
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_wwvb
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PARSE
argument_list|)
operator|||
name|defined
argument_list|(
name|PARSEPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_parse
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_parse
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MX4200
argument_list|)
operator|||
name|defined
argument_list|(
name|MX4200CLK
argument_list|)
operator|||
name|defined
argument_list|(
name|MX4200PPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_mx4200
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_mx4200
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AS2201
argument_list|)
operator|||
name|defined
argument_list|(
name|AS2201CLK
argument_list|)
operator|||
name|defined
argument_list|(
name|AS2201PPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_as2201
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_as2201
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OMEGA
argument_list|)
operator|||
name|defined
argument_list|(
name|OMEGACLK
argument_list|)
operator|||
name|defined
argument_list|(
name|OMEGAPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_omega
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_omega
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TPRO
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_tpro
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_tpro
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LEITCH
argument_list|)
operator|||
name|defined
argument_list|(
name|LEITCHCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|LEITCHPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_leitch
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_leitch
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IRIG
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_irig
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_irig
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSFEESPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_msfees
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_msfees
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GPSTM
argument_list|)
operator|||
name|defined
argument_list|(
name|GPSTMCLK
argument_list|)
operator|||
name|defined
argument_list|(
name|GPSTMPPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_gpstm
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_gpstm
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Order is clock_start(), clock_shutdown(), clock_poll(),  * clock_control(), clock_init(), clock_buginfo, clock_flags;  *  * Types are defined in ntp.h.  The index must match this.  */
end_comment

begin_decl_stmt
name|struct
name|refclock
modifier|*
name|refclock_conf
index|[]
init|=
block|{
operator|&
name|refclock_none
block|,
comment|/* 0 REFCLK_NONE */
operator|&
name|refclock_local
block|,
comment|/* 1 REFCLK_LOCAL */
operator|&
name|refclock_trak
block|,
comment|/* 2 REFCLK_GPS_TRAK */
operator|&
name|refclock_pst
block|,
comment|/* 3 REFCLK_WWV_PST */
operator|&
name|refclock_wwvb
block|,
comment|/* 4 REFCLK_WWVB_SPECTRACOM */
operator|&
name|refclock_goes
block|,
comment|/* 5 REFCLK_GOES_TRUETIME */
operator|&
name|refclock_irig
block|,
comment|/* 6 REFCLK_IRIG_AUDIO */
operator|&
name|refclock_chu
block|,
comment|/* 7 REFCLK_CHU */
operator|&
name|refclock_parse
block|,
comment|/* 8 REFCLK_PARSE */
operator|&
name|refclock_mx4200
block|,
comment|/* 9 REFCLK_GPS_MX4200 */
operator|&
name|refclock_as2201
block|,
comment|/* 10 REFCLK_GPS_AS2201 */
operator|&
name|refclock_omega
block|,
comment|/* 11 REFCLK_OMEGA_TRUETIME */
operator|&
name|refclock_tpro
block|,
comment|/* 12 REFCLK_IRIG_TPRO */
operator|&
name|refclock_leitch
block|,
comment|/* 13 REFCLK_ATOM_LEITCH */
operator|&
name|refclock_msfees
block|,
comment|/* 14 REFCLK_MSF_EES */
operator|&
name|refclock_gpstm
block|,
comment|/* 15 REFCLK_GPSTM_TRUETIME */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|num_refclock_conf
init|=
sizeof|sizeof
argument_list|(
name|refclock_conf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|refclock
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

