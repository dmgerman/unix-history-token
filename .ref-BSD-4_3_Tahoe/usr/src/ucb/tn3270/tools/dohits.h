begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)dohits.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_define
define|#
directive|define
name|numberof
parameter_list|(
name|x
parameter_list|)
value|(sizeof x/sizeof x[0])
end_define

begin_define
define|#
directive|define
name|highestof
parameter_list|(
name|x
parameter_list|)
value|(numberof(x)-1)
end_define

begin_define
define|#
directive|define
name|firstentry
parameter_list|(
name|x
parameter_list|)
value|(table[dohash(0, (x))%highestof(table)])
end_define

begin_struct
struct|struct
name|Hits
block|{
name|struct
name|hits
name|hits
decl_stmt|;
name|char
modifier|*
name|name
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|thing
block|{
name|struct
name|thing
modifier|*
name|next
decl_stmt|;
name|struct
name|Hits
modifier|*
name|hits
decl_stmt|;
name|unsigned
name|char
name|value
decl_stmt|;
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|Hits
name|Hits
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one for each of 0x00-0xff */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thing
modifier|*
name|table
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|unsigned
name|int
name|dohash
parameter_list|()
function_decl|;
end_function_decl

end_unit

