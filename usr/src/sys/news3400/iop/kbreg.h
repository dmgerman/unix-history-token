begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: kbreg.h,v 4.300 91/06/09 06:42:47 root Rel41 $ SONY  *  *	@(#)kbreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KEYBOARD__
end_ifndef

begin_define
define|#
directive|define
name|__KEYBOARD__
value|1
end_define

begin_define
define|#
directive|define
name|key_any
parameter_list|(
name|x
parameter_list|)
value|((x) != -1)
end_define

begin_define
define|#
directive|define
name|key_down
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x80) == 0)
end_define

begin_define
define|#
directive|define
name|key_up
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x80)
end_define

begin_typedef
typedef|typedef
struct|struct
name|key_string
block|{
name|int
name|key_length
decl_stmt|;
name|char
modifier|*
name|key_string
decl_stmt|;
block|}
name|Key_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pfk_table
block|{
name|int
name|pfk_addr
decl_stmt|;
name|Key_string
name|pfk_normal
decl_stmt|;
name|Key_string
name|pfk_shift
decl_stmt|;
block|}
name|Pfk_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pfk_string
block|{
name|int
name|pfk_num
decl_stmt|;
name|int
name|pfk_shift
decl_stmt|;
name|Key_string
name|pfk_string
decl_stmt|;
block|}
name|Pfk_string
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KBDPRI
value|28
end_define

begin_define
define|#
directive|define
name|KIOCSETS
value|0
end_define

begin_comment
comment|/* set pfk string	*/
end_comment

begin_define
define|#
directive|define
name|KIOCBELL
value|1
end_define

begin_comment
comment|/* ring bell		*/
end_comment

begin_define
define|#
directive|define
name|KIOCBACK
value|2
end_define

begin_comment
comment|/* push back string	*/
end_comment

begin_define
define|#
directive|define
name|KIOCREPT
value|3
end_define

begin_comment
comment|/* auto repeat on	*/
end_comment

begin_define
define|#
directive|define
name|KIOCNRPT
value|4
end_define

begin_comment
comment|/* auto repeat off	*/
end_comment

begin_define
define|#
directive|define
name|KIOCGETS
value|5
end_define

begin_comment
comment|/* get pfk string	*/
end_comment

begin_define
define|#
directive|define
name|KIOCRAW
value|6
end_define

begin_comment
comment|/* get raw key data	*/
end_comment

begin_define
define|#
directive|define
name|KIOCSETE
value|7
end_define

begin_define
define|#
directive|define
name|KIOCFLUSH
value|8
end_define

begin_define
define|#
directive|define
name|KIOCNREAD
value|FIONREAD
end_define

begin_comment
comment|/* return input char's	*/
end_comment

begin_define
define|#
directive|define
name|KIOCSETLOCK
value|10
end_define

begin_comment
comment|/* set lock type	*/
end_comment

begin_define
define|#
directive|define
name|KIOCSETTBL
value|11
end_define

begin_comment
comment|/* set key_table	*/
end_comment

begin_define
define|#
directive|define
name|KIOCGETCNUM
value|12
end_define

begin_comment
comment|/* get country number	*/
end_comment

begin_define
define|#
directive|define
name|KIOCSETCNUM
value|13
end_define

begin_comment
comment|/* set country number	*/
end_comment

begin_define
define|#
directive|define
name|KIOCDEFTBL
value|14
end_define

begin_comment
comment|/* default key_table 	*/
end_comment

begin_define
define|#
directive|define
name|KIOCCHTBL
value|15
end_define

begin_comment
comment|/* change key_table 	*/
end_comment

begin_define
define|#
directive|define
name|KIOCOYATBL
value|16
end_define

begin_comment
comment|/* oya_key_table	*/
end_comment

begin_define
define|#
directive|define
name|KIOCGETSTAT
value|17
end_define

begin_comment
comment|/* get keyboard status	*/
end_comment

begin_define
define|#
directive|define
name|KIOCSETSTAT
value|18
end_define

begin_comment
comment|/* set keyboard status	*/
end_comment

begin_define
define|#
directive|define
name|OFF
value|0x80
end_define

begin_decl_stmt
specifier|extern
name|int
name|N_Pfk
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|N_PFK
value|N_Pfk
end_define

begin_define
define|#
directive|define
name|N_KEY
value|93
end_define

begin_comment
comment|/*  * Programmable function key  */
end_comment

begin_define
define|#
directive|define
name|F1
value|1
end_define

begin_define
define|#
directive|define
name|F2
value|2
end_define

begin_define
define|#
directive|define
name|F3
value|3
end_define

begin_define
define|#
directive|define
name|F4
value|4
end_define

begin_define
define|#
directive|define
name|F5
value|5
end_define

begin_define
define|#
directive|define
name|F6
value|6
end_define

begin_define
define|#
directive|define
name|F7
value|7
end_define

begin_define
define|#
directive|define
name|F8
value|8
end_define

begin_define
define|#
directive|define
name|F9
value|9
end_define

begin_define
define|#
directive|define
name|F10
value|10
end_define

begin_define
define|#
directive|define
name|PF1
value|11
end_define

begin_define
define|#
directive|define
name|PF2
value|12
end_define

begin_define
define|#
directive|define
name|PF3
value|13
end_define

begin_define
define|#
directive|define
name|PF4
value|14
end_define

begin_define
define|#
directive|define
name|PF5
value|15
end_define

begin_define
define|#
directive|define
name|PF6
value|16
end_define

begin_define
define|#
directive|define
name|PF7
value|17
end_define

begin_define
define|#
directive|define
name|PF8
value|18
end_define

begin_define
define|#
directive|define
name|PF9
value|19
end_define

begin_define
define|#
directive|define
name|PF10
value|20
end_define

begin_define
define|#
directive|define
name|PF11
value|21
end_define

begin_define
define|#
directive|define
name|PF12
value|22
end_define

begin_define
define|#
directive|define
name|NCNV
value|23
end_define

begin_define
define|#
directive|define
name|CONV
value|24
end_define

begin_define
define|#
directive|define
name|ENTER
value|25
end_define

begin_define
define|#
directive|define
name|N0
value|26
end_define

begin_define
define|#
directive|define
name|N1
value|27
end_define

begin_define
define|#
directive|define
name|N2
value|28
end_define

begin_define
define|#
directive|define
name|N3
value|29
end_define

begin_define
define|#
directive|define
name|N4
value|30
end_define

begin_define
define|#
directive|define
name|N5
value|31
end_define

begin_define
define|#
directive|define
name|N6
value|32
end_define

begin_define
define|#
directive|define
name|N7
value|33
end_define

begin_define
define|#
directive|define
name|N8
value|34
end_define

begin_define
define|#
directive|define
name|N9
value|35
end_define

begin_define
define|#
directive|define
name|PERIOD
value|36
end_define

begin_define
define|#
directive|define
name|MINUS
value|37
end_define

begin_define
define|#
directive|define
name|PLUS
value|38
end_define

begin_define
define|#
directive|define
name|COMMA
value|39
end_define

begin_define
define|#
directive|define
name|NENTER
value|40
end_define

begin_define
define|#
directive|define
name|UP
value|41
end_define

begin_define
define|#
directive|define
name|DOWN
value|42
end_define

begin_define
define|#
directive|define
name|RIGHT
value|43
end_define

begin_define
define|#
directive|define
name|LEFT
value|44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__KEYBOARD__ */
end_comment

end_unit

