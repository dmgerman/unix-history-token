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
comment|/*  * Structure used to interface to the machine dependent hardware support  * for timekeeping.  *  * A timecounter is a (hard or soft) binary counter which has two properties:  *    * it runs at a fixed, known frequency.  *    * it must not roll over in less than (1 + delta)/HZ seconds.  "delta"  *	is expected to be less than 20 msec, but no hard data has been   *      collected on this.  16 bit at 5 MHz (31 msec) is known to work.  *  * get_timecount() reads the counter.  *  * counter_mask removes unimplemented bits from the count value.  *  * frequency is the counter frequency in hz.  *  * name is a short mnemonic name for this counter.  *  * cost is a measure of how long time it takes to read the counter.  *  * adjustment [PPM<< 16] which means that the smallest unit of correction  *     you can apply amounts to 481.5 usec/year.  *  * scale_micro [2^32 * usec/tick].  * scale_nano_i [ns/tick].  * scale_nano_f [(ns/2^32)/tick].  *  * offset_count is the contents of the counter which corresponds to the  *     rest of the offset_* values.  *  * offset_sec [s].  * offset_micro [usec].  * offset_nano [ns/2^32] is misnamed, the real unit is .23283064365...  *     attoseconds (10E-18) and before you ask: yes, they are in fact   *     called attoseconds, it comes from "atten" for 18 in Danish/Swedish.  *  * Each timecounter must supply an array of three timecounters, this is needed  * to guarantee atomicity in the code.  Index zero is used to transport   * modifications, for instance done with sysctl, into the timecounter being   * used in a safe way.  Such changes may be adopted with a delay of up to 1/HZ,  * index one& two are used alternately for the actual timekeeping.  *  * 'tc_avail' points to the next available (external) timecounter in a  *      circular queue.  This is only valid for index 0.  *  * `tc_other' points to the next "work" timecounter in a circular queue,  *      i.e., for index i> 0 it points to index 1 + (i - 1) % NTIMECOUNTER.  *      We also use it to point from index 0 to index 1.  *  * `tc_tweak' points to index 0.  */
end_comment

begin_struct_decl
struct_decl|struct
name|timecounter
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|unsigned
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
comment|/* These fields must be initialized by the driver. */
name|timecounter_get_t
modifier|*
name|tc_get_timecount
decl_stmt|;
name|timecounter_pps_t
modifier|*
name|tc_poll_pps
decl_stmt|;
name|unsigned
name|tc_counter_mask
decl_stmt|;
name|u_int32_t
name|tc_frequency
decl_stmt|;
name|char
modifier|*
name|tc_name
decl_stmt|;
name|void
modifier|*
name|tc_priv
decl_stmt|;
comment|/* These fields will be managed by the generic code. */
name|int64_t
name|tc_adjustment
decl_stmt|;
name|u_int64_t
name|tc_scale
decl_stmt|;
name|unsigned
name|tc_offset_count
decl_stmt|;
name|struct
name|bintime
name|tc_offset
decl_stmt|;
name|struct
name|timeval
name|tc_microtime
decl_stmt|;
name|struct
name|timespec
name|tc_nanotime
decl_stmt|;
name|struct
name|timecounter
modifier|*
name|tc_avail
decl_stmt|;
name|struct
name|timecounter
modifier|*
name|tc_tweak
decl_stmt|;
comment|/* Fields not to be copied in tc_windup start with tc_generation */
specifier|volatile
name|unsigned
name|tc_generation
decl_stmt|;
name|struct
name|timecounter
modifier|*
name|tc_next
decl_stmt|;
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
specifier|volatile
name|timecounter
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|void
name|tc_windup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_update
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
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

