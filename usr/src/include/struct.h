begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)struct.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRUCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_STRUCT_H_
end_define

begin_comment
comment|/* Offset of the field in the structure. */
end_comment

begin_define
define|#
directive|define
name|fldoff
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|)
define|\
value|((int)&(((struct name *)0)->field))
end_define

begin_comment
comment|/* Size of the field in the structure. */
end_comment

begin_define
define|#
directive|define
name|fldsiz
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|)
define|\
value|(sizeof(((struct name *)0)->field))
end_define

begin_comment
comment|/* Address of the structure from a field. */
end_comment

begin_define
define|#
directive|define
name|strbase
parameter_list|(
name|name
parameter_list|,
name|addr
parameter_list|,
name|field
parameter_list|)
define|\
value|((struct name *)((char *)(addr) - fldoff(name, field)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STRUCT_H_ */
end_comment

end_unit

