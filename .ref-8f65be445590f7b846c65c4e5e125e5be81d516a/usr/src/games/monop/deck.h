begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)deck.h	5.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|CC_D
value|deck[0]
end_define

begin_define
define|#
directive|define
name|CH_D
value|deck[1]
end_define

begin_struct
struct|struct
name|dk_st
block|{
comment|/* deck description structure		*/
name|int
name|num_cards
decl_stmt|;
comment|/* number of cards in deck	*/
name|int
name|last_card
decl_stmt|;
comment|/* number of last card picked	*/
name|bool
name|gojf_used
decl_stmt|;
comment|/* set if gojf card out of deck	*/
name|long
modifier|*
name|offsets
decl_stmt|;
comment|/* offests for start of cards	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dk_st
name|DECK
typedef|;
end_typedef

end_unit

