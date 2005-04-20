begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: setjmp.h,v 1.3 2001/03/08 03:23:08 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SETJMP_H
end_ifndef

begin_define
define|#
directive|define
name|SM_SETJMP_H
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* **  sm_setjmp_sig is a setjmp that saves the signal mask. **  sm_setjmp_nosig is a setjmp that does *not* save the signal mask. **  SM_JMPBUF_T is used with both of the above macros. ** **  On most systems, these can be implemented using sigsetjmp. **  Some old BSD systems do not have sigsetjmp, but they do have **  setjmp and _setjmp, which are just as good. */
end_comment

begin_if
if|#
directive|if
name|SM_CONF_SIGSETJMP
end_if

begin_typedef
typedef|typedef
name|sigjmp_buf
name|SM_JMPBUF_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sm_setjmp_sig
parameter_list|(
name|buf
parameter_list|)
value|sigsetjmp(buf, 1)
end_define

begin_define
define|#
directive|define
name|sm_setjmp_nosig
parameter_list|(
name|buf
parameter_list|)
value|sigsetjmp(buf, 0)
end_define

begin_define
define|#
directive|define
name|sm_longjmp_sig
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|siglongjmp(buf, val)
end_define

begin_define
define|#
directive|define
name|sm_longjmp_nosig
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|siglongjmp(buf, val)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_SIGSETJMP */
end_comment

begin_typedef
typedef|typedef
name|jmp_buf
name|SM_JMPBUF_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sm_setjmp_sig
parameter_list|(
name|buf
parameter_list|)
value|setjmp(buf)
end_define

begin_define
define|#
directive|define
name|sm_longjmp_sig
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|longjmp(buf, val)
end_define

begin_define
define|#
directive|define
name|sm_setjmp_nosig
parameter_list|(
name|buf
parameter_list|)
value|_setjmp(buf)
end_define

begin_define
define|#
directive|define
name|sm_longjmp_nosig
parameter_list|(
name|buf
parameter_list|,
name|val
parameter_list|)
value|_longjmp(buf, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_SIGSETJMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_SETJMP_H */
end_comment

end_unit

