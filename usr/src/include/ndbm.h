begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * %sccs.include.redist.c%  *  *	@(#)ndbm.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NDBM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NDBM_H_
end_define

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_comment
comment|/* Map dbm interface onto db(3). */
end_comment

begin_define
define|#
directive|define
name|DBM_RDONLY
value|O_RDONLY
end_define

begin_comment
comment|/* Flags to dbm_store(). */
end_comment

begin_define
define|#
directive|define
name|DBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_comment
comment|/*  * The db(3) support for ndbm(3) always appends this suffix to the  * file name to avoid overwriting the user's original database.  */
end_comment

begin_define
define|#
directive|define
name|DBM_SUFFIX
value|".db"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DB
name|DBM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dbm_pagfno
parameter_list|(
name|a
parameter_list|)
value|DBM_PAGFNO_NOT_AVAILABLE
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|dbm_close
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbm_delete
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|dbm_fetch
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|dbm_firstkey
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dbm_forder
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|datum
name|dbm_nextkey
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DBM
modifier|*
name|dbm_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbm_store
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|,
name|datum
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbm_dirfno
name|__P
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NDBM_H_ */
end_comment

end_unit

