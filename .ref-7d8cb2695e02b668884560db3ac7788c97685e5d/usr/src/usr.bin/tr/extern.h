begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.2 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
enum|enum
block|{
name|STRING1
block|,
name|STRING2
block|}
name|which
enum|;
enum|enum
block|{
name|EOS
block|,
name|INFINITE
block|,
name|NORMAL
block|,
name|RANGE
block|,
name|SEQUENCE
block|,
name|SET
block|}
name|state
enum|;
name|int
name|cnt
decl_stmt|;
comment|/* character count */
name|int
name|lastch
decl_stmt|;
comment|/* last character */
name|int
name|equiv
index|[
literal|2
index|]
decl_stmt|;
comment|/* equivalence set */
name|int
modifier|*
name|set
decl_stmt|;
comment|/* set of characters */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* user's string */
block|}
name|STR
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_define
define|#
directive|define
name|NCHARS
value|(UCHAR_MAX + 1)
end_define

begin_comment
comment|/* Number of possible characters. */
end_comment

begin_define
define|#
directive|define
name|OOBCH
value|(UCHAR_MAX + 1)
end_define

begin_comment
comment|/* Out of band character value. */
end_comment

begin_decl_stmt
name|void
name|err
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|next
name|__P
argument_list|(
operator|(
name|STR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

