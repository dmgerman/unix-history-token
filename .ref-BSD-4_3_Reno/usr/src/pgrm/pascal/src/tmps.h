begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tmps.h	5.2 (Berkeley) 11/12/86  */
end_comment

begin_comment
comment|/*  * The following structure is used  * to keep track of the amount of variable  * storage required by each block.  * "Max" is the high water mark, "off"  * the current need. Temporaries for "for"  * loops and "with" statements are allocated  * in the local variable area and these  * numbers are thereby changed if necessary.  *  * for the compiler,  *	low_water is the lowest number register allocated of its type  *	next_avail is the next available register of its type  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/*      *	the number of register types.      *	the details of how many of each kind of register there is      *	(and what they are for) is known in tmps.c      */
end_comment

begin_define
define|#
directive|define
name|NUMREGTYPES
value|1
end_define

begin_define
define|#
directive|define
name|REG_GENERAL
value|0
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

begin_comment
comment|/*      *	the number of register types.      *	the details of how many of each kind of register there is      *	(and what they are for) is known in tmps.c      */
end_comment

begin_define
define|#
directive|define
name|NUMREGTYPES
value|1
end_define

begin_define
define|#
directive|define
name|REG_GENERAL
value|0
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

begin_comment
comment|/*      *	the number of register types.      *	the details of how many of each kind of register there is      *	(and what they are for) is known in tmps.c      */
end_comment

begin_define
define|#
directive|define
name|NUMREGTYPES
value|2
end_define

begin_define
define|#
directive|define
name|REG_DATA
value|0
end_define

begin_define
define|#
directive|define
name|REG_ADDR
value|1
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

begin_endif
endif|#
directive|endif
endif|PC
end_endif

begin_struct
struct|struct
name|om
block|{
name|long
name|om_max
decl_stmt|;
ifdef|#
directive|ifdef
name|PC
name|long
name|low_water
index|[
name|NUMREGTYPES
index|]
decl_stmt|;
endif|#
directive|endif
endif|PC
struct|struct
name|tmps
block|{
name|long
name|om_off
decl_stmt|;
ifdef|#
directive|ifdef
name|PC
name|long
name|next_avail
index|[
name|NUMREGTYPES
index|]
decl_stmt|;
endif|#
directive|endif
endif|PC
block|}
name|curtmps
struct|;
block|}
name|sizes
index|[
name|DSPLYSZ
index|]
struct|;
end_struct

begin_comment
comment|/*      *	an enumeration for whether a temporary can be a register.  cf. tmps.c      */
end_comment

begin_define
define|#
directive|define
name|NOREG
value|0
end_define

begin_define
define|#
directive|define
name|REGOK
value|1
end_define

end_unit

