begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)frame.h	7.1 (Berkeley) %G%  *  * from: $Header: frame.h,v 1.4 92/06/17 06:10:17 torek Exp $  */
end_comment

begin_comment
comment|/*  * Sparc stack frame format.  *  * Note that the contents of each stack frame may be held only in  * machine register windows.  In order to get an accurate picture  * of the frame, you must first force the kernel to write any such  * windows to the stack.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|fr_local
index|[
literal|8
index|]
decl_stmt|;
comment|/* space to save locals (%l0..%l7) */
name|int
name|fr_arg
index|[
literal|6
index|]
decl_stmt|;
comment|/* space to save arguments (%i0..%i5) */
name|struct
name|frame
modifier|*
name|fr_fp
decl_stmt|;
comment|/* space to save frame pointer (%i6) */
name|int
name|fr_pc
decl_stmt|;
comment|/* space to save return pc (%i7) */
comment|/* 	 * SunOS reserves another 8 words here; this is pointless 	 * but we do it for compatibility. 	 */
name|int
name|fr_xxx
decl_stmt|;
comment|/* `structure return pointer' (unused) */
name|int
name|fr_argd
index|[
literal|6
index|]
decl_stmt|;
comment|/* `arg dump area' (lunacy) */
name|int
name|fr_argx
index|[
literal|1
index|]
decl_stmt|;
comment|/* arg extension (args 7..n; variable size) */
block|}
struct|;
end_struct

end_unit

