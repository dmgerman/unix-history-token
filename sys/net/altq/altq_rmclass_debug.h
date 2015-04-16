begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: altq_rmclass_debug.h,v 1.3 2002/11/29 04:36:24 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) Sun Microsystems, Inc. 1998 All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the SMCC Technology  *      Development Group at Sun Microsystems, Inc.  *  * 4. The name of the Sun Microsystems, Inc nor may not be used to endorse or  *      promote products derived from this software without specific prior  *      written permission.  *  * SUN MICROSYSTEMS DOES NOT CLAIM MERCHANTABILITY OF THIS SOFTWARE OR THE  * SUITABILITY OF THIS SOFTWARE FOR ANY PARTICULAR PURPOSE.  The software is  * provided "as is" without express or implied warranty of any kind.  *  * These notices must be retained in any copies of any part of this software.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_RMCLASS_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_RMCLASS_DEBUG_H_
end_define

begin_comment
comment|/* #pragma ident	"@(#)rm_class_debug.h	1.7	98/05/04 SMI" */
end_comment

begin_comment
comment|/*  * Cbq debugging macros  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CBQ_TRACE
ifndef|#
directive|ifndef
name|NCBQTRACE
define|#
directive|define
name|NCBQTRACE
value|(16 * 1024)
endif|#
directive|endif
comment|/*  * To view the trace output, using adb, type:  *	adb -k /dev/ksyms /dev/mem<cr>, then type  *	cbqtrace_count/D to get the count, then type  *	cbqtrace_buffer,0tcount/Dp4C" "Xn  *	This will dump the trace buffer from 0 to count.  */
comment|/*  * in ALTQ, "call cbqtrace_dump(N)" from DDB to display 20 events  * from Nth event in the circular buffer.  */
struct|struct
name|cbqtrace
block|{
name|int
name|count
decl_stmt|;
name|int
name|function
decl_stmt|;
comment|/* address of function */
name|int
name|trace_action
decl_stmt|;
comment|/* descriptive 4 characters */
name|int
name|object
decl_stmt|;
comment|/* object operated on */
block|}
struct|;
specifier|extern
name|struct
name|cbqtrace
name|cbqtrace_buffer
index|[]
decl_stmt|;
specifier|extern
name|struct
name|cbqtrace
modifier|*
name|cbqtrace_ptr
decl_stmt|;
specifier|extern
name|int
name|cbqtrace_count
decl_stmt|;
define|#
directive|define
name|CBQTRACEINIT
parameter_list|()
value|{				\ 	if (cbqtrace_ptr == NULL)		\ 		cbqtrace_ptr = cbqtrace_buffer; \ 	else { \ 		cbqtrace_ptr = cbqtrace_buffer; \ 		bzero((void *)cbqtrace_ptr, sizeof(cbqtrace_buffer)); \ 		cbqtrace_count = 0; \ 	} \ }
define|#
directive|define
name|LOCK_TRACE
parameter_list|()
value|splimp()
define|#
directive|define
name|UNLOCK_TRACE
parameter_list|(
name|x
parameter_list|)
value|splx(x)
define|#
directive|define
name|CBQTRACE
parameter_list|(
name|func
parameter_list|,
name|act
parameter_list|,
name|obj
parameter_list|)
value|{		\ 	int __s = LOCK_TRACE();			\ 	int *_p =&cbqtrace_ptr->count;	\ 	*_p++ = ++cbqtrace_count;		\ 	*_p++ = (int)(func);			\ 	*_p++ = (int)(act);			\ 	*_p++ = (int)(obj);			\ 	if ((struct cbqtrace *)(void *)_p>=&cbqtrace_buffer[NCBQTRACE])\ 		cbqtrace_ptr = cbqtrace_buffer; \ 	else					\ 		cbqtrace_ptr = (struct cbqtrace *)(void *)_p; \ 	UNLOCK_TRACE(__s);			\ 	}
else|#
directive|else
comment|/* If no tracing, define no-ops */
define|#
directive|define
name|CBQTRACEINIT
parameter_list|()
define|#
directive|define
name|CBQTRACE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
endif|#
directive|endif
comment|/* !CBQ_TRACE */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_RMCLASS_DEBUG_H_ */
end_comment

end_unit

