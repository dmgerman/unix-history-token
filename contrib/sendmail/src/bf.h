begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: bf.h,v 8.15 2001/05/31 21:02:53 ca Exp $  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BF_H
end_ifndef

begin_define
define|#
directive|define
name|BF_H
value|1
end_define

begin_decl_stmt
specifier|extern
name|SM_FILE_T
modifier|*
name|bfopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MODE_T
operator|,
name|size_t
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
modifier|*
name|bfdup
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bfcommit
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bfrewind
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bftruncate
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bfclose
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|bftest
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "what" flags for sm_io_setinfo() for the SM_FILE_TYPE file type */
end_comment

begin_define
define|#
directive|define
name|SM_BF_SETBUFSIZE
value|1000
end_define

begin_comment
comment|/* set buffer size */
end_comment

begin_define
define|#
directive|define
name|SM_BF_COMMIT
value|1001
end_define

begin_comment
comment|/* commit file to disk */
end_comment

begin_define
define|#
directive|define
name|SM_BF_TRUNCATE
value|1002
end_define

begin_comment
comment|/* truncate the file */
end_comment

begin_define
define|#
directive|define
name|SM_BF_TEST
value|1003
end_define

begin_comment
comment|/* historical support; temp */
end_comment

begin_define
define|#
directive|define
name|BF_FILE_TYPE
value|"SendmailBufferedFile"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BF_H */
end_comment

end_unit

