begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)dir.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* dir.h --  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIR
end_ifndef

begin_define
define|#
directive|define
name|_DIR
end_define

begin_typedef
typedef|typedef
struct|struct
name|Path
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of directory */
name|int
name|refCount
decl_stmt|;
comment|/* Number of paths with this directory */
name|int
name|hits
decl_stmt|;
comment|/* the number of times a file in this 				 * directory has been found */
name|Hash_Table
name|files
decl_stmt|;
comment|/* Hash table of files in directory */
block|}
name|Path
typedef|;
end_typedef

begin_decl_stmt
name|void
name|Dir_AddDir
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_ClearPath
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Concat
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ClientData
name|Dir_CopyDir
name|__P
argument_list|(
operator|(
name|Path
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Destroy
name|__P
argument_list|(
operator|(
name|Path
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Expand
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dir_FindFile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Dir_HasWildcards
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dir_MakeFlags
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Dir_MTime
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_PrintDirectories
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_PrintPath
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIR */
end_comment

end_unit

