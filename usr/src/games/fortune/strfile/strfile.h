begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* @(#)strfile.h	1.2 (Berkeley) 5/14/81 */
end_comment

begin_define
define|#
directive|define
name|MAXDELIMS
value|3
end_define

begin_comment
comment|/*  * bits for flag field  */
end_comment

begin_define
define|#
directive|define
name|STR_RANDOM
value|0x1
end_define

begin_define
define|#
directive|define
name|STR_ORDERED
value|0x2
end_define

begin_struct
struct|struct
name|strfile
block|{
comment|/* information table */
name|unsigned
name|int
name|str_numstr
decl_stmt|;
comment|/* # of strings in the file */
name|unsigned
name|int
name|str_longlen
decl_stmt|;
comment|/* length of longest string */
name|unsigned
name|int
name|str_shortlen
decl_stmt|;
comment|/* length of shortest string */
name|long
name|str_delims
index|[
name|MAXDELIMS
index|]
decl_stmt|;
comment|/* delimiter markings */
name|int
name|str_flags
decl_stmt|;
comment|/* bit field for flags */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|strfile
name|STRFILE
typedef|;
end_typedef

end_unit

