begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)useful.h	4.4 (Berkeley) 6/29/88  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|makedev
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* support for bool type */
end_comment

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
endif|NULL
end_endif

begin_comment
comment|/* bit hacking */
end_comment

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|(((word)& (bit)) != 0)
end_define

begin_comment
comment|/* some simple functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
endif|max
end_endif

begin_comment
comment|/* assertions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NASSERT
end_ifndef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|,
name|parm
parameter_list|)
define|\
value|if (!(expr))\ 	{\ 		fprintf(stderr, "assertion botch: %s:%d: ", __FILE__, __LINE__);\ 		fprintf(stderr, msg, parm);\ 	}
end_define

begin_else
else|#
directive|else
else|NASSERT
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|,
name|parm
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
endif|NASSERT
end_endif

begin_comment
comment|/* sccs id's */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|SCCSID
parameter_list|(
name|arg
parameter_list|)
value|static char SccsId[] = "arg";
end_define

begin_else
else|#
directive|else
else|lint
end_else

begin_define
define|#
directive|define
name|SCCSID
parameter_list|(
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* define the types of some common functions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strncat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|V6
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|void
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

end_unit

