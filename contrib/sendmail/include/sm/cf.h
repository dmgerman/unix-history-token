begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: cf.h,v 1.2 2001/03/08 03:23:07 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CF_H
end_ifndef

begin_define
define|#
directive|define
name|SM_CF_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|opt_name
decl_stmt|;
name|char
modifier|*
name|opt_val
decl_stmt|;
block|}
name|SM_CF_OPT_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sm_cf_getopt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
name|int
name|optc
operator|,
name|SM_CF_OPT_T
operator|*
name|optv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_CF_H */
end_comment

end_unit

