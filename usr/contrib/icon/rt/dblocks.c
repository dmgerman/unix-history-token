begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * Heap block size table (sizes given in bytes).  A size of -1 is used  *  for types that have no heap blocks; a size of 0 indicates that the  *  second word of the block contains the size; a value greater than  *  0 is used for types with constant sized blocks.  */
end_comment

begin_decl_stmt
name|int
name|bsizes
index|[]
init|=
block|{
operator|-
literal|1
block|,
comment|/* 0, not used */
operator|-
literal|1
block|,
comment|/* 1, not used */
sizeof|sizeof
argument_list|(
expr|struct
name|b_int
argument_list|)
block|,
comment|/* T_LONGINT (2), long integer type */
sizeof|sizeof
argument_list|(
expr|struct
name|b_real
argument_list|)
block|,
comment|/* T_REAL (3), real number */
sizeof|sizeof
argument_list|(
expr|struct
name|b_cset
argument_list|)
block|,
comment|/* T_CSET (4), cset */
sizeof|sizeof
argument_list|(
expr|struct
name|b_file
argument_list|)
block|,
comment|/* T_FILE (5), file block */
literal|0
block|,
comment|/* T_PROC (6), procedure block */
sizeof|sizeof
argument_list|(
expr|struct
name|b_list
argument_list|)
block|,
comment|/* T_LIST (7), list header block */
sizeof|sizeof
argument_list|(
expr|struct
name|b_table
argument_list|)
block|,
comment|/* T_TABLE (8), table header block */
literal|0
block|,
comment|/* T_RECORD (9), record block */
sizeof|sizeof
argument_list|(
expr|struct
name|b_telem
argument_list|)
block|,
comment|/* T_TELEM (10), table element block */
literal|0
block|,
comment|/* T_LELEM (11), list element block */
sizeof|sizeof
argument_list|(
expr|struct
name|b_tvsubs
argument_list|)
block|,
comment|/* T_TVSUBS (12), substring trapped variable */
operator|-
literal|1
block|,
comment|/* 13, not used */
sizeof|sizeof
argument_list|(
expr|struct
name|b_tvtbl
argument_list|)
block|,
comment|/* T_TVTBL (14), table element trapped variable */
operator|-
literal|1
block|,
comment|/* T_TVPOS (15),&pos trapped variable */
operator|-
literal|1
block|,
comment|/* T_TVRAND (16),&random trapped variable */
operator|-
literal|1
block|,
comment|/* T_TVTACE (17),&trace trapped variable */
operator|-
literal|1
block|,
comment|/* T_ESTACK (18), expression stack header */
literal|0
comment|/* T_EBLOCK (19), expression heap block */
ifdef|#
directive|ifdef
name|SETS
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_set
argument_list|)
block|,
comment|/* T_SET  (20), set header block */
expr|sizeof
operator|(
expr|struct
name|b_selem
operator|)
comment|/* T_SELEM  (21), set element block */
endif|#
directive|endif
endif|SETS
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Table of offsets (in bytes) to first descriptor in blocks.  -1 is for  *  non-heap types, 0 for blocks with no descriptors.  */
end_comment

begin_decl_stmt
name|int
name|firstd
index|[]
init|=
block|{
operator|-
literal|1
block|,
comment|/* 0, not used */
operator|-
literal|1
block|,
comment|/* 1, not used */
literal|0
block|,
comment|/* T_LONGINT (2), long integer type */
literal|0
block|,
comment|/* T_REAL (3), real number */
literal|0
block|,
comment|/* T_CSET (4), cset */
literal|3
operator|*
name|WORDSIZE
block|,
comment|/* T_FILE (5), file block */
literal|7
operator|*
name|WORDSIZE
block|,
comment|/* T_PROC (6), procedure block */
literal|2
operator|*
name|WORDSIZE
block|,
comment|/* T_LIST (7), list header block */
literal|2
operator|*
name|WORDSIZE
block|,
comment|/* T_TABLE (8), table header block */
literal|3
operator|*
name|WORDSIZE
block|,
comment|/* T_RECORD (9), record block */
literal|2
operator|*
name|WORDSIZE
block|,
comment|/* T_TELEM (10), table element block */
literal|5
operator|*
name|WORDSIZE
block|,
comment|/* T_LELEM (11), list element block */
literal|3
operator|*
name|WORDSIZE
block|,
comment|/* T_TVSUBS (12), substring trapped variable */
operator|-
literal|1
block|,
comment|/* 13, not used */
literal|2
operator|*
name|WORDSIZE
block|,
comment|/* T_TVTBL (14), table element trapped variable */
operator|-
literal|1
block|,
comment|/* T_TVPOS (15),&pos trapped variable */
operator|-
literal|1
block|,
comment|/* T_TVRAND (16),&random trapped variable*/
operator|-
literal|1
block|,
comment|/* T_TVTACE (17),&trace trapped variable */
operator|-
literal|1
block|,
comment|/* T_ESTACK (18), expression stack header */
literal|5
operator|*
name|WORDSIZE
comment|/* T_EBLOCK (19), expression heap block */
ifdef|#
directive|ifdef
name|SETS
block|,
literal|2
operator|*
name|WORDSIZE
block|,
comment|/* T_SET  (20), set header block */
literal|2
operator|*
name|WORDSIZE
comment|/* T_SELEM  (21), set element block */
endif|#
directive|endif
endif|SETS
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Table of block names used by debugging functions.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|blkname
index|[]
init|=
block|{
literal|"illegal name"
block|,
comment|/* 0, not used */
literal|"illegal name"
block|,
comment|/* 1, not used */
literal|"long integer"
block|,
comment|/* T_LONGINT (2), long integer type */
literal|"real number"
block|,
comment|/* T_REAL (3), real number */
literal|"cset"
block|,
comment|/* T_CSET (4), cset */
literal|"file"
block|,
comment|/* T_FILE (5), file block */
literal|"procedure"
block|,
comment|/* T_PROC (6), procedure block */
literal|"list header block"
block|,
comment|/* T_LIST (7), list header block */
literal|"table header block"
block|,
comment|/* T_TABLE  (8), table header block */
literal|"record"
block|,
comment|/* T_RECORD (9), record block */
literal|"table element block"
block|,
comment|/* T_TELEM (10), table element block  */
literal|"list element block"
block|,
comment|/* T_LELEM (11), list element block */
literal|"substring tv"
block|,
comment|/* T_TVSUBS (12), substring trapped variable */
literal|"illegal name"
block|,
comment|/* 13, not used */
literal|"table element tv"
block|,
comment|/* T_TVTBL (14), table element trapped variable */
literal|"illegal name"
block|,
comment|/* T_TVPOS (15),&pos trapped variable */
literal|"illegal name"
block|,
comment|/* T_TVRAND (16),&random trapped variable */
literal|"illegal name"
block|,
comment|/* T_TVTACE (17),&trace trapped variable */
literal|"expression stack"
block|,
comment|/* T_ESTACK (18), expression stack header */
literal|"refresh block"
comment|/* T_EBLOCK (19), expression heap block */
ifdef|#
directive|ifdef
name|SETS
block|,
literal|"set header block"
block|,
comment|/* T_SET  (20), set header block */
literal|"set member"
comment|/* T_SELEM  (21), set element block */
endif|#
directive|endif
endif|SETS
block|}
decl_stmt|;
end_decl_stmt

end_unit

