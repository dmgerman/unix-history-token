begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== util.h ============================================================  * Copyright (c) 1991, 1992, 1993 by Chris Provenzano, proven@athena.mit.edu	  *  * Description : Header file for generic utility functions.  *  * 91/08/31 proven - Added exchange.  * Exchange any two objects of any size in any table.  *  * 91/10/06 proven - Cleaned out all the old junk.   *  * 91/03/06 proven - Added getint.   */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

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

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_typedef
typedef|typedef
enum|enum
name|Boolean
block|{
name|FALSE
block|,
name|TRUE
block|, }
name|Boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_define
define|#
directive|define
name|NOTOK
value|-1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|min
argument_list|)
end_if

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Alingn the size to the next multiple of 4 bytes */
end_comment

begin_define
define|#
directive|define
name|ALIGN4
parameter_list|(
name|size
parameter_list|)
value|((size + 3)& ~3)
end_define

begin_define
define|#
directive|define
name|ALIGN8
parameter_list|(
name|size
parameter_list|)
value|((size + 7)& ~7)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG0
parameter_list|(
name|s
parameter_list|)
value|printf(s)
end_define

begin_define
define|#
directive|define
name|DEBUG1
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|printf(s,a)
end_define

begin_define
define|#
directive|define
name|DEBUG2
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|printf(s,a,b)
end_define

begin_define
define|#
directive|define
name|DEBUG3
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|printf(s,a,b,c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG0
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG1
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG2
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG3
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

