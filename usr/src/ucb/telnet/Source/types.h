begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)types.h	1.2 (Berkeley) 3/8/88  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|modedescriptions
decl_stmt|;
name|char
name|modetype
decl_stmt|;
block|}
name|Modelist
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Modelist
name|modelist
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|system
decl_stmt|,
comment|/* what the current time is */
name|echotoggle
decl_stmt|,
comment|/* last time user entered echo character */
name|modenegotiated
decl_stmt|,
comment|/* last time operating mode negotiated */
name|didnetreceive
decl_stmt|,
comment|/* last time we read data from network */
name|gotDM
decl_stmt|;
comment|/* when did we last see a data mark */
block|}
name|Clocks
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Clocks
name|clocks
decl_stmt|;
end_decl_stmt

end_unit

