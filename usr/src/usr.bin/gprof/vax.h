begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vax.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*      *	opcode of the `calls' instruction      */
end_comment

begin_define
define|#
directive|define
name|CALLS
value|0xfb
end_define

begin_comment
comment|/*      *	offset (in bytes) of the code from the entry address of a routine.      *	(see asgnsamples for use and explanation.)      */
end_comment

begin_define
define|#
directive|define
name|OFFSET_OF_CODE
value|2
end_define

begin_define
define|#
directive|define
name|UNITS_TO_CODE
value|(OFFSET_OF_CODE / sizeof(UNIT))
end_define

begin_comment
comment|/*      *	register for pc relative addressing      */
end_comment

begin_define
define|#
directive|define
name|PC
value|0xf
end_define

begin_enum
enum|enum
name|opermodes
block|{
name|literal
block|,
name|indexed
block|,
name|reg
block|,
name|regdef
block|,
name|autodec
block|,
name|autoinc
block|,
name|autoincdef
block|,
name|bytedisp
block|,
name|bytedispdef
block|,
name|worddisp
block|,
name|worddispdef
block|,
name|longdisp
block|,
name|longdispdef
block|,
name|immediate
block|,
name|absolute
block|,
name|byterel
block|,
name|bytereldef
block|,
name|wordrel
block|,
name|wordreldef
block|,
name|longrel
block|,
name|longreldef
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|opermodes
name|operandenum
typedef|;
end_typedef

begin_struct
struct|struct
name|modebyte
block|{
name|unsigned
name|int
name|regfield
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|modefield
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

end_unit

