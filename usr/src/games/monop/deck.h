begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)deck.h	5.2 (Berkeley) 6/18/88  */
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

