begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)inline.h	1.2 (Berkeley) 2/24/86  */
end_comment

begin_comment
comment|/*  * COMMENTCHAR is the character delimiting comments in the assembler.  * LABELCHAR is the character that separates labels from instructions.  * ARGSEPCHAR is the character that separates arguments in instructions.  */
end_comment

begin_define
define|#
directive|define
name|COMMENTCHAR
value|'#'
end_define

begin_define
define|#
directive|define
name|LABELCHAR
value|':'
end_define

begin_define
define|#
directive|define
name|ARGSEPCHAR
value|','
end_define

begin_comment
comment|/*  * Expansion parameters:  *   QUEUESIZE is the number of instructions to be considered for   *	integration of argument pushes and pops  *   MAXLINELEN is the longest expected input line  *   MAXARGS is the maximum number of arguments in an assembly instruction  */
end_comment

begin_define
define|#
directive|define
name|QUEUESIZE
value|16
end_define

begin_define
define|#
directive|define
name|MAXLINELEN
value|128
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|10
end_define

begin_comment
comment|/*  * The following global variables are used to manipulate the queue of  * recently seen instructions.  *	line - The queue of instructions.  *	bufhead - Pointer to next availble queue slot. It is not  *		considered part of te instruction stream until  *		bufhead is advanced.  *	buftail - Pointer to last instruction in queue.  * Note that bufhead == buftail implies that the queue is empty.  */
end_comment

begin_decl_stmt
name|int
name|bufhead
decl_stmt|,
name|buftail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|line
index|[
name|QUEUESIZE
index|]
index|[
name|MAXLINELEN
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SUCC
parameter_list|(
name|qindex
parameter_list|)
value|((qindex) + 1 == QUEUESIZE ? 0 : (qindex) + 1)
end_define

begin_define
define|#
directive|define
name|PRED
parameter_list|(
name|qindex
parameter_list|)
value|((qindex) - 1< 0 ? QUEUESIZE - 1 : (qindex) - 1)
end_define

begin_comment
comment|/*  * Hash table headers should be twice as big as the number of patterns.  * They must be a power of two.  */
end_comment

begin_define
define|#
directive|define
name|HSHSIZ
value|128
end_define

begin_comment
comment|/*  * These tables specify the substitutions that are to be done.  */
end_comment

begin_struct
struct|struct
name|pats
block|{
name|int
name|args
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|replace
decl_stmt|;
name|struct
name|pats
modifier|*
name|next
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|pats
modifier|*
name|patshdr
index|[
name|HSHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pats
name|language_ptab
index|[]
decl_stmt|,
name|libc_ptab
index|[]
decl_stmt|,
name|machine_ptab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This table defines the set of instructions that demark the  * end of a basic block.  */
end_comment

begin_struct
struct|struct
name|inststoptbl
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|inststoptbl
modifier|*
name|next
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|inststoptbl
modifier|*
name|inststoptblhdr
index|[
name|HSHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inststoptbl
name|inststoptable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Miscellaneous functions.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|newline
argument_list|()
decl_stmt|,
modifier|*
name|copyline
argument_list|()
decl_stmt|,
modifier|*
name|doreplaceon
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

