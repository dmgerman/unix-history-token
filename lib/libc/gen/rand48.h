begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Martin Birgmeier  * All rights reserved.  *  * You may redistribute unmodified or modified versions of this source  * code provided that the above copyright notice and this and the  * following conditions are retained.  *  * This software is provided ``as is'', and comes with no warranties  * of any kind. I shall in no event be liable for anything that happens  * to anyone/anything when using this software.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RAND48_H_
end_ifndef

begin_define
define|#
directive|define
name|_RAND48_H_
end_define

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
name|void
name|_dorand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RAND48_SEED_0
value|(0x330e)
end_define

begin_define
define|#
directive|define
name|RAND48_SEED_1
value|(0xabcd)
end_define

begin_define
define|#
directive|define
name|RAND48_SEED_2
value|(0x1234)
end_define

begin_define
define|#
directive|define
name|RAND48_MULT_0
value|(0xe66d)
end_define

begin_define
define|#
directive|define
name|RAND48_MULT_1
value|(0xdeec)
end_define

begin_define
define|#
directive|define
name|RAND48_MULT_2
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|RAND48_ADD
value|(0x000b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RAND48_H_ */
end_comment

end_unit

