begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: vt100esc.h,v 4.300 91/06/09 06:15:01 root Rel41 $ SONY  *  *	@(#)vt100esc.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  escape sequence structure  */
end_comment

begin_struct
struct|struct
name|esc_sequence
block|{
name|char
name|command
decl_stmt|;
name|char
modifier|*
name|terminators
decl_stmt|;
name|int
function_decl|(
modifier|*
name|esc_func
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  key pad structure  */
end_comment

begin_struct
struct|struct
name|key_pad
block|{
name|char
name|kpd_numeric
decl_stmt|;
name|char
name|kpd_applic
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NUMERIC
value|0
end_define

begin_define
define|#
directive|define
name|APPLIC
value|1
end_define

end_unit

