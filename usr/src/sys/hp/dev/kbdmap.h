begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)kbdmap.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_define
define|#
directive|define
name|DEL
value|'\177'
end_define

begin_struct
struct|struct
name|kbdmap
block|{
name|int
name|kbd_code
decl_stmt|;
name|char
modifier|*
name|kbd_desc
decl_stmt|;
name|char
modifier|*
name|kbd_keymap
decl_stmt|;
name|char
modifier|*
name|kbd_shiftmap
decl_stmt|;
name|char
modifier|*
name|kbd_ctrlmap
decl_stmt|;
name|char
modifier|*
name|kbd_ctrlshiftmap
decl_stmt|;
name|char
modifier|*
modifier|*
name|kbd_stringmap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* kbd_code */
end_comment

begin_define
define|#
directive|define
name|KBD_SPECIAL
value|0x00
end_define

begin_comment
comment|/* user defined */
end_comment

begin_define
define|#
directive|define
name|KBD_US
value|0x1F
end_define

begin_comment
comment|/* US ASCII */
end_comment

begin_define
define|#
directive|define
name|KBD_UK
value|0x17
end_define

begin_comment
comment|/* United Kingdom */
end_comment

begin_define
define|#
directive|define
name|KBD_DEFAULT
value|KBD_US
end_define

begin_comment
comment|/* default type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* XXX: ITE interface */
end_comment

begin_decl_stmt
name|char
modifier|*
name|kbd_keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_shiftmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_ctrlmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kbd_ctrlshiftmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|kbd_stringmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kbdmap
name|kbd_map
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

