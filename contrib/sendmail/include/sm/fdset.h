begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001, 2002 Proofpoint, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: fdset.h,v 1.6 2013-11-22 20:51:31 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_FDSET_H
end_ifndef

begin_define
define|#
directive|define
name|SM_FDSET_H
end_define

begin_comment
comment|/* **  Note: SM_FD_OK_SELECT(fd) requires that ValidSocket(fd) has been checked **	before. */
end_comment

begin_define
define|#
directive|define
name|SM_FD_SET
parameter_list|(
name|fd
parameter_list|,
name|pfdset
parameter_list|)
value|FD_SET(fd, pfdset)
end_define

begin_define
define|#
directive|define
name|SM_FD_ISSET
parameter_list|(
name|fd
parameter_list|,
name|pfdset
parameter_list|)
value|FD_ISSET(fd, pfdset)
end_define

begin_define
define|#
directive|define
name|SM_FD_SETSIZE
value|FD_SETSIZE
end_define

begin_define
define|#
directive|define
name|SM_FD_OK_SELECT
parameter_list|(
name|fd
parameter_list|)
value|(FD_SETSIZE<= 0 || (fd)< FD_SETSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_FDSET_H */
end_comment

end_unit

