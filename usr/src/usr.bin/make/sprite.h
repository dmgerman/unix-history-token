begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sprite.h --  *  * Common constants and type declarations for Sprite.  *  * Copyright 1985 Regents of the University of California  * All rights reserved.  *  *  * $Id: sprite.h,v 2.1 89/07/03 15:57:45 adam Exp $ SPRITE (Berkeley)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPRITE
end_ifndef

begin_define
define|#
directive|define
name|_SPRITE
end_define

begin_comment
comment|/*  * A boolean type is defined as an integer, not an enum. This allows a  * boolean argument to be an expression that isn't strictly 0 or 1 valued.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|Boolean
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

begin_endif
endif|#
directive|endif
endif|TRUE
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
endif|FALSE
end_endif

begin_comment
comment|/*  * Functions that must return a status can return a ReturnStatus to  * indicate success or type of failure.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ReturnStatus
typedef|;
end_typedef

begin_comment
comment|/*  * The following statuses overlap with the first 2 generic statuses   * defined in status.h:  *  * SUCCESS			There was no error.  * FAILURE			There was a general error.  */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FAILURE
value|0x00000001
end_define

begin_comment
comment|/*  * A nil pointer must be something that will cause an exception if   * referenced.  There are two nils: the kernels nil and the nil used  * by user processes.  */
end_comment

begin_define
define|#
directive|define
name|NIL
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|USER_NIL
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
comment|/*  * An address is just a pointer in C.  It is defined as a character pointer  * so that address arithmetic will work properly, a byte at a time.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|Address
typedef|;
end_typedef

begin_comment
comment|/*  * ClientData is an uninterpreted word.  It is defined as an int so that  * kdbx will not interpret client data as a string.  Unlike an "Address",  * client data will generally not be used in arithmetic.  */
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|ClientData
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_include
include|#
directive|include
file|"status.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|_SPRITE
end_endif

end_unit

