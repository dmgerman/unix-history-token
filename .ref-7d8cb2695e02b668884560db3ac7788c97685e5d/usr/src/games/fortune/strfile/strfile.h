begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ken Arnold.  *  * %sccs.include.redist.c%  *  *	@(#)strfile.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|STR_ENDSTRING
parameter_list|(
name|line
parameter_list|,
name|tbl
parameter_list|)
define|\
value|((line)[0] == (tbl).str_delim&& (line)[1] == '\n')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* information table */
define|#
directive|define
name|VERSION
value|1
name|unsigned
name|long
name|str_version
decl_stmt|;
comment|/* version number */
name|unsigned
name|long
name|str_numstr
decl_stmt|;
comment|/* # of strings in the file */
name|unsigned
name|long
name|str_longlen
decl_stmt|;
comment|/* length of longest string */
name|unsigned
name|long
name|str_shortlen
decl_stmt|;
comment|/* length of shortest string */
define|#
directive|define
name|STR_RANDOM
value|0x1
comment|/* randomized pointers */
define|#
directive|define
name|STR_ORDERED
value|0x2
comment|/* ordered pointers */
define|#
directive|define
name|STR_ROTATED
value|0x4
comment|/* rot-13'd text */
name|unsigned
name|long
name|str_flags
decl_stmt|;
comment|/* bit field for flags */
name|unsigned
name|char
name|stuff
index|[
literal|4
index|]
decl_stmt|;
comment|/* long aligned space */
define|#
directive|define
name|str_delim
value|stuff[0]
comment|/* delimiting character */
block|}
name|STRFILE
typedef|;
end_typedef

end_unit

