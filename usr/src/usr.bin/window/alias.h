begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)alias.h	3.7 (Berkeley) %G%  */
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

