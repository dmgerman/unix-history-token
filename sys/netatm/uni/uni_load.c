begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * Loadable kernel module support  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATM_UNI_MODULE
end_ifndef

begin_include
include|#
directive|include
file|"opt_atm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_var.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * External functions  */
end_comment

begin_function_decl
name|int
name|sscop_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscf_uni_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscf_uni_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uniip_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uniip_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisig_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Local functions  */
end_comment

begin_function_decl
specifier|static
name|int
name|uni_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|uni_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize uni processing  *   * This will be called during module loading.  We just notify all of our  * sub-services to initialize.  *  * Arguments:  *	none  *  * Returns:  *	0 	startup was successful   *	errno	startup failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_start
parameter_list|()
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Verify software version 	 */
if|if
condition|(
name|atm_version
operator|!=
name|ATM_VERSION
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"version mismatch: uni=%d.%d kernel=%d.%d\n"
argument_list|,
name|ATM_VERS_MAJ
argument_list|(
name|ATM_VERSION
argument_list|)
argument_list|,
name|ATM_VERS_MIN
argument_list|(
name|ATM_VERSION
argument_list|)
argument_list|,
name|ATM_VERS_MAJ
argument_list|(
name|atm_version
argument_list|)
argument_list|,
name|ATM_VERS_MIN
argument_list|(
name|atm_version
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
comment|/* 	 * Initialize uni sub-services 	 */
name|err
operator|=
name|sscop_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|sscf_uni_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|unisig_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|uniip_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|done
label|:
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Halt uni processing   *   * This will be called just prior to unloading the module from  * memory.  All sub-services will be notified of the termination.  *  * Arguments:  *	none  *  * Returns:  *	0 	shutdown was successful   *	errno	shutdown failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_stop
parameter_list|()
block|{
name|int
name|err
decl_stmt|,
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
comment|/* 	 * Terminate uni sub-services 	 */
name|err
operator|=
name|uniip_stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|unisig_stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|sscf_uni_stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|err
operator|=
name|sscop_stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
goto|goto
name|done
goto|;
name|done
label|:
operator|(
name|void
operator|)
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_UNI_MODULE
end_ifdef

begin_comment
comment|/*  *******************************************************************  *  * Loadable Module Support  *  *******************************************************************  */
end_comment

begin_function_decl
specifier|static
name|int
name|uni_doload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|uni_dounload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generic module load processing  *   * This function is called by an OS-specific function when this  * module is being loaded.  *  * Arguments:  *	none  *  * Returns:  *	0 	load was successful   *	errno	load failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_doload
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * Start us up 	 */
name|err
operator|=
name|uni_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
comment|/* Problems, clean up */
operator|(
name|void
operator|)
name|uni_stop
argument_list|()
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Generic module unload processing  *   * This function is called by an OS-specific function when this  * module is being unloaded.  *  * Arguments:  *	none  *  * Returns:  *	0 	unload was successful   *	errno	unload failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_dounload
parameter_list|()
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * OK, try to clean up our mess 	 */
name|err
operator|=
name|uni_stop
argument_list|()
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_comment
comment|/*  * Loadable miscellaneous module description  */
end_comment

begin_expr_stmt
name|MOD_MISC
argument_list|(
name|uni
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Loadable module support "load" entry point  *   * This is the routine called by the lkm driver whenever the  * modload(1) command is issued for this module.  *  * Arguments:  *	lkmtp	pointer to lkm drivers's structure  *	cmd	lkm command code  *  * Returns:  *	0 	command was successful   *	errno	command failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_load
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
block|{
return|return
operator|(
name|uni_doload
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Loadable module support "unload" entry point  *   * This is the routine called by the lkm driver whenever the  * modunload(1) command is issued for this module.  *  * Arguments:  *	lkmtp	pointer to lkm drivers's structure  *	cmd	lkm command code  *  * Returns:  *	0 	command was successful   *	errno	command failed - reason indicated  *  */
end_comment

begin_function
specifier|static
name|int
name|uni_unload
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
block|{
return|return
operator|(
name|uni_dounload
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Loadable module support entry point  *   * This is the routine called by the lkm driver for all loadable module  * functions for this driver.  This routine name must be specified  * on the modload(1) command.  This routine will be called whenever the  * modload(1), modunload(1) or modstat(1) commands are issued for this  * module.  *  * Arguments:  *	lkmtp	pointer to lkm drivers's structure  *	cmd	lkm command code  *	ver	lkm version  *  * Returns:  *	0 	command was successful   *	errno	command failed - reason indicated  *  */
end_comment

begin_function
name|int
name|uni_mod
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|ver
decl_stmt|;
block|{
name|MOD_DISPATCH
argument_list|(
name|uni
argument_list|,
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|uni_load
argument_list|,
name|uni_unload
argument_list|,
name|lkm_nullcmd
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ATM_UNI_MODULE */
end_comment

begin_comment
comment|/*  *******************************************************************  *  * Kernel Compiled Module Support  *  *******************************************************************  */
end_comment

begin_function_decl
specifier|static
name|void
name|uni_doload
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|SYSINIT
argument_list|(
argument|atmuni
argument_list|,
argument|SI_SUB_PROTO_END
argument_list|,
argument|SI_ORDER_ANY
argument_list|,
argument|uni_doload
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/*  * Kernel initialization  *   * Arguments:  *	arg	Not used  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|uni_doload
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* 	 * Start us up 	 */
name|err
operator|=
name|uni_start
argument_list|()
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* Problems, clean up */
operator|(
name|void
operator|)
name|uni_stop
argument_list|()
expr_stmt|;
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ATM UNI unable to initialize (%d)!!\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_UNI_MODULE */
end_comment

end_unit

