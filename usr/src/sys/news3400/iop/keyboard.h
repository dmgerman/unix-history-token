begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: keyboard.h,v 4.300 91/06/09 06:42:48 root Rel41 $ SONY  *  *	@(#)keyboard.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Key flag  */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0x003f
end_define

begin_define
define|#
directive|define
name|N
value|0x0001
end_define

begin_define
define|#
directive|define
name|S
value|0x0002
end_define

begin_define
define|#
directive|define
name|C
value|0x0004
end_define

begin_define
define|#
directive|define
name|A
value|0x0008
end_define

begin_define
define|#
directive|define
name|K
value|0x0010
end_define

begin_define
define|#
directive|define
name|G
value|0x0010
end_define

begin_define
define|#
directive|define
name|J
value|0x0020
end_define

begin_define
define|#
directive|define
name|L
value|0x0040
end_define

begin_define
define|#
directive|define
name|R
value|0x0080
end_define

begin_define
define|#
directive|define
name|O
value|(L|R)
end_define

begin_define
define|#
directive|define
name|PRG_FUNC
value|0x0100
end_define

begin_define
define|#
directive|define
name|ALT_FUNC
value|0x0200
end_define

begin_define
define|#
directive|define
name|CAP_LOCK
value|0x0400
end_define

begin_define
define|#
directive|define
name|PSH_SHFT
value|0x0800
end_define

begin_define
define|#
directive|define
name|SW_SHFT
value|0x1000
end_define

begin_define
define|#
directive|define
name|KEY_PRESS
value|0x4000
end_define

begin_define
define|#
directive|define
name|NOT_REPT
value|0x8000
end_define

begin_define
define|#
directive|define
name|S_CTRL
value|0
end_define

begin_define
define|#
directive|define
name|S_LSHFT
value|1
end_define

begin_define
define|#
directive|define
name|S_RSHFT
value|2
end_define

begin_define
define|#
directive|define
name|S_ALT
value|3
end_define

begin_define
define|#
directive|define
name|S_CAPS
value|4
end_define

begin_define
define|#
directive|define
name|S_AN
value|5
end_define

begin_define
define|#
directive|define
name|S_KANA
value|6
end_define

begin_define
define|#
directive|define
name|S_OCAPS
value|7
end_define

begin_define
define|#
directive|define
name|S_OKANA
value|8
end_define

begin_define
define|#
directive|define
name|S_ALTGR
value|9
end_define

begin_comment
comment|/*  *	Keyboard status  */
end_comment

begin_define
define|#
directive|define
name|KBD_SHIFT
value|0x0003
end_define

begin_comment
comment|/* shift mode		*/
end_comment

begin_define
define|#
directive|define
name|KBD_RSHIFT
value|0x0001
end_define

begin_define
define|#
directive|define
name|KBD_LSHIFT
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBD_CTRL
value|0x0004
end_define

begin_comment
comment|/* control mode		*/
end_comment

begin_define
define|#
directive|define
name|KBD_ALT
value|0x0008
end_define

begin_comment
comment|/* alternate mode	*/
end_comment

begin_define
define|#
directive|define
name|KBD_CAPS
value|0x0010
end_define

begin_comment
comment|/* capital lock mode	*/
end_comment

begin_define
define|#
directive|define
name|KBD_KANA
value|0x0020
end_define

begin_comment
comment|/* kana mode		*/
end_comment

begin_define
define|#
directive|define
name|KBD_NOTREPT
value|0x0080
end_define

begin_comment
comment|/* do not auto repeat	*/
end_comment

begin_define
define|#
directive|define
name|KBD_ALTGR
value|0x0800
end_define

begin_comment
comment|/* European keyboard AltGr mode	*/
end_comment

begin_comment
comment|/*  *	Lock type  */
end_comment

begin_define
define|#
directive|define
name|CAPSLOCK
value|1
end_define

begin_define
define|#
directive|define
name|SHIFTLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SHIFTLOCK2
value|3
end_define

begin_comment
comment|/*  *	Country number  */
end_comment

begin_define
define|#
directive|define
name|K_JAPANESE_J
value|0
end_define

begin_comment
comment|/* JIS */
end_comment

begin_define
define|#
directive|define
name|K_JAPANESE_O
value|1
end_define

begin_comment
comment|/* OYAYUBI */
end_comment

begin_define
define|#
directive|define
name|K_GERMAN
value|2
end_define

begin_define
define|#
directive|define
name|K_FRENCH
value|3
end_define

begin_define
define|#
directive|define
name|K_UKENGLISH
value|4
end_define

begin_define
define|#
directive|define
name|K_ITALIAN
value|5
end_define

begin_define
define|#
directive|define
name|K_SPANISH
value|6
end_define

begin_define
define|#
directive|define
name|K_SWEDISH_FINNISH
value|7
end_define

begin_define
define|#
directive|define
name|K_DANISH
value|8
end_define

begin_define
define|#
directive|define
name|K_NORWEGIAN
value|9
end_define

begin_define
define|#
directive|define
name|K_PORTUGUESE
value|10
end_define

begin_define
define|#
directive|define
name|K_USENGLISH
value|11
end_define

begin_comment
comment|/*  *	Key shift code  */
end_comment

begin_define
define|#
directive|define
name|PF_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|PF_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|PF_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|PF_ALTERNATE
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|key_table
block|{
name|short
name|key_flags
decl_stmt|;
name|char
name|normal_code
decl_stmt|;
name|char
name|shift_code
decl_stmt|;
name|char
name|ctrl_code
decl_stmt|;
name|char
name|alt_code
decl_stmt|;
name|char
name|kana_code
decl_stmt|;
name|char
name|kshft_code
decl_stmt|;
block|}
name|Key_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|key_number
decl_stmt|;
name|Key_table
name|key_num_table
decl_stmt|;
block|}
name|Key_tab_info
typedef|;
end_typedef

begin_comment
comment|/*  *	IOCTL command  */
end_comment

begin_define
define|#
directive|define
name|KBIOCBELL
value|_IOW('K', 1, int)
end_define

begin_comment
comment|/* ring bell	*/
end_comment

begin_define
define|#
directive|define
name|KBIOCREPT
value|_IO('K', 3)
end_define

begin_comment
comment|/* auto repeat on */
end_comment

begin_define
define|#
directive|define
name|KBIOCNRPT
value|_IO('K', 4)
end_define

begin_comment
comment|/* auto repeat off */
end_comment

begin_define
define|#
directive|define
name|KBIOCSETLOCK
value|_IOW('K', 10, int)
end_define

begin_comment
comment|/* set lock type */
end_comment

begin_define
define|#
directive|define
name|KBIOCSETTBL
value|_IOW('K', 11, Key_tab_info)
end_define

begin_comment
comment|/* set key_table */
end_comment

begin_define
define|#
directive|define
name|KBIOCGETCNUM
value|_IOR('K', 12, int)
end_define

begin_comment
comment|/* get country number */
end_comment

begin_define
define|#
directive|define
name|KBIOCSETCNUM
value|_IOW('K', 13, int)
end_define

begin_comment
comment|/* set country number */
end_comment

begin_define
define|#
directive|define
name|KBIOCGETSTAT
value|_IOR('K', 17, int)
end_define

begin_comment
comment|/* get status */
end_comment

begin_define
define|#
directive|define
name|KBIOCSETSTAT
value|_IOW('K', 18, int)
end_define

begin_comment
comment|/* set status */
end_comment

end_unit

