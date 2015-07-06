begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|UNBOUND_DNSTAP_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|UNBOUND_DNSTAP_CONFIG_H
end_define

begin_comment
comment|/*  * Process this file (dnstap_config.h.in) with AC_CONFIG_FILES to generate  * dnstap_config.h.  *  * This file exists so that USE_DNSTAP can be used without including config.h.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ENABLE_DNSTAP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_DNSTAP
end_ifndef

begin_define
define|#
directive|define
name|USE_DNSTAP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNBOUND_DNSTAP_CONFIG_H */
end_comment

end_unit

