begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_comment
comment|/*  * Format of a lesskey file:  *  *	LESSKEY_MAGIC (4 bytes)  *	 sections...  *	END_LESSKEY_MAGIC (4 bytes)  *  * Each section is:  *  *	section_MAGIC (1 byte)  *	section_length (2 bytes)  *	key table (section_length bytes)  */
end_comment

begin_define
define|#
directive|define
name|C0_LESSKEY_MAGIC
value|'\0'
end_define

begin_define
define|#
directive|define
name|C1_LESSKEY_MAGIC
value|'M'
end_define

begin_define
define|#
directive|define
name|C2_LESSKEY_MAGIC
value|'+'
end_define

begin_define
define|#
directive|define
name|C3_LESSKEY_MAGIC
value|'G'
end_define

begin_define
define|#
directive|define
name|CMD_SECTION
value|'c'
end_define

begin_define
define|#
directive|define
name|EDIT_SECTION
value|'e'
end_define

begin_define
define|#
directive|define
name|VAR_SECTION
value|'v'
end_define

begin_define
define|#
directive|define
name|END_SECTION
value|'x'
end_define

begin_define
define|#
directive|define
name|C0_END_LESSKEY_MAGIC
value|'E'
end_define

begin_define
define|#
directive|define
name|C1_END_LESSKEY_MAGIC
value|'n'
end_define

begin_define
define|#
directive|define
name|C2_END_LESSKEY_MAGIC
value|'d'
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|KRADIX
value|64
end_define

end_unit

