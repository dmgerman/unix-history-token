begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_conf.c - reference clock configuration  */
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
name|CLOCK_LOCAL
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_TRAK
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_PST
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_CHU
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_WWV
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_wwv
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_wwv
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_SPECTRACOM
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_PARSE
end_ifdef

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
name|CLOCK_MX4200
argument_list|)
operator|&&
name|defined
argument_list|(
name|PPS
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_AS2201
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ARBITER
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_arbiter
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_arbiter
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_TPRO
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_LEITCH
end_ifdef

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
name|CLOCK_IRIG
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
name|CLOCK_MSFEES
argument_list|)
operator|&&
name|defined
argument_list|(
name|PPS
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_BANC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_bancomm
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_bancomm
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_TRUETIME
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_true
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_true
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_DATUM
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_datum
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_datum
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ACTS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_acts
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_acts
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_HEATH
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_heath
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_heath
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_NMEA
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_nmea
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_nmea
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ATOM
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_atom
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_atom
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_PTBACTS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_ptb
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_ptb
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_USNO
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_usno
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_usno
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_HPGPS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_hpgps
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_hpgps
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_GPSVME
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_gpsvme
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_gpsvme
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ARCRON_MSF
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_arc
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_arc
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_SHM
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_shm
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_shm
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_PALISADE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_palisade
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_palisade
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ONCORE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_oncore
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_oncore
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
name|CLOCK_JUPITER
argument_list|)
operator|&&
name|defined
argument_list|(
name|PPS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_jupiter
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_jupiter
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
name|CLOCK_CHRONOLOG
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_chronolog
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_chronolog
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
name|CLOCK_DUMBCLOCK
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_dumbclock
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_dumbclock
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_ULINK
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_ulink
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_ulink
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_PCF
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_pcf
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_pcf
value|refclock_none
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLOCK_FG
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|refclock
name|refclock_fg
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|refclock_fg
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
comment|/* 4 REFCLK_SPECTRACOM */
operator|&
name|refclock_true
block|,
comment|/* 5 REFCLK_TRUETIME */
operator|&
name|refclock_irig
block|,
comment|/* 6 REFCLK_IRIG_AUDIO */
operator|&
name|refclock_chu
block|,
comment|/* 7 REFCLK_CHU_AUDIO */
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
name|refclock_arbiter
block|,
comment|/* 11 REFCLK_GPS_ARBITER */
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
name|refclock_true
block|,
comment|/* 15 alias for REFCLK_TRUETIME */
operator|&
name|refclock_bancomm
block|,
comment|/* 16 REFCLK_IRIG_BANCOMM */
operator|&
name|refclock_datum
block|,
comment|/* 17 REFCLK_GPS_DATUM */
operator|&
name|refclock_acts
block|,
comment|/* 18 REFCLK_NIST_ACTS */
operator|&
name|refclock_heath
block|,
comment|/* 19 REFCLK_WWV_HEATH */
operator|&
name|refclock_nmea
block|,
comment|/* 20 REFCLK_GPS_NMEA */
operator|&
name|refclock_gpsvme
block|,
comment|/* 21 REFCLK_GPS_VME */
operator|&
name|refclock_atom
block|,
comment|/* 22 REFCLK_ATOM_PPS */
operator|&
name|refclock_ptb
block|,
comment|/* 23 REFCLK_PTB_ACTS */
operator|&
name|refclock_usno
block|,
comment|/* 24 REFCLK_USNO */
operator|&
name|refclock_true
block|,
comment|/* 25 alias for REFCLK_TRUETIME */
operator|&
name|refclock_hpgps
block|,
comment|/* 26 REFCLK_GPS_HP */
operator|&
name|refclock_arc
block|,
comment|/* 27 REFCLK_ARCRON_MSF */
operator|&
name|refclock_shm
block|,
comment|/* 28 REFCLK_SHM */
operator|&
name|refclock_palisade
block|,
comment|/* 29 REFCLK_PALISADE */
operator|&
name|refclock_oncore
block|,
comment|/* 30 REFCLK_ONCORE */
operator|&
name|refclock_jupiter
block|,
comment|/* 31 REFCLK_GPS_JUPITER */
operator|&
name|refclock_chronolog
block|,
comment|/* 32 REFCLK_CHRONOLOG */
operator|&
name|refclock_dumbclock
block|,
comment|/* 33 REFCLK_DUMBCLOCK */
operator|&
name|refclock_ulink
block|,
comment|/* 34 REFCLOCK_ULINK */
operator|&
name|refclock_pcf
block|,
comment|/* 35 REFCLOCK_PCF */
operator|&
name|refclock_wwv
block|,
comment|/* 36 REFCLOCK_WWV_AUDIO */
operator|&
name|refclock_fg
comment|/* 37 REFCLOCK_FG */
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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_conf_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

