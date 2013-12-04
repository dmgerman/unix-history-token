begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_INTRES_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_INTRES_H
end_define

begin_comment
comment|/*  * Some systems do not support fork() and don't have an alternate  * threads implementation of ntp_intres.  Such systems are limited  * to using numeric IP addresses.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
operator|||
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|HAVE_WORKING_FORK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|NO_INTRES
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
comment|/* !defined(NTP_INTRES_H) */
end_comment

end_unit

