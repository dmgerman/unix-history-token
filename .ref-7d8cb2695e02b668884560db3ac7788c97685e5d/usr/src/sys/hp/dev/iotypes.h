begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: iotypes.h 1.1 91/12/12$  *  *	@(#)iotypes.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOTYPES_
end_ifndef

begin_define
define|#
directive|define
name|_IOTYPES_
end_define

begin_comment
comment|/*  * Where do these really belong?  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|char
name|v_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|char
name|vu_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|short
name|v_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|short
name|vu_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|int
name|v_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|int
name|vu_int
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

