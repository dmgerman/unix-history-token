begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* generic singly linked list package */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|Element
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cons
name|List
typedef|;
end_typedef

begin_struct
struct|struct
name|cons
block|{
name|Element
modifier|*
name|car
decl_stmt|;
name|List
modifier|*
name|cdr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|list_next
parameter_list|(
name|lp
parameter_list|)
value|((lp)->cdr)
end_define

begin_define
define|#
directive|define
name|list_data
parameter_list|(
name|lp
parameter_list|)
value|((lp)->car)
end_define

begin_decl_stmt
specifier|extern
name|Element
modifier|*
name|list_push
name|proto
argument_list|(
operator|(
name|List
operator|*
operator|*
operator|,
name|Element
operator|*
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|list_pop
name|proto
argument_list|(
operator|(
name|List
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

