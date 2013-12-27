begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header$  *  * $Created: Sat Aug 20 14:23:01 2005 $  *  * Copyright (C) 2005 by Frank Kardel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_DEBUG_H
end_define

begin_comment
comment|/*  * macros for debugging output - cut down on #ifdef pollution in the code  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|_lvl_
parameter_list|,
name|_arg_
parameter_list|)
define|\
value|do { 						\ 		if (debug>= (_lvl_))			\ 			printf _arg_;			\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|_lvl_
parameter_list|,
name|_arg_
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Log$  */
end_comment

end_unit

