begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.ORG> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMETC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMETC_H_
end_define

begin_comment
comment|/*  * Struct timecounter is the interface between the hardware which implements  * a timecounter and the MI code which uses this to keep track of time.  *  * A timecounter is a binary counter which has two properties:  *    * it runs at a fixed, known frequency.  *    * it has sufficient bits to not roll over in faster than approx  *	2 msec or 2/hz, whichever is faster.  (The value of 2 here is  *	really 1 + delta, for some indeterminate value of delta).  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|timecounter
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|u_int
name|timecounter_get_t
parameter_list|(
name|struct
name|timecounter
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|timecounter_pps_t
parameter_list|(
name|struct
name|timecounter
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|timecounter
block|{
name|timecounter_get_t
modifier|*
name|tc_get_timecount
decl_stmt|;
comment|/* 		 * This function reads the counter.  It is not required to 		 * mask any unimplemented bits out, as long as they are 		 * constant. 		 */
name|timecounter_pps_t
modifier|*
name|tc_poll_pps
decl_stmt|;
comment|/* 		 * This function is optional, it will be called whenever the 		 * timecounter is rewound, and is intended to check for PPS 		 * events.  Most hardware do not need it. 		 */
name|u_int
name|tc_counter_mask
decl_stmt|;
comment|/* This mask should mask off any unimplemnted bits. */
name|u_int32_t
name|tc_frequency
decl_stmt|;
comment|/* Frequency of the counter in Hz. */
name|char
modifier|*
name|tc_name
decl_stmt|;
comment|/* Name of the counter. */
name|void
modifier|*
name|tc_priv
decl_stmt|;
comment|/* Pointer to the counters private parts. */
name|struct
name|timecounter
modifier|*
name|tc_next
decl_stmt|;
comment|/* Initialize this to NUL */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|timecounter
modifier|*
name|timecounter
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int32_t
name|tc_getfrequency
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_init
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_setclock
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TIMETC_H_ */
end_comment

end_unit

