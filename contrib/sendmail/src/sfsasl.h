begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sfsasl.h,v 8.13.4.4 2000/07/18 18:44:51 gshapiro Exp $"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SFSASL_H
end_ifndef

begin_define
define|#
directive|define
name|SFSASL_H
end_define

begin_if
if|#
directive|if
name|SFIO
end_if

begin_include
include|#
directive|include
file|<sfio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_if
if|#
directive|if
name|SASL
end_if

begin_if
if|#
directive|if
name|SFIO
end_if

begin_comment
comment|/* sf discipline to add sasl */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_sasldisc
block|{
name|Sfdisc_t
name|disc
decl_stmt|;
name|sasl_conn_t
modifier|*
name|conn
decl_stmt|;
block|}
name|Sasldisc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sfdcsasl
name|__P
argument_list|(
operator|(
name|Sfio_t
operator|*
operator|,
name|Sfio_t
operator|*
operator|,
name|sasl_conn_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SASL */
end_comment

begin_if
if|#
directive|if
name|STARTTLS
end_if

begin_if
if|#
directive|if
name|SFIO
end_if

begin_comment
comment|/* sf discipline to add tls */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_tlsdisc
block|{
name|Sfdisc_t
name|disc
decl_stmt|;
name|SSL
modifier|*
name|con
decl_stmt|;
block|}
name|Tlsdisc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sfdctls
name|__P
argument_list|(
operator|(
name|Sfio_t
operator|*
operator|,
name|Sfio_t
operator|*
operator|,
name|SSL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SFIO */
end_comment

begin_if
if|#
directive|if
name|_FFR_TLS_TOREK
end_if

begin_typedef
typedef|typedef
struct|struct
name|tls_conn
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* original FILE * */
name|SSL
modifier|*
name|con
decl_stmt|;
comment|/* SSL context */
block|}
name|Tlsdisc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sfdctls
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|*
operator|,
name|FILE
operator|*
operator|*
operator|,
name|SSL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_TLS_TOREK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STARTTLS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SFSASL_H */
end_comment

end_unit

