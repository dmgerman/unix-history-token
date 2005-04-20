begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sfsasl.h,v 8.17 2000/09/19 21:30:49 ca Exp $"  */
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
name|SASL
end_if

begin_decl_stmt
specifier|extern
name|int
name|sfdcsasl
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|*
operator|,
name|SM_FILE_T
operator|*
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
comment|/* SASL */
end_comment

begin_if
if|#
directive|if
name|STARTTLS
end_if

begin_decl_stmt
specifier|extern
name|int
name|sfdctls
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|*
operator|,
name|SM_FILE_T
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

