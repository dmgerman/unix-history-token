begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)types.h	7.1 (Berkeley) %G%  *  * from: $Header: types.h,v 1.4 92/06/17 06:10:30 torek Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHTYPES_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_physadr
block|{
name|short
name|r
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|physadr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|label_t
block|{
name|int
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|label_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|vm_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|vm_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHTYPES_H_ */
end_comment

end_unit

