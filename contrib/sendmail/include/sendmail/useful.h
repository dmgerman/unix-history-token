begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: useful.h,v 8.18 1999/07/13 15:05:57 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USEFUL_H
end_ifndef

begin_define
define|#
directive|define
name|_USEFUL_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* support for bool type */
end_comment

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TRUE */
end_comment

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
end_endif

begin_comment
comment|/* ! NULL */
end_comment

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
end_endif

begin_comment
comment|/* ! max */
end_comment

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
end_else

begin_comment
comment|/* ! NASSERT */
end_comment

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
end_endif

begin_comment
comment|/* ! NASSERT */
end_comment

begin_comment
comment|/* sccs id's */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|SCCSID
parameter_list|(
name|arg
parameter_list|)
value|static char SccsId[] = #arg;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|SCCSID
parameter_list|(
name|arg
parameter_list|)
value|static char SccsId[] = "arg";
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! lint */
end_comment

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
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _USEFUL_H */
end_comment

end_unit

