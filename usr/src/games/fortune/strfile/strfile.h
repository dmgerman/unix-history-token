begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ken Arnold.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)strfile.h	5.5 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRFILE__
end_ifndef

begin_define
define|#
directive|define
name|__STRFILE__
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

begin_define
define|#
directive|define
name|STR_ROTATED
value|0x4
end_define

begin_define
define|#
directive|define
name|STR_ENDSTRING
parameter_list|(
name|line
parameter_list|,
name|tbl
parameter_list|)
value|((line)[0] == (tbl).str_delim&& (line)[1] == '\n')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* information table */
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
name|unsigned
name|char
name|str_flags
decl_stmt|;
comment|/* bit field for flags */
name|char
name|str_delim
decl_stmt|;
comment|/* delimiting character */
block|}
name|STRFILE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STRFILE__ */
end_comment

end_unit

