begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: INTERN.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_undef
undef|#
directive|undef
name|EXT
end_undef

begin_define
define|#
directive|define
name|EXT
end_define

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|xenix
end_ifdef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|=x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DOINIT
end_define

end_unit

