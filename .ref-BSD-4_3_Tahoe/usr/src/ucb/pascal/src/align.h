begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)align.h	5.2 (Berkeley) 11/12/86  */
end_comment

begin_comment
comment|/*      *	alignment of various types in bytes.      *	sizes are found using sizeof( type ).      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|4
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|4
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|A_LONG
value|4
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|4
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|1
end_define

begin_define
define|#
directive|define
name|A_STACK
value|4
end_define

begin_define
define|#
directive|define
name|A_FILET
value|4
end_define

begin_define
define|#
directive|define
name|A_SET
value|4
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|4
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|4
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|A_LONG
value|4
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|4
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|4
end_define

begin_define
define|#
directive|define
name|A_STACK
value|4
end_define

begin_define
define|#
directive|define
name|A_FILET
value|4
end_define

begin_define
define|#
directive|define
name|A_SET
value|4
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|2
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|2
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|2
end_define

begin_define
define|#
directive|define
name|A_LONG
value|2
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|2
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|2
end_define

begin_define
define|#
directive|define
name|A_STACK
value|2
end_define

begin_define
define|#
directive|define
name|A_FILET
value|2
end_define

begin_define
define|#
directive|define
name|A_SET
value|2
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|2
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

end_unit

