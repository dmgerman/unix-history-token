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
comment|/*  * macro for debugging output - cut down on #ifdef pollution.  *  * TRACE() is similar to ntpd's DPRINTF() for utilities and libntp.  * Uses mprintf() and so supports %m, replaced by strerror(errno).  *  * The calling convention is not attractive:  *     TRACE(debuglevel, (fmt, ...));  *     TRACE(2, ("this will appear on stdout if debug>= %d\n", 2));  */
end_comment

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|lvl
parameter_list|,
name|arg
parameter_list|)
define|\
value|do { 						\ 		if (debug>= (lvl))			\ 			mprintf arg;			\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_DEBUG_H */
end_comment

end_unit

