begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_acpi.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|<dev/acpica/acpivar.h>
end_include

begin_comment
comment|/*  * Support for ACPI Processor devices.  *  * Note that this only provides ACPI 1.0 support (with the exception of the  * PSTATE_CNT field).  2.0 support will involve implementing _PTC, _PCT,  * _PSS and _PPC.  */
end_comment

begin_comment
comment|/*  * Hooks for the ACPI CA debugging infrastructure  */
end_comment

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_PROCESSOR
end_define

begin_macro
name|MODULE_NAME
argument_list|(
literal|"PROCESSOR"
argument_list|)
end_macro

begin_struct
struct|struct
name|acpi_cpu_softc
block|{
name|device_t
name|cpu_dev
decl_stmt|;
name|ACPI_HANDLE
name|cpu_handle
decl_stmt|;
name|u_int32_t
name|cpu_id
decl_stmt|;
comment|/* CPU throttling control register */
name|struct
name|resource
modifier|*
name|cpu_p_blk
decl_stmt|;
define|#
directive|define
name|CPU_GET_P_CNT
parameter_list|(
name|sc
parameter_list|)
value|(bus_space_read_4(rman_get_bustag((sc)->cpu_p_blk), 	\ 						  rman_get_bushandle((sc)->cpu_p_blk),	\ 						  0))
define|#
directive|define
name|CPU_SET_P_CNT
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|(bus_space_write_4(rman_get_bustag((sc)->cpu_p_blk), 	\ 						  rman_get_bushandle((sc)->cpu_p_blk),	\ 						  0, (val)))
define|#
directive|define
name|CPU_P_CNT_THT_EN
value|(1<<4)
block|}
struct|;
end_struct

begin_comment
comment|/*   * Speeds are stored in counts, from 1 - CPU_MAX_SPEED, and  * reported to the user in tenths of a percent.  */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_duty_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_duty_width
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CPU_MAX_SPEED
value|(1<< cpu_duty_width)
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_PERCENT
parameter_list|(
name|x
parameter_list|)
value|((1000 * (x)) / CPU_MAX_SPEED)
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_PRINTABLE
parameter_list|(
name|x
parameter_list|)
value|(CPU_SPEED_PERCENT(x) / 10),(CPU_SPEED_PERCENT(x) % 10)
end_define

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_smi_cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* should be a generic way to do this */
end_comment

begin_decl_stmt
specifier|static
name|u_int8_t
name|cpu_pstate_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_current_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_performance_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_economy_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int32_t
name|cpu_max_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_t
modifier|*
name|cpu_devices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|cpu_ndevices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sysctl_ctx_list
name|acpi_cpu_sysctl_ctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sysctl_oid
modifier|*
name|acpi_cpu_sysctl_tree
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|acpi_cpu_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|acpi_cpu_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|acpi_cpu_init_throttling
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|acpi_cpu_set_speed
parameter_list|(
name|u_int32_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|acpi_cpu_powerprofile
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|acpi_cpu_speed_sysctl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|acpi_cpu_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|acpi_cpu_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|acpi_cpu_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|acpi_cpu_driver
init|=
block|{
literal|"acpi_cpu"
block|,
name|acpi_cpu_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|acpi_cpu_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|devclass_t
name|acpi_cpu_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|acpi_cpu
argument_list|,
name|acpi
argument_list|,
name|acpi_cpu_driver
argument_list|,
name|acpi_cpu_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|acpi_cpu_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|acpi_get_type
argument_list|(
name|dev
argument_list|)
operator|==
name|ACPI_TYPE_PROCESSOR
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"CPU"
argument_list|)
expr_stmt|;
comment|/* XXX get more verbose description? */
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|acpi_cpu_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|acpi_cpu_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|acpi_softc
modifier|*
name|acpi_sc
decl_stmt|;
name|ACPI_OBJECT
name|processor
decl_stmt|;
name|ACPI_BUFFER
name|buf
decl_stmt|;
name|ACPI_STATUS
name|status
decl_stmt|;
name|u_int32_t
name|p_blk
decl_stmt|;
name|u_int32_t
name|p_blk_length
decl_stmt|;
name|u_int32_t
name|duty_end
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|FUNCTION_TRACE
argument_list|(
name|__func__
argument_list|)
expr_stmt|;
name|ACPI_ASSERTLOCK
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|cpu_dev
operator|=
name|dev
expr_stmt|;
name|sc
operator|->
name|cpu_handle
operator|=
name|acpi_get_handle
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/*      * Get global parameters from the FADT.      */
if|if
condition|(
name|device_get_unit
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* get the FADT */
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|status
operator|=
name|acpi_GetTableIntoBuffer
argument_list|(
name|ACPI_TABLE_FADT
argument_list|,
literal|1
argument_list|,
operator|&
name|buf
argument_list|)
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|,
literal|"couldn't get FADT - %s\n"
argument_list|,
name|acpi_strerror
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|.
name|Pointer
operator|!=
name|NULL
condition|)
name|AcpiOsFree
argument_list|(
name|buf
operator|.
name|Pointer
argument_list|)
expr_stmt|;
name|return_VALUE
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
block|}
name|cpu_duty_offset
operator|=
operator|(
operator|(
name|FADT_DESCRIPTOR_REV2
operator|*
operator|)
name|buf
operator|.
name|Pointer
operator|)
operator|->
name|DutyOffset
expr_stmt|;
name|cpu_duty_width
operator|=
operator|(
operator|(
name|FADT_DESCRIPTOR_REV2
operator|*
operator|)
name|buf
operator|.
name|Pointer
operator|)
operator|->
name|DutyWidth
expr_stmt|;
name|cpu_smi_cmd
operator|=
operator|(
operator|(
name|FADT_DESCRIPTOR_REV1
operator|*
operator|)
name|buf
operator|.
name|Pointer
operator|)
operator|->
name|SmiCmd
expr_stmt|;
name|cpu_pstate_cnt
operator|=
operator|(
operator|(
name|FADT_DESCRIPTOR_REV2
operator|*
operator|)
name|buf
operator|.
name|Pointer
operator|)
operator|->
name|PstateCnt
expr_stmt|;
name|AcpiOsFree
argument_list|(
name|buf
operator|.
name|Pointer
argument_list|)
expr_stmt|;
comment|/* validate the offset/width */
name|duty_end
operator|=
name|cpu_duty_offset
operator|+
name|cpu_duty_width
operator|-
literal|1
expr_stmt|;
comment|/* check that it fits */
if|if
condition|(
name|duty_end
operator|>
literal|31
condition|)
block|{
name|printf
argument_list|(
literal|"acpi_cpu: CLK_VAL field overflows P_CNT register\n"
argument_list|)
expr_stmt|;
name|cpu_duty_width
operator|=
literal|0
expr_stmt|;
block|}
comment|/* check for overlap with the THT_EN bit */
if|if
condition|(
operator|(
name|cpu_duty_offset
operator|<=
literal|4
operator|)
operator|&&
operator|(
name|duty_end
operator|>=
literal|4
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"acpi_cpu: CLK_VAL field overlaps THT_EN bit\n"
argument_list|)
expr_stmt|;
name|cpu_duty_width
operator|=
literal|0
expr_stmt|;
block|}
comment|/*  	 * Start the throttling process once the probe phase completes, if we think that 	 * it's going to be useful.  If the duty width value is zero, there are no significant 	 * bits in the register and thus no throttled states. 	 */
if|if
condition|(
name|cpu_duty_width
operator|>
literal|0
condition|)
block|{
name|AcpiOsQueueForExecution
argument_list|(
name|OSD_PRIORITY_LO
argument_list|,
name|acpi_cpu_init_throttling
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|acpi_sc
operator|=
name|acpi_device_get_parent_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sysctl_ctx_init
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|)
expr_stmt|;
name|acpi_cpu_sysctl_tree
operator|=
name|SYSCTL_ADD_NODE
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|acpi_sc
operator|->
name|acpi_sysctl_tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"cpu"
argument_list|,
name|CTLFLAG_RD
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_INT
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|acpi_cpu_sysctl_tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"max_speed"
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|cpu_max_state
argument_list|,
literal|0
argument_list|,
literal|"maximum CPU speed"
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_INT
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|acpi_cpu_sysctl_tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"current_speed"
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|cpu_current_state
argument_list|,
literal|0
argument_list|,
literal|"current CPU speed"
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_PROC
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|acpi_cpu_sysctl_tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"performance_speed"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|cpu_performance_state
argument_list|,
literal|0
argument_list|,
name|acpi_cpu_speed_sysctl
argument_list|,
literal|"I"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|SYSCTL_ADD_PROC
argument_list|(
operator|&
name|acpi_cpu_sysctl_ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|acpi_cpu_sysctl_tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"economy_speed"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|cpu_economy_state
argument_list|,
literal|0
argument_list|,
name|acpi_cpu_speed_sysctl
argument_list|,
literal|"I"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
block|}
comment|/*      * Get the processor object.      */
name|buf
operator|.
name|Pointer
operator|=
operator|&
name|processor
expr_stmt|;
name|buf
operator|.
name|Length
operator|=
sizeof|sizeof
argument_list|(
name|processor
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|status
operator|=
name|AcpiEvaluateObject
argument_list|(
name|sc
operator|->
name|cpu_handle
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|buf
argument_list|)
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|,
literal|"couldn't get Processor object - %s\n"
argument_list|,
name|acpi_strerror
argument_list|(
name|status
argument_list|)
argument_list|)
expr_stmt|;
name|return_VALUE
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|processor
operator|.
name|Type
operator|!=
name|ACPI_TYPE_PROCESSOR
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|,
literal|"Processor object has bad type %d\n"
argument_list|,
name|processor
operator|.
name|Type
argument_list|)
expr_stmt|;
name|return_VALUE
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
block|}
name|sc
operator|->
name|cpu_id
operator|=
name|processor
operator|.
name|Processor
operator|.
name|ProcId
expr_stmt|;
comment|/*      * If it looks like we support throttling, find this CPU's P_BLK.      *      * Note that some systems seem to duplicate the P_BLK pointer across        * multiple CPUs, so not getting the resource is not fatal.      *       * XXX should support _PTC here as well, once we work out how to parse it.      *      * XXX is it valid to assume that the P_BLK must be 6 bytes long?      */
if|if
condition|(
name|cpu_duty_width
operator|>
literal|0
condition|)
block|{
name|p_blk
operator|=
name|processor
operator|.
name|Processor
operator|.
name|PblkAddress
expr_stmt|;
name|p_blk_length
operator|=
name|processor
operator|.
name|Processor
operator|.
name|PblkLength
expr_stmt|;
comment|/* allocate bus space if possible */
if|if
condition|(
operator|(
name|p_blk
operator|>
literal|0
operator|)
operator|&&
operator|(
name|p_blk_length
operator|==
literal|6
operator|)
condition|)
block|{
name|rid
operator|=
literal|0
expr_stmt|;
name|bus_set_resource
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
name|rid
argument_list|,
name|p_blk
argument_list|,
name|p_blk_length
argument_list|)
expr_stmt|;
name|sc
operator|->
name|cpu_p_blk
operator|=
name|bus_alloc_resource
argument_list|(
name|sc
operator|->
name|cpu_dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|rid
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
literal|1
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
name|DEBUG_PRINT
argument_list|(
argument|TRACE_IO
argument_list|,
argument|(
literal|"acpi_cpu%d: throttling with P_BLK at 0x%x/%d%s\n"
argument|,  				   device_get_unit(sc->cpu_dev), p_blk, p_blk_length, 				   sc->cpu_p_blk ?
literal|""
argument|:
literal|" (shadowed)"
argument|); 	}     }     return_VALUE(
literal|0
argument|); }
comment|/*  * Call this *after* all CPUs have been attached.  *  * Takes the ACPI lock to avoid fighting anyone over the SMI command  * port.  Could probably lock less code.  */
argument|static void acpi_cpu_init_throttling(void *arg) {      ACPI_LOCK;
comment|/* get set of CPU devices */
argument|devclass_get_devices(acpi_cpu_devclass,&cpu_devices,&cpu_ndevices);
comment|/* initialise throttling states */
argument|cpu_max_state = CPU_MAX_SPEED;     cpu_performance_state = cpu_max_state;     cpu_economy_state = cpu_performance_state /
literal|2
argument|;     if (cpu_economy_state ==
literal|0
argument|)
comment|/* 0 is 'reserved' */
argument|cpu_economy_state++;
comment|/* register performance profile change handler */
argument|EVENTHANDLER_REGISTER(powerprofile_change, acpi_cpu_powerprofile, NULL,
literal|0
argument|);
comment|/* if ACPI 2.0+, signal platform that we are taking over throttling */
argument|if (cpu_pstate_cnt !=
literal|0
argument|) {
comment|/* XXX should be a generic interface for this */
argument|AcpiOsOut8(cpu_smi_cmd, cpu_pstate_cnt);     }      ACPI_UNLOCK;
comment|/* set initial speed */
argument|acpi_cpu_powerprofile(NULL);          printf(
literal|"acpi_cpu: CPU throttling enabled, %d steps from 100%% to %d.%d%%\n"
argument|,  	   CPU_MAX_SPEED, CPU_SPEED_PRINTABLE(
literal|1
argument|)); }
comment|/*  * Set CPUs to the new state.  *  * Must be called with the ACPI lock held.  */
argument|static void acpi_cpu_set_speed(u_int32_t speed) {     struct acpi_cpu_softc	*sc;     int				i;     u_int32_t			p_cnt
argument_list|,
argument|clk_val;      ACPI_ASSERTLOCK;
comment|/* iterate over processors */
argument|for (i =
literal|0
argument|; i< cpu_ndevices; i++) { 	sc = device_get_softc(cpu_devices[i]); 	if (sc->cpu_p_blk == NULL) 	    continue;
comment|/* get the current P_CNT value and disable throttling */
argument|p_cnt = CPU_GET_P_CNT(sc); 	p_cnt&= ~CPU_P_CNT_THT_EN; 	CPU_SET_P_CNT(sc, p_cnt);
comment|/* if we're at maximum speed, that's all */
argument|if (speed< CPU_MAX_SPEED) {
comment|/* mask the old CLK_VAL off and or-in the new value */
argument|clk_val = CPU_MAX_SPEED<< cpu_duty_offset; 	    p_cnt&= ~clk_val; 	    p_cnt |= (speed<< cpu_duty_offset);
comment|/* write the new P_CNT value and then enable throttling */
argument|CPU_SET_P_CNT(sc, p_cnt); 	    p_cnt |= CPU_P_CNT_THT_EN; 	    CPU_SET_P_CNT(sc, p_cnt); 	} 	device_printf(sc->cpu_dev,
literal|"set speed to %d.%d%%\n"
argument|, CPU_SPEED_PRINTABLE(speed));     }     cpu_current_state = speed; }
comment|/*  * Power profile change hook.  *  * Uses the ACPI lock to avoid reentrancy.  */
argument|static void acpi_cpu_powerprofile(void *arg) {     u_int32_t	new;      ACPI_LOCK;          new = (powerprofile_get_state() == POWERPROFILE_PERFORMANCE) ? cpu_performance_state : cpu_economy_state;     if (cpu_current_state != new) 	acpi_cpu_set_speed(new);      ACPI_UNLOCK; }
comment|/*  * Handle changes in the performance/ecomony CPU settings.  *  * Does not need the ACPI lock (although setting *argp should  * probably be atomic).  */
argument|static int acpi_cpu_speed_sysctl(SYSCTL_HANDLER_ARGS) {     u_int32_t	*argp;     u_int32_t	arg;     int		error;      argp = (u_int32_t *)oidp->oid_arg1;     arg = *argp;     error = sysctl_handle_int(oidp,&arg,
literal|0
argument|, req);
comment|/* error or no new value */
argument|if ((error !=
literal|0
argument|) || (req->newptr == NULL)) 	return(error);
comment|/* range check */
argument|if ((arg<
literal|1
argument|) || (arg>= cpu_max_state)) 	return(EINVAL);
comment|/* set new value and possibly switch */
argument|*argp = arg;     acpi_cpu_powerprofile(NULL);      return(
literal|0
argument|); }
end_function

end_unit

