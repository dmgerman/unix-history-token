begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Top - a top users display for Berkeley Unix  *  *  Defines required to access load average figures.  *  *  This include file sets up everything we need to access the load average  *  values in the kernel in a machine independent way.  First, it sets the  *  typedef "load_avg" to be either double or long (depending on what is  *  needed), then it defines these macros appropriately:  *  *	loaddouble(la) - convert load_avg to double.  *	intload(i)     - convert integer to load_avg.  */
end_comment

begin_comment
comment|/*  * We assume that if FSCALE is defined, then avenrun and ccpu are type long.  * If your machine is an exception (mips, perhaps?) then make adjustments  * here.  *  * Defined types:  load_avg for load averages, pctcpu for cpu percentages.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NetBSD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/fixpoint.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FBITS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FSCALE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FSCALE
value|(1<< FBITS)
end_define

begin_comment
comment|/* mips */
end_comment

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
name|FSCALE
end_ifdef

begin_define
define|#
directive|define
name|FIXED_LOADAVG
value|FSCALE
end_define

begin_define
define|#
directive|define
name|FIXED_PCTCPU
value|FSCALE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ibm032
end_ifdef

begin_undef
undef|#
directive|undef
name|FIXED_LOADAVG
end_undef

begin_undef
undef|#
directive|undef
name|FIXED_PCTCPU
end_undef

begin_define
define|#
directive|define
name|FIXED_PCTCPU
value|PCT_SCALE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FIXED_PCTCPU
end_ifdef

begin_typedef
typedef|typedef
name|long
name|pctcpu
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pctdouble
parameter_list|(
name|p
parameter_list|)
value|((double)(p) / FIXED_PCTCPU)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|pctcpu
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pctdouble
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FIXED_LOADAVG
end_ifdef

begin_typedef
typedef|typedef
name|fixpt_t
name|load_avg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|loaddouble
parameter_list|(
name|la
parameter_list|)
value|((double)(la) / FIXED_LOADAVG)
end_define

begin_define
define|#
directive|define
name|intload
parameter_list|(
name|i
parameter_list|)
value|((int)((i) * FIXED_LOADAVG))
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|load_avg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|loaddouble
parameter_list|(
name|la
parameter_list|)
value|(la)
end_define

begin_define
define|#
directive|define
name|intload
parameter_list|(
name|i
parameter_list|)
value|((double)(i))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

