begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  * $Id: facpri.h,v 1.3.2.1 2001/06/26 10:43:11 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FACPRI_H__
end_ifndef

begin_define
define|#
directive|define
name|__FACPRI_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|P_DEF
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fac_toname
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fac_findname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pri_toname
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pri_findname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|P_DEF
end_ifdef

begin_undef
undef|#
directive|undef
name|__P
end_undef

begin_undef
undef|#
directive|undef
name|P_DEF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LOG_CRON
operator|==
operator|(
literal|9
operator|<<
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|LOG_CRON1
value|LOG_CRON
end_define

begin_define
define|#
directive|define
name|LOG_CRON2
value|(15<<3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LOG_CRON
operator|==
operator|(
literal|15
operator|<<
literal|3
operator|)
end_if

begin_define
define|#
directive|define
name|LOG_CRON1
value|(9<<3)
end_define

begin_define
define|#
directive|define
name|LOG_CRON2
value|LOG_CRON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FACPRI_H__ */
end_comment

end_unit

