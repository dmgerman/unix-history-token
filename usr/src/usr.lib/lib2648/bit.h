begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)bit.h	5.1 (Berkeley) 4/26/85  */
end_comment

begin_comment
comment|/*  * Bit matrix manipulations for font editor.  *  * General structure of a bit matrix: each row is packed into as few  * bytes as possible, taking the bits from left to right within bytes.  * The matrix is a sequence of such rows, i.e. up to 7 bits are wasted  * at the end of each row.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
name|char
modifier|*
name|bitmat
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|trace
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ?   (x)  : (y))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ?   (x)  : (y))
end_define

end_unit

