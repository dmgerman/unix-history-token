begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * This part for NCR UNIX with is from Andrew Maffei (arm@aqua.whoi.edu). It   * assumes TLI throughout. In order to look up endpoint address information   * we must talk to the "timod" streams module. For some reason "timod" wants   * to sit directly on top of the device driver. Therefore we pop off all   * streams modules except the driver, install the "timod" module so that we   * can figure out network addresses, and then restore the original state.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#) ncr.c 1.1 94/12/28 17:42:34"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/tiuser.h>
end_include

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_define
define|#
directive|define
name|MAX_MODULE_COUNT
value|10
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* fromhost - tear down the streams stack then rebuild it */
end_comment

begin_function
name|void
name|fromhost
parameter_list|(
name|request
parameter_list|)
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|int
name|num_mod
decl_stmt|;
name|struct
name|str_list
name|str_list
decl_stmt|;
name|struct
name|str_mlist
name|mod_buffer
index|[
name|MAX_MODULE_COUNT
index|]
decl_stmt|;
name|int
name|fd
init|=
name|request
operator|->
name|fd
decl_stmt|;
name|str_list
operator|.
name|sl_nmods
operator|=
name|MAX_MODULE_COUNT
expr_stmt|;
name|str_list
operator|.
name|sl_modlist
operator|=
operator|&
name|mod_buffer
index|[
literal|0
index|]
expr_stmt|;
comment|/*      * On systems with WIN streams support we have to be careful about what      * is on the stream we are passed. This code POPs off all modules above      * the pseudo driver, pushes timod, gets the host address information,      * pops timod and then pushes all modules back on the stream.      *       * Some state may be lost in this process. /usr/etc/tlid seems to do special      * things to the stream depending on the TCP port being serviced. (not a      * very nice thing to do!). It is unclear what to do if this code breaks      * - the stream may be left in an unknown condition.      */
if|if
condition|(
operator|(
name|num_mod
operator|=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_LIST
argument_list|,
name|NULL
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: LIST failed: %m"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_LIST
argument_list|,
operator|&
name|str_list
argument_list|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: LIST failed: %m"
argument_list|)
expr_stmt|;
comment|/*      * POP stream modules except for the driver.      */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_mod
operator|-
literal|1
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_POP
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: POP %s: %m"
argument_list|,
name|mod_buffer
index|[
name|i
index|]
operator|.
name|l_name
argument_list|)
expr_stmt|;
comment|/*      * PUSH timod so that host address ioctls can be executed.      */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_PUSH
argument_list|,
literal|"timod"
argument_list|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: PUSH timod: %m"
argument_list|)
expr_stmt|;
name|tli_host
argument_list|(
name|request
argument_list|)
expr_stmt|;
comment|/*      * POP timod, we're done with it now.      */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_POP
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: POP timod: %m"
argument_list|)
expr_stmt|;
comment|/*      * Restore stream modules.      */
for|for
control|(
name|i
operator|=
name|num_mod
operator|-
literal|2
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|I_PUSH
argument_list|,
name|mod_buffer
index|[
name|i
index|]
operator|.
name|l_name
argument_list|)
operator|<
literal|0
condition|)
name|tcpd_warn
argument_list|(
literal|"fromhost: PUSH %s: %m"
argument_list|,
name|mod_buffer
index|[
name|i
index|]
operator|.
name|l_name
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

