begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2003, 2006 Proofpoint, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: milter.h,v 8.42 2013-11-22 20:51:27 ca Exp $  */
end_comment

begin_comment
comment|/* **  MILTER.H -- Global definitions for mail filter. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_MILTER_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_MILTER_H
value|1
end_define

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_include
include|#
directive|include
file|"libmilter/mfapi.h"
end_include

begin_comment
comment|/* socket and thread portability */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_t
name|sthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|socket_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _LIBMILTER_MILTER_H */
end_comment

end_unit

