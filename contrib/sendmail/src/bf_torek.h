begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: bf_torek.h,v 8.6 1999/11/04 19:31:25 ca Exp $  *  * Contributed by Exactis.com, Inc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BF_TOREK_H
end_ifndef

begin_define
define|#
directive|define
name|BF_TOREK_H
value|1
end_define

begin_comment
comment|/* **  Data structure for storing information about each buffered file */
end_comment

begin_struct
struct|struct
name|bf
block|{
name|bool
name|bf_committed
decl_stmt|;
comment|/* Has this buffered file been committed? */
name|bool
name|bf_ondisk
decl_stmt|;
comment|/* On disk: committed or buffer overflow */
name|int
name|bf_flags
decl_stmt|;
name|int
name|bf_disk_fd
decl_stmt|;
comment|/* If on disk, associated file descriptor */
name|char
modifier|*
name|bf_buf
decl_stmt|;
comment|/* Memory buffer */
name|int
name|bf_bufsize
decl_stmt|;
comment|/* Length of above buffer */
name|int
name|bf_buffilled
decl_stmt|;
comment|/* Bytes of buffer actually filled */
name|char
modifier|*
name|bf_filename
decl_stmt|;
comment|/* Name of buffered file, if ever committed */
name|mode_t
name|bf_filemode
decl_stmt|;
comment|/* Mode of buffered file, if ever committed */
name|fpos_t
name|bf_offset
decl_stmt|;
comment|/* Currect file offset */
name|int
name|bf_size
decl_stmt|;
comment|/* Total current size of file */
name|int
name|bf_refcount
decl_stmt|;
comment|/* Reference count */
block|}
struct|;
end_struct

begin_comment
comment|/* Our lower-level I/O routines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_bfclose
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfread
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fpos_t
name|_bfseek
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|fpos_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfwrite
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BF_TOREK_H */
end_comment

end_unit

