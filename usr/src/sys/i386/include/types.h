begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)types.h	7.8 (Berkeley) %G%  */
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
name|int
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
literal|6
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

begin_comment
comment|/*  * Basic integral types.  Omit the typedef if  * not possible for a machine/compiler combination.  */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_int64
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

