begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_types.h,v 3.1 1993/07/06 01:07:00 jbj Exp  *  ntp_types.h - defines how LONG and U_LONG are treated.  For 64 bit systems  *  like the DEC Alpha, they has to be defined as int and u_int.  for 32 bit  *  systems, define them as long and u_long  */
end_comment

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_NTP_TYPES_
end_ifndef

begin_define
define|#
directive|define
name|_NTP_TYPES_
end_define

begin_comment
comment|/*  * This is another naming conflict.  * On NetBSD for MAC the macro "mac" is defined as 1  * this is fun for a as a paket structure contains an  * optional "mac" member - severe confusion results 8-)  * As we hopefully do not have to rely on that macro we  * just undefine that.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mac
end_ifdef

begin_undef
undef|#
directive|undef
name|mac
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Set up for prototyping  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ USE_PROTOTYPES */
end_comment

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* const */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ USE_PROTOTYPES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* P */
end_comment

begin_comment
comment|/*  * DEC Alpha systems need LONG and U_LONG defined as int and u_int  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LONG
end_ifndef

begin_define
define|#
directive|define
name|LONG
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|U_LONG
end_ifndef

begin_define
define|#
directive|define
name|U_LONG
value|u_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* U_LONG */
end_comment

begin_comment
comment|/*  *  All other systems fall into this part  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __alpha */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LONG
end_ifndef

begin_define
define|#
directive|define
name|LONG
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|U_LONG
end_ifndef

begin_define
define|#
directive|define
name|U_LONG
value|u_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* U_LONG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ alplha */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTP_TYPES_ */
end_comment

end_unit

