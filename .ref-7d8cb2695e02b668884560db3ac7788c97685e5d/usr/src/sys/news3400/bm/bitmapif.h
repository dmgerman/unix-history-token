begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: bitmapif.h,v 4.300 91/06/09 06:14:42 root Rel41 $ SONY  *  *	@(#)bitmapif.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  bitmap interface header  */
end_comment

begin_define
define|#
directive|define
name|C_ON
value|1
end_define

begin_define
define|#
directive|define
name|C_OFF
value|0
end_define

begin_struct
struct|struct
name|csr_buf
block|{
name|int
name|csr_x
decl_stmt|;
comment|/*XXX cursor position x	*/
name|int
name|csr_y
decl_stmt|;
comment|/*XXX cursor position y	*/
name|lPoint
name|csr_p
decl_stmt|;
comment|/*  cursor point	*/
name|int
name|csr_sw
decl_stmt|;
comment|/*  cursor activity	*/
name|int
name|csr_number
decl_stmt|;
comment|/*  which cursor use	*/
block|}
struct|;
end_struct

end_unit

