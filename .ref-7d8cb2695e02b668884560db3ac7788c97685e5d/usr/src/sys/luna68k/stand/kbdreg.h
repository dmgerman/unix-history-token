begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)kbdreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * kbdreg.h --  *  */
end_comment

begin_struct
struct|struct
name|kbd_keymap
block|{
name|int
name|km_type
decl_stmt|;
name|int
name|km_code
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KC_CHAR
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|KC_TYPE
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|KC_CODE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KC_SHIFT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KC_IGNORE
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|KS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|KS_CTRL
value|1
end_define

begin_define
define|#
directive|define
name|KS_META
value|2
end_define

end_unit

