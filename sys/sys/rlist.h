begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 William Jolitz. All rights reserved.  * Written by William Jolitz 1/92  *  * Redistribution and use in source and binary forms are freely permitted  * provided that the above copyright notice and attribution and date of work  * and this paragraph are duplicated in all such forms.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Resource lists.  *  *	Usage:  *		rlist_free(&swapmap, 100, 200);	add space to swapmap  *		rlist_alloc(&swapmap, 100,&loc); obtain 100 sectors from swap  * $Header: /a/cvs/386BSD/src/sys.386bsd/sys/rlist.h,v 1.1.1.1 1993/06/12 14:58:17 rgrimes Exp $  */
end_comment

begin_comment
comment|/* A resource list element. */
end_comment

begin_struct
struct|struct
name|rlist
block|{
name|unsigned
name|rl_start
decl_stmt|;
comment|/* boundaries of extent - inclusive */
name|unsigned
name|rl_end
decl_stmt|;
comment|/* boundaries of extent - inclusive */
name|struct
name|rlist
modifier|*
name|rl_next
decl_stmt|;
comment|/* next list entry, if present */
block|}
struct|;
end_struct

begin_comment
comment|/* Functions to manipulate resource lists.  */
end_comment

begin_decl_stmt
specifier|extern
name|rlist_free
name|__P
argument_list|(
operator|(
expr|struct
name|rlist
operator|*
operator|*
operator|,
name|unsigned
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rlist_alloc
name|__P
argument_list|(
operator|(
expr|struct
name|rlist
operator|*
operator|*
operator|,
name|unsigned
operator|,
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rlist_destroy
name|__P
argument_list|(
operator|(
expr|struct
name|rlist
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* heads of lists */
end_comment

begin_decl_stmt
name|struct
name|rlist
modifier|*
name|swapmap
decl_stmt|;
end_decl_stmt

end_unit

