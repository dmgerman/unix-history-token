begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: path.h,v 1.6 2001/04/03 01:53:00 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  Portable names for standard filesystem paths **  and macros for directories. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_PATH_H
end_ifndef

begin_define
define|#
directive|define
name|SM_PATH_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_define
define|#
directive|define
name|SM_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|SM_IS_DIR_DELIM
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_define
define|#
directive|define
name|SM_FIRST_DIR_DELIM
parameter_list|(
name|s
parameter_list|)
value|strchr(s, '/')
end_define

begin_define
define|#
directive|define
name|SM_LAST_DIR_DELIM
parameter_list|(
name|s
parameter_list|)
value|strrchr(s, '/')
end_define

begin_comment
comment|/* Warning: this must be accessible as array */
end_comment

begin_define
define|#
directive|define
name|SM_IS_DIR_START
parameter_list|(
name|s
parameter_list|)
value|((s)[0] == '/')
end_define

begin_define
define|#
directive|define
name|sm_path_isdevnull
parameter_list|(
name|path
parameter_list|)
value|(strcmp(path, "/dev/null") == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_PATH_H */
end_comment

end_unit

