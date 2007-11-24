begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: misc.h,v 1.1 2006/06/28 23:57:59 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|SM_MISC_H
value|1
end_define

begin_decl_stmt
name|int
name|sm_memstat_open
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_memstat_close
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_memstat_get
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
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
comment|/* ! SM_MISC_H */
end_comment

end_unit

