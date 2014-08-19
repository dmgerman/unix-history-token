begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Proofpoint, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_unicosmp.h,v 1.2 2013-11-22 20:51:34 ca Exp $  */
end_comment

begin_comment
comment|/* **  Cray UNICOS/mp */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"unicosmp"
end_define

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_SYS_CDEFS_H
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_MSG
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_SHM
value|1
end_define

begin_define
define|#
directive|define
name|SM_CONF_SEM
value|1
end_define

end_unit

