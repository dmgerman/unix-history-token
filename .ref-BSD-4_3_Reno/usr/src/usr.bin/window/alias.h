begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)alias.h	3.8 (Berkeley) 6/6/90  */
end_comment

begin_define
define|#
directive|define
name|alias
value|var
end_define

begin_define
define|#
directive|define
name|a_name
value|r_name
end_define

begin_define
define|#
directive|define
name|a_buf
value|r_val.v_str
end_define

begin_define
define|#
directive|define
name|a_flags
value|r_val.v_type
end_define

begin_comment
comment|/* a_flags bits, must not interfere with v_type values */
end_comment

begin_define
define|#
directive|define
name|A_INUSE
value|0x010
end_define

begin_comment
comment|/* already inuse */
end_comment

begin_define
define|#
directive|define
name|alias_set
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|var_setstr1(&alias_head, n, s)
end_define

begin_define
define|#
directive|define
name|alias_walk
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|var_walk1(alias_head, f, a)
end_define

begin_define
define|#
directive|define
name|alias_unset
parameter_list|(
name|n
parameter_list|)
value|var_unset1(&alias_head, n)
end_define

begin_define
define|#
directive|define
name|alias_lookup
parameter_list|(
name|n
parameter_list|)
value|(*var_lookup1(&alias_head, n))
end_define

begin_decl_stmt
name|struct
name|var
modifier|*
name|alias_head
decl_stmt|;
end_decl_stmt

end_unit

